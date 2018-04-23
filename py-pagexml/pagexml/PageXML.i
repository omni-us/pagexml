%module pagexml

%include "cpointer.i"
%include "typemaps.i"
%include "std_vector.i"
%include "std_string.i"
%include "exception.i"

%include "opencv.i"
%cv_mat__instantiate_defaults
%cv_point_instantiate_defaults

%define PageImage cv::Mat
%enddef

%define __PAGEXML_OGR__
%enddef

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

%pointer_class(double, ptr_double);

%template(cvPoint2fVector) std::vector<cv::Point2f>;
%template(xmlNodePtrVector) std::vector<xmlNode*>;

%include "PageXML.h"
