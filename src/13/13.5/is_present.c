#include <stdlib.h>
#include "is_present.h"

bool is_present(char letter, char* word) {
  size_t n = 0;
  while (word[n]) {
    if (word[n] == letter) return true;
    n++;
  }
  return false;
}
