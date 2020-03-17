#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

bool getn(char* prompt, int* num, int def);

// Sum of the numbers between d and f
int main(int argc, char* argv[]) {
  int d, f;
  bool even, absolute;

  if (
    !getn("From (default=0): ", &d, 0)
    || !getn("To (default=1): ", &f, 1)
  ) {return 0;}

  if (d > f) {
    printf("`To` must be bigger than `from`!\n");
    return 1;
  }

  char str[3];
  printf("[E]ven or [a]ny? [E/a]: ");
  fgets(str, sizeof str, stdin);
  even = *str == '\n' || toupper(*str) == 'E';

  printf("Absolute? [y/N]: ");
  fgets(str, sizeof str, stdin);
  absolute = *str != '\n' || toupper(*str) == 'Y';

  int sum = 0;

  for (int i = d; i <= f; i++) {
    if (!even || i % 2 == 0) sum += absolute ? abs(i) : i;
  }

  printf("The sum is %d\n", sum);

  return 0;
}

// Prints `str`, stores the result in `num`, with as default value `def` and returns wether or not a value could be stored in `num`.
bool getn(char* prompt, int* num, int def) {
  char str[127]; // Probably overkill
  while (true) {
    printf("%s", prompt);
    fflush(stdout);
    if (!fgets(str, sizeof str, stdin)) return false;
    if (*str == '\n') { // Nothing was entered
      *num = def;
      break;
    } else {
      int res = sscanf(str, "%d", num);
      if (res == 1) break;
      else if (res == EOF) {
        printf("\n");
        return false;
      } else {
        printf("Not a valid number!\n");
      }
    }
  }

  return true;
}
