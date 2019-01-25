textfeat API (version 2019.1.25)
********************************


textfeat module
===============

class textfeat.SwigPyIterator(*args, **kwargs)

   Bases: "object"

   Proxy of C++ swig::SwigPyIterator class.

   advance(self, n) -> SwigPyIterator

      n: ptrdiff_t

   copy(self) -> SwigPyIterator

      self: swig::SwigPyIterator const *

   decr(self, n=1) -> SwigPyIterator

      n: size_t

   distance(self, x) -> ptrdiff_t

      x: swig::SwigPyIterator const &

   equal(self, x) -> bool

      x: swig::SwigPyIterator const &

   incr(self, n=1) -> SwigPyIterator

      n: size_t

   next(self) -> PyObject *

      self: swig::SwigPyIterator *

   previous(self) -> PyObject *

      self: swig::SwigPyIterator *

   thisown

      The membership flag

   value(self) -> PyObject *

      self: swig::SwigPyIterator const *

class textfeat.TextFeatExtractor(*args, **kwargs)

   Bases: "object"

   Proxy of C++ TextFeatExtractor class.

   estimateAngles(self, cvimg, _slope, _slant, rotate=0.0)

      cvimg: cv::Mat & _slope: float * _slant: float * rotate: float

   extractFeats(self, feaimg, slope=0.0, slant=0.0, xheight=0, _fpgram=None, randomize=False, rotate=0.0, direction) -> cv::Mat

      feaimg: cv::Mat & slope: float slant: float xheight: int
      _fpgram: std::vector< cv::Point2f,std::allocator< cv::Point2f >
      > * randomize: bool rotate: float direction: int

   featTypes

   formatNames

   isImageFormat(self) -> bool

      self: TextFeatExtractor *

   preprocess(self, cvimg, _fcontour=None, randomize=False)

      cvimg: cv::Mat & _fcontour: std::vector<
      cv::Point,std::allocator< cv::Point > > * randomize: bool

   printConf(self, file)

      file: FILE *

   thisown

      The membership flag

   static version() -> char *

   write(self, feats, file)

      feats: cv::Mat const & file: FILE *

      write(self, feats, fname)

      feats: cv::Mat const & fname: char const *

textfeat.TextFeatExtractor_version() -> char *

class textfeat.ptr_float

   Bases: "object"

   Proxy of C++ ptr_float class.

   assign(self, value)

      value: float

   cast(self) -> float *

      self: ptr_float *

   static frompointer(t) -> ptr_float

      t: float *

   thisown

      The membership flag

   value(self) -> float

      self: ptr_float *

textfeat.ptr_float_frompointer(t) -> ptr_float

   t: float *
