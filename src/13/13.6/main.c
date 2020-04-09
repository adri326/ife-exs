#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Vertically displaying two words
int main(int argc, char** argv) {
  char word_a[1024];
  char word_b[1024];
  printf("Please input two words to be displayed vertically:\n");

  do {
    printf("> ");
    if (fgets(word_a, sizeof word_a, stdin) == NULL) return 1;
  } while (word_a[0] == '\n');
  do {
    printf("> ");
    if (fgets(word_b, sizeof word_b, stdin) == NULL) return 1;
  } while (word_b[0] == '\n');

  bool keep_printing_a = true;
  bool keep_printing_b = true;
  size_t n = 0;
  do {
    if (keep_printing_a) {
      if (word_a[n] != 0 && word_a[n] != '\n') printf("%c ", word_a[n]);
      else keep_printing_a = false;
    } else {
      printf("  ");
    }

    if (keep_printing_b) {
      if (word_b[n] != 0 && word_b[n] != '\n') printf("%c", word_b[n]);
      else keep_printing_b = false;
    }

    printf("\n");
    n++;
  } while (keep_printing_a || keep_printing_b);

  return 0;
}
