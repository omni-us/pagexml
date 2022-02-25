%{
#include "mock_cv.h"
%}
%include "mock_cv.h"

namespace cv
{
%template(Point2f) Point_<float>;
%template(Size2i) Size_<int>;
}
