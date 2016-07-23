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

//#include "ConfigProps.h"
#include "intimg.h"

enum FEAT_TYPE {
  FEAT_TYPE_DOTMATRIX = 0, // "dotm"
  FEAT_TYPE_RAW            // "raw"
};

enum FEAT_FORMAT {
  FEAT_FORMAT_ASCII = 0, // "ascii"
  FEAT_FORMAT_HTK,       // "htk"
  FEAT_FORMAT_IMAGE      // "img"
};

enum FEAT_SETTING {
  FEAT_SETTING_TYPE = 0,        // "type"
  FEAT_SETTING_FORMAT,          // "format"
  FEAT_SETTING_VERBOSE,         // "verbose"
  FEAT_SETTING_PROCIMGS,        // "procimgs"
  FEAT_SETTING_STRETCH,         // "stretch"
  FEAT_SETTING_STRETCH_SATU,    // "stretch_satu"
  FEAT_SETTING_ENH,             // "enh"
  FEAT_SETTING_ENH_WIN,         // "enh_win"
  FEAT_SETTING_ENH_PRM,         // "enh_prm"
  FEAT_SETTING_ENH_PRM_RANDMIN, // "enh_prm_randmin"
  FEAT_SETTING_ENH_PRM_RANDMAX, // "enh_prm_randmax"
  FEAT_SETTING_ENH_SLP,         // "enh_slp"
  FEAT_SETTING_SLOPE,           // "slope"
  FEAT_SETTING_SLANT,           // "slant"
  FEAT_SETTING_NORMXHEIGHT,     // "normxheight"
  FEAT_SETTING_NORMHEIGHT,      // "normheight"
  FEAT_SETTING_FPGRAM,          // "fpgram"
  FEAT_SETTING_FCONTOUR,        // "fcontour"
  FEAT_SETTING_PADDING,         // "padding"
  FEAT_SETTING_SLIDE_SHIFT,     // "slide_shift"
  FEAT_SETTING_SLIDE_SPAN,      // "slide_span"
  FEAT_SETTING_SAMPLE_WIDTH,    // "sample_width"
  FEAT_SETTING_SAMPLE_HEIGHT,   // "sample_height"
  FEAT_SETTING_PROJFILE         // "projfile"
};

class TextFeatExtractor {
  public:
    static const char* featTypes[];
    static const char* formatNames[];
    static const char* settingNames[];
    static int parseFeatType( const char* featype );
    static int parseFeatFormat( const char* format );
    static int parseFeatSetting( const char* setting );
    //TextFeatExtractor( const std::vector<ConfigProps>& config = std::vector<ConfigProps>() );
    TextFeatExtractor( const libconfig::Config& config );
    TextFeatExtractor( const char* cfgfile = NULL );
    void loadConf( const libconfig::Config& config );
    void printConf( FILE* file );
    void loadProjection( const char* projfile );
    void preprocess( Magick::Image& image, std::vector<cv::Point>* _fcontour = NULL, bool randomize = false );
    void estimateAngles( Magick::Image& image, float* _slope, float* _slant );
    cv::Mat extractFeats( Magick::Image& feaimg, float slope = 0.0, float slant = 0.0, int xheight = 0, std::vector<cv::Point2f>* _fpgram = NULL, bool randomize = false );
    cv::Mat preprocessAndExtract( Magick::Image& image, float* _slope = NULL, float* _slant = NULL, std::vector<cv::Point2f>* _fpgram = NULL, std::vector<cv::Point>* _fcontour = NULL );
    //cv::Mat extract_old( Magick::Image& image, float* _slope = NULL, float* _slant = NULL, std::vector<cv::Point2f>* _fpgram = NULL, std::vector<cv::Point>* _fcontour = NULL );
    void print( const cv::Mat& feats, FILE* file = stdout );
    void write( const cv::Mat& feats, const char* fname );
  private:
    int featype = FEAT_TYPE_DOTMATRIX;
    int format = FEAT_FORMAT_ASCII;
    //char* magick = NULL;
    bool verbose = false;
    bool procimgs = false;
    bool stretch = true;
    float stretch_satu = 0.0;
    //bool enh = true;
    float enh = 1.0;
    int enh_type = ENH_SAUVOLA;
    int enh_win = 20;
    //float enh_prm = 0.2;
    float enh_slp = 0.5;
    //float enh_prm_randmin = 0.01;
    //float enh_prm_randmax = 0.25;
    float enh_prm = 0.1;
    float enh_prm_randmin = 0.05;
    float enh_prm_randmax = 0.3;
    bool slope = true;
    bool slant = true;
    float slant_min = -6.0; // degrees
    float slant_max = 48.0; // degrees
    float slant_step = 1.0; // degrees
    int slant_hsteps = 4;
    float slant_rand = 4.0; // degrees in both directions
    //float scale_rand = 10.0; // percent smaller or larger
    float scale_rand = 0.0; // percent smaller or larger
    int normxheight = 0;
    int normheight = 0;
    bool compute_fpgram = true;
    bool compute_fcontour = true;
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
