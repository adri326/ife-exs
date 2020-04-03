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
      printf("%-*d ", num_width, array[n]); // `num_width`-character-wide number aligned to the left
    }
    printf("\n");
  }
}

size_t input_nums(const int* array, const size_t length) {
  int* guesses = (int*)malloc(sizeof(int) * length);
  size_t n_guesses = 0;

  while (n_guesses < length) {
    char input[1024];
    int guess = -1;

    printf(ANSI_COLOR_CYAN "> " ANSI_COLOR_NONE);

    // EOF
    if (!fgets(input, 1024, stdin)) {
      free(guesses);
      return n_guesses;
    }

    // Empty line: finish input
    if (input[0] == '\n') {
      free(guesses);
      return n_guesses;
    }

    if (!sscanf(input, "%d", &guess)) {
      printf(ANSI_COLOR_RED "Invalid number!\n" ANSI_COLOR_NONE);
    } else {
      // The number is valid; we check if the number wasn't already inputed
      bool valid = false;

      for (size_t n = 0; n < length; n++) {
        if (array[n] == guess) {
          valid = true;
          break;
        }
      }

      if (!valid) {
        printf(ANSI_COLOR_RED "This is not a number of the list!\n" ANSI_COLOR_NONE);
        continue;
      }

      for (size_t n = 0; n < n_guesses; n++) {
        if (guesses[n] == guess) {
          printf(ANSI_COLOR_RED "You already told me this number!\n" ANSI_COLOR_NONE);
          valid = false; // don't add the number
          break;
        }
      }

      if (valid) {
        guesses[n_guesses++] = guess;
        printf(ANSI_COLOR_GREEN "Good job! %zu numbers to go.\n" ANSI_COLOR_NONE, length - n_guesses);
      }
    }
  }

  free(guesses);
  return n_guesses;
}
