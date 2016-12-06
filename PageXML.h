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
#include <opencv2/opencv.hpp>
#include <Magick++.h>
#include <libconfig.h++>

#include "TextFeatExtractor.h"

enum PAGEXML_SETTING {
  PAGEXML_SETTING_INDENT = 0,      // "indent"
  PAGEXML_SETTING_PAGENS,          // "pagens"
  PAGEXML_SETTING_GRAYIMG,         // "grayimg"
  PAGEXML_SETTING_EXTENDED_NAMES   // "extended_names"
};

enum PAGEXML_INSERT {
  PAGEXML_INSERT_CHILD = 0,
  PAGEXML_INSERT_NEXTSIB,
  PAGEXML_INSERT_PREVSIB
};

struct NamedImage {
  std::string id;
  std::string name;
  float rotation;
  int direction;
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
    int simplifyIDs();
    bool uniqueIDs();
    std::vector<NamedImage> crop( const char* xpath );
    static std::list<Magick::Coordinate> cvToMagick( const std::vector<cv::Point2f>& points );
    static void stringToPoints( const char* spoints, std::vector<cv::Point2f>& points );
    static void stringToPoints( std::string spoints, std::vector<cv::Point2f>& points );
    static std::string pointsToString( std::vector<cv::Point2f> points, bool rounded = false );
    static std::string pointsToString( std::vector<cv::Point> points );
    static void pointsLimits( std::vector<cv::Point2f>& points, double& xmin, double& xmax, double& ymin, double& ymax );
    static void pointsBBox( std::vector<cv::Point2f>& points, std::vector<cv::Point2f>& bbox );
    static bool isBBox( const std::vector<cv::Point2f>& points );
    std::vector<xmlNodePtr> select( const char* xpath, xmlNodePtr basenode = NULL );
    std::vector<xmlNodePtr> select( std::string xpath, xmlNodePtr basenode = NULL );
    bool getAttr( const xmlNodePtr node,   const char* name,       std::string& value );
    bool getAttr( const char* xpath,       const char* name,       std::string& value );
    bool getAttr( const std::string xpath, const std::string name, std::string& value );
    int setAttr( std::vector<xmlNodePtr> nodes, const char* name,       const char* value );
    int setAttr( xmlNodePtr node,               const char* name,       const char* value );
    int setAttr( const char* xpath,             const char* name,       const char* value );
    int setAttr( const std::string xpath,       const std::string name, const std::string value );
    xmlNodePtr addElem( const char* name,       const char* id,       const xmlNodePtr node,   PAGEXML_INSERT itype = PAGEXML_INSERT_CHILD, bool checkid = false );
    xmlNodePtr addElem( const char* name,       const char* id,       const char* xpath,       PAGEXML_INSERT itype = PAGEXML_INSERT_CHILD, bool checkid = false );
    xmlNodePtr addElem( const std::string name, const std::string id, const std::string xpath, PAGEXML_INSERT itype = PAGEXML_INSERT_CHILD, bool checkid = false );
    int rmElems( const std::vector<xmlNodePtr>& nodes );
    int rmElems( const char* xpath,       xmlNodePtr basenode = NULL );
    int rmElems( const std::string xpath, xmlNodePtr basenode = NULL );
    float getRotation( const xmlNodePtr elem );
    int getReadingDirection( const xmlNodePtr elem );
    float getXheight( const xmlNodePtr node );
    float getXheight( const char* id );
    bool getFpgram( const xmlNodePtr node, std::vector<cv::Point2f>& fpgram );
    bool getPoints( const xmlNodePtr node, std::vector<cv::Point2f>& points );
    xmlNodePtr setTextEquiv( xmlNodePtr node,   const char* text, const char* conf = NULL );
    xmlNodePtr setTextEquiv( const char* xpath, const char* text, const char* conf = NULL );
    char* getBase();
    int write( const char* fname = "-" );
  private:
    bool indent = true;
    bool grayimg = false;
    bool extended_names = false;
    char* pagens = NULL;
    xmlNsPtr rpagens = NULL;
    char* xmldir = NULL;
    char* imgpath = NULL;
    char* imgbase = NULL;
    xmlDocPtr xml = NULL;
    xmlXPathContextPtr context = NULL;
    xmlNodePtr rootnode = NULL;
    Magick::Image pageimg;
    unsigned int width;
    unsigned int height;
    void release();
};

#endif
