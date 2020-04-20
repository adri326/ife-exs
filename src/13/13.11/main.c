#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <inttypes.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "display.h"
#include "verify.h"

#define N_WORDS 21
#define WORD_LEN 16

const static char WORDS[N_WORDS][WORD_LEN] = {
  // https://www.youtube.com/watch?v=cn4M-fH08XY
  "PROTECTION",
  "CREATION",
  "INITIALISATION",
  "SIMULATION",
  "DIMENSION",
  "CIRCUMFERENCE",
  "TANGENTS",
  "LIMITATIONS",
  "SATISFACTION",
  "NUTRIENTS",
  "ANTIOXIDANTS",
  "ENJOYMENT",
  "EXISTENCE",
  "VIBRATIONS",
  "COMPLETION",
  "ISOLATION",
  "FRAGMENTS",
  "DISHEARTENED",
  "ARGUMENTS",
  "EXECUTION",
  "LOVE"
};

// Game of the hanging man
int main(int argc, char* argv[]) {
  srand((unsigned int)time(0));
  const char* word = WORDS[rand() % N_WORDS];
  char attempted_letters[27] = "";
  uint8_t n_errs = 0;

  display(word, attempted_letters, n_errs);

  do {
    char attempt[1024];
    if (fgets(attempt, sizeof attempt, stdin) == NULL) return 1;

    if (attempt[0] == '\n');
    else if (attempt[1] == '\n') { // single letter
      propose_letter(word, attempted_letters, (char)toupper(attempt[0]), &n_errs);
    } else { // entire word
      char* ret_pos = strchr(attempt, '\n');
      if (ret_pos != NULL) *ret_pos = 0;
      if (strncmp(word, attempt, WORD_LEN) == 0) {
        break;
      } else {
        n_errs++;
      }
    }

    clear();
    display(word, attempted_letters, n_errs);
  } while (n_errs < 7 && !is_complete(word, attempted_letters));

  if (n_errs < 7) {
    printf("\nCongratulations! You won!\n");
  } else {
    printf("\nYou lost...\n");
  }
}
