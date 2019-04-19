pagexml API (version 2019.4.11)
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

   multipolyline

   thisown

      The membership flag

class pagexml.OGRMultiPolygon_(*args)

   Bases: "object"

   multipolygon

   thisown

      The membership flag

class pagexml.PageXML(pagexml_path=None, schema_path=None)

   Bases: "object"

   addElem(*args)

      Overloaded function with 3 signatures.

      **Signature 1**

      "xmlNodePt PageXML::addElem(const char *name, const char *id,
      const xmlNodePt node, PAGEXML_INSERT
      itype=PAGEXML_INSERT_APPEND, bool checkid=false)"

      Creates a new element and adds it relative to a given node.

      Parameters:
         * **name** (*const char **) – Name of element to create.

         * **id** (*const char **) – ID attribute for element.

         * **node** (*const xmlNodePt*) – Reference element for
           insertion.

         * **itype** (*PAGEXML_INSERT*) – Type of insertion.

         * **checkid** (*bool*) –

      Returns:
         Pointer to created element.

      Return type:
         xmlNodePt

      **Signature 2**

      "xmlNodePt PageXML::addElem(const char *name, const char *id,
      const char *xpath, PAGEXML_INSERT itype=PAGEXML_INSERT_APPEND,
      bool checkid=false)"

      Creates a new element and adds it relative to a given xpath.

      Parameters:
         * **name** (*const char **) – Name of element to create.

         * **id** (*const char **) – ID attribute for element.

         * **xpath** (*const char **) – Selector for insertion.

         * **itype** (*PAGEXML_INSERT*) – Type of insertion.

         * **checkid** (*bool*) –

      Returns:
         Pointer to created element.

      Return type:
         xmlNodePt

      **Signature 3**

      "xmlNodePt PageXML::addElem(const std::string name, const
      std::string id, const std::string xpath, PAGEXML_INSERT
      itype=PAGEXML_INSERT_APPEND, bool checkid=false)"

      Parameters:
         * **name** (*const std::string*) –

         * **id** (*const std::string*) –

         * **xpath** (*const std::string*) –

         * **itype** (*PAGEXML_INSERT*) –

         * **checkid** (*bool*) –

      Returns:
      Return type:
         xmlNodePt

   addGlyph(*args)

      Overloaded function with 2 signatures.

      **Signature 1**

      "xmlNodePt PageXML::addGlyph(xmlNodePt node, const char
      *id=NULL, const char *before_id=NULL)"

      Adds a Glyph to a given node.

      Parameters:
         * **node** (*xmlNodePt*) – The node of element to add the
           Glyph.

         * **id** (*const char **) – ID for Glyph, if NULL it is
           selected automatically.

         * **before_id** (*const char **) – If !=NULL inserts it
           before the Glyph with this ID.

      Returns:
         Pointer to created element.

      Return type:
         xmlNodePt

      **Signature 2**

      "xmlNodePt PageXML::addGlyph(const char *xpath, const char
      *id=NULL, const char *before_id=NULL)"

      Adds a Glyph to a given xpath.

      Parameters:
         * **xpath** (*const char **) – Selector for element to set
           the Glyph.

         * **id** (*const char **) – ID for Glyph, if NULL it is
           selected automatically.

         * **before_id** (*const char **) – If !=NULL inserts it
           before the Glyph with this ID.

      Returns:
         Pointer to created element.

      Return type:
         xmlNodePt

   addPage(*args)

      Overloaded function with 2 signatures.

      **Signature 1**

      "xmlNodePt PageXML::addPage(const char *image, const int imgW,
      const int imgH, const char *id=NULL, xmlNodePt
      before_node=NULL)"

      Adds a Page to the PcGts node.

      Parameters:
         * **image** (*const char **) – Path to the image file.

         * **imgW** (*const int*) – Width of image.

         * **imgH** (*const int*) – Height of image.

         * **id** (*const char **) – ID for Page, if NULL it is left
           unset.

         * **before_node** (*xmlNodePt*) – If !=NULL inserts it
           before the provided Page node.

      Returns:
         Pointer to created element.

      Return type:
         xmlNodePt

      **Signature 2**

      "xmlNodePt PageXML::addPage(std::string image, const int imgW,
      const int imgH, const char *id=NULL, xmlNodePt
      before_node=NULL)"

      Adds a Page to the PcGts node.

      Parameters:
         * **image** (*std::string*) – Path to the image file.

         * **imgW** (*const int*) – Width of image.

         * **imgH** (*const int*) – Height of image.

         * **id** (*const char **) – ID for Page, if NULL it is left
           unset.

         * **before_node** (*xmlNodePt*) – If !=NULL inserts it
           before the provided Page node.

      Returns:
         Pointer to created element.

      Return type:
         xmlNodePt

   addTextLine(*args)

      Overloaded function with 2 signatures.

      **Signature 1**

      "xmlNodePt PageXML::addTextLine(xmlNodePt node, const char
      *id=NULL, const char *before_id=NULL)"

      Adds a TextLine to a given node.

      Parameters:
         * **node** (*xmlNodePt*) – The node of element to add the
           TextLine.

         * **id** (*const char **) – ID for TextLine, if NULL it is
           selected automatically.

         * **before_id** (*const char **) – If !=NULL inserts it
           before the TextLine with this ID.

      Returns:
         Pointer to created element.

      Return type:
         xmlNodePt

      **Signature 2**

      "xmlNodePt PageXML::addTextLine(const char *xpath, const char
      *id=NULL, const char *before_id=NULL)"

      Adds a TextLine to a given xpath.

      Parameters:
         * **xpath** (*const char **) – Selector for element to add
           the TextLine.

         * **id** (*const char **) – ID for TextLine, if NULL it is
           selected automatically.

         * **before_id** (*const char **) – If !=NULL inserts it
           before the TextLine with this ID.

      Returns:
         Pointer to created element.

      Return type:
         xmlNodePt

   addTextRegion(*args)

      Overloaded function with 2 signatures.

      **Signature 1**

      "xmlNodePt PageXML::addTextRegion(xmlNodePt node, const char
      *id=NULL, const char *before_id=NULL, bool prepend=false)"

      Adds a TextRegion to a given node.

      Parameters:
         * **node** (*xmlNodePt*) – The node of element to add the
           TextRegion.

         * **id** (*const char **) – ID for TextRegion, if NULL it
           is selected automatically.

         * **before_id** (*const char **) – If !=NULL inserts it
           before the TextRegion with this ID.

         * **prepend** (*bool*) – Whether to add element before all
           other TextRegions.

      Returns:
         Pointer to created element.

      Return type:
         xmlNodePt

      **Signature 2**

      "xmlNodePt PageXML::addTextRegion(const char *xpath, const char
      *id=NULL, const char *before_id=NULL, bool prepend=false)"

      Adds new TextRegion to a given xpath.

      Parameters:
         * **xpath** (*const char **) – Selector for element to add
           the TextRegion.

         * **id** (*const char **) – ID for TextRegion, if NULL it
           is selected automatically.

         * **before_id** (*const char **) – If !=NULL inserts it
           before the TextRegion with this ID.

         * **prepend** (*bool*) –

      Returns:
         Pointer to created element.

      Return type:
         xmlNodePt

   addWord(*args)

      Overloaded function with 2 signatures.

      **Signature 1**

      "xmlNodePt PageXML::addWord(xmlNodePt node, const char *id=NULL,
      const char *before_id=NULL)"

      Adds a Word to a given node.

      Parameters:
         * **node** (*xmlNodePt*) – The node of element to add the
           Word.

         * **id** (*const char **) – ID for Word, if NULL it is
           selected automatically.

         * **before_id** (*const char **) – If !=NULL inserts it
           before the Word with this ID.

      Returns:
         Pointer to created element.

      Return type:
         xmlNodePt

      **Signature 2**

      "xmlNodePt PageXML::addWord(const char *xpath, const char
      *id=NULL, const char *before_id=NULL)"

      Adds a Word to a given xpath.

      Parameters:
         * **xpath** (*const char **) – Selector for element to set
           the Word.

         * **id** (*const char **) – ID for Word, if NULL it is
           selected automatically.

         * **before_id** (*const char **) – If !=NULL inserts it
           before the Word with this ID.

      Returns:
         Pointer to created element.

      Return type:
         xmlNodePt

   areIDsUnique()

      Verifies that all IDs in page are unique.

      Returns:
      Return type:
         bool

   clone()

      Returns:
      Return type:
         PageXML

   closest(name, node)

      Selects closest node of a given name.

      Parameters:
         * **name** (*const char **) –

         * **node** (*xmlNodePt*) –

      Returns:
      Return type:
         xmlNodePt

   computeAreas(polys)

      Computes the areas for given polygons.

      Parameters:
         **polys** (std::vector< >>OGRMultiPolygonPtr_<< >) – Polygons
         to process.

      Returns:
         The polygon areas.

      Return type:
         std::vector< double >

   computeBaselineIntersectionsWeightedByArea(poly, polys, areas)

      Computes line-polygon intersections weighted by area.

      Parameters:
         * **poly** (>>OGRMultiLineStringPtr_<<) – Polyline.

         * **polys** (std::vector< >>OGRMultiPolygonPtr_<< >) –
           Polygons to compare with.

         * **areas** (*std::vector< double >*) – Polygons areas.

      Returns:
         Obtained intersection scores.

      Return type:
         std::vector< double >

   computeCoordsIntersectionsWeightedByArea(poly, polys, areas)

      Computes polygon-polygon intersections weighted by area.

      Parameters:
         * **poly** (>>OGRMultiPolygonPtr_<<) – Polygon.

         * **polys** (std::vector< >>OGRMultiPolygonPtr_<< >) –
           Polygons to compare with.

         * **areas** (*std::vector< double >*) – Polygons areas.

      Returns:
         Obtained intersection scores.

      Return type:
         std::vector< double >

   computeIntersectFactor(*args)

      Overloaded function with 2 signatures.

      **Signature 1**

      "double PageXML::computeIntersectFactor(OGRMultiPolygonPtr_
      poly1, OGRMultiPolygonPtr_ poly2)"

      Computes the intersection factor of one multipolygon over
      another.

      Parameters:
         * **poly1** (>>OGRMultiPolygonPtr_<<) – First polygon.

         * **poly2** (>>OGRMultiPolygonPtr_<<) – Second polygon.

      Returns:
         Factor value.

      Return type:
         double

      **Signature 2**

      "double PageXML::computeIntersectFactor(OGRMultiLineStringPtr_
      poly1, OGRMultiPolygonPtr_ poly2)"

      Computes the intersection factor of one polyline over polygon.

      Parameters:
         * **poly1** (>>OGRMultiLineStringPtr_<<) – Polyline.

         * **poly2** (>>OGRMultiPolygonPtr_<<) – Polygon.

      Returns:
         Factor value.

      Return type:
         double

   computeIntersectionPercentage(poly1, poly2)

      Computes the intersection percentage of one polygon with respect
      to another polygons.

      Parameters:
         * **poly1** (>>OGRMultiPolygonPtr_<<) – First polygon.

         * **poly2** (>>OGRMultiPolygonPtr_<<) – Second polygon.

      Returns:
         Intersection percentage value.

      Return type:
         double

   computeIntersectionPercentages(poly, polys)

      Computes the intersection percentage of one polygon with respect
      to other polygons.

      Parameters:
         * **poly** (>>OGRMultiPolygonPtr_<<) – Polygon.

         * **polys** (std::vector< >>OGRMultiPolygonPtr_<< >) –
           Vector of polygons.

      Returns:
         Intersection percentage values.

      Return type:
         std::vector< double >

   computeIoU(poly1, poly2)

      Computes the intersection over union (IoU) of two polygons.

      Parameters:
         * **poly1** (>>OGRMultiPolygonPtr_<<) – First polygon.

         * **poly2** (>>OGRMultiPolygonPtr_<<) – Second polygon.

      Returns:
         IoU value.

      Return type:
         double

   computeIoUs(poly, polys)

      Computes the intersection over unions (IoU) of polygons.

      Parameters:
         * **poly** (>>OGRMultiPolygonPtr_<<) – Polygon.

         * **polys** (std::vector< >>OGRMultiPolygonPtr_<< >) –
           Vector of polygons.

      Returns:
         IoU values.

      Return type:
         std::vector< double >

   copyElem(elem, node, itype=0)

      Clone an element and add it relative to a given node.

      Parameters:
         * **elem** (*xmlNodePt*) – Element to clone.

         * **node** (*const xmlNodePt*) – Reference element for
           insertion.

         * **itype** (*PAGEXML_INSERT*) – Type of insertion.

      Returns:
         Pointer to cloned element.

      Return type:
         xmlNodePt

   copyTextLinesAssignByOverlap(pageFrom, overlap_thr=0.0, overlap_type=0, comb_alpha=0.5, verbose=False)

      Copies TextLines from one page xml to another assigning to
      regions based on overlap.

      Parameters:
         * **pageFrom** (*PageXML &*) – PageXML from where to copy
           TextLines.

         * **overlap_thr** (*double*) – Overlapping score threshold.
           If overlap below threshold, TextLine is copied to the page
           region.

         * **overlap_type** (*PAGEXML_OVERLAP*) – Type of overlap to
           use for assigning lines to regions.

         * **comb_alpha** (*double*) – Weight for overlap factors:
           alpha*bline+(1-alpha)*coords. Only for
           PAGEXML_OVERLAP_COORDS_BASELINE_IWA.

         * **verbose** (*bool*) –

      Returns:
         Number of TextLines copied.

      Return type:
         int

   count(*args)

      Overloaded function with 2 signatures.

      **Signature 1**

      "int PageXML::count(const char *xpath, xmlNodePt node=NULL)"

      Returns number of matched nodes for a given xpath.

      Parameters:
         * **xpath** (*const char **) – Selector expression.

         * **node** (*xmlNodePt*) – XML node for context, set to
           NULL for root node.

      Returns:
         Number of matched nodes.

      Return type:
         int

      **Signature 2**

      "int PageXML::count(std::string xpath, xmlNodePt node=NULL)"

      Parameters:
         * **xpath** (*std::string*) –

         * **node** (*xmlNodePt*) –

      Returns:
      Return type:
         int

   crop(xpath, margin=None, opaque_coords=True, transp_xpath=None, base_xpath=None)

      Crops images using its Coords polygon, regions outside the
      polygon are set to transparent.

      Parameters:
         * **xpath** (*const char **) – Selector for polygons to
           crop.

         * **margin** (*cv::Point2f **) – Margins, if >1.0 pixels,
           otherwise percentage of maximum of crop width and height.

         * **opaque_coords** (*bool*) – Whether to include an alpha
           channel with the polygon interior in opaque.

         * **transp_xpath** (*const char **) – Selector for semi-
           transparent elements.

         * **base_xpath** (*const char **) –

      Returns:
         An std::vector containing NamedImage objects of the cropped
         images.

      Return type:
         std::vector< NamedImage >

   filter(xpath, elems)

      Filters a vector of xml nodes given an xpath.

      Parameters:
         * **xpath** (*const char **) – Filtering expression.

         * **elems** (*const std::vector< xmlNodePt >*) – Vector of
           nodes to filter.

      Returns:
         Vector of filtered nodes.

      Return type:
         std::vector< xmlNodePt >

   getAttr(*args)

      Overloaded function with 3 signatures.

      **Signature 1**

      "string PageXML::getAttr(const xmlNodePt node, const char
      *name)"

      Gets an attribute value from an xml node.

      Parameters:
         * **node** (*const xmlNodePt*) – XML node.

         * **name** (*const char **) – Attribute name.

      Returns:
         True if attribute found, otherwise false.

      Return type:
         std::string

      **Signature 2**

      "string PageXML::getAttr(const char *xpath, const char *name)"

      Gets an attribute value for a given xpath.

      Parameters:
         * **xpath** (*const char **) – Selector for the element to
           get the attribute.

         * **name** (*const char **) – Attribute name.

      Returns:
         True if attribute found, otherwise false.

      Return type:
         std::string

      **Signature 3**

      "std::string PageXML::getAttr(const std::string xpath, const
      std::string name)"

      Parameters:
         * **xpath** (*const std::string*) –

         * **name** (*const std::string*) –

      Returns:
      Return type:
         std::string

   getBaselineOrientation(elem)

      Gets the baseline orientation angle (weighted average over
      polyline segments) of a given text line.

      Parameters:
         **elem** (*xmlNodePt*) – Node of the TextLine element.

      Returns:
         The orientation angle in radians, NaN if unset.

      Return type:
         double

   getDocPtr()

      Returns the XML document pointer.

      Returns:
      Return type:
         xmlDocPtr

   getDominantBaselinesOrientation(elems)

      Gets the dominant orientation angle for a set of baselines.

      Parameters:
         **elems** (*std::vector< xmlNodePt >*) – Nodes of the
         TextLine elements.

      Returns:
         The dominant orientation angle in radians, NaN if unset.

      Return type:
         double

   getFpgram(node)

      Retrieves the features parallelogram
      (Property[@key=’fpgram’]/@value) for a given node.

      Parameters:
         **node** (*const xmlNodePt*) – Base node.

      Returns:
         Reference to the points vector.

      Return type:
         std::vector< cv::Point2f >

   getImageBases()

      Gets image bases for all pages in xml.

      Returns:
         Vector of strings containing the image base names.

      Return type:
         std::vector< std::string >

   getImagesBaseDir()

      Returns:
      Return type:
         std::string

   getLeftRightTextContinuationGroups(elems, _group_order, _group_score, max_angle_diff=25, max_horiz_iou=0.1, min_prolong_fact=0.5, prolong_alpha=0.8, fake_baseline=False, recurse_factor=0.9)

      Determines groups of left-right text elem continuations
      (requires single segment polystripe).

      Parameters:
         * **elems** (*std::vector< xmlNodePt >*) – Text elements to
           test for continuation: TextLines, Words, Glyphs or
           TextRegions.

         * **_group_order** (*std::vector< std::vector< int > > &*)
           – Join groups line indices (output).

         * **_group_score** (*std::vector< double > &*) – Join group
           scores (output).

         * **max_angle_diff** (*double*) – Maximum baseline angle
           difference for joining.

         * **max_horiz_iou** (*double*) – Maximum horizontal IoU for
           joining.

         * **min_prolong_fact** (*double*) – Minimum prolongation
           factor for joining.

         * **prolong_alpha** (*double*) – Weight for prolongation
           factors: alpha*bline+(1-alpha)*coords.

         * **fake_baseline** (*bool*) – Use bottom line of Coords
           rectangle as the baseline.

         * **recurse_factor** (*double*) – Multiplication factor for
           continuation criteria on each recursion.

      Returns:
         Number of join groups, elements per group in order and group
         scores.

      Return type:
         int

   getLeftRightTopBottomReadingOrder(elems, max_angle_diff=25, max_horiz_iou=0.1, min_prolong_fact=0.5, prolong_alpha=0.8, fake_baseline=False, recurse_factor=0.9)

      Gets the reading order for a set of text elems (requires single
      segment polystripe).

      Parameters:
         * **elems** (*std::vector< xmlNodePt >*) – Elements to
           process: TextLines, Words, Glyphs or TextRegions.

         * **max_angle_diff** (*double*) – Maximum baseline angle
           difference for joining.

         * **max_horiz_iou** (*double*) – Maximum horizontal IoU for
           joining.

         * **min_prolong_fact** (*double*) – Minimum prolongation
           factor for joining.

         * **prolong_alpha** (*double*) – Weight for prolongation
           factors: alpha*bline+(1-alpha)*coords.

         * **fake_baseline** (*bool*) – Use bottom line of Coords
           rectangle as the baseline.

         * **recurse_factor** (*double*) – Multiplication factor for
           continuation criteria on each recursion.

      Returns:
         Pair of reading order indices and subgroup lengths.

      Return type:
         std::pair< std::vector< int >, std::vector< int > >

   getNodeName(node, base_node=None)

      Gets the name of the given node.

      Parameters:
         * **node** (*xmlNodePt*) – XML node.

         * **base_node** (*xmlNodePt*) –

      Returns:
         String with the name.

      Return type:
         std::string

   getOGRpolygon(*args, **kwargs)

      Gets an element’s Coords as an OGRMultiPolygon.

      Parameters:
         * **node** (*const xmlNodePt*) – The element from which to
           extract the Coords points.

         * **xpath** (*const char **) – Selector for the Coords
           element.

      Returns:
         Pointer to OGRMultiPolygon element.

      Return type:
         >>OGRMultiPolygonPtr_<<

   getOGRpolygonArea(poly)

      Gets the area of a OGRMultiPolygon.

      Parameters:
         **poly** (>>OGRMultiPolygonPtr_<<) – OGRMultiPolygon pointer.

      Returns:
         Area.

      Return type:
         double

   getOGRpolygons(*args, **kwargs)

      Gets elements’ Coords as OGRMultiPolygons.

      Parameters:
         * **nodes** (*std::vector< xmlNodePt >*) – Elements from
           which to extract the Coords points.

         * **xpath** (*const char **) – Selector for the Coords
           element.

      Returns:
         Vector of OGRMultiPolygon pointer elements.

      Return type:
         std::vector< >>OGRMultiPolygonPtr_<< >

   getOGRpolyline(*args, **kwargs)

      Gets the element’s Baseline as an OGRMultiLineString.

      Parameters:
         * **node** (*const xmlNodePt*) – The element from which to
           extract the Baseline points.

         * **xpath** (*const char **) –

      Returns:
         Pointer to OGRMultiLineString element.

      Return type:
         >>OGRMultiLineStringPtr_<<

   getPageHeight(*args)

      Overloaded function with 2 signatures.

      **Signature 1**

      "unsigned int PageXML::getPageHeight(xmlNodePt node)"

      Gets the height of a page (might be different to image width due
      to the image orientation).

      Parameters:
         **node** (*xmlNodePt*) – A node to get its page height.

      Returns:
         The page height.

      Return type:
         unsigned int

      **Signature 2**

      "unsigned int PageXML::getPageHeight(int pagenum)"

      Gets the height of a page (might be different to image width due
      to the image orientation).

      Parameters:
         **pagenum** (*int*) – The page number (0-based).

      Returns:
         The page height.

      Return type:
         unsigned int

   getPageImage(*args)

      Overloaded function with 2 signatures.

      **Signature 1**

      "PageImage PageXML::getPageImage(int pagenum)"

      Returns the image for the given page.

      Parameters:
         **pagenum** (*int*) –

      Returns:
      Return type:
         PageImage

      **Signature 2**

      "PageImage PageXML::getPageImage(xmlNodePt node)"

      Parameters:
         **node** (*xmlNodePt*) –

      Returns:
      Return type:
         PageImage

   getPageImageFilename(*args)

      Overloaded function with 2 signatures.

      **Signature 1**

      "string PageXML::getPageImageFilename(xmlNodePt node)"

      Returns the imageFilename of a page.

      Parameters:
         **node** (*xmlNodePt*) –

      Returns:
      Return type:
         std::string

      **Signature 2**

      "string PageXML::getPageImageFilename(int pagenum)"

      Parameters:
         **pagenum** (*int*) –

      Returns:
      Return type:
         std::string

   getPageImageOrientation(*args)

      Overloaded function with 2 signatures.

      **Signature 1**

      "int PageXML::getPageImageOrientation(xmlNodePt node)"

      Gets the image orientation for the given node.

      Parameters:
         **node** (*xmlNodePt*) – A node to get its image orientation.

      Returns:
         Orientation in degrees.

      Return type:
         int

      **Signature 2**

      "int PageXML::getPageImageOrientation(int pagenum)"

      Gets the image orientation for the given Page number.

      Parameters:
         **pagenum** (*int*) – The page number (0-based).

      Returns:
         Orientation in degrees.

      Return type:
         int

   getPageNumber(node)

      Gets the page number for the given node.

      Parameters:
         **node** (*xmlNodePt*) –

      Returns:
      Return type:
         int

   getPageWidth(*args)

      Overloaded function with 2 signatures.

      **Signature 1**

      "unsigned int PageXML::getPageWidth(xmlNodePt node)"

      Gets the width of a page (might be different to image width due
      to the image orientation).

      Parameters:
         **node** (*xmlNodePt*) – A node to get its page width.

      Returns:
         The page width.

      Return type:
         unsigned int

      **Signature 2**

      "unsigned int PageXML::getPageWidth(int pagenum)"

      Gets the width of a page (might be different to image width due
      to the image orientation).

      Parameters:
         **pagenum** (*int*) – The page number (0-based).

      Returns:
         The page width.

      Return type:
         unsigned int

   getPagesSize(*args)

      Overloaded function with 2 signatures.

      **Signature 1**

      "std::vector< cv::Size2i > PageXML::getPagesSize(std::vector<
      xmlNodePt > pages)"

      Retrieves pages size.

      Parameters:
         **pages** (*std::vector< xmlNodePt >*) – Page nodes.

      Returns:
         Vector of page sizes.

      Return type:
         std::vector< cv::Size2i >

      **Signature 2**

      "std::vector< cv::Size2i > PageXML::getPagesSize(const char
      *xpath="//_:Page")"

      Retrieves pages size.

      Parameters:
         **xpath** (*const char **) – Selector for Page nodes.

      Returns:
         Vector of page sizes.

      Return type:
         std::vector< cv::Size2i >

   getPoints(*args)

      Overloaded function with 2 signatures.

      **Signature 1**

      "vector< cv::Point2f > PageXML::getPoints(const xmlNodePt node,
      const char *xpath="_:Coords")"

      Retrieves and parses the Coords/ for a given base node.

      Parameters:
         * **node** (*const xmlNodePt*) – Base node.

         * **xpath** (*const char **) –

      Returns:
         Reference to the points vector.

      Return type:
         std::vector< cv::Point2f >

      **Signature 2**

      "std::vector< std::vector< cv::Point2f > >
      PageXML::getPoints(const std::vector< xmlNodePt > nodes, const
      char *xpath="_:Coords")"

      Retrieves and parses the Coords/ for a given list of base nodes.

      Parameters:
         * **nodes** (*const std::vector< xmlNodePt >*) – Base
           nodes.

         * **xpath** (*const char **) –

      Returns:
         Reference to the points vector.

      Return type:
         std::vector< std::vector< cv::Point2f > >

   getPolylineLength(points)

      Gets the baseline length.

      Parameters:
         **points** (*std::vector< cv::Point2f >*) – Baseline points.

      Returns:
         The orientation angle in radians, NaN if unset.

      Return type:
         double

   getPolylineOrientation(points)

      Gets the baseline orientation angle (weighted average over
      polyline segments) in radians of a given baseline.

      Parameters:
         **points** (*std::vector< cv::Point2f >*) – Baseline points.

      Returns:
         The orientation angle in radians, NaN if unset.

      Return type:
         double

   getPropertyValue(node, key)

      Retrieves a Property value.

      Parameters:
         * **node** (*xmlNodePt*) – Node element.

         * **key** (*const char **) –

      Returns:
         String with the property value.

      Return type:
         std::string

   getReadingDirection(elem)

      Retrieves the reading direction for a given TextLine or
      TextRegion node.

      Parameters:
         **elem** (*const xmlNodePt*) – Node of the TextLine or
         TextRegion element.

      Returns:
         The reading direction, PAGEXML_READ_DIRECTION_LTR if unset.

      Return type:
         int

   getRotation(elem)

      Retrieves the rotation angle for a given TextLine or TextRegion
      node.

      Parameters:
         **elem** (*const xmlNodePt*) – Node of the TextLine or
         TextRegion element.

      Returns:
         The rotation angle in degrees, 0 if unset.

      Return type:
         double

   getTextEquiv(*args, **kwargs)

      Retrieves the concatenated TextEquivs for a given root node and
      xpath.

      Parameters:
         * **node** (*xmlNodePt*) – Root node element.

         * **xpath** (*const char **) – Relative xpath to select the
           TextEquiv elements.

         * **type** (*const char **) – Type attribute. Set to “” for
           TextEquivs without a type.

         * **separator** (*const char **) – String to add between
           TextEquivs.

      Returns:
         String with the concatenated TextEquivs.

      Return type:
         std::string

   getUnionOGRpolygon(*args, **kwargs)

      Gets the union of Coords elements as a OGRMultiPolygon.

      Parameters:
         * **nodes** (*std::vector< xmlNodePt >*) – Elements from
           which to extract the Coords points.

         * **xpath** (*const char **) – Selector for the Coords
           element.

      Returns:
         Pointer to OGRMultiPolygon element.

      Return type:
         >>OGRMultiPolygonPtr_<<

   getUniqueID(prefix, suffix=None, count_start=1, count_max=100000)

      Gets a unique id.

      Parameters:
         * **prefix** (*const char **) – Prefix for id.

         * **suffix** (*const char **) – Suffix for id.

         * **count_start** (*int*) – Counter start to place between
           prefix and suffix.

         * **count_max** (*int*) – Maximum count to test.

      Returns:
         The generated unique id.

      Return type:
         std::string

   getValue(*args)

      Overloaded function with 2 signatures.

      **Signature 1**

      "std::string PageXML::getValue(xmlNodePt node)"

      Retrieves a node value.

      Parameters:
         **node** (*xmlNodePt*) – Node element.

      Returns:
         String with the node value.

      Return type:
         std::string

      **Signature 2**

      "std::string PageXML::getValue(const char *xpath, const
      xmlNodePt node=NULL)"

      Retrieves a node value.

      Parameters:
         * **xpath** (*const char **) – Selector for the element to
           get the value.

         * **node** (*const xmlNodePt*) – XML node for context, set
           to NULL for root node.

      Returns:
         String with the node value.

      Return type:
         std::string

   getXheight(*args)

      Overloaded function with 2 signatures.

      **Signature 1**

      "float PageXML::getXheight(const xmlNodePt node)"

      Retrieves the x-height for a given TextLine node.

      Parameters:
         **node** (*const xmlNodePt*) – Node of the TextLine element.

      Returns:
         x-height>0 on success, -1 if unset.

      Return type:
         float

      **Signature 2**

      "float PageXML::getXheight(const char *id)"

      Retrieves the x-height for a given TextLine id.

      Parameters:
         **id** (*const char **) – Identifier of the TextLine.

      Returns:
         x-height>0 on success, -1 if unset.

      Return type:
         float

   getXmlFilePath()

      Returns:
      Return type:
         std::string

   insertElem(elem, node, itype)

      Inserts an element relative to a given node.

      Parameters:
         * **elem** (*xmlNodePt*) – Element to insert.

         * **node** (*const xmlNodePt*) – Reference element for
           insertion.

         * **itype** (*PAGEXML_INSERT*) – Type of insertion.

      Returns:
         Pointer to inserted element.

      Return type:
         xmlNodePt

   intersection(line1_point1, line1_point2, line2_point1, line2_point2, _ipoint)

      Finds the intersection point between two lines defined by pairs
      of points or returns false if no intersection

      Parameters:
         * **line1_point1** (*cv::Point2f*) –

         * **line1_point2** (*cv::Point2f*) –

         * **line2_point1** (*cv::Point2f*) –

         * **line2_point2** (*cv::Point2f*) –

         * **_ipoint** (*cv::Point2f &*) –

      Returns:
      Return type:
         bool

   static isBBox(points)

      Determines whether a vector of points defines a bounding box.

      Parameters:
         **points** (*const std::vector< cv::Point2f > &*) – The
         vector of points to find the limits.

      Returns:
         True if bounding box, otherwise false.

      Return type:
         bool

   isPageImageLoaded(*args)

      Overloaded function with 2 signatures.

      **Signature 1**

      "bool PageXML::isPageImageLoaded(int pagenum)"

      Checks whether a page image is loaded.

      Parameters:
         **pagenum** (*int*) –

      Returns:
      Return type:
         bool

      **Signature 2**

      "bool PageXML::isPageImageLoaded(xmlNodePt node)"

      Parameters:
         **node** (*xmlNodePt*) –

      Returns:
      Return type:
         bool

   isPolystripe(coords, baseline, height=None, offset=None)

      Checks whether Coords is a poly-stripe for its corresponding
      baseline.

      Parameters:
         * **coords** (*std::vector< cv::Point2f >*) – Coords
           points.

         * **baseline** (*std::vector< cv::Point2f >*) – Baseline
           points.

         * **height** (*double **) –

         * **offset** (*double **) – The offset of the poly-stripe
           (>=0 && <= 0.5).

      Returns:
         Pointer to created element.

      Return type:
         bool

   isValid(xml_to_validate=0)

      Validates the currently loaded XML.

      Parameters:
         **xml_to_validate** (*xmlDocPtr*) –

      Returns:
      Return type:
         bool

   loadImage(*args)

      Overloaded function with 2 signatures.

      **Signature 1**

      "void PageXML::loadImage(int pagenum, const char *fname=NULL,
      const bool resize_coords=false, int density=0)"

      Parameters:
         * **pagenum** (*int*) –

         * **fname** (*const char **) –

         * **resize_coords** (*const bool*) –

         * **density** (*int*) –

      Returns:
      Return type:
         void

      **Signature 2**

      "void PageXML::loadImage(xmlNodePt node, const char *fname=NULL,
      const bool resize_coords=false, int density=0)"

      Parameters:
         * **node** (*xmlNodePt*) –

         * **fname** (*const char **) –

         * **resize_coords** (*const bool*) –

         * **density** (*int*) –

      Returns:
      Return type:
         void

   loadImages(resize_coords=False, density=0)

      Parameters:
         * **resize_coords** (*const bool*) –

         * **density** (*const int*) –

      Returns:
      Return type:
         void

   loadSchema(schema_path)

      Loads a schema for xml validation.

      Parameters:
         **schema_path** (*const char **) – File name of the XSD file
         to read.

      Returns:
      Return type:
         void

   loadXml(*args)

      Overloaded function with 2 signatures.

      **Signature 1**

      "void PageXML::loadXml(const char *fname, bool validate=true)"

      Loads a Page XML from a file.

      Parameters:
         * **fname** (*const char **) – File name of the XML file to
           read.

         * **validate** (*bool*) –

      Returns:
      Return type:
         void

      **Signature 2**

      "void PageXML::loadXml(int fnum, bool prevfree=true, bool
      validate=true)"

      Loads a Page XML from an input stream.

      Parameters:
         * **fnum** (*int*) – File number from where to read the XML
           file.

         * **prevfree** (*bool*) – Whether to release resources
           before loading.

         * **validate** (*bool*) –

      Returns:
      Return type:
         void

   loadXmlString(xml_string, validate=True)

      Loads a Page XML from a string.

      Parameters:
         * **xml_string** (*const char **) – The XML content.

         * **validate** (*bool*) –

      Returns:
      Return type:
         void

   moveElem(elem, node, itype=0)

      Unlink an element and add it relative to a given node.

      Parameters:
         * **elem** (*xmlNodePt*) – Element to move.

         * **node** (*const xmlNodePt*) – Reference element for
           insertion.

         * **itype** (*PAGEXML_INSERT*) – Type of insertion.

      Returns:
         Pointer to moved element.

      Return type:
         xmlNodePt

   moveElems(elems, node, itype=0)

      Unlink elements and add them relative to a given node.

      Parameters:
         * **elems** (*const std::vector< xmlNodePt > &*) – Elements
           to move.

         * **node** (*const xmlNodePt*) – Reference element for
           insertion.

         * **itype** (*PAGEXML_INSERT*) – Type of insertion.

      Returns:
         Pointer to moved element.

      Return type:
         int

   multiPolygonIntersection(poly1, poly2)

      Computes the intersection of two multipolygons.

      Parameters:
         * **poly1** (>>OGRMultiPolygonPtr_<<) – First polygon.

         * **poly2** (>>OGRMultiPolygonPtr_<<) – Second polygon.

      Returns:
         Intersection geometry.

      Return type:
         >>OGRMultiPolygonPtr_<<

   multiPolylineIntersection(poly1, poly2)

      Computes the intersection between a multipolylines and a
      multipolygon.

      Parameters:
         * **poly1** (>>OGRMultiLineStringPtr_<<) – Polyline.

         * **poly2** (>>OGRMultiPolygonPtr_<<) – Polygon.

      Returns:
         Intersection geometry.

      Return type:
         >>OGRMultiLineStringPtr_<<

   newXml(creator, image, imgW=0, imgH=0, pagens=None)

      Creates a new Page XML.

      Parameters:
         * **creator** (*const char **) – Info about tool creating
           the XML.

         * **image** (*const char **) – Path to the image file.

         * **imgW** (*const int*) – Width of image.

         * **imgH** (*const int*) – Height of image.

         * **pagens** (*const char **) –

      Returns:
      Return type:
         xmlNodePt

   static nodeIs(node, name)

      Checks if node is of given name.

      Parameters:
         * **node** (*xmlNodePt*) – XML node.

         * **name** (*const char **) – String with name to match
           against.

      Returns:
         True if name matches, otherwise false.

      Return type:
         bool

   parent(node)

      Returns the parent of a node.

      Parameters:
         **node** (*const xmlNodePt*) – XML node.

      Returns:
         Parent node.

      Return type:
         xmlNodePt

   static pointsBBox(points)

      Generates a vector of 4 points that define the bounding box for
      a given vector of points.

      Parameters:
         **points** (*std::vector< cv::Point2f >*) – The vector of
         points to find the limits.

      Returns:
         The 4 points defining the bounding box (top-left clockwise).

      Return type:
         std::vector< cv::Point2f >

   static pointsLimits(points, xmin, xmax, ymin, ymax)

      Gets the minimum and maximum coordinate values for an array of
      points.

      Parameters:
         * **points** (*std::vector< cv::Point2f > &*) – The vector
           of points to find the limits.

         * **xmin** (*double &*) – Minimum x value.

         * **xmax** (*double &*) – Maximum x value.

         * **ymin** (*double &*) – Minimum y value.

         * **ymax** (*double &*) – Maximum y value.

      Returns:
      Return type:
         void

   pointsToOGRpolygon(points)

      Converts Coords to an OGRMultiPolygon.

      Parameters:
         **points** (*std::vector< cv::Point2f >*) – Vector of x,y
         points.

      Returns:
         Pointer to OGRMultiPolygon element.

      Return type:
         >>OGRMultiPolygonPtr_<<

   pointsToOGRpolygons(points)

      Converts Coords to OGRMultiPolygons.

      Parameters:
         **points** (*std::vector< std::vector< cv::Point2f > >*) –
         Vectors of x,y points.

      Returns:
         Pointer to OGRMultiPolygon element.

      Return type:
         std::vector< >>OGRMultiPolygonPtr_<< >

   static pointsToString(*args)

      Overloaded function with 2 signatures.

      **Signature 1**

      "static std::string PageXML::pointsToString(std::vector<
      cv::Point2f > points, bool rounded=false)"

      Parameters:
         * **points** (*std::vector< cv::Point2f >*) –

         * **rounded** (*bool*) –

      Returns:
      Return type:
         std::string

      **Signature 2**

      "static std::string PageXML::pointsToString(std::vector<
      cv::Point > points)"

      Parameters:
         **points** (*std::vector< cv::Point >*) –

      Returns:
      Return type:
         std::string

   static printVersions(*args, **kwargs)

      Parameters:
         **file** (*FILE **) –

      Returns:
      Return type:
         void

   processEnd()

      Ends the running process in the Page XML.

      Returns:
      Return type:
         void

   processStart(tool, ref=None)

      Starts a process in the Page XML.

      Parameters:
         * **tool** (*const char **) –

         * **ref** (*const char **) –

      Returns:
      Return type:
         void

   relabelChildIDs(node, include_self=False)

      Relabels IDs of child elements.

      Parameters:
         * **node** (*xmlNodePt*) – Base node.

         * **include_self** (*bool*) – Whether to also relabel the
           base node.

      Returns:
         Number of IDs affected.

      Return type:
         int

   relativizeImageFilename(xml_path)

      Modifies imageFilename to be a relative path w.r.t. given xml
      path. Currently just checks prefix directories and removes it.

      Parameters:
         **xml_path** (*const char **) –

      Returns:
      Return type:
         void

   releaseImage(*args)

      Overloaded function with 2 signatures.

      **Signature 1**

      "void PageXML::releaseImage(int pagenum)"

      Releases an already loaded image.

      Parameters:
         **pagenum** (*int*) – The number of the page for which to
         release the image.

      Returns:
      Return type:
         void

      **Signature 2**

      "void PageXML::releaseImage(xmlNodePt node)"

      Parameters:
         **node** (*xmlNodePt*) –

      Returns:
      Return type:
         void

   releaseImages()

      Returns:
      Return type:
         void

   resize(*args)

      Overloaded function with 4 signatures.

      **Signature 1**

      "int PageXML::resize(std::vector< cv::Size2i > sizes,
      std::vector< xmlNodePt > pages, bool check_aspect_ratio=true)"

      Resizes pages and all respective coordinates.

      Parameters:
         * **sizes** (*std::vector< cv::Size2i >*) – Page sizes to
           resize to.

         * **pages** (*std::vector< xmlNodePt >*) – Page nodes.

         * **check_aspect_ratio** (*bool*) – Whether to check that
           the aspect ratio is properly preserved.

      Returns:
         Number of pages+points attributes modified.

      Return type:
         int

      **Signature 2**

      "int PageXML::resize(std::vector< cv::Size2i > sizes, const char
      *xpath="//_:Page", bool check_aspect_ratio=true)"

      Resizes pages and all respective coordinates.

      Parameters:
         * **sizes** (*std::vector< cv::Size2i >*) – Page sizes to
           resize to.

         * **xpath** (*const char **) – Selector for Page nodes.

         * **check_aspect_ratio** (*bool*) – Whether to check that
           the aspect ratio is properly preserved.

      Returns:
         Number of pages+points attributes modified.

      Return type:
         int

      **Signature 3**

      "int PageXML::resize(cv::Size2i size, xmlNodePt page, bool
      check_aspect_ratio=true)"

      Resizes a page and all respective coordinates.

      Parameters:
         * **size** (*cv::Size2i*) – Page size to resize to.

         * **page** (*xmlNodePt*) – Page node.

         * **check_aspect_ratio** (*bool*) – Whether to check that
           the aspect ratio is properly preserved.

      Returns:
         Number of pages+points attributes modified.

      Return type:
         int

      **Signature 4**

      "int PageXML::resize(double fact, const char *xpath="//_:Page")"

      Resizes a page and all respective coordinates.

      Parameters:
         * **fact** (*double*) –

         * **xpath** (*const char **) – Selector for Page nodes.

      Returns:
         Number of pages+points attributes modified.

      Return type:
         int

   rmElem(node)

      Removes the given element.

      Parameters:
         **node** (*const xmlNodePt*) – Element.

      Returns:
      Return type:
         void

   rmElems(*args)

      Overloaded function with 3 signatures.

      **Signature 1**

      "int PageXML::rmElems(const std::vector< xmlNodePt > &nodes)"

      Parameters:
         **nodes** (*const std::vector< xmlNodePt > &*) –

      Returns:
      Return type:
         int

      **Signature 2**

      "int PageXML::rmElems(const char *xpath, xmlNodePt node=NULL)"

      Remove the elements that match a given xpath.

      Parameters:
         * **xpath** (*const char **) – Selector for elements to
           remove.

         * **node** (*xmlNodePt*) – Base node for element selection.

      Returns:
         Number of elements removed.

      Return type:
         int

      **Signature 3**

      "int PageXML::rmElems(const std::string xpath, xmlNodePt
      node=NULL)"

      Parameters:
         * **xpath** (*const std::string*) –

         * **node** (*xmlNodePt*) –

      Returns:
      Return type:
         int

   rotatePage(*args)

      Overloaded function with 2 signatures.

      **Signature 1**

      "int PageXML::rotatePage(int angle, xmlNodePt page, bool
      update_image_orientation, const double conf)"

      Rotates a page.

      Parameters:
         * **angle** (*int*) – Angle to rotate in degrees
           {0,90,180,-90}.

         * **page** (*xmlNodePt*) – The Page node.

         * **update_image_orientation** (*bool*) – Whether to update
           the ImageOrientation element.

         * **conf** (*const double*) – Confidence value.

      Returns:
         Number of elements modified.

      Return type:
         int

      **Signature 2**

      "int PageXML::rotatePage(int angle, xmlNodePt page, bool
      update_image_orientation=true, const double *_conf=NULL)"

      Rotates a page.

      Parameters:
         * **angle** (*int*) – Angle to rotate in degrees
           {0,90,180,-90}.

         * **page** (*xmlNodePt*) – The Page node.

         * **update_image_orientation** (*bool*) – Whether to check
           that the aspect ratio is properly preserved.

         * **_conf** (*const double **) – Pointer to confidence
           value, NULL for no confidence.

      Returns:
         Number of elements modified.

      Return type:
         int

   select(*args)

      Overloaded function with 3 signatures.

      **Signature 1**

      "vector< xmlNodePt > PageXML::select(const char *xpath, const
      xmlNodePt node=NULL)"

      Selects nodes given an xpath.

      Parameters:
         * **xpath** (*const char **) – Selector expression.

         * **node** (*const xmlNodePt*) – XML node for context, set
           to NULL for root node.

      Returns:
         Vector of matched nodes.

      Return type:
         std::vector< xmlNodePt >

      **Signature 2**

      "std::vector<xmlNodePt> PageXML::select(std::string xpath, const
      xmlNodePt node=NULL)"

      Parameters:
         * **xpath** (*std::string*) –

         * **node** (*const xmlNodePt*) –

      Returns:
      Return type:
         std::vector< xmlNodePt >

      **Signature 3**

      "std::vector<xmlNodePt> PageXML::select(const char *xpath, const
      std::vector< xmlNodePt > nodes, bool unique=true)"

      Parameters:
         * **xpath** (*const char **) –

         * **nodes** (*const std::vector< xmlNodePt >*) –

         * **unique** (*bool*) –

      Returns:
      Return type:
         std::vector< xmlNodePt >

   selectByID(id, node=None)

      Selects an element with a given ID.

      Parameters:
         * **id** (*const char **) – ID of element to select.

         * **node** (*const xmlNodePt*) – XML node for context, set
           to NULL for root node.

      Returns:
         Matched node.

      Return type:
         xmlNodePt

   selectByOverlap(*args)

      Overloaded function with 2 signatures.

      **Signature 1**

      "std::vector< xmlNodePt > PageXML::selectByOverlap(std::vector<
      cv::Point2f > points, xmlNodePt page, const char
      *xpath=".//_:TextLine", double overlap_thr=0.1, PAGEXML_OVERLAP
      overlap_type=PAGEXML_OVERLAP_COORDS_IWA)"

      Selects elements based on overlap to a polygon.

      Parameters:
         * **points** (*std::vector< cv::Point2f >*) – Polygon for
           selection.

         * **page** (*xmlNodePt*) – Page element for selection.

         * **xpath** (*const char **) – xpath for candidate elements
           for selection.

         * **overlap_thr** (*double*) – Overlapping score threshold.

         * **overlap_type** (*PAGEXML_OVERLAP*) – Type of overlap to
           use for selecting.

      Returns:
         Number of TextLines copied.

      Return type:
         std::vector< xmlNodePt >

      **Signature 2**

      "std::vector< xmlNodePt > PageXML::selectByOverlap(std::vector<
      cv::Point2f > points, int pagenum, const char
      *xpath=".//_:TextLine", double overlap_thr=0.1, PAGEXML_OVERLAP
      overlap_type=PAGEXML_OVERLAP_COORDS_IWA)"

      Selects elements based on overlap to a polygon.

      Parameters:
         * **points** (*std::vector< cv::Point2f >*) – Polygon for
           selection.

         * **pagenum** (*int*) – Page number for selection.

         * **xpath** (*const char **) – xpath for candidate elements
           for selection.

         * **overlap_thr** (*double*) – Overlapping score threshold.

         * **overlap_type** (*PAGEXML_OVERLAP*) – Type of overlap to
           use for selecting.

      Returns:
         Number of TextLines copied.

      Return type:
         std::vector< xmlNodePt >

   selectNth(*args)

      Overloaded function with 2 signatures.

      **Signature 1**

      "xmlNodePt PageXML::selectNth(const char *xpath, int num=0,
      const xmlNodePt node=NULL)"

      Selects the n-th node that matches an xpath.

      Parameters:
         * **xpath** (*const char **) – Selector expression.

         * **num** (*int*) – Element number (0-indexed), negative
           from last.

         * **node** (*const xmlNodePt*) – XML node for context, set
           to NULL for root node.

      Returns:
         Matched node.

      Return type:
         xmlNodePt

      **Signature 2**

      "xmlNodePt PageXML::selectNth(std::string xpath, int num=0,
      const xmlNodePt node=NULL)"

      Parameters:
         * **xpath** (*std::string*) –

         * **num** (*int*) –

         * **node** (*const xmlNodePt*) –

      Returns:
      Return type:
         xmlNodePt

   setAttr(*args)

      Overloaded function with 4 signatures.

      **Signature 1**

      "int PageXML::setAttr(std::vector< xmlNodePt > nodes, const char
      *name, const char *value)"

      Parameters:
         * **nodes** (*std::vector< xmlNodePt >*) –

         * **name** (*const char **) –

         * **value** (*const char **) –

      Returns:
      Return type:
         int

      **Signature 2**

      "int PageXML::setAttr(const xmlNodePt node, const char *name,
      const char *value)"

      Adds or modifies (if already exists) an attribute for a given
      node.

      Parameters:
         * **node** (*const xmlNodePt*) – Node to set the attribute.

         * **name** (*const char **) – Attribute name.

         * **value** (*const char **) – Attribute value.

      Returns:
         Number of elements modified.

      Return type:
         int

      **Signature 3**

      "int PageXML::setAttr(const char *xpath, const char *name, const
      char *value)"

      Adds or modifies (if already exists) an attribute for a given
      xpath.

      Parameters:
         * **xpath** (*const char **) – Selector for the element(s)
           to set the attribute.

         * **name** (*const char **) – Attribute name.

         * **value** (*const char **) – Attribute value.

      Returns:
         Number of elements modified.

      Return type:
         int

      **Signature 4**

      "int PageXML::setAttr(const std::string xpath, const std::string
      name, const std::string value)"

      Parameters:
         * **xpath** (*const std::string*) –

         * **name** (*const std::string*) –

         * **value** (*const std::string*) –

      Returns:
      Return type:
         int

   setBaseline(*args)

      Overloaded function with 6 signatures.

      **Signature 1**

      "xmlNodePt PageXML::setBaseline(xmlNodePt node, const
      std::vector< cv::Point2f > &points, const double *_conf=NULL)"

      Parameters:
         * **node** (*xmlNodePt*) –

         * **points** (*const std::vector< cv::Point2f > &*) –

         * **_conf** (*const double **) –

      Returns:
      Return type:
         xmlNodePt

      **Signature 2**

      "xmlNodePt PageXML::setBaseline(xmlNodePt node, const
      std::vector< cv::Point2f > &points, const double conf)"

      Parameters:
         * **node** (*xmlNodePt*) –

         * **points** (*const std::vector< cv::Point2f > &*) –

         * **conf** (*const double*) –

      Returns:
      Return type:
         xmlNodePt

      **Signature 3**

      "xmlNodePt PageXML::setBaseline(const char *xpath, const
      std::vector< cv::Point2f > &points, const double *_conf=NULL)"

      Parameters:
         * **xpath** (*const char **) –

         * **points** (*const std::vector< cv::Point2f > &*) –

         * **_conf** (*const double **) –

      Returns:
      Return type:
         xmlNodePt

      **Signature 4**

      "xmlNodePt PageXML::setBaseline(const char *xpath, const
      std::vector< cv::Point2f > &points, const double conf)"

      Parameters:
         * **xpath** (*const char **) –

         * **points** (*const std::vector< cv::Point2f > &*) –

         * **conf** (*const double*) –

      Returns:
      Return type:
         xmlNodePt

      **Signature 5**

      "xmlNodePt PageXML::setBaseline(xmlNodePt node, double x1,
      double y1, double x2, double y2, const double *_conf=NULL)"

      Adds or modifies (if already exists) a two point Baseline for a
      given node.

      Parameters:
         * **node** (*xmlNodePt*) – The node of element to set the
           Baseline.

         * **x1** (*double*) – x value of first point.

         * **y1** (*double*) – y value of first point.

         * **x2** (*double*) – x value of second point.

         * **y2** (*double*) – y value of second point.

         * **_conf** (*const double **) – Pointer to confidence
           value, NULL for no confidence.

      Returns:
         Pointer to created element.

      Return type:
         xmlNodePt

      **Signature 6**

      "xmlNodePt PageXML::setBaseline(xmlNodePt node, double x1,
      double y1, double x2, double y2, const double conf)"

      Adds or modifies (if already exists) a two point Baseline for a
      given node.

      Parameters:
         * **node** (*xmlNodePt*) – The node of element to set the
           Baseline.

         * **x1** (*double*) – x value of first point.

         * **y1** (*double*) – y value of first point.

         * **x2** (*double*) – x value of second point.

         * **y2** (*double*) – y value of second point.

         * **conf** (*const double*) – Confidence value.

      Returns:
         Pointer to created element.

      Return type:
         xmlNodePt

   setCoords(*args)

      Overloaded function with 6 signatures.

      **Signature 1**

      "xmlNodePt PageXML::setCoords(xmlNodePt node, const std::vector<
      cv::Point2f > &points, const double *_conf=NULL)"

      Parameters:
         * **node** (*xmlNodePt*) –

         * **points** (*const std::vector< cv::Point2f > &*) –

         * **_conf** (*const double **) –

      Returns:
      Return type:
         xmlNodePt

      **Signature 2**

      "xmlNodePt PageXML::setCoords(xmlNodePt node, const std::vector<
      cv::Point2f > &points, const double conf)"

      Parameters:
         * **node** (*xmlNodePt*) –

         * **points** (*const std::vector< cv::Point2f > &*) –

         * **conf** (*const double*) –

      Returns:
      Return type:
         xmlNodePt

      **Signature 3**

      "xmlNodePt PageXML::setCoords(xmlNodePt node, const std::vector<
      cv::Point > &points, const double *_conf=NULL)"

      Parameters:
         * **node** (*xmlNodePt*) –

         * **points** (*const std::vector< cv::Point > &*) –

         * **_conf** (*const double **) –

      Returns:
      Return type:
         xmlNodePt

      **Signature 4**

      "xmlNodePt PageXML::setCoords(xmlNodePt node, const std::vector<
      cv::Point > &points, const double conf)"

      Parameters:
         * **node** (*xmlNodePt*) –

         * **points** (*const std::vector< cv::Point > &*) –

         * **conf** (*const double*) –

      Returns:
      Return type:
         xmlNodePt

      **Signature 5**

      "xmlNodePt PageXML::setCoords(const char *xpath, const
      std::vector< cv::Point2f > &points, const double *_conf=NULL)"

      Parameters:
         * **xpath** (*const char **) –

         * **points** (*const std::vector< cv::Point2f > &*) –

         * **_conf** (*const double **) –

      Returns:
      Return type:
         xmlNodePt

      **Signature 6**

      "xmlNodePt PageXML::setCoords(const char *xpath, const
      std::vector< cv::Point2f > &points, const double conf)"

      Parameters:
         * **xpath** (*const char **) –

         * **points** (*const std::vector< cv::Point2f > &*) –

         * **conf** (*const double*) –

      Returns:
      Return type:
         xmlNodePt

   setCoordsBBox(*args)

      Overloaded function with 2 signatures.

      **Signature 1**

      "xmlNodePt PageXML::setCoordsBBox(xmlNodePt node, double xmin,
      double ymin, double width, double height, const double
      *_conf=NULL, bool subone=true)"

      Adds or modifies (if already exists) the Coords as a bounding
      box for a given node.

      Parameters:
         * **node** (*xmlNodePt*) – The node of element to set the
           Coords.

         * **xmin** (*double*) – Minimum x value of bounding box.

         * **ymin** (*double*) – Minimum y value of bounding box.

         * **width** (*double*) – Width of bounding box.

         * **height** (*double*) – Height of bounding box.

         * **_conf** (*const double **) – Pointer to confidence
           value, NULL for no confidence.

         * **subone** (*bool*) – Whether to subtract 1 when
           computing xmax and ymax (discrete compatibility).

      Returns:
         Pointer to created element.

      Return type:
         xmlNodePt

      **Signature 2**

      "xmlNodePt PageXML::setCoordsBBox(xmlNodePt node, double xmin,
      double ymin, double width, double height, const double conf,
      bool subone=true)"

      Adds or modifies (if already exists) the Coords as a bounding
      box for a given node.

      Parameters:
         * **node** (*xmlNodePt*) – The node of element to set the
           Coords.

         * **xmin** (*double*) – Minimum x value of bounding box.

         * **ymin** (*double*) – Minimum y value of bounding box.

         * **width** (*double*) – Width of bounding box.

         * **height** (*double*) – Height of bounding box.

         * **conf** (*const double*) – Confidence value.

         * **subone** (*bool*) – Whether to subtract 1 when
           computing xmax and ymax (discrete compatibility).

      Returns:
         Pointer to created element.

      Return type:
         xmlNodePt

   setImagesBaseDir(imgBaseDir)

      Parameters:
         **imgBaseDir** (*std::string*) –

      Returns:
      Return type:
         void

   setPageHeight(node, height)

      Sets the height of a page (actually sets imageHeight accounting
      for image orientation).

      Parameters:
         * **node** (*xmlNodePt*) – A node to set its page height.

         * **height** (*int*) – The height to set.

      Returns:
      Return type:
         void

   setPageImageFilename(*args)

      Overloaded function with 2 signatures.

      **Signature 1**

      "void PageXML::setPageImageFilename(xmlNodePt node, const char
      *image)"

      Sets the imageFilename of a page.

      Parameters:
         * **node** (*xmlNodePt*) –

         * **image** (*const char **) –

      Returns:
      Return type:
         void

      **Signature 2**

      "void PageXML::setPageImageFilename(int pagenum, const char
      *image)"

      Parameters:
         * **pagenum** (*int*) –

         * **image** (*const char **) –

      Returns:
      Return type:
         void

   setPageImageOrientation(*args)

      Overloaded function with 4 signatures.

      **Signature 1**

      "void PageXML::setPageImageOrientation(xmlNodePt node, int
      angle, const double *_conf=NULL)"

      Sets the image orientation for the given Page node.

      Parameters:
         * **node** (*xmlNodePt*) – The page node.

         * **angle** (*int*) – The orientation angle in degrees
           {0,90,180,-90}.

         * **_conf** (*const double **) – Pointer to confidence
           value, NULL for no confidence.

      Returns:
      Return type:
         void

      **Signature 2**

      "void PageXML::setPageImageOrientation(xmlNodePt node, int
      angle, const double conf)"

      Sets the image orientation for the given Page node.

      Parameters:
         * **node** (*xmlNodePt*) – The page node.

         * **angle** (*int*) – The orientation angle in degrees
           {0,90,180,-90}.

         * **conf** (*const double*) – Confidence value.

      Returns:
      Return type:
         void

      **Signature 3**

      "void PageXML::setPageImageOrientation(int pagenum, int angle,
      const double *_conf=NULL)"

      Sets the image orientation for the given Page number.

      Parameters:
         * **pagenum** (*int*) – The page number (0-based).

         * **angle** (*int*) – The orientation angle in degrees
           {0,90,180,-90}.

         * **_conf** (*const double **) – Pointer to confidence
           value, NULL for no confidence.

      Returns:
      Return type:
         void

      **Signature 4**

      "void PageXML::setPageImageOrientation(int pagenum, int angle,
      const double conf)"

      Sets the image orientation for the given Page number.

      Parameters:
         * **pagenum** (*int*) – The page number (0-based).

         * **angle** (*int*) – The orientation angle in degrees
           {0,90,180,-90}.

         * **conf** (*const double*) – Confidence value.

      Returns:
      Return type:
         void

   setPageWidth(node, width)

      Sets the width of a page (actually sets imageWidth accounting
      for image orientation).

      Parameters:
         * **node** (*xmlNodePt*) – A node to set its page width.

         * **width** (*int*) – The width to set.

      Returns:
      Return type:
         void

   setPolystripe(node, height, offset=0.25, offset_check=True)

      Sets the Coords of a TextLine as a poly-stripe of the baseline.

      Parameters:
         * **node** (*xmlNodePt*) – The node of element to set the
           Coords.

         * **height** (*double*) – The height of the poly-stripe in
           pixels (>0).

         * **offset** (*double*) – The offset of the poly-stripe
           (>=0 && <= 0.5).

         * **offset_check** (*bool*) –

      Returns:
         Pointer to created element.

      Return type:
         xmlNodePt

   setProperty(*args)

      Overloaded function with 4 signatures.

      **Signature 1**

      "xmlNodePt PageXML::setProperty(xmlNodePt node, const char *key,
      const char *val=NULL, const double *_conf=NULL)"

      Sets a Property to a given node.

      Parameters:
         * **node** (*xmlNodePt*) – The node of element to set the
           Property.

         * **key** (*const char **) – The key for the Property.

         * **val** (*const char **) – The optional value for the
           Property.

         * **_conf** (*const double **) – Pointer to confidence
           value, NULL for no confidence.

      Returns:
         Pointer to created element.

      Return type:
         xmlNodePt

      **Signature 2**

      "xmlNodePt PageXML::setProperty(xmlNodePt node, const char *key,
      const char *val, const double conf)"

      Sets a Property to a given node.

      Parameters:
         * **node** (*xmlNodePt*) – The node of element to set the
           Property.

         * **key** (*const char **) – The key for the Property.

         * **val** (*const char **) – The optional value for the
           Property.

         * **conf** (*const double*) – Confidence value.

      Returns:
         Pointer to created element.

      Return type:
         xmlNodePt

      **Signature 3**

      "xmlNodePt PageXML::setProperty(xmlNodePt node, const char *key,
      const double val, const double *_conf=NULL)"

      Sets a Property to a given node.

      Parameters:
         * **node** (*xmlNodePt*) – The node of element to set the
           Property.

         * **key** (*const char **) – The key for the Property.

         * **val** (*const double*) – Numeric value for the
           Property.

         * **_conf** (*const double **) – Pointer to confidence
           value, NULL for no confidence.

      Returns:
         Pointer to created element.

      Return type:
         xmlNodePt

      **Signature 4**

      "xmlNodePt PageXML::setProperty(xmlNodePt node, const char *key,
      const double val, const double conf)"

      Sets a Property to a given node.

      Parameters:
         * **node** (*xmlNodePt*) – The node of element to set the
           Property.

         * **key** (*const char **) – The key for the Property.

         * **val** (*const double*) – The optional value for the
           Property.

         * **conf** (*const double*) – Confidence value.

      Returns:
         Pointer to created element.

      Return type:
         xmlNodePt

   setReadingDirection(elem, direction)

      Sets the reading direction to a TextRegion node.

      Parameters:
         * **elem** (*const xmlNodePt*) –

         * **direction** (*PAGEXML_READ_DIRECTION*) – Direction to
           set.

      Returns:
      Return type:
         void

   setRotation(elem, rotation)

      Sets the rotation angle to a TextRegion node.

      Parameters:
         * **elem** (*const xmlNodePt*) –

         * **rotation** (*const float*) – Rotation angle to set.

      Returns:
      Return type:
         void

   setTextEquiv(*args)

      Overloaded function with 4 signatures.

      **Signature 1**

      "xmlNodePt PageXML::setTextEquiv(xmlNodePt node, const char
      *text, const double *_conf=NULL, const char *type=NULL)"

      Adds or modifies (if already exists) the TextEquiv for a given
      node.

      Parameters:
         * **node** (*xmlNodePt*) – The node of element to set the
           TextEquiv.

         * **text** (*const char **) – The text string.

         * **_conf** (*const double **) – Pointer to confidence
           value, NULL for no confidence.

         * **type** (*const char **) – Type attribute.

      Returns:
         Pointer to created element.

      Return type:
         xmlNodePt

      **Signature 2**

      "xmlNodePt PageXML::setTextEquiv(xmlNodePt node, const char
      *text, const double conf, const char *type=NULL)"

      Adds or modifies (if already exists) the TextEquiv for a given
      node.

      Parameters:
         * **node** (*xmlNodePt*) – The node of element to set the
           TextEquiv.

         * **text** (*const char **) – The text string.

         * **conf** (*const double*) – Confidence value.

         * **type** (*const char **) – Type attribute.

      Returns:
         Pointer to created element.

      Return type:
         xmlNodePt

      **Signature 3**

      "xmlNodePt PageXML::setTextEquiv(const char *xpath, const char
      *text, const double *_conf=NULL, const char *type=NULL)"

      Adds or modifies (if already exists) the TextEquiv for a given
      xpath.

      Parameters:
         * **xpath** (*const char **) – Selector for element to set
           the TextEquiv.

         * **text** (*const char **) – The text string.

         * **_conf** (*const double **) – Pointer to confidence
           value, NULL for no confidence.

         * **type** (*const char **) – Type attribute.

      Returns:
         Pointer to created element.

      Return type:
         xmlNodePt

      **Signature 4**

      "xmlNodePt PageXML::setTextEquiv(const char *xpath, const char
      *text, const double conf, const char *type=NULL)"

      Adds or modifies (if already exists) the TextEquiv for a given
      xpath.

      Parameters:
         * **xpath** (*const char **) – Selector for element to set
           the TextEquiv.

         * **text** (*const char **) – The text string.

         * **conf** (*const double*) – Confidence value.

         * **type** (*const char **) –

      Returns:
         Pointer to created element.

      Return type:
         xmlNodePt

   static setValidationEnabled(val)

      Enables/disables schema validation.

      Parameters:
         **val** (*bool*) –

      Returns:
      Return type:
         void

   setValue(node, value)

      Sets a node value.

      Parameters:
         * **node** (*xmlNodePt*) – Node element.

         * **value** (*const char **) –

      Returns:
         String with the node value.

      Return type:
         void

   setXmlFilePath(xmlFilePath)

      Parameters:
         **xmlFilePath** (*std::string*) –

      Returns:
      Return type:
         void

   simplifyIDs()

      Simplifies IDs by removing imgbase prefixes and replaces invalid
      characters with _.

      Returns:
         Number of IDs simplified.

      Return type:
         int

   static stringToPoints(*args)

      Overloaded function with 2 signatures.

      **Signature 1**

      "vector< cv::Point2f > PageXML::stringToPoints(const char
      *spoints)"

      Parses a string of pairs of coordinates (x1,y1 [x2,y2 …]) into
      an array.

      Parameters:
         **spoints** (*const char **) – String containing coordinate
         pairs.

      Returns:
         Array of (x,y) coordinates.

      Return type:
         std::vector< cv::Point2f >

      **Signature 2**

      "static std::vector<cv::Point2f>
      PageXML::stringToPoints(std::string spoints)"

      Parameters:
         **spoints** (*std::string*) –

      Returns:
      Return type:
         std::vector< cv::Point2f >

   thisown

      The membership flag

   toString(indent=False, validate=True)

      Creates a string representation of the Page XML.

      Parameters:
         * **indent** (*bool*) – Whether to indent the XML.

         * **validate** (*bool*) – Whether the Page XML should be
           validated before writing.

      Returns:
         The Page XML string.

      Return type:
         std::string

   updateLastChange()

      Updates the last change time stamp.

      Returns:
      Return type:
         void

   static version()

      Returns the class version.

      Returns:
      Return type:
         char *

   write(*args, **kwargs)

      Writes the current state of the XML to a file using utf-8
      encoding.

      Parameters:
         * **fname** (*const char **) – File name of where the XML
           file will be written.

         * **indent** (*bool*) – Whether to indent the XML.

         * **validate** (*bool*) – Whether the Page XML should be
           validated before writing.

      Returns:
         Number of bytes written.

      Return type:
         int

pagexml.PageXML_isBBox(points)

   Determines whether a vector of points defines a bounding box.

   Parameters:
      **points** (*const std::vector< cv::Point2f > &*) – The vector
      of points to find the limits.

   Returns:
      True if bounding box, otherwise false.

   Return type:
      bool

pagexml.PageXML_nodeIs(node, name)

   Checks if node is of given name.

   Parameters:
      * **node** (*xmlNodePt*) – XML node.

      * **name** (*const char **) – String with name to match
        against.

   Returns:
      True if name matches, otherwise false.

   Return type:
      bool

pagexml.PageXML_pointsBBox(points)

   Generates a vector of 4 points that define the bounding box for a
   given vector of points.

   Parameters:
      **points** (*std::vector< cv::Point2f >*) – The vector of points
      to find the limits.

   Returns:
      The 4 points defining the bounding box (top-left clockwise).

   Return type:
      std::vector< cv::Point2f >

pagexml.PageXML_pointsLimits(points, xmin, xmax, ymin, ymax)

   Gets the minimum and maximum coordinate values for an array of
   points.

   Parameters:
      * **points** (*std::vector< cv::Point2f > &*) – The vector of
        points to find the limits.

      * **xmin** (*double &*) – Minimum x value.

      * **xmax** (*double &*) – Maximum x value.

      * **ymin** (*double &*) – Minimum y value.

      * **ymax** (*double &*) – Maximum y value.

   Returns:
   Return type:
      void

pagexml.PageXML_pointsToString(*args)

   Overloaded function with 2 signatures.

   **Signature 1**

   "static std::string PageXML::pointsToString(std::vector<
   cv::Point2f > points, bool rounded=false)"

   Parameters:
      * **points** (*std::vector< cv::Point2f >*) –

      * **rounded** (*bool*) –

   Returns:
   Return type:
      std::string

   **Signature 2**

   "static std::string PageXML::pointsToString(std::vector< cv::Point
   > points)"

   Parameters:
      **points** (*std::vector< cv::Point >*) –

   Returns:
   Return type:
      std::string

pagexml.PageXML_printVersions(*args, **kwargs)

   Parameters:
      **file** (*FILE **) –

   Returns:
   Return type:
      void

pagexml.PageXML_setValidationEnabled(val)

   Enables/disables schema validation.

   Parameters:
      **val** (*bool*) –

   Returns:
   Return type:
      void

pagexml.PageXML_stringToPoints(*args)

   Overloaded function with 2 signatures.

   **Signature 1**

   "vector< cv::Point2f > PageXML::stringToPoints(const char
   *spoints)"

   Parses a string of pairs of coordinates (x1,y1 [x2,y2 …]) into an
   array.

   Parameters:
      **spoints** (*const char **) – String containing coordinate
      pairs.

   Returns:
      Array of (x,y) coordinates.

   Return type:
      std::vector< cv::Point2f >

   **Signature 2**

   "static std::vector<cv::Point2f>
   PageXML::stringToPoints(std::string spoints)"

   Parameters:
      **spoints** (*std::string*) –

   Returns:
   Return type:
      std::vector< cv::Point2f >

pagexml.PageXML_version()

   Returns the class version.

   Returns:
   Return type:
      char *

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
