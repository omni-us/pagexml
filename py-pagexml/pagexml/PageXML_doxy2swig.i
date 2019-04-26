// File: xml/class_page_x_m_l.xml

%feature("docstring") PageXML::PageXML "
PageXML constructor that receives a file name to load.

Arguments:
    pagexml_path (const char *): Path to the XML file to read.
    schema_path (const char *): Path to the XSD file to read.

";

%feature("docstring") PageXML::addElem "
Overloaded function with 3 signatures.

**Signature 1**

``xmlNodePt PageXML::addElem(const char *name, const char *id, const xmlNodePt node, PAGEXML_INSERT itype=PAGEXML_INSERT_APPEND, bool checkid=false)``

Creates a new element and adds it relative to a given node.

Arguments:
    name (const char *): Name of element to create.
    id (const char *): ID attribute for element.
    node (const xmlNodePt): Reference element for insertion.
    itype (PAGEXML_INSERT): Type of insertion.
    checkid (bool): Whether to check if the id already exists.

Returns:
    xmlNodePt: Pointer to created element.

**Signature 2**

``xmlNodePt PageXML::addElem(const char *name, const char *id, const char *xpath, PAGEXML_INSERT itype=PAGEXML_INSERT_APPEND, bool checkid=false)``

Creates a new element and adds it relative to a given xpath.

Arguments:
    name (const char *): Name of element to create.
    id (const char *): ID attribute for element.
    xpath (const char *): Selector for insertion.
    itype (PAGEXML_INSERT): Type of insertion.
    checkid (bool): Whether to check if the id already exists.

Returns:
    xmlNodePt: Pointer to created element.

**Signature 3**

``xmlNodePt PageXML::addElem(const std::string name, const std::string id, const std::string xpath, PAGEXML_INSERT itype=PAGEXML_INSERT_APPEND, bool checkid=false)``

Arguments:
    name (const std::string): 
    id (const std::string): 
    xpath (const std::string): 
    itype (PAGEXML_INSERT): 
    checkid (bool): 

Returns:
    xmlNodePt: 

";

%feature("docstring") PageXML::addGlyph "
Overloaded function with 2 signatures.

**Signature 1**

``xmlNodePt PageXML::addGlyph(xmlNodePt node, const char *id=NULL, const char *before_id=NULL)``

Adds a Glyph to a given node.

Arguments:
    node (xmlNodePt): The node of element to add the Glyph.
    id (const char *): ID for Glyph, if NULL it is selected automatically.
    before_id (const char *): If !=NULL inserts it before the Glyph with this ID.

Returns:
    xmlNodePt: Pointer to created element.

**Signature 2**

``xmlNodePt PageXML::addGlyph(const char *xpath, const char *id=NULL, const char *before_id=NULL)``

Adds a Glyph to a given xpath.

Arguments:
    xpath (const char *): Selector for element to set the Glyph.
    id (const char *): ID for Glyph, if NULL it is selected automatically.
    before_id (const char *): If !=NULL inserts it before the Glyph with this ID.

Returns:
    xmlNodePt: Pointer to created element.

";

%feature("docstring") PageXML::addPage "
Overloaded function with 2 signatures.

**Signature 1**

``xmlNodePt PageXML::addPage(const char *image, const int imgW, const int imgH, const char *id=NULL, xmlNodePt before_node=NULL)``

Adds a Page to the PcGts node.

Arguments:
    image (const char *): Path to the image file.
    imgW (const int): Width of image.
    imgH (const int): Height of image.
    id (const char *): ID for Page, if NULL it is left unset.
    before_node (xmlNodePt): If !=NULL inserts it before the provided Page node.

Returns:
    xmlNodePt: Pointer to created element.

**Signature 2**

``xmlNodePt PageXML::addPage(std::string image, const int imgW, const int imgH, const char *id=NULL, xmlNodePt before_node=NULL)``

Adds a Page to the PcGts node.

Arguments:
    image (std::string): Path to the image file.
    imgW (const int): Width of image.
    imgH (const int): Height of image.
    id (const char *): ID for Page, if NULL it is left unset.
    before_node (xmlNodePt): If !=NULL inserts it before the provided Page node.

Returns:
    xmlNodePt: Pointer to created element.

";

%feature("docstring") PageXML::addTextLine "
Overloaded function with 2 signatures.

**Signature 1**

``xmlNodePt PageXML::addTextLine(xmlNodePt node, const char *id=NULL, const char *before_id=NULL)``

Adds a TextLine to a given node.

Arguments:
    node (xmlNodePt): The node of element to add the TextLine.
    id (const char *): ID for TextLine, if NULL it is selected automatically.
    before_id (const char *): If !=NULL inserts it before the TextLine with this ID.

Returns:
    xmlNodePt: Pointer to created element.

**Signature 2**

``xmlNodePt PageXML::addTextLine(const char *xpath, const char *id=NULL, const char *before_id=NULL)``

Adds a TextLine to a given xpath.

Arguments:
    xpath (const char *): Selector for element to add the TextLine.
    id (const char *): ID for TextLine, if NULL it is selected automatically.
    before_id (const char *): If !=NULL inserts it before the TextLine with this ID.

Returns:
    xmlNodePt: Pointer to created element.

";

%feature("docstring") PageXML::addTextRegion "
Overloaded function with 2 signatures.

**Signature 1**

``xmlNodePt PageXML::addTextRegion(xmlNodePt node, const char *id=NULL, const char *before_id=NULL, bool prepend=false)``

Adds a TextRegion to a given node.

Arguments:
    node (xmlNodePt): The node of element to add the TextRegion.
    id (const char *): ID for TextRegion, if NULL it is selected automatically.
    before_id (const char *): If !=NULL inserts it before the TextRegion with this ID.
    prepend (bool): Whether to add element before all other TextRegions.

Returns:
    xmlNodePt: Pointer to created element.

**Signature 2**

``xmlNodePt PageXML::addTextRegion(const char *xpath, const char *id=NULL, const char *before_id=NULL, bool prepend=false)``

Adds new TextRegion to a given xpath.

Arguments:
    xpath (const char *): Selector for element to add the TextRegion.
    id (const char *): ID for TextRegion, if NULL it is selected automatically.
    before_id (const char *): If !=NULL inserts it before the TextRegion with this ID.
    prepend (bool): 

Returns:
    xmlNodePt: Pointer to created element.

";

%feature("docstring") PageXML::addWord "
Overloaded function with 2 signatures.

**Signature 1**

``xmlNodePt PageXML::addWord(xmlNodePt node, const char *id=NULL, const char *before_id=NULL)``

Adds a Word to a given node.

Arguments:
    node (xmlNodePt): The node of element to add the Word.
    id (const char *): ID for Word, if NULL it is selected automatically.
    before_id (const char *): If !=NULL inserts it before the Word with this ID.

Returns:
    xmlNodePt: Pointer to created element.

**Signature 2**

``xmlNodePt PageXML::addWord(const char *xpath, const char *id=NULL, const char *before_id=NULL)``

Adds a Word to a given xpath.

Arguments:
    xpath (const char *): Selector for element to set the Word.
    id (const char *): ID for Word, if NULL it is selected automatically.
    before_id (const char *): If !=NULL inserts it before the Word with this ID.

Returns:
    xmlNodePt: Pointer to created element.

";

%feature("docstring") PageXML::areIDsUnique "
Verifies that all IDs in page are unique.


Returns:
    bool: 

";

%feature("docstring") PageXML::clone "

Returns:
    PageXML: 

";

%feature("docstring") PageXML::closest "
Selects closest node of a given name.

Arguments:
    name (const char *): Name of node to search for closest.
    node (xmlNodePt): Base node to start the search from.

Returns:
    xmlNodePt: Pointer to the matched closest element or NULL if nothing matched.

";

%feature("docstring") PageXML::computeAreas "
Computes the areas for given polygons.

Arguments:
    polys (std::vector< OGRMultiPolygonPtr_ >): Polygons to process.

Returns:
    std::vector< double >: The polygon areas.

";

%feature("docstring") PageXML::computeBaselineIntersectionsWeightedByArea "
Computes line-polygon intersections weighted by area.

Arguments:
    poly (OGRMultiLineStringPtr_): Polyline.
    polys (std::vector< OGRMultiPolygonPtr_ >): Polygons to compare with.
    areas (std::vector< double >): Polygons areas.

Returns:
    std::vector< double >: Obtained intersection scores.

";

%feature("docstring") PageXML::computeCoordsIntersectionsWeightedByArea "
Computes polygon-polygon intersections weighted by area.

Arguments:
    poly (OGRMultiPolygonPtr_): Polygon.
    polys (std::vector< OGRMultiPolygonPtr_ >): Polygons to compare with.
    areas (std::vector< double >): Polygons areas.

Returns:
    std::vector< double >: Obtained intersection scores.

";

%feature("docstring") PageXML::computeIntersectFactor "
Overloaded function with 2 signatures.

**Signature 1**

``double PageXML::computeIntersectFactor(OGRMultiPolygonPtr_ poly1, OGRMultiPolygonPtr_ poly2)``

Computes the intersection factor of one multipolygon over another.

Arguments:
    poly1 (OGRMultiPolygonPtr_): First polygon.
    poly2 (OGRMultiPolygonPtr_): Second polygon.

Returns:
    double: Factor value.

**Signature 2**

``double PageXML::computeIntersectFactor(OGRMultiLineStringPtr_ poly1, OGRMultiPolygonPtr_ poly2)``

Computes the intersection factor of one polyline over polygon.

Arguments:
    poly1 (OGRMultiLineStringPtr_): Polyline.
    poly2 (OGRMultiPolygonPtr_): Polygon.

Returns:
    double: Factor value.

";

%feature("docstring") PageXML::computeIntersectionPercentage "
Computes the intersection percentage of one polygon with respect to another polygons.

Arguments:
    poly1 (OGRMultiPolygonPtr_): First polygon.
    poly2 (OGRMultiPolygonPtr_): Second polygon.

Returns:
    double: Intersection percentage value.

";

%feature("docstring") PageXML::computeIntersectionPercentages "
Computes the intersection percentage of one polygon with respect to other polygons.

Arguments:
    poly (OGRMultiPolygonPtr_): Polygon.
    polys (std::vector< OGRMultiPolygonPtr_ >): Vector of polygons.

Returns:
    std::vector< double >: Intersection percentage values.

";

%feature("docstring") PageXML::computeIoU "
Computes the intersection over union (IoU) of two polygons.

Arguments:
    poly1 (OGRMultiPolygonPtr_): First polygon.
    poly2 (OGRMultiPolygonPtr_): Second polygon.

Returns:
    double: IoU value.

";

%feature("docstring") PageXML::computeIoUs "
Computes the intersection over unions (IoU) of polygons.

Arguments:
    poly (OGRMultiPolygonPtr_): Polygon.
    polys (std::vector< OGRMultiPolygonPtr_ >): Vector of polygons.

Returns:
    std::vector< double >: IoU values.

";

%feature("docstring") PageXML::copyElem "
Clone an element and add it relative to a given node.

Arguments:
    elem (xmlNodePt): Element to clone.
    node (const xmlNodePt): Reference element for insertion.
    itype (PAGEXML_INSERT): Type of insertion.

Returns:
    xmlNodePt: Pointer to cloned element.

";

%feature("docstring") PageXML::copyTextLinesAssignByOverlap "
Copies TextLines from one page xml to another assigning to regions based on overlap.

Arguments:
    pageFrom (PageXML &): PageXML from where to copy TextLines.
    overlap_thr (double): Overlapping score threshold. If overlap below threshold, TextLine is copied to the page region.
    overlap_type (PAGEXML_OVERLAP): Type of overlap to use for assigning lines to regions.
    comb_alpha (double): Weight for overlap factors: alpha*bline+(1-alpha)*coords. Only for PAGEXML_OVERLAP_COORDS_BASELINE_IWA.
    verbose (bool): 

Returns:
    int: Number of TextLines copied.

";

%feature("docstring") PageXML::count "
Overloaded function with 2 signatures.

**Signature 1**

``int PageXML::count(const char *xpath, xmlNodePt node=NULL)``

Returns number of matched nodes for a given xpath.

Arguments:
    xpath (const char *): Selector expression.
    node (xmlNodePt): XML node for context, set to NULL for root node.

Returns:
    int: Number of matched nodes.

**Signature 2**

``int PageXML::count(std::string xpath, xmlNodePt node=NULL)``

Arguments:
    xpath (std::string): 
    node (xmlNodePt): 

Returns:
    int: 

";

%feature("docstring") PageXML::crop "
Overloaded function with 2 signatures.

**Signature 1**

``std::vector< NamedImage > PageXML::crop(const char *xpath, cv::Point2f *margin=NULL, bool opaque_coords=true, const char *transp_xpath=NULL, const char *base_xpath=NULL)``

Crops images using its Coords polygon, regions outside the polygon are set to transparent.

Arguments:
    xpath (const char *): Selector for Coord nodes to crop.
    margin (cv::Point2f *): Margins, if >1.0 it is considered pixels, otherwise percentage of maximum between crop width and height.
    opaque_coords (bool): Whether to include an alpha channel with the polygon interior in opaque.
    transp_xpath (const char *): Selector for semi-transparent elements.
    base_xpath (const char *): Expression to construct sample name, overriding the default IMGBASE.ELEMID.

Returns:
    std::vector< NamedImage >: An std::vector containing NamedImage objects of the cropped images.

**Signature 2**

``std::vector< NamedImage > PageXML::crop(std::vector< xmlNodePt > elems_coords, cv::Point2f *margin=NULL, bool opaque_coords=true, const char *transp_xpath=NULL, const char *base_xpath=NULL)``

Crops images using its Coords polygon, regions outside the polygon are set to transparent.

Arguments:
    elems_coords (std::vector< xmlNodePt >): Vector of Coord nodes to crop.
    margin (cv::Point2f *): Margins, if >1.0 it is considered pixels, otherwise percentage of maximum between crop width and height.
    opaque_coords (bool): Whether to include an alpha channel with the polygon interior in opaque.
    transp_xpath (const char *): Selector for semi-transparent elements.
    base_xpath (const char *): Expression to construct sample name, overriding the default IMGBASE.ELEMID.

Returns:
    std::vector< NamedImage >: An std::vector containing NamedImage objects of the cropped images.

";

%feature("docstring") PageXML::filter "
Filters a vector of xml nodes given an xpath.

Arguments:
    xpath (const char *): Filtering expression.
    elems (const std::vector< xmlNodePt >): Vector of nodes to filter.

Returns:
    std::vector< xmlNodePt >: Vector of filtered nodes.

";

%feature("docstring") PageXML::getAttr "
Overloaded function with 3 signatures.

**Signature 1**

``string PageXML::getAttr(const xmlNodePt node, const char *name)``

Gets an attribute value from an xml node.

Arguments:
    node (const xmlNodePt): XML node.
    name (const char *): Attribute name.

Returns:
    std::string: The attribute value, empty string if not set.

**Signature 2**

``string PageXML::getAttr(const char *xpath, const char *name)``

Gets an attribute value for a given xpath.

Arguments:
    xpath (const char *): Selector for the element to get the attribute.
    name (const char *): Attribute name.

Returns:
    std::string: The attribute value, empty string if not set.

**Signature 3**

``std::string PageXML::getAttr(const std::string xpath, const std::string name)``

Arguments:
    xpath (const std::string): 
    name (const std::string): 

Returns:
    std::string: 

";

%feature("docstring") PageXML::getBaselineOrientation "
Gets the baseline orientation angle (weighted average over polyline segments) of a given text line.

Arguments:
    elem (xmlNodePt): Node of the TextLine element.

Returns:
    double: The orientation angle in radians, NaN if unset.

";

%feature("docstring") PageXML::getDocPtr "
Returns the XML document pointer.


Returns:
    xmlDocPtr: 

";

%feature("docstring") PageXML::getDominantBaselinesOrientation "
Gets the dominant orientation angle for a set of baselines.

Arguments:
    elems (std::vector< xmlNodePt >): Nodes of the TextLine elements.

Returns:
    double: The dominant orientation angle in radians, NaN if unset.

";

%feature("docstring") PageXML::getFpgram "
Retrieves the features parallelogram (Property[@key='fpgram']/@value) for a given node.

Arguments:
    node (const xmlNodePt): Base node.

Returns:
    std::vector< cv::Point2f >: Vector of points.

";

%feature("docstring") PageXML::getImageBases "
Gets image bases for all pages in xml.


Returns:
    std::vector< std::string >: Vector of strings containing the image base names.

";

%feature("docstring") PageXML::getImagesBaseDir "

Returns:
    std::string: 

";

%feature("docstring") PageXML::getLeftRightTextContinuationGroups "
Determines groups of left-right text elem continuations (requires single segment polystripe).

Arguments:
    elems (std::vector< xmlNodePt >): Text elements to test for continuation: TextLines, Words, Glyphs or TextRegions.
    _group_order (std::vector< std::vector< int > > &): Join groups line indices (output).
    _group_score (std::vector< double > &): Join group scores (output).
    max_angle_diff (double): Maximum baseline angle difference for joining.
    max_horiz_iou (double): Maximum horizontal IoU for joining.
    min_prolong_fact (double): Minimum prolongation factor for joining.
    prolong_alpha (double): Weight for prolongation factors: alpha*bline+(1-alpha)*coords.
    fake_baseline (bool): Use bottom line of Coords rectangle as the baseline.
    recurse_factor (double): Multiplication factor for continuation criteria on each recursion.

Returns:
    int: Number of join groups, elements per group in order and group scores.

";

%feature("docstring") PageXML::getLeftRightTopBottomReadingOrder "
Gets the reading order for a set of text elems (requires single segment polystripe).

Arguments:
    elems (std::vector< xmlNodePt >): Elements to process: TextLines, Words, Glyphs or TextRegions.
    max_angle_diff (double): Maximum baseline angle difference for joining.
    max_horiz_iou (double): Maximum horizontal IoU for joining.
    min_prolong_fact (double): Minimum prolongation factor for joining.
    prolong_alpha (double): Weight for prolongation factors: alpha*bline+(1-alpha)*coords.
    fake_baseline (bool): Use bottom line of Coords rectangle as the baseline.
    recurse_factor (double): Multiplication factor for continuation criteria on each recursion.

Returns:
    std::pair< std::vector< int >, std::vector< int > >: Pair of reading order indices and subgroup lengths.

";

%feature("docstring") PageXML::getNodeName "
Gets the name of the given node.

Arguments:
    node (xmlNodePt): XML node.
    base_node (xmlNodePt): 

Returns:
    std::string: String with the name.

";

%feature("docstring") PageXML::getOGRpolygon "
Gets an element's Coords as an OGRMultiPolygon.

Arguments:
    node (const xmlNodePt): The element from which to extract the Coords points.
    xpath (const char *): Selector for the Coords element.

Returns:
    OGRMultiPolygonPtr_: Pointer to OGRMultiPolygon element.

";

%feature("docstring") PageXML::getOGRpolygonArea "
Gets the area of a OGRMultiPolygon.

Arguments:
    poly (OGRMultiPolygonPtr_): OGRMultiPolygon pointer.

Returns:
    double: Area.

";

%feature("docstring") PageXML::getOGRpolygons "
Gets elements' Coords as OGRMultiPolygons.

Arguments:
    nodes (std::vector< xmlNodePt >): Elements from which to extract the Coords points.
    xpath (const char *): Selector for the Coords element.

Returns:
    std::vector< OGRMultiPolygonPtr_ >: Vector of OGRMultiPolygon pointer elements.

";

%feature("docstring") PageXML::getOGRpolyline "
Gets the element's Baseline as an OGRMultiLineString.

Arguments:
    node (const xmlNodePt): The element from which to extract the Baseline points.
    xpath (const char *): 

Returns:
    OGRMultiLineStringPtr_: Pointer to OGRMultiLineString element.

";

%feature("docstring") PageXML::getPageHeight "
Overloaded function with 2 signatures.

**Signature 1**

``unsigned int PageXML::getPageHeight(xmlNodePt node)``

Gets the height of a page (might be different to image width due to the image orientation).

Arguments:
    node (xmlNodePt): A node to get its page height.

Returns:
    unsigned int: The page height.

**Signature 2**

``unsigned int PageXML::getPageHeight(int pagenum)``

Gets the height of a page (might be different to image width due to the image orientation).

Arguments:
    pagenum (int): The page number (0-based).

Returns:
    unsigned int: The page height.

";

%feature("docstring") PageXML::getPageImage "
Overloaded function with 2 signatures.

**Signature 1**

``PageImage PageXML::getPageImage(int pagenum)``

Returns the image for the given page.

Arguments:
    pagenum (int): 

Returns:
    PageImage: 

**Signature 2**

``PageImage PageXML::getPageImage(xmlNodePt node)``

Arguments:
    node (xmlNodePt): 

Returns:
    PageImage: 

";

%feature("docstring") PageXML::getPageImageFilename "
Overloaded function with 2 signatures.

**Signature 1**

``string PageXML::getPageImageFilename(xmlNodePt node)``

Returns the imageFilename of a page.

Arguments:
    node (xmlNodePt): 

Returns:
    std::string: 

**Signature 2**

``string PageXML::getPageImageFilename(int pagenum)``

Arguments:
    pagenum (int): 

Returns:
    std::string: 

";

%feature("docstring") PageXML::getPageImageOrientation "
Overloaded function with 2 signatures.

**Signature 1**

``int PageXML::getPageImageOrientation(xmlNodePt node)``

Gets the image orientation for the given node.

Arguments:
    node (xmlNodePt): A node to get its image orientation.

Returns:
    int: Orientation in degrees.

**Signature 2**

``int PageXML::getPageImageOrientation(int pagenum)``

Gets the image orientation for the given Page number.

Arguments:
    pagenum (int): The page number (0-based).

Returns:
    int: Orientation in degrees.

";

%feature("docstring") PageXML::getPageNumber "
Gets the page number for the given node.

Arguments:
    node (xmlNodePt): 

Returns:
    int: 

";

%feature("docstring") PageXML::getPageWidth "
Overloaded function with 2 signatures.

**Signature 1**

``unsigned int PageXML::getPageWidth(xmlNodePt node)``

Gets the width of a page (might be different to image width due to the image orientation).

Arguments:
    node (xmlNodePt): A node to get its page width.

Returns:
    unsigned int: The page width.

**Signature 2**

``unsigned int PageXML::getPageWidth(int pagenum)``

Gets the width of a page (might be different to image width due to the image orientation).

Arguments:
    pagenum (int): The page number (0-based).

Returns:
    unsigned int: The page width.

";

%feature("docstring") PageXML::getPagesSize "
Overloaded function with 2 signatures.

**Signature 1**

``std::vector< cv::Size2i > PageXML::getPagesSize(std::vector< xmlNodePt > pages)``

Retrieves pages size.

Arguments:
    pages (std::vector< xmlNodePt >): Page nodes.

Returns:
    std::vector< cv::Size2i >: Vector of page sizes.

**Signature 2**

``std::vector< cv::Size2i > PageXML::getPagesSize(const char *xpath=\"//_:Page\")``

Retrieves pages size.

Arguments:
    xpath (const char *): Selector for Page nodes.

Returns:
    std::vector< cv::Size2i >: Vector of page sizes.

";

%feature("docstring") PageXML::getPoints "
Overloaded function with 2 signatures.

**Signature 1**

``vector< cv::Point2f > PageXML::getPoints(const xmlNodePt node, const char *xpath=\"_:Coords\")``

Retrieves and parses the Coords/@points for a given base node.

Arguments:
    node (const xmlNodePt): Base node.
    xpath (const char *): Relative selector for the points.

Returns:
    std::vector< cv::Point2f >: Vector of points.

**Signature 2**

``std::vector< std::vector< cv::Point2f > > PageXML::getPoints(const std::vector< xmlNodePt > nodes, const char *xpath=\"_:Coords\")``

Retrieves and parses the Coords/@points for a given list of base nodes.

Arguments:
    nodes (const std::vector< xmlNodePt >): Base nodes.
    xpath (const char *): Relative selector for the points.

Returns:
    std::vector< std::vector< cv::Point2f > >: Vector of vectors of points.

";

%feature("docstring") PageXML::getPolylineLength "
Gets the baseline length.

Arguments:
    points (std::vector< cv::Point2f >): Baseline points.

Returns:
    double: The orientation angle in radians, NaN if unset.

";

%feature("docstring") PageXML::getPolylineOrientation "
Gets the baseline orientation angle (weighted average over polyline segments) in radians of a given baseline.

Arguments:
    points (std::vector< cv::Point2f >): Baseline points.

Returns:
    double: The orientation angle in radians, NaN if unset.

";

%feature("docstring") PageXML::getPropertyValue "
Retrieves a Property value.

Arguments:
    node (xmlNodePt): Node element.
    key (const char *): The key for the Property.

Returns:
    std::string: String with the property value.

";

%feature("docstring") PageXML::getReadingDirection "
Retrieves the reading direction for a given TextLine or TextRegion node.

Arguments:
    elem (const xmlNodePt): Node of the TextLine or TextRegion element.

Returns:
    int: The reading direction, PAGEXML_READ_DIRECTION_LTR if unset.

";

%feature("docstring") PageXML::getRotation "
Retrieves the rotation angle for a given TextLine or TextRegion node.

Arguments:
    elem (const xmlNodePt): Node of the TextLine or TextRegion element.

Returns:
    double: The rotation angle in degrees, 0 if unset.

";

%feature("docstring") PageXML::getTextEquiv "
Retrieves the concatenated TextEquivs for a given root node and xpath.

Arguments:
    node (xmlNodePt): Root node element.
    xpath (const char *): Relative xpath to select the TextEquiv elements.
    type (const char *): Type attribute. Set to empty string for TextEquivs without a type.
    separator (const char *): String to add between TextEquivs.

Returns:
    std::string: String with the concatenated TextEquivs.

";

%feature("docstring") PageXML::getUnionOGRpolygon "
Gets the union of Coords elements as a OGRMultiPolygon.

Arguments:
    nodes (std::vector< xmlNodePt >): Elements from which to extract the Coords points.
    xpath (const char *): Selector for the Coords element.

Returns:
    OGRMultiPolygonPtr_: Pointer to OGRMultiPolygon element.

";

%feature("docstring") PageXML::getUniqueID "
Gets a unique id.

Arguments:
    prefix (const char *): Prefix for id.
    suffix (const char *): Suffix for id.
    count_start (int): Counter start to place between prefix and suffix.
    count_max (int): Maximum count to test.

Returns:
    std::string: The generated unique id.

";

%feature("docstring") PageXML::getValue "
Overloaded function with 2 signatures.

**Signature 1**

``std::string PageXML::getValue(xmlNodePt node)``

Retrieves a node value.

Arguments:
    node (xmlNodePt): Node element.

Returns:
    std::string: String with the node value.

**Signature 2**

``std::string PageXML::getValue(const char *xpath, const xmlNodePt node=NULL)``

Retrieves a node value.

Arguments:
    xpath (const char *): Selector for the element to get the value.
    node (const xmlNodePt): XML node for context, set to NULL for root node.

Returns:
    std::string: String with the node value.

";

%feature("docstring") PageXML::getXheight "
Overloaded function with 2 signatures.

**Signature 1**

``float PageXML::getXheight(const xmlNodePt node)``

Retrieves the x-height for a given TextLine node.

Arguments:
    node (const xmlNodePt): Node of the TextLine element.

Returns:
    float: x-height>0 on success, -1 if unset.

**Signature 2**

``float PageXML::getXheight(const char *id)``

Retrieves the x-height for a given TextLine id.

Arguments:
    id (const char *): Identifier of the TextLine.

Returns:
    float: x-height>0 on success, -1 if unset.

";

%feature("docstring") PageXML::getXmlFilePath "

Returns:
    std::string: 

";

%feature("docstring") PageXML::insertElem "
Inserts an element relative to a given node.

Arguments:
    elem (xmlNodePt): Element to insert.
    node (const xmlNodePt): Reference element for insertion.
    itype (PAGEXML_INSERT): Type of insertion.

Returns:
    xmlNodePt: Pointer to inserted element.

";

%feature("docstring") PageXML::intersection "
Finds the intersection point between two lines defined by pairs of points.

Arguments:
    line1_point1 (cv::Point2f): First point of line 1.
    line1_point2 (cv::Point2f): Second point of line 1.
    line2_point1 (cv::Point2f): First point of line 2.
    line2_point2 (cv::Point2f): Second point of line 2.
    _ipoint (cv::Point2f &): 

Returns:
    bool: False if no intersection otherwise true.

";

%feature("docstring") PageXML::isBBox "
Determines whether a vector of points defines a bounding box.

Arguments:
    points (const std::vector< cv::Point2f > &): The vector of points to find the limits.

Returns:
    bool: True if bounding box, otherwise false.

";

%feature("docstring") PageXML::isPageImageLoaded "
Overloaded function with 2 signatures.

**Signature 1**

``bool PageXML::isPageImageLoaded(int pagenum)``

Checks whether a page image is loaded.

Arguments:
    pagenum (int): 

Returns:
    bool: 

**Signature 2**

``bool PageXML::isPageImageLoaded(xmlNodePt node)``

Arguments:
    node (xmlNodePt): 

Returns:
    bool: 

";

%feature("docstring") PageXML::isPolystripe "
Checks whether Coords is a poly-stripe for its corresponding baseline.

Arguments:
    coords (std::vector< cv::Point2f >): Coords points.
    baseline (std::vector< cv::Point2f >): Baseline points.
    height (double *): 
    offset (double *): The offset of the poly-stripe (>=0 && <= 0.5).

Returns:
    bool: Pointer to created element.

";

%feature("docstring") PageXML::isValid "
Validates the currently loaded XML.

Arguments:
    xml_to_validate (xmlDocPtr): Pointer to the loaded XML to validate.

Returns:
    bool: Whether XML validates or not.

";

%feature("docstring") PageXML::loadImage "
Overloaded function with 2 signatures.

**Signature 1**

``void PageXML::loadImage(int pagenum, const char *fname=NULL, const bool resize_coords=false, int density=0)``

Arguments:
    pagenum (int): 
    fname (const char *): 
    resize_coords (const bool): 
    density (int): 

**Signature 2**

``void PageXML::loadImage(xmlNodePt node, const char *fname=NULL, const bool resize_coords=false, int density=0)``

Loads an image for a Page in the XML.

Arguments:
    node (xmlNodePt): Pointer to a Page node or a descendant.
    fname (const char *): File name of the image to read, overriding the one in the XML.
    resize_coords (const bool): If image size differs, resize page XML coordinates.
    density (int): Load the image at the given density, resizing the page coordinates if required.

";

%feature("docstring") PageXML::loadImages "
Loads images for all pages in the XML.

Arguments:
    resize_coords (const bool): If image size differs, resize page XML coordinates.
    density (const int): Load the image at the given density, resizing the page coordinates if required.

";

%feature("docstring") PageXML::loadSchema "
Loads a schema for xml validation.

Arguments:
    schema_path (const char *): File name of the XSD file to read.

";

%feature("docstring") PageXML::loadXml "
Overloaded function with 2 signatures.

**Signature 1**

``void PageXML::loadXml(const char *fname, bool validate=true)``

Loads a Page XML from a file.

Arguments:
    fname (const char *): File name of the XML file to read.
    validate (bool): Whether to validate against XSD schema.

**Signature 2**

``void PageXML::loadXml(int fnum, bool prevfree=true, bool validate=true)``

Loads a Page XML from an input stream.

Arguments:
    fnum (int): File number from where to read the XML file.
    prevfree (bool): Whether to release resources before loading.
    validate (bool): Whether to validate against XSD schema.

";

%feature("docstring") PageXML::loadXmlString "
Loads a Page XML from a string.

Arguments:
    xml_string (const char *): The XML content.
    validate (bool): Whether to validate against XSD schema.

";

%feature("docstring") PageXML::moveElem "
Unlink an element and add it relative to a given node.

Arguments:
    elem (xmlNodePt): Element to move.
    node (const xmlNodePt): Reference element for insertion.
    itype (PAGEXML_INSERT): Type of insertion.
    bugimpl (bool): 

Returns:
    xmlNodePt: Pointer to moved element.

";

%feature("docstring") PageXML::moveElems "
Unlink elements and add them relative to a given node.

Arguments:
    elems (const std::vector< xmlNodePt > &): Elements to move.
    node (const xmlNodePt): Reference element for insertion.
    itype (PAGEXML_INSERT): Type of insertion.
    bugimpl (bool): 

Returns:
    int: Pointer to moved element.

";

%feature("docstring") PageXML::multiPolygonIntersection "
Computes the intersection of two multipolygons.

Arguments:
    poly1 (OGRMultiPolygonPtr_): First polygon.
    poly2 (OGRMultiPolygonPtr_): Second polygon.

Returns:
    OGRMultiPolygonPtr_: Intersection geometry.

";

%feature("docstring") PageXML::multiPolylineIntersection "
Computes the intersection between a multipolylines and a multipolygon.

Arguments:
    poly1 (OGRMultiLineStringPtr_): Polyline.
    poly2 (OGRMultiPolygonPtr_): Polygon.

Returns:
    OGRMultiLineStringPtr_: Intersection geometry.

";

%feature("docstring") PageXML::newXml "
Creates a new Page XML.

Arguments:
    creator (const char *): Info about tool creating the XML.
    image (const char *): Path to the image file.
    imgW (const int): Width of image.
    imgH (const int): Height of image.
    pagens (const char *): The page xml namespace string to use.

Returns:
    xmlNodePt: Pointer to the Page node.

";

%feature("docstring") PageXML::nodeIs "
Checks if node is of given name.

Arguments:
    node (xmlNodePt): XML node.
    name (const char *): String with name to match against.

Returns:
    bool: True if name matches, otherwise false.

";

%feature("docstring") PageXML::parent "
Returns the parent of a node.

Arguments:
    node (const xmlNodePt): XML node.

Returns:
    xmlNodePt: Parent node.

";

%feature("docstring") PageXML::pointsBBox "
Generates a vector of 4 points that define the bounding box for a given vector of points.

Arguments:
    points (std::vector< cv::Point2f >): The vector of points to find the limits.

Returns:
    std::vector< cv::Point2f >: The 4 points defining the bounding box (top-left clockwise).

";

%feature("docstring") PageXML::pointsLimits "
Gets the minimum and maximum coordinate values for an array of points.

Arguments:
    points (std::vector< cv::Point2f > &): The vector of points to find the limits.
    xmin (double &): Minimum x value.
    xmax (double &): Maximum x value.
    ymin (double &): Minimum y value.
    ymax (double &): Maximum y value.

";

%feature("docstring") PageXML::pointsToOGRpolygon "
Converts Coords to an OGRMultiPolygon.

Arguments:
    points (std::vector< cv::Point2f >): Vector of x,y points.

Returns:
    OGRMultiPolygonPtr_: Pointer to OGRMultiPolygon element.

";

%feature("docstring") PageXML::pointsToOGRpolygons "
Converts Coords to OGRMultiPolygons.

Arguments:
    points (std::vector< std::vector< cv::Point2f > >): Vectors of x,y points.

Returns:
    std::vector< OGRMultiPolygonPtr_ >: Pointer to OGRMultiPolygon element.

";

%feature("docstring") PageXML::pointsToString "
Overloaded function with 2 signatures.

**Signature 1**

``static std::string PageXML::pointsToString(std::vector< cv::Point2f > points, bool rounded=false)``

Arguments:
    points (std::vector< cv::Point2f >): 
    rounded (bool): 

Returns:
    std::string: 

**Signature 2**

``static std::string PageXML::pointsToString(std::vector< cv::Point > points)``

Arguments:
    points (std::vector< cv::Point >): 

Returns:
    std::string: 

";

%feature("docstring") PageXML::printVersions "
Prints the version of the PageXML library and its main dependencies.

Arguments:
    file (FILE *): Stream where to print the versions.

";

%feature("docstring") PageXML::processEnd "
Ends the running process in the Page XML.


";

%feature("docstring") PageXML::processStart "
Starts a process in the Page XML.

Arguments:
    tool (const char *): Short description of tool that started the process.
    ref (const char *): Short description of execution reference.

";

%feature("docstring") PageXML::relabelChildIDs "
Relabels IDs of child elements.

Arguments:
    node (xmlNodePt): Base node.
    include_self (bool): Whether to also relabel the base node.

Returns:
    int: Number of IDs affected.

";

%feature("docstring") PageXML::relativizeImageFilename "
Modifies imageFilename to be a relative path w.r.t. given xml path. Currently just checks prefix directories and removes it.

Arguments:
    xml_path (const char *): 

";

%feature("docstring") PageXML::releaseImage "
Overloaded function with 2 signatures.

**Signature 1**

``void PageXML::releaseImage(int pagenum)``

Releases an already loaded image.

Arguments:
    pagenum (int): The number of the page for which to release the image (0-based).

**Signature 2**

``void PageXML::releaseImage(xmlNodePt node)``

Arguments:
    node (xmlNodePt): 

";

%feature("docstring") PageXML::releaseImages "

";

%feature("docstring") PageXML::resize "
Overloaded function with 4 signatures.

**Signature 1**

``int PageXML::resize(std::vector< cv::Size2i > sizes, std::vector< xmlNodePt > pages, bool check_aspect_ratio=true)``

Resizes pages and all respective coordinates.

Arguments:
    sizes (std::vector< cv::Size2i >): Page sizes to resize to.
    pages (std::vector< xmlNodePt >): Page nodes.
    check_aspect_ratio (bool): Whether to check that the aspect ratio is properly preserved.

Returns:
    int: Number of pages+points attributes modified.

**Signature 2**

``int PageXML::resize(std::vector< cv::Size2i > sizes, const char *xpath=\"//_:Page\", bool check_aspect_ratio=true)``

Resizes pages and all respective coordinates.

Arguments:
    sizes (std::vector< cv::Size2i >): Page sizes to resize to.
    xpath (const char *): Selector for Page nodes.
    check_aspect_ratio (bool): Whether to check that the aspect ratio is properly preserved.

Returns:
    int: Number of pages+points attributes modified.

**Signature 3**

``int PageXML::resize(cv::Size2i size, xmlNodePt page, bool check_aspect_ratio=true)``

Resizes a page and all respective coordinates.

Arguments:
    size (cv::Size2i): Page size to resize to.
    page (xmlNodePt): Page node.
    check_aspect_ratio (bool): Whether to check that the aspect ratio is properly preserved.

Returns:
    int: Number of pages+points attributes modified.

**Signature 4**

``int PageXML::resize(double fact, const char *xpath=\"//_:Page\")``

Resizes a page and all respective coordinates.

Arguments:
    fact (double): 
    xpath (const char *): Selector for Page nodes.

Returns:
    int: Number of pages+points attributes modified.

";

%feature("docstring") PageXML::rmElem "
Removes the given element.

Arguments:
    node (const xmlNodePt): Element.

";

%feature("docstring") PageXML::rmElems "
Overloaded function with 3 signatures.

**Signature 1**

``int PageXML::rmElems(const std::vector< xmlNodePt > &nodes)``

Arguments:
    nodes (const std::vector< xmlNodePt > &): 

Returns:
    int: 

**Signature 2**

``int PageXML::rmElems(const char *xpath, xmlNodePt node=NULL)``

Remove the elements that match a given xpath.

Arguments:
    xpath (const char *): Selector for elements to remove.
    node (xmlNodePt): Base node for element selection.

Returns:
    int: Number of elements removed.

**Signature 3**

``int PageXML::rmElems(const std::string xpath, xmlNodePt node=NULL)``

Arguments:
    xpath (const std::string): 
    node (xmlNodePt): 

Returns:
    int: 

";

%feature("docstring") PageXML::rotatePage "
Overloaded function with 2 signatures.

**Signature 1**

``int PageXML::rotatePage(int angle, xmlNodePt page, bool update_image_orientation, const double conf)``

Rotates a page.

Arguments:
    angle (int): Angle to rotate in degrees {0,90,180,-90}.
    page (xmlNodePt): The Page node.
    update_image_orientation (bool): Whether to update the ImageOrientation element.
    conf (const double): Confidence value.

Returns:
    int: Number of elements modified.

**Signature 2**

``int PageXML::rotatePage(int angle, xmlNodePt page, bool update_image_orientation=true, const double *_conf=NULL)``

Rotates a page.

Arguments:
    angle (int): Angle to rotate in degrees {0,90,180,-90}.
    page (xmlNodePt): The Page node.
    update_image_orientation (bool): Whether to check that the aspect ratio is properly preserved.
    _conf (const double *): Pointer to confidence value, NULL for no confidence.

Returns:
    int: Number of elements modified.

";

%feature("docstring") PageXML::select "
Overloaded function with 3 signatures.

**Signature 1**

``vector< xmlNodePt > PageXML::select(const char *xpath, const xmlNodePt node=NULL)``

Selects nodes given an xpath.

Arguments:
    xpath (const char *): Selector expression.
    node (const xmlNodePt): XML node for context, set to NULL for root node.

Returns:
    std::vector< xmlNodePt >: Vector of matched nodes.

**Signature 2**

``std::vector<xmlNodePt> PageXML::select(std::string xpath, const xmlNodePt node=NULL)``

Arguments:
    xpath (std::string): 
    node (const xmlNodePt): 

Returns:
    std::vector< xmlNodePt >: 

**Signature 3**

``std::vector<xmlNodePt> PageXML::select(const char *xpath, const std::vector< xmlNodePt > nodes, bool unique=true)``

Arguments:
    xpath (const char *): 
    nodes (const std::vector< xmlNodePt >): 
    unique (bool): 

Returns:
    std::vector< xmlNodePt >: 

";

%feature("docstring") PageXML::selectByID "
Selects an element with a given ID.

Arguments:
    id (const char *): ID of element to select.
    node (const xmlNodePt): XML node for context, set to NULL for root node.

Returns:
    xmlNodePt: Matched node or NULL if nothing matched.

";

%feature("docstring") PageXML::selectByOverlap "
Overloaded function with 2 signatures.

**Signature 1**

``std::vector< xmlNodePt > PageXML::selectByOverlap(std::vector< cv::Point2f > points, xmlNodePt page, const char *xpath=\".//_:TextLine\", double overlap_thr=0.1, PAGEXML_OVERLAP overlap_type=PAGEXML_OVERLAP_COORDS_IWA)``

Selects elements based on overlap to a polygon.

Arguments:
    points (std::vector< cv::Point2f >): Polygon for selection.
    page (xmlNodePt): Page element for selection.
    xpath (const char *): xpath for candidate elements for selection.
    overlap_thr (double): Overlapping score threshold.
    overlap_type (PAGEXML_OVERLAP): Type of overlap to use for selecting.

Returns:
    std::vector< xmlNodePt >: Number of TextLines copied.

**Signature 2**

``std::vector< xmlNodePt > PageXML::selectByOverlap(std::vector< cv::Point2f > points, int pagenum, const char *xpath=\".//_:TextLine\", double overlap_thr=0.1, PAGEXML_OVERLAP overlap_type=PAGEXML_OVERLAP_COORDS_IWA)``

Selects elements based on overlap to a polygon.

Arguments:
    points (std::vector< cv::Point2f >): Polygon for selection.
    pagenum (int): Page number for selection.
    xpath (const char *): xpath for candidate elements for selection.
    overlap_thr (double): Overlapping score threshold.
    overlap_type (PAGEXML_OVERLAP): Type of overlap to use for selecting.

Returns:
    std::vector< xmlNodePt >: Number of TextLines copied.

";

%feature("docstring") PageXML::selectNth "
Overloaded function with 2 signatures.

**Signature 1**

``xmlNodePt PageXML::selectNth(const char *xpath, int num=0, const xmlNodePt node=NULL)``

Selects the n-th node that matches an xpath.

Arguments:
    xpath (const char *): Selector expression.
    num (int): Element number (0-based), negative from last.
    node (const xmlNodePt): XML node for context, set to NULL for root node.

Returns:
    xmlNodePt: Matched node or NULL if nothing matched.

**Signature 2**

``xmlNodePt PageXML::selectNth(std::string xpath, int num=0, const xmlNodePt node=NULL)``

Arguments:
    xpath (std::string): 
    num (int): 
    node (const xmlNodePt): 

Returns:
    xmlNodePt: 

";

%feature("docstring") PageXML::setAttr "
Overloaded function with 4 signatures.

**Signature 1**

``int PageXML::setAttr(std::vector< xmlNodePt > nodes, const char *name, const char *value)``

Arguments:
    nodes (std::vector< xmlNodePt >): 
    name (const char *): 
    value (const char *): 

Returns:
    int: 

**Signature 2**

``int PageXML::setAttr(const xmlNodePt node, const char *name, const char *value)``

Adds or modifies (if already exists) an attribute for a given node.

Arguments:
    node (const xmlNodePt): Node to set the attribute.
    name (const char *): Attribute name.
    value (const char *): Attribute value.

Returns:
    int: Number of elements modified.

**Signature 3**

``int PageXML::setAttr(const char *xpath, const char *name, const char *value)``

Adds or modifies (if already exists) an attribute for a given xpath.

Arguments:
    xpath (const char *): Selector for the element(s) to set the attribute.
    name (const char *): Attribute name.
    value (const char *): Attribute value.

Returns:
    int: Number of elements modified.

**Signature 4**

``int PageXML::setAttr(const std::string xpath, const std::string name, const std::string value)``

Arguments:
    xpath (const std::string): 
    name (const std::string): 
    value (const std::string): 

Returns:
    int: 

";

%feature("docstring") PageXML::setBaseline "
Overloaded function with 6 signatures.

**Signature 1**

``xmlNodePt PageXML::setBaseline(xmlNodePt node, const std::vector< cv::Point2f > &points, const double *_conf=NULL)``

Arguments:
    node (xmlNodePt): 
    points (const std::vector< cv::Point2f > &): 
    _conf (const double *): 

Returns:
    xmlNodePt: 

**Signature 2**

``xmlNodePt PageXML::setBaseline(xmlNodePt node, const std::vector< cv::Point2f > &points, const double conf)``

Arguments:
    node (xmlNodePt): 
    points (const std::vector< cv::Point2f > &): 
    conf (const double): 

Returns:
    xmlNodePt: 

**Signature 3**

``xmlNodePt PageXML::setBaseline(const char *xpath, const std::vector< cv::Point2f > &points, const double *_conf=NULL)``

Arguments:
    xpath (const char *): 
    points (const std::vector< cv::Point2f > &): 
    _conf (const double *): 

Returns:
    xmlNodePt: 

**Signature 4**

``xmlNodePt PageXML::setBaseline(const char *xpath, const std::vector< cv::Point2f > &points, const double conf)``

Arguments:
    xpath (const char *): 
    points (const std::vector< cv::Point2f > &): 
    conf (const double): 

Returns:
    xmlNodePt: 

**Signature 5**

``xmlNodePt PageXML::setBaseline(xmlNodePt node, double x1, double y1, double x2, double y2, const double *_conf=NULL)``

Adds or modifies (if already exists) a two point Baseline for a given node.

Arguments:
    node (xmlNodePt): The node of element to set the Baseline.
    x1 (double): x value of first point.
    y1 (double): y value of first point.
    x2 (double): x value of second point.
    y2 (double): y value of second point.
    _conf (const double *): Pointer to confidence value, NULL for no confidence.

Returns:
    xmlNodePt: Pointer to created element.

**Signature 6**

``xmlNodePt PageXML::setBaseline(xmlNodePt node, double x1, double y1, double x2, double y2, const double conf)``

Adds or modifies (if already exists) a two point Baseline for a given node.

Arguments:
    node (xmlNodePt): The node of element to set the Baseline.
    x1 (double): x value of first point.
    y1 (double): y value of first point.
    x2 (double): x value of second point.
    y2 (double): y value of second point.
    conf (const double): Confidence value.

Returns:
    xmlNodePt: Pointer to created element.

";

%feature("docstring") PageXML::setCoords "
Overloaded function with 6 signatures.

**Signature 1**

``xmlNodePt PageXML::setCoords(xmlNodePt node, const std::vector< cv::Point2f > &points, const double *_conf=NULL)``

Arguments:
    node (xmlNodePt): 
    points (const std::vector< cv::Point2f > &): 
    _conf (const double *): 

Returns:
    xmlNodePt: 

**Signature 2**

``xmlNodePt PageXML::setCoords(xmlNodePt node, const std::vector< cv::Point2f > &points, const double conf)``

Arguments:
    node (xmlNodePt): 
    points (const std::vector< cv::Point2f > &): 
    conf (const double): 

Returns:
    xmlNodePt: 

**Signature 3**

``xmlNodePt PageXML::setCoords(xmlNodePt node, const std::vector< cv::Point > &points, const double *_conf=NULL)``

Arguments:
    node (xmlNodePt): 
    points (const std::vector< cv::Point > &): 
    _conf (const double *): 

Returns:
    xmlNodePt: 

**Signature 4**

``xmlNodePt PageXML::setCoords(xmlNodePt node, const std::vector< cv::Point > &points, const double conf)``

Arguments:
    node (xmlNodePt): 
    points (const std::vector< cv::Point > &): 
    conf (const double): 

Returns:
    xmlNodePt: 

**Signature 5**

``xmlNodePt PageXML::setCoords(const char *xpath, const std::vector< cv::Point2f > &points, const double *_conf=NULL)``

Arguments:
    xpath (const char *): 
    points (const std::vector< cv::Point2f > &): 
    _conf (const double *): 

Returns:
    xmlNodePt: 

**Signature 6**

``xmlNodePt PageXML::setCoords(const char *xpath, const std::vector< cv::Point2f > &points, const double conf)``

Arguments:
    xpath (const char *): 
    points (const std::vector< cv::Point2f > &): 
    conf (const double): 

Returns:
    xmlNodePt: 

";

%feature("docstring") PageXML::setCoordsBBox "
Overloaded function with 2 signatures.

**Signature 1**

``xmlNodePt PageXML::setCoordsBBox(xmlNodePt node, double xmin, double ymin, double width, double height, const double *_conf=NULL, bool subone=true)``

Adds or modifies (if already exists) the Coords as a bounding box for a given node.

Arguments:
    node (xmlNodePt): The node of element to set the Coords.
    xmin (double): Minimum x value of bounding box.
    ymin (double): Minimum y value of bounding box.
    width (double): Width of bounding box.
    height (double): Height of bounding box.
    _conf (const double *): Pointer to confidence value, NULL for no confidence.
    subone (bool): Whether to subtract 1 when computing xmax and ymax (discrete compatibility).

Returns:
    xmlNodePt: Pointer to created element.

**Signature 2**

``xmlNodePt PageXML::setCoordsBBox(xmlNodePt node, double xmin, double ymin, double width, double height, const double conf, bool subone=true)``

Adds or modifies (if already exists) the Coords as a bounding box for a given node.

Arguments:
    node (xmlNodePt): The node of element to set the Coords.
    xmin (double): Minimum x value of bounding box.
    ymin (double): Minimum y value of bounding box.
    width (double): Width of bounding box.
    height (double): Height of bounding box.
    conf (const double): Confidence value.
    subone (bool): Whether to subtract 1 when computing xmax and ymax (discrete compatibility).

Returns:
    xmlNodePt: Pointer to created element.

";

%feature("docstring") PageXML::setImagesBaseDir "
Arguments:
    imgBaseDir (std::string): 

";

%feature("docstring") PageXML::setPageHeight "
Sets the height of a page (actually sets imageHeight accounting for image orientation).

Arguments:
    node (xmlNodePt): A node to set its page height.
    height (int): The height to set.

";

%feature("docstring") PageXML::setPageImageFilename "
Overloaded function with 2 signatures.

**Signature 1**

``void PageXML::setPageImageFilename(xmlNodePt node, const char *image)``

Sets the imageFilename of a page.

Arguments:
    node (xmlNodePt): 
    image (const char *): 

**Signature 2**

``void PageXML::setPageImageFilename(int pagenum, const char *image)``

Arguments:
    pagenum (int): 
    image (const char *): 

";

%feature("docstring") PageXML::setPageImageOrientation "
Overloaded function with 4 signatures.

**Signature 1**

``void PageXML::setPageImageOrientation(xmlNodePt node, int angle, const double *_conf=NULL)``

Sets the image orientation for the given Page node.

Arguments:
    node (xmlNodePt): The page node.
    angle (int): The orientation angle in degrees {0,90,180,-90}.
    _conf (const double *): Pointer to confidence value, NULL for no confidence.

**Signature 2**

``void PageXML::setPageImageOrientation(xmlNodePt node, int angle, const double conf)``

Sets the image orientation for the given Page node.

Arguments:
    node (xmlNodePt): The page node.
    angle (int): The orientation angle in degrees {0,90,180,-90}.
    conf (const double): Confidence value.

**Signature 3**

``void PageXML::setPageImageOrientation(int pagenum, int angle, const double *_conf=NULL)``

Sets the image orientation for the given Page number.

Arguments:
    pagenum (int): The page number (0-based).
    angle (int): The orientation angle in degrees {0,90,180,-90}.
    _conf (const double *): Pointer to confidence value, NULL for no confidence.

**Signature 4**

``void PageXML::setPageImageOrientation(int pagenum, int angle, const double conf)``

Sets the image orientation for the given Page number.

Arguments:
    pagenum (int): The page number (0-based).
    angle (int): The orientation angle in degrees {0,90,180,-90}.
    conf (const double): Confidence value.

";

%feature("docstring") PageXML::setPageWidth "
Sets the width of a page (actually sets imageWidth accounting for image orientation).

Arguments:
    node (xmlNodePt): A node to set its page width.
    width (int): The width to set.

";

%feature("docstring") PageXML::setPolystripe "
Sets the Coords of a TextLine as a poly-stripe of the baseline.

Arguments:
    node (xmlNodePt): The node of element to set the Coords.
    height (double): The height of the poly-stripe in pixels (>0).
    offset (double): The offset of the poly-stripe (>=0 && <= 0.5).
    offset_check (bool): Whether to check if offset is valid.

Returns:
    xmlNodePt: Pointer to created element.

";

%feature("docstring") PageXML::setProperty "
Overloaded function with 4 signatures.

**Signature 1**

``xmlNodePt PageXML::setProperty(xmlNodePt node, const char *key, const char *val=NULL, const double *_conf=NULL)``

Sets a Property to a given node.

Arguments:
    node (xmlNodePt): The node of element to set the Property.
    key (const char *): The key for the Property.
    val (const char *): The optional value for the Property.
    _conf (const double *): Pointer to confidence value, NULL for no confidence.

Returns:
    xmlNodePt: Pointer to created element.

**Signature 2**

``xmlNodePt PageXML::setProperty(xmlNodePt node, const char *key, const char *val, const double conf)``

Sets a Property to a given node.

Arguments:
    node (xmlNodePt): The node of element to set the Property.
    key (const char *): The key for the Property.
    val (const char *): The optional value for the Property.
    conf (const double): Confidence value.

Returns:
    xmlNodePt: Pointer to created element.

**Signature 3**

``xmlNodePt PageXML::setProperty(xmlNodePt node, const char *key, const double val, const double *_conf=NULL)``

Sets a Property to a given node.

Arguments:
    node (xmlNodePt): The node of element to set the Property.
    key (const char *): The key for the Property.
    val (const double): Numeric value for the Property.
    _conf (const double *): Pointer to confidence value, NULL for no confidence.

Returns:
    xmlNodePt: Pointer to created element.

**Signature 4**

``xmlNodePt PageXML::setProperty(xmlNodePt node, const char *key, const double val, const double conf)``

Sets a Property to a given node.

Arguments:
    node (xmlNodePt): The node of element to set the Property.
    key (const char *): The key for the Property.
    val (const double): The optional value for the Property.
    conf (const double): Confidence value.

Returns:
    xmlNodePt: Pointer to created element.

";

%feature("docstring") PageXML::setReadingDirection "
Sets the reading direction to a TextRegion node.

Arguments:
    elem (const xmlNodePt): 
    direction (PAGEXML_READ_DIRECTION): Direction to set.

";

%feature("docstring") PageXML::setRotation "
Sets the rotation angle to a TextRegion node.

Arguments:
    elem (const xmlNodePt): 
    rotation (const float): Rotation angle to set.

";

%feature("docstring") PageXML::setTextEquiv "
Overloaded function with 4 signatures.

**Signature 1**

``xmlNodePt PageXML::setTextEquiv(xmlNodePt node, const char *text, const double *_conf=NULL, const char *type=NULL)``

Adds or modifies (if already exists) the TextEquiv for a given node.

Arguments:
    node (xmlNodePt): The node of element to set the TextEquiv.
    text (const char *): The text string.
    _conf (const double *): Pointer to confidence value, NULL for no confidence.
    type (const char *): Type attribute.

Returns:
    xmlNodePt: Pointer to created element.

**Signature 2**

``xmlNodePt PageXML::setTextEquiv(xmlNodePt node, const char *text, const double conf, const char *type=NULL)``

Adds or modifies (if already exists) the TextEquiv for a given node.

Arguments:
    node (xmlNodePt): The node of element to set the TextEquiv.
    text (const char *): The text string.
    conf (const double): Confidence value.
    type (const char *): Type attribute.

Returns:
    xmlNodePt: Pointer to created element.

**Signature 3**

``xmlNodePt PageXML::setTextEquiv(const char *xpath, const char *text, const double *_conf=NULL, const char *type=NULL)``

Adds or modifies (if already exists) the TextEquiv for a given xpath.

Arguments:
    xpath (const char *): Selector for element to set the TextEquiv.
    text (const char *): The text string.
    _conf (const double *): Pointer to confidence value, NULL for no confidence.
    type (const char *): Type attribute.

Returns:
    xmlNodePt: Pointer to created element.

**Signature 4**

``xmlNodePt PageXML::setTextEquiv(const char *xpath, const char *text, const double conf, const char *type=NULL)``

Adds or modifies (if already exists) the TextEquiv for a given xpath.

Arguments:
    xpath (const char *): Selector for element to set the TextEquiv.
    text (const char *): The text string.
    conf (const double): Confidence value.
    type (const char *): Type attribute.

Returns:
    xmlNodePt: Pointer to created element.

";

%feature("docstring") PageXML::setValidationEnabled "
Enables/disables schema validation.

Arguments:
    val (bool): Whether schema validation should be enabled.

";

%feature("docstring") PageXML::setValue "
Sets a node value.

Arguments:
    node (xmlNodePt): Node element.
    value (const char *): String with the value to set.

";

%feature("docstring") PageXML::setXmlFilePath "
Arguments:
    xmlFilePath (std::string): 

";

%feature("docstring") PageXML::simplifyIDs "
Simplifies IDs by removing imgbase prefixes and replaces invalid characters with _.


Returns:
    int: Number of IDs simplified.

";

%feature("docstring") PageXML::stringToPoints "
Overloaded function with 2 signatures.

**Signature 1**

``vector< cv::Point2f > PageXML::stringToPoints(const char *spoints)``

Parses a string of pairs of coordinates (x1,y1 [x2,y2 ...]) into an array.

Arguments:
    spoints (const char *): String containing coordinate pairs.

Returns:
    std::vector< cv::Point2f >: Array of (x,y) coordinates.

**Signature 2**

``static std::vector<cv::Point2f> PageXML::stringToPoints(std::string spoints)``

Arguments:
    spoints (std::string): 

Returns:
    std::vector< cv::Point2f >: 

";

%feature("docstring") PageXML::toString "
Creates a string representation of the Page XML.

Arguments:
    indent (bool): Whether to indent the XML.
    validate (bool): Whether the Page XML should be validated before writing.

Returns:
    std::string: The Page XML string.

";

%feature("docstring") PageXML::updateLastChange "
Updates the last change time stamp.


";

%feature("docstring") PageXML::version "
Returns the class version.


Returns:
    char *: 

";

%feature("docstring") PageXML::write "
Writes the current state of the XML to a file using utf-8 encoding.

Arguments:
    fname (const char *): File name of where the XML file will be written.
    indent (bool): Whether to indent the XML.
    validate (bool): Whether the Page XML should be validated before writing.

Returns:
    int: Number of bytes written.

";

%feature("docstring") PageXML::~PageXML "
PageXML object destructor.


";

