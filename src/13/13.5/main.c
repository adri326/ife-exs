#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "is_present.h"

// Common letter enumerator
int main(int argc, char** argv) {
  char word_a[1024];
  char word_b[1024];
  printf("Tell me two words and I will tell you their letters in common!\n");

  do {
    printf("> ");
    if (fgets(word_a, sizeof word_a, stdin) == NULL) return 1;
  } while (word_a[0] == '\n');
  do {
    printf("> ");
    if (fgets(word_b, sizeof word_b, stdin) == NULL) return 1;
  } while (word_b[0] == '\n');

  // Compact toupper, cf. 13.1
  for (size_t n = 0; word_a[n]; n++) word_a[n] = (char)toupper(word_a[n]);
  for (size_t n = 0; word_b[n]; n++) word_b[n] = (char)toupper(word_b[n]);

  printf("These two words have in common the following letters: ");
  for (char letter = 'A'; letter <= 'Z'; letter++) {
    if (is_present(letter, word_a) && is_present(letter, word_b)) {
      printf("%c ", letter);
    }
  }
  printf("\n");
  return 0;
}
