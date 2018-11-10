pagexml API (version 2018.11.10)
********************************


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

   Proxy of C++ cv::DataType<(bool)> class.

   channels = 1

   fmt = 'u'

   generic_type = 0

   thisown

      The membership flag

class pagexml.DataType_char

   Bases: "object"

   Proxy of C++ cv::DataType<(char)> class.

   channels = 1

   fmt = 'c'

   generic_type = 0

   thisown

      The membership flag

class pagexml.DataType_double

   Bases: "object"

   Proxy of C++ cv::DataType<(double)> class.

   channels = 1

   fmt = 'd'

   generic_type = 0

   thisown

      The membership flag

class pagexml.DataType_float

   Bases: "object"

   Proxy of C++ cv::DataType<(float)> class.

   channels = 1

   fmt = 'f'

   generic_type = 0

   thisown

      The membership flag

class pagexml.DataType_int

   Bases: "object"

   Proxy of C++ cv::DataType<(int)> class.

   channels = 1

   fmt = 'i'

   generic_type = 0

   thisown

      The membership flag

class pagexml.DataType_schar

   Bases: "object"

   Proxy of C++ cv::DataType<(schar)> class.

   channels = 1

   fmt = 'c'

   generic_type = 0

   thisown

      The membership flag

class pagexml.DataType_short

   Bases: "object"

   Proxy of C++ cv::DataType<(short)> class.

   channels = 1

   fmt = 's'

   generic_type = 0

   thisown

      The membership flag

class pagexml.DataType_uchar

   Bases: "object"

   Proxy of C++ cv::DataType<(uchar)> class.

   channels = 1

   fmt = 'u'

   generic_type = 0

   thisown

      The membership flag

class pagexml.DataType_ushort

   Bases: "object"

   Proxy of C++ cv::DataType<(ushort)> class.

   channels = 1

   fmt = 'w'

   generic_type = 0

   thisown

      The membership flag

class pagexml.Mat(*args)

   Bases: "object"

   Proxy of C++ cv::Mat class.

   AUTO_STEP = 0

   CONTINUOUS_FLAG = 16384

   DEPTH_MASK = 7

   MAGIC_MASK = -65536

   MAGIC_VAL = 1124007936

   SUBMATRIX_FLAG = 32768

   TYPE_MASK = 4095

   addref(self)

      self: cv::Mat *

   adjustROI(self, dtop, dbottom, dleft, dright) -> Mat

      dtop: int dbottom: int dleft: int dright: int

   assignTo(self, m, type=-1)

      m: cv::Mat & type: int

      assignTo(self, m)

      m: cv::Mat &

   channels(self) -> int

      self: cv::Mat const *

   checkVector(self, elemChannels, depth=-1, requireContinuous=True) -> int

      elemChannels: int depth: int requireContinuous: bool

      checkVector(self, elemChannels, depth=-1) -> int

      elemChannels: int depth: int

      checkVector(self, elemChannels) -> int

      elemChannels: int

   clone(self) -> Mat

      self: cv::Mat const *

   col(self, x) -> Mat

      x: int

   colRange(self, startcol, endcol) -> Mat

      startcol: int endcol: int

      colRange(self, r) -> Mat

      r: cv::Range const &

   cols

      Mat_cols_get(self) -> int

      self: cv::Mat *

   copySize(self, m)

      m: cv::Mat const &

   create(self, rows, cols, type)

      rows: int cols: int type: int

      create(self, size, type)

      size: cv::Size type: int

      create(self, ndims, sizes, type)

      ndims: int sizes: int const * type: int

   data

      Mat_data_get(self) -> uchar *

      self: cv::Mat *

   dataend

      Mat_dataend_get(self) -> uchar const *

      self: cv::Mat *

   datalimit

      Mat_datalimit_get(self) -> uchar const *

      self: cv::Mat *

   datastart

      Mat_datastart_get(self) -> uchar const *

      self: cv::Mat *

   deallocate(self)

      self: cv::Mat *

   depth(self) -> int

      self: cv::Mat const *

   diag(self, d=0) -> Mat

      d: int

      diag(self) -> Mat

      self: cv::Mat const *

   dims

      Mat_dims_get(self) -> int

      self: cv::Mat *

   elemSize(self) -> size_t

      self: cv::Mat const *

   elemSize1(self) -> size_t

      self: cv::Mat const *

   empty(self) -> bool

      self: cv::Mat const *

   flags

      Mat_flags_get(self) -> int

      self: cv::Mat *

   classmethod from_array(array)

   isContinuous(self) -> bool

      self: cv::Mat const *

   isSubmatrix(self) -> bool

      self: cv::Mat const *

   locateROI(self, wholeSize, ofs)

      wholeSize: cv::Size & ofs: cv::Point &

   pop_back(self, nelems=1)

      nelems: size_t

      pop_back(self)

      self: cv::Mat *

   ptr(self, i0=0) -> uchar

      i0: int

      ptr(self) -> uchar ptr(self, i0=0) -> uchar const

      i0: int

      ptr(self) -> uchar const ptr(self, i0, i1) -> uchar

      i0: int i1: int

      ptr(self, i0, i1) -> uchar const

      i0: int i1: int

      ptr(self, i0, i1, i2) -> uchar

      i0: int i1: int i2: int

      ptr(self, i0, i1, i2) -> uchar const

      i0: int i1: int i2: int

      ptr(self, idx) -> uchar

      idx: int const *

      ptr(self, idx) -> uchar const *

      idx: int const *

   push_back(self, m)

      m: cv::Mat const &

   push_back_(self, elem)

      elem: void const *

   release(self)

      self: cv::Mat *

   reserve(self, sz)

      sz: size_t

   reshape(self, cn, rows=0) -> Mat

      cn: int rows: int

      reshape(self, cn) -> Mat

      cn: int

      reshape(self, cn, newndims, newsz) -> Mat

      cn: int newndims: int newsz: int const *

   resize(self, sz)

      sz: size_t

      resize(self, sz, s)

      sz: size_t s: cv::Scalar const &

   row(self, y) -> Mat

      y: int

   rowRange(self, startrow, endrow) -> Mat

      startrow: int endrow: int

      rowRange(self, r) -> Mat

      r: cv::Range const &

   rows

      Mat_rows_get(self) -> int

      self: cv::Mat *

   step1(self, i=0) -> size_t

      i: int

      step1(self) -> size_t

      self: cv::Mat const *

   thisown

      The membership flag

   total(self) -> size_t

      self: cv::Mat const *

   type(self) -> int

      self: cv::Mat const *

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

   Proxy of C++ cv::Matx_AddOp class.

   thisown

      The membership flag

class pagexml.Matx_DivOp

   Bases: "object"

   Proxy of C++ cv::Matx_DivOp class.

   thisown

      The membership flag

class pagexml.Matx_MatMulOp

   Bases: "object"

   Proxy of C++ cv::Matx_MatMulOp class.

   thisown

      The membership flag

class pagexml.Matx_MulOp

   Bases: "object"

   Proxy of C++ cv::Matx_MulOp class.

   thisown

      The membership flag

class pagexml.Matx_ScaleOp

   Bases: "object"

   Proxy of C++ cv::Matx_ScaleOp class.

   thisown

      The membership flag

class pagexml.Matx_SubOp

   Bases: "object"

   Proxy of C++ cv::Matx_SubOp class.

   thisown

      The membership flag

class pagexml.Matx_TOp

   Bases: "object"

   Proxy of C++ cv::Matx_TOp class.

   thisown

      The membership flag

class pagexml.NamedImage(*args)

   Bases: "object"

   Proxy of C++ NamedImage class.

   direction

      NamedImage_direction_get(self) -> int

      self: NamedImage *

   id

      NamedImage_id_get(self) -> std::string const &

      self: NamedImage *

   image

      NamedImage_image_get(self) -> Mat

      self: NamedImage *

   name

      NamedImage_name_get(self) -> std::string const &

      self: NamedImage *

   node

      NamedImage_node_get(self) -> xmlNode *

      self: NamedImage *

   rotation

      NamedImage_rotation_get(self) -> float

      self: NamedImage *

   thisown

      The membership flag

   x

      NamedImage_x_get(self) -> int

      self: NamedImage *

   y

      NamedImage_y_get(self) -> int

      self: NamedImage *

class pagexml.OGRMultiLineString_(*args)

   Bases: "object"

   Proxy of C++ >>OGRMultiLineString_<< class.

   multipolyline

      OGRMultiLineString__multipolyline_get(self) ->
      OGRMultiLineString *

      self: >>OGRMultiLineString_<< *

   thisown

      The membership flag

class pagexml.OGRMultiPolygon_(*args)

   Bases: "object"

   Proxy of C++ >>OGRMultiPolygon_<< class.

   multipolygon

      OGRMultiPolygon__multipolygon_get(self) -> OGRMultiPolygon *

      self: >>OGRMultiPolygon_<< *

   thisown

      The membership flag

class pagexml.PageXML(pagexml_path=None, schema_path=None)

   Bases: "object"

   Proxy of C++ PageXML class.

   addElem(self, name, id, node, itype=PAGEXML_INSERT_APPEND, checkid=False) -> xmlNode

      name: char const * id: char const * node: xmlNode const * itype:
      enum PAGEXML_INSERT checkid: bool

      addElem(self, name, id, node, itype=PAGEXML_INSERT_APPEND) ->
      xmlNode

      name: char const * id: char const * node: xmlNode const * itype:
      enum PAGEXML_INSERT

      addElem(self, name, id, node) -> xmlNode

      name: char const * id: char const * node: xmlNode const *

      addElem(self, name, id, xpath, itype=PAGEXML_INSERT_APPEND,
      checkid=False) -> xmlNode

      name: char const * id: char const * xpath: char const * itype:
      enum PAGEXML_INSERT checkid: bool

      addElem(self, name, id, xpath, itype=PAGEXML_INSERT_APPEND) ->
      xmlNode

      name: char const * id: char const * xpath: char const * itype:
      enum PAGEXML_INSERT

      addElem(self, name, id, xpath) -> xmlNode

      name: char const * id: char const * xpath: char const *

      addElem(self, name, id, xpath, itype=PAGEXML_INSERT_APPEND,
      checkid=False) -> xmlNode

      name: std::string const id: std::string const xpath: std::string
      const itype: enum PAGEXML_INSERT checkid: bool

      addElem(self, name, id, xpath, itype=PAGEXML_INSERT_APPEND) ->
      xmlNode

      name: std::string const id: std::string const xpath: std::string
      const itype: enum PAGEXML_INSERT

      addElem(self, name, id, xpath) -> xmlNode *

      name: std::string const id: std::string const xpath: std::string
      const

   addGlyph(self, node, id=None, before_id=None) -> xmlNode

      node: xmlNode * id: char const * before_id: char const *

      addGlyph(self, node, id=None) -> xmlNode

      node: xmlNode * id: char const *

      addGlyph(self, node) -> xmlNode

      node: xmlNode *

      addGlyph(self, xpath, id=None, before_id=None) -> xmlNode

      xpath: char const * id: char const * before_id: char const *

      addGlyph(self, xpath, id=None) -> xmlNode

      xpath: char const * id: char const *

      addGlyph(self, xpath) -> xmlNode *

      xpath: char const *

   addPage(self, image, imgW, imgH, id=None, before_node=None) -> xmlNode

      image: char const * imgW: int const imgH: int const id: char
      const * before_node: xmlNode *

      addPage(self, image, imgW, imgH, id=None) -> xmlNode

      image: char const * imgW: int const imgH: int const id: char
      const *

      addPage(self, image, imgW, imgH) -> xmlNode

      image: char const * imgW: int const imgH: int const

      addPage(self, image, imgW, imgH, id=None, before_node=None) ->
      xmlNode

      image: std::string imgW: int const imgH: int const id: char
      const * before_node: xmlNode *

      addPage(self, image, imgW, imgH, id=None) -> xmlNode

      image: std::string imgW: int const imgH: int const id: char
      const *

      addPage(self, image, imgW, imgH) -> xmlNode *

      image: std::string imgW: int const imgH: int const

   addTextLine(self, node, id=None, before_id=None) -> xmlNode

      node: xmlNode * id: char const * before_id: char const *

      addTextLine(self, node, id=None) -> xmlNode

      node: xmlNode * id: char const *

      addTextLine(self, node) -> xmlNode

      node: xmlNode *

      addTextLine(self, xpath, id=None, before_id=None) -> xmlNode

      xpath: char const * id: char const * before_id: char const *

      addTextLine(self, xpath, id=None) -> xmlNode

      xpath: char const * id: char const *

      addTextLine(self, xpath) -> xmlNode *

      xpath: char const *

   addTextRegion(self, node, id=None, before_id=None, prepend=False) -> xmlNode

      node: xmlNode * id: char const * before_id: char const *
      prepend: bool

      addTextRegion(self, node, id=None, before_id=None) -> xmlNode

      node: xmlNode * id: char const * before_id: char const *

      addTextRegion(self, node, id=None) -> xmlNode

      node: xmlNode * id: char const *

      addTextRegion(self, node) -> xmlNode

      node: xmlNode *

      addTextRegion(self, xpath, id=None, before_id=None,
      prepend=False) -> xmlNode

      xpath: char const * id: char const * before_id: char const *
      prepend: bool

      addTextRegion(self, xpath, id=None, before_id=None) -> xmlNode

      xpath: char const * id: char const * before_id: char const *

      addTextRegion(self, xpath, id=None) -> xmlNode

      xpath: char const * id: char const *

      addTextRegion(self, xpath) -> xmlNode *

      xpath: char const *

   addWord(self, node, id=None, before_id=None) -> xmlNode

      node: xmlNode * id: char const * before_id: char const *

      addWord(self, node, id=None) -> xmlNode

      node: xmlNode * id: char const *

      addWord(self, node) -> xmlNode

      node: xmlNode *

      addWord(self, xpath, id=None, before_id=None) -> xmlNode

      xpath: char const * id: char const * before_id: char const *

      addWord(self, xpath, id=None) -> xmlNode

      xpath: char const * id: char const *

      addWord(self, xpath) -> xmlNode *

      xpath: char const *

   areIDsUnique(self) -> bool

      self: PageXML *

   closest(self, name, node) -> xmlNode *

      name: char const * node: xmlNode *

   computeAreas(self, polys) -> _doubleArray

      polys: std::vector< >>OGRMultiPolygonPtr_<<,std::allocator<
      >>OGRMultiPolygonPtr_<< > >

   computeBaselineIntersectionsWeightedByArea(self, poly, polys, areas) -> _doubleArray

      poly: >>OGRMultiLineStringPtr_<< polys: std::vector<
      >>OGRMultiPolygonPtr_<<,std::allocator< >>OGRMultiPolygonPtr_<<
      > > areas: std::vector< double,std::allocator< double > >

   computeCoordsIntersectionsWeightedByArea(self, poly, polys, areas) -> _doubleArray

      poly: >>OGRMultiPolygonPtr_<< polys: std::vector<
      >>OGRMultiPolygonPtr_<<,std::allocator< >>OGRMultiPolygonPtr_<<
      > > areas: std::vector< double,std::allocator< double > >

   computeIntersectFactor(self, poly1, poly2) -> double

      poly1: >>OGRMultiPolygonPtr_<< poly2: >>OGRMultiPolygonPtr_<<

      computeIntersectFactor(self, poly1, poly2) -> double

      poly1: >>OGRMultiLineStringPtr_<< poly2: >>OGRMultiPolygonPtr_<<

   computeIntersectionPercentage(self, poly1, poly2) -> double

      poly1: >>OGRMultiPolygonPtr_<< poly2: >>OGRMultiPolygonPtr_<<

   computeIntersectionPercentages(self, poly, polys) -> _doubleArray

      poly: >>OGRMultiPolygonPtr_<< polys: std::vector<
      >>OGRMultiPolygonPtr_<<,std::allocator< >>OGRMultiPolygonPtr_<<
      > >

   computeIoU(self, poly1, poly2) -> double

      poly1: >>OGRMultiPolygonPtr_<< poly2: >>OGRMultiPolygonPtr_<<

   computeIoUs(self, poly, polys) -> _doubleArray

      poly: >>OGRMultiPolygonPtr_<< polys: std::vector<
      >>OGRMultiPolygonPtr_<<,std::allocator< >>OGRMultiPolygonPtr_<<
      > >

   copyElem(self, elem, node, itype=PAGEXML_INSERT_APPEND) -> xmlNode

      elem: xmlNode * node: xmlNode const * itype: enum PAGEXML_INSERT

      copyElem(self, elem, node) -> xmlNode *

      elem: xmlNode * node: xmlNode const *

   copyTextLinesAssignByOverlap(self, pageFrom, overlap_type=PAGEXML_OVERLAP_COORDS_IOU, overlap_fact=0.5) -> int

      pageFrom: PageXML & overlap_type: enum PAGEXML_OVERLAP
      overlap_fact: double

      copyTextLinesAssignByOverlap(self, pageFrom,
      overlap_type=PAGEXML_OVERLAP_COORDS_IOU) -> int

      pageFrom: PageXML & overlap_type: enum PAGEXML_OVERLAP

      copyTextLinesAssignByOverlap(self, pageFrom) -> int

      pageFrom: PageXML &

   count(self, xpath, node=None) -> int

      xpath: char const * node: xmlNode *

      count(self, xpath) -> int

      xpath: char const *

      count(self, xpath, node=None) -> int

      xpath: std::string node: xmlNode *

      count(self, xpath) -> int

      xpath: std::string

   crop(self, xpath, margin=None, opaque_coords=True, transp_xpath=None, base_xpath=None) -> std::vector< NamedImage,std::allocator< NamedImage > >

      xpath: char const * margin: cv::Point2f * opaque_coords: bool
      transp_xpath: char const * base_xpath: char const *

      crop(self, xpath, margin=None, opaque_coords=True,
      transp_xpath=None) -> std::vector< NamedImage,std::allocator<
      NamedImage > >

      xpath: char const * margin: cv::Point2f * opaque_coords: bool
      transp_xpath: char const *

      crop(self, xpath, margin=None, opaque_coords=True) ->
      std::vector< NamedImage,std::allocator< NamedImage > >

      xpath: char const * margin: cv::Point2f * opaque_coords: bool

      crop(self, xpath, margin=None) -> std::vector<
      NamedImage,std::allocator< NamedImage > >

      xpath: char const * margin: cv::Point2f *

      crop(self, xpath) -> std::vector< NamedImage,std::allocator<
      NamedImage > >

      xpath: char const *

   getAttr(self, node, name) -> std::string

      node: xmlNode const * name: char const *

      getAttr(self, xpath, name) -> std::string

      xpath: char const * name: char const *

      getAttr(self, xpath, name) -> std::string

      xpath: std::string const name: std::string const

   getBaselineLength(self, points) -> double

      points: std::vector< cv::Point2f,std::allocator< cv::Point2f > >

   getBaselineOrientation(self, elem) -> double

      elem: xmlNode *

      getBaselineOrientation(self, points) -> double

      points: std::vector< cv::Point2f,std::allocator< cv::Point2f > >

   getDocPtr(self) -> xmlDocPtr

      self: PageXML *

   getFpgram(self, node) -> cvPoint2fVector

      node: xmlNode const *

   getImageBases(self) -> std::vector< std::string,std::allocator< std::string > >

      self: PageXML *

   getNodeName(self, node, base_node=None) -> std::string

      node: xmlNode * base_node: xmlNode *

      getNodeName(self, node) -> std::string

      node: xmlNode *

   getOGRpolygon(self, node, xpath) -> OGRMultiPolygonPtr_

      node: xmlNode const * xpath: char const *

      getOGRpolygon(self, node) -> >>OGRMultiPolygonPtr_<<

      node: xmlNode const *

   getOGRpolygonArea(self, poly) -> double

      poly: >>OGRMultiPolygonPtr_<<

   getOGRpolygons(self, nodes, xpath) -> std::vector< OGRMultiPolygonPtr_,std::allocator< OGRMultiPolygonPtr_ > >

      nodes: std::vector< xmlNode >>*<<,std::allocator< xmlNode * > >
      xpath: char const *

      getOGRpolygons(self, nodes) -> std::vector<
      >>OGRMultiPolygonPtr_<<,std::allocator< >>OGRMultiPolygonPtr_<<
      > >

      nodes: std::vector< xmlNode >>*<<,std::allocator< xmlNode * > >

   getOGRpolyline(self, node, xpath) -> OGRMultiLineStringPtr_

      node: xmlNode const * xpath: char const *

      getOGRpolyline(self, node) -> >>OGRMultiLineStringPtr_<<

      node: xmlNode const *

   getPageHeight(self, node) -> unsigned int

      node: xmlNode *

      getPageHeight(self, pagenum) -> unsigned int

      pagenum: int

   getPageImage(self, pagenum) -> Mat

      pagenum: int

      getPageImage(self, node) -> Mat

      node: xmlNode *

   getPageImageFilename(self, node) -> std::string

      node: xmlNode *

      getPageImageFilename(self, pagenum) -> std::string

      pagenum: int

   getPageImageOrientation(self, node) -> int

      node: xmlNode *

      getPageImageOrientation(self, pagenum) -> int

      pagenum: int

   getPageNumber(self, node) -> int

      node: xmlNode *

   getPageWidth(self, node) -> unsigned int

      node: xmlNode *

      getPageWidth(self, pagenum) -> unsigned int

      pagenum: int

   getPagesSize(self, pages) -> cvSize2iVector

      pages: std::vector< xmlNode >>*<<,std::allocator< xmlNode * > >

      getPagesSize(self, xpath) -> cvSize2iVector

      xpath: char const *

      getPagesSize(self) -> cvSize2iVector

      self: PageXML *

   getPoints(self, node, xpath) -> cvPoint2fVector

      node: xmlNode const * xpath: char const *

      getPoints(self, node) -> cvPoint2fVector

      node: xmlNode const *

      getPoints(self, nodes, xpath) -> std::vector< std::vector<
      cv::Point2f,std::allocator< cv::Point2f > >,std::allocator<
      std::vector< cv::Point2f,std::allocator< cv::Point2f > > > >

      nodes: std::vector< xmlNode >>*<<,std::allocator< xmlNode * > >
      const xpath: char const *

      getPoints(self, nodes) -> std::vector< std::vector<
      cv::Point2f,std::allocator< cv::Point2f > >,std::allocator<
      std::vector< cv::Point2f,std::allocator< cv::Point2f > > > >

      nodes: std::vector< xmlNode >>*<<,std::allocator< xmlNode * > >
      const

   getPropertyValue(self, node, key) -> std::string

      node: xmlNode * key: char const *

   getReadingDirection(self, elem) -> int

      elem: xmlNode const *

   getRotation(self, elem) -> double

      elem: xmlNode const *

   getTextEquiv(self, node, xpath, separator) -> std::string

      node: xmlNode * xpath: char const * separator: char const *

      getTextEquiv(self, node, xpath) -> std::string

      node: xmlNode * xpath: char const *

      getTextEquiv(self, node) -> std::string

      node: xmlNode *

   getTextLinesReadingOrder(self, lines, max_angle_diff=25, max_horiz_iou=0.1, min_prolong_fact=0.5, prolong_alpha=0.8, fake_baseline=False) -> _intArray

      lines: std::vector< xmlNode >>*<<,std::allocator< xmlNode * > >
      max_angle_diff: double max_horiz_iou: double min_prolong_fact:
      double prolong_alpha: double fake_baseline: bool

      getTextLinesReadingOrder(self, lines, max_angle_diff=25,
      max_horiz_iou=0.1, min_prolong_fact=0.5, prolong_alpha=0.8) ->
      _intArray

      lines: std::vector< xmlNode >>*<<,std::allocator< xmlNode * > >
      max_angle_diff: double max_horiz_iou: double min_prolong_fact:
      double prolong_alpha: double

      getTextLinesReadingOrder(self, lines, max_angle_diff=25,
      max_horiz_iou=0.1, min_prolong_fact=0.5) -> _intArray

      lines: std::vector< xmlNode >>*<<,std::allocator< xmlNode * > >
      max_angle_diff: double max_horiz_iou: double min_prolong_fact:
      double

      getTextLinesReadingOrder(self, lines, max_angle_diff=25,
      max_horiz_iou=0.1) -> _intArray

      lines: std::vector< xmlNode >>*<<,std::allocator< xmlNode * > >
      max_angle_diff: double max_horiz_iou: double

      getTextLinesReadingOrder(self, lines, max_angle_diff=25) ->
      _intArray

      lines: std::vector< xmlNode >>*<<,std::allocator< xmlNode * > >
      max_angle_diff: double

      getTextLinesReadingOrder(self, lines) -> _intArray

      lines: std::vector< xmlNode >>*<<,std::allocator< xmlNode * > >

   getUnionOGRpolygon(self, nodes, xpath) -> OGRMultiPolygonPtr_

      nodes: std::vector< xmlNode >>*<<,std::allocator< xmlNode * > >
      xpath: char const *

      getUnionOGRpolygon(self, nodes) -> >>OGRMultiPolygonPtr_<<

      nodes: std::vector< xmlNode >>*<<,std::allocator< xmlNode * > >

   getValue(self, node) -> std::string

      node: xmlNode *

      getValue(self, xpath, node=None) -> std::string

      xpath: char const * node: xmlNode const *

      getValue(self, xpath) -> std::string

      xpath: char const *

   getXheight(self, node) -> float

      node: xmlNode const *

      getXheight(self, id) -> float

      id: char const *

   insertElem(self, elem, node, itype) -> xmlNode *

      elem: xmlNode * node: xmlNode const * itype: enum PAGEXML_INSERT

   intersection(self, line1_point1, line1_point2, line2_point1, line2_point2, _ipoint) -> bool

      line1_point1: cv::Point2f line1_point2: cv::Point2f
      line2_point1: cv::Point2f line2_point2: cv::Point2f _ipoint:
      cv::Point2f &

   static isBBox(points) -> bool

      points: std::vector< cv::Point2f,std::allocator< cv::Point2f > >
      const &

   isPolystripe(self, coords, baseline, height=None, offset=None) -> bool

      coords: std::vector< cv::Point2f,std::allocator< cv::Point2f > >
      baseline: std::vector< cv::Point2f,std::allocator< cv::Point2f >
      > height: double * offset: double *

      isPolystripe(self, coords, baseline, height=None) -> bool

      coords: std::vector< cv::Point2f,std::allocator< cv::Point2f > >
      baseline: std::vector< cv::Point2f,std::allocator< cv::Point2f >
      > height: double *

      isPolystripe(self, coords, baseline) -> bool

      coords: std::vector< cv::Point2f,std::allocator< cv::Point2f > >
      baseline: std::vector< cv::Point2f,std::allocator< cv::Point2f >
      >

   isValid(self) -> bool

      self: PageXML *

   loadImage(self, pagenum, fname=None, resize_coords=False, density=0)

      pagenum: int fname: char const * resize_coords: bool const
      density: int

      loadImage(self, pagenum, fname=None, resize_coords=False)

      pagenum: int fname: char const * resize_coords: bool const

      loadImage(self, pagenum, fname=None)

      pagenum: int fname: char const *

      loadImage(self, pagenum)

      pagenum: int

      loadImage(self, node, fname=None, resize_coords=False,
      density=0)

      node: xmlNode * fname: char const * resize_coords: bool const
      density: int

      loadImage(self, node, fname=None, resize_coords=False)

      node: xmlNode * fname: char const * resize_coords: bool const

      loadImage(self, node, fname=None)

      node: xmlNode * fname: char const *

      loadImage(self, node)

      node: xmlNode *

   loadImages(self, resize_coords, density)

      resize_coords: bool const density: int const

   loadSchema(self, schema_path)

      schema_path: char const *

   loadXml(self, fname, validate=True)

      fname: char const * validate: bool

      loadXml(self, fname)

      fname: char const *

      loadXml(self, fnum, prevfree=True, validate=True)

      fnum: int prevfree: bool validate: bool

      loadXml(self, fnum, prevfree=True)

      fnum: int prevfree: bool

      loadXml(self, fnum)

      fnum: int

   loadXmlString(self, xml_string, validate=True)

      xml_string: char const * validate: bool

      loadXmlString(self, xml_string)

      xml_string: char const *

   moveElem(self, elem, node, itype=PAGEXML_INSERT_APPEND) -> xmlNode

      elem: xmlNode * node: xmlNode const * itype: enum PAGEXML_INSERT

      moveElem(self, elem, node) -> xmlNode *

      elem: xmlNode * node: xmlNode const *

   moveElems(self, elems, node, itype=PAGEXML_INSERT_APPEND) -> int

      elems: std::vector< xmlNode >>*<<,std::allocator< xmlNode * > >
      const & node: xmlNode const * itype: enum PAGEXML_INSERT

      moveElems(self, elems, node) -> int

      elems: std::vector< xmlNode >>*<<,std::allocator< xmlNode * > >
      const & node: xmlNode const *

   multiPolygonIntersection(self, poly1, poly2) -> OGRMultiPolygonPtr_

      poly1: >>OGRMultiPolygonPtr_<< poly2: >>OGRMultiPolygonPtr_<<

   multiPolylineIntersection(self, poly1, poly2) -> OGRMultiLineStringPtr_

      poly1: >>OGRMultiLineStringPtr_<< poly2: >>OGRMultiPolygonPtr_<<

   newXml(self, creator, image, imgW=0, imgH=0) -> xmlNode

      creator: char const * image: char const * imgW: int const imgH:
      int const

      newXml(self, creator, image, imgW=0) -> xmlNode

      creator: char const * image: char const * imgW: int const

      newXml(self, creator, image) -> xmlNode *

      creator: char const * image: char const *

   static nodeIs(node, name) -> bool

      node: xmlNode * name: char const *

   parent(self, node) -> xmlNode *

      node: xmlNode const *

   static pointsBBox(points) -> cvPoint2fVector

      points: std::vector< cv::Point2f,std::allocator< cv::Point2f > >

   static pointsLimits(points, xmin, xmax, ymin, ymax)

      points: std::vector< cv::Point2f,std::allocator< cv::Point2f > >
      & xmin: double & xmax: double & ymin: double & ymax: double &

   pointsToOGRpolygon(self, points) -> OGRMultiPolygonPtr_

      points: std::vector< cv::Point2f,std::allocator< cv::Point2f > >

   pointsToOGRpolygons(self, points) -> std::vector< OGRMultiPolygonPtr_,std::allocator< OGRMultiPolygonPtr_ > >

      points: std::vector< std::vector< cv::Point2f,std::allocator<
      cv::Point2f > >,std::allocator< std::vector<
      cv::Point2f,std::allocator< cv::Point2f > > > >

   static pointsToString(points, rounded=False) -> std::string

      points: std::vector< cv::Point2f,std::allocator< cv::Point2f > >
      rounded: bool

      pointsToString(points) -> std::string

      points: std::vector< cv::Point2f,std::allocator< cv::Point2f > >

      pointsToString(points) -> std::string

      points: std::vector< cv::Point,std::allocator< cv::Point > >

   printConf(self, file)

      file: FILE *

      printConf(self)

      self: PageXML *

   static printVersions(file)

      file: FILE *

      printVersions()

   processEnd(self)

      self: PageXML *

   processStart(self, tool, ref=None)

      tool: char const * ref: char const *

      processStart(self, tool)

      tool: char const *

   relativizeImageFilename(self, xml_path)

      xml_path: char const *

   resize(self, sizes, pages, check_aspect_ratio=True) -> int

      sizes: std::vector< cv::Size2i,std::allocator< cv::Size2i > >
      pages: std::vector< xmlNode >>*<<,std::allocator< xmlNode * > >
      check_aspect_ratio: bool

      resize(self, sizes, pages) -> int

      sizes: std::vector< cv::Size2i,std::allocator< cv::Size2i > >
      pages: std::vector< xmlNode >>*<<,std::allocator< xmlNode * > >

      resize(self, sizes, xpath, check_aspect_ratio=True) -> int

      sizes: std::vector< cv::Size2i,std::allocator< cv::Size2i > >
      xpath: char const * check_aspect_ratio: bool

      resize(self, sizes, xpath) -> int

      sizes: std::vector< cv::Size2i,std::allocator< cv::Size2i > >
      xpath: char const *

      resize(self, sizes) -> int

      sizes: std::vector< cv::Size2i,std::allocator< cv::Size2i > >

      resize(self, size, page, check_aspect_ratio=True) -> int

      size: cv::Size2i page: xmlNode * check_aspect_ratio: bool

      resize(self, size, page) -> int

      size: cv::Size2i page: xmlNode *

      resize(self, fact, xpath) -> int

      fact: double xpath: char const *

      resize(self, fact) -> int

      fact: double

   rmElem(self, node)

      node: xmlNode const *

   rmElems(self, nodes) -> int

      nodes: std::vector< xmlNode >>*<<,std::allocator< xmlNode * > >
      const &

      rmElems(self, xpath, node=None) -> int

      xpath: char const * node: xmlNode *

      rmElems(self, xpath) -> int

      xpath: char const *

      rmElems(self, xpath, node=None) -> int

      xpath: std::string const node: xmlNode *

      rmElems(self, xpath) -> int

      xpath: std::string const

   select(self, xpath, node=None) -> xmlNodePtrVector

      xpath: char const * node: xmlNode const *

      select(self, xpath) -> xmlNodePtrVector

      xpath: char const *

      select(self, xpath, node=None) -> xmlNodePtrVector

      xpath: std::string node: xmlNode const *

      select(self, xpath) -> xmlNodePtrVector

      xpath: std::string

      select(self, xpath, nodes, unique=True) -> xmlNodePtrVector

      xpath: char const * nodes: std::vector< xmlNode
      >>*<<,std::allocator< xmlNode * > > const unique: bool

      select(self, xpath, nodes) -> xmlNodePtrVector

      xpath: char const * nodes: std::vector< xmlNode
      >>*<<,std::allocator< xmlNode * > > const

   selectByID(self, id, node=None) -> xmlNode

      id: char const * node: xmlNode const *

      selectByID(self, id) -> xmlNode *

      id: char const *

   selectByOverlap(self, points, page, xpath, overlap_thr=0.1, overlap_type=PAGEXML_OVERLAP_COORDS_IWA) -> xmlNodePtrVector

      points: std::vector< cv::Point2f,std::allocator< cv::Point2f > >
      page: xmlNode * xpath: char const * overlap_thr: double
      overlap_type: enum PAGEXML_OVERLAP

      selectByOverlap(self, points, page, xpath, overlap_thr=0.1) ->
      xmlNodePtrVector

      points: std::vector< cv::Point2f,std::allocator< cv::Point2f > >
      page: xmlNode * xpath: char const * overlap_thr: double

      selectByOverlap(self, points, page, xpath) -> xmlNodePtrVector

      points: std::vector< cv::Point2f,std::allocator< cv::Point2f > >
      page: xmlNode * xpath: char const *

      selectByOverlap(self, points, page) -> xmlNodePtrVector

      points: std::vector< cv::Point2f,std::allocator< cv::Point2f > >
      page: xmlNode *

      selectByOverlap(self, points, pagenum, xpath, overlap_thr=0.1,
      overlap_type=PAGEXML_OVERLAP_COORDS_IWA) -> xmlNodePtrVector

      points: std::vector< cv::Point2f,std::allocator< cv::Point2f > >
      pagenum: int xpath: char const * overlap_thr: double
      overlap_type: enum PAGEXML_OVERLAP

      selectByOverlap(self, points, pagenum, xpath, overlap_thr=0.1)
      -> xmlNodePtrVector

      points: std::vector< cv::Point2f,std::allocator< cv::Point2f > >
      pagenum: int xpath: char const * overlap_thr: double

      selectByOverlap(self, points, pagenum, xpath) ->
      xmlNodePtrVector

      points: std::vector< cv::Point2f,std::allocator< cv::Point2f > >
      pagenum: int xpath: char const *

      selectByOverlap(self, points, pagenum) -> xmlNodePtrVector

      points: std::vector< cv::Point2f,std::allocator< cv::Point2f > >
      pagenum: int

   selectNth(self, xpath, num=0, node=None) -> xmlNode

      xpath: char const * num: int node: xmlNode const *

      selectNth(self, xpath, num=0) -> xmlNode

      xpath: char const * num: int

      selectNth(self, xpath) -> xmlNode

      xpath: char const *

      selectNth(self, xpath, num=0, node=None) -> xmlNode

      xpath: std::string num: int node: xmlNode const *

      selectNth(self, xpath, num=0) -> xmlNode

      xpath: std::string num: int

      selectNth(self, xpath) -> xmlNode *

      xpath: std::string

   setAttr(self, nodes, name, value) -> int

      nodes: std::vector< xmlNode >>*<<,std::allocator< xmlNode * > >
      name: char const * value: char const *

      setAttr(self, node, name, value) -> int

      node: xmlNode const * name: char const * value: char const *

      setAttr(self, xpath, name, value) -> int

      xpath: char const * name: char const * value: char const *

      setAttr(self, xpath, name, value) -> int

      xpath: std::string const name: std::string const value:
      std::string const

   setBaseline(self, node, points, _conf=None) -> xmlNode

      node: xmlNode * points: std::vector< cv::Point2f,std::allocator<
      cv::Point2f > > const & _conf: double const *

      setBaseline(self, node, points) -> xmlNode

      node: xmlNode * points: std::vector< cv::Point2f,std::allocator<
      cv::Point2f > > const &

      setBaseline(self, xpath, points, _conf=None) -> xmlNode

      xpath: char const * points: std::vector<
      cv::Point2f,std::allocator< cv::Point2f > > const & _conf:
      double const *

      setBaseline(self, xpath, points) -> xmlNode

      xpath: char const * points: std::vector<
      cv::Point2f,std::allocator< cv::Point2f > > const &

      setBaseline(self, node, x1, y1, x2, y2, _conf=None) -> xmlNode

      node: xmlNode * x1: double y1: double x2: double y2: double
      _conf: double const *

      setBaseline(self, node, x1, y1, x2, y2) -> xmlNode *

      node: xmlNode * x1: double y1: double x2: double y2: double

   setCoords(self, node, points, _conf=None) -> xmlNode

      node: xmlNode * points: std::vector< cv::Point2f,std::allocator<
      cv::Point2f > > const & _conf: double const *

      setCoords(self, node, points) -> xmlNode

      node: xmlNode * points: std::vector< cv::Point2f,std::allocator<
      cv::Point2f > > const &

      setCoords(self, node, points, _conf=None) -> xmlNode

      node: xmlNode * points: std::vector< cv::Point,std::allocator<
      cv::Point > > const & _conf: double const *

      setCoords(self, node, points) -> xmlNode

      node: xmlNode * points: std::vector< cv::Point,std::allocator<
      cv::Point > > const &

      setCoords(self, xpath, points, _conf=None) -> xmlNode

      xpath: char const * points: std::vector<
      cv::Point2f,std::allocator< cv::Point2f > > const & _conf:
      double const *

      setCoords(self, xpath, points) -> xmlNode *

      xpath: char const * points: std::vector<
      cv::Point2f,std::allocator< cv::Point2f > > const &

   setCoordsBBox(self, node, xmin, ymin, width, height, _conf=None, subone=True) -> xmlNode

      node: xmlNode * xmin: double ymin: double width: double height:
      double _conf: double const * subone: bool

      setCoordsBBox(self, node, xmin, ymin, width, height, _conf=None)
      -> xmlNode

      node: xmlNode * xmin: double ymin: double width: double height:
      double _conf: double const *

      setCoordsBBox(self, node, xmin, ymin, width, height) -> xmlNode
      *

      node: xmlNode * xmin: double ymin: double width: double height:
      double

   setPageImageFilename(self, node, image)

      node: xmlNode * image: char const *

      setPageImageFilename(self, pagenum, image)

      pagenum: int image: char const *

   setPageImageOrientation(self, node, angle, _conf=None)

      node: xmlNode * angle: int _conf: double const *

      setPageImageOrientation(self, node, angle)

      node: xmlNode * angle: int

      setPageImageOrientation(self, pagenum, angle, _conf=None)

      pagenum: int angle: int _conf: double const *

      setPageImageOrientation(self, pagenum, angle)

      pagenum: int angle: int

   setPolystripe(self, node, height, offset=0.25, offset_check=True) -> xmlNode

      node: xmlNode * height: double offset: double offset_check: bool

      setPolystripe(self, node, height, offset=0.25) -> xmlNode

      node: xmlNode * height: double offset: double

      setPolystripe(self, node, height) -> xmlNode *

      node: xmlNode * height: double

   setProperty(self, node, key, val=None, _conf=None) -> xmlNode

      node: xmlNode * key: char const * val: char const * _conf:
      double const *

      setProperty(self, node, key, val=None) -> xmlNode

      node: xmlNode * key: char const * val: char const *

      setProperty(self, node, key) -> xmlNode

      node: xmlNode * key: char const *

      setProperty(self, node, key, val, _conf=None) -> xmlNode

      node: xmlNode * key: char const * val: double const _conf:
      double const *

      setProperty(self, node, key, val) -> xmlNode *

      node: xmlNode * key: char const * val: double const

   setReadingDirection(self, elem, direction)

      elem: xmlNode const * direction: enum PAGEXML_READ_DIRECTION

   setRotation(self, elem, rotation)

      elem: xmlNode const * rotation: float const

   setTextEquiv(self, node, text, _conf=None) -> xmlNode

      node: xmlNode * text: char const * _conf: double const *

      setTextEquiv(self, node, text) -> xmlNode

      node: xmlNode * text: char const *

      setTextEquiv(self, xpath, text, _conf=None) -> xmlNode

      xpath: char const * text: char const * _conf: double const *

      setTextEquiv(self, xpath, text) -> xmlNode *

      xpath: char const * text: char const *

   static setValidationEnabled(val)

      val: bool

   simplifyIDs(self) -> int

      self: PageXML *

   static stringToPoints(spoints) -> cvPoint2fVector

      spoints: char const *

      stringToPoints(spoints) -> cvPoint2fVector

      spoints: std::string

   testTextLineContinuation(self, lines, _line_group_order, _line_group_score, max_angle_diff=25, max_horiz_iou=0.1, min_prolong_fact=0.5, prolong_alpha=0.8, fake_baseline=False) -> int

      lines: std::vector< xmlNode >>*<<,std::allocator< xmlNode * > >
      _line_group_order: std::vector< std::vector< int,std::allocator<
      int > >,std::allocator< std::vector< int,std::allocator< int > >
      > > & _line_group_score: std::vector< double,std::allocator<
      double > > & max_angle_diff: double max_horiz_iou: double
      min_prolong_fact: double prolong_alpha: double fake_baseline:
      bool

      testTextLineContinuation(self, lines, _line_group_order,
      _line_group_score, max_angle_diff=25, max_horiz_iou=0.1,
      min_prolong_fact=0.5, prolong_alpha=0.8) -> int

      lines: std::vector< xmlNode >>*<<,std::allocator< xmlNode * > >
      _line_group_order: std::vector< std::vector< int,std::allocator<
      int > >,std::allocator< std::vector< int,std::allocator< int > >
      > > & _line_group_score: std::vector< double,std::allocator<
      double > > & max_angle_diff: double max_horiz_iou: double
      min_prolong_fact: double prolong_alpha: double

      testTextLineContinuation(self, lines, _line_group_order,
      _line_group_score, max_angle_diff=25, max_horiz_iou=0.1,
      min_prolong_fact=0.5) -> int

      lines: std::vector< xmlNode >>*<<,std::allocator< xmlNode * > >
      _line_group_order: std::vector< std::vector< int,std::allocator<
      int > >,std::allocator< std::vector< int,std::allocator< int > >
      > > & _line_group_score: std::vector< double,std::allocator<
      double > > & max_angle_diff: double max_horiz_iou: double
      min_prolong_fact: double

      testTextLineContinuation(self, lines, _line_group_order,
      _line_group_score, max_angle_diff=25, max_horiz_iou=0.1) -> int

      lines: std::vector< xmlNode >>*<<,std::allocator< xmlNode * > >
      _line_group_order: std::vector< std::vector< int,std::allocator<
      int > >,std::allocator< std::vector< int,std::allocator< int > >
      > > & _line_group_score: std::vector< double,std::allocator<
      double > > & max_angle_diff: double max_horiz_iou: double

      testTextLineContinuation(self, lines, _line_group_order,
      _line_group_score, max_angle_diff=25) -> int

      lines: std::vector< xmlNode >>*<<,std::allocator< xmlNode * > >
      _line_group_order: std::vector< std::vector< int,std::allocator<
      int > >,std::allocator< std::vector< int,std::allocator< int > >
      > > & _line_group_score: std::vector< double,std::allocator<
      double > > & max_angle_diff: double

      testTextLineContinuation(self, lines, _line_group_order,
      _line_group_score) -> int

      lines: std::vector< xmlNode >>*<<,std::allocator< xmlNode * > >
      _line_group_order: std::vector< std::vector< int,std::allocator<
      int > >,std::allocator< std::vector< int,std::allocator< int > >
      > > & _line_group_score: std::vector< double,std::allocator<
      double > > &

   thisown

      The membership flag

   toString(self, validate=True) -> std::string

      validate: bool

      toString(self) -> std::string

      self: PageXML *

   updateLastChange(self)

      self: PageXML *

   static version() -> char *

   write(self, fname, validate=True) -> int

      fname: char const * validate: bool

      write(self, fname) -> int

      fname: char const *

      write(self) -> int

      self: PageXML *

pagexml.PageXML_isBBox(points) -> bool

   points: std::vector< cv::Point2f,std::allocator< cv::Point2f > >
   const &

pagexml.PageXML_nodeIs(node, name) -> bool

   node: xmlNode * name: char const *

pagexml.PageXML_pointsBBox(points) -> cvPoint2fVector

   points: std::vector< cv::Point2f,std::allocator< cv::Point2f > >

pagexml.PageXML_pointsLimits(points, xmin, xmax, ymin, ymax)

   points: std::vector< cv::Point2f,std::allocator< cv::Point2f > > &
   xmin: double & xmax: double & ymin: double & ymax: double &

pagexml.PageXML_pointsToString(*args)

   pointsToString(points, rounded=False) -> std::string

   points: std::vector< cv::Point2f,std::allocator< cv::Point2f > >
   rounded: bool

   pointsToString(points) -> std::string

   points: std::vector< cv::Point2f,std::allocator< cv::Point2f > >

   PageXML_pointsToString(points) -> std::string

   points: std::vector< cv::Point,std::allocator< cv::Point > >

pagexml.PageXML_printVersions(*args)

   printVersions(file)

   file: FILE *

   PageXML_printVersions()

pagexml.PageXML_setValidationEnabled(val)

   val: bool

pagexml.PageXML_stringToPoints(*args)

   stringToPoints(spoints) -> cvPoint2fVector

   spoints: char const *

   PageXML_stringToPoints(spoints) -> cvPoint2fVector

   spoints: std::string

pagexml.PageXML_version() -> char *

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

   Proxy of C++ cv::Range class.

   static all() -> Range

   empty(self) -> bool

      self: cv::Range const *

   end

      Range_end_get(self) -> int

      self: cv::Range *

   size(self) -> int

      self: cv::Range const *

   start

      Range_start_get(self) -> int

      self: cv::Range *

   thisown

      The membership flag

pagexml.Range_all() -> Range

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

   Proxy of C++ swig::SwigPyIterator class.

   advance(self, n) -> SwigPyIterator

      n: ptrdiff_t

   copy(self) -> SwigPyIterator

      self: swig::SwigPyIterator const *

   decr(self, n=1) -> SwigPyIterator

      n: size_t

      decr(self) -> SwigPyIterator

      self: swig::SwigPyIterator *

   distance(self, x) -> ptrdiff_t

      x: swig::SwigPyIterator const &

   equal(self, x) -> bool

      x: swig::SwigPyIterator const &

   incr(self, n=1) -> SwigPyIterator

      n: size_t

      incr(self) -> SwigPyIterator

      self: swig::SwigPyIterator *

   next(self) -> PyObject *

      self: swig::SwigPyIterator *

   previous(self) -> PyObject *

      self: swig::SwigPyIterator *

   thisown

      The membership flag

   value(self) -> PyObject *

      self: swig::SwigPyIterator const *

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

   Proxy of C++ std::vector<(cv::Point2f)> class.

   append(self, x)

      x: std::vector< cv::Point_< float > >::value_type const &

   assign(self, n, x)

      n: std::vector< cv::Point_< float > >::size_type x: std::vector<
      cv::Point_< float > >::value_type const &

   back(self) -> _Point__float

      self: std::vector< cv::Point2f > const *

   begin(self) -> std::vector< cv::Point_< float > >::iterator

      self: std::vector< cv::Point2f > *

   capacity(self) -> std::vector< cv::Point_< float > >::size_type

      self: std::vector< cv::Point2f > const *

   clear(self)

      self: std::vector< cv::Point2f > *

   empty(self) -> bool

      self: std::vector< cv::Point2f > const *

   end(self) -> std::vector< cv::Point_< float > >::iterator

      self: std::vector< cv::Point2f > *

   erase(self, pos) -> std::vector< cv::Point_< float > >::iterator

      pos: std::vector< cv::Point_< float > >::iterator

      erase(self, first, last) -> std::vector< cv::Point_< float >
      >::iterator

      first: std::vector< cv::Point_< float > >::iterator last:
      std::vector< cv::Point_< float > >::iterator

   front(self) -> _Point__float

      self: std::vector< cv::Point2f > const *

   get_allocator(self) -> std::vector< cv::Point_< float > >::allocator_type

      self: std::vector< cv::Point2f > const *

   insert(self, pos, x) -> std::vector< cv::Point_< float > >::iterator

      pos: std::vector< cv::Point_< float > >::iterator x:
      std::vector< cv::Point_< float > >::value_type const &

      insert(self, pos, n, x)

      pos: std::vector< cv::Point_< float > >::iterator n:
      std::vector< cv::Point_< float > >::size_type x: std::vector<
      cv::Point_< float > >::value_type const &

   iterator(self) -> SwigPyIterator

      self: std::vector< cv::Point2f > *

   pop(self) -> _Point__float

      self: std::vector< cv::Point2f > *

   pop_back(self)

      self: std::vector< cv::Point2f > *

   push_back(self, x)

      x: std::vector< cv::Point_< float > >::value_type const &

   rbegin(self) -> std::vector< cv::Point_< float > >::reverse_iterator

      self: std::vector< cv::Point2f > *

   rend(self) -> std::vector< cv::Point_< float > >::reverse_iterator

      self: std::vector< cv::Point2f > *

   reserve(self, n)

      n: std::vector< cv::Point_< float > >::size_type

   resize(self, new_size)

      new_size: std::vector< cv::Point_< float > >::size_type

      resize(self, new_size, x)

      new_size: std::vector< cv::Point_< float > >::size_type x:
      std::vector< cv::Point_< float > >::value_type const &

   size(self) -> std::vector< cv::Point_< float > >::size_type

      self: std::vector< cv::Point2f > const *

   swap(self, v)

      v: std::vector< cv::Point2f > &

   thisown

      The membership flag

class pagexml.cvSize2iVector(*args)

   Bases: "object"

   Proxy of C++ std::vector<(cv::Size2i)> class.

   append(self, x)

      x: std::vector< cv::Size_< int > >::value_type const &

   assign(self, n, x)

      n: std::vector< cv::Size_< int > >::size_type x: std::vector<
      cv::Size_< int > >::value_type const &

   back(self) -> _Size__int

      self: std::vector< cv::Size2i > const *

   begin(self) -> std::vector< cv::Size_< int > >::iterator

      self: std::vector< cv::Size2i > *

   capacity(self) -> std::vector< cv::Size_< int > >::size_type

      self: std::vector< cv::Size2i > const *

   clear(self)

      self: std::vector< cv::Size2i > *

   empty(self) -> bool

      self: std::vector< cv::Size2i > const *

   end(self) -> std::vector< cv::Size_< int > >::iterator

      self: std::vector< cv::Size2i > *

   erase(self, pos) -> std::vector< cv::Size_< int > >::iterator

      pos: std::vector< cv::Size_< int > >::iterator

      erase(self, first, last) -> std::vector< cv::Size_< int >
      >::iterator

      first: std::vector< cv::Size_< int > >::iterator last:
      std::vector< cv::Size_< int > >::iterator

   front(self) -> _Size__int

      self: std::vector< cv::Size2i > const *

   get_allocator(self) -> std::vector< cv::Size_< int > >::allocator_type

      self: std::vector< cv::Size2i > const *

   insert(self, pos, x) -> std::vector< cv::Size_< int > >::iterator

      pos: std::vector< cv::Size_< int > >::iterator x: std::vector<
      cv::Size_< int > >::value_type const &

      insert(self, pos, n, x)

      pos: std::vector< cv::Size_< int > >::iterator n: std::vector<
      cv::Size_< int > >::size_type x: std::vector< cv::Size_< int >
      >::value_type const &

   iterator(self) -> SwigPyIterator

      self: std::vector< cv::Size2i > *

   pop(self) -> _Size__int

      self: std::vector< cv::Size2i > *

   pop_back(self)

      self: std::vector< cv::Size2i > *

   push_back(self, x)

      x: std::vector< cv::Size_< int > >::value_type const &

   rbegin(self) -> std::vector< cv::Size_< int > >::reverse_iterator

      self: std::vector< cv::Size2i > *

   rend(self) -> std::vector< cv::Size_< int > >::reverse_iterator

      self: std::vector< cv::Size2i > *

   reserve(self, n)

      n: std::vector< cv::Size_< int > >::size_type

   resize(self, new_size)

      new_size: std::vector< cv::Size_< int > >::size_type

      resize(self, new_size, x)

      new_size: std::vector< cv::Size_< int > >::size_type x:
      std::vector< cv::Size_< int > >::value_type const &

   size(self) -> std::vector< cv::Size_< int > >::size_type

      self: std::vector< cv::Size2i > const *

   swap(self, v)

      v: std::vector< cv::Size2i > &

   thisown

      The membership flag

class pagexml.ptr_double

   Bases: "object"

   Proxy of C++ ptr_double class.

   assign(self, value)

      value: double

   cast(self) -> double *

      self: ptr_double *

   static frompointer(t) -> ptr_double

      t: double *

   thisown

      The membership flag

   value(self) -> double

      self: ptr_double *

pagexml.ptr_double_frompointer(t) -> ptr_double

   t: double *

class pagexml.xmlNodePtrVector(*args)

   Bases: "object"

   Proxy of C++ std::vector<(p.xmlNode)> class.

   append(self, x)

      x: std::vector< xmlNode * >::value_type

   assign(self, n, x)

      n: std::vector< xmlNode * >::size_type x: std::vector< xmlNode *
      >::value_type

   back(self) -> std::vector< xmlNode * >::value_type

      self: std::vector< xmlNode * > const *

   begin(self) -> std::vector< xmlNode * >::iterator

      self: std::vector< xmlNode * > *

   capacity(self) -> std::vector< xmlNode * >::size_type

      self: std::vector< xmlNode * > const *

   clear(self)

      self: std::vector< xmlNode * > *

   empty(self) -> bool

      self: std::vector< xmlNode * > const *

   end(self) -> std::vector< xmlNode * >::iterator

      self: std::vector< xmlNode * > *

   erase(self, pos) -> std::vector< xmlNode * >::iterator

      pos: std::vector< xmlNode * >::iterator

      erase(self, first, last) -> std::vector< xmlNode * >::iterator

      first: std::vector< xmlNode * >::iterator last: std::vector<
      xmlNode * >::iterator

   front(self) -> std::vector< xmlNode * >::value_type

      self: std::vector< xmlNode * > const *

   get_allocator(self) -> std::vector< xmlNode * >::allocator_type

      self: std::vector< xmlNode * > const *

   insert(self, pos, x) -> std::vector< xmlNode * >::iterator

      pos: std::vector< xmlNode * >::iterator x: std::vector< xmlNode
      * >::value_type

      insert(self, pos, n, x)

      pos: std::vector< xmlNode * >::iterator n: std::vector< xmlNode
      * >::size_type x: std::vector< xmlNode * >::value_type

   iterator(self) -> SwigPyIterator

      self: std::vector< xmlNode * > *

   pop(self) -> std::vector< xmlNode * >::value_type

      self: std::vector< xmlNode * > *

   pop_back(self)

      self: std::vector< xmlNode * > *

   push_back(self, x)

      x: std::vector< xmlNode * >::value_type

   rbegin(self) -> std::vector< xmlNode * >::reverse_iterator

      self: std::vector< xmlNode * > *

   rend(self) -> std::vector< xmlNode * >::reverse_iterator

      self: std::vector< xmlNode * > *

   reserve(self, n)

      n: std::vector< xmlNode * >::size_type

   resize(self, new_size)

      new_size: std::vector< xmlNode * >::size_type

      resize(self, new_size, x)

      new_size: std::vector< xmlNode * >::size_type x: std::vector<
      xmlNode * >::value_type

   size(self) -> std::vector< xmlNode * >::size_type

      self: std::vector< xmlNode * > const *

   swap(self, v)

      v: std::vector< xmlNode * > &

   thisown

      The membership flag
