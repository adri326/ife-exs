#include <stdbool.h>
#include "extrema.h"

size_t find_minimum(const uint8_t* array, const size_t length) {
  size_t res = 0;
  uint8_t min = 255;
  for (size_t n = 0; n < length; n++) {
    if (array[n] < min) {
      min = array[n];
      res = n;
    }
  }
  return res;
}

size_t find_maximum(const uint8_t* array, const size_t length) {
  size_t res = 0;
  uint8_t max = 0;
  for (size_t n = 0; n < length; n++) {
    if (array[n] > max) {
      max = array[n];
      res = n;
    }
  }
  return res;
}
