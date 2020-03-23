#include "complex.h"
#include <math.h>

// Note that the exercise required edge cases to be handled. This proposed method does not have any edge case.
void cartesian_to_polar(double x, double y, double* r, double* theta) {
  *r = sqrt(x * x + y * y);
  *theta = atan2(x, y);
}
