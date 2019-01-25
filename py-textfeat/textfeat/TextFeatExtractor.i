%module textfeat

%feature("autodoc", "2");

%include "cpointer.i"
%include "typemaps.i"
%include "std_vector.i"
%include "std_string.i"
%include "exception.i"

//%define PageImage Magick::Image
//%define PageImage cv::Mat
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

%pointer_class(float, ptr_float);

%{
#include "TextFeatExtractor.h"
%}

%include "TextFeatExtractor.h"
