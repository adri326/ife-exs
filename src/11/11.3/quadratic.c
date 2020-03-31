#include <stdlib.h>
#include <math.h>
#include "quadratic.h"

void solve_quad(const float a, const float b, const float c, uint8_t* n, float* x1, float* x2) {
  const float delta = b * b - 4 * a * c;
  if (delta < 0) {
    *n = 0;
    *x1 = *x2 = 0; // prevent UB
  } else if (delta > 0) {
    *n = 2;
    *x1 = (-b + sqrt(delta)) / 2;
    *x2 = (-b - sqrt(delta)) / 2;
  } else {
    *n = 1;
    *x1 = *x2 = -b / 2 / a;
  }
}
