#include <string.h>
#include "verify.h"

void propose_letter(const char* word, char attempted_letters[27], char attempt, uint8_t* n_errs) {
  if (attempt < 'A' || attempt > 'Z') return;
  if (strchr(attempted_letters, attempt) != NULL) return;
  char attempt_str[2] = {attempt, 0};
  strcat(attempted_letters, attempt_str);
  if (strchr(word, attempt) == NULL) {
    *n_errs += 1;
  }
}

bool is_complete(const char* word, char attempted_letters[27]) {
  for (size_t n = 0; word[n]; n++) {
    if (strchr(attempted_letters, word[n]) == NULL) return false;
  }
  return true;
}
