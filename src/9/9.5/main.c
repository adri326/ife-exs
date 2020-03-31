#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>
#include <limits.h>
#include <ctype.h>

#define N_ATTEMPTS 3

uint32_t get_number(const char* prompt, const uint32_t lbound, const uint32_t ubound);

// Multiplication CLI app
int main(int argc, char* argv[]) {
  while (true) {
    uint32_t a, b;
    printf("What numbers would you like to multiply together?\n");

    if ((a = get_number("1st number (from 1 to 10): ", 1, 10)) == UINT32_MAX) return 0;
    if ((b = get_number("2nd number (from 1 to 10): ", 1, 10)) == UINT32_MAX) return 0;

    for (int i = 0; i < N_ATTEMPTS; i++) {
      printf("%" PRIu32 " * %" PRIu32 " = ", a, b);
      uint32_t attempt = get_number("", 0, UINT32_MAX);
      if (attempt == UINT32_MAX) return 0;
      if (attempt != a * b) {
        if (i == N_ATTEMPTS - 1) {
          printf("Wrong! The right answer was %" PRIu32 ".\n", a * b);
        } else {
          printf("Wrong! Try again.\n");
        }
      } else {
        printf("Yay!\n");
        break;
      }
    }

    printf("Would you like to try again? [Y/n] ");
    char c[3];
    if (fgets(c, 3, stdin) != NULL) {
      if (toupper(*c) != 'Y' && *c != '\n') break;
    } else return 0;
  }
}

// Gets a number that must be between lbound and ubound
uint32_t get_number(const char* prompt, const uint32_t lbound, const uint32_t ubound) {
  uint32_t n;
  char str[64];
  while (true) {
    printf("%s", prompt);

    if (fgets(str, sizeof str, stdin) == NULL) {
      printf("\n");
      return UINT32_MAX;
    }

    if (*str != '\n' && sscanf(str, "%" SCNu32, &n)) {
      if (n < lbound || n > ubound) {
        printf("The number should be within %d and %d!\n", lbound, ubound);
      } else return n;
    } else {
      printf("Invalid number!\n");
    }
  }
}
