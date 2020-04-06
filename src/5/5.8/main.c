#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// math.h is required *not* to define M_PI, thus we have to define it ourselves if the compiler does not define it already
#ifndef M_PI
  #define M_PI 3.14159265358979323846
#endif

// Seconds into hours, minutes and seconds
int main(int argc, char* argv[]) {
  float r;
  printf("r = ");
  scanf("%f", &r);

  printf("V = %f m³\n", r * r * r * 4.0f / 3.0f * M_PI);
  printf("S = %f m²\n", r * r * 4.0f * M_PI);

  return 0;
}
