#include <stdlib.h>
#include <stdio.h>

// Rotate three floating-point numbers
int main(int argc, char* argv[]) {
  float a = 0.2;
  float b = 0.6;
  float c = -1.2;

  {
    float d = c;
    c = b;
    b = a;
    a = d;
  }
  printf("%.2f, %.2f, %.2f\n", a, b, c);

  return 0;
}
