#include <stdbool.h>
#include "insertion-sort.h"

void insertion_sort(int* array, const size_t length) {
  int* buffer = (int*)malloc(length * sizeof(int));
  size_t target_len = 1; // populated by the first element, already present
  for (size_t n = 0; n < length; n++) {
    buffer[n] = array[n];
  }
  for (size_t buffer_pos = 1; buffer_pos < length; buffer_pos++) {
    int current = buffer[buffer_pos];
    bool inserted = false;
    for (size_t n = 0; n < target_len; n++) {
      if (array[n] >= current) {
        // shift and insert
        for (size_t o = target_len + 1; o > n; o--) {
          array[o] = array[o - 1];
        }
        array[n] = current;
        target_len++;
        inserted = true;
        break;
      }
    }
    if (!inserted) {
      // push at the end
      array[target_len] = current;
      target_len++;
    }
  }
  free(buffer);
}
