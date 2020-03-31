#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARR_LEN 5
// The exercise did not make any grammatical sense
// I assumed that we were tasked to find a specific item in a sorted array

bool is_in_array(const int* hay, const size_t length, const int needle);

int main(int argc, char** argv) {
  const int arr[ARR_LEN] = {1, 2, 4, 4, 5};
  printf("Array is [%d, %d, %d, %d, %d].\n", arr[0], arr[1], arr[2], arr[3], arr[4]);

  for (int n = 1; n <= 5; n++) {
    if (is_in_array(arr, ARR_LEN, n)) {
      printf("%d is in the array.\n", n);
    } else {
      printf("%d is not in the array.\n", n);
    }
  }

  return 0;
}

bool is_in_array(const int* hay, const size_t length, const int needle) {
  for (size_t n = 0; n < length; n++) {
    if (hay[n] == needle) return true;
    else if (hay[n] > needle) return false;
  }
  return false;
}
