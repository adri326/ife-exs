#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include "bubble-sort.h"


void bubble_sort(int* array, const size_t length) {
  for (size_t a = 1; a <= length; a++) {
    bool sorted = true;
    for (size_t n = 0; n < length - a; n++) {
      if (array[n] > array[n + 1]) {
        const int tmp = array[n];
        sorted = false;
        array[n] = array[n + 1];
        array[n + 1] = tmp;
      }
    }
    if (sorted) return;
  }
}
