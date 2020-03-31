#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <sys/time.h>

#define ARR_LEN 200

int minimum(const int* array, const size_t length);
int maximum(const int* array, const size_t length);
size_t n_occurences(const int* array, const size_t length, const int needle);

// Generate a random array and count the number of occurences of the minimum and maximum
int main(int argc, char** argv) {
  struct timeval tv;
  gettimeofday(&tv, NULL);

  int arr[ARR_LEN];
  srand((unsigned int)tv.tv_sec);
  for (size_t n = 0; n < ARR_LEN; n++) {
    arr[n] = rand() % 21;
  }

  int min = minimum(arr, ARR_LEN);
  int max = maximum(arr, ARR_LEN);
  printf("The minimum is %d and it occurs %zu times.\n", min, n_occurences(arr, ARR_LEN, min));
  printf("The maximum is %d and it occurs %zu times.\n", max, n_occurences(arr, ARR_LEN, max));

  return 0;
}

int minimum(const int* array, const size_t length) {
  int min = INT_MAX;
  for (size_t n = 0; n < length; n++) {
    if (array[n] < min) min = array[n];
  }
  return min;
}

int maximum(const int* array, const size_t length) {
  int max = INT_MIN;
  for (size_t n = 0; n < length; n++) {
    if (array[n] > max) max = array[n];
  }
  return max;
}

size_t n_occurences(const int* array, const size_t length, const int needle) {
  size_t res = 0;
  for (size_t n = 0; n < length; n++) {
    if (array[n] == needle) res++;
  }
  return res;
}
