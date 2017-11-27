%module pagexml

%include "cpointer.i"
%include "typemaps.i"
%include "std_vector.i"
%include "std_string.i"
%include "exception.i"

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

%include "PageXML.h"
