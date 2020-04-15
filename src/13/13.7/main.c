#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>
#include <string.h>
#include <ctype.h>

/** Asks the user for a word of at least `min_len` letters; returns false if no word was entered,
* @param word_res - Where to put the entered word
* @param min_len - The minimum length of a word
* @param max_len - The maximum length of a word
* @returns - False if no word was entered
*/
bool ask_word(char* word_res, const size_t min_len, const size_t max_len);

/** Counts the letter usage throughout `word` (does not differentiate between lower-range ASCII codes and UTF-8 codepoints)
* @param letter_counts - The array that will count the letters; not initialized
* @param word - The word to process
*/
void count_letters(uint32_t letter_counts[26], const char* word);
uint32_t max_count(const uint32_t letter_counts[26]);

// Most used letters in a set of words
int main(int argc, char** argv) {
  char word[1024];
  uint32_t letter_counts[26];

  for (size_t n = 0; n < 26; n++) letter_counts[n] = 0;

  while (ask_word(word, 6, sizeof word)) {
    count_letters(letter_counts, word);
  }

  uint32_t max = max_count(letter_counts);

  printf("The most used letters are ");
  for (size_t n = 0; n < 26; n++) {
    if (letter_counts[n] == max) printf("%c ", 'A' + (char)n);
  }
  printf("\nEach are used %" PRIu32 " times.\n", max);

  return 0;
}

bool ask_word(char* word_res, const size_t min_len, const size_t max_len) {
  do {
    printf("Please enter a word of at least %zu letters: ", min_len);
    fgets(word_res, (int)max_len, stdin);
    if (word_res[0] == '\n') break;
    if (strlen(word_res) - 1 < min_len) {
      printf("Your word is too small!\n");
    }
  } while (strlen(word_res) - 1 < min_len);

  for (size_t n = 0; n < max_len && word_res[n] != 0 && word_res[n] != '\n'; n++) {
    word_res[n] = (char)toupper(word_res[n]);
  }

  return word_res[0] != '\n';
}

void count_letters(uint32_t letter_counts[26], const char* word) {
  for (size_t n = 0; word[n]; n++) {
    if (word[n] >= 'A' && word[n] <= 'Z') {
      letter_counts[word[n] - 'A']++;
    }
  }
}

uint32_t max_count(const uint32_t letter_counts[26]) {
  uint32_t max = letter_counts[0];
  for (size_t n = 0; n < 26; n++) {
    if (letter_counts[n] > max) max = letter_counts[n];
  }
  return max;
}
