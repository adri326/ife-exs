#include "vec3.h"

struct vec3_t vec3_add(const struct vec3_t a, const struct vec3_t b) {
  struct vec3_t res;
  res.x = a.x + b.x;
  res.y = a.y + b.y;
  res.z = a.z + b.z;
  return res;
}

float vec3_dot(const struct vec3_t a, const struct vec3_t b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

struct vec3_t vec3_cross(const struct vec3_t a, const struct vec3_t b) {
  struct vec3_t res;
  res.x = a.y * b.z - a.z * b.y;
  res.y = a.z * b.x - a.x * b.z;
  res.z = a.x * b.y - a.y * b.x;
  return res;
}
