#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include "quadratic.h"

int main(int argc, char** argv) {
  float a = 0.0, b = 0.0, c = 0.0;
  int scanf_res = 0;
  while (scanf_res < 3) {
    printf("Please enter the three quadratic arguments separated by a space: ");
    scanf_res = scanf("%f %f %f", &a, &b, &c);
    if (scanf_res == EOF) {
      printf("\n");
      return 0;
    } else if (scanf_res != 3) {
      printf("Invalid input!\n");
      scanf("%*[^\n]");
    }
  }
  uint8_t n;
  float x1, x2;
  printf("Equation: %fx^2%+fx%+f = 0\n", a, b, c);
  solve_quad(a, b, c, &n, &x1, &x2);
  if (n == 0) {
    printf("No solutions!\n");
  } else if (n == 1) {
    printf("%f is the only solution.\n", x1);
  } else if (n == 2) {
    printf("%f and %f are the two solutions to this equation.\n", x1, x2);
  }

  // return 0;
}
