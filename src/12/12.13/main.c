#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>

#define ARR_LEN 25

void selection_sort(int* array, const size_t length);

// Selection sort
int main(int argc, char** argv) {
  int arr[ARR_LEN];

  srand((unsigned int)time(0));

  for (size_t n = 0; n < ARR_LEN; n++) {
    arr[n] = rand() % ARR_LEN;
  }

  selection_sort(arr, ARR_LEN);

  for (size_t n = 0; n < ARR_LEN; n++) {
    printf("%d\n", arr[n]);
  }

  return 0;
}

void selection_sort(int* array, const size_t length) {
  // n is the number of items already processed
  for (size_t n = 0; n < length - 1; n++) {
    size_t pos = n;
    int min = INT_MAX;
    // find the minimum in the [o; length]-part of the array
    for (size_t o = n; o < length; o++) {
      if (array[o] < min) {
        min = array[o];
        pos = o;
      }
    }
    // swap `pos` and `n`
    const int tmp = array[n];
    array[n] = array[pos];
    array[pos] = tmp;
  }
}
