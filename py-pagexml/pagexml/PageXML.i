%module pagexml

%include "cpointer.i"
%include "typemaps.i"
%include "std_vector.i"
%include "std_string.i"

%{
#include "PageXML.h"
%}

%pointer_class(double, ptr_double);

%template(cvPoint2fVector) std::vector<cv::Point2f>;

%include "PageXML.h"
