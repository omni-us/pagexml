/**
 * TextFeatExtractor class
 *
 * @version $Version: 2017.06.09$
 * @copyright Copyright (c) 2016-present, Mauricio Villegas <mauricio_ville@yahoo.com>
 * @license MIT License
 */

#include "TextFeatExtractor.h"

#include <chrono>

#ifndef FAILURE
#define FAILURE 1
#endif
#ifndef SUCCESS
#define SUCCESS 0
#endif

using namespace std;
using namespace std::chrono;
using namespace cv;
using namespace Magick;
using namespace libconfig;
using namespace H5;

const char* TextFeatExtractor::featTypes[] = { "dotm", "raw" };
const char* TextFeatExtractor::formatNames[] = { "ascii", "htk", "img" };
const char* TextFeatExtractor::settingNames[] = {
  "type",
  "format",
  "verbose",
  "procimgs",
  "stretch",
  "stretch_satu",
  "enh",
  "enh_win",
  "enh_prm",
  "enh_prm_rand",
  "enh_slp",
  "deslope",
  "deslant",
  "normxheight",
  "normheight",
  "momentnorm",
  "fpgram",
  "fcontour",
  "fcontour_dilate",
  "padding",
  "slide_shift",
  "slide_span",
  "sample_width",
  "sample_height",
  "projfile"
};

const Color colorWhite("white");
const Color colorBlack("black");

/////////////////////
/// Class version ///
/////////////////////

static char class_version[] = "Version: 2017.06.09";

/**
 * Returns the class version.
 */
char* TextFeatExtractor::version() {
  return class_version+9;
}

////////////////////
/// Constructors ///
////////////////////

/**
 * TextFeatExtractor constructor that receives a libconfig Config object.
 *
 * @param config  A libconfig Config object.
 */
TextFeatExtractor::TextFeatExtractor( const Config& config ) {
  loadConf(config);
}

/**
 * TextFeatExtractor constructor that receives a configuration file name.
 *
 * @param cfgfile  Configuration file to use.
 */
TextFeatExtractor::TextFeatExtractor( const char* cfgfile ) {
  if( cfgfile != NULL ) {
    Config config;
    config.readFile(cfgfile);
    loadConf(config);
  }
}

/////////////////////
/// Configuration ///
/////////////////////

/**
 * Gets a config setting as a double even if it is an int.
 */
inline static double settingNumber( const Setting& setting ) {
  return setting.getType() == Setting::Type::TypeInt ?
    (double)((int)setting) :
    (double)setting ;
}

/**
 * Gets a config setting as a bool even if it is a yes/no or true/false string.
 */
inline static bool settingBoolean( const Setting& setting ) {
  if( setting.getType() == Setting::Type::TypeString ) {
    if( !strcasecmp("true",setting.c_str()) || !strcasecmp("yes",setting.c_str()) )
      return true;
    else if( !strcasecmp("false",setting.c_str()) || !strcasecmp("no",setting.c_str()) )
      return false;
  }
  return (bool)setting;
}

/**
 * Gets the enum value for a feature type, or -1 if unknown.
 *
 * @param format  String containing feature type name.
 * @return        Enum feature type value.
 */
inline static int parseFeatType( const char* featype ) {
  int featypes = sizeof(TextFeatExtractor::featTypes) / sizeof(TextFeatExtractor::featTypes[0]);
  for( int n=0; n<featypes; n++ )
    if( ! strcmp(TextFeatExtractor::featTypes[n],featype) )
      return n;
  return -1;
}

/**
 * Gets the enum value for an output format name, or -1 if unknown.
 *
 * @param format  String containing format name.
 * @return        Enum format value.
 */
inline static int parseFeatFormat( const char* format ) {
  int formats = sizeof(TextFeatExtractor::formatNames) / sizeof(TextFeatExtractor::formatNames[0]);
  for( int n=0; n<formats; n++ )
    if( ! strcmp(TextFeatExtractor::formatNames[n],format) )
      return n;
  return -1;
}

/**
 * Gets the enum value for a configuration setting name, or -1 if unknown.
 *
 * @param format  String containing setting name.
 * @return        Enum format value.
 */
inline static int parseFeatSetting( const char* setting ) {
  int settings = sizeof(TextFeatExtractor::settingNames) / sizeof(TextFeatExtractor::settingNames[0]);
  for( int n=0; n<settings; n++ )
    if( ! strcmp(TextFeatExtractor::settingNames[n],setting) )
      return n;
  return -1;
}

/**
 * Applies configuration options to the TextFeatExtractor instance.
 *
 * @param config  A libconfig Config object.
 */
void TextFeatExtractor::loadConf( const Config& config ) {
  if( ! config.exists("TextFeatExtractor") )
    return;

  const Setting& featcfg = config.getRoot()["TextFeatExtractor"];

  int numsettings = featcfg.getLength();
  for( int i = 0; i < numsettings; i++ ) {
    const Setting& setting = featcfg[i];
    //printf("TextFeatExtractor: setting=%s enum=%d\n",setting.getName(),parseFeatSetting(setting.getName()));
    switch( parseFeatSetting(setting.getName()) ) {
      case TEXTFEAT_SETTING_TYPE:
        featype = parseFeatType(setting.c_str());
        if( featype < 0 )
          throw invalid_argument( string("TextFeatExtractor: unknown features type: ") + setting.c_str() );
        break;
      case TEXTFEAT_SETTING_FORMAT:
        format = parseFeatFormat(setting.c_str());
        if( format < 0 )
          throw invalid_argument( string("TextFeatExtractor: unknown output features format: ") + setting.c_str() );
        break;
      case TEXTFEAT_SETTING_VERBOSE:
        verbose = settingBoolean(setting);
        break;
      case TEXTFEAT_SETTING_PROCIMGS:
        procimgs = settingBoolean(setting);
        break;
      case TEXTFEAT_SETTING_STRETCH:
        stretch = settingBoolean(setting);
        break;
      case TEXTFEAT_SETTING_STRETCH_SATU:
        stretch_satu = settingNumber(setting);
        break;
      case TEXTFEAT_SETTING_ENH:
        enh = settingNumber(setting);
        break;
      case TEXTFEAT_SETTING_ENH_WIN:
        enh_win = (int)setting;
        if( enh_win <= 0 )
          throw invalid_argument( "TextFeatExtractor: enhancement window width must be > 0" );
        break;
      case TEXTFEAT_SETTING_ENH_PRM:
        if( setting.getType() == Setting::Type::TypeArray || setting.getLength() == 3 ) {
          enh3_prm0 = settingNumber(setting[0]);
          enh_prm = settingNumber(setting[1]);
          enh3_prm2 = settingNumber(setting[2]);
        }
        else if( setting.getType() == Setting::Type::TypeFloat || setting.getType() == Setting::Type::TypeInt ) {
          enh_prm = settingNumber(setting);
          enh3_prm0 = enh3_prm2 = 0.0;
        }
        else
          throw invalid_argument( "TextFeatExtractor: enhancement parameter must be a single value or an array of 3 values" );
        if( enh3_prm0 < 0.0 || enh_prm < 0.0 || enh3_prm2 < 0.0 )
          throw invalid_argument( "TextFeatExtractor: enhancement parameter must be >= 0.0" );
        break;
      case TEXTFEAT_SETTING_ENH_PRM_RAND:
        if( setting.getType() != Setting::Type::TypeArray || setting.getLength() != 2 )
          throw invalid_argument( "TextFeatExtractor: enhancement parameter random must be an array with 2 numbers" );
        enh_prm_randmin = settingNumber(setting[0]);
        enh_prm_randmax = settingNumber(setting[1]);
        if( enh_prm_randmin < 0.0 || enh_prm_randmax < 0.0 || enh_prm_randmin >= enh_prm_randmax )
          throw invalid_argument( "TextFeatExtractor: enhancement parameter random to be 2 increasing values >= 0.0" );
        break;
      case TEXTFEAT_SETTING_ENH_SLP:
        enh_slp = settingNumber(setting);
        if( enh_slp < 0.0 )
          throw invalid_argument( "TextFeatExtractor: enhancement slope must be >= 0.0" );
        break;
      case TEXTFEAT_SETTING_DESLOPE:
        deslope = settingBoolean(setting);
        break;
      case TEXTFEAT_SETTING_DESLANT:
        deslant = settingBoolean(setting);
        break;
      case TEXTFEAT_SETTING_NORMXHEIGHT:
        normxheight = (int)setting;
        break;
      case TEXTFEAT_SETTING_NORMHEIGHT:
        normheight = (int)setting;
        break;
      case TEXTFEAT_SETTING_MOMENTNORM:
        momentnorm = settingBoolean(setting);
        break;
      case TEXTFEAT_SETTING_FPGRAM:
        compute_fpgram = settingBoolean(setting);
        break;
      case TEXTFEAT_SETTING_FCONTOUR:
        compute_fcontour = settingBoolean(setting);
        break;
      case TEXTFEAT_SETTING_FCONTOUR_DILATE:
        fcontour_dilate = settingNumber(setting);
        break;
      case TEXTFEAT_SETTING_PADDING:
        padding = (int)settingNumber(setting);
        break;
      case TEXTFEAT_SETTING_SLIDE_SHIFT:
        slide_shift = settingNumber(setting);
        if( slide_shift <= 0.0 )
          throw invalid_argument( "TextFeatExtractor: slide_shift must be > 0.0" );
        break;
      case TEXTFEAT_SETTING_SLIDE_SPAN:
        slide_span = settingNumber(setting);
        if( slide_span < 1.0 )
          throw invalid_argument( "TextFeatExtractor: slide_span must be >= 1.0" );
        break;
      case TEXTFEAT_SETTING_SAMPLE_WIDTH:
        sample_width = (int)setting;
        if( sample_width < 1 )
          throw invalid_argument( "TextFeatExtractor: sample_width must be >= 1" );
        break;
      case TEXTFEAT_SETTING_SAMPLE_HEIGHT:
        sample_height = (int)setting;
        if( sample_height < 1 )
          throw invalid_argument( "TextFeatExtractor: sample_height must be >= 1" );
        break;
      case TEXTFEAT_SETTING_PROJFILE:
        //if( setting.c_str() != NULL && setting.c_str() != '\0' )
          loadProjection( setting.c_str() );
        break;
      default:
        throw invalid_argument( string("TextFeatExtractor: unexpected configuration property: ") + setting.getName() );
    } // switch( parseFeatSetting(setting.getName()) ) {
  }
}

/**
 * Prints the current configuration.
 *
 * @param file  File to print to.
 */
void TextFeatExtractor::printConf( FILE* file ) {
  fprintf( file, "TextFeatExtractor: {\n" );
  fprintf( file, "  type = \"%s\";\n", featTypes[featype] );
  fprintf( file, "  format = \"%s\";\n", formatNames[format] );
  fprintf( file, "  stretch = %s;\n", stretch ? "true" : "false" );
  //fprintf( file, "  stretch_satu = %g;\n", stretch_satu );
  fprintf( file, "  enh = %g;\n", enh );
  fprintf( file, "  enh_win = %d;\n", enh_win );
  fprintf( file, "  enh_prm = %g;\n", enh_prm );
  fprintf( file, "  enh_prm_rand = [ %g, %g ];\n", enh_prm_randmin, enh_prm_randmax );
  fprintf( file, "  enh_slp = %g;\n", enh_slp );
  fprintf( file, "  deslope = %s;\n", deslope ? "true" : "false" );
  fprintf( file, "  deslant = %s;\n", deslant ? "true" : "false" );
  fprintf( file, "  normxheight = %d;\n", normxheight );
  fprintf( file, "  normheight = %d;\n", normheight );
  fprintf( file, "  momentnorm = %s;\n", momentnorm ? "true" : "false" );
  fprintf( file, "  fpgram = %s;\n", compute_fpgram ? "true" : "false" );
  fprintf( file, "  fcontour = %s;\n", compute_fcontour ? "true" : "false" );
  fprintf( file, "  fcontour_dilate = %g;\n", fcontour_dilate );
  fprintf( file, "  padding = %d;\n", padding );
  fprintf( file, "  slide_shift = %g;\n", slide_shift );
  fprintf( file, "  slide_span = %g;\n", slide_span );
  fprintf( file, "  sample_width = %d;\n", sample_width );
  fprintf( file, "  sample_height = %d;\n", sample_height );
  if( projbase.rows > 0 )
    fprintf( file, "  projfile = \"%s\";\n", projfile.c_str() );
  fprintf( file, "}\n" );
}


///////////////
/// Loaders ///
///////////////

/**
 * Loads the projecton matrix from an hdf5 file.
 *
 * @param projfile  File from which to read the projection.
 */
void TextFeatExtractor::loadProjection( const char* projfile ) {
  /// Open HDF5 file handle, read only ///
  H5File fp(projfile,H5F_ACC_RDONLY);

  /// Access projection base ///
  DataSet dset = fp.openDataSet("/B/value");
  DataSpace dspace = dset.getSpace();
  H5T_class_t type_class = dset.getTypeClass();
  hsize_t dims[2];
  hsize_t rank = dspace.getSimpleExtentDims(dims, NULL);
  if( type_class != H5T_FLOAT || rank != 2 )
    throw invalid_argument( "TextFeatExtractor: expected projection base (B) to be a matrix of type H5T_IEEE_F64LE" );

  /// Create opencv matrix with projection matrix ///
  float Bmat[dims[0]*dims[1]];
  dset.read(Bmat, PredType::NATIVE_FLOAT, dspace);
  projbase = cv::Mat(dims[0], dims[1], CV_32F, &Bmat);
  projbase = projbase.t();

  /// Access mean vector ///
  dset = fp.openDataSet("/mu/value");
  dspace = dset.getSpace();
  type_class = dset.getTypeClass();
  rank = dspace.getSimpleExtentDims(dims, NULL);
  if( type_class != H5T_FLOAT || dims[1] != 1 )
    throw invalid_argument( "TextFeatExtractor: expected mean (mu) to be a vectir of type H5T_IEEE_F64LE" );

  /// Create opencv matrix with mean ///
  float mumat[dims[0]];
  dset.read(mumat, PredType::NATIVE_FLOAT, dspace);
  projmu = cv::Mat(dims[0], dims[1], CV_32F, &mumat);
  projmu = projmu.t();

  fp.close();

  this->projfile = string(projfile);
}

///////////////////////
/// Features output ///
///////////////////////

/**
 * Prints a long in binary.
 */
inline static void print_int( long data, FILE* file ) {
  fwrite( ((char*) &data) + 3, sizeof(char), 1, file );
  fwrite( ((char*) &data) + 2, sizeof(char), 1, file );
  fwrite( ((char*) &data) + 1, sizeof(char), 1, file );
  fwrite( ((char*) &data)    , sizeof(char), 1, file );
}

/**
 * Prints an int in binary.
 */
inline static void print_short( int data, FILE* file ) {
  fwrite( ((char*) &data) + 1, sizeof(char), 1, file );
  fwrite( ((char*) &data)    , sizeof(char), 1, file );
}

/**
 * Prints a float in binary.
 */
inline static void print_float( float data, FILE* file ) {
  fwrite( ((char*) &data) + 3, sizeof(char), 1, file );
  fwrite( ((char*) &data) + 2, sizeof(char), 1, file );
  fwrite( ((char*) &data) + 1, sizeof(char), 1, file );
  fwrite( ((char*) &data)    , sizeof(char), 1, file );
}

/**
 * Prints features to a file stream using HTK format.
 *
 * @param feats  OpenCV matrix containing the features.
 * @param file   File stream to print the features.
 */
static void print_features_htk( const Mat& feats, FILE* file ) {
  int nSamples = feats.rows;
  int sampPeriod = 100000; /* 10000000 = 1seg */
  int sampSize = 4*feats.cols;
  int parmKind = 9; /* PARMKIND=USER */

  print_int( nSamples, file );
  print_int( sampPeriod, file );
  print_short( sampSize, file );
  print_short( parmKind, file );

  for( int i=0; i < feats.rows; i++ ) {
    const float* data = feats.ptr<float>(i);
    for( int j = 0; j < feats.cols; j++ )
      print_float( data[j], file );
  }
}

/**
 * Prints features to a file stream using ASCII format.
 *
 * @param feats  OpenCV matrix containing the features.
 * @param file   File stream to print the features.
 */
static void print_features_ascii( const Mat& feats, FILE* file ) {
  for( int i=0; i<feats.rows; i++ ) {
    const float *data = feats.ptr<float>(i);
    fprintf( file, "%g", data[0] );
    for( int j=1; j<feats.cols; j++ )
      fprintf( file, " %g", data[j] );
    fprintf( file, "\n" );
  }
}

/**
 * Whether the configured output format is image.
 */
bool TextFeatExtractor::isImageFormat() {
  return format == TEXTFEAT_FORMAT_IMAGE ? true : false ;
}

/**
 * Prints features to a file stream using the configured output format.
 *
 * @param feats  OpenCV matrix containing the features.
 * @param file   File stream to print the features.
 */
void TextFeatExtractor::print( const Mat& feats, FILE* file ) {
  if( feats.cols == 0 )
    throw runtime_error( "TextFeatExtractor::print: empty features matrix" );
  switch( format ) {
    case TEXTFEAT_FORMAT_ASCII:
      print_features_ascii( feats, file );
      break;
    case TEXTFEAT_FORMAT_HTK:
      print_features_htk( feats, file );
      break;
    case TEXTFEAT_FORMAT_IMAGE:
      throw runtime_error( "TextFeatExtractor::print: print is unsupported for image format" );
    default:
      throw runtime_error( "TextFeatExtractor::print: unknown output features format" );
  }
}

/**
 * Writes features to a file using the configured output format.
 *
 * @param feats  OpenCV matrix containing the features.
 * @param file   File name of where to write the features.
 */
void TextFeatExtractor::write( const Mat& feats, const char* fname ) {
  if( feats.cols == 0 )
    throw runtime_error( "TextFeatExtractor::write: empty features matrix" );
  if( format == TEXTFEAT_FORMAT_IMAGE )
    imwrite( fname, feats );
  else {
    FILE *file;
    if( (file=fopen(fname,"wb")) == NULL )
      throw runtime_error( string("TextFeatExtractor::write: unable to open file: ") + fname );
    print( feats, file );
    fclose(file);
  }
}

////////////////////////
/// Image processing ///
////////////////////////

/**
 * Copies image data from Magick::Image to an OpenCV Mat.
 *
 * @param image   Magick++ Image object.
 * @param cvimg   OpenCV Mat.
 */
static void magick2cvmat8u( Image& image, Mat& cvimg ) {
  CV_Assert( cvimg.depth() == CV_8U ); // accept only char type matrices
  CV_Assert( cvimg.channels() == 1 ); // accept only single channel matrices
  CV_Assert( image.type() == GrayscaleMatteType || image.type() == GrayscaleType );
  CV_Assert( (int)image.columns() == cvimg.cols );
  CV_Assert( (int)image.rows() == cvimg.rows );

  Pixels view(image);
  const PixelPacket *pixs = view.getConst( 0, 0, image.columns(), image.rows() );

  for( int y=0, n=0; y<cvimg.rows; y++ ) {
    uchar* ptr = cvimg.ptr<uchar>(y);
    for( int x=0; x<cvimg.cols; x++, n++ )
#if MAGICKCORE_QUANTUM_DEPTH == 16
      ptr[x] = pixs[n].red >> 8;
#elif MAGICKCORE_QUANTUM_DEPTH == 8
      ptr[x] = pixs[n].red;
#endif
  }
}

static void magick2cvmat8uc3( Image& image, Mat& cvimg ) {
  CV_Assert( cvimg.depth() == CV_8U ); // accept only char type matrices
  CV_Assert( cvimg.channels() == 3 ); // accept only three channel matrices
  CV_Assert( image.type() == TrueColorMatteType || image.type() == TrueColorType );
  CV_Assert( (int)image.columns() == cvimg.cols );
  CV_Assert( (int)image.rows() == cvimg.rows );

  Pixels view(image);
  const PixelPacket *pixs = view.getConst( 0, 0, image.columns(), image.rows() );

  for( int y=0, n=0; y<cvimg.rows; y++ ) {
    Vec3b *ptr = cvimg.ptr<Vec3b>(y);
    for( int x=0; x<cvimg.cols; x++, n++ ) {
#if MAGICKCORE_QUANTUM_DEPTH == 16
      ptr[x][2] = pixs[n].red >> 8;
      ptr[x][1] = pixs[n].green >> 8;
      ptr[x][0] = pixs[n].blue >> 8;
#elif MAGICKCORE_QUANTUM_DEPTH == 8
      ptr[x][2] = pixs[n].red;
      ptr[x][1] = pixs[n].green;
      ptr[x][0] = pixs[n].blue;
#endif
    }
  }
}

/**
 * Copies image data from Magick::Image to an unsigned char matrix.
 *
 * @param image   Magick++ Image object.
 * @param gimg    Unsigned char matrix (it is allocated if NULL).
 * @param _alpha  Pointer to unsigned char matrix for alpha channel (it is allocated if NULL).
 */
static void magick2graym( Image& image, gray**& gimg, gray*** _alpha = NULL ) {
  if( gimg == NULL )
    if( malloc_graym(image.columns(),image.rows(),&gimg,false) )
      throw runtime_error( "TextFeatExtractor: unable to reserve memory" );
  bool getalpha = _alpha != NULL && image.matte() ? true : false ;
  gray** alpha = NULL;
  if( getalpha ) {
    alpha = *_alpha;
    if( alpha == NULL )
      if( malloc_graym(image.columns(),image.rows(),&alpha,false) )
        throw runtime_error( "TextFeatExtractor: unable to reserve memory" );
    *_alpha = alpha;
  }
  Pixels view(image);
  const PixelPacket *pixs = view.getConst( 0, 0, image.columns(), image.rows() );
  for( int n=image.columns()*image.rows()-1; n>=0; n-- ) {
#if MAGICKCORE_QUANTUM_DEPTH == 16
    gimg[0][n] = pixs[n].red >> 8;
    if( getalpha )
      alpha[0][n] = pixs[n].opacity >> 8;
#elif MAGICKCORE_QUANTUM_DEPTH == 8
    gimg[0][n] = pixs[n].red;
    if( getalpha )
      alpha[0][n] = pixs[n].opacity;
#endif
  }
}

/**
 * Converts unsigned char to 16-bits.
 */
inline static int to16bits( int val ) {
  if( val == 255 )
    val = 65535;
  else if( val > 0 )
    val = ( val << 8 ) + 127;
  return val;
}

/**
 * Copies image data from unsigned char matrix to Magick::Image.
 *
 * @param image  Magick++ Image object.
 * @param gimg   Unsigned char matrix.
 * @param alpha  Unsigned char matrix for alpha channel.
 */
static void graym2magick( Image& image, gray** gimg, gray** alpha = NULL ) {
  Geometry page = image.page();
  Geometry density = image.density();
  //ResolutionType units = image.resolutionUnits(); // Magick++ bug
  ResolutionType units = image.image()->units;

  image = Image( Geometry(image.columns(), image.rows()), colorBlack );
  image.depth(8);
  image.page(page);
  image.density(density);
  image.resolutionUnits(units);

  //image.modifyImage();

  if( alpha != NULL && image.type() != GrayscaleMatteType )
    image.type( GrayscaleMatteType );
  else if( alpha == NULL && image.type() != GrayscaleType )
    image.type( GrayscaleType );
  Pixels view(image);
  PixelPacket *pixs = view.get( 0, 0, image.columns(), image.rows() );
  for( int n=image.columns()*image.rows()-1; n>=0; n-- ) {
#if MAGICKCORE_QUANTUM_DEPTH == 16
    pixs[n].red = pixs[n].green = pixs[n].blue = to16bits(gimg[0][n]);
    if( alpha != NULL )
      pixs[n].opacity = to16bits(alpha[0][n]);
#elif MAGICKCORE_QUANTUM_DEPTH == 8
    pixs[n].red = pixs[n].green = pixs[n].blue = gimg[0][n];
    if( alpha != NULL )
      pixs[n].opacity = alpha[0][n];
#endif
  }
  view.sync();
}

/**
 * Copies image data from unsigned char matrix to Magick::Image.
 *
 * @param image  Magick++ Image object.
 * @param gimg   Unsigned char matrix.
 * @param alpha  Unsigned char matrix for alpha channel.
 */
static void grayms2magick( Image& image, gray** rimg, gray** gimg, gray** bimg, gray** alpha = NULL ) {
  Geometry page = image.page();
  Geometry density = image.density();
  ResolutionType units = image.image()->units;

  image = Image( Geometry(image.columns(), image.rows()), colorBlack );
  image.depth(8);
  image.page(page);
  image.density(density);
  image.resolutionUnits(units);

  if( alpha != NULL && image.type() != TrueColorMatteType )
    image.type( TrueColorMatteType );
  else if( alpha == NULL && image.type() != TrueColorType )
    image.type( TrueColorType );
  Pixels view(image);
  PixelPacket *pixs = view.get( 0, 0, image.columns(), image.rows() );
  for( int n=image.columns()*image.rows()-1; n>=0; n-- ) {
#if MAGICKCORE_QUANTUM_DEPTH == 16
    pixs[n].red = to16bits(rimg[0][n]);
    pixs[n].green = to16bits(gimg[0][n]);
    pixs[n].blue = to16bits(bimg[0][n]);
    if( alpha != NULL )
      pixs[n].opacity = to16bits(alpha[0][n]);
#elif MAGICKCORE_QUANTUM_DEPTH == 8
    pixs[n].red = rimg[0][n];
    pixs[n].green = gimg[0][n];
    pixs[n].blue = bimg[0][n];
    if( alpha != NULL )
      pixs[n].opacity = alpha[0][n];
#endif
  }
  view.sync();
}


/**
 * Copies image data from an OpenCV Mat to Magick::Image.
 *
 * @param image   Magick++ Image object.
 * @param cvimg   OpenCV Mat.
 */
static void cvmat8u2magick( Image& image, Mat& cvimg ) {
  CV_Assert( cvimg.depth() == CV_8U ); // accept only char type matrices
  CV_Assert( cvimg.channels() == 1 ); // accept only single channel matrices
  CV_Assert( (int)image.columns() == cvimg.cols );
  CV_Assert( (int)image.rows() == cvimg.rows );

  Geometry page = image.page();
  Geometry density = image.density();
  //ResolutionType units = image.resolutionUnits(); // Magick++ bug
  ResolutionType units = image.image()->units;
  image = Image( Geometry(image.columns(), image.rows()), colorBlack );
  image.depth(8);
  image.page(page);
  image.density(density);
  image.resolutionUnits(units);

  //image.modifyImage();

  if( image.type() != GrayscaleType )
    image.type( GrayscaleType );
  Pixels view(image);
  PixelPacket *pixs = view.get( 0, 0, image.columns(), image.rows() );
  for( int y=0, n=0; y<cvimg.rows; y++ ) {
    uchar* ptr = cvimg.ptr<uchar>(y);
    for( int x=0; x<cvimg.cols; x++, n++ )
#if MAGICKCORE_QUANTUM_DEPTH == 16
    pixs[n].red = pixs[n].green = pixs[n].blue = to16bits(ptr[x]);
#elif MAGICKCORE_QUANTUM_DEPTH == 8
    pixs[n].red = pixs[n].green = pixs[n].blue = ptr[x];
#endif
  }
  view.sync();
}


/**
 * Does a local enhancement of a text image.
 *
 * @param image  Magick++ Image object.
 * @param winW   Window width for local enhancement.
 * @param prm    Enhancement parameter.
 * @param slp    Gray slope parameter.
 * @param type   Enhancement algorithm.
 */
static void enhance( Image& image, int winW, double prm1, double slp, int type, double prm0 = 0.0, double prm2 = 0.0 ) {
  gray** gimg = NULL;
  gray** msk = NULL;
  II1** ii1 = NULL;
  II2** ii2 = NULL;
  II1** cnt = NULL;

  magick2graym(image,gimg,&msk);
  if( msk != NULL )
    for( int n=image.columns()*image.rows()-1; n>=0; n-- )
      msk[0][n] = 255-msk[0][n];

  if( prm0 == 0.0 && prm2 == 0.0 ) {
    enhLocal_graym( gimg, msk, image.columns(), image.rows(), &ii1, &ii2, &cnt, winW, prm1, slp, type );
    graym2magick(image,gimg);
  }
  else {
    gray** rimg = NULL;
    gray** bimg = NULL;
    malloc_graym(image.columns(),image.rows(),&rimg,false);
    malloc_graym(image.columns(),image.rows(),&bimg,false);
    for( int n=image.columns()*image.rows()-1; n>=0; n-- )
      rimg[0][n] = bimg[0][n] = gimg[0][n];

    enhLocal_graym( rimg, msk, image.columns(), image.rows(), &ii1, &ii2, &cnt, winW, prm0, slp, type );
    enhLocal_graym( gimg, msk, image.columns(), image.rows(), &ii1, &ii2, &cnt, winW, prm1, slp, type );
    enhLocal_graym( bimg, msk, image.columns(), image.rows(), &ii1, &ii2, &cnt, winW, prm2, slp, type );
    grayms2magick(image,rimg,gimg,bimg);

    free(rimg);
    free(bimg);
  }

  free(gimg);
  free(ii1);
  free(ii2);
  if( msk != NULL ) {
    free(msk);
    free(cnt);
  }
}





int rlsa4_graym(gray** img, int imgW, int imgH, char op, int* lengths, bool negate, gray** res) {
  int n;
  if( negate )
    for( n=imgW*imgH-1; n>=0; n-- )
      img[0][n] = 255-img[0][n];

  gray **freeimg = NULL;
  if( img == res ) {
    if( clone_graym(img,imgW,imgH,&freeimg) ) {
      fprintf(stderr,"rlsa4_graym: error: unable to reserve memory\n");
      return FAILURE;
    }
    img = freeimg;
  }
  else
    memcpy(res[0],img[0],imgW*imgH*sizeof(gray));

  /*** bit 0 -> '-' ***/
  if( op & 0x01 ) {
    //fprintf(stderr,"rlsa4_graym: '-'\n");
    int length = lengths[0];
    int y;
    for( y=imgH-1; y>=0; y-- ) {
      gray *imgy = img[y];
      gray *resy = res[y];

      int x = imgW-1;
      while( x>0 ) {
        int xx, prevx = x;
        /* move all white pixels */
        while( x>=0 && imgy[x] )
          x--;
        /* change white pixels to black if less than length */
        if( x>=0 && (prevx-x)<length && prevx!=imgW-1 )
          for( xx=prevx; xx>x; xx-- )
            resy[xx] = 0;
        /* move all black pixels */
        while( x>=0 && !imgy[x] )
          x--;
      }
    }
  }

  /*** bit 1 -> '|' ***/
  if( (op>>1) & 0x01 ) {
    //fprintf(stderr,"rlsa4_graym: '|'\n");
    int length = lengths[1];
    int x;
    for( x=imgW-1; x>=0; x-- ) {

      int y = imgH-1;
      while( y>0 ) {
        int yy, prevy = y;
        /* move all white pixels */
        while( y>=0 && img[y][x] )
          y--;
        /* change white pixels to black if less than length */
        if( y>=0 && (prevy-y)<length && prevy!=imgH-1 )
          for( yy=prevy; yy>y; yy-- )
            res[yy][x] = 0;
        /* move all black pixels */
        while( y>=0 && !img[y][x] )
          y--;
      }
    }
  }

  /*** bit 2 -> '/' ***/
  if( (op>>2) & 0x01 ) {
    //fprintf(stderr,"rlsa4_graym: '/'\n");
    int length = lengths[2];

    int n;
    for( n=-imgH; n<imgW; n++ ) {
      int x = n<0 ? 0 : n ;
      int y = n<0 ? imgH+n : imgH-1 ;

      while( x<imgW-1 && y>0 ) {
        int xx, yy, prevx = x, prevy = y;
        /* move all white pixels */
        while( x<=imgW-1 && y>=0 && img[y][x] ) {
          x++;
          y--;
        }
        /* change white pixels to black if less than length */
        if( x<=imgW-1 && y>=0 &&
            (prevy-y)<length &&
            prevx!=0 && prevy!=imgH-1 )
          for( xx=prevx, yy=prevy; yy>y; xx++, yy-- )
            res[yy][xx] = 0;
        /* move all black pixels */
        while( x<=imgW-1 && y>=0 && !img[y][x] ) {
          x++;
          y--;
        }
      }
    }
  }

  /*** bit 3 -> '\' ***/
  if( (op>>3) & 0x01 ) {
    //fprintf(stderr,"rlsa4_graym: '\\'\n");
    int length = lengths[3];

    int n;
    for( n=-imgH; n<imgW; n++ ) {
      int x = n<0 ? imgW-1 : imgW-1-n ;
      int y = n<0 ? imgH+n : imgH-1 ;

      while( x>0 && y>0 ) {
        int xx, yy, prevx = x, prevy = y;
        /* move all white pixels */
        while( x>=0 && y>=0 && img[y][x] ) {
          x--;
          y--;
        }
        /* change white pixels to black if less than length */
        if( x>=0 && y>=0 &&
            (prevy-y)<length &&
            prevx!=imgW-1 && prevy!=imgH-1 )
          for( xx=prevx, yy=prevy; yy>y; xx--, yy-- )
            res[yy][xx] = 0;
        /* move all black pixels */
        while( x>=0 && y>=0 && !img[y][x] ) {
          x--;
          y--;
        }
      }
    }
  }

  if( negate ) {
    for( n=imgW*imgH-1; n>=0; n-- )
      res[0][n] = 255-res[0][n];
    if( freeimg == NULL )
      for( n=imgW*imgH-1; n>=0; n-- )
        img[0][n] = 255-img[0][n];
  }

  if( freeimg != NULL )
    free(freeimg);

  return SUCCESS;
}








inline static void findMinMax( int size, double* vals, bool* isset, double* _minval = NULL, double* _maxval = NULL, int* _minidx = NULL, int* _maxidx = NULL ) {
  int minidx = -1;
  int maxidx = -1;
  double min = 0.0;
  double max = 0.0;
  for( int n=size-1; n>=0; n-- )
    if( isset[n] ) {
      if( minidx < 0 || min < vals[n] )
        min = vals[ minidx = n ];
      if( maxidx < 0 || max < vals[n] )
        max = vals[ maxidx = n ];
    }
  if( _minidx != NULL ) *_minidx = minidx;
  if( _maxidx != NULL ) *_maxidx = maxidx;
  if( _minval != NULL ) *_minval = min;
  if( _maxval != NULL ) *_maxval = max;
}


#define __SLANT_PYRAMIDAL__
//#define __SLANT_WEIGHTED_SHEAR__

/**
 * Estimates the slant angle of an image containing handwritten text.
 *
 * @param image  Magick++ Image object.
 * @param amin   Minimum slant angle in degrees.
 * @param amax   Maximum slant angle in degrees.
 * @param amin   Slant angle step in degrees.
 * @return       Estimated slant angle in degrees.
 *
 * @todo If alpha channel, do not project transparent
 */
static double estimateSlant( Image& image, double amin, double amax, double astep, int hsteps = 4, double hfact = 0.7 ) {
  amin *= M_PI/180;
  amax *= M_PI/180;
  astep *= M_PI/180;

  int imgW = image.columns();
  int imgH = image.rows();
  int imgWH = imgW*imgH;
  int lgth = imgW + 4*imgH;
  double proj[lgth];
  double cnt[lgth];
  double bestangle = 0.0;
#ifndef __SLANT_PYRAMIDAL__
  double maxvar = 0.0;
#endif

  Pixels view(image);
  const PixelPacket *pixs = view.getConst( 0, 0, image.columns(), image.rows() );

#ifdef __SLANT_PYRAMIDAL__
  /// List angles for pyramidal sampling ///
  int Nangles = 0;
  for( double angle=amin; angle<=amax+0.1*astep; angle+=astep )
    Nangles++;
  if( Nangles == 0 )
    return bestangle;
  bool test_angle[Nangles];
  bool seen_angle[Nangles];
  double angles[Nangles];
  double values[Nangles];
  int skip = 1 << (hsteps-1);

  /// Pyramidal sampling loop ///
  for( int hstep=hsteps; hstep>0; hstep--, skip/=2 ) {

    /// Initially only sample every skip angles ///
    if( hstep == hsteps ) {
      int offset = ( skip - Nangles + 1 + (int)(floor((double)(Nangles-1)/skip)*skip) ) / 2;
      for( int a=0; a<Nangles; amin+=astep, a++ ) {
        test_angle[a] = a == 0 || a == Nangles-1 || (a+offset)%skip == 0 ? true : false ;
        seen_angle[a] = false;
        angles[a] = amin;
      }
    }

    /// Then sample on both sides of large found values, each time with half the skip ///
    else {
      double maxval, minval;
      findMinMax( Nangles, values, seen_angle, &minval, &maxval );
      maxval = hfact*(maxval-minval)+minval;
      for( int a=Nangles-1; a>=0; a-- )
        if( seen_angle[a] && values[a] >= maxval ) {
          if( a-skip > 0 && ! seen_angle[a-skip] )
            test_angle[a-skip] = true;
          if( a+skip < Nangles-1 && ! seen_angle[a+skip] )
            test_angle[a+skip] = true;
        }
    }

    for( int a=Nangles-1; a>=0; a-- ) {
      if( seen_angle[a] || ! test_angle[a] )
        continue;
      double angle = angles[a];
#else

  /// Test possible slant angles ///
  for( double angle = amin; angle<=amax+0.1*astep; angle += astep ) {
#endif

    for( int n=lgth-1; n>=0; n-- )
      proj[n] = cnt[n] = 0.0;
    double maxdisp = (imgH-1)*tan(angle);
    double offset = maxdisp < 0 ? -maxdisp : 0 ;

    /// Project for the current angle ///
    for( int y=imgH-1, xy=imgWH-1; y>=0; y-- ) {
    //for( int y=0, xy=0; y<imgH; y++ ) {
      double disp = maxdisp*y/(imgH-1);
      for( int x=imgW-1; x>=0; x--, xy-- ) {
      //for( int x=0; x<imgW; x++, xy++ ) {
        float xx = x + offset + disp;
        //double xx = x + offset + disp;
        int floorxx = (int)xx;
        if( floorxx < 0 || floorxx+(floorxx==xx?0:1) >= lgth )
          continue;

#ifdef __SLANT_WEIGHTED_SHEAR__
        if( floorxx == xx ) {
#endif
          proj[floorxx] += pixs[xy].green;
          cnt[floorxx]++;
#ifdef __SLANT_WEIGHTED_SHEAR__
        }
        else {
          float fact = xx-floorxx;
          float val = fact*pixs[xy].green;
          //double fact = xx-floorxx;
          //double val = fact*pixs[xy].green;
          proj[floorxx] += pixs[xy].red-val;
          proj[floorxx+1] += val;
          cnt[floorxx] += 1.0-fact;
          cnt[floorxx+1] += fact;
        }
#endif
      }
    }

    /// Compute variance of projection ///
    double s = 0.0;
    double ss = 0.0;
    int tot = 0;
    for( int n=lgth-1; n>=0; n-- )
      if( cnt[n] > 0.0 ) {
        tot ++;
        double val = proj[n]/(cnt[n]*QuantumRange);
        s += val;
        ss += val*val;
      }
    s /= tot;
    s = ss/tot - s*s;

#ifdef __SLANT_PYRAMIDAL__
    values[a] = s;
    seen_angle[a] = true;
    test_angle[a] = false;

#else
    /// Keep angle with largest variance ///
    if( s > 0.0 && s > maxvar ) {
      maxvar = s;
      bestangle = angle;
    }
#endif
    //printf(" %g",sqrt(s));
  }
  //printf("\n");

#ifdef __SLANT_PYRAMIDAL__
  }

  //double speedup = 0;
  //for( int a=0; a<Nangles; a++ )
  //  speedup += seen_angle[a] ? 0 : 1 ;
  //fprintf(stderr,"speedup=%g\n",100.0*speedup/Nangles);

  int maxidx;
  findMinMax( Nangles, values, seen_angle, NULL, NULL, NULL, &maxidx );
  bestangle = angles[maxidx];
#endif

  return bestangle*180/M_PI;
}










/**
 * Gets outer contour points of connected components in an image, optionally approximating it.
 *
 * @param image     Magick++ Image object.
 * @param contours  Output array of arrays containing the contours.
 * @param method    Contour approximation method.
 * @param eps       Epsilon for approxPolyDP, zero to disable.
 */
void findOuterContours( Image& img, vector< vector<Point> >& contours, int method, double eps = 0.0 ) {
  cv::Mat cvimg( cv::Size(img.columns(),img.rows()), CV_8U );
  magick2cvmat8u( img, cvimg );

  /// Get outer contours ///
  cv::findContours( cvimg, contours, CV_RETR_EXTERNAL, method, cvPoint(0,0) );

  /// Approximate contours ///
  if( eps > 0.0 ) {
    for( size_t n=0; n<contours.size(); n++ ) {
      vector<Point> approx;
      cv::approxPolyDP( contours[n], approx, eps, true );
      contours[n] = approx;
    }
  }

  /// Add image page offset to contour coordinates ///
  int xoff = img.page().xOff();
  int yoff = img.page().yOff();
  if( xoff != 0 || xoff != 0 )
    for( size_t n=0; n<contours.size(); n++ ) {
      for( size_t m=0; m<contours[n].size(); m++ ) {
        contours[n][m].x += xoff;
        contours[n][m].y += yoff;
      }
    }
}


/**
 * Joints all connected components in an image using 1px thick lines between nearest contour points.
 *
 * @param image    Magick++ Image object.
 */
static void joinComponents( Image& img ) {
  cv::Mat cvimg( cv::Size(img.columns(),img.rows()), CV_8U );
  magick2cvmat8u( img, cvimg );

  /// Get external contours ///
  vector< vector<Point> > contours;
  cv::findContours( cvimg, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, cvPoint(0,0) );

  magick2cvmat8u( img, cvimg );

  /// Prepare contours nearest neighbor search ///
  int N = 0;
  int C = contours.size();
  for( int x=0; x<C; x++ )
    N += contours[x].size();

  int* ccid = NULL;
  malloc_I1v( C+N, &ccid, false );
  int *nnccid = ccid + C;

  for( int x=0; x<C; x++ )
    ccid[x] = x;

  /// Loop through all contours ///
  for( int x=0; x<C; x++ )
    if( ccid[x] == x ) { // test if not already joined
      int nx=0, ny=0;

      /// Copy x-th component coordinates for test ///
      for( int xx=0; xx<C; xx++ )
        nx += x == ccid[xx] ? contours[xx].size() : 0 ;

      if( nx == N )
        break;

      cv::Mat ftest = cv::Mat::zeros( nx, 2, CV_32F );
      for( int xx=0,nn=0; xx<C; xx++ )
        if( x == ccid[xx] ) {
          vector<Point> contxx = contours[xx];
          for( size_t n=0; n<contxx.size(); n++,nn++ ) {
            ftest.at<float>(nn,0) = contxx[n].x;
            ftest.at<float>(nn,1) = contxx[n].y;
          }
        }

      /// Copy all other component coordinates for reference ///
      cv::Mat fref = cv::Mat::zeros( N-nx, 2, CV_32F );
      for( int y=0,nn=0; y<C; y++ )
        if( x != ccid[y] ) {
          vector<Point> conty = contours[y];
          for( size_t n=0; n<conty.size(); n++,nn++,ny++ ) {
            fref.at<float>(nn,0) = conty[n].x;
            fref.at<float>(nn,1) = conty[n].y;
            nnccid[ny] = y;
          }
        }

      /// Find nearest neighbors ///
      cv::Mat nnidx( N-nx, 1, CV_32S );
      cv::Mat nndst( N-nx, 1, CV_32F );
      cv::flann::Index flann_index( fref, cv::flann::LinearIndexParams() );

      flann_index.knnSearch( ftest, nnidx, nndst, 1, cv::flann::SearchParams() );

      float dst = nndst.at<float>(0,0);
      int i = 0;
      for( int n=1; n<nx; n++ )
        if( dst > nndst.at<float>(n,0) ) {
          dst = nndst.at<float>(n,0);
          i = n;
        }

      /// Relabel joined components ///
      int j = nnidx.at<int>(i,0);
      int c = nnccid[j];
      while( c != ccid[c] )
        c = ccid[c];
      for( int xx=0; xx<C; xx++ )
        if( x == ccid[xx] )
          ccid[xx] = c;

      /// Join components with a line ///
      cv::line( cvimg, Point(ftest.at<float>(i,0),ftest.at<float>(i,1)), Point(fref.at<float>(j,0),fref.at<float>(j,1)), Scalar(255,255,255,0) );

      ftest.release();
      fref.release();
      nnidx.release();
      nndst.release();
      flann_index.release();
    }

  cvmat8u2magick( img, cvimg );

  free(ccid);
}






/**
 * Converts image to grayscale preserving alpha channel if present.
 *
 * @param image    Image to process.
 * @return         Whether the conversion was performed.
 */
bool toGrayscale( Image& image ) {
  if( image.type() == GrayscaleMatteType || image.type() == GrayscaleType )
    return false;
  if( image.matte() && image.type() != GrayscaleMatteType )
    image.type( GrayscaleMatteType );
  else if( ! image.matte() && image.type() != GrayscaleType )
    image.type( GrayscaleType );
  return true;
}

/**
 * Removes alpha channel, setting all transparent regions to the background color.
 *
 * @param image    Image to process.
 * @param color    Color for the background.
 * @return         Whether flattening was performed.
 */
bool flattenImage( Image& image, const Color* color = NULL ) {
  if( ! image.matte() )
    return false;

  Image clone = Image( Geometry(image.columns(), image.rows()), color == NULL ? colorWhite : *color );
  clone.depth(image.depth());
  clone.page(image.page());
  clone.density(image.density());
  //clone.resolutionUnits(image.resolutionUnits()); // Magick++ bug
  clone.resolutionUnits(image.image()->units);
  clone.type( GrayscaleType );

  Pixels view_image(image);
  PixelPacket *pixs_image = view_image.get( 0, 0, image.columns(), image.rows() );
  Pixels view_clone(clone);
  PixelPacket *pixs_clone = view_clone.get( 0, 0, image.columns(), image.rows() );
  for( int n=image.columns()*image.rows()-1; n>=0; n-- )
    if( ! pixs_image[n].opacity )
      pixs_clone[n] = pixs_image[n];
  view_clone.sync();

  image = clone;
  return true;
}
/*bool flattenImageOld( Image& image, const Color* color = NULL ) {
  if( ! image.matte() )
    return false;
  if( color != NULL )
    image.backgroundColor( *color );
  list<Image> flattenList = { image };
  Image flat;
  flattenImages( &flat, flattenList.begin(), flattenList.end() );
  image = flat;
  return true;
}*/

/**
 * Pre-processes a text image, optionally computing the connected components contour.
 *
 * @param image      Image to process.
 * @param _fcontour  Output contour points, set to NULL to skip computation.
 * @param randomize  Whether to do a random perturbation of preprocessing parameters.
 */
void TextFeatExtractor::preprocess( Image& image, vector<Point>* _fcontour, bool randomize ) {
  high_resolution_clock::time_point tm;

  /// Convert to grayscale ///
  tm = high_resolution_clock::now();
  if( toGrayscale(image) && verbose )
    fprintf(stderr,"gray time: %d us\n",(int)duration_cast<microseconds>(high_resolution_clock::now()-tm).count());

  if( procimgs )
    image.write("procimg_1_input.png");

  /// Contrast stretching ///
  if( stretch ) {
    tm = high_resolution_clock::now();
    image.normalize();
    //MagickCore::ContrastStretchImage(image.image(), (to_string(100*stretch_satu)+"%").c_str() );
    if( verbose )
      fprintf(stderr,"stretch time: %d us\n",(int)duration_cast<microseconds>(high_resolution_clock::now()-tm).count());
    if( procimgs )
      image.write("procimg_2_stretch.png");
  }

  /// Text image enhancement ///
  if( enh ) {
    float prm = enh_prm;

    /// Random perturbation ///
    if( randomize && enh_prm_randmax ) {
      prm = (enh_prm_randmax-enh_prm_randmin)*rand()/(float)RAND_MAX + enh_prm_randmin;
      if( verbose )
        fprintf(stderr,"random prm: %g\n",prm);
    }

    tm = high_resolution_clock::now();
    //enhance( image, enh_win, prm, enh_slp, enh_type );
    enhance( image, enh_win, prm, enh_slp, enh_type, enh3_prm0, enh3_prm2 );
    if( verbose )
      fprintf(stderr,"enhance time: %d us\n",(int)duration_cast<microseconds>(high_resolution_clock::now()-tm).count());
    if( procimgs )
      image.write("procimg_3_enh.png");
  }
  else
    flattenImage(image);

  /// Compute connected components contour polygon ///
  if( compute_fcontour && _fcontour != NULL && ! randomize ) {
    tm = high_resolution_clock::now();

    //float fcontour_dilate = 4;
    int border = fcontour_dilate+1;

    /// Binalize image ///
    Image tmp = image;
    tmp.threshold(QuantumRange-1);

    /// Add border ///
    Geometry page = image.page();
    tmp.borderColor( colorWhite );
    tmp.border( Geometry(border,border) );
    tmp.page( Geometry(page.width(),page.height(),page.xOff()-border,page.yOff()-border) );

    /// Apply RLSA ///
    gray** gimg = NULL;
    magick2graym(tmp,gimg);
    int irlsa[] = { 50, 20, 20, 20 };
    rlsa4_graym( gimg, tmp.columns(), tmp.rows(), 0xff, irlsa, false, gimg );
    graym2magick(tmp,gimg);
    free(gimg);

    /// Joint connected components ///
    tmp.negate();
    joinComponents( tmp );

    /// Dilate using disk structural element ///
    char kern[32];
    sprintf( kern, "Disk:%.2g", fcontour_dilate );
    tmp.morphology( DilateMorphology, string(kern) );

    /// Get contour coordinates ///
    vector<vector<Point> > fcontour;
    double eps = fcontour_dilate/2.0;
    //int method = CV_CHAIN_APPROX_TC89_KCOS;
    int method = CV_CHAIN_APPROX_SIMPLE;
    findOuterContours( tmp, fcontour, method, eps );

    *_fcontour = fcontour[0];

    if( verbose )
      fprintf(stderr,"fcontour time: %d us\n",(int)duration_cast<microseconds>(high_resolution_clock::now()-tm).count());
  }
}

/**
 * Estimates slope and slant angles for an image.
 *
 * @param image   Image to process.
 * @param _slope  Estimated slope angle in degrees.
 * @param _slant  Estimated slant angle in degrees.
 */
void TextFeatExtractor::estimateAngles( Image& image, float* _slope, float* _slant, float rotate ) {
  high_resolution_clock::time_point tm;

  /// Estimate line slope angle ///
  float vslope = 0.0;
  Image desloped = image;

  if( rotate != 0.0 )
    desloped.rotate(rotate);

  //#pragma omp critical
  if( deslope ) {
    tm = high_resolution_clock::now();
    desloped.deskew( 0.4*QuantumRange );
    if( verbose )
      fprintf(stderr,"deslope time: %d us\n",(int)duration_cast<microseconds>(high_resolution_clock::now()-tm).count());
    vslope = stof( desloped.artifact("deskew:angle") );
  }
  if( _slope != NULL )
    *_slope = vslope;

  //if( procimgs )
  //  desloped.write("procimg_4_deslope.png");

  /*Image tmp = image;
  tm = high_resolution_clock::now();
  //tmp.monochrome(true);
//tmp.write("x:");
  gray** gimg = NULL;
  magick2graym(tmp,gimg);
  double slope2;
  skew_angle(gimg,tmp.columns(),tmp.rows(),8*M_PI/180,0.1*M_PI/180,&slope2);
  if( verbose )
    fprintf(stderr,"slope2 time: %d us\n",(int)duration_cast<microseconds>(high_resolution_clock::now()-tm).count());
fprintf(stderr,"slope:   %g   %g\n",slope,slope2*180/M_PI);*/

  /// Estimate writing slant angle ///
  float vslant = 0.0;
  if( deslant ) {
    tm = high_resolution_clock::now();
    vslant = estimateSlant( desloped, deslant_min, deslant_max, deslant_step, deslant_hsteps );
    if( verbose )
      fprintf(stderr,"deslant time: %d us\n",(int)duration_cast<microseconds>(high_resolution_clock::now()-tm).count());
  }
  if( _slant != NULL )
    *_slant = vslant;
}



/**
 * Extracts features for the given image already preprocessed image.
 *
 * @param feaimg     Image to process.
 * @param slope      Slope angle in degrees.
 * @param slant      Slant angle in degrees.
 * @param _fpgram    Output features parallelogram coordinates.
 * @param randomize  Whether to do a random perturbation of extraction parameters.
 * @return           Features matrix.
 */
Mat TextFeatExtractor::extractFeats( Image& feaimg, float slope, float slant, int xheight, vector<Point2f>* _fpgram, bool randomize, float rotate, int direction ) {
  high_resolution_clock::time_point tm = high_resolution_clock::now();

  /// Set image transparent zones to white ///
  if( flattenImage(feaimg,&colorWhite) && verbose )
    fprintf(stderr,"flatten time: %d us\n",(int)duration_cast<microseconds>(high_resolution_clock::now()-tm).count());

  /// Random slant ///
  if( randomize && slant_rand ) {
    float rnd = 2*slant_rand*((rand()/(float)RAND_MAX)-0.5);
    if( verbose )
      fprintf(stderr,"random slant: %g\n",rnd);
    slant += rnd;
  }

  /// Apply affine transformation considering both slope and slant ///
  int bboxoffx = feaimg.page().xOff();
  int bboxoffy = feaimg.page().yOff();
  int offx = 0;
  int offy = 0;
  const double deg_to_rad = M_PI/180;
  double co = cos( slope*deg_to_rad );
  double si = sin( slope*deg_to_rad );
  double s = tan( slant*deg_to_rad );

  Matx33d R0( co,  si, 0, -si, co, 0, 0, 0, 1 );
  Matx33d R1( co, -si, 0,  si, co, 0, 0, 0, 1 );
  Matx33d S0( 1, 0, 0,  s, 1, 0, 0, 0, 1 );
  Matx33d S1( 1, 0, 0, -s, 1, 0, 0, 0, 1 );
  Matx33d A0 = R0*S0;
  Matx33d A1 = S1*R1;

  if( rotate != 0.0 ) {
    feaimg.rotate(rotate);
    // @todo The following is incorrect, need to fix it
    //fprintf("warning: fpgrams for rotated lines not yet implemented\n");
    co = cos( -rotate*deg_to_rad );
    si = sin( -rotate*deg_to_rad );
    Matx33d R3( co, -si, 0,  si, co, 0, 0, 0, 1 );
    A1 = A1*R3;
  }

  feaimg.page( Geometry(0,0,0,0) );

  if( slope != 0.0 || slant != 0.0 ) {
    tm = high_resolution_clock::now();
    feaimg.virtualPixelMethod( WhiteVirtualPixelMethod );
    //feaimg.interpolate( BilinearInterpolatePixel );
    //feaimg.interpolate( SplineInterpolatePixel );
    //feaimg.interpolate( NearestNeighborInterpolatePixel );
    feaimg.affineTransform( DrawableAffine( A0(0,0), A0(1,1), A0(0,1), A0(1,0), A0(2,0), A0(2,1) ) );
    //printf( "affine: %g %g %g %g %g %g\n", A0(0,0), A0(1,1), A0(0,1), A0(1,0), A0(2,0), A0(2,1) );
    feaimg.shave( Geometry(1,1) );
    offx = feaimg.page().xNegative() ? -feaimg.page().xOff() : feaimg.page().xOff();
    offy = feaimg.page().yNegative() ? -feaimg.page().yOff() : feaimg.page().yOff();
    //fprintf( stderr, "page_off: %d %d\n", offx, offy );
    feaimg.page( Geometry(0,0,0,0) );
    if( verbose )
      fprintf(stderr,"affine time: %d us\n",(int)duration_cast<microseconds>(high_resolution_clock::now()-tm).count());
    if( procimgs )
      feaimg.write("procimg_5_affine.png");
  }

  /// Trim image ///
  Image trimmed = feaimg;
  trimmed.trim();
  if( trimmed.columns()+trimmed.rows() > 2 ) {
    feaimg = trimmed;
    offx += feaimg.page().xOff();
    offy += feaimg.page().yOff();
    //fprintf( stderr, "trim_page_off: %d %d\n", offx, offy );
  }

  /// Momentum normalization ///
  if( momentnorm ) {
    cv::Mat line_img( feaimg.rows(), feaimg.columns(), CV_8UC1, cv::Scalar(0) );

    Image momimg = feaimg;
    if( momimg.type() != GrayscaleType ) {
      momimg.type( GrayscaleType );
      //momimg.quantizeColorSpace( GRAYColorspace ); 
      //momimg.quantizeColors( 256 ); 
      //momimg.quantize( );
    }

    magick2cvmat8u( momimg, line_img );
    line_img = line_img ^ 0xFF;

    cv::Mat sob_x, sob_y;
    cv::Sobel(cv::InputArray(line_img), cv::OutputArray(sob_x), CV_32FC1, 1, 0);
    cv::Sobel(cv::InputArray(line_img), cv::OutputArray(sob_y), CV_32FC1, 0, 1);
    cv::magnitude(sob_x, sob_y, line_img);

    cv::Moments line_mnt = cv::moments(line_img);

    if( line_mnt.m00 != 0.0 ) {
      int mom_height = round( 4*sqrt(line_mnt.mu02/line_mnt.m00) );
      int mom_yoff = round( line_mnt.m01/line_mnt.m00 - 0.5*mom_height );
      feaimg.extent( Geometry(feaimg.columns(),mom_height,0,mom_yoff), colorWhite );
      offy += mom_yoff; // @todo Is ths correct?
      //fprintf(stderr,"mom_norm: yoff=%d height=%d\n",mom_yoff,mom_height);
    }
  }

  double scaling = 1.0;
  //int orig_height = feaimg.rows();

  /// Normalize x-height ///
  if( normxheight > 0 && xheight > 0 ) {
    float fact = 100.0*(float)normxheight/(float)xheight;
    scaling *= 0.01*fact;
    feaimg.resize( Geometry( (to_string(fact)+"%").c_str() ) );
  }

// @todo BUG: When there is an image resize (height normalization) fpgram is wrong
  if( normheight && ! normxheight ) {
    scaling *= (float)normheight/(float)feaimg.rows();
    feaimg.resize( Geometry( ("x"+to_string(normheight)).c_str() ) );
  }

  /// Random scaling ///
  if( randomize && scale_rand ) {
    float rnd = 100 + 2*scale_rand*((rand()/(float)RAND_MAX)-0.5);
    if( verbose )
      fprintf(stderr,"random scale: %g%%\n",rnd);
    feaimg.resize( Geometry( (to_string(rnd)+"%").c_str() ) );
    scaling *= 0.01*rnd;
  }

  /// Add left and right padding ///
  if( padding ) {
    feaimg.borderColor( colorWhite );
    feaimg.border( Geometry(padding,0) );
  }

  /// Account for reading direction ///
  if( direction == PAGEXML_READ_DIRECTION_RTL )
    feaimg.flop();
  else if( direction == PAGEXML_READ_DIRECTION_TTB || direction == PAGEXML_READ_DIRECTION_BTT )
    fprintf(stderr,"warning: vertical reading directions not supported\n");

  if( procimgs )
    feaimg.write("procimg_6_fea.png");

  /// Compute features parallelogram ///
  if( compute_fpgram && _fpgram != NULL && ! randomize ) {
    double xmin = -padding;
    double xmax = feaimg.columns()-1-padding;
    /*if( featype == TEXTFEAT_TYPE_DOTMATRIX ) {
      int numFea = 0;
      for( double x=-slide_span; x<=feaimg.columns()+1; x+=slide_shift )
        numFea++;
      xmin = -0.5*slide_span-padding;
      xmax = xmin+(numFea-1)*slide_shift;
    }*/
    //fprintf(stderr,"numFea=%d xmin=%g xmax=%g\n",numFea,xmin,xmax);

    /*Matx43d pts( offx+xmin, offy, 1,
                 offx+xmax, offy, 1,
                 offx+xmax, offy+feaimg.rows()-1, 1,
                 offx+xmin, offy+feaimg.rows()-1, 1 );*/
    Matx43d pts( offx+(1.0/scaling)*xmin, offy, 1,
                 offx+(1.0/scaling)*xmax, offy, 1,
                 offx+(1.0/scaling)*xmax, offy+(1.0/scaling)*(feaimg.rows()-1), 1,
                 offx+(1.0/scaling)*xmin, offy+(1.0/scaling)*(feaimg.rows()-1), 1 );
    pts = pts * A1 + Matx43d( bboxoffx, bboxoffy, 0,
                              bboxoffx, bboxoffy, 0,
                              bboxoffx, bboxoffy, 0,
                              bboxoffx, bboxoffy, 0 );

    //fprintf(stderr,"bboxoff=%d,%d off=%d,%d xlim=%g,%g pts=%g,%g\n",bboxoffx,bboxoffy,offx,offy,xmin,xmax,pts(0,0),pts(0,1));

    vector<Point2f> fpgram = { Point2f(pts(0,0),pts(0,1)),
                               Point2f(pts(1,0),pts(1,1)),
                               Point2f(pts(2,0),pts(2,1)),
                               Point2f(pts(3,0),pts(3,1)) };

    if( rotate == 0.0 ) // @todo
    *_fpgram = fpgram;
  }

  /// Compute features ///
  Mat feats;
  //double moment_weight = 1;
  //bool window = true;
  //bool window = false;
  switch( featype ) {
    /*case TEXTFEAT_TYPE_DOTMATRIX:
      tm = high_resolution_clock::now();
      cv::Mat dotmatrix( Image image, double win_size, double shift, int sample_width, int sample_height, double moment_weight, bool window, cv::Mat projbase, cv::Mat projmu );
      feats = dotmatrix( feaimg, slide_span, slide_shift, sample_width, sample_height, moment_weight, window, projbase, projmu );
      if( verbose )
        fprintf(stderr,"dotmatrix time: %d us\n",(int)duration_cast<microseconds>(high_resolution_clock::now()-tm).count());
      break;*/
    case TEXTFEAT_TYPE_RAW:
      if( feaimg.type() == GrayscaleMatteType || feaimg.type() == GrayscaleType ) {
        feats = Mat( feaimg.rows(), feaimg.columns(), CV_8U );
        magick2cvmat8u( feaimg, feats );
      }
      else {
        feats = Mat( feaimg.rows(), feaimg.columns(), CV_8UC3 );
        magick2cvmat8uc3( feaimg, feats );
      }
      break;
  }

  return feats;
}


Mat TextFeatExtractor::preprocessAndExtract( Image& image, float* _slope, float* _slant, vector<Point2f>* _fpgram, vector<Point>* _fcontour ) {
  /// Image cleaning and enhancement ///
  preprocess( image, _fcontour );

  /// Estimation of slope and slant ///
  float vslope = 0.0, vslant = 0.0;
  estimateAngles( image, &vslope, &vslant );
  if( _slope != NULL ) *_slope = vslope;
  if( _slant != NULL ) *_slant = vslant;

  /// Extraction of features ///
  Image feaimg = image;
  Mat feats = extractFeats( feaimg, vslope, vslant, 0, _fpgram );

  return feats;
}
