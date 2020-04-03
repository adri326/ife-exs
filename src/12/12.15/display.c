#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "display.h"

void welcome_message(const int n_nums, const int duration) {
  printf("Welcome to the " ANSI_COLOR_YELLOW "memory test v1.0" ANSI_COLOR_NONE "!\n\n");

  printf(
    "You will be given "
    ANSI_COLOR_CYAN "%d numbers" ANSI_COLOR_NONE
    " and " ANSI_COLOR_CYAN "%d seconds" ANSI_COLOR_NONE
    " for you to memorize them.\n",
    n_nums,
    duration
  );
}

void print_nums(
  const int* array,
  const size_t length,
  const size_t nums_per_line,
  const unsigned int num_width
) {
  for (size_t n = 0; n < length;) {
    for (size_t o = 0; o < nums_per_line && n < length; o++, n++) {
      printf(ANSI_COLOR_CYAN "%2zu" ANSI_COLOR_NONE ": %-*d ", n + 1, num_width, array[n]); // `num_width`-character-wide number aligned to the left
    }
    printf("\n");
  }
}

size_t input_nums(const int* array, const size_t length) {
  bool* guesses_done = (bool*)malloc(sizeof(bool) * length);
  for (size_t n = 0; n < length; n++) guesses_done[n] = false;
  size_t n_guesses = 0;
  size_t guesses_correct = 0;

  while (n_guesses++ < length) {
    char input[1024];
    int guess = -1;
    size_t guess_id = (size_t)rand() % length;

    // Step until we hit a false
    while (guesses_done[guess_id]) guess_id = (guess_id + 1) % length;
    guesses_done[guess_id] = true;

    printf("Please input the " ANSI_COLOR_YELLOW "%zuth" ANSI_COLOR_NONE " number:\n", guess_id + 1);

    while (true) {
      printf(ANSI_COLOR_CYAN "> " ANSI_COLOR_NONE);

      // EOF
      if (!fgets(input, 1024, stdin)) {
        free(guesses_done);
        return guesses_correct;
      }

      // Empty line: display a warning
      if (input[0] == '\n') {
        printf(ANSI_COLOR_RED "You did not put a number!\n" ANSI_COLOR_NONE);
        break;
      }

      if (!sscanf(input, "%d", &guess)) {
        printf(ANSI_COLOR_RED "Invalid number!\n" ANSI_COLOR_NONE);
        // loop again
      } else {
        break;
      }
    }

    if (guess == array[guess_id]) {
      printf(ANSI_COLOR_GREEN "Good job!\n" ANSI_COLOR_NONE);
      guesses_correct++;
    } else {
      printf(ANSI_COLOR_RED "Wrong number!\n" ANSI_COLOR_NONE);
    }
  }

  free(guesses_done);
  return guesses_correct;
}
