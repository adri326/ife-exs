#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARR_LEN 5
#define F_ERR ((size_t)(-1))

// Find the index of a number in a sorted array using binary searching.
size_t binary_search(int* hay, size_t length, int needle);

int main(int argc, char** argv) {
  int arr[ARR_LEN] = {1, 2, 4, 4, 5};
  printf("Array is [%d, %d, %d, %d, %d].\n", arr[0], arr[1], arr[2], arr[3], arr[4]);

  for (int n = 1; n <= 5; n++) {
    size_t index = binary_search(arr, ARR_LEN, n);
    if (index == F_ERR) {
      printf("%d is not in the array!\n", n);
    } else {
      printf("%d is at the %zuth index of the array.\n", n, index);
    }
  }

  return 0;
}

size_t binary_search(int* hay, size_t length, int needle) {
  if (length == 0) return F_ERR;
  if (length == 1) return 0;
  if (hay[length / 2] == needle) return length / 2;
  else if (hay[length / 2] < needle) {
    size_t res = binary_search(&hay[length / 2], length - (length / 2), needle);
    if (res == F_ERR) return F_ERR;
    return length / 2 + res;
  }
  else return binary_search(hay, length / 2, needle);
}
