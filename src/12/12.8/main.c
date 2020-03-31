#include <stdlib.h>
#include <stdio.h>
#include "bubble-sort.h"

#define ARR_LEN 5

// Counts the number of occurences of an item in an unsorted array
int main(int argc, char** argv) {
  int arr[ARR_LEN] = {1, 5, 4, 2, 4};
  printf("Array is [%d, %d, %d, %d, %d].\n", arr[0], arr[1], arr[2], arr[3], arr[4]);

  bubble_sort(arr, ARR_LEN);

  printf("The sorted array is [%d, %d, %d, %d, %d].\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
}
