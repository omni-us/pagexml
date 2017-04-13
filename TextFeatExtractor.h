/**
 * Header file for the TextFeatExtractor class
 *
 * @version $Revision::       $$Date::             $
 * @copyright Copyright (c) 2016 to the present, Mauricio Villegas <mauvilsa@upv.es>
 */

#ifndef __TEXTFEATEXTRACTOR_H__
#define __TEXTFEATEXTRACTOR_H__

#include <opencv2/opencv.hpp>
#include <Magick++.h>
#include <libconfig.h++>
#include <H5Cpp.h>

#include "intimg.h"
#include "PageXML.h"

enum TEXTFEAT_TYPE {
  TEXTFEAT_TYPE_DOTMATRIX = 0, // "dotm"
  TEXTFEAT_TYPE_RAW            // "raw"
};

enum TEXTFEAT_FORMAT {
  TEXTFEAT_FORMAT_ASCII = 0, // "ascii"
  TEXTFEAT_FORMAT_HTK,       // "htk"
  TEXTFEAT_FORMAT_IMAGE      // "img"
};

enum TEXTFEAT_SETTING {
  TEXTFEAT_SETTING_TYPE = 0,        // "type"
  TEXTFEAT_SETTING_FORMAT,          // "format"
  TEXTFEAT_SETTING_VERBOSE,         // "verbose"
  TEXTFEAT_SETTING_PROCIMGS,        // "procimgs"
  TEXTFEAT_SETTING_STRETCH,         // "stretch"
  TEXTFEAT_SETTING_STRETCH_SATU,    // "stretch_satu"
  TEXTFEAT_SETTING_ENH,             // "enh"
  TEXTFEAT_SETTING_ENH_WIN,         // "enh_win"
  TEXTFEAT_SETTING_ENH_PRM,         // "enh_prm"
  TEXTFEAT_SETTING_ENH_PRM_RAND,    // "enh_prm_rand"
  TEXTFEAT_SETTING_ENH_SLP,         // "enh_slp"
  TEXTFEAT_SETTING_DESLOPE,         // "slope"
  TEXTFEAT_SETTING_DESLANT,         // "slant"
  TEXTFEAT_SETTING_NORMXHEIGHT,     // "normxheight"
  TEXTFEAT_SETTING_NORMHEIGHT,      // "normheight"
  TEXTFEAT_SETTING_MOMENTNORM,      // "momentnorm"
  TEXTFEAT_SETTING_FPGRAM,          // "fpgram"
  TEXTFEAT_SETTING_FCONTOUR,        // "fcontour"
  TEXTFEAT_SETTING_FCONTOUR_DILATE, // "fcontour_dilate"
  TEXTFEAT_SETTING_PADDING,         // "padding"
  TEXTFEAT_SETTING_SLIDE_SHIFT,     // "slide_shift"
  TEXTFEAT_SETTING_SLIDE_SPAN,      // "slide_span"
  TEXTFEAT_SETTING_SAMPLE_WIDTH,    // "sample_width"
  TEXTFEAT_SETTING_SAMPLE_HEIGHT,   // "sample_height"
  TEXTFEAT_SETTING_PROJFILE         // "projfile"
};

class TextFeatExtractor {
  public:
    static const char* featTypes[];
    static const char* formatNames[];
    static const char* settingNames[];
    TextFeatExtractor( const libconfig::Config& config );
    TextFeatExtractor( const char* cfgfile = NULL );
    void loadConf( const libconfig::Config& config );
    void printConf( FILE* file );
    void loadProjection( const char* projfile );
    void preprocess( Magick::Image& image, std::vector<cv::Point>* _fcontour = NULL, bool randomize = false );
    void estimateAngles( Magick::Image& image, float* _slope, float* _slant, float rotate = 0.0 );
    cv::Mat extractFeats( Magick::Image& feaimg, float slope = 0.0, float slant = 0.0, int xheight = 0, std::vector<cv::Point2f>* _fpgram = NULL, bool randomize = false, float rotate = 0.0, int direction = PAGEXML_READ_DIRECTION_LTR );
    cv::Mat preprocessAndExtract( Magick::Image& image, float* _slope = NULL, float* _slant = NULL, std::vector<cv::Point2f>* _fpgram = NULL, std::vector<cv::Point>* _fcontour = NULL );
    bool isImageFormat();
    void print( const cv::Mat& feats, FILE* file = stdout );
    void write( const cv::Mat& feats, const char* fname );
  private:
    int featype = TEXTFEAT_TYPE_DOTMATRIX;
    int format = TEXTFEAT_FORMAT_ASCII;
    bool verbose = false;
    bool procimgs = false;
    bool stretch = true;
    float stretch_satu = 0.0;
    //bool enh = true;
    float enh = 1.0;
    int enh_type = ENH_SAUVOLA;
    int enh_win = 20;
    float enh_slp = 0.5;
    float enh_prm = 0.1;
    float enh_prm_randmin = 0.05;
    float enh_prm_randmax = 0.3;
    float enh3_prm0 = 0.0;
    float enh3_prm2 = 0.0;
    bool deslope = true;
    bool deslant = true;
    float deslant_min = -6.0; // degrees
    float deslant_max = 48.0; // degrees
    float deslant_step = 1.0; // degrees
    int deslant_hsteps = 4;
    float slant_rand = 0.0; // degrees in both directions
    float scale_rand = 0.0; // percent smaller or larger
    int normxheight = 0;
    int normheight = 0;
    bool momentnorm = false;
    bool compute_fpgram = true;
    bool compute_fcontour = true;
    float fcontour_dilate = 4.0;
    int padding = 12;
    float slide_shift = 2.0;
    float slide_span = 20.0;
    int sample_width = 8;
    int sample_height = 32;
    std::string projfile;
    cv::Mat projbase;
    cv::Mat projmu;
};

#endif
