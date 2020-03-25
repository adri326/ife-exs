#include "p2c.h"
#include <math.h>

void polar_to_cartesian(double r, double theta, double* x, double* y) {
  *x = r * cos(theta);
  *y = r * sin(theta);
}
