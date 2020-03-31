#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

size_t n_occurences(const int* array, const size_t length, const int needle);

#define ARR_LEN 5

// Counts the number of occurences of an item in an unsorted array
int main(int argc, char** argv) {
  const int arr[ARR_LEN] = {1, 5, 4, 2, 4};
  printf("Array is [%d, %d, %d, %d, %d].\n", arr[0], arr[1], arr[2], arr[3], arr[4]);

  for (int n = 0; n <= ARR_LEN; n++) {
    printf("%d occurs %zu times in the array.\n", n, n_occurences(arr, ARR_LEN, n));
  }
}

size_t n_occurences(const int* array, const size_t length, const int needle) {
  size_t sum = 0;
  for (size_t i = 0; i < length; i++) {
    if (array[i] == needle) {
      sum++;
    }
  }
  return sum;
}
