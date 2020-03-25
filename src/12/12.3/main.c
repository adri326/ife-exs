#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// The exercise did not make any grammatical sense
// I assumed that we were tasked to find a specific item in an array

bool is_in_array(int* hay, size_t length, int needle);

int main(int argc, char** argv) {
  int arr[5] = {2, 4, 4, 1, 5};
  printf("Array is [%d, %d, %d, %d, %d].\n", arr[0], arr[1], arr[2], arr[3], arr[4]);

  for (int n = 1; n <= 5; n++) {
    if (is_in_array(arr, sizeof arr, n)) {
      printf("%d is in the array.\n", n);
    } else {
      printf("%d is not in the array.\n", n);
    }
  }

  return 0;
}

bool is_in_array(int* hay, size_t length, int needle) {
  for (size_t n = 0; n < length; n++) {
    if (hay[n] == needle) return true;
  }
  return false;
}
