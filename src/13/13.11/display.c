#include <stdio.h>
#include <string.h>
#include "display.h"

void display_hanging_man(const uint8_t n_errs) {
  /* full man:
  ┬──┬
  │  @
  │ /!\
  │  #
  │ / \
  │
  ▒▒▒▒▒▒▒
  */
  if (n_errs < 7) {
    printf(
      " ┬──┬  \n"
      " │  %s  \n"
      " │ %s \n"
      " │  %s  \n"
      " │ %s \n"
      " │     \n"
      ANSI_COLOR_GREEN "▒▒▒▒▒▒▒" ANSI_COLOR_NONE "\n",
      n_errs >= 1 ? ANSI_COLOR_YELLOW "@" ANSI_COLOR_NONE : " ",
      n_errs == 2 ? ANSI_COLOR_YELLOW " ! " ANSI_COLOR_NONE :
        (n_errs == 3 ? ANSI_COLOR_YELLOW "/! " ANSI_COLOR_NONE :
        (n_errs >= 4 ? ANSI_COLOR_YELLOW "/!\\" ANSI_COLOR_NONE :
        " ")),
      n_errs >= 5 ? ANSI_COLOR_YELLOW "#" ANSI_COLOR_NONE : " ",
      n_errs == 6 ? ANSI_COLOR_YELLOW "/  " ANSI_COLOR_NONE :
        (n_errs >= 7 ? ANSI_COLOR_YELLOW "/ \\" ANSI_COLOR_NONE :
        " ")
    );
  } else {
    printf(
      " ┬──┬\n"
      " │  " ANSI_COLOR_RED "@" ANSI_COLOR_NONE "\n"
      " │ " ANSI_COLOR_RED "/!\\" ANSI_COLOR_NONE "\n"
      " │  " ANSI_COLOR_RED "#" ANSI_COLOR_NONE "\n"
      " │ " ANSI_COLOR_RED "/ \\" ANSI_COLOR_NONE "\n"
      " │\n"
      ANSI_COLOR_RED "▒▒▒▒▒▒▒" ANSI_COLOR_NONE "\n"
    );
  }
}

void display_word(const char* word, char attempted_letters[27]) {
  for (size_t n = 0; word[n]; n++) {
    if (strchr(attempted_letters, word[n]) != NULL) {
      printf("%c", word[n]);
    } else {
      printf("-");
    }
  }
  printf("\n");
}

void display(const char* word, char attempted_letters[27], const uint8_t n_errs) {
  display_hanging_man(n_errs);
  printf("\n");
  display_word(word, attempted_letters);
  printf("> ");
}

void clear() {
  for (size_t n = 0; n < HANGING_MAN_HEIGHT + 3; n++) {
    printf(ANSI_UP ANSI_CLEAR_LINE);
  }
}
