#ifndef VEC3_H
#define VEC3_H


/** A 3-dimensional vector
* x - The X coordinate of the vector
* y - The Y coordinate of the vector
* z - The Z coordinate of the vector
**/
struct vec3_t {
  float x;
  float y;
  float z;
};

/** Computes the sum of two vectors
* @param a - Vector 1
* @param b - Vector 2
* @returns - The sum of both vectors
**/
struct vec3_t vec3_add(const struct vec3_t a, const struct vec3_t b);

/** Computes the dot product of two vectors
* @param a - Vector 1
* @param b - Vector 2
* @returns - The dot product of both vectors
**/
float vec3_dot(const struct vec3_t a, const struct vec3_t b);

/** Computes the cross product of two vectors
* @param a - Vector 1
* @param b - Vector 2
* @returns - The creoss product of both vectors
**/
struct vec3_t vec3_cross(const struct vec3_t a, const struct vec3_t b);

#endif // VEC3_H
