#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Seconds into hours, minutes and seconds
int main(int argc, char* argv[]) {
  float r;
  printf("r = ");
  scanf("%f", &r);

  printf("V = %f m³\n", r * r * r * 4.0f / 3.0f * M_PI);
  printf("S = %f m²\n", r * r * 4.0f * M_PI);

  return 0;
}
