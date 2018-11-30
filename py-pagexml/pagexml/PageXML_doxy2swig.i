
// File: index.xml

// File: structi_f1.xml


%feature("docstring") iF1 "

C++ includes: mem.h
";

// File: structi_i1.xml


%feature("docstring") iI1 "

C++ includes: mem.h
";

// File: struct_i_v2.xml


%feature("docstring") IV2 "

C++ includes: mem.h
";

// File: struct_named_image.xml


%feature("docstring") NamedImage "

C++ includes: PageXML.h
";

%feature("docstring") NamedImage::NamedImage "
";

%feature("docstring") NamedImage::NamedImage "
";

// File: class_o_g_r_multi_line_string__.xml


%feature("docstring") OGRMultiLineString_ "

C++ includes: PageXML.h
";

%feature("docstring") OGRMultiLineString_::~OGRMultiLineString_ "
";

%feature("docstring") OGRMultiLineString_::OGRMultiLineString_ "
";

%feature("docstring") OGRMultiLineString_::OGRMultiLineString_ "
";

// File: class_o_g_r_multi_polygon__.xml


%feature("docstring") OGRMultiPolygon_ "

C++ includes: PageXML.h
";

%feature("docstring") OGRMultiPolygon_::~OGRMultiPolygon_ "
";

%feature("docstring") OGRMultiPolygon_::OGRMultiPolygon_ "
";

%feature("docstring") OGRMultiPolygon_::OGRMultiPolygon_ "
";

// File: class_page_x_m_l.xml


%feature("docstring") PageXML "

C++ includes: PageXML.h
";

%feature("docstring") PageXML::version "

Returns the class version.  
";

%feature("docstring") PageXML::printVersions "
";

%feature("docstring") PageXML::setValidationEnabled "

Enables/disables schema validation.  
";

%feature("docstring") PageXML::stringToPoints "

Page processing ///.  

Parses a string of pairs of coordinates (x1,y1 [x2,y2 ...]) into an array.  

Parameters
----------
* `spoints` :  
    String containing coordinate pairs.  

Returns
-------
Array of (x,y) coordinates.  
";

%feature("docstring") PageXML::stringToPoints "
";

%feature("docstring") PageXML::pointsToString "
";

%feature("docstring") PageXML::pointsToString "
";

%feature("docstring") PageXML::pointsLimits "

Gets the minimum and maximum coordinate values for an array of points.  

Parameters
----------
* `points` :  
    The vector of points to find the limits.  
* `xmin` :  
    Minimum x value.  
* `xmax` :  
    Maximum x value.  
* `ymin` :  
    Minimum y value.  
* `ymax` :  
    Maximum y value.  
";

%feature("docstring") PageXML::pointsBBox "

Generates a vector of 4 points that define the bounding box for a given vector
of points.  

Parameters
----------
* `points` :  
    The vector of points to find the limits.  

Returns
-------
The 4 points defining the bounding box (top-left clockwise).  
";

%feature("docstring") PageXML::isBBox "

Determines whether a vector of points defines a bounding box.  

Parameters
----------
* `points` :  
    The vector of points to find the limits.  

Returns
-------
True if bounding box, otherwise false.  
";

%feature("docstring") PageXML::nodeIs "

Checks if node is of given name.  

Parameters
----------
* `node` :  
    XML node.  
* `name` :  
    String with name to match against.  

Returns
-------
True if name matches, otherwise false.  
";

%feature("docstring") PageXML::~PageXML "

PageXML object destructor.  
";

%feature("docstring") PageXML::PageXML "

Constructors ///.  

PageXML constructor that receives a file name to load.  

Parameters
----------
* `pagexml_path` :  
    Path to the XML file to read.  
* `schema_path` :  
    Path to the XSD file to read.  
";

%feature("docstring") PageXML::loadSchema "

Loads a schema for xml validation.  

Parameters
----------
* `schema_path` :  
    File name of the XSD file to read.  
";

%feature("docstring") PageXML::isValid "

Validates the currently loaded XML.  
";

%feature("docstring") PageXML::printConf "

Configuration ///.  

Prints the current configuration.  

Parameters
----------
* `file` :  
    File to print to.  
";

%feature("docstring") PageXML::newXml "

Loaders ///.  

Creates a new Page XML.  

Parameters
----------
* `creator` :  
    Info about tool creating the XML.  
* `image` :  
    Path to the image file.  
* `imgW` :  
    Width of image.  
* `imgH` :  
    Height of image.  
";

%feature("docstring") PageXML::loadXml "

Loads a Page XML from a file.  

Parameters
----------
* `fname` :  
    File name of the XML file to read.  
";

%feature("docstring") PageXML::loadXml "

Loads a Page XML from an input stream.  

Parameters
----------
* `fnum` :  
    File number from where to read the XML file.  
* `prevfree` :  
    Whether to release resources before loading.  
";

%feature("docstring") PageXML::loadXmlString "

Loads a Page XML from a string.  

Parameters
----------
* `xml_string` :  
    The XML content.  
";

%feature("docstring") PageXML::loadImage "
";

%feature("docstring") PageXML::loadImage "
";

%feature("docstring") PageXML::loadImages "
";

%feature("docstring") PageXML::simplifyIDs "

Simplifies IDs by removing imgbase prefixes and replaces invalid characters with
_.  

Returns
-------
Number of IDs simplified.  
";

%feature("docstring") PageXML::relativizeImageFilename "

Modifies imageFilename to be a relative path w.r.t. given xml path. Currently
just checks prefix directories and removes it.  
";

%feature("docstring") PageXML::getImageBases "

Gets image bases for all pages in xml.  

Returns
-------
Vector of strings containing the image base names.  
";

%feature("docstring") PageXML::areIDsUnique "

Verifies that all IDs in page are unique.  
";

%feature("docstring") PageXML::getNodeName "

Gets the name of the given node.  

Parameters
----------
* `node` :  
    XML node.  

Returns
-------
String with the name.  
";

%feature("docstring") PageXML::crop "

Crops images using its Coords polygon, regions outside the polygon are set to
transparent.  

Parameters
----------
* `xpath` :  
    Selector for polygons to crop.  
* `margin` :  
    Margins, if >1.0 pixels, otherwise percentage of maximum of crop width and
    height.  
* `opaque_coords` :  
    Whether to include an alpha channel with the polygon interior in opaque.  
* `transp_xpath` :  
    Selector for semi-transparent elements.  

Returns
-------
An std::vector containing NamedImage objects of the cropped images.  

Get parent node id ///  

Construct sample name ///  

Get coords points ///  

Get crop window parameters ///  

Add margin to bounding box ///  

Crop image ///  

Subtract crop window offset and round points ///  

Draw opaque polygon for Coords ///  

Draw semi-transparent polygons according to xpath ///  

Add alpha channel to image ///  

Append crop and related data to list ///  
";

%feature("docstring") PageXML::count "

Returns number of matched nodes for a given xpath.  

Parameters
----------
* `xpath` :  
    Selector expression.  
* `node` :  
    XML node for context, set to NULL for root node.  

Returns
-------
Number of matched nodes.  
";

%feature("docstring") PageXML::count "
";

%feature("docstring") PageXML::select "

Selects nodes given an xpath.  

Parameters
----------
* `xpath` :  
    Selector expression.  
* `node` :  
    XML node for context, set to NULL for root node.  

Returns
-------
Vector of matched nodes.  
";

%feature("docstring") PageXML::select "
";

%feature("docstring") PageXML::select "
";

%feature("docstring") PageXML::selectNth "

Selects the n-th node that matches an xpath.  

Parameters
----------
* `xpath` :  
    Selector expression.  
* `num` :  
    Element number (0-indexed), negative from last.  
* `node` :  
    XML node for context, set to NULL for root node.  

Returns
-------
Matched node.  
";

%feature("docstring") PageXML::selectNth "
";

%feature("docstring") PageXML::selectByID "

Selects an element with a given ID.  

Parameters
----------
* `id` :  
    ID of element to select.  
* `node` :  
    XML node for context, set to NULL for root node.  

Returns
-------
Matched node.  
";

%feature("docstring") PageXML::closest "

Selects closest node of a given name.  
";

%feature("docstring") PageXML::parent "

Returns the parent of a node.  

Parameters
----------
* `node` :  
    XML node.  

Returns
-------
Parent node.  
";

%feature("docstring") PageXML::getValue "

Retrieves a node value.  

Parameters
----------
* `node` :  
    Node element.  

Returns
-------
String with the node value.  
";

%feature("docstring") PageXML::getValue "

Retrieves a node value.  

Parameters
----------
* `xpath` :  
    Selector for the element to get the value.  
* `node` :  
    XML node for context, set to NULL for root node.  

Returns
-------
String with the node value.  
";

%feature("docstring") PageXML::setValue "

Sets a node value.  

Parameters
----------
* `node` :  
    Node element.  

Returns
-------
String with the node value.  
";

%feature("docstring") PageXML::getAttr "

Gets an attribute value from an xml node.  

Parameters
----------
* `node` :  
    XML node.  
* `name` :  
    Attribute name.  
* `value` :  
    String to set the value.  

Returns
-------
True if attribute found, otherwise false.  
";

%feature("docstring") PageXML::getAttr "

Gets an attribute value for a given xpath.  

Parameters
----------
* `xpath` :  
    Selector for the element to get the attribute.  
* `name` :  
    Attribute name.  
* `value` :  
    String to set the value.  

Returns
-------
True if attribute found, otherwise false.  
";

%feature("docstring") PageXML::getAttr "
";

%feature("docstring") PageXML::setAttr "
";

%feature("docstring") PageXML::setAttr "

Adds or modifies (if already exists) an attribute for a given node.  

Parameters
----------
* `node` :  
    Node to set the attribute.  
* `name` :  
    Attribute name.  
* `value` :  
    Attribute value.  

Returns
-------
Number of elements modified.  
";

%feature("docstring") PageXML::setAttr "

Adds or modifies (if already exists) an attribute for a given xpath.  

Parameters
----------
* `xpath` :  
    Selector for the element(s) to set the attribute.  
* `name` :  
    Attribute name.  
* `value` :  
    Attribute value.  

Returns
-------
Number of elements modified.  
";

%feature("docstring") PageXML::setAttr "
";

%feature("docstring") PageXML::insertElem "

Inserts an element relative to a given node.  

Parameters
----------
* `elem` :  
    Element to insert.  
* `node` :  
    Reference element for insertion.  
* `itype` :  
    Type of insertion.  

Returns
-------
Pointer to inserted element.  
";

%feature("docstring") PageXML::addElem "

Creates a new element and adds it relative to a given node.  

Parameters
----------
* `name` :  
    Name of element to create.  
* `id` :  
    ID attribute for element.  
* `node` :  
    Reference element for insertion.  
* `itype` :  
    Type of insertion.  

Returns
-------
Pointer to created element.  
";

%feature("docstring") PageXML::addElem "

Creates a new element and adds it relative to a given xpath.  

Parameters
----------
* `name` :  
    Name of element to create.  
* `id` :  
    ID attribute for element.  
* `xpath` :  
    Selector for insertion.  
* `itype` :  
    Type of insertion.  

Returns
-------
Pointer to created element.  
";

%feature("docstring") PageXML::addElem "
";

%feature("docstring") PageXML::rmElem "

Removes the given element.  

Parameters
----------
* `node` :  
    Element.  
";

%feature("docstring") PageXML::rmElems "
";

%feature("docstring") PageXML::rmElems "

Remove the elements that match a given xpath.  

Parameters
----------
* `xpath` :  
    Selector for elements to remove.  
* `node` :  
    Base node for element selection.  

Returns
-------
Number of elements removed.  
";

%feature("docstring") PageXML::rmElems "
";

%feature("docstring") PageXML::copyElem "

Clone an element and add it relative to a given node.  

Parameters
----------
* `elem` :  
    Element to clone.  
* `node` :  
    Reference element for insertion.  
* `itype` :  
    Type of insertion.  

Returns
-------
Pointer to cloned element.  
";

%feature("docstring") PageXML::moveElem "

Unlink an element and add it relative to a given node.  

Parameters
----------
* `elem` :  
    Element to move.  
* `node` :  
    Reference element for insertion.  
* `itype` :  
    Type of insertion.  

Returns
-------
Pointer to moved element.  
";

%feature("docstring") PageXML::moveElems "

Unlink elements and add them relative to a given node.  

Parameters
----------
* `elems` :  
    Elements to move.  
* `node` :  
    Reference element for insertion.  
* `itype` :  
    Type of insertion.  

Returns
-------
Pointer to moved element.  
";

%feature("docstring") PageXML::setRotation "

Sets the rotation angle to a TextRegion node.  

Parameters
----------
* `node` :  
    Node of the TextRegion element.  
* `rotation` :  
    Rotation angle to set.  
";

%feature("docstring") PageXML::setReadingDirection "

Sets the reading direction to a TextRegion node.  

Parameters
----------
* `node` :  
    Node of the TextRegion element.  
* `direction` :  
    Direction to set.  
";

%feature("docstring") PageXML::getBaselineOrientation "

Gets the (average) baseline orientation angle in radians of a given text line.  

Parameters
----------
* `elem` :  
    Node of the TextLine element.  

Returns
-------
The orientation angle in radians, NaN if unset.  
";

%feature("docstring") PageXML::getBaselineOrientation "

Gets the (average) baseline orientation angle in radians of a given baseline.  

Parameters
----------
* `points` :  
    Baseline points.  

Returns
-------
The orientation angle in radians, NaN if unset.  
";

%feature("docstring") PageXML::getBaselineLength "

Gets the baseline length.  

Parameters
----------
* `points` :  
    Baseline points.  

Returns
-------
The orientation angle in radians, NaN if unset.  
";

%feature("docstring") PageXML::getRotation "

Retrieves the rotation angle for a given TextLine or TextRegion node.  

Parameters
----------
* `elem` :  
    Node of the TextLine or TextRegion element.  

Returns
-------
The rotation angle in degrees, 0 if unset.  

If TextLine try to get rotation from custom attribute ///  

Otherwise try to get rotation from readingOrientation attribute ///  
";

%feature("docstring") PageXML::getReadingDirection "

Retrieves the reading direction for a given TextLine or TextRegion node.  

Parameters
----------
* `elem` :  
    Node of the TextLine or TextRegion element.  

Returns
-------
The reading direction, PAGEXML_READ_DIRECTION_LTR if unset.  

If TextLine try to get direction from custom attribute ///  

Otherwise try to get direction from readingDirection attribute ///  
";

%feature("docstring") PageXML::getXheight "

Retrieves the x-height for a given TextLine node.  

Parameters
----------
* `node` :  
    Node of the TextLine element.  

Returns
-------
x-height>0 on success, -1 if unset.  
";

%feature("docstring") PageXML::getXheight "

Retrieves the x-height for a given TextLine id.  

Parameters
----------
* `id` :  
    Identifier of the TextLine.  

Returns
-------
x-height>0 on success, -1 if unset.  
";

%feature("docstring") PageXML::getFpgram "

Retrieves the features parallelogram (Property[=\"fpgram\"]/) for a given node.  

Parameters
----------
* `node` :  
    Base node.  

Returns
-------
Reference to the points vector.  
";

%feature("docstring") PageXML::getPoints "

Retrieves and parses the Coords/ for a given base node.  

Parameters
----------
* `node` :  
    Base node.  

Returns
-------
Reference to the points vector.  
";

%feature("docstring") PageXML::getPoints "

Retrieves and parses the Coords/ for a given list of base nodes.  

Parameters
----------
* `nodes` :  
    Base nodes.  

Returns
-------
Reference to the points vector.  
";

%feature("docstring") PageXML::getTextEquiv "

Retrieves the concatenated TextEquivs for a given root node and xpath.  

Parameters
----------
* `node` :  
    Root node element.  
* `xpath` :  
    Relative xpath to select the TextEquiv elements.  
* `separator` :  
    String to add between TextEquivs.  

Returns
-------
String with the concatenated TextEquivs.  
";

%feature("docstring") PageXML::processStart "

Starts a process in the Page XML.  

Add Process element ///  

Start time attribute ///  

Tool and ref attributes ///  
";

%feature("docstring") PageXML::processEnd "

Ends the running process in the Page XML.  
";

%feature("docstring") PageXML::updateLastChange "

Updates the last change time stamp.  
";

%feature("docstring") PageXML::getPropertyValue "

Retrieves a Property value.  

Parameters
----------
* `node` :  
    Node element.  

Returns
-------
String with the property value.  
";

%feature("docstring") PageXML::setProperty "

Sets a Property to a given node.  

Parameters
----------
* `node` :  
    The node of element to set the Property.  
* `key` :  
    The key for the Property.  
* `val` :  
    The optional value for the Property.  
* `_conf` :  
    Pointer to confidence value, NULL for no confidence.  

Returns
-------
Pointer to created element.  
";

%feature("docstring") PageXML::setProperty "

Sets a Property to a given node.  

Parameters
----------
* `node` :  
    The node of element to set the Property.  
* `key` :  
    The key for the Property.  
* `val` :  
    The optional value for the Property.  
* `conf` :  
    Confidence value.  

Returns
-------
Pointer to created element.  
";

%feature("docstring") PageXML::setProperty "

Sets a Property to a given node.  

Parameters
----------
* `node` :  
    The node of element to set the Property.  
* `key` :  
    The key for the Property.  
* `val` :  
    Numeric value for the Property.  
* `_conf` :  
    Pointer to confidence value, NULL for no confidence.  

Returns
-------
Pointer to created element.  
";

%feature("docstring") PageXML::setProperty "

Sets a Property to a given node.  

Parameters
----------
* `node` :  
    The node of element to set the Property.  
* `key` :  
    The key for the Property.  
* `val` :  
    The optional value for the Property.  
* `conf` :  
    Confidence value.  

Returns
-------
Pointer to created element.  
";

%feature("docstring") PageXML::setTextEquiv "

Adds or modifies (if already exists) the TextEquiv for a given node.  

Parameters
----------
* `node` :  
    The node of element to set the TextEquiv.  
* `text` :  
    The text string.  
* `_conf` :  
    Pointer to confidence value, NULL for no confidence.  

Returns
-------
Pointer to created element.  
";

%feature("docstring") PageXML::setTextEquiv "

Adds or modifies (if already exists) the TextEquiv for a given node.  

Parameters
----------
* `node` :  
    The node of element to set the TextEquiv.  
* `text` :  
    The text string.  
* `conf` :  
    Confidence value.  

Returns
-------
Pointer to created element.  
";

%feature("docstring") PageXML::setTextEquiv "

Adds or modifies (if already exists) the TextEquiv for a given xpath.  

Parameters
----------
* `xpath` :  
    Selector for element to set the TextEquiv.  
* `text` :  
    The text string.  
* `_conf` :  
    Pointer to confidence value, NULL for no confidence.  

Returns
-------
Pointer to created element.  
";

%feature("docstring") PageXML::setTextEquiv "

Adds or modifies (if already exists) the TextEquiv for a given xpath.  

Parameters
----------
* `xpath` :  
    Selector for element to set the TextEquiv.  
* `text` :  
    The text string.  
* `conf` :  
    Confidence value.  

Returns
-------
Pointer to created element.  
";

%feature("docstring") PageXML::setCoords "
";

%feature("docstring") PageXML::setCoords "
";

%feature("docstring") PageXML::setCoords "
";

%feature("docstring") PageXML::setCoords "
";

%feature("docstring") PageXML::setCoords "
";

%feature("docstring") PageXML::setCoords "
";

%feature("docstring") PageXML::setCoordsBBox "

Adds or modifies (if already exists) the Coords as a bounding box for a given
node.  

Parameters
----------
* `node` :  
    The node of element to set the Coords.  
* `xmin` :  
    Minimum x value of bounding box.  
* `ymin` :  
    Minimum y value of bounding box.  
* `width` :  
    Width of bounding box.  
* `height` :  
    Height of bounding box.  
* `_conf` :  
    Pointer to confidence value, NULL for no confidence.  
* `subone` :  
    Whether to subtract 1 when computing xmax and ymax (discrete compatibility).  

Returns
-------
Pointer to created element.  
";

%feature("docstring") PageXML::setCoordsBBox "

Adds or modifies (if already exists) the Coords as a bounding box for a given
node.  

Parameters
----------
* `node` :  
    The node of element to set the Coords.  
* `xmin` :  
    Minimum x value of bounding box.  
* `ymin` :  
    Minimum y value of bounding box.  
* `width` :  
    Width of bounding box.  
* `height` :  
    Height of bounding box.  
* `conf` :  
    Confidence value.  
* `subone` :  
    Whether to subtract 1 when computing xmax and ymax (discrete compatibility).  

Returns
-------
Pointer to created element.  
";

%feature("docstring") PageXML::setBaseline "
";

%feature("docstring") PageXML::setBaseline "
";

%feature("docstring") PageXML::setBaseline "
";

%feature("docstring") PageXML::setBaseline "
";

%feature("docstring") PageXML::setBaseline "

Adds or modifies (if already exists) a two point Baseline for a given node.  

Parameters
----------
* `node` :  
    The node of element to set the Baseline.  
* `x1` :  
    x value of first point.  
* `y1` :  
    y value of first point.  
* `x2` :  
    x value of second point.  
* `y2` :  
    y value of second point.  
* `_conf` :  
    Pointer to confidence value, NULL for no confidence.  

Returns
-------
Pointer to created element.  
";

%feature("docstring") PageXML::setBaseline "

Adds or modifies (if already exists) a two point Baseline for a given node.  

Parameters
----------
* `node` :  
    The node of element to set the Baseline.  
* `x1` :  
    x value of first point.  
* `y1` :  
    y value of first point.  
* `x2` :  
    x value of second point.  
* `y2` :  
    y value of second point.  
* `conf` :  
    Confidence value.  

Returns
-------
Pointer to created element.  
";

%feature("docstring") PageXML::intersection "

Finds the intersection point between two lines defined by pairs of points or
returns false if no intersection  
";

%feature("docstring") PageXML::isPolystripe "

Checks whether Coords is a poly-stripe for its corresponding baseline.  

Parameters
----------
* `coords` :  
    Coords points.  
* `baseline` :  
    Baseline points.  
* `offset` :  
    The offset of the poly-stripe (>=0 && <= 0.5).  

Returns
-------
Pointer to created element.  

Check points are collinear ///  

Check lines are parallel ///  

Check stripe extremes perpendicular to baseline ///  
";

%feature("docstring") PageXML::setPolystripe "

Sets the Coords of a TextLine as a poly-stripe of the baseline.  

Parameters
----------
* `node` :  
    The node of element to set the Coords.  
* `height` :  
    The height of the poly-stripe in pixels (>0).  
* `offset` :  
    The offset of the poly-stripe (>=0 && <= 0.5).  

Returns
-------
Pointer to created element.  
";

%feature("docstring") PageXML::getPageNumber "

Gets the page number for the given node.  
";

%feature("docstring") PageXML::setPageImageOrientation "

Sets the image orientation for the given Page node.  

Parameters
----------
* `node` :  
    The page node.  
* `angle` :  
    The orientation angle in degrees {0,90,180,-90}.  
* `_conf` :  
    Pointer to confidence value, NULL for no confidence.  

Normalize angle between [-90,180] ///  
";

%feature("docstring") PageXML::setPageImageOrientation "

Sets the image orientation for the given Page node.  

Parameters
----------
* `node` :  
    The page node.  
* `angle` :  
    The orientation angle in degrees {0,90,180,-90}.  
* `conf` :  
    Confidence value.  
";

%feature("docstring") PageXML::setPageImageOrientation "

Sets the image orientation for the given Page number.  

Parameters
----------
* `pagenum` :  
    The page number (0-based).  
* `angle` :  
    The orientation angle in degrees {0,90,180,-90}.  
* `_conf` :  
    Pointer to confidence value, NULL for no confidence.  
";

%feature("docstring") PageXML::setPageImageOrientation "

Sets the image orientation for the given Page number.  

Parameters
----------
* `pagenum` :  
    The page number (0-based).  
* `angle` :  
    The orientation angle in degrees {0,90,180,-90}.  
* `conf` :  
    Confidence value.  
";

%feature("docstring") PageXML::getPageImageOrientation "

Gets the image orientation for the given node.  

Parameters
----------
* `node` :  
    A node to get its image orientation.  

Returns
-------
Orientation in degrees.  
";

%feature("docstring") PageXML::getPageImageOrientation "

Gets the image orientation for the given Page number.  

Parameters
----------
* `pagenum` :  
    The page number (0-based).  

Returns
-------
Orientation in degrees.  
";

%feature("docstring") PageXML::getPageWidth "

Gets the width of a page (might be different to image width due to the image
orientation).  

Parameters
----------
* `node` :  
    A node to get its page width.  

Returns
-------
The page width.  
";

%feature("docstring") PageXML::getPageWidth "

Gets the width of a page (might be different to image width due to the image
orientation).  

Parameters
----------
* `pagenum` :  
    The page number (0-based).  

Returns
-------
The page width.  
";

%feature("docstring") PageXML::getPageHeight "

Gets the height of a page (might be different to image width due to the image
orientation).  

Parameters
----------
* `node` :  
    A node to get its page height.  

Returns
-------
The page height.  
";

%feature("docstring") PageXML::getPageHeight "

Gets the height of a page (might be different to image width due to the image
orientation).  

Parameters
----------
* `pagenum` :  
    The page number (0-based).  

Returns
-------
The page height.  
";

%feature("docstring") PageXML::setPageWidth "

Sets the width of a page (actually sets imageWidth accounting for image
orientation).  

Parameters
----------
* `node` :  
    A node to set its page width.  
* `width` :  
    The width to set.  
";

%feature("docstring") PageXML::setPageHeight "

Sets the height of a page (actually sets imageHeight accounting for image
orientation).  

Parameters
----------
* `node` :  
    A node to set its page height.  
* `height` :  
    The height to set.  
";

%feature("docstring") PageXML::getPagesSize "

Retrieves pages size.  

Parameters
----------
* `pages` :  
    Page nodes.  

Returns
-------
Vector of page sizes.  
";

%feature("docstring") PageXML::getPagesSize "

Retrieves pages size.  

Parameters
----------
* `xpath` :  
    Selector for Page nodes.  

Returns
-------
Vector of page sizes.  
";

%feature("docstring") PageXML::rotatePage "

Rotates a page.  

Parameters
----------
* `angle` :  
    Angle to rotate in degrees {0,90,180,-90}.  
* `page` :  
    The Page node.  
* `update_image_orientation` :  
    Whether to update the ImageOrientation element.  
* `conf` :  
    Confidence value.  

Returns
-------
Number of elements modified.  
";

%feature("docstring") PageXML::rotatePage "

Rotates a page.  

Parameters
----------
* `angle` :  
    Angle to rotate in degrees {0,90,180,-90}.  
* `page` :  
    The Page node.  
* `update_image_orientation` :  
    Whether to check that the aspect ratio is properly preserved.  
* `_conf` :  
    Pointer to confidence value, NULL for no confidence.  

Returns
-------
Number of elements modified.  

Normalize angle between [-90,180] ///  

Set image orientation ///  

Select all elements with coordinates ///  

Rotate all coordinates ///  
";

%feature("docstring") PageXML::resize "

Resizes pages and all respective coordinates.  

Parameters
----------
* `sizes` :  
    Page sizes to resize to.  
* `pages` :  
    Page nodes.  
* `check_aspect_ratio` :  
    Whether to check that the aspect ratio is properly preserved.  

Returns
-------
Number of pages+points attributes modified.  

Input checks ///  

Check that aspect ratios are the same ///  

For each page update size and resize coords ///  

Resize Coords/ and Baseline/ ///  

Resize Property[='fpgram']/ ///  
";

%feature("docstring") PageXML::resize "

Resizes pages and all respective coordinates.  

Parameters
----------
* `sizes` :  
    Page sizes to resize to.  
* `xpath` :  
    Selector for Page nodes.  
* `check_aspect_ratio` :  
    Whether to check that the aspect ratio is properly preserved.  

Returns
-------
Number of pages+points attributes modified.  
";

%feature("docstring") PageXML::resize "

Resizes a page and all respective coordinates.  

Parameters
----------
* `size` :  
    Page size to resize to.  
* `page` :  
    Page node.  
* `check_aspect_ratio` :  
    Whether to check that the aspect ratio is properly preserved.  

Returns
-------
Number of pages+points attributes modified.  
";

%feature("docstring") PageXML::resize "

Resizes a page and all respective coordinates.  

Parameters
----------
* `factor` :  
    Resizing factor.  
* `xpath` :  
    Selector for Page nodes.  

Returns
-------
Number of pages+points attributes modified.  
";

%feature("docstring") PageXML::setPageImageFilename "

Sets the imageFilename of a page.  
";

%feature("docstring") PageXML::setPageImageFilename "
";

%feature("docstring") PageXML::getPageImageFilename "

Returns the imageFilename of a page.  
";

%feature("docstring") PageXML::getPageImageFilename "
";

%feature("docstring") PageXML::getPageImage "

Returns the image for the given page.  
";

%feature("docstring") PageXML::getPageImage "
";

%feature("docstring") PageXML::addGlyph "

Adds a Glyph to a given node.  

Parameters
----------
* `node` :  
    The node of element to add the Glyph.  
* `id` :  
    ID for Glyph, if NULL it is selected automatically.  
* `before_id` :  
    If !=NULL inserts it before the Glyph with this ID.  

Returns
-------
Pointer to created element.  
";

%feature("docstring") PageXML::addGlyph "

Adds a Glyph to a given xpath.  

Parameters
----------
* `xpath` :  
    Selector for element to set the Glyph.  
* `id` :  
    ID for Glyph, if NULL it is selected automatically.  
* `before_id` :  
    If !=NULL inserts it before the Glyph with this ID.  

Returns
-------
Pointer to created element.  
";

%feature("docstring") PageXML::addWord "

Adds a Word to a given node.  

Parameters
----------
* `node` :  
    The node of element to add the Word.  
* `id` :  
    ID for Word, if NULL it is selected automatically.  
* `before_id` :  
    If !=NULL inserts it before the Word with this ID.  

Returns
-------
Pointer to created element.  
";

%feature("docstring") PageXML::addWord "

Adds a Word to a given xpath.  

Parameters
----------
* `xpath` :  
    Selector for element to set the Word.  
* `id` :  
    ID for Word, if NULL it is selected automatically.  
* `before_id` :  
    If !=NULL inserts it before the Word with this ID.  

Returns
-------
Pointer to created element.  
";

%feature("docstring") PageXML::addTextLine "

Adds a TextLine to a given node.  

Parameters
----------
* `node` :  
    The node of element to add the TextLine.  
* `id` :  
    ID for TextLine, if NULL it is selected automatically.  
* `before_id` :  
    If !=NULL inserts it before the TextLine with this ID.  

Returns
-------
Pointer to created element.  
";

%feature("docstring") PageXML::addTextLine "

Adds a TextLine to a given xpath.  

Parameters
----------
* `xpath` :  
    Selector for element to add the TextLine.  
* `id` :  
    ID for TextLine, if NULL it is selected automatically.  
* `before_id` :  
    If !=NULL inserts it before the TextLine with this ID.  

Returns
-------
Pointer to created element.  
";

%feature("docstring") PageXML::addTextRegion "

Adds a TextRegion to a given node.  

Parameters
----------
* `node` :  
    The node of element to add the TextRegion.  
* `id` :  
    ID for TextRegion, if NULL it is selected automatically.  
* `before_id` :  
    If !=NULL inserts it before the TextRegion with this ID.  
* `prepend` :  
    Whether to add element before all other TextRegions.  

Returns
-------
Pointer to created element.  
";

%feature("docstring") PageXML::addTextRegion "

Adds new TextRegion to a given xpath.  

Parameters
----------
* `xpath` :  
    Selector for element to add the TextRegion.  
* `id` :  
    ID for TextRegion, if NULL it is selected automatically.  
* `before_id` :  
    If !=NULL inserts it before the TextRegion with this ID.  

Returns
-------
Pointer to created element.  
";

%feature("docstring") PageXML::addPage "

Adds a Page to the PcGts node.  

Parameters
----------
* `image` :  
    Path to the image file.  
* `imgW` :  
    Width of image.  
* `imgH` :  
    Height of image.  
* `id` :  
    ID for Page, if NULL it is left unset.  
* `before_node` :  
    If !=NULL inserts it before the provided Page node.  

Returns
-------
Pointer to created element.  
";

%feature("docstring") PageXML::addPage "

Adds a Page to the PcGts node.  

Parameters
----------
* `image` :  
    Path to the image file.  
* `imgW` :  
    Width of image.  
* `imgH` :  
    Height of image.  
* `id` :  
    ID for Page, if NULL it is left unset.  
* `before_node` :  
    If !=NULL inserts it before the provided Page node.  

Returns
-------
Pointer to created element.  
";

%feature("docstring") PageXML::write "

Output ///.  

Writes the current state of the XML to a file using utf-8 encoding.  

Parameters
----------
* `fname` :  
    File name of where the XML file will be written.  

Returns
-------
Number of bytes written.  
";

%feature("docstring") PageXML::toString "

Creates a string representation of the Page XML.  
";

%feature("docstring") PageXML::pointsToOGRpolygon "

Converts Coords to an OGRMultiPolygon.  

Parameters
----------
* `points` :  
    Vector of x,y points.  

Returns
-------
Pointer to OGRMultiPolygon element.  
";

%feature("docstring") PageXML::pointsToOGRpolygons "

Converts Coords to OGRMultiPolygons.  

Parameters
----------
* `points` :  
    Vectors of x,y points.  

Returns
-------
Pointer to OGRMultiPolygon element.  
";

%feature("docstring") PageXML::getOGRpolygon "

Gets an element's Coords as an OGRMultiPolygon.  

Parameters
----------
* `node` :  
    The element from which to extract the Coords points.  
* `xpath` :  
    Selector for the Coords element.  

Returns
-------
Pointer to OGRMultiPolygon element.  
";

%feature("docstring") PageXML::getOGRpolygons "

Gets elements' Coords as OGRMultiPolygons.  

Parameters
----------
* `nodes` :  
    Elements from which to extract the Coords points.  
* `xpath` :  
    Selector for the Coords element.  

Returns
-------
Vector of OGRMultiPolygon pointer elements.  
";

%feature("docstring") PageXML::getUnionOGRpolygon "

Gets the union of Coords elements as a OGRMultiPolygon.  

Parameters
----------
* `nodes` :  
    Elements from which to extract the Coords points.  
* `xpath` :  
    Selector for the Coords element.  

Returns
-------
Pointer to OGRMultiPolygon element.  
";

%feature("docstring") PageXML::getOGRpolygonArea "

Gets the area of a OGRMultiPolygon.  

Parameters
----------
* `poly` :  
    OGRMultiPolygon pointer.  

Returns
-------
Area.  
";

%feature("docstring") PageXML::getOGRpolyline "

Gets the element's Baseline as an OGRMultiLineString.  

Parameters
----------
* `node` :  
    The element from which to extract the Baseline points.  

Returns
-------
Pointer to OGRMultiLineString element.  
";

%feature("docstring") PageXML::multiPolylineIntersection "

Computes the intersection between a multipolylines and a multipolygon.  

Parameters
----------
* `poly1` :  
    Polyline.  
* `poly2` :  
    Polygon.  

Returns
-------
Intersection geometry.  
";

%feature("docstring") PageXML::multiPolygonIntersection "

Computes the intersection of two multipolygons.  

Parameters
----------
* `poly1` :  
    First polygon.  
* `poly2` :  
    Second polygon.  

Returns
-------
Intersection geometry.  
";

%feature("docstring") PageXML::computeIntersectFactor "

Computes the intersection factor of one multipolygon over another.  

Parameters
----------
* `poly1` :  
    First polygon.  
* `poly2` :  
    Second polygon.  

Returns
-------
Factor value.  
";

%feature("docstring") PageXML::computeIntersectFactor "

Computes the intersection factor of one polyline over polygon.  

Parameters
----------
* `poly1` :  
    Polyline.  
* `poly2` :  
    Polygon.  

Returns
-------
Factor value.  
";

%feature("docstring") PageXML::computeIoU "

Computes the intersection over union (IoU) of two polygons.  

Parameters
----------
* `poly1` :  
    First polygon.  
* `poly2` :  
    Second polygon.  

Returns
-------
IoU value.  
";

%feature("docstring") PageXML::computeIoUs "

Computes the intersection over unions (IoU) of polygons.  

Parameters
----------
* `poly` :  
    Polygon.  
* `polys` :  
    Vector of polygons.  

Returns
-------
IoU values.  
";

%feature("docstring") PageXML::computeIntersectionPercentage "

Computes the intersection percentage of one polygon with respect to another
polygons.  

Parameters
----------
* `poly1` :  
    First polygon.  
* `poly2` :  
    Second polygon.  

Returns
-------
Intersection percentage value.  
";

%feature("docstring") PageXML::computeIntersectionPercentages "

Computes the intersection percentage of one polygon with respect to other
polygons.  

Parameters
----------
* `poly` :  
    Polygon.  
* `polys` :  
    Vector of polygons.  

Returns
-------
Intersection percentage values.  
";

%feature("docstring") PageXML::computeAreas "

Computes the areas for given polygons.  

Parameters
----------
* `polys` :  
    Polygons to process.  

Returns
-------
The polygon areas.  
";

%feature("docstring") PageXML::computeCoordsIntersectionsWeightedByArea "

Computes polygon-polygon intersections weighted by area.  

Parameters
----------
* `poly` :  
    Polygon.  
* `polys` :  
    Polygons to compare with.  
* `areas` :  
    Polygons areas.  

Returns
-------
Obtained intersection scores.  

Check input ///  

Compute intersections ///  

Return if fewer than 2 intersects ///  

Weight by areas ///  
";

%feature("docstring") PageXML::computeBaselineIntersectionsWeightedByArea "

Computes line-polygon intersections weighted by area.  

Parameters
----------
* `poly` :  
    Polyline.  
* `polys` :  
    Polygons to compare with.  
* `areas` :  
    Polygons areas.  

Returns
-------
Obtained intersection scores.  

Check input ///  

Compute intersections ///  

Return if fewer than 2 intersects ///  

Weight by areas ///  
";

%feature("docstring") PageXML::selectByOverlap "

Selects elements based on overlap to a polygon.  

Parameters
----------
* `points` :  
    Polygon for selection.  
* `page` :  
    Page element for selection.  
* `xpath` :  
    xpath for candidate elements for selection.  
* `overlap_thr` :  
    Overlapping score threshold.  
* `overlap_type` :  
    Type of overlap to use for selecting.  

Returns
-------
Number of TextLines copied.  

OGR polygon(s) for selection ///  

Get areas for overlap computation ///  

Loop through elements ///  

Compute overlap scores ///  

Add if higher than threshold ///  
";

%feature("docstring") PageXML::selectByOverlap "

Selects elements based on overlap to a polygon.  

Parameters
----------
* `points` :  
    Polygon for selection.  
* `pagenum` :  
    Page number for selection.  
* `xpath` :  
    xpath for candidate elements for selection.  
* `overlap_thr` :  
    Overlapping score threshold.  
* `overlap_type` :  
    Type of overlap to use for selecting.  

Returns
-------
Number of TextLines copied.  
";

%feature("docstring") PageXML::copyTextLinesAssignByOverlap "

Copies TextLines from one page xml to another assigning to regions based on
overlap.  

Parameters
----------
* `pageFrom` :  
    PageXML from where to copy TextLines.  
* `overlap_type` :  
    Type of overlap to use for assigning lines to regions.  
* `overlap_fact` :  
    Overlapping factor.  

Returns
-------
Number of TextLines copied.  

Loop through pages ///  

Check that image size is the same in both PageXMLs ///  

Select page region or create one if it does not exist ///  

Select relevant elements ///  

Get polygons of regions for IoU computation ///  

Loop through lines ///  

Compute overlap scores ///  

Clone line and add it to the destination region node ///  

Remove added page region if no TextLine was added to it ///  
";

%feature("docstring") PageXML::getLeftRightTextContinuationGroups "

Determines groups of left-right text elem continuations (requires single segment
polystripe).  

Parameters
----------
* `elems` :  
    Text elements to test for continuation: TextLines, Words, Glyphs or
    TextRegions.  
* `_group_order` :  
    Join groups line indices (output).  
* `_group_score` :  
    Join group scores (output).  
* `max_angle_diff` :  
    Maximum baseline angle difference for joining.  
* `max_horiz_iou` :  
    Maximum horizontal IoU for joining.  
* `min_prolong_fact` :  
    Minimum prolongation factor for joining.  
* `prolong_alpha` :  
    Weight for prolongation factors: alpha*bline+(1-alpha)*coords.  
* `fake_baseline` :  
    Use bottom line of Coords rectangle as the baseline.  
* `recurse_factor` :  
    Multiplication factor for continuation criteria on each recursion.  

Returns
-------
Number of join groups, elements per group in order and group scores.  

Get points and compute baseline angles and lengths ///  

Loop through all directed pairs of text elems ///  

Check that baseline angle difference is small ///  

Project baseline limits onto the local horizontal axis ///  

Check that elem n starts before elem m ///  

Check that horizontal IoU is small //  

Compute coords endpoint-startpoint intersection factors /// (both ways,
intersection length of prolongated elem 1 and elem 2 divided by height of elem
2) /// Todo
Possible improvement: coords_fact_xx = isect_1d / min(norm_n,norm_m)  

Compute baseline alignment factors /// (both ways, one minus distance between
prolongated baseline 1 and baseline 2 divided by height of elem 2 ) /// Todo
Possible improvement: max( 0, 1-norm(isec_xx-bline_x)/max(norm_n,norm_m) )  

Overall alignment factor ///  

Add text elem to a group (new or existing) ///  

Check if should be part of existing group ///  

Unique existing group ///  

Two existing groups, thus merge groups ///  

Update groups ///  

Adjust text elem order for groups with more than two text elems ///  

Get horizontal direction ///  

Check if there is high horizontal overlaps within group ///  

If high overlap recurse with stricter criterion ///  

Project baseline centers onto the local horizontal axis ///  

Sort text elems by horizontal center projections ///  

Score as average of scores ///  

Add recursed extra groups ///  

Sort groups based on first element original order ///  
";

%feature("docstring") PageXML::getLeftRightTopBottomReadingOrder "

Gets the reading order for a set of text elems (requires single segment
polystripe).  

Parameters
----------
* `elems` :  
    Elements to process: TextLines, Words, Glyphs or TextRegions.  
* `max_angle_diff` :  
    Maximum baseline angle difference for joining.  
* `max_horiz_iou` :  
    Maximum horizontal IoU for joining.  
* `min_prolong_fact` :  
    Minimum prolongation factor for joining.  
* `prolong_alpha` :  
    Weight for prolongation factors: alpha*bline+(1-alpha)*coords.  
* `fake_baseline` :  
    Use bottom line of Coords rectangle as the baseline.  
* `recurse_factor` :  
    Multiplication factor for continuation criteria on each recursion.  

Returns
-------
Pair of reading order indices and subgroup lengths.  

Get text elem join groups ///  

Get points and compute baseline angles and lengths ///  

Get horizontal direction ///  

Add text elems not in join groups ///  

Get vertical group center projections ///  

Sort groups by vertical center projections ///  

Populate reading order vector ///  
";

%feature("docstring") PageXML::getDocPtr "

Returns the XML document pointer.  
";

// File: structrgb.xml


%feature("docstring") rgb "

C++ includes: mem.h
";

// File: class_text_feat_extractor.xml


%feature("docstring") TextFeatExtractor "

C++ includes: TextFeatExtractor.h
";

%feature("docstring") TextFeatExtractor::version "

Returns the class version.  
";

%feature("docstring") TextFeatExtractor::TextFeatExtractor "

Constructors ///.  
";

%feature("docstring") TextFeatExtractor::printConf "

Configuration ///.  

Prints the current configuration.  

Parameters
----------
* `file` :  
    File to print to.  
";

%feature("docstring") TextFeatExtractor::preprocess "

Pre-processes a text image, optionally computing the connected components
contour.  

Parameters
----------
* `image` :  
    Image to process.  
* `_fcontour` :  
    Output contour points, set to NULL to skip computation.  
* `randomize` :  
    Whether to do a random perturbation of preprocessing parameters.  

Convert to grayscale ///  

Contrast stretching ///  

Text image enhancement ///  

Random perturbation ///  

Compute connected components contour polygon ///  

Binalize image ///  

Add border ///  

Apply RLSA ///  

Join connected components ///  

Dilate using disk structural element ///  

Get contour coordinates ///  
";

%feature("docstring") TextFeatExtractor::estimateAngles "

Estimates slope and slant angles for an image.  

Parameters
----------
* `image` :  
    Image to process.  
* `_slope` :  
    Estimated slope angle in degrees.  
* `_slant` :  
    Estimated slant angle in degrees.  

Estimate line slope angle ///  

Estimate writing slant angle ///  
";

%feature("docstring") TextFeatExtractor::extractFeats "

Extracts features for the given image already preprocessed image.  

Parameters
----------
* `feaimg` :  
    Image to process.  
* `slope` :  
    Slope angle in degrees.  
* `slant` :  
    Slant angle in degrees.  
* `_fpgram` :  
    Output features parallelogram coordinates.  
* `randomize` :  
    Whether to do a random perturbation of extraction parameters.  

Returns
-------
Features matrix.  

Set image transparent zones to white ///  

Random slant ///  

Apply affine transformation considering both slope and slant ///  

Trim image ///  

Momentum normalization ///  

Normalize x-height ///  

Random scaling ///  

Add left and right padding ///  

Account for reading direction ///  

Compute features parallelogram ///  

Compute features ///  
";

%feature("docstring") TextFeatExtractor::isImageFormat "

Whether the configured output format is image.  
";

%feature("docstring") TextFeatExtractor::write "

Prints features to a file stream using the configured output format.  

Parameters
----------
* `feats` :  
    OpenCV matrix containing the features.  
* `file` :  
    File stream to write the features.  
";

%feature("docstring") TextFeatExtractor::write "

Writes features to a file using the configured output format.  

Parameters
----------
* `feats` :  
    OpenCV matrix containing the features.  
* `file` :  
    File name of where to write the features.  
";

// File: namespacestd.xml

// File: namespacestd_1_1chrono.xml

// File: intimg_8cc.xml

%feature("docstring") malloc_II1 "

Functions related to integral images  

copyright: Copyright (c) 2004-present, Mauricio Villegas
    mauricio_ville@yahoo.com  MIT License  
";

%feature("docstring") malloc_II2 "
";

%feature("docstring") compII12_graym "
";

%feature("docstring") cropsum_II "
";

%feature("docstring") mean_II "
";

%feature("docstring") sd_II "
";

%feature("docstring") meanSd_II "
";

%feature("docstring") meanSdCW_II "
";

%feature("docstring") enhSauvola_single "
";

%feature("docstring") enhWolf_single "
";

%feature("docstring") minValmaxStd "
";

%feature("docstring") enhLocal_graym "
";

%feature("docstring") enhSauvola_sample_prm_graym "
";

// File: intimg_8h.xml

%feature("docstring") malloc_II1 "

Functions related to integral images  

copyright: Copyright (c) 2004-present, Mauricio Villegas
    mauricio_ville@yahoo.com  MIT License  
";

%feature("docstring") malloc_II2 "
";

%feature("docstring") compII12_graym "
";

%feature("docstring") cropsum_II "
";

%feature("docstring") mean_II "
";

%feature("docstring") sd_II "
";

%feature("docstring") meanSd_II "
";

%feature("docstring") enhLocal_graym "
";

%feature("docstring") enhSauvola_graym "
";

%feature("docstring") enhSauvola_sample_prm_graym "
";

// File: mem_8cc.xml

%feature("docstring") bfree "

Functions for allocating memory  

copyright: Copyright (c) 2004-present, Mauricio Villegas
    mauricio_ville@yahoo.com  MIT License  
";

%feature("docstring") zeros_I1 "
";

%feature("docstring") zeros_F1 "
";

%feature("docstring") zeros_D1 "
";

%feature("docstring") copy_I1 "
";

%feature("docstring") copy_F1 "
";

%feature("docstring") copy_D1 "
";

%feature("docstring") clone_graym "
";

%feature("docstring") clone_pixelm "
";

%feature("docstring") malloc_grayv "
";

%feature("docstring") malloc_pixelv "
";

%feature("docstring") malloc_I1v "
";

%feature("docstring") malloc_F1v "
";

%feature("docstring") malloc_D1v "
";

%feature("docstring") malloc_iI1v "
";

%feature("docstring") malloc_iF1v "
";

%feature("docstring") malloc_IV2v "
";

%feature("docstring") malloc_graym "
";

%feature("docstring") malloc_pixelm "
";

%feature("docstring") malloc_I1m "
";

%feature("docstring") malloc_F1m "
";

%feature("docstring") malloc_D1m "
";

%feature("docstring") malloc_F1t "
";

%feature("docstring") malloc_D1t "
";

%feature("docstring") nullfree "
";

%feature("docstring") mclone "
";

%feature("docstring") mem "
";

%feature("docstring") mmem "
";

%feature("docstring") bmem "
";

%feature("docstring") tmem "
";

%feature("docstring") vrmem_index "
";

%feature("docstring") vrmem "
";

// File: mem_8h.xml

%feature("docstring") bfree "

Functions for allocating memory  

copyright: Copyright (c) 2004-present, Mauricio Villegas
    mauricio_ville@yahoo.com  MIT License  
";

%feature("docstring") zeros_I1 "
";

%feature("docstring") zeros_F1 "
";

%feature("docstring") zeros_D1 "
";

%feature("docstring") copy_I1 "
";

%feature("docstring") copy_F1 "
";

%feature("docstring") copy_D1 "
";

%feature("docstring") clone_graym "
";

%feature("docstring") clone_pixelm "
";

%feature("docstring") malloc_grayv "
";

%feature("docstring") malloc_pixelv "
";

%feature("docstring") malloc_I1v "
";

%feature("docstring") malloc_F1v "
";

%feature("docstring") malloc_D1v "
";

%feature("docstring") malloc_iI1v "
";

%feature("docstring") malloc_iF1v "
";

%feature("docstring") malloc_IV2v "
";

%feature("docstring") malloc_graym "
";

%feature("docstring") malloc_pixelm "
";

%feature("docstring") malloc_I1m "
";

%feature("docstring") malloc_F1m "
";

%feature("docstring") malloc_D1m "
";

%feature("docstring") malloc_F1t "
";

%feature("docstring") malloc_D1t "
";

%feature("docstring") nullfree "
";

%feature("docstring") mclone "
";

%feature("docstring") mem "
";

%feature("docstring") mmem "
";

%feature("docstring") bmem "
";

%feature("docstring") tmem "
";

%feature("docstring") vrmem_index "
";

%feature("docstring") vrmem "
";

// File: _page_x_m_l_8cc.xml

%feature("docstring") std::reXheight "
";

%feature("docstring") std::reRotation "
";

%feature("docstring") std::reDirection "
";

%feature("docstring") std::reFileExt "
";

%feature("docstring") std::reInvalidBaseChars "
";

%feature("docstring") std::reImagePageNum "
";

%feature("docstring") std::reIsPdf "
";

%feature("docstring") std::reIsTiff "
";

%feature("docstring") std::validationErrorFunc "

Schema validation ///.  
";

%feature("docstring") std::validationWarningFunc "
";

%feature("docstring") std::mktemp "

Function that creates a temporal file using the mktemp command  

Parameters
----------
* `tempbase` :  
    The mktemp template to use, including at least 3 consecutive X.  
";

%feature("docstring") std::project_2d_to_1d "

Projects points onto a line defined by a direction and y-offset  
";

%feature("docstring") std::angleDiff "

Computes the difference between two angles [-PI,PI] accounting for the
discontinuity  
";

%feature("docstring") std::intersection_1d "

Computes the 1D intersection  
";

%feature("docstring") std::IoU_1d "

Computes the 1D intersection over union  
";

%feature("docstring") std::withinSegment "

Checks if a point is within a line segment  

Parameters
----------
* `segm_start` :  
    Point for begining of segment.  
* `segm_end` :  
    Point for end of segment.  
* `point` :  
    Point to check withiness.  

Returns
-------
0 if within segment, +1 if outside but aligned to the right, -1 if outside but
aligned to the left, otherwise NaN.  

check collinearity (normalized triangle area) ///  

return zero if in segment ///  

return +1 if to the right and -1 if to the left ///  
";

// File: _page_x_m_l_8h.xml

// File: _text_feat_extractor_8cc.xml

%feature("docstring") std::chrono::colorWhite "
";

%feature("docstring") std::chrono::colorBlack "
";

%feature("docstring") std::chrono::print_int "

Loaders ///.  

Loads the projecton matrix from an hdf5 file.  

Parameters
----------
* `projfile` :  
    File from which to read the projection.Features output /// Prints a long in
    binary.  
";

%feature("docstring") std::chrono::print_short "

Prints an int in binary.  
";

%feature("docstring") std::chrono::print_float "

Prints a float in binary.  
";

%feature("docstring") std::chrono::print_features_htk "

Prints features to a file stream using HTK format.  

Parameters
----------
* `feats` :  
    OpenCV matrix containing the features.  
* `file` :  
    File stream to print the features.  
";

%feature("docstring") std::chrono::print_features_ascii "

Prints features to a file stream using ASCII format.  

Parameters
----------
* `feats` :  
    OpenCV matrix containing the features.  
* `file` :  
    File stream to print the features.  
";

%feature("docstring") std::chrono::magick2cvmat8u "

Image processing ///.  

Copies image data from Magick::Image to an OpenCV Mat.  

Parameters
----------
* `image` :  
    Magick++ Image object.  
* `cvimg` :  
    OpenCV Mat.  
";

%feature("docstring") std::chrono::magick2cvmat8uc3 "
";

%feature("docstring") std::chrono::magick2graym "

Copies image data from Magick::Image to an unsigned char matrix.  

Parameters
----------
* `image` :  
    Magick++ Image object.  
* `gimg` :  
    Unsigned char matrix (it is allocated if NULL).  
* `_alpha` :  
    Pointer to unsigned char matrix for alpha channel (it is allocated if NULL).  
";

%feature("docstring") std::chrono::to16bits "

Converts unsigned char to 16-bits.  
";

%feature("docstring") std::chrono::graym2magick "

Copies image data from unsigned char matrix to Magick::Image.  

Parameters
----------
* `image` :  
    Magick++ Image object.  
* `gimg` :  
    Unsigned char matrix.  
* `alpha` :  
    Unsigned char matrix for alpha channel.  
";

%feature("docstring") std::chrono::grayms2magick "

Copies image data from unsigned char matrix to Magick::Image.  

Parameters
----------
* `image` :  
    Magick++ Image object.  
* `gimg` :  
    Unsigned char matrix.  
* `alpha` :  
    Unsigned char matrix for alpha channel.  
";

%feature("docstring") std::chrono::cvmat8u2magick "

Copies image data from an OpenCV Mat to Magick::Image.  

Parameters
----------
* `image` :  
    Magick++ Image object.  
* `cvimg` :  
    OpenCV Mat.  
";

%feature("docstring") std::chrono::cvmat8u2magick "

Copies image data from an OpenCV Mat to Magick::Image.  

Parameters
----------
* `image` :  
    Magick++ Image object.  
* `cvimg` :  
    OpenCV Mat.  
* `cvimg_alpha` :  
    OpenCV Mat.  
";

%feature("docstring") std::chrono::cvmat8uc32magick "

Copies image data from an OpenCV Mat to Magick::Image.  

Parameters
----------
* `image` :  
    Magick++ Image object.  
* `cvimg` :  
    OpenCV Mat.  
";

%feature("docstring") std::chrono::enhance "

Does a local enhancement of a text image.  

Parameters
----------
* `image` :  
    Magick++ Image object.  
* `winW` :  
    Window width for local enhancement.  
* `prm` :  
    Enhancement parameter.  
* `slp` :  
    Gray slope parameter.  
* `type` :  
    Enhancement algorithm.  
";

%feature("docstring") std::chrono::rlsa4_graym "
";

%feature("docstring") std::chrono::findMinMax "
";

%feature("docstring") std::chrono::estimateSlant "

Estimates the slant angle of an image containing handwritten text.  

Parameters
----------
* `image` :  
    Magick++ Image object.  
* `amin` :  
    Minimum slant angle in degrees.  
* `amax` :  
    Maximum slant angle in degrees.  
* `amin` :  
    Slant angle step in degrees.  

Returns
-------
Estimated slant angle in degrees.  
Todo
If alpha channel, do not project transparent  

List angles for pyramidal sampling ///  

Pyramidal sampling loop ///  

Initially only sample every skip angles ///  

Then sample on both sides of large found values, each time with half the skip
///  

Project for the current angle ///  

Compute variance of projection ///  
";

%feature("docstring") std::chrono::findOuterContours "

Gets outer contour points of connected components in an image, optionally
approximating it.  

Parameters
----------
* `image` :  
    Magick++ Image object.  
* `contours` :  
    Output array of arrays containing the contours.  
* `method` :  
    Contour approximation method.  
* `eps` :  
    Epsilon for approxPolyDP, zero to disable.  

Get outer contours ///  

Approximate contours ///  

If no contours, use full image as contour ///  

Add image page offset to contour coordinates ///  
";

%feature("docstring") std::chrono::joinComponents "

Joints all connected components in an image using 1px thick lines between
nearest contour points.  

Parameters
----------
* `image` :  
    Magick++ Image object.  

Get external contours ///  

Prepare contours nearest neighbor search ///  

Loop through all contours ///  

Copy x-th component coordinates for test ///  

Copy all other component coordinates for reference ///  

Find nearest neighbors ///  

Relabel joined components ///  

Join components with a line ///  
";

%feature("docstring") std::chrono::toGrayscale "

Converts image to grayscale preserving alpha channel if present.  

Parameters
----------
* `image` :  
    Image to process.  

Returns
-------
Whether the conversion was performed.  
";

%feature("docstring") std::chrono::flattenImage "

Removes alpha channel, setting all transparent regions to the background color.  

Parameters
----------
* `image` :  
    Image to process.  
* `color` :  
    Color for the background.  

Returns
-------
Whether flattening was performed.  
";

// File: _text_feat_extractor_8h.xml

// File: todo.xml

