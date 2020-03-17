#include <stdlib.h>
#include <stdio.h>

// Tasked to execute the following program
// Note that the original exercise did not have any type cast, etc.
int main(int argc, char* argv[]) {
  int a, b;
  float x, y, z;
  a = 2;
  b = 9;
  a = b / a; // a = 4
  x = (float)(a + b % a); // x = 5.0
  y = (float)b + x / 4; // y = 10.25
  z = x - y; // z = -5.25
  printf("x = %.2f\n", x);
  printf("y = %.2f\n", y);
  printf("z = %.2f\n", z);

  return 0;
}
