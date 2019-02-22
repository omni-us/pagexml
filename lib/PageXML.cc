/**
 * Class for input, output and processing of Page XML files and referenced image.
 *
 * @version $Version: 2019.02.22$
 * @copyright Copyright (c) 2016-present, Mauricio Villegas <mauricio_ville@yahoo.com>
 * @license MIT License
 */

#include "PageXML.h"

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdexcept>
#include <regex>
#include <iomanip>
#include <unordered_set>
#include <cassert>

#include <opencv2/opencv.hpp>
#include <libxml/xpathInternals.h>
//#include <libxslt/xslt.h>
#include <libxslt/xsltconfig.h>

using namespace std;

#if defined (__PAGEXML_LIBCONFIG__)
const char* PageXML::settingNames[] = {
  "indent",
  "pagens",
  "grayimg"
};
#endif

char default_pagens[] = "http://schema.primaresearch.org/PAGE/gts/pagecontent/2013-07-15";

#ifdef __PAGEXML_MAGICK__
Magick::Color transparent("rgba(0,0,0,0)");
Magick::Color opaque("rgba(0,0,0,100%)");
Magick::Color colorWhite("white");
#endif
regex reXheight(".*x-height: *([0-9.]+) *px;.*");
regex reRotation(".*readingOrientation: *([0-9.]+) *;.*");
regex reDirection(".*readingDirection: *([lrt]t[rlb]) *;.*");
regex reFileExt("\\.[^.]+$");
regex reInvalidBaseChars(" ");
regex reImagePageNum("(.*)\\[([0-9]+)\\]$");
regex reIsPdf(".+\\.pdf(\\[[0-9]+\\]){0,1}$",std::regex::icase);
regex reIsTiff(".+\\.tif{1,2}(\\[[0-9]+\\]){0,1}$",std::regex::icase);

xsltStylesheetPtr sortattr = xsltParseStylesheetDoc( xmlParseDoc( (xmlChar*)"<xsl:stylesheet xmlns:xsl=\"http://www.w3.org/1999/XSL/Transform\" version=\"1.0\"><xsl:output method=\"xml\" indent=\"yes\" encoding=\"utf-8\" omit-xml-declaration=\"no\"/><xsl:template match=\"*\"><xsl:copy><xsl:apply-templates select=\"@*\"><xsl:sort select=\"name()\"/></xsl:apply-templates><xsl:apply-templates/></xsl:copy></xsl:template><xsl:template match=\"@*|comment()|processing-instruction()\"><xsl:copy/></xsl:template></xsl:stylesheet>" ) );

xsltStylesheetPtr sortelem = xsltParseStylesheetDoc( xmlParseDoc( (xmlChar*)"<xsl:stylesheet xmlns:xsl=\"http://www.w3.org/1999/XSL/Transform\" xmlns:_=\"http://schema.primaresearch.org/PAGE/gts/pagecontent/2013-07-15\" xmlns=\"http://schema.primaresearch.org/PAGE/gts/pagecontent/2013-07-15\" version=\"1.0\"><xsl:output method=\"xml\" indent=\"yes\" encoding=\"utf-8\" omit-xml-declaration=\"no\"/><xsl:strip-space elements=\"*\"/><xsl:template match=\"@* | node()\"><xsl:copy><xsl:apply-templates select=\"@* | node()\"/></xsl:copy></xsl:template><xsl:template match=\"_:PcGts\"><xsl:copy><xsl:apply-templates select=\"@*\"/><xsl:apply-templates select=\"_:Metadata\"/><xsl:apply-templates select=\"_:Property\"/><xsl:apply-templates select=\"_:Page\"/><xsl:apply-templates select=\"node()[not(contains(' Metadata Property Page ',concat(' ',local-name(),' ')))]\"/></xsl:copy></xsl:template><xsl:template match=\"*[_:Coords or _:Baseline or _:TextEquiv]\"><xsl:copy><xsl:apply-templates select=\"@*\"/><xsl:apply-templates select=\"_:ImageOrientation\"/><xsl:apply-templates select=\"_:Property\"/><xsl:apply-templates select=\"_:Coords\"/><xsl:apply-templates select=\"_:Baseline\"/><xsl:apply-templates select=\"_:TextLine | _:Word | _:Glyph\"/><xsl:apply-templates select=\"_:TextEquiv\"/><xsl:apply-templates select=\"node()[not(contains(' ImageOrientation Property Coords Baseline TextLine Word Glyph TextEquiv ',concat(' ',local-name(),' ')))]\"/></xsl:copy></xsl:template></xsl:stylesheet>" ) );

bool validation_enabled = true;

/////////////////////
/// Class version ///
/////////////////////

static char class_version[] = "Version: 2019.02.22";

/**
 * Returns the class version.
 */
char* PageXML::version() {
  return class_version+9;
}

void PageXML::printVersions( FILE* file ) {
  fprintf( file, "compiled against PageXML %s\n", class_version+9 );
  fprintf( file, "compiled against libxml2 %s, linked with %s\n", LIBXML_DOTTED_VERSION, xmlParserVersion );
  fprintf( file, "compiled against libxslt %s, linked with %s\n", LIBXSLT_DOTTED_VERSION, xsltEngineVersion );
  fprintf( file, "compiled against opencv %s\n", CV_VERSION );
}


/////////////////////////
/// Resources release ///
/////////////////////////

/**
 * Releases all reserved resources of PageXML instance.
 */
void PageXML::release() {
  freeXML();
  freeSchema();
}

/**
 * Releases XML related resources.
 */
void PageXML::freeXML() {
  if( xml == NULL )
    return;

  if( xml != NULL )
    xmlFreeDoc(xml);
  xml = NULL;
  if( context != NULL )
    xmlXPathFreeContext(context);
  context = NULL;
  xmlDir = string("");
#if defined (__PAGEXML_LEPT__) || defined (__PAGEXML_IMG_MAGICK__) || defined (__PAGEXML_IMG_CV__)
  releaseImages();
#endif
  pagesImage = std::vector<PageImage>();
  pagesImageFilename = std::vector<std::string>();
  pagesImageBase = std::vector<std::string>();
  process_running = NULL;
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

#if defined (__PAGEXML_LIBCONFIG__)

PageXML::PageXML() {
  if( pagens == NULL )
    pagens = default_pagens;
}

/**
 * PageXML constructor that receives a libconfig Config object.
 *
 * @param config  A libconfig Config object.
 */
PageXML::PageXML( const libconfig::Config& config ) {
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
    libconfig::Config config;
    config.readFile(cfgfile);
    loadConf(config);
  }
  if( pagens == NULL )
    pagens = default_pagens;
}

#else

/**
 * PageXML constructor that receives a file name to load.
 *
 * @param pagexml_path  Path to the XML file to read.
 * @param schema_path   Path to the XSD file to read.
 */
PageXML::PageXML( const char* pagexml_path, const char* schema_path ) {
  if( pagens == NULL )
    pagens = default_pagens;
  if( schema_path != NULL )
    loadSchema( schema_path );
  if( pagexml_path != NULL )
    loadXml( pagexml_path );
}

#endif


/////////////////////////
/// Schema validation ///
/////////////////////////

static void validationErrorFunc( void* ctx __attribute__((unused)), const char *msg, ... ) {
  static char buffer[5000];
  va_list argp;
  va_start( argp, msg );
  vsprintf( buffer, msg, argp );
  va_end( argp );
  fprintf( stderr, "error: %s\n", buffer );
}

static void validationWarningFunc( void* ctx __attribute__((unused)), const char *msg, ... ) {
  static char buffer[5000];
  va_list argp;
  va_start( argp, msg );
  vsprintf( buffer, msg, argp );
  va_end( argp );
  fprintf( stderr, "warning: %s\n", buffer );
}

/**
 * Releases schema related resources.
 */
void PageXML::freeSchema() {
  if( valid_context ) {
    xmlSchemaFreeValidCtxt(valid_context);
    valid_context = NULL;
  }
  if( valid_schema ) {
    xmlSchemaFree(valid_schema);
    valid_schema = NULL;
  }
  if( valid_parser ) {
    xmlSchemaFreeParserCtxt(valid_parser);
    valid_parser = NULL;
  }
  if( valid_doc ) {
    xmlFreeDoc(valid_doc);
    valid_doc = NULL;
  }
}

/**
 * Loads a schema for xml validation.
 *
 * @param schema_path  File name of the XSD file to read.
 */
void PageXML::loadSchema( const char *schema_path ) {
  if( schema_path == NULL )
    return;
  freeSchema();
  if( ! (valid_doc = xmlReadFile(schema_path, NULL, XML_PARSE_NONET)) )
    throw_runtime_error( "PageXML.loadSchema: problems reading schema: %s", schema_path );
  if( ! (valid_parser = xmlSchemaNewDocParserCtxt(valid_doc)) )
    throw_runtime_error( "PageXML.loadSchema: problems creating schema parser: %s", schema_path );
  if( ! (valid_schema = xmlSchemaParse(valid_parser)) )
    throw_runtime_error( "PageXML.loadSchema: problems parsing schema: %s", schema_path );
  if( ! (valid_context = xmlSchemaNewValidCtxt(valid_schema)) )
    throw_runtime_error( "PageXML.loadSchema: problems creating validation context: %s", schema_path );
  xmlSchemaSetValidErrors( valid_context, &validationErrorFunc, &validationWarningFunc, NULL );
}

/**
 * Validates the currently loaded XML.
 */
bool PageXML::isValid( xmlDocPtr xml_to_validate ) {
  if( xml_to_validate == NULL )
    xml_to_validate = xml;
  if( xml_to_validate == NULL || valid_context == NULL || ! validation_enabled )
    return true;
  return xmlSchemaValidateDoc(valid_context, xml_to_validate) ? false : true;
}

/**
 * Enables/disables schema validation.
 */
void PageXML::setValidationEnabled( bool val ) {
  validation_enabled = val;
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
int PageXML::write( const char* fname, bool validate ) {
  if ( process_running )
    processEnd();
  xmlDocPtr sortedElemXml = xsltApplyStylesheet( sortelem, xml, NULL );
  xmlDocPtr sortedXml = xsltApplyStylesheet( sortattr, sortedElemXml, NULL );
  xmlFreeDoc(sortedElemXml);
  if( validate && ! isValid(sortedXml) ) {
    xmlFreeDoc(sortedXml);
    throw_runtime_error( "PageXML.write: aborted write of invalid PageXML" );
  }
  int bytes = xmlSaveFormatFileEnc( fname, sortedXml, "utf-8", indent );
  xmlFreeDoc(sortedXml);
  return bytes;
}

/**
 * Creates a string representation of the Page XML.
 */
string PageXML::toString( bool validate ) {
  if ( process_running )
    processEnd();
  string sxml;
  xmlChar *cxml;
  int size;
  xmlDocPtr sortedElemXml = xsltApplyStylesheet( sortelem, xml, NULL );
  xmlDocPtr sortedXml = xsltApplyStylesheet( sortattr, sortedElemXml, NULL );
  xmlFreeDoc(sortedElemXml);
  if( validate && ! isValid(sortedXml) ) {
    xmlFreeDoc(sortedXml);
    throw_runtime_error( "PageXML.toString: aborted conversion to string of invalid PageXML" );
  }
  xmlDocDumpMemory(sortedXml, &cxml, &size);
  xmlFreeDoc(sortedXml);
  if ( cxml == NULL ) {
    throw_runtime_error( "PageXML.toString: problem dumping to memory" );
    return sxml;
  }
  sxml = string((char*)cxml);
  xmlFree(cxml);
  return sxml;
}


/////////////////////
/// Configuration ///
/////////////////////

#if defined (__PAGEXML_LIBCONFIG__)

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
void PageXML::loadConf( const libconfig::Config& config ) {
  if( ! config.exists("PageXML") )
    return;

  const libconfig::Setting& pagecfg = config.getRoot()["PageXML"];

  int numsettings = pagecfg.getLength();
  for( int i = 0; i < numsettings; i++ ) {
    const libconfig::Setting& setting = pagecfg[i];
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
      case PAGEXML_SETTING_GRAYIMG:
        grayimg = (bool)setting;
        break;
      default:
        throw invalid_argument( string("PageXML.loadConf: unexpected configuration property: ") + setting.getName() );
    }
  }
}

#endif

/**
 * Prints the current configuration.
 *
 * @param file  File to print to.
 */
void PageXML::printConf( FILE* file ) {
  fprintf( file, "PageXML: {\n" );
  fprintf( file, "  indent = %s;\n", indent ? "true" : "false" );
  fprintf( file, "  pagens = \"%s\";\n", pagens );
  fprintf( file, "  grayimg = %s;\n", grayimg ? "true" : "false" );
  fprintf( file, "}\n" );
}


///////////////
/// Loaders ///
///////////////

/**
 * Creates a new Page XML.
 *
 * @param creator  Info about tool creating the XML.
 * @param image    Path to the image file.
 * @param imgW     Width of image.
 * @param imgH     Height of image.
 */
xmlNodePt PageXML::newXml( const char* creator, const char* image, const int imgW, const int imgH ) {
  freeXML();

  time_t now;
  time(&now);
  char tstamp[sizeof "YYYY-MM-DDTHH:MM:SSZ"];
  strftime(tstamp, sizeof tstamp, "%FT%TZ", gmtime(&now));

  string str = string("<?xml version=\"1.0\" encoding=\"utf-8\"?>\n")
      + "<PcGts xmlns=\"" + pagens + "\">\n"
      + "  <Metadata>\n"
      + "    <Creator>" + (creator == NULL ? "PageXML.cc" : creator) + "</Creator>\n"
      + "    <Created>" + tstamp + "</Created>\n"
      + "    <LastChange>" + tstamp + "</LastChange>\n"
      + "  </Metadata>\n"
      + "  <Page imageFilename=\"" + image +"\" imageHeight=\"" + to_string(imgH) + "\" imageWidth=\"" + to_string(imgW) + "\"/>\n"
      + "</PcGts>\n";

  xmlKeepBlanksDefault(0);
  xml = xmlParseDoc( (xmlChar*)str.c_str() );
  setupXml();

  if( imgW <= 0 || imgH <= 0 ) {
#if defined (__PAGEXML_LEPT__) || defined (__PAGEXML_IMG_MAGICK__) || defined (__PAGEXML_IMG_CV__)
    loadImage( 0, NULL, false );
#if defined (__PAGEXML_LEPT__)
    int width = pixGetWidth(pagesImage[0]);
    int height = pixGetHeight(pagesImage[0]);
#elif defined (__PAGEXML_IMG_MAGICK__)
    int width = pagesImage[0].columns();
    int height = pagesImage[0].rows();
#elif defined (__PAGEXML_IMG_CV__)
    int width = pagesImage[0].size().width;
    int height = pagesImage[0].size().height;
#endif
    setAttr( "//_:Page", "imageWidth", to_string(width).c_str() );
    setAttr( "//_:Page", "imageHeight", to_string(height).c_str() );
#else
    throw_runtime_error( "PageXML.newXml: invalid image size" );
    freeXML();
    return NULL;
#endif
  }

  return selectNth( "//_:Page", 0 );
}

/**
 * Loads a Page XML from a file.
 *
 * @param fname  File name of the XML file to read.
 */
void PageXML::loadXml( const char* fname, bool validate ) {
  freeXML();

  if ( ! strcmp(fname,"-") ) {
    loadXml( STDIN_FILENO, false, validate );
    return;
  }

  size_t slash_pos = string(fname).find_last_of("/");
  xmlDir = slash_pos == string::npos ?
    string(""):
    string(fname).substr(0,slash_pos);

  FILE *file;
  if ( (file=fopen(fname,"rb")) == NULL ) {
    throw_runtime_error( "PageXML.loadXml: unable to open file: %s", fname );
    return;
  }
  loadXml( fileno(file), false, validate );
  fclose(file);
}

/**
 * Loads a Page XML from an input stream.
 *
 * @param fnum      File number from where to read the XML file.
 * @param prevfree  Whether to release resources before loading.
 */
void PageXML::loadXml( int fnum, bool prevfree, bool validate ) {
  if ( prevfree )
    freeXML();

  xmlKeepBlanksDefault(0);
  xml = xmlReadFd( fnum, NULL, NULL, XML_PARSE_NONET );
  if ( ! xml ) {
    throw_runtime_error( "PageXML.loadXml: problems reading file" );
    return;
  }
  setupXml();

  if( validate && ! isValid() ) {
    freeXML();
    throw_runtime_error( "PageXML.loadXml: aborted load of invalid Page XML" );
  }
}

/**
 * Loads a Page XML from a string.
 *
 * @param xml_string  The XML content.
 */
void PageXML::loadXmlString( const char* xml_string, bool validate ) {
  freeXML();

  xmlKeepBlanksDefault(0);
  xml = xmlParseDoc( (xmlChar*)xml_string );
  if ( ! xml ) {
    throw_runtime_error( "PageXML.loadXmlString: problems reading XML from string" );
    return;
  }
  setupXml();

  if( validate && ! isValid() ) {
    freeXML();
    throw_runtime_error( "PageXML.loadXml: aborted load of invalid Page XML" );
  }
}

/**
 * Populates the imageFilename and pagesImageBase arrays for the given page number.
 */
void PageXML::parsePageImage( int pagenum ) {
  xmlNodePt page = selectNth( "//_:Page", pagenum );
  string imageFilename = getAttr( page, "imageFilename" );
  if( imageFilename.empty() ) {
    throw_runtime_error( "PageXML.parsePageImage: problems retrieving image filename from xml" );
    return;
  }
  pagesImageFilename[pagenum] = imageFilename;

  string imageBase = regex_replace( imageFilename, reFileExt, "" );
  imageBase = regex_replace( imageBase, reInvalidBaseChars, "_" );
  pagesImageBase[pagenum] = imageBase;
}

/**
 * Setups internal variables related to the loaded Page XML.
 */
void PageXML::setupXml() {
  context = xmlXPathNewContext(xml);
  if( context == NULL ) {
    throw_runtime_error( "PageXML.setupXml: unable create xpath context" );
    return;
  }
  if( xmlXPathRegisterNs( context, (xmlChar*)"_", (xmlChar*)pagens ) != 0 ) {
    throw_runtime_error( "PageXML.setupXml: unable to register namespace" );
    return;
  }
  rootnode = xmlDocGetRootElement(xml);
  rpagens = xmlSearchNsByHref(xml,rootnode,(xmlChar*)pagens);

  vector<xmlNodePt> elem_page = select( "//_:Page" );
  if( elem_page.size() == 0 ) {
    throw_runtime_error( "PageXML.setupXml: unable to find Page element(s)" );
    return;
  }

  pagesImage = std::vector<PageImage>(elem_page.size());
  pagesImageFilename = std::vector<std::string>(elem_page.size());
  pagesImageBase = std::vector<std::string>(elem_page.size());

  for( int n=0; n<(int)elem_page.size(); n++ )
    parsePageImage(n);

  if( xmlDir.empty() )
    xmlDir = string(".");
}

#if defined (__PAGEXML_LEPT__) || defined (__PAGEXML_IMG_MAGICK__) || defined (__PAGEXML_IMG_CV__)

/**
 * Function that creates a temporal file using the mktemp command
 *
 * @param tempbase    The mktemp template to use, including at least 3 consecutive X.
 */
void mktemp( const char* tempbase, char *tempname ) {
  char cmd[FILENAME_MAX];
  sprintf( cmd, "mktemp %s", tempbase );
  FILE *p = popen( cmd, "r" );
  if( p != NULL ) {
    sprintf( cmd, "%%%ds\n", FILENAME_MAX-1 );
    if( fscanf( p, cmd, tempname ) != 1 )
      tempname[0] = '\0';
    pclose(p);
  }
}

#if defined (__PAGEXML_MAGICK__)

/**
 * Removes alpha channel, setting all transparent regions to the background color.
 *
 * @param image    Image to process.
 * @param color    Color for the background.
 * @return         Whether flattening was performed.
 */
bool listFlattenImage( Magick::Image& image, const Magick::Color* color = NULL ) {
  if( ! image.matte() )
    return false;
  image.backgroundColor( color == NULL ? colorWhite : *color );
  list<Magick::Image> flattenList = { image };
  Magick::Image flat;
  flattenImages( &flat, flattenList.begin(), flattenList.end() );
  image = flat;
  return true;
}

#endif

/**
 * Releases an already loaded image.
 *
 * @param pagenum        The number of the page for which to release the image.
 */
void PageXML::releaseImage( int pagenum ) {
  if( pagenum < 0 || pagenum >= (int)pagesImageFilename.size() )
    throw_runtime_error( "PageXML.releaseImage: invalid page number: %d", pagenum );

#if defined (__PAGEXML_LEPT__)
  if ( pagesImage[pagenum] != NULL ) {
    pixDestroy(&(pagesImage[pagenum]));
    pagesImage[pagenum] = NULL;
  }
#elif defined (__PAGEXML_IMG_MAGICK__)
  pagesImage[pagenum] = Magick::Image();
#elif defined (__PAGEXML_IMG_CV__)
  pagesImage[pagenum] = cv::Mat();
#endif
}
void PageXML::releaseImage( xmlNodePt node ) {
  return releaseImage( getPageNumber(node) );
}

void PageXML::releaseImages() {
  for( int n=(int)pagesImageFilename.size()-1; n>=0; n-- )
    releaseImage( n );
}

/**
 * Loads an image for a Page in the XML.
 *
 * @param pagenum        The number of the page for which to load the image.
 * @param fname          File name of the image to read, overriding the one in the XML.
 * @param resize_coords  If image size differs, resize page XML coordinates.
 * @param density        Load the image at the given density, resizing the page coordinates if required.
 */
#if defined (__PAGEXML_LEPT__) && defined (__PAGEXML_MAGICK__)
void PageXML::loadImage( int pagenum, const char* fname, const bool resize_coords, const int density ) {
#else
void PageXML::loadImage( int pagenum, const char* fname, const bool resize_coords, const int density __attribute__((unused)) ) {
#endif
  if( pagenum < 0 || pagenum >= (int)pagesImageFilename.size() )
    throw_runtime_error( "PageXML.loadImage: invalid page number: %d", pagenum );
  string aux;
  string fbase;
  if( fname == NULL ) {
    aux = pagesImageFilename[pagenum].at(0) == '/' ? pagesImageFilename[pagenum] : (xmlDir+'/'+pagesImageFilename[pagenum]);
    fname = aux.c_str();
  }

  /// Get image number for multipage files ///
#if defined (__PAGEXML_LEPT__) || defined (__PAGEXML_MAGICK__)
  int imgnum = 0;
#endif
#if defined (__PAGEXML_MAGICK__)
  fbase = string(fname);
  cmatch base_match;
  if( std::regex_match(fname,base_match,reImagePageNum) ) {
    imgnum = stoi(base_match[2].str())-1;
    aux = base_match[1].str() + "[" + std::to_string(imgnum) + "]";
    fname = aux.c_str();
    fbase = string(base_match[1]);
  }
#endif

  releaseImage(pagenum);
#if defined (__PAGEXML_LEPT__)
#if defined (__PAGEXML_MAGICK__)
  /// Leptonica load pdf page ///
  if( std::regex_match(fname, reIsPdf) ) {
    int ldensity = density;
    if( ! density ) {
      if( resize_coords )
        throw_runtime_error( "PageXML.loadImage: density is required when reading pdf with resize_coords option" );
      Magick::Image ptmp;
      ptmp.ping(fname);
      double Dw = 72.0*getPageWidth(pagenum)/ptmp.columns();
      double Dh = 72.0*getPageHeight(pagenum)/ptmp.rows();
      ldensity = std::round(0.5*(Dw+Dh));
    }
    Magick::Image tmp;
    tmp.density(std::to_string(ldensity).c_str());
    tmp.read(fname);
    listFlattenImage(tmp);
    char tmpfname[FILENAME_MAX];
    std::string tmpbase = std::string("tmp_PageXML_pdf_")+std::to_string(pagenum)+"_XXXXXXXX.png";
    mktemp( tmpbase.c_str(), tmpfname );
    tmp.resolutionUnits(MagickCore::ResolutionType::PixelsPerInchResolution);
    tmp.write( (std::string("png24:")+tmpfname).c_str() );
    pagesImage[pagenum] = pixRead(tmpfname);
    unlink(tmpfname);
  }
#endif
  if( pagesImage[pagenum] == NULL ) {
    /// Leptonica load tiff page ///
    if( std::regex_match(fname, reIsTiff) ) {
      PIXA* tiffimage = pixaReadMultipageTiff( fbase.c_str() );
      if( tiffimage == NULL || tiffimage->n == 0 )
        throw_runtime_error( "PageXML.loadImage: problems reading tiff image: %s", fbase.c_str() );
      if( imgnum >= tiffimage->n )
        throw_runtime_error( "PageXML.loadImage: requested page %d but tiff image only has %d pages: %s", imgnum+1, tiffimage->n, fbase.c_str() );
      pagesImage[pagenum] = pixClone(tiffimage->pix[imgnum]);
      pixaDestroy(&tiffimage);
    }
    /// Leptonica load other image formats ///
    else
      pagesImage[pagenum] = pixRead(fname);
  }
  if( pagesImage[pagenum] == NULL ) {
    throw_runtime_error( "PageXML.loadImage: problems reading image: %s", fname );
    return;
  }
#elif defined (__PAGEXML_IMG_MAGICK__)
  /// ImageMagick load image ///
  try {
    if( density )
      pagesImage[pagenum].density(std::to_string(density).c_str());
    pagesImage[pagenum].read(fname);
    if( std::regex_match(fname, reIsPdf) )
      listFlattenImage( pagesImage[pagenum] );
    pagesImage[pagenum].page( Magick::Geometry(0,0,0,0) );
  }
  catch( exception& e ) {
    throw_runtime_error( "PageXML.loadImage: problems reading image: %s", e.what() );
    return;
  }
#elif defined (__PAGEXML_IMG_CV__)
#if defined (__PAGEXML_MAGICK__)
  /// OpenCV load pdf page ///
  if( std::regex_match(fname, reIsPdf) ) {
    int ldensity = density;
    if( ! density ) {
      if( resize_coords )
        throw_runtime_error( "PageXML.loadImage: density is required when reading pdf with resize_coords option" );
      Magick::Image ptmp;
      ptmp.ping(fname);
      double Dw = 72.0*getPageWidth(pagenum)/ptmp.columns();
      double Dh = 72.0*getPageHeight(pagenum)/ptmp.rows();
      ldensity = std::round(0.5*(Dw+Dh));
    }
    Magick::Image tmp;
    tmp.density(std::to_string(ldensity).c_str());
    tmp.read(fname);
    char tmpfname[FILENAME_MAX];
    std::string tmpbase = std::string("tmp_PageXML_pdf_")+std::to_string(pagenum)+"_XXXXXXXX.png";
    mktemp( tmpbase.c_str(), tmpfname );
    tmp.resolutionUnits(MagickCore::ResolutionType::PixelsPerInchResolution);
    tmp.write( (std::string("png24:")+tmpfname).c_str() );
    pagesImage[pagenum] = grayimg ? cv::imread(fname,CV_LOAD_IMAGE_GRAYSCALE) : cv::imread(tmpfname);
    unlink(tmpfname);
  }
  else
#endif
  /// OpenCV load other image formats ///
  pagesImage[pagenum] = grayimg ? cv::imread(fname,CV_LOAD_IMAGE_GRAYSCALE) : cv::imread(fname);
  if ( ! pagesImage[pagenum].data ) {
    throw_runtime_error( "PageXML.loadImage: problems reading image: %s", fname );
    return;
  }
#endif

  /// Convert to grayscale: Leptonica or ImageMagick ///
  if( grayimg ) {
#if defined (__PAGEXML_LEPT__)
    Pix *orig = pagesImage[pagenum];
    pagesImage[pagenum] = pixConvertRGBToGray(orig,0.0,0.0,0.0);
    pixDestroy(&orig);
#elif defined (__PAGEXML_IMG_MAGICK__)
    if( pagesImage[pagenum].matte() && pagesImage[pagenum].type() != Magick::GrayscaleMatteType )
      pagesImage[pagenum].type( Magick::GrayscaleMatteType );
    else if( ! pagesImage[pagenum].matte() && pagesImage[pagenum].type() != Magick::GrayscaleType )
      pagesImage[pagenum].type( Magick::GrayscaleType );
#endif
  }

#if defined (__PAGEXML_LEPT__)
  int imgwidth = pixGetWidth(pagesImage[pagenum]);
  int imgheight = pixGetHeight(pagesImage[pagenum]);
#elif defined (__PAGEXML_IMG_MAGICK__)
  int imgwidth = (int)pagesImage[pagenum].columns();
  int imgheight = (int)pagesImage[pagenum].rows();
#elif defined (__PAGEXML_IMG_CV__)
  int imgwidth = pagesImage[pagenum].size().width;
  int imgheight = pagesImage[pagenum].size().height;
#endif
#if defined (__PAGEXML_IMG_MAGICK__)
  int imgwidth_orig = imgwidth;
  int imgheight_orig = imgheight;
#endif
  int angle = getPageImageOrientation( pagenum );
  if ( angle == 90 || angle == 180 )
    std::swap(imgwidth, imgheight);
  int width = getPageWidth(pagenum);
  int height = getPageHeight(pagenum);

  /// Resize XML coords if required ///
  if( ( width != imgwidth || height != imgheight ) && resize_coords ) {
    double ratio_diff = imgwidth < imgheight ?
      (double)imgwidth/imgheight - (double)width/height:
      (double)imgheight/imgwidth - (double)height/width;
    if ( fabs(ratio_diff) > 1e-2 )
      throw_runtime_error( "PageXML.loadImage: aspect ratio too different for page %d (%ux%u vs. %ux%u)", pagenum, width, height, imgwidth, imgheight );
    xmlNodePt page = selectNth("//_:Page",pagenum);
    resize( cv::Size2i(imgwidth,imgheight), page, true );
    width = getPageWidth(page);
    height = getPageHeight(page);
  }

  /// Check that image size agrees with XML ///
  if( width != imgwidth || height != imgheight )
    throw_runtime_error( "PageXML.loadImage: discrepancy between image and xml page size (%dx%d vs. %dx%d): %s", imgwidth, imgheight, width, height, fname );

  /// Check image orientation and rotate accordingly ///
  if ( angle ) {
#if defined (__PAGEXML_LEPT__)
    Pix *orig = pagesImage[pagenum];
    if ( angle == 90 )
      pagesImage[pagenum] = pixRotateOrth(orig,1);
    else if ( angle == 180 )
      pagesImage[pagenum] = pixRotateOrth(orig,2);
    else if ( angle == -90 )
      pagesImage[pagenum] = pixRotateOrth(orig,3);
    pixDestroy(&orig);
#elif defined (__PAGEXML_IMG_MAGICK__)
    if( angle != 0 ) {
      Magick::Image rotated( Magick::Geometry(imgwidth, imgheight), Magick::Color("black") );
      Magick::Pixels view_orig(pagesImage[pagenum]);
      Magick::Pixels view_rot(rotated);
      const Magick::PixelPacket *pixs_orig = view_orig.getConst( 0, 0, imgwidth_orig, imgheight_orig );
      Magick::PixelPacket *pixs_rot = view_rot.get( 0, 0, imgwidth, imgheight );
      if ( angle == 90 ) {
        for( int y=0, n=0; y<imgheight_orig; y++ )
          for( int x=0; x<imgwidth_orig; x++, n++ )
            pixs_rot[x*imgwidth+(imgwidth-1-y)] = pixs_orig[n];
      }
      else if ( angle == 180 ) {
        for( int y=0, n=0; y<imgheight_orig; y++ )
          for( int x=0; x<imgwidth_orig; x++, n++ )
            pixs_rot[(imgheight-1-y)*imgwidth+(imgwidth-1-x)] = pixs_orig[n];
      }
      else if ( angle == -90 ) {
        for( int y=0, n=0; y<imgheight_orig; y++ )
          for( int x=0; x<imgwidth_orig; x++, n++ )
            pixs_rot[(imgheight-1-x)*imgwidth+y] = pixs_orig[n];
      }
      view_rot.sync();
      pagesImage[pagenum] = rotated;
    }
#elif defined (__PAGEXML_IMG_CV__)
    PageImage rotated;
    if ( angle == 90 ) {
      cv::transpose(pagesImage[pagenum], rotated);
      cv::flip(rotated, rotated, 1); //transpose+flip(1)=CW
    }
    else if ( angle == 180 ) {
      cv::flip(pagesImage[pagenum], rotated, -1); //flip(-1)=180
    }
    else if ( angle == -90 ) {
      cv::transpose(pagesImage[pagenum], rotated);
      cv::flip(rotated, rotated, 0); //transpose+flip(0)=CCW
    }
    pagesImage[pagenum] = rotated;
#endif
  }
}

void PageXML::loadImage( xmlNodePt node, const char* fname, const bool resize_coords, const int density ) {
  int pagenum = getPageNumber(node);
  if( pagenum >= 0 )
    return loadImage( pagenum, fname, resize_coords, density );
  throw_runtime_error( "PageXML.loadImage: node must be a Page or descendant of a Page" );
}

void PageXML::loadImages( const bool resize_coords, const int density ) {
  int numpages = count("//_:Page");
  for( int n=0; n<numpages; n++ )
    loadImage( n, NULL, resize_coords, density );
}


#endif

///////////////////////
/// Page processing ///
///////////////////////

#ifdef __PAGEXML_IMG_MAGICK__

/**
 * Converts an cv vector of points to a Magick++ list of Coordinates.
 *
 * @param points   Vector of points.
 * @return         List of coordinates.
 */
list<Magick::Coordinate> cvToMagick( const vector<cv::Point2f>& points ) {
//list<Magick::Coordinate> PageXML::cvToMagick( const vector<cv::Point2f>& points ) {
  list<Magick::Coordinate> mpoints;
  for( int n=0; n<(int)points.size(); n++ ) {
    mpoints.push_back( Magick::Coordinate( points[n].x, points[n].y ) );
  }
  return mpoints;
}

#endif

/**
 * Parses a string of pairs of coordinates (x1,y1 [x2,y2 ...]) into an array.
 *
 * @param spoints  String containing coordinate pairs.
 * @return         Array of (x,y) coordinates.
 */
vector<cv::Point2f> PageXML::stringToPoints( const char* spoints ) {
  vector<cv::Point2f> points;

  int n = 0;
  char *p = (char*)spoints-1;
  while( true ) {
    p++;
    double x, y;
    if( sscanf( p, "%lf,%lf", &x, &y ) != 2 )
      break;
    points.push_back(cv::Point2f(x,y));
    n++;
    if( (p = strchr(p,' ')) == NULL )
      break;
  }

  return points;
}

/**
 * Parses a string of pairs of coordinates (x1,y1 [x2,y2 ...]) into an array.
 *
 * @param spoints  String containing coordinate pairs.
 * @return         Array of (x,y) coordinates.
 */
vector<cv::Point2f> PageXML::stringToPoints( string spoints ) {
  return stringToPoints( spoints.c_str() );
}

/**
 * Gets the minimum and maximum coordinate values for an array of points.
 *
 * @param points     The vector of points to find the limits.
 * @param xmin       Minimum x value.
 * @param xmax       Maximum x value.
 * @param ymin       Minimum y value.
 * @param ymax       Maximum y value.
 */
void PageXML::pointsLimits( vector<cv::Point2f>& points, double& xmin, double& xmax, double& ymin, double& ymax ) {
  if( points.size() == 0 )
    return;

  xmin = xmax = points[0].x;
  ymin = ymax = points[0].y;

  for( auto&& point : points ) {
    if( xmin > point.x ) xmin = point.x;
    if( xmax < point.x ) xmax = point.x;
    if( ymin > point.y ) ymin = point.y;
    if( ymax < point.y ) ymax = point.y;
  }

  return;
}

/**
 * Generates a vector of 4 points that define the bounding box for a given vector of points.
 *
 * @param points     The vector of points to find the limits.
 * @return           The 4 points defining the bounding box (top-left clockwise).
 */
std::vector<cv::Point2f> PageXML::pointsBBox( std::vector<cv::Point2f> points ) {
  std::vector<cv::Point2f> bbox;
  if( points.size() == 0 )
    return bbox;

  double xmin = std::numeric_limits<double>::quiet_NaN();
  double xmax = std::numeric_limits<double>::quiet_NaN();
  double ymin = std::numeric_limits<double>::quiet_NaN();
  double ymax = std::numeric_limits<double>::quiet_NaN();

  pointsLimits( points, xmin, xmax, ymin, ymax );

  bbox.push_back( cv::Point2f(xmin,ymin) );
  bbox.push_back( cv::Point2f(xmax,ymin) );
  bbox.push_back( cv::Point2f(xmax,ymax) );
  bbox.push_back( cv::Point2f(xmin,ymax) );

  return bbox;
}

/**
 * Determines whether a vector of points defines a bounding box.
 *
 * @param points   The vector of points to find the limits.
 * @return         True if bounding box, otherwise false.
 */
bool PageXML::isBBox( const vector<cv::Point2f>& points ) {
  if( points.size() == 4 &&
      points[0].x == points[3].x &&
      points[0].y == points[1].y &&
      points[1].x == points[2].x &&
      points[2].y == points[3].y )
    return true;
  return false;
}

/**
 * Cronvers a vector of points to a string in format "x1,y1 x2,y2 ...".
 *
 * @param points   Vector of points.
 * @param rounded  Whether to round values.
 * @return         String representation of the points.
 */
string PageXML::pointsToString( vector<cv::Point2f> points, bool rounded ) {
  char val[64];
  string str("");
  for( size_t n=0; n<points.size(); n++ ) {
    if( rounded )
      sprintf( val, "%.0f,%.0f", points[n].x, points[n].y );
    else
      sprintf( val, "%g,%g",
        fabs(points[n].x) < 1e-4 ? 0.0 : points[n].x,
        fabs(points[n].y) < 1e-4 ? 0.0 : points[n].y );
    str += ( n == 0 ? "" : " " ) + string(val);
  }
  return str;
}

/**
 * Cronvers a vector of points to a string in format "x1,y1 x2,y2 ...".
 *
 * @param points  Vector of points.
 * @return        String representation of the points.
 */
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
 * Returns number of matched nodes for a given xpath.
 *
 * @param xpath  Selector expression.
 * @param node   XML node for context, set to NULL for root node.
 * @return       Number of matched nodes.
 */
int PageXML::count( const char* xpath, xmlNodePt node ) {
  return select( xpath, node ).size();
}

/**
 * Returns number of matched nodes for a given xpath.
 *
 * @param xpath  Selector expression.
 * @param node   XML node for context, set to NULL for root node.
 * @return       Number of matched nodes.
 */
int PageXML::count( string xpath, xmlNodePt node ) {
  return select( xpath.c_str(), node ).size();
}

/**
 * Selects nodes given an xpath.
 *
 * @param xpath  Selector expression.
 * @param node   XML node for context, set to NULL for root node.
 * @return       Vector of matched nodes.
 */
vector<xmlNodePt> PageXML::select( const char* xpath, const xmlNodePt node ) {
  vector<xmlNodePt> matched;

#define __REUSE_CONTEXT__

#ifdef __REUSE_CONTEXT__
  xmlXPathContextPtr ncontext = context;
#else
  xmlXPathContextPtr ncontext = xmlXPathNewContext(xml);
  if( ncontext == NULL ) {
    throw_runtime_error( "PageXML.select: unable to create xpath context" );
    return matched;
  }
  if( xmlXPathRegisterNs( ncontext, (xmlChar*)"_", (xmlChar*)pagens ) != 0 ) {
    throw_runtime_error( "PageXML.select: unable to register namespace" );
    return matched;
  }
#endif
  ncontext->node = node == NULL ? (xmlNodePtr)rootnode : (xmlNodePtr)node;

  xmlXPathObjectPtr xsel = xmlXPathEvalExpression( (xmlChar*)xpath, ncontext );
#ifndef __REUSE_CONTEXT__
  xmlXPathFreeContext(ncontext);
#endif

  if( xsel == NULL ) {
    throw_runtime_error( "PageXML.select: xpath expression failed: %s", xpath );
    return matched;
  }
  else {
    if( ! xmlXPathNodeSetIsEmpty(xsel->nodesetval) )
      for( int n=0; n<xsel->nodesetval->nodeNr; n++ )
        matched.push_back( xsel->nodesetval->nodeTab[n] );
    xmlXPathFreeObject(xsel);
  }

  return matched;
}

/**
 * Selects nodes given an xpath.
 *
 * @param xpath  Selector expression.
 * @param node   XML node for context, set to NULL for root node.
 * @return       Vector of matched nodes.
 */
vector<xmlNodePt> PageXML::select( string xpath, const xmlNodePt node ) {
  return select( xpath.c_str(), node );
}

/**
 * Selects nodes given an xpath and a vector of base nodes.
 *
 * @param xpath   Selector expression.
 * @param nodes   XML nodes for context.
 * @param unique  Whether to return unique matches.
 * @return        Vector of matched nodes.
 */
vector<xmlNodePt> PageXML::select( const char* xpath, const vector<xmlNodePt> nodes, bool unique ) {
  vector<xmlNodePt> matched;
  set<xmlNodePt> seen;

  for( int n=0; n<(int)nodes.size(); n++ ) {
    vector<xmlNodePt> matched_n = select( xpath, nodes[n] );
    if( ! unique )
      matched.insert( matched.end(), matched_n.begin(), matched_n.end() );
    else
      for( int m=0; m<(int)matched_n.size(); m++ )
        if( seen.count(matched_n[m]) == 0 ) {
          matched.push_back(matched_n[m]);
          seen.insert(matched_n[m]);
        }
  }

  return matched;
}

/**
 * Selects the n-th node that matches an xpath.
 *
 * @param xpath  Selector expression.
 * @param num    Element number (0-indexed), negative from last.
 * @param node   XML node for context, set to NULL for root node.
 * @return       Matched node.
 */
xmlNodePt PageXML::selectNth( const char* xpath, int num, const xmlNodePt node ) {
  vector<xmlNodePt> matches = select( xpath, node );
  if( num >= (int)matches.size() || num < -(int)matches.size() )
    return NULL;
  return matches[ num < 0 ? matches.size()+num : num ];
}

/**
 * Selects the n-th node that matches an xpath.
 *
 * @param xpath  Selector expression.
 * @param num    Element number (0-indexed), negative from last.
 * @param node   XML node for context, set to NULL for root node.
 * @return       Matched node.
 */
xmlNodePt PageXML::selectNth( string xpath, int num, const xmlNodePt node ) {
  return selectNth( xpath.c_str(), num, node );
}

/**
 * Selects an element with a given ID.
 *
 * @param id     ID of element to select.
 * @param node   XML node for context, set to NULL for root node.
 * @return       Matched node.
 */
xmlNodePt PageXML::selectByID( const char* id, const xmlNodePt node ) {
  vector<xmlNodePt> sel = select( (string(".//*[@id='")+id+"']").c_str(), node );
  return sel.size() == 0 ? NULL : sel[0];
}

/**
 * Filters a vector of xml nodes given an xpath.
 *
 * @param xpath  Filtering expression.
 * @param elems  Vector of nodes to filter.
 * @return       Vector of filtered nodes.
 */
std::vector<xmlNodePt> PageXML::filter( const char* xpath, const std::vector<xmlNodePt> elems ) {
  std::vector<xmlNodePt> filtered;
  for ( int n=0; n<(int)elems.size(); n++ ) {
    std::vector<xmlNodePt> sel = select( xpath, elems[n]->parent );
    if ( std::find(sel.begin(), sel.end(), elems[n]) != sel.end() )
      filtered.push_back(elems[n]);
  }
  return filtered;
}

/**
 * Selects closest node of a given name.
 */
xmlNodePt PageXML::closest( const char* name, xmlNodePt node ) {
  return selectNth( string("ancestor-or-self::*[local-name()='")+name+"']", 0, node );
}

/**
 * Returns the parent of a node.
 *
 * @param node   XML node.
 * @return       Parent node.
 */
xmlNodePt PageXML::parent( const xmlNodePt node ) {
  return node->parent;
}

/**
 * Checks if node is of given name.
 *
 * @param node  XML node.
 * @param name  String with name to match against.
 * @return      True if name matches, otherwise false.
 */
bool PageXML::nodeIs( xmlNodePt node, const char* name ) {
  return ! node || xmlStrcmp( node->name, (const xmlChar*)name ) ? false : true;
}

/**
 * Gets the name of the given node.
 *
 * @param node  XML node.
 * @return      String with the name.
 */
std::string PageXML::getNodeName( xmlNodePt node, xmlNodePt base_node ) {
  string nodename = getAttr( node, "id" );
  if( nodename.empty() ) {
    throw_runtime_error( "PageXML.getNodeName: expected element to include id attribute" );
    return nodename;
  }
  
  if( base_node != NULL )
    nodename = getValue(base_node) + "." + nodename;
  else {
    xmlNodePt page = selectNth( "ancestor-or-self::*[local-name()='Page']", 0, node );
    nodename = pagesImageBase[getPageNumber(page)] + "." + nodename;
  }

  return nodename;
}

#if defined (__PAGEXML_LEPT__) || defined (__PAGEXML_IMG_MAGICK__) || defined (__PAGEXML_IMG_CV__)

/**
 * Crops images using its Coords polygon, regions outside the polygon are set to transparent.
 *
 * @param xpath          Selector for polygons to crop.
 * @param margin         Margins, if >1.0 pixels, otherwise percentage of maximum of crop width and height.
 * @param opaque_coords  Whether to include an alpha channel with the polygon interior in opaque.
 * @param transp_xpath   Selector for semi-transparent elements.
 * @return               An std::vector containing NamedImage objects of the cropped images.
 */
vector<NamedImage> PageXML::crop( const char* xpath, cv::Point2f* margin, bool opaque_coords, const char* transp_xpath, const char* base_xpath ) {
  vector<NamedImage> images;

  vector<xmlNodePt> elems_coords = select( xpath );
  if( elems_coords.size() == 0 )
    return images;

  xmlNodePt prevPage = NULL;
  //string imageBase;
  unsigned int width = 0;
  unsigned int height = 0;
#if defined (__PAGEXML_LEPT__)
  PageImage pageImage = NULL;
#else
  PageImage pageImage;
#endif

  xmlNodePt base_node = NULL;
  if( base_xpath != NULL ) {
    base_node = selectNth( base_xpath, 0 );
    if( base_node == NULL ) {
      throw_runtime_error( "PageXML.crop: base xpath did not match any nodes: xpath=%s", base_xpath );
      return images;
    }
  }
  // @todo Allow base_xpath to be relative to node, e.g. to select a different property for each page, region, etc.

  for( int n=0; n<(int)elems_coords.size(); n++ ) {
    xmlNodePt node = elems_coords[n];

    if( ! nodeIs( node, "Coords") ) {
      throw_runtime_error( "PageXML.crop: expected xpath to match only Coords elements: match=%d xpath=%s", n+1, xpath );
      return images;
    }

    xmlNodePt page = selectNth( "ancestor-or-self::*[local-name()='Page']", 0, node );
    if( prevPage != page ) {
      prevPage = page;
      int pagenum = getPageNumber(page);
      //imageBase = pagesImageBase[pagenum];
      width = getPageWidth(page);
      height = getPageHeight(page);
      #if defined (__PAGEXML_LEPT__)
        if( pagesImage[pagenum] == NULL )
      #elif defined (__PAGEXML_IMG_MAGICK__)
        if( pagesImage[pagenum].columns() == 0 )
      #elif defined (__PAGEXML_IMG_CV__)
        if( ! pagesImage[pagenum].data )
      #endif
          loadImage(pagenum);
        pageImage = pagesImage[pagenum];
    }

    /// Get parent node id ///
    string sampid = getAttr( node->parent, "id" );
    if( sampid.empty() ) {
      throw_runtime_error( "PageXML.crop: expected parent element to include id attribute: match=%d xpath=%s", n+1, xpath );
      return images;
    }

    /// Construct sample name ///
    //string sampname = imageBase + "." + sampid;
    std::string sampname = getNodeName( node->parent, base_node );

    /// Get coords points ///
    string spoints = getAttr( node, "points" );
    if( spoints.empty() ) {
      throw_runtime_error( "PageXML.crop: expected a points attribute in Coords element: id=%s", sampid.c_str() );
      return images;
    }
    vector<cv::Point2f> coords = stringToPoints( spoints );

    /// Get crop window parameters ///
    double xmin=0, xmax=0, ymin=0, ymax=0;
    pointsLimits( coords, xmin, xmax, ymin, ymax );
    size_t cropW = (size_t)(ceil(xmax)-floor(xmin)+1);
    size_t cropH = (size_t)(ceil(ymax)-floor(ymin)+1);
    int cropX = (int)floor(xmin);
    int cropY = (int)floor(ymin);

    /// Add margin to bounding box ///
    if( margin != NULL ) {
      int maxWH = cropW > cropH ? cropW : cropH;
      int ocropX = cropX;
      int ocropY = cropY;
      cropX -= margin[0].x < 1.0 ? maxWH*margin[0].x : margin[0].x;
      cropY -= margin[0].y < 1.0 ? maxWH*margin[0].y : margin[0].y;
      cropX = cropX < 0 ? 0 : cropX;
      cropY = cropY < 0 ? 0 : cropY;
      cropW += ocropX - cropX;
      cropH += ocropY - cropY;
      cropW += margin[1].x < 1.0 ? maxWH*margin[1].x : margin[1].x;
      cropH += margin[1].y < 1.0 ? maxWH*margin[1].y : margin[1].y;
      cropW = cropX+cropW-1 >= width ? width-cropX-1 : cropW;
      cropH = cropY+cropH-1 >= height ? height-cropY-1 : cropH;
    }

    /// Crop image ///
#if defined (__PAGEXML_LEPT__)
    BOX* box = boxCreate(cropX, cropY, cropW, cropH);
    Pix* cropimg = pixClipRectangle(pageImage, box, NULL);
    boxDestroy(&box);
#elif defined (__PAGEXML_IMG_MAGICK__)
    Magick::Image cropimg = pageImage;
    try {
      cropimg.crop( Magick::Geometry(cropW,cropH,cropX,cropY) );
    }
    catch( exception& error ) {
      fprintf( stderr, "PageXML.crop: error (%s): %s\n", sampname.c_str(), error.what() );
      continue;
    }

    //if( cropimg.columns() != cropW || cropimg.rows() != cropH || cropimg.page().xOff() != cropX || cropimg.page().yOff() != cropY )
    //  fprintf(stderr,"warning: modified crop for id=%s, requested: %zux%zu+%d+%d vs. obtained: %zux%zu+%ld+%ld\n", sampid.c_str(), cropW,cropH,cropX,cropY, cropimg.columns(),cropimg.rows(),cropimg.page().xOff(),cropimg.page().yOff() );

#elif defined (__PAGEXML_IMG_CV__)
    cv::Rect rect_image(0, 0, width, height);
    cv::Rect rect_crop(cropX, cropY, cropW, cropH);
    cv::Rect roi = rect_image & rect_crop;
    if( roi.area() <= 0 ) {
      fprintf( stderr, "PageXML.crop: error (%s): crop window completely outside of image region\n", sampname.c_str() );
      continue;
    }
    cv::Mat cropimg = pageImage(roi);
#endif

    if( opaque_coords /*&& ! isBBox( coords )*/ ) {
#if defined (__PAGEXML_LEPT__)
      if( transp_xpath != NULL ) {
        throw_runtime_error( "PageXML.crop: transp_xpath not implemented for __PAGEXML_LEPT__" );
        return images;
      }
      throw_runtime_error( "PageXML.crop: opaque_coords not implemented for __PAGEXML_LEPT__" );
      return images;

#elif defined (__PAGEXML_IMG_MAGICK__)
      /// Subtract crop window offset ///
      for( auto&& coord : coords ) {
        coord.x -= cropX;
        coord.y -= cropY;
      }

      /// Add transparency layer ///
      list<Magick::Drawable> drawList;
      drawList.push_back( Magick::DrawableStrokeColor(opaque) );
      drawList.push_back( Magick::DrawableFillColor(opaque) );
      drawList.push_back( Magick::DrawableFillRule(Magick::NonZeroRule) );
      drawList.push_back( Magick::DrawableStrokeAntialias(false) );
      drawList.push_back( Magick::DrawablePolygon(cvToMagick(coords)) );
      Magick::Image mask( Magick::Geometry(cropW,cropH), transparent );
      mask.draw(drawList);
      cropimg.draw( Magick::DrawableCompositeImage(0,0,0,0,mask,Magick::CopyOpacityCompositeOp) );

      if( transp_xpath != NULL ) {
        throw_runtime_error( "PageXML.crop: transp_xpath not implemented for __PAGEXML_IMG_MAGICK__" );
        return images;
      }

#elif defined (__PAGEXML_IMG_CV__)
      /// Subtract crop window offset and round points ///
      std::vector<cv::Point> rcoods;
      std::vector<std::vector<cv::Point> > polys;
      for( auto&& coord : coords )
        rcoods.push_back( cv::Point( round(coord.x-cropX), round(coord.y-cropY) ) );
      polys.push_back(rcoods);

      /// Draw opaque polygon for Coords ///
      cv::Mat wmask( cropimg.size(), CV_MAKE_TYPE(cropimg.type(),cropimg.channels()+1), cv::Scalar(0,0,0,0) );
      cv::fillPoly( wmask, polys, cv::Scalar(0,0,0,255) );

      /// Draw semi-transparent polygons according to xpath ///
      if( transp_xpath != NULL ) {
        vector<xmlNodePt> child_coords = select( transp_xpath, node );

        polys.clear();
        for( int m=0; m<(int)child_coords.size(); m++ ) {
          xmlNodePt childnode = child_coords[m];

          string childid = getAttr( childnode->parent, "id" );

          spoints = getAttr( childnode, "points" );
          if( spoints.empty() ) {
            throw_runtime_error( "PageXML.crop: expected a points attribute in Coords element: id=%s", childid.c_str() );
            return images;
          }
          coords = stringToPoints( spoints );

          std::vector<cv::Point> rcoods;
          for( auto&& coord : coords )
            rcoods.push_back( cv::Point( round(coord.x-cropX), round(coord.y-cropY) ) );
          polys.push_back(rcoods);
        }
        cv::fillPoly( wmask, polys, cv::Scalar(0,0,0,128) );
      }

      /// Add alpha channel to image ///
      int from_to[] = { 0,0, 1,1, 2,2 };
      cv::mixChannels( &cropimg, 1, &wmask, 1, from_to, cropimg.channels() );
      cropimg = wmask;
#endif
    }

    double rotation = std::numeric_limits<double>::quiet_NaN();
    if ( nodeIs( node->parent, "TextLine" ) )
      rotation = getBaselineOrientation( node->parent )*180.0/M_PI;
    if ( std::isnan(rotation) )
      rotation = getRotation(node->parent);

    /// Append crop and related data to list ///
    NamedImage namedimage(
      sampid,
      sampname,
      rotation,
      getReadingDirection(node->parent),
      cropX,
      cropY,
      cropimg,
      node );

    images.push_back(namedimage);
  }

  return images;
}

#endif

/**
 * Retrieves a node value.
 *
 * @param node       Node element.
 * @return           String with the node value.
 */
std::string PageXML::getValue( xmlNodePt node ) {
  if( node == NULL )
    throw_runtime_error( "PageXML.getValue: received NULL pointer" );
  xmlChar* val = xmlNodeGetContent(node);
  std::string text = (char*)val;
  xmlFree(val);
  return text;
}

/**
 * Retrieves a node value.
 *
 * @param xpath      Selector for the element to get the value.
 * @param node       XML node for context, set to NULL for root node.
 * @return           String with the node value.
 */
std::string PageXML::getValue( const char* xpath, const xmlNodePt node ) {
  return getValue( selectNth( xpath, 0, node ) );
}

/**
 * Sets a node value.
 *
 * @param node       Node element.
 * @return           String with the node value.
 */
void PageXML::setValue( xmlNodePt node, const char* value ) {
  if( node == NULL || value == NULL )
    throw_runtime_error( "PageXML.setValue: received NULL pointer (node=%p, value=%p)", node, value );
  xmlNodeSetContent( node, (xmlChar*)value );
}

/**
 * Gets an attribute value from an xml node.
 *
 * @param node   XML node.
 * @param name   Attribute name.
 * @param value  String to set the value.
 * @return       True if attribute found, otherwise false.
*/
string PageXML::getAttr( const xmlNodePt node, const char* name ) {
  string value("");
  if( node == NULL )
    return value;

  xmlChar* attr = xmlGetProp( node, (xmlChar*)name );
  if( attr == NULL )
    return value;
  value = string((char*)attr);
  xmlFree(attr);

  return value;
}

/**
 * Gets an attribute value for a given xpath.
 *
 * @param xpath  Selector for the element to get the attribute.
 * @param name   Attribute name.
 * @param value  String to set the value.
 * @return       True if attribute found, otherwise false.
*/
string PageXML::getAttr( const char* xpath, const char* name ) {
  vector<xmlNodePt> xsel = select( xpath );
  if( xsel.size() == 0 )
    return string("");

  return getAttr( xsel[0], name );
}

/**
 * Gets an attribute value for a given xpath.
 *
 * @param xpath  Selector for the element to get the attribute.
 * @param name   Attribute name.
 * @param value  String to set the value.
 * @return       True if attribute found, otherwise false.
*/
string PageXML::getAttr( const string xpath, const string name ) {
  vector<xmlNodePt> xsel = select( xpath.c_str() );
  if( xsel.size() == 0 )
    return string("");

  return getAttr( xsel[0], name.c_str() );
}

/**
 * Adds or modifies (if already exists) an attribute for a given list of nodes.
 *
 * @param nodes  Vector of nodes to set the attribute.
 * @param name   Attribute name.
 * @param value  Attribute value.
 * @return       Number of elements modified.
 */
int PageXML::setAttr( vector<xmlNodePt> nodes, const char* name, const char* value ) {
  for( int n=(int)nodes.size()-1; n>=0; n-- ) {
    xmlAttrPtr attr = xmlHasProp( nodes[n], (xmlChar*)name ) ?
      xmlSetProp( nodes[n], (xmlChar*)name, (xmlChar*)value ) :
      xmlNewProp( nodes[n], (xmlChar*)name, (xmlChar*)value ) ;
    if( ! attr ) {
      throw_runtime_error( "PageXML.setAttr: problems setting attribute: name=%s", name );
      return 0;
    }
  }

  return (int)nodes.size();
}

/**
 * Adds or modifies (if already exists) an attribute for a given node.
 *
 * @param node   Node to set the attribute.
 * @param name   Attribute name.
 * @param value  Attribute value.
 * @return       Number of elements modified.
 */
int PageXML::setAttr( const xmlNodePt node, const char* name, const char* value ) {
  return setAttr( vector<xmlNodePt>{(xmlNodePtr)node}, name, value );
}

/**
 * Adds or modifies (if already exists) an attribute for a given xpath.
 *
 * @param xpath  Selector for the element(s) to set the attribute.
 * @param name   Attribute name.
 * @param value  Attribute value.
 * @return       Number of elements modified.
 */
int PageXML::setAttr( const char* xpath, const char* name, const char* value ) {
  return setAttr( select(xpath), name, value );
}

/**
 * Adds or modifies (if already exists) an attribute for a given xpath.
 *
 * @param xpath  Selector for the element(s) to set the attribute.
 * @param name   Attribute name.
 * @param value  Attribute value.
 * @return       Number of elements modified.
 */
int PageXML::setAttr( const string xpath, const string name, const string value ) {
  return setAttr( select(xpath.c_str()), name.c_str(), value.c_str() );
}

/**
 * Inserts an element relative to a given node.
 *
 * @param elem   Element to insert.
 * @param node   Reference element for insertion.
 * @param itype  Type of insertion.
 * @return       Pointer to inserted element.
 */
xmlNodePt PageXML::insertElem( xmlNodePt elem, const xmlNodePt node, PAGEXML_INSERT itype ) {
  if( elem == NULL ) {
    throw_runtime_error( "PageXML.insertElem: received NULL pointer" );
    return NULL;
  }
  if( node->doc != xml ) {
    throw_runtime_error( "PageXML.insertElem: node is required to be a child of this PageXML object" );
    return NULL;
  }

  xmlNodePt sel = NULL;
  switch( itype ) {
    case PAGEXML_INSERT_APPEND:
      elem = xmlAddChild((xmlNodePtr)node,elem);
      break;
    case PAGEXML_INSERT_PREPEND:
      sel = selectNth("*",0,node);
      if( sel )
        elem = xmlAddPrevSibling(sel,elem);
      else
        elem = xmlAddChild((xmlNodePtr)node,elem);
      break;
    case PAGEXML_INSERT_NEXTSIB:
      elem = xmlAddNextSibling((xmlNodePtr)node,elem);
      break;
    case PAGEXML_INSERT_PREVSIB:
      elem = xmlAddPrevSibling((xmlNodePtr)node,elem);
      break;
  }

  return elem;
}


/**
 * Creates a new element and adds it relative to a given node.
 *
 * @param name   Name of element to create.
 * @param id     ID attribute for element.
 * @param node   Reference element for insertion.
 * @param itype  Type of insertion.
 * @return       Pointer to created element.
 */
xmlNodePt PageXML::addElem( const char* name, const char* id, const xmlNodePt node, PAGEXML_INSERT itype, bool checkid ) {
  xmlNodePt elem = xmlNewNode( rpagens, (xmlChar*)name );
  if( ! elem ) {
    throw_runtime_error( "PageXML.addElem: problems creating new element: name=%s", name );
    return NULL;
  }
  if( id != NULL ) {
    if( checkid ) {
      vector<xmlNodePt> idsel = select( (string("//*[@id='")+id+"']").c_str() );
      if( idsel.size() > 0 ) {
        throw_runtime_error( "PageXML.addElem: id already exists: id=%s", id );
        return NULL;
      }
    }
    xmlNewProp( elem, (xmlChar*)"id", (xmlChar*)id );
  }

  return insertElem( elem, node, itype );

/*   xmlNodePt sel = NULL;
  switch( itype ) {
    case PAGEXML_INSERT_APPEND:
      elem = xmlAddChild((xmlNodePtr)node,elem);
      break;
    case PAGEXML_INSERT_PREPEND:
      sel = selectNth("*",0,node);
      if( sel )
        elem = xmlAddPrevSibling(sel,elem);
      else
        elem = xmlAddChild((xmlNodePtr)node,elem);
      break;
    case PAGEXML_INSERT_NEXTSIB:
      elem = xmlAddNextSibling((xmlNodePtr)node,elem);
      break;
    case PAGEXML_INSERT_PREVSIB:
      elem = xmlAddPrevSibling((xmlNodePtr)node,elem);
      break;
  }

  return elem; */
}

/**
 * Creates a new element and adds it relative to a given xpath.
 *
 * @param name   Name of element to create.
 * @param id     ID attribute for element.
 * @param xpath  Selector for insertion.
 * @param itype  Type of insertion.
 * @return       Pointer to created element.
 */
xmlNodePt PageXML::addElem( const char* name, const char* id, const char* xpath, PAGEXML_INSERT itype, bool checkid ) {
  vector<xmlNodePt> target = select( xpath );
  if( target.size() == 0 ) {
    throw_runtime_error( "PageXML.addElem: unmatched target: xpath=%s", xpath );
    return NULL;
  }

  return addElem( name, id, target[0], itype, checkid );
}

/**
 * Creates a new element and adds it relative to a given xpath.
 *
 * @param name   Name of element to create.
 * @param id     ID attribute for element.
 * @param xpath  Selector for insertion.
 * @param itype  Type of insertion.
 * @return       Pointer to created element.
 */
xmlNodePt PageXML::addElem( const string name, const string id, const string xpath, PAGEXML_INSERT itype, bool checkid ) {
  vector<xmlNodePt> target = select( xpath );
  if( target.size() == 0 ) {
    throw_runtime_error( "PageXML.addElem: unmatched target: xpath=%s", xpath.c_str() );
    return NULL;
  }

  return addElem( name.c_str(), id.c_str(), target[0], itype, checkid );
}

/**
 * Removes the given element.
 *
 * @param node   Element.
 */
void PageXML::rmElem( const xmlNodePt node ) {
  xmlUnlinkNode((xmlNodePtr)node);
  xmlFreeNode((xmlNodePtr)node);
}

/**
 * Removes the elements given in a vector.
 *
 * @param nodes  Vector of elements.
 * @return       Number of elements removed.
 */
int PageXML::rmElems( const vector<xmlNodePt>& nodes ) {
  for( int n=(int)nodes.size()-1; n>=0; n-- ) {
    xmlUnlinkNode((xmlNodePtr)nodes[n]);
    xmlFreeNode((xmlNodePtr)nodes[n]);
  }

  return (int)nodes.size();
}

/**
 * Remove the elements that match a given xpath.
 *
 * @param xpath  Selector for elements to remove.
 * @param node   Base node for element selection.
 * @return       Number of elements removed.
 */
int PageXML::rmElems( const char* xpath, xmlNodePt node ) {
  return rmElems( select( xpath, node ) );
}

/**
 * Remove the elements that match a given xpath.
 *
 * @param xpath    Selector for elements to remove.
 * @param node     Base node for element selection.
 * @return         Number of elements removed.
 */
int PageXML::rmElems( const string xpath, xmlNodePt node ) {
  return rmElems( select( xpath.c_str(), node ) );
}

/**
 * Clone an element and add it relative to a given node.
 *
 * @param elem   Element to clone.
 * @param node   Reference element for insertion.
 * @param itype  Type of insertion.
 * @return       Pointer to cloned element.
 */
xmlNodePt PageXML::copyElem( xmlNodePt elem, const xmlNodePt node, PAGEXML_INSERT itype ) {
  if( elem == NULL || node == NULL ) {
    throw_runtime_error( "PageXML.copyElem: received NULL pointer (elem=%p, node=%p)", elem, node );
    return NULL;
  }
  if( node->doc != xml ) {
    throw_runtime_error( "PageXML.copyElem: node is required to be a child of this PageXML object" );
    return NULL;
  }

  xmlNodePt elemcopy = NULL;
  if ( 0 != xmlDOMWrapCloneNode( NULL, NULL, elem, &elemcopy, xml, NULL, 1, 0 ) ||
      elemcopy == NULL ) {
    throw_runtime_error( "PageXML.copyElem: problems cloning node" );
    return NULL;
  }
  try {
    return insertElem( elemcopy, node, itype );
  }
  catch( exception& e ) {
    xmlFreeNode(elemcopy);
    throw_runtime_error( "PageXML.copyElem: problems inserting element" );
    return NULL;
  }
}

/**
 * Unlink an element and add it relative to a given node.
 *
 * @param elem   Element to move.
 * @param node   Reference element for insertion.
 * @param itype  Type of insertion.
 * @return       Pointer to moved element.
 */
xmlNodePt PageXML::moveElem( xmlNodePt elem, const xmlNodePt node, PAGEXML_INSERT itype ) {
  if( elem == NULL || node == NULL ) {
    throw_runtime_error( "PageXML.moveElem: received NULL pointer (elem=%p, node=%p)", elem, node );
    return NULL;
  }
  if( node->doc != xml ) {
    throw_runtime_error( "PageXML.moveElem: node is required to be a child of this PageXML object" );
    return NULL;
  }

  xmlNodePt elemcopy = NULL;
  try {
    elemcopy = copyElem( elem, node, itype );
  }
  catch( exception& e ) {
    throw_runtime_error( "PageXML.moveElem: problems moving element: %s", e.what() );
    return NULL;
  }
  xmlUnlinkNode(elem);
  xmlFreeNode(elem);

  return elemcopy;
}

/**
 * Unlink elements and add them relative to a given node.
 *
 * @param elems  Elements to move.
 * @param node   Reference element for insertion.
 * @param itype  Type of insertion.
 * @return       Pointer to moved element.
 */
int PageXML::moveElems( const std::vector<xmlNodePt>& elems, const xmlNodePt node, PAGEXML_INSERT itype ) {
  int moves = 0;
  switch( itype ) {
    case PAGEXML_INSERT_APPEND:
    case PAGEXML_INSERT_PREVSIB:
      for( int n=0; n<(int)elems.size(); n++ )
        if( moveElem(elems[n],node,itype) != NULL )
          moves++;
      break;
    case PAGEXML_INSERT_PREPEND:
    case PAGEXML_INSERT_NEXTSIB:
      for( int n=(int)elems.size()-1; n>=0; n-- )
        if( moveElem(elems[n],node,itype) != NULL )
          moves++;
      break;
  }

  return moves;
}

/**
 * Sets the rotation angle to a TextRegion node.
 *
 * @param node       Node of the TextRegion element.
 * @param rotation   Rotation angle to set.
 */
void PageXML::setRotation( const xmlNodePt node, const float rotation ) {
  if( ! xmlStrcmp( node->name, (const xmlChar*)"TextRegion") ) {
    char rot[64];
    snprintf( rot, sizeof rot, "%g", rotation );
    if( rotation )
      setAttr( node, "readingOrientation", rot );
    else
      rmElems( select( "@readingOrientation", node ) );
  }
  else {
    throw_runtime_error( "PageXML.setRotation: only possible for TextRegion" );
    return;
  }
}

/**
 * Sets the reading direction to a TextRegion node.
 *
 * @param node       Node of the TextRegion element.
 * @param direction  Direction to set.
 */
void PageXML::setReadingDirection( const xmlNodePt node, PAGEXML_READ_DIRECTION direction ) {
  if( ! xmlStrcmp( node->name, (const xmlChar*)"TextRegion") ) {
    if( direction == PAGEXML_READ_DIRECTION_RTL )
      setAttr( node, "readingDirection", "right-to-left" );
    else if( direction == PAGEXML_READ_DIRECTION_TTB )
      setAttr( node, "readingDirection", "top-to-bottom" );
    else if( direction == PAGEXML_READ_DIRECTION_BTT )
      setAttr( node, "readingDirection", "bottom-to-top" );
    else if( direction == PAGEXML_READ_DIRECTION_LTR )
      //setAttr( node, "readingDirection", "left-to-right" );
      rmElems( select( "@readingDirection", node ) );
  }
  else {
    throw_runtime_error( "PageXML.setReadingDirection: only possible for TextRegion" );
    return;
  }
}

/**
 * Projects points onto a line defined by a direction and y-offset
 */
std::vector<double> static project_2d_to_1d( std::vector<cv::Point2f> points, cv::Point2f axis, double yoffset = 0.0 ) {
  axis *= 1.0/cv::norm(axis);
  std::vector<double> proj(points.size());
  for ( int n=0; n<(int)points.size(); n++ )
    proj[n] = points[n].x*axis.x + (points[n].y-yoffset)*axis.y;
  return proj;
}

/**
 * Computes the difference between two angles [-PI,PI] accounting for the discontinuity
 */
double static inline angleDiff( double a1, double a2 ) {
  double a = a1 - a2;
  a += (a>M_PI) ? -2*M_PI : (a<-M_PI) ? 2*M_PI : 0;
  return a;
}

/**
 * Computes the 1D intersection
 */
double static inline intersection_1d( double& a1, double& a2, double& b1, double& b2 ) {
  double tmp;
  if ( a1 > a2 ) {
    tmp = a1;
    a1 = a2;
    a2 = tmp;
  }
  if ( b1 > b2 ) {
    tmp = b1;
    b1 = b2;
    b2 = tmp;
  }
  return std::max(0.0, std::min(a2, b2) - std::max(a1, b1));
}

/**
 * Computes the 1D intersection over union
 */
double static inline IoU_1d( double a1, double a2, double b1, double b2 ) {
  double isect = intersection_1d(a1,a2,b1,b2);
  return isect == 0.0 ? 0.0 : isect/((a2-a1)+(b2-b1));
}

/**
 * Gets the dominant orientation angle for a set of baselines.
 *
 * @param elems  Nodes of the TextLine elements.
 * @return       The dominant orientation angle in radians, NaN if unset.
 */
double PageXML::getDominantBaselinesOrientation( std::vector<xmlNodePt> elems ) {
  if ( elems.size() == 0 )
    throw_runtime_error( "PageXML.getDominantBaselinesOrientation: received zero elements" );

  double x = 0.0;
  double y = 0.0;
  double totlength = 0.0;

  for ( int n=elems.size()-1; n>=0; n-- ) {
    // @todo Add fake_baseline parameter, creating function to get the fake since used in several places.
    std::vector<cv::Point2f> baseline = getPoints(elems[n],"_:Baseline");
    if ( baseline.size() == 0 )
      throw_runtime_error( "PageXML.getDominantBaselinesOrientation: unable to get baseline points for element %d", n+1 );

    double angle = getPolylineOrientation(baseline);
    if ( elems.size() == 1 )
      return angle;
    double length = getPolylineLength(baseline);

    x += length * cos(angle);
    y += length * sin(angle);
    totlength += length;
  }

  x /= totlength;
  y /= totlength;

  return -atan2(y,x);
}

/**
 * Gets the baseline orientation angle (weighted average over polyline segments) of a given text line.
 *
 * @param elem   Node of the TextLine element.
 * @return       The orientation angle in radians, NaN if unset.
 */
double PageXML::getBaselineOrientation( xmlNodePt elem ) {
  if ( ! nodeIs( elem, "TextLine" ) ) {
    throw_runtime_error( "PageXML.getBaselineOrientation: node is required to be a TextLine" );
    return std::numeric_limits<double>::quiet_NaN();
  }
  std::vector<cv::Point2f> points = getPoints( elem, "_:Baseline" );
  return getPolylineOrientation(points);
}

/**
 * Gets the baseline orientation angle (weighted average over polyline segments) in radians of a given baseline.
 *
 * @param points  Baseline points.
 * @return        The orientation angle in radians, NaN if unset.
 */
double PageXML::getPolylineOrientation( std::vector<cv::Point2f> points ) {
  if ( points.size() == 0 )
    return std::numeric_limits<double>::quiet_NaN();

  //double angle1st = 0.0;
  //double avgAngle = 0.0;
  double x = 0.0;
  double y = 0.0;
  double totlgth = 0.0;

  for ( int n = 1; n < (int)points.size(); n++ ) {
    double lgth = cv::norm(points[n]-points[n-1]);
    totlgth += lgth;
    double angle = -atan2( points[n].y-points[n-1].y, points[n].x-points[n-1].x );
    x += lgth * cos(angle);
    y += lgth * sin(angle);
    //if ( n == 1 ) {
    //  angle1st = angle;
    //  avgAngle += lgth*angle;
    //}
    //else {
    //  avgAngle += lgth*(angle1st+angleDiff(angle,angle1st));
    //}
  }

  x /= totlgth;
  y /= totlgth;

  return -atan2(y,x);
  //return avgAngle/totlgth;
}

/**
 * Gets the baseline length.
 *
 * @param points  Baseline points.
 * @return        The orientation angle in radians, NaN if unset.
 */
double PageXML::getPolylineLength( std::vector<cv::Point2f> points ) {
  double totlgth = 0.0;
  for ( int n = 1; n < (int)points.size(); n++ )
    totlgth += cv::norm(points[n]-points[n-1]);
  return totlgth;
}

/**
 * Retrieves the rotation angle for a given TextLine or TextRegion node.
 *
 * @param elem   Node of the TextLine or TextRegion element.
 * @return       The rotation angle in degrees, 0 if unset.
 */
double PageXML::getRotation( const xmlNodePt elem ) {
  double rotation = 0.0;
  if( elem == NULL )
    return rotation;

  xmlNodePt node = (xmlNodePt)elem;

  /// If TextLine try to get rotation from custom attribute ///
  if( ! xmlStrcmp( node->name, (const xmlChar*)"TextLine") ) {
    if( ! xmlHasProp( node, (xmlChar*)"custom" ) )
      node = node->parent;
    else {
      xmlChar* attr = xmlGetProp( node, (xmlChar*)"custom" );
      cmatch base_match;
      if( regex_match((char*)attr,base_match,reRotation) )
        rotation = stod(base_match[1].str());
      else
        node = node->parent;
      xmlFree(attr);
    }
  }
  /// Otherwise try to get rotation from readingOrientation attribute ///
  if( xmlHasProp( node, (xmlChar*)"readingOrientation" ) ) {
    xmlChar* attr = xmlGetProp( node, (xmlChar*)"readingOrientation" );
    rotation = stod((char*)attr);
    xmlFree(attr);
  }

  return rotation;
}

/**
 * Retrieves the reading direction for a given TextLine or TextRegion node.
 *
 * @param elem   Node of the TextLine or TextRegion element.
 * @return       The reading direction, PAGEXML_READ_DIRECTION_LTR if unset.
 */
int PageXML::getReadingDirection( const xmlNodePt elem ) {
  int direction = PAGEXML_READ_DIRECTION_LTR;
  if( elem == NULL )
    return direction;

  xmlNodePt node = (xmlNodePt)elem;

  /// If TextLine try to get direction from custom attribute ///
  if( ! xmlStrcmp( node->name, (const xmlChar*)"TextLine") ) {
    if( ! xmlHasProp( node, (xmlChar*)"custom" ) )
      node = node->parent;
    else {
      xmlChar* attr = xmlGetProp( node, (xmlChar*)"custom" );
      cmatch base_match;
      if( regex_match((char*)attr,base_match,reDirection) ) {
        if( ! strcmp(base_match[1].str().c_str(),"ltr") )
          direction = PAGEXML_READ_DIRECTION_LTR;
        else if( ! strcmp(base_match[1].str().c_str(),"rtl") )
          direction = PAGEXML_READ_DIRECTION_RTL;
        else if( ! strcmp(base_match[1].str().c_str(),"ttb") )
          direction = PAGEXML_READ_DIRECTION_TTB;
        else if( ! strcmp(base_match[1].str().c_str(),"btt") )
          direction = PAGEXML_READ_DIRECTION_BTT;
      }
      else
        node = node->parent;
      xmlFree(attr);
    }
  }
  /// Otherwise try to get direction from readingDirection attribute ///
  if( xmlHasProp( node, (xmlChar*)"readingDirection" ) ) {
    char* attr = (char*)xmlGetProp( node, (xmlChar*)"readingDirection" );
    if( ! strcmp(attr,"left-to-right") )
      direction = PAGEXML_READ_DIRECTION_LTR;
    else if( ! strcmp(attr,"right-to-left") )
      direction = PAGEXML_READ_DIRECTION_RTL;
    else if( ! strcmp(attr,"top-to-bottom") )
      direction = PAGEXML_READ_DIRECTION_TTB;
    else if( ! strcmp(attr,"bottom-to-top") )
      direction = PAGEXML_READ_DIRECTION_BTT;
    xmlFree(attr);
  }

  return direction;
}

/**
 * Retrieves the x-height for a given TextLine node.
 *
 * @param node   Node of the TextLine element.
 * @return       x-height>0 on success, -1 if unset.
 */
float PageXML::getXheight( const xmlNodePt node ) {
  float xheight = -1;

  if( node != NULL &&
      xmlHasProp( node, (xmlChar*)"custom" ) ) {
    xmlChar* custom = xmlGetProp( node, (xmlChar*)"custom" );
    cmatch base_match;
    if( regex_match((char*)custom,base_match,reXheight) )
      xheight = stof(base_match[1].str());
    xmlFree(custom);
  }

  return xheight;
}

/**
 * Retrieves the x-height for a given TextLine id.
 *
 * @param id     Identifier of the TextLine.
 * @return       x-height>0 on success, -1 if unset.
 */
float PageXML::getXheight( const char* id ) {
  vector<xmlNodePt> elem = select( string("//*[@id='")+id+"']" );
  return getXheight( elem.size() == 0 ? NULL : elem[0] );
}

/**
 * Retrieves the features parallelogram (Property[@key="fpgram"]/@value) for a given node.
 *
 * @param node   Base node.
 * @return       Reference to the points vector.
 */
vector<cv::Point2f> PageXML::getFpgram( const xmlNodePt node ) {
  vector<cv::Point2f> points;
  if( node == NULL )
    return points;

  vector<xmlNodePt> coords = select( "_:Property[@key='fpgram']", node );
  if( coords.size() == 0 )
    return points;

  string spoints = getAttr( coords[0], "value" );
  if( spoints.empty() )
    return points;

  points = stringToPoints( spoints.c_str() );
  if( points.size() != 4 ) {
    throw_runtime_error( "PageXML.getFpgram: expected property value to be four points" );
    return points;
  }

  return points;
}

/**
 * Retrieves and parses the Coords/@points for a given base node.
 *
 * @param node   Base node.
 * @return       Reference to the points vector.
 */
vector<cv::Point2f> PageXML::getPoints( const xmlNodePt node, const char* xpath ) {
  vector<cv::Point2f> points;
  if( node == NULL )
    return points;

  vector<xmlNodePt> coords = select( xpath, node );
  if( coords.size() == 0 )
    return points;

  string spoints = getAttr( coords[0], "points" );
  if( spoints.empty() )
    return points;

  return stringToPoints( spoints.c_str() );
}

/**
 * Retrieves and parses the Coords/@points for a given list of base nodes.
 *
 * @param nodes  Base nodes.
 * @return       Reference to the points vector.
 */
std::vector<std::vector<cv::Point2f> > PageXML::getPoints( const std::vector<xmlNodePt> nodes, const char* xpath ) {
  std::vector<std::vector<cv::Point2f> > points;
  for ( int n=0; n<(int)nodes.size(); n++ ) {
    std::vector<cv::Point2f> pts_n = getPoints( nodes[n], xpath );
    if ( pts_n.size() == 0 )
      return std::vector<std::vector<cv::Point2f> >();
    points.push_back(pts_n);
  }
  return points;
}

/**
 * Retrieves the concatenated TextEquivs for a given root node and xpath.
 *
 * @param node       Root node element.
 * @param xpath      Relative xpath to select the TextEquiv elements.
 * @param separator  String to add between TextEquivs.
 * @return           String with the concatenated TextEquivs.
 */
std::string PageXML::getTextEquiv( xmlNodePt node, const char* xpath, const char* separator ) {
  std::vector<xmlNodePt> nodes = select( xpath, node );
  std::string text;
  for ( int n=0; n<(int)nodes.size(); n++ ) {
    xmlChar* t = xmlNodeGetContent(nodes[n]);
    text += std::string(n==0?"":separator) + (char*)t;
    xmlFree(t);
  }
  return text;
}

/**
 * Starts a process in the Page XML.
 */
void PageXML::processStart( const char* tool, const char* ref ) {
  if( tool == NULL || tool[0] == '\0' ) {
    throw_runtime_error( "PageXML.processStart: tool string is required" );
    return;
  }
  if( ref != NULL && ref[0] == '\0' ) {
    throw_runtime_error( "PageXML.processStart: ref if provided cannot be empty" );
    return;
  }

  process_started = chrono::high_resolution_clock::now();

  /// Add Process element ///
  process_running = addElem( "Process", NULL, "//_:Metadata" );
  if ( ! process_running ) {
    throw_runtime_error( "PageXML.processStart: problems creating element" );
    return;
  }

  /// Start time attribute ///
  time_t now;
  time(&now);
  char tstamp[sizeof "YYYY-MM-DDTHH:MM:SSZ"];
  strftime(tstamp, sizeof tstamp, "%FT%TZ", gmtime(&now));
  setAttr( process_running, "started", tstamp );

  /// Tool and ref attributes ///
  setAttr( process_running, "tool", tool );
  if ( ref != NULL )
    setAttr( process_running, "ref", ref );
}

/**
 * Ends the running process in the Page XML.
 */
void PageXML::processEnd() {
  if ( ! process_running )
    return;
  double duration = 1e-6*chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now()-process_started).count();
  char sduration[64];
  snprintf( sduration, sizeof sduration, "%g", duration );
  setAttr( process_running, "time", sduration );
  process_running = NULL;
  updateLastChange();
}

/**
 * Updates the last change time stamp.
 */
void PageXML::updateLastChange() {
  xmlNodePt lastchange = selectNth( "//_:LastChange", 0 );
  if( ! lastchange ) {
    throw_runtime_error( "PageXML.updateLastChange: unable to select node" );
    return;
  }
  rmElems( select( "text()", lastchange ) );
  time_t now;
  time(&now);
  char tstamp[sizeof "YYYY-MM-DDTHH:MM:SSZ"];
  strftime(tstamp, sizeof tstamp, "%FT%TZ", gmtime(&now));
  xmlNodePt text = xmlNewText( (xmlChar*)tstamp );
  if( ! text || ! xmlAddChild(lastchange,text) ) {
    throw_runtime_error( "PageXML.updateLastChange: problems updating time stamp" );
    return;
  }
}

/**
 * Retrieves a Property value.
 *
 * @param node       Node element.
 * @return           String with the property value.
 */
std::string PageXML::getPropertyValue( xmlNodePt node, const char* key ) {
  xmlNodePt prop = selectNth( std::string("_:Property[@key='")+key+"']/@value", 0, node );
  return prop == NULL ? std::string("") : getValue(prop);
}

/**
 * Sets a Property to a given node.
 *
 * @param node  The node of element to set the Property.
 * @param key   The key for the Property.
 * @param val   The optional value for the Property.
 * @param _conf Pointer to confidence value, NULL for no confidence.
 * @return      Pointer to created element.
 */
xmlNodePt PageXML::setProperty( xmlNodePt node, const char* key, const char* val, const double* _conf ) {
  rmElems( select( std::string("_:Property[@key=\"")+key+"\"]", node ) );

  std::vector<xmlNodePt> siblafter = select( "*[local-name()!='Property' and local-name()!='Metadata']", node );
  std::vector<xmlNodePt> props = select( "_:Property", node );

  xmlNodePt prop = NULL;
  if ( props.size() > 0 )
    prop = addElem( "Property", NULL, props[props.size()-1], PAGEXML_INSERT_NEXTSIB );
  else if ( siblafter.size() > 0 )
    prop = addElem( "Property", NULL, siblafter[0], PAGEXML_INSERT_PREVSIB );
  else
    prop = addElem( "Property", NULL, node );
  if ( ! prop ) {
    throw_runtime_error( "PageXML.setProperty: problems creating element" );
    return NULL;
  }

  if ( ! setAttr( prop, "key", key ) ) {
    rmElem( prop );
    throw_runtime_error( "PageXML.setProperty: problems setting key attribute" );
    return NULL;
  }
  if ( val != NULL && ! setAttr( prop, "value", val ) ) {
    rmElem( prop );
    throw_runtime_error( "PageXML.setProperty: problems setting value attribute" );
    return NULL;
  }

  if( _conf != NULL ) {
    char conf[64];
    snprintf( conf, sizeof conf, "%g", *_conf );
    if( ! xmlNewProp( prop, (xmlChar*)"conf", (xmlChar*)conf ) ) {
      rmElem( prop );
      throw_runtime_error( "PageXML.setProperty: problems setting conf attribute" );
      return NULL;
    }
  }

  return prop;
}

/**
 * Sets a Property to a given node.
 *
 * @param node  The node of element to set the Property.
 * @param key   The key for the Property.
 * @param val   The optional value for the Property.
 * @param conf  Confidence value.
 * @return      Pointer to created element.
 */
xmlNodePt PageXML::setProperty( xmlNodePt node, const char* key, const char* val, const double conf ) {
  return setProperty(node,key,val,&conf);
}

/**
 * Sets a Property to a given node.
 *
 * @param node  The node of element to set the Property.
 * @param key   The key for the Property.
 * @param val   Numeric value for the Property.
 * @param _conf Pointer to confidence value, NULL for no confidence.
 * @return      Pointer to created element.
 */
xmlNodePt PageXML::setProperty( xmlNodePt node, const char* key, const double val, const double* _conf ) {
  char buffer[32];
  snprintf( buffer, sizeof buffer, "%g", val );
  return setProperty(node,key,buffer,_conf);
}

/**
 * Sets a Property to a given node.
 *
 * @param node  The node of element to set the Property.
 * @param key   The key for the Property.
 * @param val   The optional value for the Property.
 * @param conf  Confidence value.
 * @return      Pointer to created element.
 */
xmlNodePt PageXML::setProperty( xmlNodePt node, const char* key, const double val, const double conf ) {
  return setProperty(node,key,val,&conf);
}

/**
 * Adds or modifies (if already exists) the TextEquiv for a given node.
 *
 * @param node   The node of element to set the TextEquiv.
 * @param text   The text string.
 * @param _conf  Pointer to confidence value, NULL for no confidence.
 * @return       Pointer to created element.
 */
xmlNodePt PageXML::setTextEquiv( xmlNodePt node, const char* text, const double* _conf ) {
  if( node == NULL ) {
    throw_runtime_error( "PageXML.setTextEquiv: received NULL node pointer" );
    return NULL;
  }

  rmElems( select( "_:TextEquiv", node ) );

  xmlNodePt textequiv = addElem( "TextEquiv", NULL, node );

  xmlNodePt unicode = xmlNewTextChild( textequiv, NULL, (xmlChar*)"Unicode", (xmlChar*)text );
  if( ! unicode ) {
    throw_runtime_error( "PageXML.setTextEquiv: problems setting TextEquiv" );
    return NULL;
  }

  if( _conf != NULL ) {
    char conf[64];
    snprintf( conf, sizeof conf, "%g", *_conf );
    if( ! xmlNewProp( textequiv, (xmlChar*)"conf", (xmlChar*)conf ) ) {
      throw_runtime_error( "PageXML.setTextEquiv: problems setting conf attribute" );
      return NULL;
    }
  }

  return textequiv;
}

/**
 * Adds or modifies (if already exists) the TextEquiv for a given node.
 *
 * @param node   The node of element to set the TextEquiv.
 * @param text   The text string.
 * @param conf   Confidence value.
 * @return       Pointer to created element.
 */
xmlNodePt PageXML::setTextEquiv( xmlNodePt node, const char* text, const double conf ) {
  return setTextEquiv( node, text, &conf );
}

/**
 * Adds or modifies (if already exists) the TextEquiv for a given xpath.
 *
 * @param xpath  Selector for element to set the TextEquiv.
 * @param text   The text string.
 * @param _conf  Pointer to confidence value, NULL for no confidence.
 * @return       Pointer to created element.
 */
xmlNodePt PageXML::setTextEquiv( const char* xpath, const char* text, const double* _conf ) {
  vector<xmlNodePt> target = select( xpath );
  if( target.size() == 0 ) {
    throw_runtime_error( "PageXML.setTextEquiv: unmatched target: xpath=%s", xpath );
    return NULL;
  }

  return setTextEquiv( target[0], text, _conf );
}

/**
 * Adds or modifies (if already exists) the TextEquiv for a given xpath.
 *
 * @param xpath  Selector for element to set the TextEquiv.
 * @param text   The text string.
 * @param conf   Confidence value.
 * @return       Pointer to created element.
 */
xmlNodePt PageXML::setTextEquiv( const char* xpath, const char* text, const double conf ) {
  return setTextEquiv( xpath, text, &conf );
}

/**
 * Adds or modifies (if already exists) the Coords for a given node.
 *
 * @param node   The node of element to set the Coords.
 * @param points Vector of x,y coordinates for the points attribute.
 * @param _conf  Pointer to confidence value, NULL for no confidence.
 * @return       Pointer to created element.
 */
xmlNodePt PageXML::setCoords( xmlNodePt node, const vector<cv::Point2f>& points, const double* _conf ) {
  rmElems( select( "_:Coords", node ) );

  xmlNodePt coords;
  vector<xmlNodePt> sel = select( "*[local-name()!='Property']", node );
  if( sel.size() > 0 )
    coords = addElem( "Coords", NULL, sel[0], PAGEXML_INSERT_PREVSIB );
  else
    coords = addElem( "Coords", NULL, node );

  if( ! xmlNewProp( coords, (xmlChar*)"points", (xmlChar*)pointsToString(points).c_str() ) ) {
    throw_runtime_error( "PageXML.setCoords: problems setting points attribute" );
    return NULL;
  }

  if( _conf != NULL ) {
    char conf[64];
    snprintf( conf, sizeof conf, "%g", *_conf );
    if( ! xmlNewProp( coords, (xmlChar*)"conf", (xmlChar*)conf ) ) {
      throw_runtime_error( "PageXML.setCoords: problems setting conf attribute" );
      return NULL;
    }
  }

  return coords;
}

/**
 * Adds or modifies (if already exists) the Coords for a given node.
 *
 * @param node   The node of element to set the Coords.
 * @param points Vector of x,y coordinates for the points attribute.
 * @param conf   Confidence value.
 * @return       Pointer to created element.
 */
xmlNodePt PageXML::setCoords( xmlNodePt node, const vector<cv::Point2f>& points, const double conf ) {
  return setCoords( node, points, &conf );
}

/**
 * Adds or modifies (if already exists) the Coords for a given node.
 *
 * @param node   The node of element to set the Coords.
 * @param points Vector of x,y coordinates for the points attribute.
 * @param _conf  Pointer to confidence value, NULL for no confidence.
 * @return       Pointer to created element.
 */
xmlNodePt PageXML::setCoords( xmlNodePt node, const vector<cv::Point>& points, const double* _conf ) {
  std::vector<cv::Point2f> points2f;
  cv::Mat(points).convertTo(points2f, cv::Mat(points2f).type());
  return setCoords( node, points2f, _conf );
}

/**
 * Adds or modifies (if already exists) the Coords for a given node.
 *
 * @param node   The node of element to set the Coords.
 * @param points Vector of x,y coordinates for the points attribute.
 * @param conf   Confidence value.
 * @return       Pointer to created element.
 */
xmlNodePt PageXML::setCoords( xmlNodePt node, const vector<cv::Point>& points, const double conf ) {
  return setCoords( node, points, &conf );
}

/**
 * Adds or modifies (if already exists) the Coords for a given xpath.
 *
 * @param node   Selector for element to set the Coords.
 * @param points Vector of x,y coordinates for the points attribute.
 * @param _conf  Pointer to confidence value, NULL for no confidence.
 * @return       Pointer to created element.
 */
xmlNodePt PageXML::setCoords( const char* xpath, const vector<cv::Point2f>& points, const double* _conf ) {
  vector<xmlNodePt> target = select( xpath );
  if( target.size() == 0 ) {
    throw_runtime_error( "PageXML.setCoords: unmatched target: xpath=%s", xpath );
    return NULL;
  }

  return setCoords( target[0], points, _conf );
}

/**
 * Adds or modifies (if already exists) the Coords for a given xpath.
 *
 * @param node   Selector for element to set the Coords.
 * @param points Vector of x,y coordinates for the points attribute.
 * @param conf   Confidence value.
 * @return       Pointer to created element.
 */
xmlNodePt PageXML::setCoords( const char* xpath, const vector<cv::Point2f>& points, const double conf ) {
  return setCoords( xpath, points, &conf );
}

/**
 * Adds or modifies (if already exists) the Coords as a bounding box for a given node.
 *
 * @param node      The node of element to set the Coords.
 * @param xmin      Minimum x value of bounding box.
 * @param ymin      Minimum y value of bounding box.
 * @param width     Width of bounding box.
 * @param height    Height of bounding box.
 * @param _conf     Pointer to confidence value, NULL for no confidence.
 * @param subone    Whether to subtract 1 when computing xmax and ymax (discrete compatibility).
 * @return          Pointer to created element.
 */
xmlNodePt PageXML::setCoordsBBox( xmlNodePt node, double xmin, double ymin, double width, double height, const double* _conf, bool subone ) {
  double xmax = xmin + width - (subone?1:0);
  double ymax = ymin + height - (subone?1:0);
  vector<cv::Point2f> bbox;
  bbox.push_back( cv::Point2f(xmin,ymin) );
  bbox.push_back( cv::Point2f(xmax,ymin) );
  bbox.push_back( cv::Point2f(xmax,ymax) );
  bbox.push_back( cv::Point2f(xmin,ymax) );

  return setCoords( node, bbox, _conf );
}

/**
 * Adds or modifies (if already exists) the Coords as a bounding box for a given node.
 *
 * @param node      The node of element to set the Coords.
 * @param xmin      Minimum x value of bounding box.
 * @param ymin      Minimum y value of bounding box.
 * @param width     Width of bounding box.
 * @param height    Height of bounding box.
 * @param conf      Confidence value.
 * @param subone    Whether to subtract 1 when computing xmax and ymax (discrete compatibility).
 * @return          Pointer to created element.
 */
xmlNodePt PageXML::setCoordsBBox( xmlNodePt node, double xmin, double ymin, double width, double height, const double conf, bool subone ) {
  return setCoordsBBox( node, xmin, ymin, width, height, &conf, subone );
}

/**
 * Adds or modifies (if already exists) the Baseline for a given node.
 *
 * @param node   The node of element to set the Baseline.
 * @param points Vector of x,y coordinates for the points attribute.
 * @param _conf  Pointer to confidence value, NULL for no confidence.
 * @return       Pointer to created element.
 */
xmlNodePt PageXML::setBaseline( xmlNodePt node, const vector<cv::Point2f>& points, const double* _conf ) {
  if( ! nodeIs( node, "TextLine" ) ) {
    throw_runtime_error( "PageXML.setBaseline: node is required to be a TextLine" );
    return NULL;
  }

  rmElems( select( "_:Baseline", node ) );

  xmlNodePt baseline;
  vector<xmlNodePt> sel = select( "*[local-name()!='Property' and local-name()!='Coords']", node );
  if( sel.size() > 0 )
    baseline = addElem( "Baseline", NULL, sel[0], PAGEXML_INSERT_PREVSIB );
  else
    baseline = addElem( "Baseline", NULL, node );

  if( ! xmlNewProp( baseline, (xmlChar*)"points", (xmlChar*)pointsToString(points).c_str() ) ) {
    throw_runtime_error( "PageXML.setBaseline: problems setting points attribute" );
    return NULL;
  }

  if( _conf != NULL ) {
    char conf[64];
    snprintf( conf, sizeof conf, "%g", *_conf );
    if( ! xmlNewProp( baseline, (xmlChar*)"conf", (xmlChar*)conf ) ) {
      throw_runtime_error( "PageXML.setBaseline: problems setting conf attribute" );
      return NULL;
    }
  }

  return baseline;
}

/**
 * Adds or modifies (if already exists) the Baseline for a given node.
 *
 * @param node   The node of element to set the Baseline.
 * @param points Vector of x,y coordinates for the points attribute.
 * @param conf   Confidence value.
 * @return       Pointer to created element.
 */
xmlNodePt PageXML::setBaseline( xmlNodePt node, const vector<cv::Point2f>& points, const double conf ) {
  return setBaseline( node, points, &conf );
}

/**
 * Adds or modifies (if already exists) the Baseline for a given xpath.
 *
 * @param xpath  Selector for element to set the Baseline.
 * @param points Vector of x,y coordinates for the points attribute.
 * @param _conf  Pointer to confidence value, NULL for no confidence.
 * @return       Pointer to created element.
 */
xmlNodePt PageXML::setBaseline( const char* xpath, const vector<cv::Point2f>& points, const double* _conf ) {
  vector<xmlNodePt> target = select( xpath );
  if( target.size() == 0 ) {
    throw_runtime_error( "PageXML.setBaseline: unmatched target: xpath=%s", xpath );
    return NULL;
  }

  return setBaseline( target[0], points, _conf );
}

/**
 * Adds or modifies (if already exists) the Baseline for a given xpath.
 *
 * @param xpath  Selector for element to set the Baseline.
 * @param points Vector of x,y coordinates for the points attribute.
 * @param conf   Confidence value.
 * @return       Pointer to created element.
 */
xmlNodePt PageXML::setBaseline( const char* xpath, const vector<cv::Point2f>& points, const double conf ) {
  return setBaseline( xpath, points, &conf );
}

/**
 * Adds or modifies (if already exists) a two point Baseline for a given node.
 *
 * @param node   The node of element to set the Baseline.
 * @param x1     x value of first point.
 * @param y1     y value of first point.
 * @param x2     x value of second point.
 * @param y2     y value of second point.
 * @param _conf  Pointer to confidence value, NULL for no confidence.
 * @return       Pointer to created element.
 */
xmlNodePt PageXML::setBaseline( xmlNodePt node, double x1, double y1, double x2, double y2, const double* _conf ) {
  vector<cv::Point2f> pts;
  pts.push_back( cv::Point2f(x1,y1) );
  pts.push_back( cv::Point2f(x2,y2) );

  return setBaseline( node, pts, _conf );
}

/**
 * Adds or modifies (if already exists) a two point Baseline for a given node.
 *
 * @param node   The node of element to set the Baseline.
 * @param x1     x value of first point.
 * @param y1     y value of first point.
 * @param x2     x value of second point.
 * @param y2     y value of second point.
 * @param conf   Confidence value.
 * @return       Pointer to created element.
 */
xmlNodePt PageXML::setBaseline( xmlNodePt node, double x1, double y1, double x2, double y2, const double conf ) {
  return setBaseline( node, x1, y1, x2, y2, &conf );
}

/**
 * Finds the intersection point between two lines defined by pairs of points or returns false if no intersection
 */
bool PageXML::intersection( cv::Point2f line1_point1, cv::Point2f line1_point2, cv::Point2f line2_point1, cv::Point2f line2_point2, cv::Point2f& _ipoint ) {
  cv::Point2f x = line2_point1-line1_point1;
  cv::Point2f direct1 = line1_point2-line1_point1;
  cv::Point2f direct2 = line2_point2-line2_point1;

  double cross = direct1.x*direct2.y - direct1.y*direct2.x;
  if( fabs(cross) < /*EPS*/1e-8 )
    return false;

  double t1 = (x.x * direct2.y - x.y * direct2.x)/cross;
  _ipoint = line1_point1+t1*direct1;

  return true;
}

/**
 * Checks if a point is within a line segment
 *
 * @param segm_start  Point for begining of segment.
 * @param segm_end    Point for end of segment.
 * @param point       Point to check withiness.
 * @return            0 if within segment, +1 if outside but aligned to the right, -1 if outside but aligned to the left, otherwise NaN.
 */
double withinSegment( cv::Point2f segm_start, cv::Point2f segm_end, cv::Point2f point ) {
  cv::Point2f a = segm_start;
  cv::Point2f b = segm_end;
  cv::Point2f c = point;
  double ab = cv::norm(a-b);
  double ac = cv::norm(a-c);
  double bc = cv::norm(b-c);
  double area = fabs( a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y) ) / (2*(ab+ac+bc)*(ab+ac+bc));

  /// check collinearity (normalized triangle area) ///
  if ( area > 1e-3 )
    return std::numeric_limits<double>::quiet_NaN();
  /// return zero if in segment ///
  if ( ac <= ab && bc <= ab )
    return 0.0;
  /// return +1 if to the right and -1 if to the left ///
  return ac > bc ? 1.0 : -1.0;
}

/**
 * Checks whether Coords is a poly-stripe for its corresponding baseline.
 *
 * @param coords    Coords points.
 * @param baseline  Baseline points.
 * @param offset    The offset of the poly-stripe (>=0 && <= 0.5).
 * @return          Pointer to created element.
 */
bool PageXML::isPolystripe( std::vector<cv::Point2f> coords, std::vector<cv::Point2f> baseline, double* height, double* offset ) {
  if ( baseline.size() == 0 ||
       baseline.size()*2 != coords.size() )
    return false;

  double eps = 1e-2;
  cv::Point2f prevbase;
  cv::Point2f prevabove;
  cv::Point2f prevbelow;

  for ( int n=0; n<(int)baseline.size(); n++ ) {
    int m = coords.size()-1-n;

    /// Check points are collinear ///
    if ( withinSegment( coords[n], coords[m], baseline[n] ) == 0.0 )
      return false;

    /// Check lines are parallel ///
    if ( n > 0 ) {
      prevbase = baseline[n-1]-baseline[n]; prevbase *= 1.0/cv::norm(prevbase);
      prevabove = coords[n-1]-coords[n];    prevabove *= 1.0/cv::norm(prevabove);
      prevbelow = coords[m+1]-coords[m];    prevbelow *= 1.0/cv::norm(prevbelow);
      if ( fabs(1-fabs(prevabove.x*prevbase.x+prevabove.y*prevbase.y)) > eps ||
           fabs(1-fabs(prevbelow.x*prevbase.x+prevbelow.y*prevbase.y)) > eps )
        return false;
    }

    /// Check stripe extremes perpendicular to baseline ///
    if ( n == 0 || n == (int)(baseline.size()-1) ) {
      cv::Point2f base = n > 0 ? prevbase : baseline[1]-baseline[0]; base *= 1.0/cv::norm(base);
      cv::Point2f extr = coords[n]-coords[m]; extr *= 1.0/cv::norm(extr);
      if ( base.x*extr.x+base.y*extr.y > eps )
        return false;
    }
  }

  if ( height != NULL || offset != NULL ) {
    double offup = cv::norm(baseline[0]-coords[0]);
    double offdown = cv::norm(baseline[0]-coords[coords.size()-1]);
    if ( height != NULL )
      *height = offup+offdown;
    if ( offset != NULL )
      *offset = offdown/(offup+offdown);
  }

  return true;
}

/**
 * Sets the Coords of a TextLine as a poly-stripe of the baseline.
 *
 * @param node   The node of element to set the Coords.
 * @param height The height of the poly-stripe in pixels (>0).
 * @param offset The offset of the poly-stripe (>=0 && <= 0.5).
 * @return       Pointer to created element.
 */
xmlNodePt PageXML::setPolystripe( xmlNodePt node, double height, double offset, bool offset_check ) {
  if( ! nodeIs( node, "TextLine" ) ) {
    throw_runtime_error( "PageXML.setPolystripe: node is required to be a TextLine" );
    return NULL;
  }
  if( count( "_:Baseline", node ) == 0 ) {
    throw_runtime_error( "PageXML.setPolystripe: node is required to have a Baseline" );
    return NULL;
  }
  if ( height <= 0 ) {
    throw_runtime_error( "PageXML.setPolystripe: unexpected height: %g", height );
    return NULL;
  }
  if ( offset_check && ( offset < 0 || offset > 0.5 ) ) {
    throw_runtime_error( "PageXML.setPolystripe: unexpected offset: %g", offset );
    return NULL;
  }

  double offup = height - offset*height;
  double offdown = height - offup;

  vector<cv::Point2f> baseline = getPoints( node, "_:Baseline" );
  vector<cv::Point2f> coords;

  cv::Point2f l1p1, l1p2, l2p1, l2p2, base, perp, point;

  for ( int n=0; n<(int)baseline.size()-1; n++ ) {
    base = baseline[n+1]-baseline[n];
    perp = cv::Point2f(base.y,-base.x)*(offup/cv::norm(base));
    l2p1 = baseline[n]+perp;
    l2p2 = baseline[n+1]+perp;
    if ( n == 0 || ! intersection( l1p1, l1p2, l2p1, l2p2, point ) )
      coords.push_back(cv::Point2f(l2p1));
    else
      coords.push_back(cv::Point2f(point));
    l1p1 = l2p1;
    l1p2 = l2p2;
  }
  coords.push_back(cv::Point2f(l2p2));

  for ( int n = baseline.size()-1; n>0; n-- ) {
    base = baseline[n-1]-baseline[n];
    perp = cv::Point2f(base.y,-base.x)*(offdown/cv::norm(base));
    l2p1 = baseline[n]+perp;
    l2p2 = baseline[n-1]+perp;
    if ( n == (int)baseline.size()-1 || ! intersection( l1p1, l1p2, l2p1, l2p2, point ) )
      coords.push_back(cv::Point2f(l2p1));
    else
      coords.push_back(cv::Point2f(point));
    l1p1 = l2p1;
    l1p2 = l2p2;
  }
  coords.push_back(cv::Point2f(l2p2));

  return setCoords( node, coords );
}

/**
 * Gets the page number for the given node.
 */
int PageXML::getPageNumber( xmlNodePt node ) {
  node = selectNth( "ancestor-or-self::*[local-name()='Page']", 0, node );
  vector<xmlNodePt> pages = select("//_:Page");
  for( int n=0; n<(int)pages.size(); n++ )
    if( node == pages[n] )
      return n;
  return -1;
}

/**
 * Sets the image orientation for the given Page node.
 *
 * @param node   The page node.
 * @param angle  The orientation angle in degrees {0,90,180,-90}.
 * @param _conf  Pointer to confidence value, NULL for no confidence.
 */
void PageXML::setPageImageOrientation( xmlNodePt node, int angle, const double* _conf ) {
  if( ! nodeIs( node, "Page" ) ) {
    throw_runtime_error( "PageXML.setPageImageOrientation: node is required to be a Page" );
    return;
  }
  if( angle % 90 != 0 ) {
    throw_runtime_error( "PageXML.setPageImageOrientation: only angles multiple of 90 are accepted" );
    return;
  }

  /// Normalize angle between [-90,180] ///
  angle = ( angle + 90 ) % 360;
  if ( angle < 0 )
    angle += 360;
  angle -= 90;

  rmElems( "_:ImageOrientation", node );

  if( _conf == NULL && angle == 0 )
    return;

  xmlNodePt orientation = addElem( "ImageOrientation", NULL, node, PAGEXML_INSERT_PREPEND );

  setAttr( orientation, "angle", to_string(angle).c_str() );

  if( _conf != NULL ) {
    char conf[32];
    snprintf( conf, sizeof conf, "%g", *_conf );
    setAttr( orientation, "conf", conf );
  }
}

/**
 * Sets the image orientation for the given Page node.
 *
 * @param node   The page node.
 * @param angle  The orientation angle in degrees {0,90,180,-90}.
 * @param conf   Confidence value.
 */
void PageXML::setPageImageOrientation( xmlNodePt node, int angle, const double conf ) {
  setPageImageOrientation( node, angle, &conf );
}

/**
 * Sets the image orientation for the given Page number.
 *
 * @param pagenum  The page number (0-based).
 * @param angle    The orientation angle in degrees {0,90,180,-90}.
 * @param _conf    Pointer to confidence value, NULL for no confidence.
 */
void PageXML::setPageImageOrientation( int pagenum, int angle, const double* _conf ) {
  return setPageImageOrientation( selectNth("//_:Page",pagenum), angle, _conf );
}

/**
 * Sets the image orientation for the given Page number.
 *
 * @param pagenum  The page number (0-based).
 * @param angle    The orientation angle in degrees {0,90,180,-90}.
 * @param conf     Confidence value.
 */
void PageXML::setPageImageOrientation( int pagenum, int angle, const double conf ) {
  setPageImageOrientation( pagenum, angle, &conf );
}

/**
 * Gets the image orientation for the given node.
 *
 * @param node   A node to get its image orientation.
 * @return       Orientation in degrees.
 */
int PageXML::getPageImageOrientation( xmlNodePt node ) {
  node = selectNth( "ancestor-or-self::*[local-name()='Page']", 0, node );
  if( ! node ) {
    throw_runtime_error( "PageXML.getPageImageOrientation: node must be a Page or descendant of a Page" );
    return 0;
  }

  node = selectNth( "_:ImageOrientation", 0, node );
  if( ! node )
    return 0;

  string angle = getAttr( node, "angle" );
  return atoi(angle.c_str());
}

/**
 * Gets the image orientation for the given Page number.
 *
 * @param pagenum  The page number (0-based).
 * @return         Orientation in degrees.
 */
int PageXML::getPageImageOrientation( int pagenum ) {
  return getPageImageOrientation( selectNth("//_:Page",pagenum) );
}

/**
 * Gets the width of a page (might be different to image width due to the image orientation).
 *
 * @param node   A node to get its page width.
 * @return       The page width.
 */
unsigned int PageXML::getPageWidth( xmlNodePt node ) {
  node = selectNth( "ancestor-or-self::*[local-name()='Page']", 0, node );
  if( ! nodeIs( node, "Page" ) ) {
    throw_runtime_error( "PageXML.getPageWidth: node is required to be a Page or descendant of a Page" );
    return 0;
  }
  int angle = getPageImageOrientation( node );
  string width = getAttr( node, ( angle == 0 || angle == 180 ) ? "imageWidth" : "imageHeight" );
  return atoi(width.c_str());
}

/**
 * Gets the width of a page (might be different to image width due to the image orientation).
 *
 * @param pagenum  The page number (0-based).
 * @return         The page width.
 */
unsigned int PageXML::getPageWidth( int pagenum ) {
  return getPageWidth( selectNth("//_:Page",pagenum) );
}

/**
 * Gets the height of a page (might be different to image width due to the image orientation).
 *
 * @param node   A node to get its page height.
 * @return       The page height.
 */
unsigned int PageXML::getPageHeight( xmlNodePt node ) {
  node = selectNth( "ancestor-or-self::*[local-name()='Page']", 0, node );
  if( ! nodeIs( node, "Page" ) ) {
    throw_runtime_error( "PageXML.getPageHeight: node is required to be a Page or descendant of a Page" );
    return 0;
  }
  int angle = getPageImageOrientation( node );
  string height = getAttr( node, ( angle == 0 || angle == 180 ) ? "imageHeight" : "imageWidth" );
  return atoi(height.c_str());
}

/**
 * Gets the height of a page (might be different to image width due to the image orientation).
 *
 * @param pagenum  The page number (0-based).
 * @return         The page height.
 */
unsigned int PageXML::getPageHeight( int pagenum ) {
  return getPageHeight( selectNth("//_:Page",pagenum) );
}

/**
 * Sets the width of a page (actually sets imageWidth accounting for image orientation).
 *
 * @param node   A node to set its page width.
 * @param width  The width to set.
 */
void PageXML::setPageWidth( xmlNodePt node, int width ) {
  node = selectNth( "ancestor-or-self::*[local-name()='Page']", 0, node );
  if( ! nodeIs( node, "Page" ) )
    throw_runtime_error( "PageXML.setPageWidth: node is required to be a Page or descendant of a Page" );
  int angle = getPageImageOrientation( node );
  setAttr( node, ( angle == 0 || angle == 180 ) ? "imageWidth" : "imageHeight", std::to_string(width).c_str() );
}

/**
 * Sets the height of a page (actually sets imageHeight accounting for image orientation).
 *
 * @param node    A node to set its page height.
 * @param height  The height to set.
 */
void PageXML::setPageHeight( xmlNodePt node, int height ) {
  node = selectNth( "ancestor-or-self::*[local-name()='Page']", 0, node );
  if( ! nodeIs( node, "Page" ) )
    throw_runtime_error( "PageXML.setPageHeight: node is required to be a Page or descendant of a Page" );
  int angle = getPageImageOrientation( node );
  setAttr( node, ( angle == 0 || angle == 180 ) ? "imageHeight" : "imageWidth", std::to_string(height).c_str() );
}

/**
 * Retrieves pages size.
 *
 * @param pages      Page nodes.
 * @return           Vector of page sizes.
 */
std::vector<cv::Size2i> PageXML::getPagesSize( std::vector<xmlNodePt> pages ) {
  std::vector<cv::Size2i> sizes;
  for ( int n=0; n<(int)pages.size(); n++ ) {
    if( ! nodeIs( pages[n], "Page" ) ) {
      throw_runtime_error( "PageXML.getPagesSize: node is required to be a Page" );
      return sizes;
    }
    cv::Size2i size( getPageWidth(pages[n]), getPageHeight(pages[n]) );
    sizes.push_back(size);
  }
  return sizes;
}

/**
 * Retrieves pages size.
 *
 * @param xpath      Selector for Page nodes.
 * @return           Vector of page sizes.
 */
std::vector<cv::Size2i> PageXML::getPagesSize( const char* xpath ) {
  return getPagesSize( select(xpath) );
}

/**
 * Rotates a page.
 *
 * @param angle                     Angle to rotate in degrees {0,90,180,-90}.
 * @param page                      The Page node.
 * @param update_image_orientation  Whether to update the ImageOrientation element.
 * @param conf                      Confidence value.
 * @return                          Number of elements modified.
 */
int PageXML::rotatePage( int angle, xmlNodePt page, bool update_image_orientation, const double conf ) {
  return rotatePage( angle, page, update_image_orientation, &conf );
}

/**
 * Rotates a page.
 *
 * @param angle                     Angle to rotate in degrees {0,90,180,-90}.
 * @param page                      The Page node.
 * @param update_image_orientation  Whether to check that the aspect ratio is properly preserved.
 * @param _conf                     Pointer to confidence value, NULL for no confidence.
 * @return                          Number of elements modified.
 */
int PageXML::rotatePage( int angle, xmlNodePt page, bool update_image_orientation, const double* _conf ) {
  if( angle % 90 != 0 ) {
    throw_runtime_error( "PageXML.rotatePage: only angles multiple of 90 are accepted" );
    return 0;
  }

  /// Normalize angle between [-90,180] ///
  angle = ( angle + 90 ) % 360;
  if ( angle < 0 )
    angle += 360;
  angle -= 90;

  int pageWidth = getPageWidth(page);
  int pageHeight = getPageHeight(page);

  /// Set image orientation ///
  int num = 0;
  if ( update_image_orientation ) {
    setPageImageOrientation( page, getPageImageOrientation(page)-angle, _conf );
    num++;
  }
  if ( angle == 0 )
    return num;

  /// Select all elements with coordinates ///
  std::vector<xmlNodePt> points = select(".//@points[.!=\"0,0 0,0\"]", page);
  std::vector<xmlNodePt> fpgrams = select(".//_:Property[@key='fpgram']/@value", page);
  points.insert(points.end(), fpgrams.begin(), fpgrams.end());

  /// Rotate all coordinates ///
  for ( int n=(int)points.size()-1; n>=0; n-- ) {
    std::vector<cv::Point2f> pts = stringToPoints(getValue(points[n]));
    if ( angle == -90 )
      for ( int m=(int)pts.size()-1; m>=0; m-- ) {
        double x = pts[m].x;
        pts[m].x = pageHeight-1-pts[m].y;
        pts[m].y = x;
      }
    else if ( angle == 90 )
      for ( int m=(int)pts.size()-1; m>=0; m-- ) {
        double x = pts[m].x;
        pts[m].x = pts[m].y;
        pts[m].y = pageWidth-1-x;
      }
    else if ( angle == 180 )
      for ( int m=(int)pts.size()-1; m>=0; m-- ) {
        pts[m].x = pageWidth-1-pts[m].x;
        pts[m].y = pageHeight-1-pts[m].y;
      }
    setValue( points[n], pointsToString(pts).c_str() );
    num++;
  }

  return num;
}

/**
 * Resizes pages and all respective coordinates.
 *
 * @param sizes               Page sizes to resize to.
 * @param pages               Page nodes.
 * @param check_aspect_ratio  Whether to check that the aspect ratio is properly preserved.
 * @return                    Number of pages+points attributes modified.
 */
int PageXML::resize( std::vector<cv::Size2i> sizes, std::vector<xmlNodePt> pages, bool check_aspect_ratio ) {
  /// Input checks ///
  if ( sizes.size() != pages.size() ) {
    throw_runtime_error( "PageXML.resize: number of sizes and pages must coincide" );
    return 0;
  }
  for ( int n=0; n<(int)pages.size(); n++ )
    if ( ! nodeIs( pages[n], "Page" ) ) {
      throw_runtime_error( "PageXML.resize: all nodes are required to be Page" );
      return 0;
    }

  /// Check that aspect ratios are the same ///
  std::vector<cv::Size2i> orig_sizes = getPagesSize(pages);
  if ( check_aspect_ratio )
    for ( int n=0; n<(int)pages.size(); n++ ) {
      double ratio_diff = sizes[n].width < sizes[n].height ?
        (double)sizes[n].width/sizes[n].height - (double)orig_sizes[n].width/orig_sizes[n].height:
        (double)sizes[n].height/sizes[n].width - (double)orig_sizes[n].height/orig_sizes[n].width;
      if ( fabs(ratio_diff) > 1e-2 ) {
        throw_runtime_error( "PageXML.resize: aspect ratio too different for page %d (%ux%u vs. %ux%u)", n, orig_sizes[n].width, orig_sizes[n].height, sizes[n].width, sizes[n].height );
        return 0;
      }
    }

  /// For each page update size and resize coords ///
  int updated = 0;
  for ( int n=0; n<(int)pages.size(); n++ ) {
    int currWidth = getPageWidth(pages[n]);
    int currHeight = getPageHeight(pages[n]);
    if ( currWidth == sizes[n].width && currHeight == sizes[n].height )
      continue;

    setPageWidth( pages[n], sizes[n].width );
    setPageHeight( pages[n], sizes[n].height );
    updated++;

    double fact_x = (double)sizes[n].width/orig_sizes[n].width;
    double fact_y = (double)sizes[n].height/orig_sizes[n].height;

    /// Resize Coords/@points and Baseline/@points ///
    std::vector<xmlNodePt> coords = select( ".//*[@points]", pages[n] );
    for ( int m=0; m<(int)coords.size(); m++ ) {
      std::vector<cv::Point2f> pts = stringToPoints( getAttr(coords[m],"points") );
      for ( int k=(int)pts.size()-1; k>=0; k-- ) {
        pts[k].x *= fact_x;
        pts[k].y *= fact_y;
      }
      setAttr( coords[m], "points", pointsToString(pts).c_str() );
    }

    /// Resize Property[@key='fpgram']/@value ///
    std::vector<xmlNodePt> fpgram = select( ".//_:Property[@key='fpgram' and @value]", pages[n] );
    for ( int m=0; m<(int)fpgram.size(); m++ ) {
      std::vector<cv::Point2f> pts = stringToPoints( getAttr(fpgram[m],"value") );
      for ( int k=(int)pts.size()-1; k>=0; k-- ) {
        pts[k].x *= fact_x;
        pts[k].y *= fact_y;
      }
      setAttr( fpgram[m], "value", pointsToString(pts).c_str() );
    }

    updated += coords.size()+fpgram.size();
  }

  return updated;
}

/**
 * Resizes pages and all respective coordinates.
 *
 * @param sizes               Page sizes to resize to.
 * @param xpath               Selector for Page nodes.
 * @param check_aspect_ratio  Whether to check that the aspect ratio is properly preserved.
 * @return                    Number of pages+points attributes modified.
 */
int PageXML::resize( std::vector<cv::Size2i> sizes, const char* xpath, bool check_aspect_ratio ) {
  return resize( sizes, select(xpath), check_aspect_ratio );
}

/**
 * Resizes a page and all respective coordinates.
 *
 * @param size                Page size to resize to.
 * @param page                Page node.
 * @param check_aspect_ratio  Whether to check that the aspect ratio is properly preserved.
 * @return                    Number of pages+points attributes modified.
 */
int PageXML::resize( cv::Size2i size, xmlNodePt page, bool check_aspect_ratio ) {
  std::vector<cv::Size2i> sizes = {size};
  std::vector<xmlNodePt> pages = {page};
  return resize( sizes, pages, check_aspect_ratio );
}

/**
 * Resizes a page and all respective coordinates.
 *
 * @param factor              Resizing factor.
 * @param xpath               Selector for Page nodes.
 * @return                    Number of pages+points attributes modified.
 */
int PageXML::resize( double fact, const char* xpath ) {
  std::vector<xmlNodePt> pages = select(xpath);
  std::vector<cv::Size2i> sizes = getPagesSize(pages);
  for ( int p=0; p<(int)sizes.size(); p++ ) {
    sizes[p].width = std::round(fact*sizes[p].width);
    sizes[p].height = std::round(fact*sizes[p].height);
  }
  return resize( sizes, pages, true );
}

/**
 * Sets the imageFilename of a page.
 */
void PageXML::setPageImageFilename( xmlNodePt node, const char* image ) {
  if( ! nodeIs( node, "Page" ) ) {
    throw_runtime_error( "PageXML.setPageImageFilename: node is required to be a Page" );
    return;
  }
  setAttr( node, "imageFilename", image );
}
void PageXML::setPageImageFilename( int pagenum, const char* image ) {
  return setPageImageFilename( selectNth("//_:Page",pagenum), image );
}

/**
 * Returns the imageFilename of a page.
 */
string PageXML::getPageImageFilename( xmlNodePt node ) {
  node = selectNth( "ancestor-or-self::*[local-name()='Page']", 0, node );
  if( ! nodeIs( node, "Page" ) ) {
    throw_runtime_error( "PageXML.getPageImageFilename: node is required to be a Page or descendant of a Page" );
    return string("");
  }
  return getAttr( node, "imageFilename" );
}
string PageXML::getPageImageFilename( int pagenum ) {
  return getPageImageFilename( selectNth("//_:Page",pagenum) );
}

/**
 * Checks whether a page image is loaded.
 */
bool PageXML::isPageImageLoaded( int pagenum ) {
  bool loaded = true;
#if defined (__PAGEXML_LEPT__)
  if( pagesImage[pagenum] == NULL )
#elif defined (__PAGEXML_IMG_MAGICK__)
  if( pagesImage[pagenum].columns() == 0 )
#elif defined (__PAGEXML_IMG_CV__)
  if( ! pagesImage[pagenum].data )
#endif
    loaded = false;
  return loaded;
}
bool PageXML::isPageImageLoaded( xmlNodePt node ) {
  return isPageImageLoaded( getPageNumber(node) );
}

/**
 * Returns the image for the given page.
 */
PageImage PageXML::getPageImage( int pagenum ) {
  if( pagenum < 0 || pagenum >= (int)pagesImage.size() ) {
    throw_runtime_error( "PageXML.getPageImage: page number out of range" );
    PageImage pageImage;
    return pageImage;
  }

  if( ! isPageImageLoaded(pagenum) )
    loadImage(pagenum);

  return pagesImage[pagenum];
}
PageImage PageXML::getPageImage( xmlNodePt node ) {
  return getPageImage( getPageNumber(node) );
}

/**
 * Adds a Glyph to a given node.
 *
 * @param node       The node of element to add the Glyph.
 * @param id         ID for Glyph, if NULL it is selected automatically.
 * @param before_id  If !=NULL inserts it before the Glyph with this ID.
 * @return           Pointer to created element.
 */
xmlNodePt PageXML::addGlyph( xmlNodePt node, const char* id, const char* before_id ) {
  if( ! nodeIs( node, "Word" ) ) {
    throw_runtime_error( "PageXML.addGlyph: node is required to be a Word" );
    return NULL;
  }

  xmlNodePt glyph;

  string gid;
  if( id != NULL )
    gid = string(id);
  else {
    string wid = getAttr( node, "id" );
    if( wid.empty() ) {
      throw_runtime_error( "PageXML.addGlyph: expected element to have an id attribute" );
      return NULL;
    }
    int n = select( "_:Glyph", node ).size();
    while( true ) {
      if( selectByID( (wid+"_g"+to_string(++n)).c_str() ) == NULL ) {
        gid = wid+"_g"+to_string(n);
        break;
      }
      if( n > 100000 ) {
        throw_runtime_error( "PageXML.addGlyph: apparently in infinite loop" );
        return NULL;
      }
    }
  }

  if( before_id != NULL ) {
    xmlNodePt sel = selectByID( before_id, node );
    if( sel == NULL ) {
      throw_runtime_error( "PageXML.addGlyph: unable to find id=%s", before_id );
      return NULL;
    }
    glyph = addElem( "Glyph", gid.c_str(), sel, PAGEXML_INSERT_PREVSIB, true );
  }
  else {
    vector<xmlNodePt> sel = select( "_:TextEquiv", node );
    if( sel.size() > 0 )
      glyph = addElem( "Glyph", gid.c_str(), sel[0], PAGEXML_INSERT_PREVSIB, true );
    else
      glyph = addElem( "Glyph", gid.c_str(), node, PAGEXML_INSERT_APPEND, true );
  }

  return glyph;
}

/**
 * Adds a Glyph to a given xpath.
 *
 * @param xpath      Selector for element to set the Glyph.
 * @param id         ID for Glyph, if NULL it is selected automatically.
 * @param before_id  If !=NULL inserts it before the Glyph with this ID.
 * @return           Pointer to created element.
 */
xmlNodePt PageXML::addGlyph( const char* xpath, const char* id, const char* before_id ) {
  vector<xmlNodePt> target = select( xpath );
  if( target.size() == 0 ) {
    throw_runtime_error( "PageXML.addGlyph: unmatched target: xpath=%s", xpath );
    return NULL;
  }

  return addGlyph( target[0], id, before_id );
}

/**
 * Adds a Word to a given node.
 *
 * @param node       The node of element to add the Word.
 * @param id         ID for Word, if NULL it is selected automatically.
 * @param before_id  If !=NULL inserts it before the Word with this ID.
 * @return           Pointer to created element.
 */
xmlNodePt PageXML::addWord( xmlNodePt node, const char* id, const char* before_id ) {
  if( ! nodeIs( node, "TextLine" ) ) {
    throw_runtime_error( "PageXML.addWord: node is required to be a TextLine" );
    return NULL;
  }

  xmlNodePt word;

  string wid;
  if( id != NULL )
    wid = string(id);
  else {
    string lid = getAttr( node, "id" );
    if( lid.empty() ) {
      throw_runtime_error( "PageXML.addWord: expected element to have an id attribute" );
      return NULL;
    }
    int n = select( "_:Word", node ).size();
    while( true ) {
      if( selectByID( (lid+"_w"+to_string(++n)).c_str() ) == NULL ) {
        wid = lid+"_w"+to_string(n);
        break;
      }
      if( n > 100000 ) {
        throw_runtime_error( "PageXML.addWord: apparently in infinite loop" );
        return NULL;
      }
    }
  }

  if( before_id != NULL ) {
    xmlNodePt sel = selectByID( before_id, node );
    if( sel == NULL ) {
      throw_runtime_error( "PageXML.addWord: unable to find id=%s", before_id );
      return NULL;
    }
    word = addElem( "Word", wid.c_str(), sel, PAGEXML_INSERT_PREVSIB, true );
  }
  else {
    vector<xmlNodePt> sel = select( "_:TextEquiv", node );
    if( sel.size() > 0 )
      word = addElem( "Word", wid.c_str(), sel[0], PAGEXML_INSERT_PREVSIB, true );
    else
      word = addElem( "Word", wid.c_str(), node, PAGEXML_INSERT_APPEND, true );
  }

  return word;
}

/**
 * Adds a Word to a given xpath.
 *
 * @param xpath      Selector for element to set the Word.
 * @param id         ID for Word, if NULL it is selected automatically.
 * @param before_id  If !=NULL inserts it before the Word with this ID.
 * @return           Pointer to created element.
 */
xmlNodePt PageXML::addWord( const char* xpath, const char* id, const char* before_id ) {
  vector<xmlNodePt> target = select( xpath );
  if( target.size() == 0 ) {
    throw_runtime_error( "PageXML.addWord: unmatched target: xpath=%s", xpath );
    return NULL;
  }

  return addWord( target[0], id, before_id );
}

/**
 * Adds a TextLine to a given node.
 *
 * @param node       The node of element to add the TextLine.
 * @param id         ID for TextLine, if NULL it is selected automatically.
 * @param before_id  If !=NULL inserts it before the TextLine with this ID.
 * @return           Pointer to created element.
 */
xmlNodePt PageXML::addTextLine( xmlNodePt node, const char* id, const char* before_id ) {
  if( ! nodeIs( node, "TextRegion" ) ) {
    throw_runtime_error( "PageXML.addTextLine: node is required to be a TextRegion" );
    return NULL;
  }

  xmlNodePt textline;

  string lid;
  if( id != NULL )
    lid = string(id);
  else {
    string rid = getAttr( node, "id" );
    if( rid.empty() ) {
      throw_runtime_error( "PageXML.addTextLine: expected element to have an id attribute" );
      return NULL;
    }
    int n = select( "_:TextLine", node ).size();
    while( true ) {
      if( selectByID( (rid+"_l"+to_string(++n)).c_str() ) == NULL ) {
        lid = rid+"_l"+to_string(n);
        break;
      }
      if( n > 100000 ) {
        throw_runtime_error( "PageXML.addTextLine: apparently in infinite loop" );
        return NULL;
      }
    }
  }

  if( before_id != NULL ) {
    xmlNodePt sel = selectByID( before_id, node );
    if( sel == NULL ) {
      throw_runtime_error( "PageXML.addTextLine: unable to find id=%s", before_id );
      return NULL;
    }
    textline = addElem( "TextLine", lid.c_str(), sel, PAGEXML_INSERT_PREVSIB, true );
  }
  else {
    vector<xmlNodePt> sel = select( "_:TextEquiv", node );
    if( sel.size() > 0 )
      textline = addElem( "TextLine", lid.c_str(), sel[0], PAGEXML_INSERT_PREVSIB, true );
    else
      textline = addElem( "TextLine", lid.c_str(), node, PAGEXML_INSERT_APPEND, true );
  }

  return textline;
}

/**
 * Adds a TextLine to a given xpath.
 *
 * @param xpath      Selector for element to add the TextLine.
 * @param id         ID for TextLine, if NULL it is selected automatically.
 * @param before_id  If !=NULL inserts it before the TextLine with this ID.
 * @return           Pointer to created element.
 */
xmlNodePt PageXML::addTextLine( const char* xpath, const char* id, const char* before_id ) {
  vector<xmlNodePt> target = select( xpath );
  if( target.size() == 0 ) {
    throw_runtime_error( "PageXML.addTextLine: unmatched target: xpath=%s", xpath );
    return NULL;
  }

  return addTextLine( target[0], id, before_id );
}

/**
 * Adds a TextRegion to a given node.
 *
 * @param node       The node of element to add the TextRegion.
 * @param id         ID for TextRegion, if NULL it is selected automatically.
 * @param before_id  If !=NULL inserts it before the TextRegion with this ID.
 * @param prepend    Whether to add element before all other TextRegions.
 * @return           Pointer to created element.
 */
xmlNodePt PageXML::addTextRegion( xmlNodePt node, const char* id, const char* before_id, bool prepend ) {
  if( ! nodeIs( node, "Page" ) ) {
    throw_runtime_error( "PageXML.addTextRegion: node is required to be a Page" );
    return NULL;
  }

  xmlNodePt textreg;

  string rid;
  if( id != NULL )
    rid = string(id);
  else {
    int n = select( "*/_:TextRegion", node->parent ).size();
    while( true ) {
      if( selectByID( (string("t")+to_string(++n)).c_str() ) == NULL ) {
        rid = string("t")+to_string(n);
        break;
      }
      if( n > 100000 ) {
        throw_runtime_error( "PageXML.addTextRegion: apparently in infinite loop" );
        return NULL;
      }
    }
  }

  if( before_id != NULL ) {
    xmlNodePt sel = selectByID( before_id, node );
    if( sel == NULL ) {
      throw_runtime_error( "PageXML.addTextRegion: unable to find id=%s", before_id );
      return NULL;
    }
    textreg = addElem( "TextRegion", rid.c_str(), sel, PAGEXML_INSERT_PREVSIB, true );
  }
  else {
    vector<xmlNodePt> sel = select( prepend ? "*[local-name()='TextEquiv' or local-name()='TextRegion']" : "_:TextEquiv", node );
    if( sel.size() > 0 )
      textreg = addElem( "TextRegion", rid.c_str(), sel[0], PAGEXML_INSERT_PREVSIB, true );
    else
      textreg = addElem( "TextRegion", rid.c_str(), node, PAGEXML_INSERT_APPEND, true );
  }

  return textreg;
}

/**
 * Adds new TextRegion to a given xpath.
 *
 * @param xpath      Selector for element to add the TextRegion.
 * @param id         ID for TextRegion, if NULL it is selected automatically.
 * @param before_id  If !=NULL inserts it before the TextRegion with this ID.
 * @return           Pointer to created element.
 */
xmlNodePt PageXML::addTextRegion( const char* xpath, const char* id, const char* before_id, bool prepend ) {
  if( xpath == NULL )
    xpath = "//_:Page";
  vector<xmlNodePt> target = select( xpath );
  if( target.size() == 0 ) {
    throw_runtime_error( "PageXML.addTextRegion: unmatched target: xpath=%s", xpath );
    return NULL;
  }

  return addTextRegion( target[0], id, before_id, prepend );
}

/**
 * Adds a Page to the PcGts node.
 *
 * @param image        Path to the image file.
 * @param imgW         Width of image.
 * @param imgH         Height of image.
 * @param id           ID for Page, if NULL it is left unset.
 * @param before_node  If !=NULL inserts it before the provided Page node.
 * @return             Pointer to created element.
 */
xmlNodePt PageXML::addPage( const char* image, const int imgW, const int imgH, const char* id, xmlNodePt before_node ) {
  xmlNodePt page;

#if defined (__PAGEXML_LEPT__)
  PageImage pageImage = NULL;
#else
  PageImage pageImage;
#endif
  string imageFilename;
  string imageBase;

  int page_num = -1;

  if( before_node != NULL ) {
    if( ! nodeIs( before_node, "Page" ) ) {
      throw_runtime_error( "PageXML.addPage: before_node is required to be a Page" );
      return NULL;
    }
    page = addElem( "Page", id, before_node, PAGEXML_INSERT_PREVSIB, true );
    page_num = getPageNumber(page);

    int numpages = pagesImage.size();
    pagesImage.push_back(pagesImage[numpages-1]);
    pagesImageFilename.push_back(pagesImageFilename[numpages-1]);
    pagesImageBase.push_back(pagesImageBase[numpages-1]);
    for( int n=numpages-1; n>page_num; n-- ) {
      pagesImage[n] = pagesImage[n-1];
      pagesImageFilename[n] = pagesImageFilename[n-1];
      pagesImageBase[n] = pagesImageBase[n-1];
    }
    pagesImage[page_num] = pageImage;
    pagesImageFilename[page_num] = imageFilename;
    pagesImageBase[page_num] = imageBase;
  }
  else {
    xmlNodePt pcgts = selectNth("/_:PcGts",0);
    if( ! pcgts ) {
      throw_runtime_error( "PageXML.addPage: unable to select PcGts node" );
      return NULL;
    }
    page = addElem( "Page", id, pcgts, PAGEXML_INSERT_APPEND, true );
    page_num = getPageNumber(page);

    pagesImage.push_back(pageImage);
    pagesImageFilename.push_back(imageFilename);
    pagesImageBase.push_back(imageBase);
  }

  setAttr( page, "imageFilename", image );
  // @todo If size is zero, read the image and get size like in newXml
  setAttr( page, "imageWidth", to_string(imgW).c_str() );
  setAttr( page, "imageHeight", to_string(imgH).c_str() );

  parsePageImage( page_num );

  return page;
}

/**
 * Adds a Page to the PcGts node.
 *
 * @param image        Path to the image file.
 * @param imgW         Width of image.
 * @param imgH         Height of image.
 * @param id           ID for Page, if NULL it is left unset.
 * @param before_node  If !=NULL inserts it before the provided Page node.
 * @return             Pointer to created element.
 */
xmlNodePt PageXML::addPage( std::string image, const int imgW, const int imgH, const char* id, xmlNodePt before_node ) {
  return addPage(image.c_str(),imgW,imgH,id,before_node);
}

/**
 * Gets image bases for all pages in xml.
 *
 * @return  Vector of strings containing the image base names.
 */
std::vector<std::string> PageXML::getImageBases() {
  return pagesImageBase;
}

/**
 * Verifies that all IDs in page are unique.
 */
bool PageXML::areIDsUnique() {
  string id;
  bool unique = true;
  map<string,bool> seen;

  vector<xmlNodePt> nodes = select( "//*[@id]" );
  for( int n=(int)nodes.size()-1; n>=0; n-- ) {
    id = getAttr( nodes[n], "id" );
    if( seen.find(id) != seen.end() && seen[id] ) {
      fprintf( stderr, "PageXML.areIDsUnique: duplicate ID: %s\n", id.c_str() );
      seen[id] = unique = false;
    }
    else
      seen[id] = true;
  }

  return unique;
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
  string sampbase;
  xmlNodePt prevPage = NULL;

  vector<xmlNodePt> nodes = select( "//*[@id][local-name()='TextLine' or local-name()='TextRegion']" );

  for( int n=(int)nodes.size()-1; n>=0; n-- ) {
    xmlNodePt page = selectNth( "ancestor-or-self::*[local-name()='Page']", 0, nodes[n] );
    if( prevPage != page ) {
      prevPage = page;
      sampbase = pagesImageBase[getPageNumber(page)];
    }
    char* id = (char*)xmlGetProp( nodes[n], (xmlChar*)"id" );
    string sampid(id);
    if( sampid.size() > sampbase.size() &&
        ! sampid.compare(0,sampbase.size(),sampbase) ) {
      sampid.erase( 0, sampbase.size() );
      sampid = regex_replace(sampid,reTrim,"");
      if( sampid.size() > 0 ) {
        sampid = regex_replace(sampid,reInvalid,"_");
        setAttr( nodes[n], "orig-id", id );
        setAttr( nodes[n], "id", sampid.c_str() );
        simplified++;
      }
    }
    free(id);
  }

  return simplified;
}

/**
 * Modifies imageFilename to be a relative path w.r.t. given xml path. Currently just checks prefix directories and removes it.
 */
void PageXML::relativizeImageFilename( const char* xml_path ) {
  string xml_base = regex_replace(xml_path,regex("/[^/]+$"),"/");

  vector<xmlNodePt> pages = select( "//_:Page" );

  for ( int n=(int)pages.size()-1; n>=0; n-- ) {
    std::string img = getAttr( pages[n], "imageFilename" );
    if ( img.compare(0, xml_base.length(), xml_base) == 0 ) {
      img.erase(0,xml_base.length());
      setAttr( pages[n], "imageFilename", img.c_str() );
    }
  }
}

/**
 * Gets a unique id.
 *
 * @param prefix      Prefix for id.
 * @param suffix      Suffix for id.
 * @param count_start Counter start to place between prefix and suffix.
 * @param count_max   Maximum count to test.
 * @return            The generated unique id.
 */
std::string PageXML::getUniqueID( const char* prefix, const char* suffix, int count_start, int count_max ) {
  std::string ssuffix = std::string(suffix == NULL ? "" : suffix);
  std::string id;
  int n;
  for ( n=count_start; n<=count_max; n++ ) {
    if( selectByID( (std::string(prefix)+std::to_string(n)+ssuffix).c_str() ) == NULL ) {
      id = std::string(prefix)+std::to_string(n)+ssuffix;
      break;
    }
  }
  if( n > count_max )
    throw_runtime_error( "PageXML.getUniqueID: unable to get unique id" );
  return id;
}

/**
 * Relabels IDs of child elements.
 *
 * @param node         Base node.
 * @param include_self Whether to also relabel the base node.
 * @return             Number of IDs affected.
 */
int PageXML::relabelChildIDs( xmlNodePt node, bool include_self ) {
  int n, cnt = 0;
  if ( include_self ) {
    std::string id;
    if( nodeIs( node, "Page") )
      id = getUniqueID( "pg" );
    else if( nodeIs( node, "TextRegion") ) {
      std::string pgid = getAttr(node->parent,"id");
      id = getUniqueID( pgid.empty() ? "r" : (pgid+"_r").c_str() );
    }
    else if( nodeIs( node, "TextLine") )
      id = getUniqueID( (getAttr(node->parent,"id")+"_l").c_str() );
    else if( nodeIs( node, "Word") )
      id = getUniqueID( (getAttr(node->parent,"id")+"_w").c_str() );
    else if( nodeIs( node, "Glyph") )
      id = getUniqueID( (getAttr(node->parent,"id")+"_g").c_str() );
    else
      throw_runtime_error( "PageXML.relabelChildIDs: unsupported node type" );
    setAttr(node, "id", id.c_str());
    cnt++;
  }

  std::vector<xmlNodePt> lines = select(".//_:TextLine", node);
  for ( n=0; n<(int)lines.size(); n++ )
    setAttr(lines[n], "id", (getAttr(lines[n]->parent,"id")+"_l"+std::to_string(n+1)).c_str());
  cnt += lines.size();

  std::vector<xmlNodePt> words = select(".//_:Word", node);
  for ( n=0; n<(int)words.size(); n++ )
    setAttr(words[n], "id", (getAttr(words[n]->parent,"id")+"_w"+std::to_string(n+1)).c_str());
  cnt += words.size();

  std::vector<xmlNodePt> glyphs = select(".//_:Glyph", node);
  for ( n=0; n<(int)glyphs.size(); n++ )
    setAttr(glyphs[n], "id", (getAttr(glyphs[n]->parent,"id")+"_g"+std::to_string(n+1)).c_str());
  cnt += glyphs.size();

  return cnt;
}


#if defined (__PAGEXML_OGR__)

OGRMultiPolygon_::~OGRMultiPolygon_() {
  if ( multipolygon )
    OGRGeometryFactory::destroyGeometry(multipolygon);
}
OGRMultiPolygon_::OGRMultiPolygon_() {}
OGRMultiPolygon_::OGRMultiPolygon_( OGRGeometry* geometry ) {
  multipolygon = (OGRMultiPolygon*)OGRGeometryFactory::forceToMultiPolygon(geometry);
}

OGRMultiLineString_::~OGRMultiLineString_() {
  if ( multipolyline )
    OGRGeometryFactory::destroyGeometry(multipolyline);
}
OGRMultiLineString_::OGRMultiLineString_() {}
OGRMultiLineString_::OGRMultiLineString_( OGRGeometry* geometry ) {
  multipolyline = (OGRMultiLineString*)OGRGeometryFactory::forceToMultiLineString(geometry);
}


/**
 * Converts Coords to an OGRMultiPolygon.
 *
 * @param points     Vector of x,y points.
 * @return           Pointer to OGRMultiPolygon element.
 */
OGRMultiPolygonPtr_ PageXML::pointsToOGRpolygon( std::vector<cv::Point2f> points ) {
  if ( points.size() == 0 )
    return OGRMultiPolygonPtr_(new OGRMultiPolygon_());

  OGRLinearRing* ring = new OGRLinearRing();
  OGRPolygon* poly = new OGRPolygon();

  for ( int n=0; n<(int)points.size(); n++ )
    ring->addPoint(points[n].x, points[n].y);
  ring->closeRings();
  poly->addRing(ring);
  delete ring;

  return OGRMultiPolygonPtr_(new OGRMultiPolygon_(poly));
}

/**
 * Converts Coords to OGRMultiPolygons.
 *
 * @param points     Vectors of x,y points.
 * @return           Pointer to OGRMultiPolygon element.
 */
std::vector<OGRMultiPolygonPtr_> PageXML::pointsToOGRpolygons( std::vector<std::vector<cv::Point2f> > points ) {
  std::vector<OGRMultiPolygonPtr_> polys;
  for ( int n=0; n<(int)points.size(); n++ )
    polys.push_back( pointsToOGRpolygon(points[n]) );
  return polys;
}

/**
 * Gets an element's Coords as an OGRMultiPolygon.
 *
 * @param node       The element from which to extract the Coords points.
 * @param xpath      Selector for the Coords element.
 * @return           Pointer to OGRMultiPolygon element.
 */
OGRMultiPolygonPtr_ PageXML::getOGRpolygon( const xmlNodePt node, const char* xpath ) {
  return pointsToOGRpolygon( getPoints(node,xpath) );
}

/**
 * Gets elements' Coords as OGRMultiPolygons.
 *
 * @param nodes      Elements from which to extract the Coords points.
 * @param xpath      Selector for the Coords element.
 * @return           Vector of OGRMultiPolygon pointer elements.
 */
std::vector<OGRMultiPolygonPtr_> PageXML::getOGRpolygons( std::vector<xmlNodePt> nodes, const char* xpath ) {
  std::vector<OGRMultiPolygonPtr_> polys;
  for ( int n=0; n<(int)nodes.size(); n++ )
    polys.push_back( getOGRpolygon(nodes[n],xpath) );
  return polys;
}

/**
 * Gets the union of Coords elements as a OGRMultiPolygon.
 *
 * @param nodes      Elements from which to extract the Coords points.
 * @param xpath      Selector for the Coords element.
 * @return           Pointer to OGRMultiPolygon element.
 */
OGRMultiPolygonPtr_ PageXML::getUnionOGRpolygon( std::vector<xmlNodePt> nodes, const char* xpath ) {
  OGRMultiPolygonPtr_ geo_union = getOGRpolygon(nodes[0],xpath);
  for ( int n=1; n<(int)nodes.size(); n++ )
    geo_union = OGRMultiPolygonPtr_(new OGRMultiPolygon_( ((OGRGeometry*)geo_union->multipolygon)->Union( getOGRpolygon(nodes[n],xpath)->multipolygon ) ));
  return geo_union;
}

/**
 * Gets the area of a OGRMultiPolygon.
 *
 * @param poly       OGRMultiPolygon pointer.
 * @return           Area.
 */
double PageXML::getOGRpolygonArea( OGRMultiPolygonPtr_ poly ) {
  int isect_type = poly->multipolygon->getGeometryType();
  if ( isect_type != wkbPolygon &&
       isect_type != wkbMultiPolygon &&
       isect_type != wkbGeometryCollection )
    return 0.0;
  return poly->multipolygon->get_Area();
}

/**
 * Gets the element's Baseline as an OGRMultiLineString.
 *
 * @param node       The element from which to extract the Baseline points.
 * @return           Pointer to OGRMultiLineString element.
 */
OGRMultiLineStringPtr_ PageXML::getOGRpolyline( const xmlNodePt node, const char* xpath ) {
  std::vector<cv::Point2f> pts = getPoints(node,xpath);

  OGRLineString* curve = new OGRLineString();

  for ( int n=0; n<(int)pts.size(); n++ )
    curve->addPoint(pts[n].x, pts[n].y);

  return OGRMultiLineStringPtr_(new OGRMultiLineString_(curve));
}

/**
 * Computes the intersection between a multipolylines and a multipolygon.
 *
 * @param poly1      Polyline.
 * @param poly2      Polygon.
 * @return           Intersection geometry.
 */
OGRMultiLineStringPtr_ PageXML::multiPolylineIntersection( OGRMultiLineStringPtr_ poly1, OGRMultiPolygonPtr_ poly2 ) {
  return OGRMultiLineStringPtr_(new OGRMultiLineString_( poly1->multipolyline->Intersection(poly2->multipolygon) ));
}

/**
 * Computes the intersection of two multipolygons.
 *
 * @param poly1      First polygon.
 * @param poly2      Second polygon.
 * @return           Intersection geometry.
 */
OGRMultiPolygonPtr_ PageXML::multiPolygonIntersection( OGRMultiPolygonPtr_ poly1, OGRMultiPolygonPtr_ poly2 ) {
  return OGRMultiPolygonPtr_(new OGRMultiPolygon_( poly1->multipolygon->Intersection(poly2->multipolygon) ));
}

/**
 * Computes the intersection factor of one multipolygon over another.
 *
 * @param poly1      First polygon.
 * @param poly2      Second polygon.
 * @return           Factor value.
 */
double PageXML::computeIntersectFactor( OGRMultiPolygonPtr_ poly1, OGRMultiPolygonPtr_ poly2 ) {
  OGRMultiPolygonPtr_ isect = multiPolygonIntersection(poly1,poly2);
  return getOGRpolygonArea(isect)/getOGRpolygonArea(poly1);
}

/**
 * Computes the intersection factor of one polyline over polygon.
 *
 * @param poly1      Polyline.
 * @param poly2      Polygon.
 * @return           Factor value.
 */
double PageXML::computeIntersectFactor( OGRMultiLineStringPtr_ poly1, OGRMultiPolygonPtr_ poly2 ) {
  OGRMultiLineStringPtr_ isect = multiPolylineIntersection(poly1,poly2);
  int isect_type = isect->multipolyline->getGeometryType();
  if ( isect_type != wkbLineString &&
       isect_type != wkbMultiLineString &&
       isect_type != wkbGeometryCollection )
    return 0.0;

  return isect->multipolyline->get_Length()/poly1->multipolyline->get_Length();
}

/**
 * Computes the intersection over union (IoU) of two polygons.
 *
 * @param poly1      First polygon.
 * @param poly2      Second polygon.
 * @return           IoU value.
 */
double PageXML::computeIoU( OGRMultiPolygonPtr_ poly1, OGRMultiPolygonPtr_ poly2 ) {
  OGRMultiPolygonPtr_ isect = multiPolygonIntersection(poly1,poly2);
  double iou = getOGRpolygonArea(isect);
  if ( iou != 0.0 )
    iou /= getOGRpolygonArea(poly1)+getOGRpolygonArea(poly2)-iou;

  return iou;
}

/**
 * Computes the intersection over unions (IoU) of polygons.
 *
 * @param poly      Polygon.
 * @param polys     Vector of polygons.
 * @return          IoU values.
 */
std::vector<double> PageXML::computeIoUs( OGRMultiPolygonPtr_ poly, std::vector<OGRMultiPolygonPtr_> polys ) {
  std::vector<double> ious;
  if ( getOGRpolygonArea(poly) == 0.0 )
    for ( int n=0; n<(int)polys.size(); n++ )
      ious.push_back(0.0);
  else
    for ( int n=0; n<(int)polys.size(); n++ )
      ious.push_back( computeIoU(poly,polys[n]) );
  return ious;
}

/**
 * Computes the intersection percentage of one polygon with respect to another polygons.
 *
 * @param poly1      First polygon.
 * @param poly2      Second polygon.
 * @return           Intersection percentage value.
 */
double PageXML::computeIntersectionPercentage( OGRMultiPolygonPtr_ poly1, OGRMultiPolygonPtr_ poly2 ) {
  double poly1_area = getOGRpolygonArea(poly1);
  if ( poly1_area == 0.0 )
    return 0.0;

  OGRMultiPolygonPtr_ isect = multiPolygonIntersection(poly1,poly2);

  return getOGRpolygonArea(isect)/poly1_area;
}

/**
 * Computes the intersection percentage of one polygon with respect to other polygons.
 *
 * @param poly      Polygon.
 * @param polys     Vector of polygons.
 * @return          Intersection percentage values.
 */
std::vector<double> PageXML::computeIntersectionPercentages( OGRMultiPolygonPtr_ poly, std::vector<OGRMultiPolygonPtr_> polys ) {
  std::vector<double> isect;
  for ( int n=0; n<(int)polys.size(); n++ )
    isect.push_back( computeIntersectionPercentage(poly,polys[n]) );
  return isect;
}

/**
 * Computes the areas for given polygons.
 *
 * @param polys      Polygons to process.
 * @return           The polygon areas.
 */
std::vector<double> PageXML::computeAreas( std::vector<OGRMultiPolygonPtr_> polys ) {
  std::vector<double> areas;
  for ( int n=0; n<(int)polys.size(); n++ )
    areas.push_back( getOGRpolygonArea(polys[n]) );
  return areas;
}

/**
 * Computes polygon-polygon intersections weighted by area.
 *
 * @param poly    Polygon.
 * @param polys   Polygons to compare with.
 * @param areas   Polygons areas.
 * @return        Obtained intersection scores.
 */
std::vector<double> PageXML::computeCoordsIntersectionsWeightedByArea( OGRMultiPolygonPtr_ poly, std::vector<OGRMultiPolygonPtr_> polys, std::vector<double> areas ) {
  std::vector<double> scores;

  /// Check input ///
  if ( polys.size() != areas.size() ) {
    throw_runtime_error( "PageXML.computeCoordsIntersectionsWeightedByArea: size of polys and areas must be the same" );
    return scores;
  }

  /// Compute intersections ///
  double poly_area = getOGRpolygonArea(poly);
  if ( poly_area == 0.0 ) {
    for ( int n=0; n<(int)polys.size(); n++ )
      scores.push_back(0.0);
    return scores;
  }
  double sum_areas = 0.0;
  int isect_count = 0;
  for ( int n=0; n<(int)polys.size(); n++ ) {
    OGRMultiPolygonPtr_ isect = multiPolygonIntersection(poly,polys[n]);
    double isect_area = getOGRpolygonArea(isect);
    scores.push_back( isect_area <= 0.0 ? 0.0 : isect_area/poly_area );
    if ( isect_area > 0.0 ) {
      sum_areas += areas[n];
      isect_count++;
    }
  }

  /// Return if fewer than 2 intersects ///
  if ( isect_count < 2 )
    return scores;

  /// Weight by areas ///
  for ( int n=0; n<(int)scores.size(); n++ )
    if ( scores[n] > 0.0 )
      scores[n] *= 1.0-areas[n]/sum_areas;

  return scores;
}

/**
 * Computes line-polygon intersections weighted by area.
 *
 * @param poly    Polyline.
 * @param polys   Polygons to compare with.
 * @param areas   Polygons areas.
 * @return        Obtained intersection scores.
 */
std::vector<double> PageXML::computeBaselineIntersectionsWeightedByArea( OGRMultiLineStringPtr_ poly, std::vector<OGRMultiPolygonPtr_> polys, std::vector<double> areas ) {
  std::vector<double> scores;

  /// Check input ///
  if ( polys.size() != areas.size() ) {
    throw_runtime_error( "PageXML.computeBaselineIntersectionsWeightedByArea: size of polys and areas must be the same" );
    return scores;
  }

  /// Compute intersections ///
  double baseline_length = poly->multipolyline->get_Length();
  double sum_areas = 0.0;
  int isect_count = 0;
  for ( int n=0; n<(int)polys.size(); n++ ) {
    OGRMultiLineStringPtr_ isect = multiPolylineIntersection(poly,polys[n]);
    double isect_lgth = isect->multipolyline->get_Length();
    scores.push_back( isect_lgth <= 0.0 ? 0.0 : isect_lgth/baseline_length );
    if ( isect_lgth > 0.0 ) {
      sum_areas += areas[n];
      isect_count++;
    }
  }

  /// Return if fewer than 2 intersects ///
  if ( isect_count < 2 )
    return scores;

  /// Weight by areas ///
  for ( int n=0; n<(int)scores.size(); n++ )
    if ( scores[n] > 0.0 )
      scores[n] *= 1.0-areas[n]/sum_areas;

  return scores;
}

/**
 * Selects elements based on overlap to a polygon.
 *
 * @param points        Polygon for selection.
 * @param page          Page element for selection.
 * @param xpath         xpath for candidate elements for selection.
 * @param overlap_thr   Overlapping score threshold.
 * @param overlap_type  Type of overlap to use for selecting.
 * @return              Number of TextLines copied.
 */
std::vector<xmlNodePt> PageXML::selectByOverlap( std::vector<cv::Point2f> points, xmlNodePt page, const char* xpath, double overlap_thr, PAGEXML_OVERLAP overlap_type ) {
  std::vector<xmlNodePtr> selection;
  if( xpath[0] == '/' && xpath[1] == '/' ) {
    throw_runtime_error( "PageXML.selectByOverlap: xpath expected to be relative, got: %s", xpath );
    return selection;
  }

  /// OGR polygon(s) for selection ///
  std::vector<OGRMultiPolygonPtr_> polys;
  polys.push_back(pointsToOGRpolygon(points));
  if( getOGRpolygonArea(polys[0]) == 0.0 )
    return selection;
  if ( overlap_type == PAGEXML_OVERLAP_COORDS_IWA || overlap_type == PAGEXML_OVERLAP_BASELINE_IWA ) {
    double imW = getPageWidth(page);
    double imH = getPageHeight(page);
    std::vector<cv::Point2f> pagereg;
    pagereg.push_back( cv::Point2f(0,0) );
    pagereg.push_back( cv::Point2f(imW-1,0) );
    pagereg.push_back( cv::Point2f(imW-1,imH-1) );
    pagereg.push_back( cv::Point2f(0,imH-1) );
    polys.push_back(pointsToOGRpolygon(pagereg));
  }

  /// Get areas for overlap computation ///
  std::vector<double> areas = computeAreas(polys);

  /// Loop through elements ///
  std::vector<xmlNodePt> elems = select( xpath, page );
  for ( int n=0; n<(int)elems.size(); n++ ) {
    /// Compute overlap scores ///
    std::vector<double> overlap;
    switch ( overlap_type ) {
      case PAGEXML_OVERLAP_COORDS_IOU:
        overlap = computeIoUs( getOGRpolygon(elems[n]), polys );
        break;
      case PAGEXML_OVERLAP_COORDS_ISECT:
        overlap = computeIntersectionPercentages( getOGRpolygon(elems[n]), polys );
        break;
      case PAGEXML_OVERLAP_COORDS_IWA:
        overlap = computeCoordsIntersectionsWeightedByArea( getOGRpolygon(elems[n]), polys, areas );
        break;
      case PAGEXML_OVERLAP_BASELINE_IWA:
        overlap = computeBaselineIntersectionsWeightedByArea( getOGRpolyline(elems[n]), polys, areas );
        break;
      case PAGEXML_OVERLAP_COORDS_BASELINE_IWA:
        throw_runtime_error( "PageXML.selectByOverlap: PAGEXML_OVERLAP_COORDS_BASELINE_IWA not possible" );
        return selection;
    }

    /// Add if higher than threshold ///
    if ( overlap[0] > overlap_thr )
      selection.push_back(elems[n]);
  }

  return selection;
}

/**
 * Selects elements based on overlap to a polygon.
 *
 * @param points        Polygon for selection.
 * @param pagenum       Page number for selection.
 * @param xpath         xpath for candidate elements for selection.
 * @param overlap_thr   Overlapping score threshold.
 * @param overlap_type  Type of overlap to use for selecting.
 * @return              Number of TextLines copied.
 */
std::vector<xmlNodePt> PageXML::selectByOverlap( std::vector<cv::Point2f> points, int pagenum, const char* xpath, double overlap_thr, PAGEXML_OVERLAP overlap_type ) {
  return selectByOverlap( points, selectNth("//_:Page",pagenum), xpath, overlap_thr, overlap_type );
}

/**
 * Copies TextLines from one page xml to another assigning to regions based on overlap.
 *
 * @param pageFrom      PageXML from where to copy TextLines.
 * @param overlap_thr   Overlapping score threshold. If overlap below threshold, TextLine is copied to the page region.
 * @param overlap_type  Type of overlap to use for assigning lines to regions.
 * @param comb_alpha    Weight for overlap factors: alpha*bline+(1-alpha)*coords. Only for PAGEXML_OVERLAP_COORDS_BASELINE_IWA.
 * @return              Number of TextLines copied.
 */
int PageXML::copyTextLinesAssignByOverlap( PageXML& pageFrom, double overlap_thr, PAGEXML_OVERLAP overlap_type, double comb_alpha, bool verbose ) {
  xmlDocPtr docToPtr = getDocPtr();
  std::vector<xmlNodePt> pgsFrom = pageFrom.select("//_:Page");
  std::vector<xmlNodePt> pgsTo = select("//_:Page");

  if ( pgsFrom.size() != pgsTo.size() ) {
    throw_runtime_error( "PageXML.copyTextLinesAssignByOverlap: PageXML objects must have the same number of pages" );
    return 0;
  }

  int linesCopied = 0;

  /// Loop through pages ///
  for ( int npage = 0; npage<(int)pgsFrom.size(); npage++ ) {
    std::vector<xmlNodePt> linesFrom = pageFrom.select( ".//_:TextLine", pgsFrom[npage] );
    if( linesFrom.size() == 0 )
      continue;

    unsigned int toImW = getPageWidth(npage);
    unsigned int toImH = getPageHeight(npage);
    /// Check that image size is the same in both PageXMLs ///
    if ( toImW != pageFrom.getPageWidth(npage) ||
         toImH != pageFrom.getPageHeight(npage) ) {
      throw_runtime_error( "PageXML.copyTextLinesAssignByOverlap: for Page %d image size differs between input PageXMLs", npage );
      return 0;
    }

    /// Select page region or create one if it does not exist ///
    std::string xmax = std::to_string(toImW-1);
    std::string ymax = std::to_string(toImH-1);
    xmlNodePt pageRegTo = selectNth( std::string("_:TextRegion[_:Coords/@points='0,0 ")+xmax+",0 "+xmax+","+ymax+" 0,"+ymax+"']", 0, pgsTo[npage] );
    bool pageregadded = false;
    if ( ! pageRegTo ) {
      for ( int num=0; num<100; num++ ) {
        std::string pageregid = std::string("page")+std::to_string(npage+1)+(num?"_cnt"+std::to_string(num):"");
        if ( ! selectByID(pageregid.c_str()) ) {
          pageRegTo = addTextRegion( pgsTo[npage], pageregid.c_str(), NULL, true );
          setCoordsBBox( pageRegTo, 0, 0, toImW, toImH, nullptr, true );
          pageregadded = true;
          break;
        }
      }
      if ( ! pageregadded ) {
        throw_runtime_error( "PageXML.copyTextLinesAssignByOverlap: problems adding page region for Page %d", npage );
        return 0;
      }
    }

    /// Select relevant elements ///
    std::vector<xmlNodePt> regsTo = select( ".//_:TextRegion[_:Coords]", pgsTo[npage] );

    /// Get polygons of regions for IoU computation ///
    std::vector<OGRMultiPolygonPtr_> regs_poly = getOGRpolygons(regsTo);
    std::vector<double> reg_areas;
    if ( overlap_type == PAGEXML_OVERLAP_COORDS_IWA || overlap_type == PAGEXML_OVERLAP_BASELINE_IWA || overlap_type == PAGEXML_OVERLAP_COORDS_BASELINE_IWA )
      reg_areas = computeAreas(regs_poly);

    /// Loop through lines ///
    std::vector<xmlNodePt> linesAdded;
    for ( int n=0; n<(int)linesFrom.size(); n++ ) {
      if ( overlap_type != PAGEXML_OVERLAP_BASELINE_IWA && getPoints(linesFrom[n]).size() < 4 ) {
        if ( verbose )
          fprintf( stderr, "PageXML.copyTextLinesAssignByOverlap: warning: expected Coords to have at least 4 points, skipping copy of id=%s\n", getAttr(linesFrom[n],"id").c_str() );
        continue;
      }
      /// Compute overlap scores ///
      std::vector<double> overlap;
      std::vector<double> overlap2;
      switch ( overlap_type ) {
        case PAGEXML_OVERLAP_COORDS_IOU:
          overlap = computeIoUs( pageFrom.getOGRpolygon(linesFrom[n]), regs_poly );
          break;
        case PAGEXML_OVERLAP_COORDS_ISECT:
          overlap = computeIntersectionPercentages( pageFrom.getOGRpolygon(linesFrom[n]), regs_poly );
          break;
        case PAGEXML_OVERLAP_COORDS_IWA:
          overlap = computeCoordsIntersectionsWeightedByArea( pageFrom.getOGRpolygon(linesFrom[n]), regs_poly, reg_areas );
          break;
        case PAGEXML_OVERLAP_BASELINE_IWA:
          overlap = computeBaselineIntersectionsWeightedByArea( pageFrom.getOGRpolyline(linesFrom[n]), regs_poly, reg_areas );
          break;
        case PAGEXML_OVERLAP_COORDS_BASELINE_IWA:
          overlap = computeBaselineIntersectionsWeightedByArea( pageFrom.getOGRpolyline(linesFrom[n]), regs_poly, reg_areas );
          overlap2 = computeCoordsIntersectionsWeightedByArea( pageFrom.getOGRpolygon(linesFrom[n]), regs_poly, reg_areas );
          for ( int m=0; m<(int)overlap.size(); m++ )
            overlap[m] = comb_alpha*overlap[m]+(1-comb_alpha)*overlap2[m];
          break;
      }

      /// Check if TextLine should be copied ///
      int max_idx = std::distance(overlap.begin(), std::max_element(overlap.begin(), overlap.end()));
      if ( overlap[max_idx] == 0.0 ) {
        if ( verbose )
          fprintf( stderr, "PageXML.copyTextLinesAssignByOverlap: warning: TextLine does not overlap with any region, skipping copy of id=%s\n", getAttr(linesFrom[n],"id").c_str() );
        continue;
      }
      /// Clone line and add it to the destination region node ///
      std::string lid = getUniqueID( "cp", (std::string("_")+getAttr( linesFrom[n], "id" )).c_str() );
      xmlNodePt lineclone = NULL;
      if ( 0 != xmlDOMWrapCloneNode( NULL, NULL, linesFrom[n], &lineclone, docToPtr, NULL, 1, 0 ) ||
          lineclone == NULL ) {
        throw_runtime_error( "PageXML.copyTextLinesAssignByOverlap: problems cloning TextLine node" );
        return 0;
      }
      setAttr(lineclone, "id", lid.c_str());
      relabelChildIDs(lineclone);
      if ( overlap[max_idx] < overlap_thr ) {
        xmlAddChild(pageRegTo,lineclone);
        if ( verbose )
          fprintf( stderr, "PageXML.copyTextLinesAssignByOverlap: TextLine %s copied to background TextRegion %s since overlap below threshold (%g < %g)\n", getAttr(linesFrom[n],"id").c_str(), getAttr(pageRegTo,"id").c_str(), overlap[max_idx], overlap_thr );
      }
      else {
        xmlAddChild(regsTo[max_idx],lineclone);
        if ( verbose )
          fprintf( stderr, "PageXML.copyTextLinesAssignByOverlap: TextLine %s copied to TextRegion %s, overlap=%g\n", getAttr(linesFrom[n],"id").c_str(), getAttr(regsTo[max_idx],"id").c_str(), overlap[max_idx] );
      }
    }

    /// Remove added page region if no TextLine was added to it ///
    if ( pageregadded && count("_:TextLine",pageRegTo) == 0 )
      rmElem(pageRegTo);

    linesCopied += linesFrom.size();
  }

  return linesCopied;
}

#endif

/**
 * Determines groups of left-right text elem continuations (requires single segment polystripe).
 *
 * @param elems                 Text elements to test for continuation: TextLines, Words, Glyphs or TextRegions.
 * @param _group_order          Join groups line indices (output).
 * @param _group_score          Join group scores (output).
 * @param max_angle_diff        Maximum baseline angle difference for joining.
 * @param max_horiz_iou         Maximum horizontal IoU for joining.
 * @param min_prolong_fact      Minimum prolongation factor for joining.
 * @param prolong_alpha         Weight for prolongation factors: alpha*bline+(1-alpha)*coords.
 * @param fake_baseline         Use bottom line of Coords rectangle as the baseline.
 * @param recurse_factor        Multiplication factor for continuation criteria on each recursion.
 * @return                      Number of join groups, elements per group in order and group scores.
 */
int PageXML::getLeftRightTextContinuationGroups( std::vector<xmlNodePt> elems, std::vector<std::vector<int> >& _group_order, std::vector<double>& _group_score, double max_angle_diff, double max_horiz_iou, double min_prolong_fact, double prolong_alpha, bool fake_baseline, double recurse_factor ) {
  /// Get points and compute baseline angles and lengths ///
  std::vector< std::vector<cv::Point2f> > coords;
  std::vector< std::vector<cv::Point2f> > baseline;
  std::vector<double> angle;
  std::vector<double> length;
  int num_elems = elems.size();
  for ( int n=0; n<num_elems; n++ ) {
    coords.push_back( getPoints(elems[n]) );
    if ( fake_baseline ) {
      if ( coords[n].size() != 4 ) {
        throw_runtime_error( "PageXML.getLeftRightTextContinuationGroups: fake_baseline requires Coords to have exactly 4 points (id=%s)", getAttr(elems[n],"id").c_str() );
        return -1;
      }
      std::vector<cv::Point2f> baseline_n;
      baseline_n.push_back( cv::Point2f(coords[n][3]) );
      baseline_n.push_back( cv::Point2f(coords[n][2]) );
      baseline.push_back(baseline_n);
    }
    else
      baseline.push_back( getPoints(elems[n],"_:Baseline") );
    angle.push_back(getPolylineOrientation(baseline[n]));
    length.push_back(getPolylineLength(baseline[n]));

    if ( ! ( nodeIs(elems[n],"TextLine") || nodeIs(elems[n],"Word") || nodeIs(elems[n],"Glyph") || nodeIs(elems[n],"TextRegion") ) ) {
      throw_runtime_error( "PageXML.getLeftRightTextContinuationGroups: input nodes need to be TextLines or Words or Glyphs or TextRegions" );
      return -1;
    }
    // @todo Check for single segment polystripe 
    if ( baseline[n].size() != 2 || coords[n].size() != 4 ) {
      throw_runtime_error( "PageXML.getLeftRightTextContinuationGroups: Baselines and Coords are required to have exactly 2 and 4 points respectively. For horizontal left-to-right text give fake_baseline=true. (id=%s, #baseline=%d, #coords=%d)", getAttr(elems[n],"id").c_str(), (int)baseline[n].size(), (int)coords[n].size() );
      return -1;
    }
  }

  std::vector<std::unordered_set<int> > elem_groups;
  std::vector<std::vector<int> > elem_group_order;
  std::vector<std::vector<double> > elem_group_scores;
  std::vector<double> elem_group_direct;
  int group_idx[num_elems];
  for ( int n=0; n<num_elems; n++ )
    group_idx[n] = -1;

  /// Loop through all directed pairs of text elems ///
  for ( int n=0; n<num_elems; n++ )
    for ( int m=0; m<num_elems; m++ )
      if ( n != m ) {
        /// Check that baseline angle difference is small ///
        double angle_diff = fabs(angleDiff(angle[n],angle[m]));
        if ( angle_diff > max_angle_diff )
          continue;

        /// Project baseline limits onto the local horizontal axis ///
        cv::Point2f dir_n = baseline[n][1]-baseline[n][0];
        cv::Point2f dir_m = baseline[m][1]-baseline[m][0];
        dir_n *= 1.0/cv::norm(dir_n);
        dir_m *= 1.0/cv::norm(dir_m);
        cv::Point2f horiz = (length[n]*dir_n+length[m]*dir_m)*(1.0/(length[n]+length[m]));

        std::vector<double> horiz_n = project_2d_to_1d(baseline[n],horiz);
        std::vector<double> horiz_m = project_2d_to_1d(baseline[m],horiz);

        /// Check that elem n starts before elem m ///
        double direct = horiz_n[0] < horiz_n[1] ? 1.0 : -1.0;
        if ( direct*horiz_m[0] < direct*horiz_n[0] )
          continue;
        
        /// Check that horizontal IoU is small //
        double iou = IoU_1d(horiz_n[0],horiz_n[1],horiz_m[0],horiz_m[1]);
        if ( iou > max_horiz_iou )
          continue;

        /// Compute coords endpoint-startpoint intersection factors ///
        /// (both ways, intersection length of prolongated elem 1 and elem 2 divided by height of elem 2) ///
        /// @todo Possible improvement: coords_fact_xx = isect_1d / min(norm_n,norm_m)
        std::vector<cv::Point2f> pts_n = coords[n];
        std::vector<cv::Point2f> pts_m = coords[m];
        std::vector<cv::Point2f> isect_nm(2);
        std::vector<cv::Point2f> isect_mn(2);

        if ( ! intersection( pts_n[0], pts_n[1], pts_m[0], pts_m[3], isect_nm[0] ) ) continue;
        if ( ! intersection( pts_n[3], pts_n[2], pts_m[0], pts_m[3], isect_nm[1] ) ) continue;
        if ( ! intersection( pts_m[0], pts_m[1], pts_n[1], pts_n[2], isect_mn[0] ) ) continue;
        if ( ! intersection( pts_m[3], pts_m[2], pts_n[1], pts_n[2], isect_mn[1] ) ) continue;

        std::vector<double> vert_nm_n = project_2d_to_1d(isect_nm, pts_m[3]-pts_m[0]);
        std::vector<double> vert_nm_m = project_2d_to_1d(pts_m, pts_m[3]-pts_m[0]);
        std::vector<double> vert_mn_n = project_2d_to_1d(pts_n, pts_n[2]-pts_n[1]);
        std::vector<double> vert_mn_m = project_2d_to_1d(isect_mn, pts_n[2]-pts_n[1]);
        double coords_fact_nm = intersection_1d(vert_nm_n[0],vert_nm_n[1],vert_nm_m[0],vert_nm_m[3])/cv::norm(pts_m[3]-pts_m[0]);
        double coords_fact_mn = intersection_1d(vert_mn_n[1],vert_mn_n[2],vert_mn_m[0],vert_mn_m[1])/cv::norm(pts_n[2]-pts_n[1]);

        /// Compute baseline alignment factors ///
        /// (both ways, one minus distance between prolongated baseline 1 and baseline 2 divided by height of elem 2 ) ///
        /// @todo Possible improvement: max( 0, 1-norm(isec_xx-bline_x)/max(norm_n,norm_m) )
        std::vector<cv::Point2f> bline_n = baseline[n];
        std::vector<cv::Point2f> bline_m = baseline[m];
        if ( ! intersection( bline_n[0], bline_n[1], pts_m[0], pts_m[3], isect_nm[0] ) ) continue;
        if ( ! intersection( bline_m[1], bline_m[0], pts_n[1], pts_n[2], isect_mn[0] ) ) continue;
        double bline_fact_nm = std::max(0.0, 1.0-cv::norm(isect_nm[0]-bline_m[0])/cv::norm(pts_m[3]-pts_m[0]));
        double bline_fact_mn = std::max(0.0, 1.0-cv::norm(isect_mn[0]-bline_n[1])/cv::norm(pts_n[2]-pts_n[1]));

        /// Overall alignment factor ///
        double coords_fact = 0.5*(coords_fact_nm+coords_fact_mn);
        double bline_fact = 0.5*(bline_fact_nm+bline_fact_mn);

        double prolong_fact = prolong_alpha*bline_fact + (1.0-prolong_alpha)*coords_fact;
        if ( prolong_fact < min_prolong_fact )
          continue;

        /// Add text elem to a group (new or existing) ///
        int k = (int)elem_groups.size();
        std::unordered_set<int> elem_group;
        std::vector<int> group_order;
        std::vector<double> group_scores;
        std::vector<double> group_direct;

        /// Check if should be part of existing group ///
        if ( group_idx[n] != -1 || group_idx[m] != -1 ) {

          /// Unique existing group ///
          if ( group_idx[n] == -1 || group_idx[m] == -1 || group_idx[n] == group_idx[m] )
            k = std::max(group_idx[n], group_idx[m]);

          /// Two existing groups, thus merge groups ///
          else {
            k = std::min(group_idx[n], group_idx[m]);
            int kk = std::max(group_idx[n], group_idx[m]);
            elem_groups[k].insert(elem_groups[kk].begin(), elem_groups[kk].end());
            elem_group_order[k].insert(elem_group_order[k].end(), elem_group_order[kk].begin(), elem_group_order[kk].end());
            elem_group_scores[k].insert(elem_group_scores[k].end(), elem_group_scores[kk].begin(), elem_group_scores[kk].end());
            for ( const auto& e: elem_groups[kk] )
              group_idx[e] = k;
            for ( int j=(int)elem_groups.size()-1; j>kk; j-- )
              for ( const auto& e: elem_groups[j] )
                group_idx[e] = j-1;
            elem_groups.erase(elem_groups.begin() + kk);
            elem_group_order.erase(elem_group_order.begin() + kk);
            elem_group_scores.erase(elem_group_scores.begin() + kk);
          }

          elem_group = elem_groups[k];
          group_order = elem_group_order[k];
          group_scores = elem_group_scores[k];
        }
        group_idx[n] = group_idx[m] = k;

        /// Update groups ///
        elem_group.insert(n);
        elem_group.insert(m);
        group_order.push_back(n);
        group_order.push_back(m);
        group_scores.push_back(prolong_fact);
        if ( k < (int)elem_groups.size() ) {
          elem_groups[k] = elem_group;
          elem_group_order[k] = group_order;
          elem_group_scores[k] = group_scores;
          elem_group_direct[k] = direct;
        }
        else {
          elem_groups.push_back(elem_group);
          elem_group_order.push_back(group_order);
          elem_group_scores.push_back(group_scores);
          elem_group_direct.push_back(direct);
        }
      }

  /// Adjust text elem order for groups with more than two text elems ///
  std::vector<std::vector<int> > extra_group_order;
  std::vector<double> extra_group_score;

  for ( int k=0; k<(int)elem_groups.size(); k++ )
    if ( elem_group_scores[k].size() > 1 ) {
      int num_group = elem_groups[k].size();

      /// Get horizontal direction ///
      std::vector<int> idx;
      double totlength = 0.0;
      cv::Point2f horiz(0.0,0.0);
      for ( auto it = elem_groups[k].begin(); it != elem_groups[k].end(); it++ ) {
        idx.push_back(*it);
        totlength += length[*it];
        cv::Point2f tmp = baseline[*it][1]-baseline[*it][0];
        horiz += (length[*it]/cv::norm(tmp))*tmp;
      }
      horiz *= 1.0/totlength;

      /// Check if there is high horizontal overlaps within group ///
      std::vector<std::vector<double> > blines;
      for ( int j=0; j<(int)idx.size(); j++ )
        blines.push_back( project_2d_to_1d(baseline[idx[j]],horiz) );

      // @todo Recurse if x-axis iou too low?
      bool recurse = false;
      if ( recurse_factor )
        for ( int j=0; j<(int)blines.size(); j++ )
          for ( int i=j+1; i<(int)blines.size(); i++ ) {
            double iou = IoU_1d(blines[j][0],blines[j][1],blines[i][0],blines[i][1]);
            if ( iou > max_horiz_iou ) {
              recurse = true;
              goto afterRecourseLoop;
            }
          }
      afterRecourseLoop:

      /// If high overlap recurse with stricter criterion ///
      if ( recurse ) {
        std::vector<xmlNodePtr> recurse_elems;
        std::vector<std::vector<int> > recurse_group_order;
        std::vector<double> recurse_group_score;

        for ( int j=0; j<(int)idx.size(); j++ )
          recurse_elems.push_back(elems[idx[j]]);

        getLeftRightTextContinuationGroups( recurse_elems, recurse_group_order, recurse_group_score, max_angle_diff*recurse_factor, max_horiz_iou*recurse_factor, min_prolong_fact/recurse_factor, prolong_alpha, fake_baseline );

        if ( recurse_group_order.size() == 0 ) {
          elem_groups.erase(elem_groups.begin()+k);
          elem_group_order.erase(elem_group_order.begin()+k);
          elem_group_scores.erase(elem_group_scores.begin()+k);
          elem_group_direct.erase(elem_group_direct.begin()+k);
          k--;
        }
        else {
          for ( int j=0; j<(int)recurse_group_order.size(); j++ )
            for ( int i=0; i<(int)recurse_group_order[j].size(); i++ )
              recurse_group_order[j][i] = idx[recurse_group_order[j][i]];
          elem_group_order[k] = recurse_group_order[0];
          elem_group_scores[k].clear();
          elem_group_scores[k].push_back(recurse_group_score[0]);
          for ( int j=1; j<(int)recurse_group_order.size(); j++ ) {
            extra_group_order.push_back(recurse_group_order[j]);
            extra_group_score.push_back(recurse_group_score[j]);
          }
        }

        continue;
      }

      /// Project baseline centers onto the local horizontal axis ///
      std::vector<cv::Point2f> cent;
      for ( int j=0; j<(int)idx.size(); j++ )
        cent.push_back(0.5*(baseline[idx[j]][0]+baseline[idx[j]][1]));
      std::vector<double> hpos = project_2d_to_1d(cent,horiz);

      /// Sort text elems by horizontal center projections ///
      int flags = elem_group_direct[k] == 1.0 ? CV_SORT_ASCENDING : CV_SORT_DESCENDING;
      std::vector<int> sidx(num_group);
      cv::sortIdx( hpos, sidx, flags );
      std::vector<int> group_order;
      for ( int j=0; j<(int)sidx.size(); j++ )
        group_order.push_back(idx[sidx[j]]);

      /// Score as average of scores ///
      double score = 0.0;
      for ( int j=0; j<(int)elem_group_scores[k].size(); j++ )
        score += elem_group_scores[k][j];
      std::vector<double> group_scores;
      group_scores.push_back(score/elem_group_scores[k].size());

      elem_group_order[k] = group_order;
      elem_group_scores[k] = group_scores;
    }

  std::vector<double> elem_group_score;
  for ( int k=0; k<(int)elem_group_scores.size(); k++ )
    elem_group_score.push_back(elem_group_scores[k][0]);

  /// Add recursed extra groups ///
  if ( extra_group_order.size() > 0 ) {
    elem_group_order.insert(elem_group_order.end(), extra_group_order.begin(), extra_group_order.end());
    elem_group_score.insert(elem_group_score.end(), extra_group_score.begin(), extra_group_score.end());
  }

  /// Sort groups based on first element original order ///
  if ( elem_group_order.size() > 0 ) {
    std::vector<int> sval(elem_group_order.size());
    std::vector<int> sidx(elem_group_order.size());
    for ( int n=0; n<(int)elem_group_order.size(); n++ )
      sval[n] = elem_group_order[n][0];
    cv::sortIdx( sval, sidx, CV_SORT_ASCENDING );
    std::vector<std::vector<int> > sorted_group_order;
    std::vector<double> sorted_group_score;
    for ( int n=0; n<(int)sidx.size(); n++ ) {
      sorted_group_order.push_back( elem_group_order[sidx[n]] );
      sorted_group_score.push_back( elem_group_score[sidx[n]] );
    }
    elem_group_order = sorted_group_order;
    elem_group_score = sorted_group_score;
  }

  _group_order = elem_group_order;
  _group_score = elem_group_score;

  return (int)elem_group_order.size();
}

/**
 * Gets the reading order for a set of text elems (requires single segment polystripe).
 *
 * @param elems                 Elements to process: TextLines, Words, Glyphs or TextRegions.
 * @param max_angle_diff        Maximum baseline angle difference for joining.
 * @param max_horiz_iou         Maximum horizontal IoU for joining.
 * @param min_prolong_fact      Minimum prolongation factor for joining.
 * @param prolong_alpha         Weight for prolongation factors: alpha*bline+(1-alpha)*coords.
 * @param fake_baseline         Use bottom line of Coords rectangle as the baseline.
 * @param recurse_factor        Multiplication factor for continuation criteria on each recursion.
 * @return                      Pair of reading order indices and subgroup lengths.
 */
std::pair<std::vector<int>, std::vector<int> > PageXML::getLeftRightTopBottomReadingOrder( std::vector<xmlNodePt> elems, double max_angle_diff, double max_horiz_iou, double min_prolong_fact, double prolong_alpha, bool fake_baseline, double recurse_factor ) {
  std::vector<int> reading_order;
  std::vector<int> subgroup_lengths;
  if ( elems.size() == 0 )
    return std::pair<std::vector<int>, std::vector<int> >(reading_order, subgroup_lengths);

  /// Get text elem join groups ///
  std::vector<std::vector<int> > elem_groups;
  std::vector<double> join_group_score;
  int num_joins = getLeftRightTextContinuationGroups( elems, elem_groups, join_group_score, max_angle_diff, max_horiz_iou, min_prolong_fact, prolong_alpha, fake_baseline, recurse_factor );

  /// Get points and compute baseline angles and lengths ///
  std::vector<std::vector<cv::Point2f> > baseline;
  std::vector<double> length;
  for ( int n=0; n<(int)elems.size(); n++ ) {
    if ( fake_baseline ) {
      std::vector<cv::Point2f> coords = getPoints(elems[n]);
      std::vector<cv::Point2f> baseline_n;
      baseline_n.push_back(coords[3]);
      baseline_n.push_back(coords[2]);
      baseline.push_back(baseline_n);
    }
    else
      baseline.push_back( getPoints(elems[n],"_:Baseline") );
    length.push_back( getPolylineLength(baseline[n]) );
  }

  /// Get horizontal direction ///
  double totlength = 0.0;
  cv::Point2f horiz(0.0,0.0);
  for ( int n=0; n<(int)elems.size(); n++ ) {
    totlength += length[n];
    cv::Point2f tmp = baseline[n][1]-baseline[n][0];
    horiz += (length[n]/cv::norm(tmp))*tmp;
  }
  horiz *= 1.0/totlength;

  /// Add text elems not in join groups ///
  for ( int n=0; n<(int)elems.size(); n++ ) {
    bool in_join_group = false;
    for ( int i=0; i<num_joins; i++ )
      for ( int j=0; j<(int)elem_groups[i].size(); j++ )
        if ( n == elem_groups[i][j] ) {
          in_join_group = true;
          i = num_joins;
          break;
        }
    if ( ! in_join_group ) {
      std::vector<int> new_elem;
      new_elem.push_back(n);
      elem_groups.push_back(new_elem);
    }
  }

  /// Get vertical group center projections ///
  std::vector<cv::Point2f> cent;
  for ( int i=0; i<(int)elem_groups.size(); i++ ) {
    double totlength = 0.0;
    cv::Point2f gcent(0.0,0.0);
    for ( int j=0; j<(int)elem_groups[i].size(); j++ ) {
      int n = elem_groups[i][j];
      totlength += length[n];
      gcent += length[n]*0.5*(baseline[n][0]+baseline[n][1]);
    }
    gcent *= 1.0/totlength;
    cent.push_back(gcent);
  }
  cv::Point2f vert(-horiz.y,horiz.x);
  std::vector<double> vpos = project_2d_to_1d(cent,vert);

  /// Sort groups by vertical center projections ///
  std::vector<int> sidx(vpos.size());
  cv::sortIdx( vpos, sidx, CV_SORT_ASCENDING );

  /// Populate reading order vector ///
  for ( int ii=0; ii<(int)sidx.size(); ii++ ) {
    int i = sidx[ii];
    subgroup_lengths.push_back((int)elem_groups[i].size());
    for ( int j=0; j<(int)elem_groups[i].size(); j++ )
      reading_order.push_back(elem_groups[i][j]);
  }

  if( reading_order.size() != elems.size() )
    throw_runtime_error( "PageXML.getLeftRightTopBottomReadingOrder: implementation bug, obtained reading order size different to number of input elements: %d vs. %d", (int)reading_order.size(), (int)elems.size() );

  return std::pair<std::vector<int>, std::vector<int> >(reading_order, subgroup_lengths);
}

/**
 * Returns the XML document pointer.
 */
xmlDocPtr PageXML::getDocPtr() {
  return xml;
}
