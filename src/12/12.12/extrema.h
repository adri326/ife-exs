#ifndef EXTREMA_H
#define EXTREMA_H

#include <stdlib.h>
#include <inttypes.h>

/** Finds the index of the minimum value in an array
* @param array - The array to scan through
* @param length - The length of the array
* @returns The index of the minimum value in the array
*/
size_t find_minimum(const uint8_t* array, const size_t length);

/** Finds the index of the maximum value in an array
* @param array - The array to scan through
* @param length - The length of the array
* @returns The index of the maximum value in the array
*/
size_t find_maximum(const uint8_t* array, const size_t length);

#endif // EXTREMA_H
