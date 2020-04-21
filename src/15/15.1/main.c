#include <stdlib.h>
#include <stdio.h>
#include "vec3.h"

int main(int argc, char* argv[]) {
  struct vec3_t a;
  struct vec3_t b;
  a.x = 1.0;
  a.y = -2.0;
  a.z = 0.0;
  b.x = 4.0;
  b.y = 0.0;
  b.z = 0.0;

  struct vec3_t sum = vec3_add(a, b);
  float dot = vec3_dot(a, b);
  struct vec3_t cross = vec3_cross(a, b);
  printf("a = (%.1f, %.1f, %.1f)\n", a.x, a.y, a.z);
  printf("b = (%.1f, %.1f, %.1f)\n", b.x, b.y, b.z);
  printf("a + b = (%.1f, %.1f, %.1f)\n", sum.x, sum.y, sum.z);
  printf("a * b = %.1f\n", dot);
  printf("a x b = (%.1f, %.1f, %.1f)\n", cross.x, cross.y, cross.z);

  return 0;
}
