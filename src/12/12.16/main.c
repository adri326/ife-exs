#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define N_DRAWS 6

/** Draws `length` unique random numbers within [0; max)
* Complexity: Ω(length^2)
* Does not store and shift an array of the numbers from 0 to max, but insteads scans back the array of already picked numbers
* @param array - The array to put the numbers in
* @param length - The length of the array
* @param min - The minimum value for the random numbers
* @param max - The maximum value for the random numbers
*/
void draw_uniques(int* array, const size_t length, const int min, const int max);

// Lotto, by the old rules
int main(int argc, char** argv) {
  int draws[N_DRAWS];
  srand((unsigned int)time(0));

  draw_uniques(draws, N_DRAWS, 1, 50);

  for (size_t n = 0; n < N_DRAWS; n++) {
    printf("%d\n", draws[n]);
  }
}

void draw_uniques(int* array, const size_t length, const int min, const int max) {
  for (size_t n = 0; n < length; n++) {
    array[n] = rand() % (max - min) + min;
    for (size_t o = 0; o < n; o++) {
      if (array[o] == array[n]) {
        // Decrement and loop over
        n--;
        break;
      }
    }
  }
}
