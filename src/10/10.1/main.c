#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include "change-base.h"

// Base conversion
int main(int argc, char** argv) {
  uint8_t res[64], num[64];
  uint8_t from = 0, to = 0;

  char raw[65];
  raw[0] = '\n';

  while (raw[0] == '\n') {
    printf("Please enter a number: ");
    if (fgets(raw, sizeof raw, stdin) == NULL) {
      printf("\n");
      return 0;
    }
  }

  for (size_t n = 0; n < 64; n++) num[n] = 0;

  for (size_t n = 0; n < 64; n++) {
    if (raw[n] == '\n' || raw[n] == 0) break;
    if (raw[n] < '0' || raw[n] > '9') {
      printf("Invalid number!");
      return 1;
    }
    num[n] = (uint8_t)(raw[n] - '0');
  }

  printf("What base is the number you just entered (2-10)? ");
  int scanf_res = 0;
  while (scanf_res == 0) {
    scanf_res = scanf("%" SCNu8, &from);
    if (scanf_res == EOF) {
      printf("\n");
      return 0;
    }
  }

  printf("What base do you want to convert it to (2-10)? ");
  scanf_res = 0;
  while (scanf_res == 0) {
    scanf_res = scanf("%" SCNu8, &to);
    if (scanf_res == EOF) {
      printf("\n");
      return 0;
    } else if (scanf_res == 0 || to <= 1 || to > 10) {
      printf("This isn't a valid number!\n");
    }
  }

  size_t max_index = change_base(num, from, to, res);

  if (max_index != (size_t)(-1)) {
    printf("Your modified number is: ");
    for (size_t n = max_index; n != (size_t)(-1); n--) {
      printf("%c", res[n] + '0');
    }
    printf("\n");
  } else {
    printf("Couldn't change base: this is likely due to an overflow.\n");
  }

  return 0;
}
