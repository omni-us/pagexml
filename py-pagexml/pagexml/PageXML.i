%module swigPageXML

//%feature("autodoc", "2");
%include "PageXML_doxy2swig.i"

%include "cpointer.i"
%include "typemaps.i"
%include "std_vector.i"
%include "std_string.i"
%include "std_pair.i"
%include "exception.i"

%include "opencv.i"
%cv_mat__instantiate_defaults
%cv_point_instantiate_defaults
%cv_size_instantiate_defaults

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
  } catch(std::runtime_error err) {
    SWIG_exception(SWIG_RuntimeError, err.what());
  }
}

%{
#include "PageXML.h"
%}

%template(cvPoint2fVector) std::vector<cv::Point2f>;
%template(cvSize2iVector) std::vector<cv::Size2i>;
%template(xmlNodePtrVector) std::vector<xmlNode*>;
%template(NamedImageVector) std::vector<NamedImage>;
%template() std::pair<std::vector<int>, std::vector<int> >;

%pointer_class(double, ptr_double);
%pointer_class(std::vector<cv::Point>, ptr_cvPointVector);
%pointer_class(std::vector<cv::Point2f>, ptr_cvPoint2fVector);

%include "PageXML.h"
