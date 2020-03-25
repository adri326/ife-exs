#include <stdlib.h>
#include <stdio.h>
#include "p2c.h"

// polar to cartesian complex conversion
int main(int argc, char** argv) {
  double r = 0.0, theta = 0.0, x = 0.0, y = 0.0;
  int scanf_res = 0;
  while (scanf_res < 2) {
    printf("Please enter the modulo and argument of your complex number, separated by a space: ");
    scanf_res = scanf("%lf %lf", &r, &theta);
    if (scanf_res == EOF) {
      printf("\n");
      return 0;
    } else if (scanf_res < 2 || r < 0) {
      printf("Invalid input!\n");
      scanf("%*[^\n]");
    }
  }

  polar_to_cartesian(r, theta, &x, &y);

  printf("%lfe^(%lfi) = %lf%+lfi\n", r, theta, x, y);

  return 0;
}
