/**
 * Header file for the PageXML class
 *
 * @version $Revision::       $$Date::             $
 * @copyright Copyright (c) 2016 to the present, Mauricio Villegas <mauvilsa@upv.es>
 */

#ifndef __PAGEXML_H__
#define __PAGEXML_H__

#include <vector>

#include <libxml/parser.h>
#include <libxml/xpath.h>
#include <Magick++.h>
#include <libconfig.h++>

#include "TextFeatExtractor.h"

enum PAGEXML_SETTING {
  PAGEXML_SETTING_INDENT = 0,      // "indent"
  PAGEXML_SETTING_PAGENS,          // "pagens"
  //PAGEXML_SETTING_LOADIMG,         // "loadimg"
  PAGEXML_SETTING_GRAYIMG,         // "grayimg"
  PAGEXML_SETTING_EXTENDED_NAME    // "extended_name"
};

struct NamedImage {
  std::string id;
  std::string name;
  Magick::Image image;
};

class PageXML {
  public:
    static const char* settingNames[];
    PageXML( const libconfig::Config& config );
    PageXML( const char* cfgfile = NULL );
    ~PageXML();
    void loadConf( const libconfig::Config& config );
    void printConf( FILE* file );
    void loadXml( const char* fname );
    void loadXml( int fnum );
    void loadImage( const char* fname = NULL );
    std::vector<NamedImage> crop( const char* xpath );
    static std::string pointsToString( std::vector<cv::Point2f> points );
    static std::string pointsToString( std::vector<cv::Point> points );
    int setAttr( const char* xpath, const char* name, const char* value );
    float getXheight( const char* id );
    char* getBase();
    int write( const char* fname = "-" );
  private:
    bool indent = true;
    //bool loadimg = false;
    bool grayimg = false;
    bool extended_name = true;
    char* pagens = NULL;
    char* xmldir = NULL;
    char* imgpath = NULL;
    char* imgbase = NULL;
    xmlDocPtr xml = NULL;
    xmlXPathContextPtr context = NULL;
    Magick::Image pageimg;
    unsigned int width;
    unsigned int height;
    void release();
};

#endif
