%module swigPageXML

//%feature("autodoc", "2");
%include "PageXML_doxy2swig.i"

%include "cpointer.i"
%include "typemaps.i"
%include "std_vector.i"
%include "std_string.i"
%include "std_pair.i"
%include "exception.i"

#ifdef __PAGEXML_SLIM__
%include "mock_cv.i"
#else
%include "opencv.i"
%cv_mat__instantiate_defaults
%cv_point_instantiate_defaults
%cv_size_instantiate_defaults
#endif

//%define PageImage Magick::Image
//%define PageImage cv::Mat
//%enddef

//%define __PAGEXML_OGR__
//%enddef
//%define __PAGEXML_IMG_MAGICK__
//%define __PAGEXML_IMG_CV__
//%enddef
//%define __PAGEXML_MAGICK__
//%enddef

%exception {
  try {
    $function
  } catch(std::runtime_error const& err) {
    SWIG_exception(SWIG_RuntimeError, err.what());
  }
}

%{
#include "PageXML.h"
%}

%template(cvPoint2fVector) std::vector<cv::Point2f>;
%template(cvSize2iVector) std::vector<cv::Size2i>;
%template(xmlNodePtrVector) std::vector<xmlNode*>;
#ifndef __PAGEXML_SLIM__
%template(NamedImageVector) std::vector<NamedImage>;
#endif
%template() std::pair<std::vector<int>, std::vector<int> >;

%pointer_class(double, ptr_double);
#ifndef __PAGEXML_SLIM__
%pointer_class(std::vector<cv::Point>, ptr_cvPointVector);
#endif
%pointer_class(std::vector<cv::Point2f>, ptr_cvPoint2fVector);

%include "PageXML.h"
