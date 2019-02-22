pagexml API (version 2019.2.22)
*******************************


pagexml module
==============

pagexml.DataType_Vec2b

   alias of "pagexml._DataType_Vec_uint8_t_2"

pagexml.DataType_Vec2d

   alias of "pagexml._DataType_Vec_double_2"

pagexml.DataType_Vec2f

   alias of "pagexml._DataType_Vec_float_2"

pagexml.DataType_Vec2i

   alias of "pagexml._DataType_Vec_int_2"

pagexml.DataType_Vec2s

   alias of "pagexml._DataType_Vec_short_2"

pagexml.DataType_Vec2w

   alias of "pagexml._DataType_Vec_ushort_2"

pagexml.DataType_Vec3b

   alias of "pagexml._DataType_Vec_uint8_t_3"

pagexml.DataType_Vec3d

   alias of "pagexml._DataType_Vec_double_3"

pagexml.DataType_Vec3f

   alias of "pagexml._DataType_Vec_float_3"

pagexml.DataType_Vec3i

   alias of "pagexml._DataType_Vec_int_3"

pagexml.DataType_Vec3s

   alias of "pagexml._DataType_Vec_short_3"

pagexml.DataType_Vec3w

   alias of "pagexml._DataType_Vec_ushort_3"

pagexml.DataType_Vec4b

   alias of "pagexml._DataType_Vec_uint8_t_4"

pagexml.DataType_Vec4d

   alias of "pagexml._DataType_Vec_double_4"

pagexml.DataType_Vec4f

   alias of "pagexml._DataType_Vec_float_4"

pagexml.DataType_Vec4i

   alias of "pagexml._DataType_Vec_int_4"

pagexml.DataType_Vec4s

   alias of "pagexml._DataType_Vec_short_4"

pagexml.DataType_Vec4w

   alias of "pagexml._DataType_Vec_ushort_4"

pagexml.DataType_Vec6d

   alias of "pagexml._DataType_Vec_double_6"

pagexml.DataType_Vec6f

   alias of "pagexml._DataType_Vec_float_6"

pagexml.DataType_Vec6i

   alias of "pagexml._DataType_Vec_int_6"

pagexml.DataType_Vec8i

   alias of "pagexml._DataType_Vec_int_8"

class pagexml.DataType_bool

   Bases: "object"

   channels = 1

   fmt = 'u'

   generic_type = 0

   thisown

      The membership flag

class pagexml.DataType_char

   Bases: "object"

   channels = 1

   fmt = 'c'

   generic_type = 0

   thisown

      The membership flag

class pagexml.DataType_double

   Bases: "object"

   channels = 1

   fmt = 'd'

   generic_type = 0

   thisown

      The membership flag

class pagexml.DataType_float

   Bases: "object"

   channels = 1

   fmt = 'f'

   generic_type = 0

   thisown

      The membership flag

class pagexml.DataType_int

   Bases: "object"

   channels = 1

   fmt = 'i'

   generic_type = 0

   thisown

      The membership flag

class pagexml.DataType_schar

   Bases: "object"

   channels = 1

   fmt = 'c'

   generic_type = 0

   thisown

      The membership flag

class pagexml.DataType_short

   Bases: "object"

   channels = 1

   fmt = 's'

   generic_type = 0

   thisown

      The membership flag

class pagexml.DataType_uchar

   Bases: "object"

   channels = 1

   fmt = 'u'

   generic_type = 0

   thisown

      The membership flag

class pagexml.DataType_ushort

   Bases: "object"

   channels = 1

   fmt = 'w'

   generic_type = 0

   thisown

      The membership flag

class pagexml.Mat(*args)

   Bases: "object"

   AUTO_STEP = 0

   CONTINUOUS_FLAG = 16384

   DEPTH_MASK = 7

   MAGIC_MASK = -65536

   MAGIC_VAL = 1124007936

   SUBMATRIX_FLAG = 32768

   TYPE_MASK = 4095

   addref()

   adjustROI(dtop, dbottom, dleft, dright)

   assignTo(m, type=-1)

   channels()

   checkVector(elemChannels, depth=-1, requireContinuous=True)

   clone()

   col(x)

   colRange(*args)

   cols

   copySize(m)

   create(*args)

   data

   dataend

   datalimit

   datastart

   deallocate()

   depth()

   diag(d=0)

   dims

   elemSize()

   elemSize1()

   empty()

   flags

   classmethod from_array(array)

   isContinuous()

   isSubmatrix()

   locateROI(wholeSize, ofs)

   pop_back(nelems=1)

   ptr(*args)

   push_back(m)

   push_back_(elem)

   release()

   reserve(sz)

   reshape(*args)

   resize(*args)

   row(y)

   rowRange(*args)

   rows

   step1(i=0)

   thisown

      The membership flag

   total()

   type()

pagexml.Mat1b

   alias of "pagexml._Mat__uchar"

pagexml.Mat1d

   alias of "pagexml._Mat__double"

pagexml.Mat1f

   alias of "pagexml._Mat__float"

pagexml.Mat1i

   alias of "pagexml._Mat__int"

pagexml.Mat1s

   alias of "pagexml._Mat__short"

pagexml.Mat1w

   alias of "pagexml._Mat__ushort"

pagexml.Mat2b

   alias of "pagexml._Mat__Vec2b"

pagexml.Mat2d

   alias of "pagexml._Mat__Vec2d"

pagexml.Mat2f

   alias of "pagexml._Mat__Vec2f"

pagexml.Mat2i

   alias of "pagexml._Mat__Vec2i"

pagexml.Mat2s

   alias of "pagexml._Mat__Vec2s"

pagexml.Mat2w

   alias of "pagexml._Mat__Vec2w"

pagexml.Mat3b

   alias of "pagexml._Mat__Vec3b"

pagexml.Mat3d

   alias of "pagexml._Mat__Vec3d"

pagexml.Mat3f

   alias of "pagexml._Mat__Vec3f"

pagexml.Mat3i

   alias of "pagexml._Mat__Vec3i"

pagexml.Mat3s

   alias of "pagexml._Mat__Vec3s"

pagexml.Mat3w

   alias of "pagexml._Mat__Vec3w"

pagexml.Mat4b

   alias of "pagexml._Mat__Vec4b"

pagexml.Mat4d

   alias of "pagexml._Mat__Vec4d"

pagexml.Mat4f

   alias of "pagexml._Mat__Vec4f"

pagexml.Mat4i

   alias of "pagexml._Mat__Vec4i"

pagexml.Mat4s

   alias of "pagexml._Mat__Vec4s"

pagexml.Mat4w

   alias of "pagexml._Mat__Vec4w"

pagexml.Matx21b

   alias of "pagexml._Matx_uint8_t_2_1"

pagexml.Matx21d

   alias of "pagexml._Matx_double_2_1"

pagexml.Matx21f

   alias of "pagexml._Matx_float_2_1"

pagexml.Matx21i

   alias of "pagexml._Matx_int_2_1"

pagexml.Matx21s

   alias of "pagexml._Matx_short_2_1"

pagexml.Matx21w

   alias of "pagexml._Matx_ushort_2_1"

pagexml.Matx31b

   alias of "pagexml._Matx_uint8_t_3_1"

pagexml.Matx31d

   alias of "pagexml._Matx_double_3_1"

pagexml.Matx31f

   alias of "pagexml._Matx_float_3_1"

pagexml.Matx31i

   alias of "pagexml._Matx_int_3_1"

pagexml.Matx31s

   alias of "pagexml._Matx_short_3_1"

pagexml.Matx31w

   alias of "pagexml._Matx_ushort_3_1"

pagexml.Matx41b

   alias of "pagexml._Matx_uint8_t_4_1"

pagexml.Matx41d

   alias of "pagexml._Matx_double_4_1"

pagexml.Matx41f

   alias of "pagexml._Matx_float_4_1"

pagexml.Matx41i

   alias of "pagexml._Matx_int_4_1"

pagexml.Matx41s

   alias of "pagexml._Matx_short_4_1"

pagexml.Matx41w

   alias of "pagexml._Matx_ushort_4_1"

pagexml.Matx61d

   alias of "pagexml._Matx_double_6_1"

pagexml.Matx61f

   alias of "pagexml._Matx_float_6_1"

pagexml.Matx61i

   alias of "pagexml._Matx_int_6_1"

pagexml.Matx81i

   alias of "pagexml._Matx_int_8_1"

class pagexml.Matx_AddOp

   Bases: "object"

   thisown

      The membership flag

class pagexml.Matx_DivOp

   Bases: "object"

   thisown

      The membership flag

class pagexml.Matx_MatMulOp

   Bases: "object"

   thisown

      The membership flag

class pagexml.Matx_MulOp

   Bases: "object"

   thisown

      The membership flag

class pagexml.Matx_ScaleOp

   Bases: "object"

   thisown

      The membership flag

class pagexml.Matx_SubOp

   Bases: "object"

   thisown

      The membership flag

class pagexml.Matx_TOp

   Bases: "object"

   thisown

      The membership flag

class pagexml.NamedImage(*args)

   Bases: "object"

   C++ includes: PageXML.h

   direction

   id

   image

   name

   node

   rotation

   thisown

      The membership flag

   x

   y

class pagexml.NamedImageVector(*args)

   Bases: "object"

   append(x)

   assign(n, x)

   back()

   begin()

   capacity()

   clear()

   empty()

   end()

   erase(*args)

   front()

   get_allocator()

   insert(*args)

   iterator()

   pop()

   pop_back()

   push_back(x)

   rbegin()

   rend()

   reserve(n)

   resize(*args)

   size()

   swap(v)

   thisown

      The membership flag

class pagexml.OGRMultiLineString_(*args)

   Bases: "object"

   C++ includes: PageXML.h

   multipolyline

   thisown

      The membership flag

class pagexml.OGRMultiPolygon_(*args)

   Bases: "object"

   C++ includes: PageXML.h

   multipolygon

   thisown

      The membership flag

class pagexml.PageXML(pagexml_path=None, schema_path=None)

   Bases: "object"

   C++ includes: PageXML.h

   addElem(*args)

   addGlyph(*args)

      Adds a Glyph to a given xpath.

      * *xpath* :

           Selector for element to set the Glyph.

      * *id* :

           ID for Glyph, if NULL it is selected automatically.

      * *before_id* :

           If !=NULL inserts it before the Glyph with this ID.

      Pointer to created element.

   addPage(*args)

      Adds a Page to the PcGts node.

      * *image* :

           Path to the image file.

      * *imgW* :

           Width of image.

      * *imgH* :

           Height of image.

      * *id* :

           ID for Page, if NULL it is left unset.

      * *before_node* :

           If !=NULL inserts it before the provided Page node.

      Pointer to created element.

   addTextLine(*args)

      Adds a TextLine to a given xpath.

      * *xpath* :

           Selector for element to add the TextLine.

      * *id* :

           ID for TextLine, if NULL it is selected automatically.

      * *before_id* :

           If !=NULL inserts it before the TextLine with this ID.

      Pointer to created element.

   addTextRegion(*args)

      Adds new TextRegion to a given xpath.

      * *xpath* :

           Selector for element to add the TextRegion.

      * *id* :

           ID for TextRegion, if NULL it is selected automatically.

      * *before_id* :

           If !=NULL inserts it before the TextRegion with this ID.

      Pointer to created element.

   addWord(*args)

      Adds a Word to a given xpath.

      * *xpath* :

           Selector for element to set the Word.

      * *id* :

           ID for Word, if NULL it is selected automatically.

      * *before_id* :

           If !=NULL inserts it before the Word with this ID.

      Pointer to created element.

   areIDsUnique()

      Verifies that all IDs in page are unique.

   closest(name, node)

      Selects closest node of a given name.

   computeAreas(polys)

      Computes the areas for given polygons.

      * *polys* :

           Polygons to process.

      The polygon areas.

   computeBaselineIntersectionsWeightedByArea(poly, polys, areas)

      Computes line-polygon intersections weighted by area.

      * *poly* :

           Polyline.

      * *polys* :

           Polygons to compare with.

      * *areas* :

           Polygons areas.

      Obtained intersection scores.

      Check input ///

      Compute intersections ///

      Return if fewer than 2 intersects ///

      Weight by areas ///

   computeCoordsIntersectionsWeightedByArea(poly, polys, areas)

      Computes polygon-polygon intersections weighted by area.

      * *poly* :

           Polygon.

      * *polys* :

           Polygons to compare with.

      * *areas* :

           Polygons areas.

      Obtained intersection scores.

      Check input ///

      Compute intersections ///

      Return if fewer than 2 intersects ///

      Weight by areas ///

   computeIntersectFactor(*args)

      Computes the intersection factor of one polyline over polygon.

      * *poly1* :

           Polyline.

      * *poly2* :

           Polygon.

      Factor value.

   computeIntersectionPercentage(poly1, poly2)

      Computes the intersection percentage of one polygon with respect
      to another polygons.

      * *poly1* :

           First polygon.

      * *poly2* :

           Second polygon.

      Intersection percentage value.

   computeIntersectionPercentages(poly, polys)

      Computes the intersection percentage of one polygon with respect
      to other polygons.

      * *poly* :

           Polygon.

      * *polys* :

           Vector of polygons.

      Intersection percentage values.

   computeIoU(poly1, poly2)

      Computes the intersection over union (IoU) of two polygons.

      * *poly1* :

           First polygon.

      * *poly2* :

           Second polygon.

      IoU value.

   computeIoUs(poly, polys)

      Computes the intersection over unions (IoU) of polygons.

      * *poly* :

           Polygon.

      * *polys* :

           Vector of polygons.

      IoU values.

   copyElem(elem, node, itype=0)

      Clone an element and add it relative to a given node.

      * *elem* :

           Element to clone.

      * *node* :

           Reference element for insertion.

      * *itype* :

           Type of insertion.

      Pointer to cloned element.

   copyTextLinesAssignByOverlap(pageFrom, overlap_thr=0.0, overlap_type=0, comb_alpha=0.5, verbose=False)

      Copies TextLines from one page xml to another assigning to
      regions based on overlap.

      * *pageFrom* :

           PageXML from where to copy TextLines.

      * *overlap_thr* :

           Overlapping score threshold for copying.

      * *overlap_type* :

           Type of overlap to use for assigning lines to regions.

      * *comb_alpha* :

           Weight for overlap factors: alpha*bline+(1-alpha)*coords.
           Only for PAGEXML_OVERLAP_COORDS_BASELINE_IWA.

      Number of TextLines copied.

      Loop through pages ///

      Check that image size is the same in both PageXMLs ///

      Select page region or create one if it does not exist ///

      Select relevant elements ///

      Get polygons of regions for IoU computation ///

      Loop through lines ///

      Compute overlap scores ///

      Check if TextLine should be copied ///

      Clone line and add it to the destination region node ///

      Remove added page region if no TextLine was added to it ///

   count(*args)

   crop(xpath, margin=None, opaque_coords=True, transp_xpath=None, base_xpath=None)

      Crops images using its Coords polygon, regions outside the
      polygon are set to transparent.

      * *xpath* :

           Selector for polygons to crop.

      * *margin* :

           Margins, if >1.0 pixels, otherwise percentage of maximum of
           crop width and height.

      * *opaque_coords* :

           Whether to include an alpha channel with the polygon
           interior in opaque.

      * *transp_xpath* :

           Selector for semi-transparent elements.

      An std::vector containing NamedImage objects of the cropped
      images.

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

   filter(xpath, elems)

      Filters a vector of xml nodes given an xpath.

      * *xpath* :

           Filtering expression.

      * *elems* :

           Vector of nodes to filter.

      Vector of filtered nodes.

   getAttr(*args)

   getBaselineOrientation(elem)

      Gets the baseline orientation angle (weighted average over
      polyline segments) of a given text line.

      * *elem* :

           Node of the TextLine element.

      The orientation angle in radians, NaN if unset.

   getDocPtr()

      Returns the XML document pointer.

   getDominantBaselinesOrientation(elems)

      Gets the dominant orientation angle for a set of baselines.

      * *elems* :

           Nodes of the TextLine elements.

      The dominant orientation angle in radians, NaN if unset.

   getFpgram(node)

      Retrieves the features parallelogram (Property[="fpgram"]/) for
      a given node.

      * *node* :

           Base node.

      Reference to the points vector.

   getImageBases()

      Gets image bases for all pages in xml.

      Vector of strings containing the image base names.

   getLeftRightTextContinuationGroups(elems, _group_order, _group_score, max_angle_diff=25, max_horiz_iou=0.1, min_prolong_fact=0.5, prolong_alpha=0.8, fake_baseline=False, recurse_factor=0.9)

      Determines groups of left-right text elem continuations
      (requires single segment polystripe).

      * *elems* :

           Text elements to test for continuation: TextLines, Words,
           Glyphs or TextRegions.

      * *_group_order* :

           Join groups line indices (output).

      * *_group_score* :

           Join group scores (output).

      * *max_angle_diff* :

           Maximum baseline angle difference for joining.

      * *max_horiz_iou* :

           Maximum horizontal IoU for joining.

      * *min_prolong_fact* :

           Minimum prolongation factor for joining.

      * *prolong_alpha* :

           Weight for prolongation factors:
           alpha*bline+(1-alpha)*coords.

      * *fake_baseline* :

           Use bottom line of Coords rectangle as the baseline.

      * *recurse_factor* :

           Multiplication factor for continuation criteria on each
           recursion.

      Number of join groups, elements per group in order and group
      scores.

      Get points and compute baseline angles and lengths ///

      Loop through all directed pairs of text elems ///

      Check that baseline angle difference is small ///

      Project baseline limits onto the local horizontal axis ///

      Check that elem n starts before elem m ///

      Check that horizontal IoU is small //

      Compute coords endpoint-startpoint intersection factors ///
      (both ways, intersection length of prolongated elem 1 and elem 2
      divided by height of elem 2) /// Todo Possible improvement:
      coords_fact_xx = isect_1d / min(norm_n,norm_m)

      Compute baseline alignment factors /// (both ways, one minus
      distance between prolongated baseline 1 and baseline 2 divided
      by height of elem 2 ) /// Todo Possible improvement: max( 0,
      1-norm(isec_xx-bline_x)/max(norm_n,norm_m) )

      Overall alignment factor ///

      Add text elem to a group (new or existing) ///

      Check if should be part of existing group ///

      Unique existing group ///

      Two existing groups, thus merge groups ///

      Update groups ///

      Adjust text elem order for groups with more than two text elems
      ///

      Get horizontal direction ///

      Check if there is high horizontal overlaps within group ///

      If high overlap recurse with stricter criterion ///

      Project baseline centers onto the local horizontal axis ///

      Sort text elems by horizontal center projections ///

      Score as average of scores ///

      Add recursed extra groups ///

      Sort groups based on first element original order ///

   getLeftRightTopBottomReadingOrder(elems, max_angle_diff=25, max_horiz_iou=0.1, min_prolong_fact=0.5, prolong_alpha=0.8, fake_baseline=False, recurse_factor=0.9)

      Gets the reading order for a set of text elems (requires single
      segment polystripe).

      * *elems* :

           Elements to process: TextLines, Words, Glyphs or
           TextRegions.

      * *max_angle_diff* :

           Maximum baseline angle difference for joining.

      * *max_horiz_iou* :

           Maximum horizontal IoU for joining.

      * *min_prolong_fact* :

           Minimum prolongation factor for joining.

      * *prolong_alpha* :

           Weight for prolongation factors:
           alpha*bline+(1-alpha)*coords.

      * *fake_baseline* :

           Use bottom line of Coords rectangle as the baseline.

      * *recurse_factor* :

           Multiplication factor for continuation criteria on each
           recursion.

      Pair of reading order indices and subgroup lengths.

      Get text elem join groups ///

      Get points and compute baseline angles and lengths ///

      Get horizontal direction ///

      Add text elems not in join groups ///

      Get vertical group center projections ///

      Sort groups by vertical center projections ///

      Populate reading order vector ///

   getNodeName(node, base_node=None)

      Gets the name of the given node.

      * *node* :

           XML node.

      String with the name.

   getOGRpolygon(*args)

      Gets an element's Coords as an OGRMultiPolygon.

      * *node* :

           The element from which to extract the Coords points.

      * *xpath* :

           Selector for the Coords element.

      Pointer to OGRMultiPolygon element.

   getOGRpolygonArea(poly)

      Gets the area of a OGRMultiPolygon.

      * *poly* :

           OGRMultiPolygon pointer.

      Area.

   getOGRpolygons(*args)

      Gets elements' Coords as OGRMultiPolygons.

      * *nodes* :

           Elements from which to extract the Coords points.

      * *xpath* :

           Selector for the Coords element.

      Vector of OGRMultiPolygon pointer elements.

   getOGRpolyline(*args)

      Gets the element's Baseline as an OGRMultiLineString.

      * *node* :

           The element from which to extract the Baseline points.

      Pointer to OGRMultiLineString element.

   getPageHeight(*args)

      Gets the height of a page (might be different to image width due
      to the image orientation).

      * *pagenum* :

           The page number (0-based).

      The page height.

   getPageImage(*args)

   getPageImageFilename(*args)

   getPageImageOrientation(*args)

      Gets the image orientation for the given Page number.

      * *pagenum* :

           The page number (0-based).

      Orientation in degrees.

   getPageNumber(node)

      Gets the page number for the given node.

   getPageWidth(*args)

      Gets the width of a page (might be different to image width due
      to the image orientation).

      * *pagenum* :

           The page number (0-based).

      The page width.

   getPagesSize(*args)

      Retrieves pages size.

      * *xpath* :

           Selector for Page nodes.

      Vector of page sizes.

   getPoints(*args)

      Retrieves and parses the Coords/ for a given list of base nodes.

      * *nodes* :

           Base nodes.

      Reference to the points vector.

   getPolylineLength(points)

      Gets the baseline length.

      * *points* :

           Baseline points.

      The orientation angle in radians, NaN if unset.

   getPolylineOrientation(points)

      Gets the baseline orientation angle (weighted average over
      polyline segments) in radians of a given baseline.

      * *points* :

           Baseline points.

      The orientation angle in radians, NaN if unset.

   getPropertyValue(node, key)

      Retrieves a Property value.

      * *node* :

           Node element.

      String with the property value.

   getReadingDirection(elem)

      Retrieves the reading direction for a given TextLine or
      TextRegion node.

      * *elem* :

           Node of the TextLine or TextRegion element.

      The reading direction, PAGEXML_READ_DIRECTION_LTR if unset.

      If TextLine try to get direction from custom attribute ///

      Otherwise try to get direction from readingDirection attribute
      ///

   getRotation(elem)

      Retrieves the rotation angle for a given TextLine or TextRegion
      node.

      * *elem* :

           Node of the TextLine or TextRegion element.

      The rotation angle in degrees, 0 if unset.

      If TextLine try to get rotation from custom attribute ///

      Otherwise try to get rotation from readingOrientation attribute
      ///

   getTextEquiv(*args)

      Retrieves the concatenated TextEquivs for a given root node and
      xpath.

      * *node* :

           Root node element.

      * *xpath* :

           Relative xpath to select the TextEquiv elements.

      * *separator* :

           String to add between TextEquivs.

      String with the concatenated TextEquivs.

   getUnionOGRpolygon(*args)

      Gets the union of Coords elements as a OGRMultiPolygon.

      * *nodes* :

           Elements from which to extract the Coords points.

      * *xpath* :

           Selector for the Coords element.

      Pointer to OGRMultiPolygon element.

   getUniqueID(prefix, suffix=None, count_start=1, count_max=100000)

      Gets a unique id.

      * *prefix* :

           Prefix for id.

      * *suffix* :

           Suffix for id.

      * *count_start* :

           Counter start to place between prefix and suffix.

      * *count_max* :

           Maximum count to test.

      The generated unique id.

   getValue(*args)

      Retrieves a node value.

      * *xpath* :

           Selector for the element to get the value.

      * *node* :

           XML node for context, set to NULL for root node.

      String with the node value.

   getXheight(*args)

      Retrieves the x-height for a given TextLine id.

      * *id* :

           Identifier of the TextLine.

      x-height>0 on success, -1 if unset.

   insertElem(elem, node, itype)

      Inserts an element relative to a given node.

      * *elem* :

           Element to insert.

      * *node* :

           Reference element for insertion.

      * *itype* :

           Type of insertion.

      Pointer to inserted element.

   intersection(line1_point1, line1_point2, line2_point1, line2_point2, _ipoint)

      Finds the intersection point between two lines defined by pairs
      of points or returns false if no intersection

   static isBBox(points)

      Determines whether a vector of points defines a bounding box.

      * *points* :

           The vector of points to find the limits.

      True if bounding box, otherwise false.

   isPageImageLoaded(*args)

   isPolystripe(coords, baseline, height=None, offset=None)

      Checks whether Coords is a poly-stripe for its corresponding
      baseline.

      * *coords* :

           Coords points.

      * *baseline* :

           Baseline points.

      * *offset* :

           The offset of the poly-stripe (>=0 && <= 0.5).

      Pointer to created element.

      Check points are collinear ///

      Check lines are parallel ///

      Check stripe extremes perpendicular to baseline ///

   isValid(xml_to_validate=0)

      Validates the currently loaded XML.

   loadImage(*args)

   loadImages(resize_coords=False, density=0)

   loadSchema(schema_path)

      Loads a schema for xml validation.

      * *schema_path* :

           File name of the XSD file to read.

   loadXml(*args)

      Loads a Page XML from an input stream.

      * *fnum* :

           File number from where to read the XML file.

      * *prevfree* :

           Whether to release resources before loading.

   loadXmlString(xml_string, validate=True)

      Loads a Page XML from a string.

      * *xml_string* :

           The XML content.

   moveElem(elem, node, itype=0)

      Unlink an element and add it relative to a given node.

      * *elem* :

           Element to move.

      * *node* :

           Reference element for insertion.

      * *itype* :

           Type of insertion.

      Pointer to moved element.

   moveElems(elems, node, itype=0)

      Unlink elements and add them relative to a given node.

      * *elems* :

           Elements to move.

      * *node* :

           Reference element for insertion.

      * *itype* :

           Type of insertion.

      Pointer to moved element.

   multiPolygonIntersection(poly1, poly2)

      Computes the intersection of two multipolygons.

      * *poly1* :

           First polygon.

      * *poly2* :

           Second polygon.

      Intersection geometry.

   multiPolylineIntersection(poly1, poly2)

      Computes the intersection between a multipolylines and a
      multipolygon.

      * *poly1* :

           Polyline.

      * *poly2* :

           Polygon.

      Intersection geometry.

   newXml(creator, image, imgW=0, imgH=0)

      Loaders ///.

      Creates a new Page XML.

      * *creator* :

           Info about tool creating the XML.

      * *image* :

           Path to the image file.

      * *imgW* :

           Width of image.

      * *imgH* :

           Height of image.

   static nodeIs(node, name)

      Checks if node is of given name.

      * *node* :

           XML node.

      * *name* :

           String with name to match against.

      True if name matches, otherwise false.

   parent(node)

      Returns the parent of a node.

      * *node* :

           XML node.

      Parent node.

   static pointsBBox(points)

      Generates a vector of 4 points that define the bounding box for
      a given vector of points.

      * *points* :

           The vector of points to find the limits.

      The 4 points defining the bounding box (top-left clockwise).

   static pointsLimits(points, xmin, xmax, ymin, ymax)

      Gets the minimum and maximum coordinate values for an array of
      points.

      * *points* :

           The vector of points to find the limits.

      * *xmin* :

           Minimum x value.

      * *xmax* :

           Maximum x value.

      * *ymin* :

           Minimum y value.

      * *ymax* :

           Maximum y value.

   pointsToOGRpolygon(points)

      Converts Coords to an OGRMultiPolygon.

      * *points* :

           Vector of x,y points.

      Pointer to OGRMultiPolygon element.

   pointsToOGRpolygons(points)

      Converts Coords to OGRMultiPolygons.

      * *points* :

           Vectors of x,y points.

      Pointer to OGRMultiPolygon element.

   static pointsToString(*args)

   printConf(*args)

      Configuration ///.

      Prints the current configuration.

      * *file* :

           File to print to.

   static printVersions(*args)

   processEnd()

      Ends the running process in the Page XML.

   processStart(tool, ref=None)

      Starts a process in the Page XML.

      Add Process element ///

      Start time attribute ///

      Tool and ref attributes ///

   relabelChildIDs(node, include_self=False)

      Relabels IDs of child elements.

      * *node* :

           Base node.

      * *include_self* :

           Whether to also relabel the base node.

      Number of IDs affected.

   relativizeImageFilename(xml_path)

      Modifies imageFilename to be a relative path w.r.t. given xml
      path. Currently just checks prefix directories and removes it.

   releaseImage(*args)

   releaseImages()

   resize(*args)

      Resizes a page and all respective coordinates.

      * *factor* :

           Resizing factor.

      * *xpath* :

           Selector for Page nodes.

      Number of pages+points attributes modified.

   rmElem(node)

      Removes the given element.

      * *node* :

           Element.

   rmElems(*args)

   rotatePage(*args)

      Rotates a page.

      * *angle* :

           Angle to rotate in degrees {0,90,180,-90}.

      * *page* :

           The Page node.

      * *update_image_orientation* :

           Whether to check that the aspect ratio is properly
           preserved.

      * *_conf* :

           Pointer to confidence value, NULL for no confidence.

      Number of elements modified.

      Normalize angle between [-90,180] ///

      Set image orientation ///

      Select all elements with coordinates ///

      Rotate all coordinates ///

   select(*args)

   selectByID(id, node=None)

      Selects an element with a given ID.

      * *id* :

           ID of element to select.

      * *node* :

           XML node for context, set to NULL for root node.

      Matched node.

   selectByOverlap(*args)

      Selects elements based on overlap to a polygon.

      * *points* :

           Polygon for selection.

      * *pagenum* :

           Page number for selection.

      * *xpath* :

           xpath for candidate elements for selection.

      * *overlap_thr* :

           Overlapping score threshold.

      * *overlap_type* :

           Type of overlap to use for selecting.

      Number of TextLines copied.

   selectNth(*args)

   setAttr(*args)

   setBaseline(*args)

      Adds or modifies (if already exists) a two point Baseline for a
      given node.

      * *node* :

           The node of element to set the Baseline.

      * *x1* :

           x value of first point.

      * *y1* :

           y value of first point.

      * *x2* :

           x value of second point.

      * *y2* :

           y value of second point.

      * *conf* :

           Confidence value.

      Pointer to created element.

   setCoords(*args)

   setCoordsBBox(*args)

      Adds or modifies (if already exists) the Coords as a bounding
      box for a given node.

      * *node* :

           The node of element to set the Coords.

      * *xmin* :

           Minimum x value of bounding box.

      * *ymin* :

           Minimum y value of bounding box.

      * *width* :

           Width of bounding box.

      * *height* :

           Height of bounding box.

      * *conf* :

           Confidence value.

      * *subone* :

           Whether to subtract 1 when computing xmax and ymax
           (discrete compatibility).

      Pointer to created element.

   setPageHeight(node, height)

      Sets the height of a page (actually sets imageHeight accounting
      for image orientation).

      * *node* :

           A node to set its page height.

      * *height* :

           The height to set.

   setPageImageFilename(*args)

   setPageImageOrientation(*args)

      Sets the image orientation for the given Page number.

      * *pagenum* :

           The page number (0-based).

      * *angle* :

           The orientation angle in degrees {0,90,180,-90}.

      * *conf* :

           Confidence value.

   setPageWidth(node, width)

      Sets the width of a page (actually sets imageWidth accounting
      for image orientation).

      * *node* :

           A node to set its page width.

      * *width* :

           The width to set.

   setPolystripe(node, height, offset=0.25, offset_check=True)

      Sets the Coords of a TextLine as a poly-stripe of the baseline.

      * *node* :

           The node of element to set the Coords.

      * *height* :

           The height of the poly-stripe in pixels (>0).

      * *offset* :

           The offset of the poly-stripe (>=0 && <= 0.5).

      Pointer to created element.

   setProperty(*args)

      Sets a Property to a given node.

      * *node* :

           The node of element to set the Property.

      * *key* :

           The key for the Property.

      * *val* :

           The optional value for the Property.

      * *conf* :

           Confidence value.

      Pointer to created element.

   setReadingDirection(elem, direction)

      Sets the reading direction to a TextRegion node.

      * *node* :

           Node of the TextRegion element.

      * *direction* :

           Direction to set.

   setRotation(elem, rotation)

      Sets the rotation angle to a TextRegion node.

      * *node* :

           Node of the TextRegion element.

      * *rotation* :

           Rotation angle to set.

   setTextEquiv(*args)

      Adds or modifies (if already exists) the TextEquiv for a given
      xpath.

      * *xpath* :

           Selector for element to set the TextEquiv.

      * *text* :

           The text string.

      * *conf* :

           Confidence value.

      Pointer to created element.

   static setValidationEnabled(val)

      Enables/disables schema validation.

   setValue(node, value)

      Sets a node value.

      * *node* :

           Node element.

      String with the node value.

   simplifyIDs()

      Simplifies IDs by removing imgbase prefixes and replaces invalid
      characters with _.

      Number of IDs simplified.

   static stringToPoints(*args)

   thisown

      The membership flag

   toString(validate=True)

      Creates a string representation of the Page XML.

   updateLastChange()

      Updates the last change time stamp.

   static version()

      Returns the class version.

   write(*args)

      Output ///.

      Writes the current state of the XML to a file using utf-8
      encoding.

      * *fname* :

           File name of where the XML file will be written.

      Number of bytes written.

pagexml.PageXML_isBBox(points)

   Determines whether a vector of points defines a bounding box.

   * *points* :

        The vector of points to find the limits.

   True if bounding box, otherwise false.

pagexml.PageXML_nodeIs(node, name)

   Checks if node is of given name.

   * *node* :

        XML node.

   * *name* :

        String with name to match against.

   True if name matches, otherwise false.

pagexml.PageXML_pointsBBox(points)

   Generates a vector of 4 points that define the bounding box for a
   given vector of points.

   * *points* :

        The vector of points to find the limits.

   The 4 points defining the bounding box (top-left clockwise).

pagexml.PageXML_pointsLimits(points, xmin, xmax, ymin, ymax)

   Gets the minimum and maximum coordinate values for an array of
   points.

   * *points* :

        The vector of points to find the limits.

   * *xmin* :

        Minimum x value.

   * *xmax* :

        Maximum x value.

   * *ymin* :

        Minimum y value.

   * *ymax* :

        Maximum y value.

pagexml.PageXML_pointsToString(*args)

pagexml.PageXML_printVersions(*args)

pagexml.PageXML_setValidationEnabled(val)

   Enables/disables schema validation.

pagexml.PageXML_stringToPoints(*args)

pagexml.PageXML_version()

   Returns the class version.

pagexml.Point

   alias of "pagexml._Point__int"

pagexml.Point2d

   alias of "pagexml._Point__double"

pagexml.Point2f

   alias of "pagexml._Point__float"

pagexml.Point2i

   alias of "pagexml._Point__int"

class pagexml.Range(*args)

   Bases: "object"

   static all()

   empty()

   end

   size()

   start

   thisown

      The membership flag

pagexml.Size

   alias of "pagexml._Size__int"

pagexml.Size2d

   alias of "pagexml._Size__double"

pagexml.Size2f

   alias of "pagexml._Size__float"

pagexml.Size2i

   alias of "pagexml._Size__int"

class pagexml.SwigPyIterator(*args, **kwargs)

   Bases: "object"

   advance(n)

   copy()

   decr(n=1)

   distance(x)

   equal(x)

   incr(n=1)

   next()

   previous()

   thisown

      The membership flag

   value()

pagexml.Vec2b

   alias of "pagexml._Vec_uint8_t_2"

pagexml.Vec2d

   alias of "pagexml._Vec_double_2"

pagexml.Vec2f

   alias of "pagexml._Vec_float_2"

pagexml.Vec2i

   alias of "pagexml._Vec_int_2"

pagexml.Vec2s

   alias of "pagexml._Vec_short_2"

pagexml.Vec2w

   alias of "pagexml._Vec_ushort_2"

pagexml.Vec3b

   alias of "pagexml._Vec_uint8_t_3"

pagexml.Vec3d

   alias of "pagexml._Vec_double_3"

pagexml.Vec3f

   alias of "pagexml._Vec_float_3"

pagexml.Vec3i

   alias of "pagexml._Vec_int_3"

pagexml.Vec3s

   alias of "pagexml._Vec_short_3"

pagexml.Vec3w

   alias of "pagexml._Vec_ushort_3"

pagexml.Vec4b

   alias of "pagexml._Vec_uint8_t_4"

pagexml.Vec4d

   alias of "pagexml._Vec_double_4"

pagexml.Vec4f

   alias of "pagexml._Vec_float_4"

pagexml.Vec4i

   alias of "pagexml._Vec_int_4"

pagexml.Vec4s

   alias of "pagexml._Vec_short_4"

pagexml.Vec4w

   alias of "pagexml._Vec_ushort_4"

pagexml.Vec6d

   alias of "pagexml._Vec_double_6"

pagexml.Vec6f

   alias of "pagexml._Vec_float_6"

pagexml.Vec6i

   alias of "pagexml._Vec_int_6"

pagexml.Vec8i

   alias of "pagexml._Vec_int_8"

class pagexml.cvPoint2fVector(*args)

   Bases: "object"

   append(x)

   assign(n, x)

   back()

   begin()

   capacity()

   clear()

   empty()

   end()

   erase(*args)

   front()

   get_allocator()

   insert(*args)

   iterator()

   pop()

   pop_back()

   push_back(x)

   rbegin()

   rend()

   reserve(n)

   resize(*args)

   size()

   swap(v)

   thisown

      The membership flag

class pagexml.cvSize2iVector(*args)

   Bases: "object"

   append(x)

   assign(n, x)

   back()

   begin()

   capacity()

   clear()

   empty()

   end()

   erase(*args)

   front()

   get_allocator()

   insert(*args)

   iterator()

   pop()

   pop_back()

   push_back(x)

   rbegin()

   rend()

   reserve(n)

   resize(*args)

   size()

   swap(v)

   thisown

      The membership flag

class pagexml.ptr_cvPoint2fVector

   Bases: "object"

   assign(value)

   cast()

   static frompointer()

   thisown

      The membership flag

   value()

class pagexml.ptr_cvPointVector

   Bases: "object"

   assign(value)

   cast()

   static frompointer()

   thisown

      The membership flag

   value()

class pagexml.ptr_double

   Bases: "object"

   assign(value)

   cast()

   static frompointer()

   thisown

      The membership flag

   value()

class pagexml.xmlNodePtrVector(*args)

   Bases: "object"

   append(x)

   assign(n, x)

   back()

   begin()

   capacity()

   clear()

   empty()

   end()

   erase(*args)

   front()

   get_allocator()

   insert(*args)

   iterator()

   pop()

   pop_back()

   push_back(x)

   rbegin()

   rend()

   reserve(n)

   resize(*args)

   size()

   swap(v)

   thisown

      The membership flag
