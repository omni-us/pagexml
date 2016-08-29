/**
 * Class for input, output and processing of Page XML files and referenced image.
 *
 * @version $Revision::       $$Date::             $
 * @copyright Copyright (c) 2016 to the present, Mauricio Villegas <mauvilsa@upv.es>
 */

#include "PageXML.h"

#include <stdio.h>
#include <string.h>
#include <stdexcept>
#include <regex>

#include <opencv2/opencv.hpp>
#include <libxml/xpathInternals.h>

using namespace std;
using namespace Magick;
using namespace libconfig;

const char* PageXML::settingNames[] = {
  "indent",
  "pagens",
  //"loadimg",
  "grayimg",
  "extended_names"
};

char default_pagens[] = "http://schema.primaresearch.org/PAGE/gts/pagecontent/2013-07-15";

Color transparent("rgba(0,0,0,0)");
Color opaque("rgba(0,0,0,100%)");
regex reXheight(".*x-height: *([0-9.]+) *px;.*");

/////////////////////////
/// Resources release ///
/////////////////////////

/**
 * Releases all reserved resources of PageXML instance.
 */
void PageXML::release() {
  if( xml == NULL )
    return;

  pageimg = Image();
  if( xml != NULL )
    xmlFreeDoc(xml);
  xml = NULL;
  if( context != NULL )
    xmlXPathFreeContext(context);
  context = NULL;
  if( xmldir != NULL )
    free(xmldir);
  xmldir = NULL;
  if( imgpath != NULL )
    free(imgpath);
  imgpath = NULL;
  if( imgbase != NULL )
    free(imgbase);
  imgbase = NULL;
}

/**
 * PageXML object destructor.
 */
PageXML::~PageXML() {
  release();
}

////////////////////
/// Constructors ///
////////////////////

/**
 * PageXML constructor that receives a libconfig Config object.
 *
 * @param config  A libconfig Config object.
 */
PageXML::PageXML( const Config& config ) {
  loadConf(config);
  if( pagens == NULL )
    pagens = default_pagens;
}

/**
 * PageXML constructor that receives a configuration file name.
 *
 * @param cfgfile  Configuration file to use.
 */
PageXML::PageXML( const char* cfgfile ) {
  if( cfgfile != NULL ) {
    Config config;
    config.readFile(cfgfile);
    loadConf(config);
  }
  if( pagens == NULL )
    pagens = default_pagens;
}

//////////////
/// Output ///
//////////////

/**
 * Writes the current state of the XML to a file using utf-8 encoding.
 *
 * @param fname  File name of where the XML file will be written.
 * @return       Number of bytes written.
 */
int PageXML::write( const char* fname ) {
  return xmlSaveFormatFileEnc( fname, xml, "utf-8", indent );
}

/**
 * Gets the base name of the Page file derived from the image file name.
 *
 * @return  String containing the image base name.
 */
char* PageXML::getBase() {
  return imgbase;
}

/////////////////////
/// Configuration ///
/////////////////////

/**
 * Gets the enum value for a configuration setting name, or -1 if unknown.
 *
 * @param format  String containing setting name.
 * @return        Enum format value.
 */
inline static int parsePageSetting( const char* setting ) {
  int settings = sizeof(PageXML::settingNames) / sizeof(PageXML::settingNames[0]);
  for( int n=0; n<settings; n++ )
    if( ! strcmp(PageXML::settingNames[n],setting) )
      return n;
  return -1;
}

/**
 * Applies configuration options to the PageXML instance.
 *
 * @param config  A libconfig Config object.
 */
void PageXML::loadConf( const Config& config ) {
  if( ! config.exists("PageXML") )
    return;

  const Setting& pagecfg = config.getRoot()["PageXML"];

  int numsettings = pagecfg.getLength();
  for( int i = 0; i < numsettings; i++ ) {
    const Setting& setting = pagecfg[i];
    //printf("PageXML: setting=%s enum=%d\n",setting.getName(),parsePageSetting(setting.getName()));
    switch( parsePageSetting(setting.getName()) ) {
      case PAGEXML_SETTING_INDENT:
        indent = (bool)setting;
        break;
      case PAGEXML_SETTING_PAGENS:
        if( pagens != NULL && pagens != default_pagens )
          free(pagens);
        pagens = strdup(setting.c_str());
        break;
      //case PAGEXML_SETTING_LOADIMG:
      //  loadimg = (bool)setting;
      //  break;
      case PAGEXML_SETTING_GRAYIMG:
        grayimg = (bool)setting;
        break;
      case PAGEXML_SETTING_EXTENDED_NAMES:
        extended_names = (bool)setting;
        break;
      default:
        throw invalid_argument( string("PageXML: unexpected configuration property: ") + setting.getName() );
    }
  }
}

/**
 * Prints the current configuration.
 *
 * @param file  File to print to.
 */
void PageXML::printConf( FILE* file ) {
  fprintf( file, "PageXML: {\n" );
  fprintf( file, "  indent = %s;\n", indent ? "true" : "false" );
  fprintf( file, "  pagens = \"%s\";\n", pagens );
  //fprintf( file, "  loadimg = %s;\n", loadimg ? "true" : "false" );
  fprintf( file, "  grayimg = %s;\n", grayimg ? "true" : "false" );
  fprintf( file, "  extended_names = %s;\n", extended_names ? "true" : "false" );
  fprintf( file, "}\n" );
}

///////////////
/// Loaders ///
///////////////

/**
 * Loads a Page XML from a file.
 *
 * @param fname  File name of the XML file to read.
 */
void PageXML::loadXml( const char* fname ) {
  release();

  if( strrchr(fname,'/') != NULL )
    xmldir = strndup(fname,strrchr(fname,'/')-fname);
  FILE *file;
  if( (file=fopen(fname,"rb")) == NULL )
    throw runtime_error( string("PageXML: loadXml: unable to open file: ") + fname );
  loadXml( fileno(file) );
  fclose(file);
}

/**
 * Loads a Page XML from an input stream.
 *
 * @param fnum  File number from where to read the XML file.
 */
void PageXML::loadXml( int fnum ) {
  release();

  xmlKeepBlanksDefault(0);
  xml = xmlReadFd( fnum, NULL, NULL, XML_PARSE_NONET );

  context = xmlXPathNewContext(xml);
  if( context == NULL )
    throw runtime_error( "PageXML: loadXml: unable create xpath context" );
  if( xmlXPathRegisterNs( context, (xmlChar*)"_", (xmlChar*)pagens ) != 0 )
    throw runtime_error( "PageXML: loadXml: unable to register namespace" );

  xmlXPathObjectPtr elem_page = xmlXPathEvalExpression( (xmlChar*)"//_:Page", context );
  if( xmlXPathNodeSetIsEmpty(elem_page->nodesetval) )
    throw runtime_error( "PageXML: loadXml: unable to find page element" );

  /// Get page size ///
  xmlChar* uwidth = xmlGetProp( elem_page->nodesetval->nodeTab[0], (xmlChar*)"imageWidth" );
  xmlChar* uheight = xmlGetProp( elem_page->nodesetval->nodeTab[0], (xmlChar*)"imageHeight" );
  if( uwidth == NULL || uheight == NULL )
    throw runtime_error( "PageXML: loadXml: problems retrieving page size from xml" );
  width = atoi((char*)uwidth);
  height = atoi((char*)uheight);
  xmlFree(uwidth);
  xmlFree(uheight);

  /// Get image path ///
  imgpath = (char*)xmlGetProp( elem_page->nodesetval->nodeTab[0], (xmlChar*)"imageFilename" );
  if( imgpath ==NULL )
    throw runtime_error( "PageXML: loadXml: problems retrieving image file from xml" );

  char* p = strrchr(imgpath,'/') == NULL ? imgpath : strrchr(imgpath,'/')+1;
  if( strrchr(p,'.') == NULL )
    throw runtime_error( string("PageXML: loadXml: expected image file name to have an extension: ")+p );
  imgbase = strndup(p,strrchr(p,'.')-p);
  for( char *p=imgbase; *p!='\0'; p++ )
    if( *p == ' ' /*|| *p == '[' || *p == ']' || *p == '(' || *p == ')'*/ )
      *p = '_';

  xmlXPathFreeObject(elem_page);

  if( xmldir == NULL )
    xmldir = strdup(".");

  //if( loadimg )
  //  loadImage();
}

/**
 * Loads an image for the Page XML.
 *
 * @param fname  File name of the image to read.
 */
void PageXML::loadImage( const char* fname ) {
  string aux;
  if( fname == NULL )
    fname = imgpath[0] == '/' ? imgpath : (aux=string(xmldir)+'/'+imgpath).c_str();

  try {
    pageimg.read(fname);
  } 
  catch( exception& e ) {
    throw runtime_error( string("PageXML: loadImage: ") + e.what() );
  } 

  if( grayimg ) {
    if( pageimg.matte() && pageimg.type() != GrayscaleMatteType )
      pageimg.type( GrayscaleMatteType );
    else if( ! pageimg.matte() && pageimg.type() != GrayscaleType )
      pageimg.type( GrayscaleType );
  }

  if( width != pageimg.columns() || height != pageimg.rows() )
    throw runtime_error( string("PageXML: loadImage: discrepancy between image and xml page size: ") + fname );
}

///////////////////////
/// Page processing ///
///////////////////////

/**
 * Parses a string of pairs of coordinates (x1,y1 [x2,y2 ...]) into a list.
 *
 * @param str_coords  String containing coordinate pairs.
 * @param _xmin       Minimum x value.
 * @param _xmax       Maximum x value.
 * @param _ymin       Minimum y value.
 * @param _ymax       Maximum y value.
 * @return            List of (x,y) coordinates.
 */
static list<Coordinate> parsePoints( xmlChar* str_coords, double* _xmin = NULL, double* _xmax = NULL, double* _ymin = NULL, double* _ymax = NULL ) {
  list<Coordinate> points;

  double xmin = NAN;
  double xmax = NAN;
  double ymin = NAN;
  double ymax = NAN;

  int n = 0;
  char *p = (char*)str_coords-1;
  while( true ) {
    p++;
    double x, y;
    if( sscanf( p, "%lf,%lf", &x, &y ) != 2 )
      break;
    points.push_back(Coordinate(x,y));
    if( n == 0 || xmin > x ) xmin = x;
    if( n == 0 || xmax < x ) xmax = x;
    if( n == 0 || ymin > y ) ymin = y;
    if( n == 0 || ymax < y ) ymax = y;
    n++;
    if( (p = strchr(p,' ')) == NULL )
      break;
  }

  if( _xmin != NULL ) *_xmin = xmin;
  if( _xmax != NULL ) *_xmax = xmax;
  if( _ymin != NULL ) *_ymin = ymin;
  if( _ymax != NULL ) *_ymax = ymax;

  return points;
}

/**
 * Cronvers a vector of points to a string in format "x1,y1 x2,y2 ...".
 *
 * @param points  Vector of points.
 * @return        String representation of the points.
 */
string PageXML::pointsToString( vector<cv::Point2f> points ) {
  char val[32];
  string str("");
  for( size_t n=0; n<points.size(); n++ ) {
    sprintf( val, "%g,%g", points[n].x, points[n].y );
    str += ( n == 0 ? "" : " " ) + string(val);
  }
  return str;
}
string PageXML::pointsToString( vector<cv::Point> points ) {
  char val[32];
  string str("");
  for( size_t n=0; n<points.size(); n++ ) {
    sprintf( val, "%d,%d", points[n].x, points[n].y );
    str += ( n == 0 ? "" : " " ) + string(val);
  }
  return str;
}

/**
 * Crops images using its Coords polygon, regions outside the polygon are set to transparent.
 *
 * @param xpath  Selector for polygons to crop.
 * @return       An std::vector containing (id,name,image) triplets of the cropped images.
 */
vector<NamedImage> PageXML::crop( const char* xpath ) {
  xmlXPathObjectPtr elems_coords = xmlXPathEvalExpression( (xmlChar*)xpath, context );

  if( pageimg.columns() == 0 )
    loadImage();

  vector<NamedImage> images;
  if( ! xmlXPathNodeSetIsEmpty(elems_coords->nodesetval) )
  for( int n=0; n<elems_coords->nodesetval->nodeNr; n++ ) {
    xmlNodePtr node = elems_coords->nodesetval->nodeTab[n];

    if( xmlStrcmp( node->name, (const xmlChar*)"Coords") )
      throw runtime_error( string("PageXML: expected xpath to match only Coords elements: match=") + to_string(n+1) + " xpath=" + xpath );

    /// Get parent node id ///
    char* id1 = (char*)xmlGetProp( node->parent, (xmlChar*)"id" );
    if( id1 == NULL )
      throw runtime_error( string("PageXML: expected parent element to include id attribute: match=") + to_string(n+1) + " xpath=" + xpath );

    /// Get coords points ///
    double xmin, xmax, ymin, ymax;
    xmlChar* points = xmlGetProp( node, (xmlChar*)"points" );
    if( points == NULL )
      throw runtime_error( string("PageXML: expected a points attribute in Coords[@id=\"") + id1 + "\"]" );
    list<Coordinate> coords = parsePoints( points, &xmin, &xmax, &ymin, &ymax );
    xmlFree(points);

    /// Construct sample name ///
    string sampid(id1);
    /*string sampbase(imgbase);
    if( sampid.size() > sampbase.size() &&
        ! sampid.compare(0,sampbase.size(),sampbase) )
      sampid.erase( 0, sampbase.size() );*/
    string sampname = string(".") + sampid;
    free(id1);
    if( extended_names )
      if( ! xmlStrcmp( node->parent->name, (const xmlChar*)"TextLine") ||
          ! xmlStrcmp( node->parent->name, (const xmlChar*)"Word") ) {
        char* id2 = (char*)xmlGetProp( node->parent->parent, (xmlChar*)"id" );
        sampname = string(".") + id2 + sampname;
        free(id2);
        if( ! xmlStrcmp( node->parent->name, (const xmlChar*)"Word") ) {
          char* id3 = (char*)xmlGetProp( node->parent->parent->parent, (xmlChar*)"id" );
          sampname = string(".") + id3 + sampname;
          free(id3);
        }
      }
    sampname = string(imgbase) + sampname;

    //char* line_id = (char*)xmlGetProp( elems_coords->nodesetval->nodeTab[n]->parent, (xmlChar*)"id" );
    //char* reg_id = (char*)xmlGetProp( elems_coords->nodesetval->nodeTab[n]->parent->parent, (xmlChar*)"id" );
    //string sampid(line_id);
    //string sampname = string(imgbase)+"."+reg_id+"."+line_id;
    //free(line_id);
    //free(reg_id);

    size_t cropW = (size_t)(ceil(xmax)-floor(xmin)+1);
    size_t cropH = (size_t)(ceil(ymax)-floor(ymin)+1);
    int cropX = (int)floor(xmin);
    int cropY = (int)floor(ymin);

    for( list<Coordinate>::iterator coord = coords.begin(), end = coords.end(); coord != end; coord++ ) {
      coord->x( coord->x()-cropX );
      coord->y( coord->y()-cropY );
    }

    Image cropimg = pageimg;
    cropimg.crop( Geometry(cropW,cropH,cropX,cropY) );

    // @todo Skip transparent if polygon is bounding box
    list<Drawable> drawList;
    drawList.push_back(DrawableStrokeColor(opaque));
    drawList.push_back(DrawableFillColor(opaque));
    drawList.push_back(DrawableStrokeAntialias(false));
    drawList.push_back(DrawablePolygon(coords));
    Image mask( Geometry(cropW,cropH), transparent );
    mask.draw(drawList);
    cropimg.draw( DrawableCompositeImage(0,0,0,0,mask,CopyOpacityCompositeOp) );

    NamedImage namedimage = { sampid, sampname, cropimg };

    images.push_back(namedimage);
  }

  xmlXPathFreeObject(elems_coords);

  return images;
}

/**
 * Adds or modifies (if already exists) attributes in the XML.
 *
 * @param xpath  Selector for the element(s) to set the attribute.
 * @return       Number of elements modified.
 */
int PageXML::setAttr( const char* xpath, const char* name, const char* value ) {
  int numSet = 0;
  xmlXPathObjectPtr elem = xmlXPathEvalExpression( (xmlChar*)xpath, context );

  if( elem != NULL && elem->nodesetval )
    for( int n=0; n<elem->nodesetval->nodeNr; n++ ) {
      xmlAttrPtr attr = xmlHasProp( elem->nodesetval->nodeTab[n], (xmlChar*)name ) ?
        xmlSetProp( elem->nodesetval->nodeTab[n], (xmlChar*)name, (xmlChar*)value ) :
        xmlNewProp( elem->nodesetval->nodeTab[n], (xmlChar*)name, (xmlChar*)value ) ;
      if( ! attr )
        throw runtime_error( string("PageXML: problems setting attribute: xpath=") + xpath + " name=" + name );
    }

  if( elem != NULL )
    xmlXPathFreeObject(elem);

  return numSet;
}

/**
 * Retrieves the x-height for a given TextLine id.
 *
 * @param id     Identifier of the TextLine.
 * @return       x-height>0 on success, -1 if unset for line.
 */
float PageXML::getXheight( const char* id ) {
  float xheight = -1;
  string xpath = string("//*[@id='")+id+"']";
  xmlXPathObjectPtr elem = xmlXPathEvalExpression( (xmlChar*)xpath.c_str(), context );

  if( elem != NULL && elem->nodesetval && elem->nodesetval->nodeNr > 0 &&
      xmlHasProp( elem->nodesetval->nodeTab[0], (xmlChar*)"custom" ) ) {
    xmlChar* custom = xmlGetProp( elem->nodesetval->nodeTab[0], (xmlChar*)"custom" );
    cmatch base_match;
    if( regex_match((char*)custom,base_match,reXheight) )
      xheight = stof(base_match[1].str());
    xmlFree(custom);
  }

  if( elem != NULL )
    xmlXPathFreeObject(elem);

  return xheight;
}

/**
 * Simplifies IDs by removing imgbase prefixes and replaces invalid characters with _.
 *
 * @return       Number of IDs simplified.
 */
int PageXML::simplifyIDs() {
  int simplified = 0;

  regex reTrim("^[^a-zA-Z]*");
  regex reInvalid("[^a-zA-Z0-9_-]");
  string sampbase(imgbase);
  //xmlXPathObjectPtr elem = xmlXPathEvalExpression( (xmlChar*)"//*[@id]", context );
  xmlXPathObjectPtr elem = xmlXPathEvalExpression( (xmlChar*)"//*[@id][local-name()='TextLine' or local-name()='TextRegion']", context );

  if( elem != NULL && elem->nodesetval )
    for( int n=0; n<elem->nodesetval->nodeNr; n++ ) {
      xmlChar* id = xmlGetProp( elem->nodesetval->nodeTab[n], (xmlChar*)"id" );
      string sampid((char*)id);
      if( sampid.size() > sampbase.size() &&
          ! sampid.compare(0,sampbase.size(),sampbase) ) {
        sampid.erase( 0, sampbase.size() );
        sampid = regex_replace(sampid,reTrim,"");
        if( sampid.size() > 0 ) {
          sampid = regex_replace(sampid,reInvalid,"_");
          xmlHasProp( elem->nodesetval->nodeTab[n], (xmlChar*)"orig-id" ) ?
            xmlSetProp( elem->nodesetval->nodeTab[n], (xmlChar*)"orig-id", id ) :
            xmlNewProp( elem->nodesetval->nodeTab[n], (xmlChar*)"orig-id", id ) ;
          xmlSetProp( elem->nodesetval->nodeTab[n], (xmlChar*)"id", (xmlChar*)sampid.c_str() );
          simplified++;
        }
      }
      free(id);
    }

  if( elem != NULL )
    xmlXPathFreeObject(elem);

  return simplified;
}
