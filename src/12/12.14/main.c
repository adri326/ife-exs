#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#ifdef _WIN32
  #include <windows.h>
  #define IS_WIN
#endif
#ifdef _WIN64
  #include <windows.h>
  #define IS_WIN
#endif

#ifdef linux
  #include <unistd.h>
#endif

#include "display.h"

#define N_NUMS 10
#define MAX_NUM 10000
#define NUMS_PER_LINE 5
#define NUM_WIDTH 6
#define DURATION 10

void gen_unique_numbers(int* array, const size_t length, const int from, const int to);

// Memorizing game
int main(int argc, char** argv) {
  int nums[N_NUMS];
  char input[1024];

  srand((unsigned int)time(0));

  gen_unique_numbers(nums, N_NUMS, 0, MAX_NUM);

  // Print the welcoming message and ask the user to press `ENTER` when ready
  welcome_message(N_NUMS, DURATION);
  printf("Press " ANSI_COLOR_CYAN "ENTER" ANSI_COLOR_NONE " to start! ");
  fgets(input, 1024, stdin);

  // print the numbers
  printf("\n");
  print_nums(nums, N_NUMS, NUMS_PER_LINE, NUM_WIDTH);

  // Sleep `DURATION` seconds
#ifdef linux
  sleep(DURATION);
#endif
#ifdef IS_WIN
  Sleep(DURATION * 1000);
#endif

  // Clear up the lines (will only work with NO_COLOR=false)
  for (size_t n = 0; n <= N_NUMS / NUMS_PER_LINE; n++) {
    printf(ANSI_UP ANSI_CLEAR_LINE);
  }
  printf("\n");
  printf("Time for you to write as many of these numbers back:\n\n");

  // Ask the user to give back numbers
  size_t n_valid = input_nums(nums, N_NUMS);

  // Congratulation message
  printf("\n");
  printf("You managed to memorize " ANSI_COLOR_GREEN "%zu" ANSI_COLOR_NONE " of the " ANSI_COLOR_CYAN "%d" ANSI_COLOR_NONE " numbers!\n", n_valid, N_NUMS);

  return 0;
}

void gen_unique_numbers(int* array, const size_t length, const int from, const int to) {
  for (size_t n = 0; n < length; n++) {
    array[n] = rand() % (to - from) + from;
    for (size_t o = 0; o < n; o++) {
      if (array[o] == array[n]) {
        // decremented to loop again
        n--;
        break;
      }
    }
  }
}
