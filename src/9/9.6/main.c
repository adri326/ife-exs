#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>
#include <ctype.h>

uint32_t get_number(const char* prompt, const uint32_t lbound, const uint32_t ubound);
void sum_odd(void);
void sum_even(void);
uint32_t sum(uint32_t i, const uint32_t max);

// "Sums of even or odd numbers" (they were probably out of ideas)
int main(int argc, char* argv[]) {
  while (true) {
    char str[3];
    printf("What would you like to do? (o = sum of odd numbers, e = sum of even numbers, c = cancel) [o/E/c] ");
    if (fgets(str, sizeof str, stdin) == NULL) return 0;

    if (toupper(*str) == 'E' || *str == '\n') sum_even();
    else if (toupper(*str) == 'O') sum_odd();
    else break;
  }
  return 0;
}

void sum_even() {
  uint32_t max = get_number("Enter a number from 2 to 100: ", 2, 100);
  printf("The sum of the even numbers up to %" PRIu32 " is %" PRIu32 ".\n", max, sum(0, max));
}

void sum_odd() {
  uint32_t max = get_number("Enter a number from 2 to 100: ", 2, 100);
  printf("The sum of the odd numbers up to %" PRIu32 " is %" PRIu32 ".\n", max, sum(1, max));
}

// Gets a number that must be between lbound and ubound
uint32_t get_number(const char* prompt, const uint32_t lbound, const uint32_t ubound) {
  uint32_t n;
  char str[64];
  while (true) {
    printf("%s", prompt);

    if (fgets(str, sizeof str, stdin) == NULL) {
      printf("\n");
      exit(0);
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

// Returns the sum of the odd/even numbers, i determining wether we should sum odd or even numbers
uint32_t sum(uint32_t i, const uint32_t max) {
  uint32_t s = 0;
  for (; i <= max; i += 2) s += i;
  return s;
}
