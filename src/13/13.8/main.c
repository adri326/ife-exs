#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>
#include <string.h>
#include "roman.h"

// Roman numerals to decimal number conversion
int main(int argc, char** argv) {
  char input[1024];
  printf("Please enter a roman numerals: ");
  if (fgets(input, sizeof input, stdin) == NULL) return 1;

  for (size_t n = 0; input[n] != 0 && input[n] != '\n'; n++) {
    switch (input[n]) {
      case 'I':
      case 'V':
      case 'X':
      case 'L':
      case 'C':
      case 'D':
      case 'M':
        // noop
        break;
      default:
        printf("Invalid roman number!\n");
        return 1;
    }
  }

  uint32_t res = roman_to_decimal(input, strlen(input) - 1);
  printf("%" PRIu32 "\n", res);
  return 0;
}
