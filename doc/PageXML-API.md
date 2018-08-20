# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`define `[`__REUSE_CONTEXT__`](#_page_x_m_l_8cc_1ac9a9b912d159957b6b8712591e950ef4)            | 
`define `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)            | Header file for the [PageXML](#class_page_x_m_l) class
`define `[`throw_runtime_error`](#_page_x_m_l_8h_1a950a67fe0e59f7788788db2c2061d2af)            | 
`enum `[`PAGEXML_SETTING`](#_page_x_m_l_8h_1a5079ef3d3aefc01672107a1737c12993)            | 
`enum `[`PAGEXML_INSERT`](#_page_x_m_l_8h_1adfd6b61039753caee671c2667b7b2b4b)            | 
`enum `[`PAGEXML_READ_DIRECTION`](#_page_x_m_l_8h_1a151afb8ef7c7e05585713fafd180a2ea)            | 
`enum `[`PAGEXML_OVERLAP`](#_page_x_m_l_8h_1a8606ef3ee6c75085c7c5d97b79132c50)            | 
`public regex `[`reXheight`](#_page_x_m_l_8cc_1a726c6cc001ee5d420a795decf8fd680d)`(".*x-height: *([0-9.]+) *px;.*")`            | 
`public regex `[`reRotation`](#_page_x_m_l_8cc_1ace361379b17a512eaf8ef91bc8ee0914)`(".*readingOrientation: *([0-9.]+) *;.*")`            | 
`public regex `[`reDirection`](#_page_x_m_l_8cc_1a3eab4de6fb9cae3e28f0fc041a4da1cb)`(".*readingDirection: *([lrt]t[rlb]) *;.*")`            | 
`public regex `[`reFileExt`](#_page_x_m_l_8cc_1a459740e4dc280acefcffaa5cb8971eac)`("\\.+$")`            | 
`public regex `[`reInvalidBaseChars`](#_page_x_m_l_8cc_1aa7ad44cbc1ef82ed4fcadaec999ed6ad)`(" ")`            | 
`public regex `[`reImagePageNum`](#_page_x_m_l_8cc_1a976a19d24d088777ff392917ede71cf9)`("(.*)\\+)`            | 
`public regex `[`reIsPdf`](#_page_x_m_l_8cc_1a79e508b639cf33c0f2fc6c77f1ebb138)`(".*\\.pdf(\\[[0-9]+\\])*$",std::regex::icase)`            | 
`public void `[`mktemp`](#_page_x_m_l_8cc_1a54bdec4c6dd5a11b008fc79598dfbd64)`(const char * tempbase,char * tempname)`            | Function that creates a temporal file using the mktemp command
`public static std::vector< double > `[`project_2d_to_1d`](#_page_x_m_l_8cc_1aa295be52a9f7d03cb5a745bc6b2550e9)`(std::vector< cv::Point2f > points,cv::Point2f axis,double yoffset)`            | Projects points onto a line defined by a direction and y-offset
`public inline static double `[`angleDiff`](#_page_x_m_l_8cc_1a61fc06d078d73deb50298f47d612eedd)`(double a1,double a2)`            | Computes the difference between two angles [-PI,PI] accounting for the discontinuity
`public inline static double `[`intersection_1d`](#_page_x_m_l_8cc_1a8cb2d5f6e60399cf47f11bb9201fb4dc)`(double & a1,double & a2,double & b1,double & b2)`            | Computes the 1D intersection
`public inline static double `[`IoU_1d`](#_page_x_m_l_8cc_1ac09c1ca85100d59d39f77e7f545eca8d)`(double a1,double a2,double b1,double b2)`            | Computes the 1D intersection over union
`public double `[`withinSegment`](#_page_x_m_l_8cc_1a01aee68a0af5ee992c2f6b499b4a5558)`(cv::Point2f segm_start,cv::Point2f segm_end,cv::Point2f point)`            | Checks if a point is within a line segment
`class `[`PageXML`](#class_page_x_m_l) | 
`struct `[`NamedImage`](#struct_named_image) | 

## Members

#### `define `[`__REUSE_CONTEXT__`](#_page_x_m_l_8cc_1ac9a9b912d159957b6b8712591e950ef4) 

#### `define `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80) 

Header file for the [PageXML](#class_page_x_m_l) class

Version2018.08.17

Copyright (c) 2016-present, Mauricio Villegas [mauricio_ville@yahoo.com](mailto:mauricio_ville@yahoo.com)  MIT License

#### `define `[`throw_runtime_error`](#_page_x_m_l_8h_1a950a67fe0e59f7788788db2c2061d2af) 

#### `enum `[`PAGEXML_SETTING`](#_page_x_m_l_8h_1a5079ef3d3aefc01672107a1737c12993) 

 Values                         | Descriptions                                
--------------------------------|---------------------------------------------
PAGEXML_SETTING_INDENT            | 
PAGEXML_SETTING_PAGENS            | 
PAGEXML_SETTING_GRAYIMG            | 

#### `enum `[`PAGEXML_INSERT`](#_page_x_m_l_8h_1adfd6b61039753caee671c2667b7b2b4b) 

 Values                         | Descriptions                                
--------------------------------|---------------------------------------------
PAGEXML_INSERT_APPEND            | 
PAGEXML_INSERT_PREPEND            | 
PAGEXML_INSERT_NEXTSIB            | 
PAGEXML_INSERT_PREVSIB            | 

#### `enum `[`PAGEXML_READ_DIRECTION`](#_page_x_m_l_8h_1a151afb8ef7c7e05585713fafd180a2ea) 

 Values                         | Descriptions                                
--------------------------------|---------------------------------------------
PAGEXML_READ_DIRECTION_LTR            | 
PAGEXML_READ_DIRECTION_RTL            | 
PAGEXML_READ_DIRECTION_TTB            | 
PAGEXML_READ_DIRECTION_BTT            | 

#### `enum `[`PAGEXML_OVERLAP`](#_page_x_m_l_8h_1a8606ef3ee6c75085c7c5d97b79132c50) 

 Values                         | Descriptions                                
--------------------------------|---------------------------------------------
PAGEXML_OVERLAP_COORDS_IOU            | 
PAGEXML_OVERLAP_COORDS_ISECT            | 
PAGEXML_OVERLAP_COORDS_IWA            | 
PAGEXML_OVERLAP_BASELINE_IWA            | 
PAGEXML_OVERLAP_COORDS_BASELINE_IWA            | 

#### `public regex `[`reXheight`](#_page_x_m_l_8cc_1a726c6cc001ee5d420a795decf8fd680d)`(".*x-height: *([0-9.]+) *px;.*")` 

#### `public regex `[`reRotation`](#_page_x_m_l_8cc_1ace361379b17a512eaf8ef91bc8ee0914)`(".*readingOrientation: *([0-9.]+) *;.*")` 

#### `public regex `[`reDirection`](#_page_x_m_l_8cc_1a3eab4de6fb9cae3e28f0fc041a4da1cb)`(".*readingDirection: *([lrt]t[rlb]) *;.*")` 

#### `public regex `[`reFileExt`](#_page_x_m_l_8cc_1a459740e4dc280acefcffaa5cb8971eac)`("\\.+$")` 

#### `public regex `[`reInvalidBaseChars`](#_page_x_m_l_8cc_1aa7ad44cbc1ef82ed4fcadaec999ed6ad)`(" ")` 

#### `public regex `[`reImagePageNum`](#_page_x_m_l_8cc_1a976a19d24d088777ff392917ede71cf9)`("(.*)\\+)` 

#### `public regex `[`reIsPdf`](#_page_x_m_l_8cc_1a79e508b639cf33c0f2fc6c77f1ebb138)`(".*\\.pdf(\\[[0-9]+\\])*$",std::regex::icase)` 

#### `public void `[`mktemp`](#_page_x_m_l_8cc_1a54bdec4c6dd5a11b008fc79598dfbd64)`(const char * tempbase,char * tempname)` 

Function that creates a temporal file using the mktemp command

#### Parameters
* `tempbase` The mktemp template to use, including at least 3 consecutive X.

#### `public static std::vector< double > `[`project_2d_to_1d`](#_page_x_m_l_8cc_1aa295be52a9f7d03cb5a745bc6b2550e9)`(std::vector< cv::Point2f > points,cv::Point2f axis,double yoffset)` 

Projects points onto a line defined by a direction and y-offset

#### `public inline static double `[`angleDiff`](#_page_x_m_l_8cc_1a61fc06d078d73deb50298f47d612eedd)`(double a1,double a2)` 

Computes the difference between two angles [-PI,PI] accounting for the discontinuity

#### `public inline static double `[`intersection_1d`](#_page_x_m_l_8cc_1a8cb2d5f6e60399cf47f11bb9201fb4dc)`(double & a1,double & a2,double & b1,double & b2)` 

Computes the 1D intersection

#### `public inline static double `[`IoU_1d`](#_page_x_m_l_8cc_1ac09c1ca85100d59d39f77e7f545eca8d)`(double a1,double a2,double b1,double b2)` 

Computes the 1D intersection over union

#### `public double `[`withinSegment`](#_page_x_m_l_8cc_1a01aee68a0af5ee992c2f6b499b4a5558)`(cv::Point2f segm_start,cv::Point2f segm_end,cv::Point2f point)` 

Checks if a point is within a line segment

#### Parameters
* `segm_start` Point for begining of segment. 

* `segm_end` Point for end of segment. 

* `point` Point to check withiness. 

#### Returns
0 if within segment, +1 if outside but aligned to the right, -1 if outside but aligned to the left, otherwise NaN.

# class `PageXML` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`~PageXML`](#class_page_x_m_l_1accc94a5c0375b71fd2f058abc04ca25e)`()` | [PageXML](#class_page_x_m_l) object destructor.
`public  `[`PageXML`](#class_page_x_m_l_1a86b2558ba9790fed8ee2a78cbb8f0ed0)`()` | Constructors ///.
`public  `[`PageXML`](#class_page_x_m_l_1a95475e2d030caccd682493ee8f4b7c30)`(const char * fname)` | [PageXML](#class_page_x_m_l) constructor that receives a file name to load.
`public void `[`printConf`](#class_page_x_m_l_1a2f243e564f59e0e86be34fb3641526e0)`(FILE * file)` | Configuration ///.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`newXml`](#class_page_x_m_l_1a95f40947e6da8415578a4dcaf7a8eea3)`(const char * creator,const char * image,const int imgW,const int imgH)` | Loaders ///.
`public void `[`loadXml`](#class_page_x_m_l_1a1598083e01ebff5727d248a8ac150c6d)`(const char * fname)` | Loads a Page XML from a file.
`public void `[`loadXml`](#class_page_x_m_l_1a6c06d9d821dfe96ce0bf140e639f5978)`(int fnum,bool prevfree)` | Loads a Page XML from an input stream.
`public void `[`loadXmlString`](#class_page_x_m_l_1acd4f674900ec7351e4f31b5fa3d66a09)`(const char * xml_string)` | Loads a Page XML from a string.
`public void `[`loadImage`](#class_page_x_m_l_1acc541aed93c06fdfeec29ad217f217a8)`(int pagenum,const char * fname,const bool resize_coords,int density)` | Loads an image for a Page in the XML.
`public void `[`loadImage`](#class_page_x_m_l_1a74593bb0b4ca5e266dfc5650ca5009d0)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * fname,const bool resize_coords,int density)` | 
`public void `[`loadImages`](#class_page_x_m_l_1a8c3f3f964ef4039094e0a81a73f679a0)`(const bool resize_coords,const int density)` | 
`public int `[`simplifyIDs`](#class_page_x_m_l_1a5d3b4a59cecbf6fdf8c84f806a7648f0)`()` | Simplifies IDs by removing imgbase prefixes and replaces invalid characters with _.
`public void `[`relativizeImageFilename`](#class_page_x_m_l_1a3c43349d7cff78cea6d1ba7b01f023b3)`(const char * xml_path)` | Modifies imageFilename to be a relative path w.r.t. given xml path. Currently just checks prefix directories and removes it.
`public std::vector< std::string > `[`getImageBases`](#class_page_x_m_l_1a3c43f4e51877f674f29af7a421fa973b)`()` | Gets image bases for all pages in xml.
`public bool `[`areIDsUnique`](#class_page_x_m_l_1aeb8f1e60e4e2521c2bb50fe495327648)`()` | Verifies that all IDs in page are unique.
`public std::string `[`getNodeName`](#class_page_x_m_l_1a8e8ded73daa9edf93b02d75bac16b9de)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` base_node)` | Gets the name of the given node.
`public std::vector< `[`NamedImage`](#struct_named_image)` > `[`crop`](#class_page_x_m_l_1a3264214ef4bc3ea7d5706b33440c57a0)`(const char * xpath,cv::Point2f * margin,bool opaque_coords,const char * transp_xpath,const char * base_xpath)` | Crops images using its Coords polygon, regions outside the polygon are set to transparent.
`public int `[`count`](#class_page_x_m_l_1ad4fa4aef07f44a011f154cee73aa6002)`(const char * xpath,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` basenode)` | Returns number of matched nodes for a given xpath.
`public int `[`count`](#class_page_x_m_l_1a9017068318dd91aead4d39a472ee2a8d)`(std::string xpath,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` basenode)` | 
`public std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > `[`select`](#class_page_x_m_l_1a562f6a2af80c35e01a9cfa36afc10435)`(const char * xpath,const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` basenode)` | Selects nodes given an xpath.
`public std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > `[`select`](#class_page_x_m_l_1ad1fd441a90b31c4900bb9896185a177f)`(std::string xpath,const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` | 
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`selectNth`](#class_page_x_m_l_1ab23937e1762c713c2ca2636de8d1075f)`(const char * xpath,unsigned num,const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` | Selects the n-th node that matches an xpath.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`selectNth`](#class_page_x_m_l_1a20ceffc31be1dd670069e57012e5202d)`(std::string xpath,unsigned num,const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` | 
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`selectByID`](#class_page_x_m_l_1ace787087add3c5f3016ec837553d48b5)`(const char * id,const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` | Selects an element with a given ID.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`closest`](#class_page_x_m_l_1a089e2ca706141bf750b301fd34595fc1)`(const char * name,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` | Selects closest node of a given name.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`parent`](#class_page_x_m_l_1a8ac32174f32b120caf595ec3a82e57d1)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` | Returns the parent of a node.
`public std::string `[`getValue`](#class_page_x_m_l_1a806731e1825cfbfa406ddf3e6978d747)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` | Retrieves a node value.
`public std::string `[`getAttr`](#class_page_x_m_l_1a23e16f7c70950b4fe990b8c22a2e1ce5)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * name)` | Gets an attribute value from an xml node.
`public std::string `[`getAttr`](#class_page_x_m_l_1abef00c0a3b59143989b8d29beaeb14bf)`(const char * xpath,const char * name)` | Gets an attribute value for a given xpath.
`public std::string `[`getAttr`](#class_page_x_m_l_1a057bb3cecf33b3cd2e621d56095a4716)`(const std::string xpath,const std::string name)` | 
`public int `[`setAttr`](#class_page_x_m_l_1ada5a3f0e91615340782afe1eea87c23d)`(std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > nodes,const char * name,const char * value)` | 
`public int `[`setAttr`](#class_page_x_m_l_1abaa5b2ad59b0769bb8cff58a53b04231)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * name,const char * value)` | Adds or modifies (if already exists) an attribute for a given node.
`public int `[`setAttr`](#class_page_x_m_l_1a8cc6e9bffff7951aa5db47af47642601)`(const char * xpath,const char * name,const char * value)` | Adds or modifies (if already exists) an attribute for a given xpath.
`public int `[`setAttr`](#class_page_x_m_l_1a8d1d681d5b986527265ff07c757a2b3b)`(const std::string xpath,const std::string name,const std::string value)` | 
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`insertElem`](#class_page_x_m_l_1ab0e8796f7920a2fc3ff1a490b85b6b8b)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` elem,const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,`[`PAGEXML_INSERT`](#_page_x_m_l_8h_1adfd6b61039753caee671c2667b7b2b4b)` itype)` | Inserts an element relative to a given node.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addElem`](#class_page_x_m_l_1a2dd9a0a6cfeb68a91c005740dd6ce315)`(const char * name,const char * id,const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,`[`PAGEXML_INSERT`](#_page_x_m_l_8h_1adfd6b61039753caee671c2667b7b2b4b)` itype,bool checkid)` | Creates a new element and adds it relative to a given node.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addElem`](#class_page_x_m_l_1a4b218c9cddda9763bdd3f65d3074d5f7)`(const char * name,const char * id,const char * xpath,`[`PAGEXML_INSERT`](#_page_x_m_l_8h_1adfd6b61039753caee671c2667b7b2b4b)` itype,bool checkid)` | Creates a new element and adds it relative to a given xpath.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addElem`](#class_page_x_m_l_1abbbf302357d6016ffde3a2b859fa1f93)`(const std::string name,const std::string id,const std::string xpath,`[`PAGEXML_INSERT`](#_page_x_m_l_8h_1adfd6b61039753caee671c2667b7b2b4b)` itype,bool checkid)` | 
`public void `[`rmElem`](#class_page_x_m_l_1ad3e1cc3040a7aef670d64fac0e2e82d8)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` | Removes the given element.
`public int `[`rmElems`](#class_page_x_m_l_1a58b3870ad811accb8b91a433796fbf6f)`(const std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > & nodes)` | 
`public int `[`rmElems`](#class_page_x_m_l_1a47752b5ea364d374008f3f04b984a0cb)`(const char * xpath,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` basenode)` | Remove the elements that match a given xpath.
`public int `[`rmElems`](#class_page_x_m_l_1aa1c5ac267af4aeda9fea84eada6e91db)`(const std::string xpath,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` basenode)` | 
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`moveElem`](#class_page_x_m_l_1af214054f7b648086704f7cc0bd3b51e1)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` elem,const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,`[`PAGEXML_INSERT`](#_page_x_m_l_8h_1adfd6b61039753caee671c2667b7b2b4b)` itype)` | Unlink an element and add it relative to a given node.
`public int `[`moveElems`](#class_page_x_m_l_1ac6320b747e78baa3d2f5753086e54189)`(const std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > & elems,const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,`[`PAGEXML_INSERT`](#_page_x_m_l_8h_1adfd6b61039753caee671c2667b7b2b4b)` itype)` | Unlink elements and add them relative to a given node.
`public void `[`setRotation`](#class_page_x_m_l_1afc92cad64293df78c84bc7d8c899cf6f)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` elem,const float rotation)` | Sets the rotation angle to a TextRegion node.
`public void `[`setReadingDirection`](#class_page_x_m_l_1af1eef0ce8e1ff941b79430db6802e51a)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` elem,`[`PAGEXML_READ_DIRECTION`](#_page_x_m_l_8h_1a151afb8ef7c7e05585713fafd180a2ea)` direction)` | Sets the reading direction to a TextRegion node.
`public double `[`getBaselineOrientation`](#class_page_x_m_l_1a01d20d4333c5011f80bf83fe246ac76b)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` elem)` | Gets the (average) baseline orientation angle in radians of a given text line.
`public double `[`getBaselineOrientation`](#class_page_x_m_l_1afe1e54530f0f34624339ebd3fc6aae49)`(std::vector< cv::Point2f > points)` | Gets the (average) baseline orientation angle in radians of a given baseline.
`public double `[`getBaselineLength`](#class_page_x_m_l_1af10f6f194ad7eed3f9924544b54e1c09)`(std::vector< cv::Point2f > points)` | Gets the baseline length.
`public double `[`getRotation`](#class_page_x_m_l_1a6e68136a69dd82168bbc28c64bff45e4)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` elem)` | Retrieves the rotation angle for a given TextLine or TextRegion node.
`public int `[`getReadingDirection`](#class_page_x_m_l_1acc2adc9d4408836ea87d8056e2d522f6)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` elem)` | Retrieves the reading direction for a given TextLine or TextRegion node.
`public float `[`getXheight`](#class_page_x_m_l_1a6d7cd4ada93f19226e3723d6c41a9ebf)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` | Retrieves the x-height for a given TextLine node.
`public float `[`getXheight`](#class_page_x_m_l_1a401b8196ba181dec3fa5d76eb9c6e585)`(const char * id)` | Retrieves the x-height for a given TextLine id.
`public std::vector< cv::Point2f > `[`getFpgram`](#class_page_x_m_l_1a0425df4d97b66a7f259cfb1fae847667)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` | Retrieves the features parallelogram (Property[="fpgram"]/) for a given node.
`public std::vector< cv::Point2f > `[`getPoints`](#class_page_x_m_l_1aba7be6cf9e66f1395c84f0880ca2a069)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * xpath)` | Retrieves and parses the Coords/ for a given base node.
`public std::vector< std::vector< cv::Point2f > > `[`getPoints`](#class_page_x_m_l_1a41e062ef2c08e4c3212c39d4ec48b2fa)`(const std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > nodes,const char * xpath)` | Retrieves and parses the Coords/ for a given list of base nodes.
`public std::string `[`getTextEquiv`](#class_page_x_m_l_1aede7f24b63a9ca5acfbfe21e9343b977)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * xpath,const char * separator)` | Retrieves the concatenated TextEquivs for a given root node and xpath.
`public void `[`processStart`](#class_page_x_m_l_1a3eeffa37a2ace0dc732405e81cb49e4d)`(const char * tool,const char * ref)` | Starts a process in the Page XML.
`public void `[`processEnd`](#class_page_x_m_l_1a29d780f46c1f14b241f48665d835394c)`()` | Ends the running process in the Page XML.
`public void `[`updateLastChange`](#class_page_x_m_l_1a99bc8c45fae21207bb608e69609dedcd)`()` | Updates the last change time stamp.
`public std::string `[`getPropertyValue`](#class_page_x_m_l_1ab4d79c28bc94086d1d379f0ea73ff899)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * key)` | Retrieves a Property value.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setProperty`](#class_page_x_m_l_1af6e80d30313f63054228fcb15305db31)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * key,const char * val,const double * _conf)` | Sets a Property to a given node.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setProperty`](#class_page_x_m_l_1a82ffe7a5366736034a3e4514b43ab389)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * key,const double val,const double * _conf)` | Sets a Property to a given node.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setTextEquiv`](#class_page_x_m_l_1a65f380acfc400de2a6dc59eb1ee22904)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * text,const double * _conf)` | Adds or modifies (if already exists) the TextEquiv for a given node.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setTextEquiv`](#class_page_x_m_l_1ae7938084955a0668bc44f24307ad77ba)`(const char * xpath,const char * text,const double * _conf)` | Adds or modifies (if already exists) the TextEquiv for a given xpath.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setCoords`](#class_page_x_m_l_1a8d92328ba656b8e8e847bf2ad3607a46)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const std::vector< cv::Point2f > & points,const double * _conf)` | 
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setCoords`](#class_page_x_m_l_1a626847a8aac3c4bc650d0b27f3ce042b)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const std::vector< cv::Point > & points,const double * _conf)` | 
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setCoords`](#class_page_x_m_l_1a1038c674a0522759ea3004bac9cac5f2)`(const char * xpath,const std::vector< cv::Point2f > & points,const double * _conf)` | 
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setCoordsBBox`](#class_page_x_m_l_1ac42051db4e4f1feb754401e78f5cb53d)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,double xmin,double ymin,double width,double height,const double * _conf,bool subone)` | Adds or modifies (if already exists) the Coords as a bounding box for a given node.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setBaseline`](#class_page_x_m_l_1a2a85dc0b7eb35ac29780551a642a3e51)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const std::vector< cv::Point2f > & points,const double * _conf)` | 
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setBaseline`](#class_page_x_m_l_1a12a577c21cf6109f30843336bbdaba8d)`(const char * xpath,const std::vector< cv::Point2f > & points,const double * _conf)` | 
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setBaseline`](#class_page_x_m_l_1a489cf14031d07454f538a048e4b48c03)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,double x1,double y1,double x2,double y2,const double * _conf)` | Adds or modifies (if already exists) a two point Baseline for a given node.
`public bool `[`intersection`](#class_page_x_m_l_1a37da0ed1fb708b374e7d83e6b22cbb23)`(cv::Point2f line1_point1,cv::Point2f line1_point2,cv::Point2f line2_point1,cv::Point2f line2_point2,cv::Point2f & _ipoint)` | Finds the intersection point between two lines defined by pairs of points or returns false if no intersection
`public bool `[`isPolystripe`](#class_page_x_m_l_1a61c1b6597c7bcf7b65dc195e95ef7ab4)`(std::vector< cv::Point2f > coords,std::vector< cv::Point2f > baseline,double * height,double * offset)` | Checks whether Coords is a poly-stripe for its corresponding baseline.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setPolystripe`](#class_page_x_m_l_1ab97470a0132a3e497c80f26e061aba28)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,double height,double offset,bool offset_check)` | Sets the Coords of a TextLine as a poly-stripe of the baseline.
`public int `[`getPageNumber`](#class_page_x_m_l_1ae660a692143a9983406bba434037e78c)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` | Gets the page number for the given node.
`public void `[`setPageImageOrientation`](#class_page_x_m_l_1a7f89e6da35429f37f6d887b36510772c)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,int angle,const double * _conf)` | Sets the image orientation for the given Page node.
`public void `[`setPageImageOrientation`](#class_page_x_m_l_1a94c03640c38f7ddd743b9c0423c71342)`(int pagenum,int angle,const double * _conf)` | 
`public int `[`getPageImageOrientation`](#class_page_x_m_l_1a3f776930d7d1be6239497c49f6ea6b9a)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` | Gets the image orientation for the given node.
`public int `[`getPageImageOrientation`](#class_page_x_m_l_1acd1a1b7bbe14a6c8e14e3ef5afccd3cf)`(int pagenum)` | 
`public unsigned int `[`getPageWidth`](#class_page_x_m_l_1a7746613d3800267f27d7bef2240ec827)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` | Returns the width of a page.
`public unsigned int `[`getPageWidth`](#class_page_x_m_l_1aa1b7155d7ae5b37710310b7891d1c314)`(int pagenum)` | 
`public unsigned int `[`getPageHeight`](#class_page_x_m_l_1ab96562c1fe4d95706778507ed2e8b57d)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` | Returns the height of a page.
`public unsigned int `[`getPageHeight`](#class_page_x_m_l_1a80e90205b325157f3d1fd680f7ebc108)`(int pagenum)` | 
`public std::vector< cv::Size2i > `[`getPagesSize`](#class_page_x_m_l_1a525354fa982782061b40718607b960dd)`(std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > pages)` | Retrieves pages size.
`public std::vector< cv::Size2i > `[`getPagesSize`](#class_page_x_m_l_1aab0456c928c85b694387acf75339c02f)`(const char * xpath)` | 
`public int `[`resize`](#class_page_x_m_l_1a81f6aa2af3574985f268959662ac4c2b)`(std::vector< cv::Size2i > sizes,std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > pages,bool check_aspect_ratio)` | Resizes pages and all respective coordinates.
`public int `[`resize`](#class_page_x_m_l_1a8b24748e08ccb010eb709a9d91c711cc)`(std::vector< cv::Size2i > sizes,const char * xpath,bool check_aspect_ratio)` | Resizes pages and all respective coordinates.
`public int `[`resize`](#class_page_x_m_l_1ae9772185b88e2e12e26025effc2c39c7)`(cv::Size2i size,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` page,bool check_aspect_ratio)` | Resizes a page and all respective coordinates.
`public int `[`resize`](#class_page_x_m_l_1a06f171653bd8d50c03ed153523e24fc5)`(double fact,const char * xpath)` | Resizes a page and all respective coordinates.
`public void `[`setPageImageFilename`](#class_page_x_m_l_1a66d14b834c2ff1e162ddc268d92e9318)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * image)` | Sets the imageFilename of a page.
`public void `[`setPageImageFilename`](#class_page_x_m_l_1a1f6225549414316c7b42d466f37ea9ae)`(int pagenum,const char * image)` | 
`public std::string `[`getPageImageFilename`](#class_page_x_m_l_1ab6670ff942eeb850d64cb87a9932be58)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` | Returns the imageFilename of a page.
`public std::string `[`getPageImageFilename`](#class_page_x_m_l_1ac6fe17760af6634bf781b82831f6145b)`(int pagenum)` | 
`public `[`PageImage`](#_page_x_m_l_8h_1ac50a58a5d388d3de0e068f1ac3f90cb9)` `[`getPageImage`](#class_page_x_m_l_1acc09b01d19dfafb3ccd43b0099313045)`(int pagenum)` | Returns the image for the given page.
`public `[`PageImage`](#_page_x_m_l_8h_1ac50a58a5d388d3de0e068f1ac3f90cb9)` `[`getPageImage`](#class_page_x_m_l_1abf54fa39f33ca21661e87528136b00b6)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` | 
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addGlyph`](#class_page_x_m_l_1a0814aa1518e897289014c38c441a8bf1)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * id,const char * before_id)` | Adds a Glyph to a given node.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addGlyph`](#class_page_x_m_l_1acaa1832064f9fadb99580bce37ff2a61)`(const char * xpath,const char * id,const char * before_id)` | Adds a Glyph to a given xpath.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addWord`](#class_page_x_m_l_1ab865d14cd40a7898f7612ca3e1cb507f)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * id,const char * before_id)` | Adds a Word to a given node.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addWord`](#class_page_x_m_l_1a35b83528a5e85c0f8e5fe91e6603ea7f)`(const char * xpath,const char * id,const char * before_id)` | Adds a Word to a given xpath.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addTextLine`](#class_page_x_m_l_1a990faea859827afc6ed10243f1c347fb)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * id,const char * before_id)` | Adds a TextLine to a given node.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addTextLine`](#class_page_x_m_l_1a52798d2245ba8af0afb948b31b311243)`(const char * xpath,const char * id,const char * before_id)` | Adds a TextLine to a given xpath.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addTextRegion`](#class_page_x_m_l_1af335dbda4b11ddc8078df72ffca38f7c)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * id,const char * before_id,bool prepend)` | Adds a TextRegion to a given node.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addTextRegion`](#class_page_x_m_l_1afd831d3d6a2a33cc53feae4e4c3b4662)`(const char * xpath,const char * id,const char * before_id,bool prepend)` | Adds new TextRegion to a given xpath.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addPage`](#class_page_x_m_l_1a99fbe6075faea2c881f8a5bbb2d68f0e)`(const char * image,const int imgW,const int imgH,const char * id,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` before_node)` | Adds a Page to the PcGts node.
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addPage`](#class_page_x_m_l_1ad7c0aed4a410245017724a7cefc40654)`(std::string image,const int imgW,const int imgH,const char * id,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` before_node)` | Adds a Page to the PcGts node.
`public int `[`write`](#class_page_x_m_l_1a3de4da73170e0d402131603da0314ecf)`(const char * fname)` | Output ///.
`public std::string `[`toString`](#class_page_x_m_l_1a32549b2df27c0b2308d2ad7437cf328f)`()` | Creates a string representation of the Page XML.
`public OGRMultiPolygon * `[`pointsToOGRpolygon`](#class_page_x_m_l_1a8c9648fe45b6f8787f72a426b2b21efd)`(std::vector< cv::Point2f > points)` | Converts Coords to an OGRMultiPolygon.
`public std::vector< OGRMultiPolygon * > `[`pointsToOGRpolygons`](#class_page_x_m_l_1a0824036bc27ae4707329665fb2d8c422)`(std::vector< std::vector< cv::Point2f > > points)` | Converts Coords to OGRMultiPolygons.
`public OGRMultiPolygon * `[`getOGRpolygon`](#class_page_x_m_l_1a87274fd138a85857892a1de1f177e8d2)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * xpath)` | Gets an element's Coords as an OGRMultiPolygon.
`public std::vector< OGRMultiPolygon * > `[`getOGRpolygons`](#class_page_x_m_l_1a3fdacaecdb7f703513f53b25b5907732)`(std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > nodes,const char * xpath)` | Gets elements' Coords as OGRMultiPolygons.
`public OGRMultiPolygon * `[`getUnionOGRpolygon`](#class_page_x_m_l_1a281c42635101e469e08fea5b8ec03906)`(std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > nodes,const char * xpath)` | Gets the union of Coords elements as a OGRMultiPolygon.
`public double `[`getOGRpolygonArea`](#class_page_x_m_l_1a64ebd377c84d7a93636f266617173f48)`(OGRMultiPolygon * poly)` | Gets the area of a OGRMultiPolygon.
`public OGRMultiLineString * `[`getOGRpolyline`](#class_page_x_m_l_1a1ee918e01bb6529a44d605c7256c69a6)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * xpath)` | Gets the element's Baseline as an OGRMultiLineString.
`public double `[`computeIntersectFactor`](#class_page_x_m_l_1a14235c2d307d8b6c2ede5fba074ae6b4)`(OGRMultiPolygon * poly1,OGRMultiPolygon * poly2)` | Computes the intersection factor of one polygon over another.
`public double `[`computeIntersectFactor`](#class_page_x_m_l_1a013c3823c3f6c5ceefb43cb8f3205490)`(OGRMultiLineString * poly1,OGRMultiPolygon * poly2)` | Computes the intersection factor of one polyline over polygon.
`public double `[`computeIoU`](#class_page_x_m_l_1a17808b4a1ddc73d3678c6441c5d44b83)`(OGRMultiPolygon * poly1,OGRMultiPolygon * poly2)` | Computes the intersection over union (IoU) of two polygons.
`public std::vector< double > `[`computeIoUs`](#class_page_x_m_l_1aceff17e141c37b9e39fed30fe67c7379)`(OGRMultiPolygon * poly,std::vector< OGRMultiPolygon * > polys)` | Computes the intersection over unions (IoU) of polygons.
`public double `[`computeIntersectionPercentage`](#class_page_x_m_l_1a3c3bf48e2cf7496a07790253384d1008)`(OGRMultiPolygon * poly1,OGRMultiPolygon * poly2)` | Computes the intersection percentage of one polygon with respect to another polygons.
`public std::vector< double > `[`computeIntersectionPercentages`](#class_page_x_m_l_1a465631113aa581de9c9aa2ba4d780716)`(OGRMultiPolygon * poly,std::vector< OGRMultiPolygon * > polys)` | Computes the intersection percentage of one polygon with respect to other polygons.
`public std::vector< double > `[`computeAreas`](#class_page_x_m_l_1a00b39565e78cad9a8b4abceb106a105c)`(std::vector< OGRMultiPolygon * > polys)` | Computes the areas for given polygons.
`public std::vector< double > `[`computeCoordsIntersectionsWeightedByArea`](#class_page_x_m_l_1aaac21cae37920f6707f511d4300fb5d4)`(OGRMultiPolygon * poly,std::vector< OGRMultiPolygon * > polys,std::vector< double > areas)` | Computes polygon-polygon intersections weighted by area.
`public std::vector< double > `[`computeBaselineIntersectionsWeightedByArea`](#class_page_x_m_l_1a4c30956a60ac8c6149486029e3b4eb09)`(OGRMultiLineString * poly,std::vector< OGRMultiPolygon * > polys,std::vector< double > areas)` | Computes line-polygon intersections weighted by area.
`public std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > `[`selectByOverlap`](#class_page_x_m_l_1a3718a39284bb9e947e19af32b75a00cb)`(std::vector< cv::Point2f > points,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` page,const char * xpath,double overlap_thr,`[`PAGEXML_OVERLAP`](#_page_x_m_l_8h_1a8606ef3ee6c75085c7c5d97b79132c50)` overlap_type)` | Selects elements based on overlap to a polygon.
`public std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > `[`selectByOverlap`](#class_page_x_m_l_1a5f355663308e4f139495d06015a4854f)`(std::vector< cv::Point2f > points,int pagenum,const char * xpath,double overlap_thr,`[`PAGEXML_OVERLAP`](#_page_x_m_l_8h_1a8606ef3ee6c75085c7c5d97b79132c50)` overlap_type)` | Selects elements based on overlap to a polygon.
`public int `[`copyTextLinesAssignByOverlap`](#class_page_x_m_l_1ae4b049403a387f9455bc0cc3026a7b76)`(`[`PageXML`](#class_page_x_m_l)` & pageFrom,`[`PAGEXML_OVERLAP`](#_page_x_m_l_8h_1a8606ef3ee6c75085c7c5d97b79132c50)` overlap_type,double overlap_fact)` | Copies TextLines from one page xml to another assigning to regions based on overlap.
`public int `[`testTextLineContinuation`](#class_page_x_m_l_1a508d158670341a3fc48ae03918f1b65b)`(std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > lines,std::vector< std::vector< int > > & _line_group_order,std::vector< double > & _line_group_score,double cfg_max_angle_diff,double cfg_max_horiz_iou,double cfg_min_prolong_fact,bool fake_baseline)` | Tests for text line continuation (requires single segment polystripe).
`public std::vector< int > `[`getTextLinesReadingOrder`](#class_page_x_m_l_1a625fb5d653053410316f8c7a5f741c3e)`(std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > lines,double cfg_max_angle_diff,double cfg_max_horiz_iou,double cfg_min_prolong_fact,bool fake_baseline)` | Gets the reading order for a set of text lines (requires single segment polystripe).
`public xmlDocPtr `[`getDocPtr`](#class_page_x_m_l_1a279bbf7b7641aa329f9fd5607cdde52c)`()` | Returns the XML document pointer.

## Members

#### `public  `[`~PageXML`](#class_page_x_m_l_1accc94a5c0375b71fd2f058abc04ca25e)`()` 

[PageXML](#class_page_x_m_l) object destructor.

#### `public  `[`PageXML`](#class_page_x_m_l_1a86b2558ba9790fed8ee2a78cbb8f0ed0)`()` 

Constructors ///.

#### `public  `[`PageXML`](#class_page_x_m_l_1a95475e2d030caccd682493ee8f4b7c30)`(const char * fname)` 

[PageXML](#class_page_x_m_l) constructor that receives a file name to load.

#### Parameters
* `fname` File name of the XML file to read.

#### `public void `[`printConf`](#class_page_x_m_l_1a2f243e564f59e0e86be34fb3641526e0)`(FILE * file)` 

Configuration ///.

Prints the current configuration.

#### Parameters
* `file` File to print to.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`newXml`](#class_page_x_m_l_1a95f40947e6da8415578a4dcaf7a8eea3)`(const char * creator,const char * image,const int imgW,const int imgH)` 

Loaders ///.

Creates a new Page XML.

#### Parameters
* `creator` Info about tool creating the XML. 

* `image` Path to the image file. 

* `imgW` Width of image. 

* `imgH` Height of image.

#### `public void `[`loadXml`](#class_page_x_m_l_1a1598083e01ebff5727d248a8ac150c6d)`(const char * fname)` 

Loads a Page XML from a file.

#### Parameters
* `fname` File name of the XML file to read.

#### `public void `[`loadXml`](#class_page_x_m_l_1a6c06d9d821dfe96ce0bf140e639f5978)`(int fnum,bool prevfree)` 

Loads a Page XML from an input stream.

#### Parameters
* `fnum` File number from where to read the XML file. 

* `prevfree` Whether to release resources before loading.

#### `public void `[`loadXmlString`](#class_page_x_m_l_1acd4f674900ec7351e4f31b5fa3d66a09)`(const char * xml_string)` 

Loads a Page XML from a string.

#### Parameters
* `xml_string` The XML content.

#### `public void `[`loadImage`](#class_page_x_m_l_1acc541aed93c06fdfeec29ad217f217a8)`(int pagenum,const char * fname,const bool resize_coords,int density)` 

Loads an image for a Page in the XML.

#### Parameters
* `pagenum` The number of the page for which to load the image. 

* `fname` File name of the image to read, overriding the one in the XML. 

* `resize_coords` If image size differs, resize page XML coordinates. 

* `density` Load the image at the given density, resizing the page coordinates if required.

#### `public void `[`loadImage`](#class_page_x_m_l_1a74593bb0b4ca5e266dfc5650ca5009d0)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * fname,const bool resize_coords,int density)` 

#### `public void `[`loadImages`](#class_page_x_m_l_1a8c3f3f964ef4039094e0a81a73f679a0)`(const bool resize_coords,const int density)` 

#### `public int `[`simplifyIDs`](#class_page_x_m_l_1a5d3b4a59cecbf6fdf8c84f806a7648f0)`()` 

Simplifies IDs by removing imgbase prefixes and replaces invalid characters with _.

#### Returns
Number of IDs simplified.

#### `public void `[`relativizeImageFilename`](#class_page_x_m_l_1a3c43349d7cff78cea6d1ba7b01f023b3)`(const char * xml_path)` 

Modifies imageFilename to be a relative path w.r.t. given xml path. Currently just checks prefix directories and removes it.

#### `public std::vector< std::string > `[`getImageBases`](#class_page_x_m_l_1a3c43f4e51877f674f29af7a421fa973b)`()` 

Gets image bases for all pages in xml.

#### Returns
Vector of strings containing the image base names.

#### `public bool `[`areIDsUnique`](#class_page_x_m_l_1aeb8f1e60e4e2521c2bb50fe495327648)`()` 

Verifies that all IDs in page are unique.

#### `public std::string `[`getNodeName`](#class_page_x_m_l_1a8e8ded73daa9edf93b02d75bac16b9de)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` base_node)` 

Gets the name of the given node.

#### Parameters
* `node` XML node. 

#### Returns
String with the name.

#### `public std::vector< `[`NamedImage`](#struct_named_image)` > `[`crop`](#class_page_x_m_l_1a3264214ef4bc3ea7d5706b33440c57a0)`(const char * xpath,cv::Point2f * margin,bool opaque_coords,const char * transp_xpath,const char * base_xpath)` 

Crops images using its Coords polygon, regions outside the polygon are set to transparent.

#### Parameters
* `xpath` Selector for polygons to crop. 

* `margin` Margins, if >1.0 pixels, otherwise percentage of maximum of crop width and height. 

* `opaque_coords` Whether to include an alpha channel with the polygon interior in opaque. 

* `transp_xpath` Selector for semi-transparent elements. 

#### Returns
An std::vector containing [NamedImage](#struct_named_image) objects of the cropped images.

#### `public int `[`count`](#class_page_x_m_l_1ad4fa4aef07f44a011f154cee73aa6002)`(const char * xpath,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` basenode)` 

Returns number of matched nodes for a given xpath.

#### Parameters
* `xpath` Selector expression. 

* `node` XML node for context, set to NULL for root node. 

#### Returns
Number of matched nodes.

#### `public int `[`count`](#class_page_x_m_l_1a9017068318dd91aead4d39a472ee2a8d)`(std::string xpath,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` basenode)` 

#### `public std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > `[`select`](#class_page_x_m_l_1a562f6a2af80c35e01a9cfa36afc10435)`(const char * xpath,const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` basenode)` 

Selects nodes given an xpath.

#### Parameters
* `xpath` Selector expression. 

* `node` XML node for context, set to NULL for root node. 

#### Returns
Vector of matched nodes.

#### `public std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > `[`select`](#class_page_x_m_l_1ad1fd441a90b31c4900bb9896185a177f)`(std::string xpath,const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` 

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`selectNth`](#class_page_x_m_l_1ab23937e1762c713c2ca2636de8d1075f)`(const char * xpath,unsigned num,const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` 

Selects the n-th node that matches an xpath.

#### Parameters
* `xpath` Selector expression. 

* `num` Element number (0-indexed). 

* `node` XML node for context, set to NULL for root node. 

#### Returns
Matched node.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`selectNth`](#class_page_x_m_l_1a20ceffc31be1dd670069e57012e5202d)`(std::string xpath,unsigned num,const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` 

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`selectByID`](#class_page_x_m_l_1ace787087add3c5f3016ec837553d48b5)`(const char * id,const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` 

Selects an element with a given ID.

#### Parameters
* `id` ID of element to select. 

* `node` XML node for context, set to NULL for root node. 

#### Returns
Matched node.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`closest`](#class_page_x_m_l_1a089e2ca706141bf750b301fd34595fc1)`(const char * name,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` 

Selects closest node of a given name.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`parent`](#class_page_x_m_l_1a8ac32174f32b120caf595ec3a82e57d1)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` 

Returns the parent of a node.

#### Parameters
* `node` XML node. 

#### Returns
Parent node.

#### `public std::string `[`getValue`](#class_page_x_m_l_1a806731e1825cfbfa406ddf3e6978d747)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` 

Retrieves a node value.

#### Parameters
* `node` Node element. 

#### Returns
String with the node value.

#### `public std::string `[`getAttr`](#class_page_x_m_l_1a23e16f7c70950b4fe990b8c22a2e1ce5)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * name)` 

Gets an attribute value from an xml node.

#### Parameters
* `node` XML node. 

* `name` Attribute name. 

* `value` String to set the value. 

#### Returns
True if attribute found, otherwise false.

#### `public std::string `[`getAttr`](#class_page_x_m_l_1abef00c0a3b59143989b8d29beaeb14bf)`(const char * xpath,const char * name)` 

Gets an attribute value for a given xpath.

#### Parameters
* `xpath` Selector for the element to get the attribute. 

* `name` Attribute name. 

* `value` String to set the value. 

#### Returns
True if attribute found, otherwise false.

#### `public std::string `[`getAttr`](#class_page_x_m_l_1a057bb3cecf33b3cd2e621d56095a4716)`(const std::string xpath,const std::string name)` 

#### `public int `[`setAttr`](#class_page_x_m_l_1ada5a3f0e91615340782afe1eea87c23d)`(std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > nodes,const char * name,const char * value)` 

#### `public int `[`setAttr`](#class_page_x_m_l_1abaa5b2ad59b0769bb8cff58a53b04231)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * name,const char * value)` 

Adds or modifies (if already exists) an attribute for a given node.

#### Parameters
* `node` Node to set the attribute. 

* `name` Attribute name. 

* `value` Attribute value. 

#### Returns
Number of elements modified.

#### `public int `[`setAttr`](#class_page_x_m_l_1a8cc6e9bffff7951aa5db47af47642601)`(const char * xpath,const char * name,const char * value)` 

Adds or modifies (if already exists) an attribute for a given xpath.

#### Parameters
* `xpath` Selector for the element(s) to set the attribute. 

* `name` Attribute name. 

* `value` Attribute value. 

#### Returns
Number of elements modified.

#### `public int `[`setAttr`](#class_page_x_m_l_1a8d1d681d5b986527265ff07c757a2b3b)`(const std::string xpath,const std::string name,const std::string value)` 

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`insertElem`](#class_page_x_m_l_1ab0e8796f7920a2fc3ff1a490b85b6b8b)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` elem,const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,`[`PAGEXML_INSERT`](#_page_x_m_l_8h_1adfd6b61039753caee671c2667b7b2b4b)` itype)` 

Inserts an element relative to a given node.

#### Parameters
* `elem` Element to insert. 

* `node` Reference element for insertion. 

* `itype` Type of insertion. 

#### Returns
Pointer to inserted element.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addElem`](#class_page_x_m_l_1a2dd9a0a6cfeb68a91c005740dd6ce315)`(const char * name,const char * id,const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,`[`PAGEXML_INSERT`](#_page_x_m_l_8h_1adfd6b61039753caee671c2667b7b2b4b)` itype,bool checkid)` 

Creates a new element and adds it relative to a given node.

#### Parameters
* `name` Name of element to create. 

* `id` ID attribute for element. 

* `node` Reference element for insertion. 

* `itype` Type of insertion. 

#### Returns
Pointer to created element.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addElem`](#class_page_x_m_l_1a4b218c9cddda9763bdd3f65d3074d5f7)`(const char * name,const char * id,const char * xpath,`[`PAGEXML_INSERT`](#_page_x_m_l_8h_1adfd6b61039753caee671c2667b7b2b4b)` itype,bool checkid)` 

Creates a new element and adds it relative to a given xpath.

#### Parameters
* `name` Name of element to create. 

* `id` ID attribute for element. 

* `xpath` Selector for insertion. 

* `itype` Type of insertion. 

#### Returns
Pointer to created element.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addElem`](#class_page_x_m_l_1abbbf302357d6016ffde3a2b859fa1f93)`(const std::string name,const std::string id,const std::string xpath,`[`PAGEXML_INSERT`](#_page_x_m_l_8h_1adfd6b61039753caee671c2667b7b2b4b)` itype,bool checkid)` 

#### `public void `[`rmElem`](#class_page_x_m_l_1ad3e1cc3040a7aef670d64fac0e2e82d8)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` 

Removes the given element.

#### Parameters
* `node` Element.

#### `public int `[`rmElems`](#class_page_x_m_l_1a58b3870ad811accb8b91a433796fbf6f)`(const std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > & nodes)` 

#### `public int `[`rmElems`](#class_page_x_m_l_1a47752b5ea364d374008f3f04b984a0cb)`(const char * xpath,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` basenode)` 

Remove the elements that match a given xpath.

#### Parameters
* `xpath` Selector for elements to remove. 

* `node` Base node for element selection. 

#### Returns
Number of elements removed.

#### `public int `[`rmElems`](#class_page_x_m_l_1aa1c5ac267af4aeda9fea84eada6e91db)`(const std::string xpath,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` basenode)` 

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`moveElem`](#class_page_x_m_l_1af214054f7b648086704f7cc0bd3b51e1)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` elem,const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,`[`PAGEXML_INSERT`](#_page_x_m_l_8h_1adfd6b61039753caee671c2667b7b2b4b)` itype)` 

Unlink an element and add it relative to a given node.

#### Parameters
* `elem` Element to move. 

* `node` Reference element for insertion. 

* `itype` Type of insertion. 

#### Returns
Pointer to moved element.

#### `public int `[`moveElems`](#class_page_x_m_l_1ac6320b747e78baa3d2f5753086e54189)`(const std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > & elems,const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,`[`PAGEXML_INSERT`](#_page_x_m_l_8h_1adfd6b61039753caee671c2667b7b2b4b)` itype)` 

Unlink elements and add them relative to a given node.

#### Parameters
* `elem` Element to move. 

* `node` Reference element for insertion. 

* `itype` Type of insertion. 

#### Returns
Pointer to moved element.

#### `public void `[`setRotation`](#class_page_x_m_l_1afc92cad64293df78c84bc7d8c899cf6f)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` elem,const float rotation)` 

Sets the rotation angle to a TextRegion node.

#### Parameters
* `node` Node of the TextRegion element. 

* `rotation` Rotation angle to set.

#### `public void `[`setReadingDirection`](#class_page_x_m_l_1af1eef0ce8e1ff941b79430db6802e51a)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` elem,`[`PAGEXML_READ_DIRECTION`](#_page_x_m_l_8h_1a151afb8ef7c7e05585713fafd180a2ea)` direction)` 

Sets the reading direction to a TextRegion node.

#### Parameters
* `node` Node of the TextRegion element. 

* `direction` Direction to set.

#### `public double `[`getBaselineOrientation`](#class_page_x_m_l_1a01d20d4333c5011f80bf83fe246ac76b)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` elem)` 

Gets the (average) baseline orientation angle in radians of a given text line.

#### Parameters
* `elem` Node of the TextLine element. 

#### Returns
The orientation angle in radians, NaN if unset.

#### `public double `[`getBaselineOrientation`](#class_page_x_m_l_1afe1e54530f0f34624339ebd3fc6aae49)`(std::vector< cv::Point2f > points)` 

Gets the (average) baseline orientation angle in radians of a given baseline.

#### Parameters
* `points` Baseline points. 

#### Returns
The orientation angle in radians, NaN if unset.

#### `public double `[`getBaselineLength`](#class_page_x_m_l_1af10f6f194ad7eed3f9924544b54e1c09)`(std::vector< cv::Point2f > points)` 

Gets the baseline length.

#### Parameters
* `points` Baseline points. 

#### Returns
The orientation angle in radians, NaN if unset.

#### `public double `[`getRotation`](#class_page_x_m_l_1a6e68136a69dd82168bbc28c64bff45e4)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` elem)` 

Retrieves the rotation angle for a given TextLine or TextRegion node.

#### Parameters
* `elem` Node of the TextLine or TextRegion element. 

#### Returns
The rotation angle in degrees, 0 if unset.

#### `public int `[`getReadingDirection`](#class_page_x_m_l_1acc2adc9d4408836ea87d8056e2d522f6)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` elem)` 

Retrieves the reading direction for a given TextLine or TextRegion node.

#### Parameters
* `elem` Node of the TextLine or TextRegion element. 

#### Returns
The reading direction, PAGEXML_READ_DIRECTION_LTR if unset.

#### `public float `[`getXheight`](#class_page_x_m_l_1a6d7cd4ada93f19226e3723d6c41a9ebf)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` 

Retrieves the x-height for a given TextLine node.

#### Parameters
* `node` Node of the TextLine element. 

#### Returns
x-height>0 on success, -1 if unset.

#### `public float `[`getXheight`](#class_page_x_m_l_1a401b8196ba181dec3fa5d76eb9c6e585)`(const char * id)` 

Retrieves the x-height for a given TextLine id.

#### Parameters
* `id` Identifier of the TextLine. 

#### Returns
x-height>0 on success, -1 if unset.

#### `public std::vector< cv::Point2f > `[`getFpgram`](#class_page_x_m_l_1a0425df4d97b66a7f259cfb1fae847667)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` 

Retrieves the features parallelogram (Property[="fpgram"]/) for a given node.

#### Parameters
* `node` Base node. 

#### Returns
Reference to the points vector.

#### `public std::vector< cv::Point2f > `[`getPoints`](#class_page_x_m_l_1aba7be6cf9e66f1395c84f0880ca2a069)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * xpath)` 

Retrieves and parses the Coords/ for a given base node.

#### Parameters
* `node` Base node. 

#### Returns
Reference to the points vector.

#### `public std::vector< std::vector< cv::Point2f > > `[`getPoints`](#class_page_x_m_l_1a41e062ef2c08e4c3212c39d4ec48b2fa)`(const std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > nodes,const char * xpath)` 

Retrieves and parses the Coords/ for a given list of base nodes.

#### Parameters
* `nodes` Base nodes. 

#### Returns
Reference to the points vector.

#### `public std::string `[`getTextEquiv`](#class_page_x_m_l_1aede7f24b63a9ca5acfbfe21e9343b977)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * xpath,const char * separator)` 

Retrieves the concatenated TextEquivs for a given root node and xpath.

#### Parameters
* `node` Root node element. 

* `xpath` Relative xpath to select the TextEquiv elements. 

* `separator` String to add between TextEquivs. 

#### Returns
String with the concatenated TextEquivs.

#### `public void `[`processStart`](#class_page_x_m_l_1a3eeffa37a2ace0dc732405e81cb49e4d)`(const char * tool,const char * ref)` 

Starts a process in the Page XML.

#### `public void `[`processEnd`](#class_page_x_m_l_1a29d780f46c1f14b241f48665d835394c)`()` 

Ends the running process in the Page XML.

#### `public void `[`updateLastChange`](#class_page_x_m_l_1a99bc8c45fae21207bb608e69609dedcd)`()` 

Updates the last change time stamp.

#### `public std::string `[`getPropertyValue`](#class_page_x_m_l_1ab4d79c28bc94086d1d379f0ea73ff899)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * key)` 

Retrieves a Property value.

#### Parameters
* `node` Node element. 

#### Returns
String with the property value.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setProperty`](#class_page_x_m_l_1af6e80d30313f63054228fcb15305db31)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * key,const char * val,const double * _conf)` 

Sets a Property to a given node.

#### Parameters
* `node` The node of element to set the Property. 

* `key` The key for the Property. 

* `val` The optional value for the Property. 

* `_conf` Pointer to confidence value, NULL for no confidence. 

#### Returns
Pointer to created element.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setProperty`](#class_page_x_m_l_1a82ffe7a5366736034a3e4514b43ab389)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * key,const double val,const double * _conf)` 

Sets a Property to a given node.

#### Parameters
* `node` The node of element to set the Property. 

* `key` The key for the Property. 

* `val` Numeric value for the Property. 

* `_conf` Pointer to confidence value, NULL for no confidence. 

#### Returns
Pointer to created element.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setTextEquiv`](#class_page_x_m_l_1a65f380acfc400de2a6dc59eb1ee22904)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * text,const double * _conf)` 

Adds or modifies (if already exists) the TextEquiv for a given node.

#### Parameters
* `node` The node of element to set the TextEquiv. 

* `text` The text string. 

* `_conf` Pointer to confidence value, NULL for no confidence. 

#### Returns
Pointer to created element.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setTextEquiv`](#class_page_x_m_l_1ae7938084955a0668bc44f24307ad77ba)`(const char * xpath,const char * text,const double * _conf)` 

Adds or modifies (if already exists) the TextEquiv for a given xpath.

#### Parameters
* `xpath` Selector for element to set the TextEquiv. 

* `text` The text string. 

* `_conf` Pointer to confidence value, NULL for no confidence. 

#### Returns
Pointer to created element.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setCoords`](#class_page_x_m_l_1a8d92328ba656b8e8e847bf2ad3607a46)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const std::vector< cv::Point2f > & points,const double * _conf)` 

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setCoords`](#class_page_x_m_l_1a626847a8aac3c4bc650d0b27f3ce042b)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const std::vector< cv::Point > & points,const double * _conf)` 

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setCoords`](#class_page_x_m_l_1a1038c674a0522759ea3004bac9cac5f2)`(const char * xpath,const std::vector< cv::Point2f > & points,const double * _conf)` 

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setCoordsBBox`](#class_page_x_m_l_1ac42051db4e4f1feb754401e78f5cb53d)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,double xmin,double ymin,double width,double height,const double * _conf,bool subone)` 

Adds or modifies (if already exists) the Coords as a bounding box for a given node.

#### Parameters
* `node` The node of element to set the Coords. 

* `xmin` Minimum x value of bounding box. 

* `ymin` Minimum y value of bounding box. 

* `width` Width of bounding box. 

* `height` Height of bounding box. 

* `_conf` Pointer to confidence value, NULL for no confidence. 

* `subone` Whether to subtract 1 when computing xmax and ymax (discrete compatibility). 

#### Returns
Pointer to created element.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setBaseline`](#class_page_x_m_l_1a2a85dc0b7eb35ac29780551a642a3e51)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const std::vector< cv::Point2f > & points,const double * _conf)` 

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setBaseline`](#class_page_x_m_l_1a12a577c21cf6109f30843336bbdaba8d)`(const char * xpath,const std::vector< cv::Point2f > & points,const double * _conf)` 

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setBaseline`](#class_page_x_m_l_1a489cf14031d07454f538a048e4b48c03)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,double x1,double y1,double x2,double y2,const double * _conf)` 

Adds or modifies (if already exists) a two point Baseline for a given node.

#### Parameters
* `node` The node of element to set the Baseline. 

* `x1` x value of first point. 

* `y1` y value of first point. 

* `x2` x value of second point. 

* `y2` y value of second point. 

* `_conf` Pointer to confidence value, NULL for no confidence. 

#### Returns
Pointer to created element.

#### `public bool `[`intersection`](#class_page_x_m_l_1a37da0ed1fb708b374e7d83e6b22cbb23)`(cv::Point2f line1_point1,cv::Point2f line1_point2,cv::Point2f line2_point1,cv::Point2f line2_point2,cv::Point2f & _ipoint)` 

Finds the intersection point between two lines defined by pairs of points or returns false if no intersection

#### `public bool `[`isPolystripe`](#class_page_x_m_l_1a61c1b6597c7bcf7b65dc195e95ef7ab4)`(std::vector< cv::Point2f > coords,std::vector< cv::Point2f > baseline,double * height,double * offset)` 

Checks whether Coords is a poly-stripe for its corresponding baseline.

#### Parameters
* `coords` Coords points. 

* `baseline` Baseline points. 

* `offset` The offset of the poly-stripe (>=0 && <= 0.5). 

#### Returns
Pointer to created element.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`setPolystripe`](#class_page_x_m_l_1ab97470a0132a3e497c80f26e061aba28)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,double height,double offset,bool offset_check)` 

Sets the Coords of a TextLine as a poly-stripe of the baseline.

#### Parameters
* `node` The node of element to set the Coords. 

* `height` The height of the poly-stripe in pixels (>0). 

* `offset` The offset of the poly-stripe (>=0 && <= 0.5). 

#### Returns
Pointer to created element.

#### `public int `[`getPageNumber`](#class_page_x_m_l_1ae660a692143a9983406bba434037e78c)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` 

Gets the page number for the given node.

#### `public void `[`setPageImageOrientation`](#class_page_x_m_l_1a7f89e6da35429f37f6d887b36510772c)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,int angle,const double * _conf)` 

Sets the image orientation for the given Page node.

#### Parameters
* `node` The page node. 

* `angle` The orientation angle in degrees {0,90,180,-90}. 

* `_conf` Pointer to confidence value, NULL for no confidence.

#### `public void `[`setPageImageOrientation`](#class_page_x_m_l_1a94c03640c38f7ddd743b9c0423c71342)`(int pagenum,int angle,const double * _conf)` 

#### `public int `[`getPageImageOrientation`](#class_page_x_m_l_1a3f776930d7d1be6239497c49f6ea6b9a)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` 

Gets the image orientation for the given node.

#### Parameters
* `node` A node to get its image orientation. 

#### Returns
Orientation in degrees.

#### `public int `[`getPageImageOrientation`](#class_page_x_m_l_1acd1a1b7bbe14a6c8e14e3ef5afccd3cf)`(int pagenum)` 

#### `public unsigned int `[`getPageWidth`](#class_page_x_m_l_1a7746613d3800267f27d7bef2240ec827)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` 

Returns the width of a page.

#### `public unsigned int `[`getPageWidth`](#class_page_x_m_l_1aa1b7155d7ae5b37710310b7891d1c314)`(int pagenum)` 

#### `public unsigned int `[`getPageHeight`](#class_page_x_m_l_1ab96562c1fe4d95706778507ed2e8b57d)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` 

Returns the height of a page.

#### `public unsigned int `[`getPageHeight`](#class_page_x_m_l_1a80e90205b325157f3d1fd680f7ebc108)`(int pagenum)` 

#### `public std::vector< cv::Size2i > `[`getPagesSize`](#class_page_x_m_l_1a525354fa982782061b40718607b960dd)`(std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > pages)` 

Retrieves pages size.

#### Parameters
* `pages` Page nodes. 

#### Returns
Vector of page sizes.

#### `public std::vector< cv::Size2i > `[`getPagesSize`](#class_page_x_m_l_1aab0456c928c85b694387acf75339c02f)`(const char * xpath)` 

#### `public int `[`resize`](#class_page_x_m_l_1a81f6aa2af3574985f268959662ac4c2b)`(std::vector< cv::Size2i > sizes,std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > pages,bool check_aspect_ratio)` 

Resizes pages and all respective coordinates.

#### Parameters
* `sizes` Page sizes to resize to. 

* `pages` Page nodes. 

* `check_aspect_ratio` Whether to check that the aspect ratio is properly preserved. 

#### Returns
Number of pages+points attributes modified.

#### `public int `[`resize`](#class_page_x_m_l_1a8b24748e08ccb010eb709a9d91c711cc)`(std::vector< cv::Size2i > sizes,const char * xpath,bool check_aspect_ratio)` 

Resizes pages and all respective coordinates.

#### Parameters
* `sizes` Page sizes to resize to. 

* `xpath` Selector for Page nodes. 

* `check_aspect_ratio` Whether to check that the aspect ratio is properly preserved. 

#### Returns
Number of pages+points attributes modified.

#### `public int `[`resize`](#class_page_x_m_l_1ae9772185b88e2e12e26025effc2c39c7)`(cv::Size2i size,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` page,bool check_aspect_ratio)` 

Resizes a page and all respective coordinates.

#### Parameters
* `size` Page size to resize to. 

* `page` Page node. 

* `check_aspect_ratio` Whether to check that the aspect ratio is properly preserved. 

#### Returns
Number of pages+points attributes modified.

#### `public int `[`resize`](#class_page_x_m_l_1a06f171653bd8d50c03ed153523e24fc5)`(double fact,const char * xpath)` 

Resizes a page and all respective coordinates.

#### Parameters
* `factor` Resizing factor. 

* `xpath` Selector for Page nodes. 

#### Returns
Number of pages+points attributes modified.

#### `public void `[`setPageImageFilename`](#class_page_x_m_l_1a66d14b834c2ff1e162ddc268d92e9318)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * image)` 

Sets the imageFilename of a page.

#### `public void `[`setPageImageFilename`](#class_page_x_m_l_1a1f6225549414316c7b42d466f37ea9ae)`(int pagenum,const char * image)` 

#### `public std::string `[`getPageImageFilename`](#class_page_x_m_l_1ab6670ff942eeb850d64cb87a9932be58)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` 

Returns the imageFilename of a page.

#### `public std::string `[`getPageImageFilename`](#class_page_x_m_l_1ac6fe17760af6634bf781b82831f6145b)`(int pagenum)` 

#### `public `[`PageImage`](#_page_x_m_l_8h_1ac50a58a5d388d3de0e068f1ac3f90cb9)` `[`getPageImage`](#class_page_x_m_l_1acc09b01d19dfafb3ccd43b0099313045)`(int pagenum)` 

Returns the image for the given page.

#### `public `[`PageImage`](#_page_x_m_l_8h_1ac50a58a5d388d3de0e068f1ac3f90cb9)` `[`getPageImage`](#class_page_x_m_l_1abf54fa39f33ca21661e87528136b00b6)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node)` 

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addGlyph`](#class_page_x_m_l_1a0814aa1518e897289014c38c441a8bf1)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * id,const char * before_id)` 

Adds a Glyph to a given node.

#### Parameters
* `node` The node of element to add the Glyph. 

* `id` ID for Glyph, if NULL it is selected automatically. 

* `before_id` If !=NULL inserts it before the Glyph with this ID. 

#### Returns
Pointer to created element.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addGlyph`](#class_page_x_m_l_1acaa1832064f9fadb99580bce37ff2a61)`(const char * xpath,const char * id,const char * before_id)` 

Adds a Glyph to a given xpath.

#### Parameters
* `xpath` Selector for element to set the Glyph. 

* `id` ID for Glyph, if NULL it is selected automatically. 

* `before_id` If !=NULL inserts it before the Glyph with this ID. 

#### Returns
Pointer to created element.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addWord`](#class_page_x_m_l_1ab865d14cd40a7898f7612ca3e1cb507f)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * id,const char * before_id)` 

Adds a Word to a given node.

#### Parameters
* `node` The node of element to add the Word. 

* `id` ID for Word, if NULL it is selected automatically. 

* `before_id` If !=NULL inserts it before the Word with this ID. 

#### Returns
Pointer to created element.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addWord`](#class_page_x_m_l_1a35b83528a5e85c0f8e5fe91e6603ea7f)`(const char * xpath,const char * id,const char * before_id)` 

Adds a Word to a given xpath.

#### Parameters
* `xpath` Selector for element to set the Word. 

* `id` ID for Word, if NULL it is selected automatically. 

* `before_id` If !=NULL inserts it before the Word with this ID. 

#### Returns
Pointer to created element.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addTextLine`](#class_page_x_m_l_1a990faea859827afc6ed10243f1c347fb)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * id,const char * before_id)` 

Adds a TextLine to a given node.

#### Parameters
* `node` The node of element to add the TextLine. 

* `id` ID for TextLine, if NULL it is selected automatically. 

* `before_id` If !=NULL inserts it before the TextLine with this ID. 

#### Returns
Pointer to created element.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addTextLine`](#class_page_x_m_l_1a52798d2245ba8af0afb948b31b311243)`(const char * xpath,const char * id,const char * before_id)` 

Adds a TextLine to a given xpath.

#### Parameters
* `xpath` Selector for element to add the TextLine. 

* `id` ID for TextLine, if NULL it is selected automatically. 

* `before_id` If !=NULL inserts it before the TextLine with this ID. 

#### Returns
Pointer to created element.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addTextRegion`](#class_page_x_m_l_1af335dbda4b11ddc8078df72ffca38f7c)`(`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * id,const char * before_id,bool prepend)` 

Adds a TextRegion to a given node.

#### Parameters
* `node` The node of element to add the TextRegion. 

* `id` ID for TextRegion, if NULL it is selected automatically. 

* `before_id` If !=NULL inserts it before the TextRegion with this ID. 

* `prepend` Whether to add element before all other TextRegions. 

#### Returns
Pointer to created element.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addTextRegion`](#class_page_x_m_l_1afd831d3d6a2a33cc53feae4e4c3b4662)`(const char * xpath,const char * id,const char * before_id,bool prepend)` 

Adds new TextRegion to a given xpath.

#### Parameters
* `xpath` Selector for element to add the TextRegion. 

* `id` ID for TextRegion, if NULL it is selected automatically. 

* `before_id` If !=NULL inserts it before the TextRegion with this ID. 

#### Returns
Pointer to created element.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addPage`](#class_page_x_m_l_1a99fbe6075faea2c881f8a5bbb2d68f0e)`(const char * image,const int imgW,const int imgH,const char * id,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` before_node)` 

Adds a Page to the PcGts node.

#### Parameters
* `image` Path to the image file. 

* `imgW` Width of image. 

* `imgH` Height of image. 

* `id` ID for Page, if NULL it is left unset. 

* `before_node` If !=NULL inserts it before the provided Page node. 

#### Returns
Pointer to created element.

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`addPage`](#class_page_x_m_l_1ad7c0aed4a410245017724a7cefc40654)`(std::string image,const int imgW,const int imgH,const char * id,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` before_node)` 

Adds a Page to the PcGts node.

#### Parameters
* `image` Path to the image file. 

* `imgW` Width of image. 

* `imgH` Height of image. 

* `id` ID for Page, if NULL it is left unset. 

* `before_node` If !=NULL inserts it before the provided Page node. 

#### Returns
Pointer to created element.

#### `public int `[`write`](#class_page_x_m_l_1a3de4da73170e0d402131603da0314ecf)`(const char * fname)` 

Output ///.

Writes the current state of the XML to a file using utf-8 encoding.

#### Parameters
* `fname` File name of where the XML file will be written. 

#### Returns
Number of bytes written.

#### `public std::string `[`toString`](#class_page_x_m_l_1a32549b2df27c0b2308d2ad7437cf328f)`()` 

Creates a string representation of the Page XML.

#### `public OGRMultiPolygon * `[`pointsToOGRpolygon`](#class_page_x_m_l_1a8c9648fe45b6f8787f72a426b2b21efd)`(std::vector< cv::Point2f > points)` 

Converts Coords to an OGRMultiPolygon.

#### Parameters
* `points` Vector of x,y points. 

#### Returns
Pointer to OGRMultiPolygon element.

#### `public std::vector< OGRMultiPolygon * > `[`pointsToOGRpolygons`](#class_page_x_m_l_1a0824036bc27ae4707329665fb2d8c422)`(std::vector< std::vector< cv::Point2f > > points)` 

Converts Coords to OGRMultiPolygons.

#### Parameters
* `points` Vectors of x,y points. 

#### Returns
Pointer to OGRMultiPolygon element.

#### `public OGRMultiPolygon * `[`getOGRpolygon`](#class_page_x_m_l_1a87274fd138a85857892a1de1f177e8d2)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * xpath)` 

Gets an element's Coords as an OGRMultiPolygon.

#### Parameters
* `node` The element from which to extract the Coords points. 

* `xpath` Selector for the Coords element. 

#### Returns
Pointer to OGRMultiPolygon element.

#### `public std::vector< OGRMultiPolygon * > `[`getOGRpolygons`](#class_page_x_m_l_1a3fdacaecdb7f703513f53b25b5907732)`(std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > nodes,const char * xpath)` 

Gets elements' Coords as OGRMultiPolygons.

#### Parameters
* `nodes` Elements from which to extract the Coords points. 

* `xpath` Selector for the Coords element. 

#### Returns
Vector of OGRMultiPolygon pointer elements.

#### `public OGRMultiPolygon * `[`getUnionOGRpolygon`](#class_page_x_m_l_1a281c42635101e469e08fea5b8ec03906)`(std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > nodes,const char * xpath)` 

Gets the union of Coords elements as a OGRMultiPolygon.

#### Parameters
* `nodes` Elements from which to extract the Coords points. 

* `xpath` Selector for the Coords element. 

#### Returns
Pointer to OGRMultiPolygon element.

#### `public double `[`getOGRpolygonArea`](#class_page_x_m_l_1a64ebd377c84d7a93636f266617173f48)`(OGRMultiPolygon * poly)` 

Gets the area of a OGRMultiPolygon.

#### Parameters
* `poly` OGRMultiPolygon pointer. 

#### Returns
Area.

#### `public OGRMultiLineString * `[`getOGRpolyline`](#class_page_x_m_l_1a1ee918e01bb6529a44d605c7256c69a6)`(const `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` node,const char * xpath)` 

Gets the element's Baseline as an OGRMultiLineString.

#### Parameters
* `node` The element from which to extract the Baseline points. 

#### Returns
Pointer to OGRMultiLineString element.

#### `public double `[`computeIntersectFactor`](#class_page_x_m_l_1a14235c2d307d8b6c2ede5fba074ae6b4)`(OGRMultiPolygon * poly1,OGRMultiPolygon * poly2)` 

Computes the intersection factor of one polygon over another.

#### Parameters
* `poly1` First polygon. 

* `poly2` Second polygon. 

#### Returns
Factor value.

#### `public double `[`computeIntersectFactor`](#class_page_x_m_l_1a013c3823c3f6c5ceefb43cb8f3205490)`(OGRMultiLineString * poly1,OGRMultiPolygon * poly2)` 

Computes the intersection factor of one polyline over polygon.

#### Parameters
* `poly1` Polyline. 

* `poly2` Polygon. 

#### Returns
Factor value.

#### `public double `[`computeIoU`](#class_page_x_m_l_1a17808b4a1ddc73d3678c6441c5d44b83)`(OGRMultiPolygon * poly1,OGRMultiPolygon * poly2)` 

Computes the intersection over union (IoU) of two polygons.

#### Parameters
* `poly1` First polygon. 

* `poly2` Second polygon. 

#### Returns
IoU value.

#### `public std::vector< double > `[`computeIoUs`](#class_page_x_m_l_1aceff17e141c37b9e39fed30fe67c7379)`(OGRMultiPolygon * poly,std::vector< OGRMultiPolygon * > polys)` 

Computes the intersection over unions (IoU) of polygons.

#### Parameters
* `poly` Polygon. 

* `polys` Vector of polygons. 

#### Returns
IoU values.

#### `public double `[`computeIntersectionPercentage`](#class_page_x_m_l_1a3c3bf48e2cf7496a07790253384d1008)`(OGRMultiPolygon * poly1,OGRMultiPolygon * poly2)` 

Computes the intersection percentage of one polygon with respect to another polygons.

#### Parameters
* `poly1` First polygon. 

* `poly2` Second polygon. 

#### Returns
Intersection percentage value.

#### `public std::vector< double > `[`computeIntersectionPercentages`](#class_page_x_m_l_1a465631113aa581de9c9aa2ba4d780716)`(OGRMultiPolygon * poly,std::vector< OGRMultiPolygon * > polys)` 

Computes the intersection percentage of one polygon with respect to other polygons.

#### Parameters
* `poly` Polygon. 

* `polys` Vector of polygons. 

#### Returns
Intersection percentage values.

#### `public std::vector< double > `[`computeAreas`](#class_page_x_m_l_1a00b39565e78cad9a8b4abceb106a105c)`(std::vector< OGRMultiPolygon * > polys)` 

Computes the areas for given polygons.

#### Parameters
* `polys` Polygons to process. 

#### Returns
The polygon areas.

#### `public std::vector< double > `[`computeCoordsIntersectionsWeightedByArea`](#class_page_x_m_l_1aaac21cae37920f6707f511d4300fb5d4)`(OGRMultiPolygon * poly,std::vector< OGRMultiPolygon * > polys,std::vector< double > areas)` 

Computes polygon-polygon intersections weighted by area.

#### Parameters
* `poly` Polygon. 

* `polys` Polygons to compare with. 

* `areas` Polygons areas. 

#### Returns
Obtained intersection scores.

#### `public std::vector< double > `[`computeBaselineIntersectionsWeightedByArea`](#class_page_x_m_l_1a4c30956a60ac8c6149486029e3b4eb09)`(OGRMultiLineString * poly,std::vector< OGRMultiPolygon * > polys,std::vector< double > areas)` 

Computes line-polygon intersections weighted by area.

#### Parameters
* `poly` Polyline. 

* `polys` Polygons to compare with. 

* `areas` Polygons areas. 

#### Returns
Obtained intersection scores.

#### `public std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > `[`selectByOverlap`](#class_page_x_m_l_1a3718a39284bb9e947e19af32b75a00cb)`(std::vector< cv::Point2f > points,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` page,const char * xpath,double overlap_thr,`[`PAGEXML_OVERLAP`](#_page_x_m_l_8h_1a8606ef3ee6c75085c7c5d97b79132c50)` overlap_type)` 

Selects elements based on overlap to a polygon.

#### Parameters
* `points` Polygon for selection. 

* `page` Page element for selection. 

* `xpath` xpath for candidate elements for selection. 

* `overlap_thr` Overlapping score threshold. 

* `overlap_type` Type of overlap to use for selecting. 

#### Returns
Number of TextLines copied.

#### `public std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > `[`selectByOverlap`](#class_page_x_m_l_1a5f355663308e4f139495d06015a4854f)`(std::vector< cv::Point2f > points,int pagenum,const char * xpath,double overlap_thr,`[`PAGEXML_OVERLAP`](#_page_x_m_l_8h_1a8606ef3ee6c75085c7c5d97b79132c50)` overlap_type)` 

Selects elements based on overlap to a polygon.

#### Parameters
* `points` Polygon for selection. 

* `pagenum` Page number for selection. 

* `xpath` xpath for candidate elements for selection. 

* `overlap_thr` Overlapping score threshold. 

* `overlap_type` Type of overlap to use for selecting. 

#### Returns
Number of TextLines copied.

#### `public int `[`copyTextLinesAssignByOverlap`](#class_page_x_m_l_1ae4b049403a387f9455bc0cc3026a7b76)`(`[`PageXML`](#class_page_x_m_l)` & pageFrom,`[`PAGEXML_OVERLAP`](#_page_x_m_l_8h_1a8606ef3ee6c75085c7c5d97b79132c50)` overlap_type,double overlap_fact)` 

Copies TextLines from one page xml to another assigning to regions based on overlap.

#### Parameters
* `pageFrom` [PageXML](#class_page_x_m_l) from where to copy TextLines. 

* `overlap_type` Type of overlap to use for assigning lines to regions. 

* `overlap_fact` Overlapping factor. 

#### Returns
Number of TextLines copied.

#### `public int `[`testTextLineContinuation`](#class_page_x_m_l_1a508d158670341a3fc48ae03918f1b65b)`(std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > lines,std::vector< std::vector< int > > & _line_group_order,std::vector< double > & _line_group_score,double cfg_max_angle_diff,double cfg_max_horiz_iou,double cfg_min_prolong_fact,bool fake_baseline)` 

Tests for text line continuation (requires single segment polystripe).

#### Parameters
* `lines` TextLine elements to test for continuation. 

* `_line_group_order` Join groups line indices (output). 

* `_line_group_score` Join group scores (output). 

* `cfg_max_angle_diff` Maximum baseline angle difference for joining. 

* `cfg_max_horiz_iou` Maximum horizontal IoU for joining. 

* `cfg_min_prolong_fact` Minimum prolongation factor for joining. 

* `fake_baseline` Use bottom line of Coords rectangle as the baseline. 

#### Returns
Number of join groups.

#### `public std::vector< int > `[`getTextLinesReadingOrder`](#class_page_x_m_l_1a625fb5d653053410316f8c7a5f741c3e)`(std::vector< `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` > lines,double cfg_max_angle_diff,double cfg_max_horiz_iou,double cfg_min_prolong_fact,bool fake_baseline)` 

Gets the reading order for a set of text lines (requires single segment polystripe).

#### Parameters
* `lines` TextLine elements to process. 

* `cfg_max_angle_diff` Maximum baseline angle difference for joining. 

* `cfg_max_horiz_iou` Maximum horizontal IoU for joining. 

* `cfg_min_prolong_fact` Minimum prolongation factor for joining. 

#### Returns
Reading order indices.

#### `public xmlDocPtr `[`getDocPtr`](#class_page_x_m_l_1a279bbf7b7641aa329f9fd5607cdde52c)`()` 

Returns the XML document pointer.

# struct `NamedImage` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public std::string `[`id`](#struct_named_image_1a15cce4fef87364e870d24ce7af8bba7a) | 
`public std::string `[`name`](#struct_named_image_1a3091d87d082c33c731f47df06f7ffec3) | 
`public float `[`rotation`](#struct_named_image_1ab277b090578b630cbf481373def2e910) | 
`public int `[`direction`](#struct_named_image_1a014632405141de28d9ef5c3d8b33fd27) | 
`public int `[`x`](#struct_named_image_1a0ca2bf51b4d9e41ffc6013b6ebb0eb5f) | 
`public int `[`y`](#struct_named_image_1ae37031be3a775dc1bdab07378169bc61) | 
`public `[`PageImage`](#_page_x_m_l_8h_1ac50a58a5d388d3de0e068f1ac3f90cb9)` `[`image`](#struct_named_image_1ad3acaf8a72f72434ff9474dfeee81a03) | 
`public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`node`](#struct_named_image_1a0ea94db18d30fd437a8424cf742afb9d) | 
`public inline  `[`NamedImage`](#struct_named_image_1a70560cf030f1554b2ebe91e01584d30f)`()` | 
`public inline  `[`NamedImage`](#struct_named_image_1af33a1269609e69b72d9b1e3425e09309)`(std::string _id,std::string _name,double _rotation,int _direction,int _x,int _y,`[`PageImage`](#_page_x_m_l_8h_1ac50a58a5d388d3de0e068f1ac3f90cb9)` _image,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` _node)` | 

## Members

#### `public std::string `[`id`](#struct_named_image_1a15cce4fef87364e870d24ce7af8bba7a) 

#### `public std::string `[`name`](#struct_named_image_1a3091d87d082c33c731f47df06f7ffec3) 

#### `public float `[`rotation`](#struct_named_image_1ab277b090578b630cbf481373def2e910) 

#### `public int `[`direction`](#struct_named_image_1a014632405141de28d9ef5c3d8b33fd27) 

#### `public int `[`x`](#struct_named_image_1a0ca2bf51b4d9e41ffc6013b6ebb0eb5f) 

#### `public int `[`y`](#struct_named_image_1ae37031be3a775dc1bdab07378169bc61) 

#### `public `[`PageImage`](#_page_x_m_l_8h_1ac50a58a5d388d3de0e068f1ac3f90cb9)` `[`image`](#struct_named_image_1ad3acaf8a72f72434ff9474dfeee81a03) 

#### `public `[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` `[`node`](#struct_named_image_1a0ea94db18d30fd437a8424cf742afb9d) 

#### `public inline  `[`NamedImage`](#struct_named_image_1a70560cf030f1554b2ebe91e01584d30f)`()` 

#### `public inline  `[`NamedImage`](#struct_named_image_1af33a1269609e69b72d9b1e3425e09309)`(std::string _id,std::string _name,double _rotation,int _direction,int _x,int _y,`[`PageImage`](#_page_x_m_l_8h_1ac50a58a5d388d3de0e068f1ac3f90cb9)` _image,`[`xmlNodePt`](#_page_x_m_l_8h_1af218c64e915cb44ddde63d5f20078a80)` _node)` 

Generated by [Moxygen](https://sourcey.com/moxygen)