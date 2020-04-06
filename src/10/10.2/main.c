#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "complex.h"

// cf. 5.8
#ifndef M_PI
  #define M_PI 3.14159265358979323846
#endif

// Complex numbers
int main(int argc, char** argv) {
  int scanf_res = 0;
  double x = 0, y = 0, r = 0, theta = 0;
  do {
    printf("Please enter the coordinates, separated by a space: ");
    scanf_res = scanf("%lf %lf", &x, &y);
    if (scanf_res == EOF) {
      printf("\n");
      return 0;
    } else if (scanf_res != 2) {
      printf("Invalid coordinates! Make sure you entered the numbers right.\n");
    }
  } while (scanf_res != 2);

  cartesian_to_polar(x, y, &r, &theta);

  printf("%lf%+lfi = %lf*e^(%lfi)\n", x, y, r, theta);
  printf("θ = %lf°\n", theta * 180 / M_PI);

  return 0;
}
