#include <stdio.h>
#include <time.h>
#include <inttypes.h>
#include <stdbool.h>

void decompose(uint32_t n);

// Digits of a number
int main(int argc, char* argv[]) {
  uint32_t num;

  while (true) {
    printf("Please input a number: ");
    char str[50];
    if (fgets(str, 50, stdin) == NULL) {
      printf("\n");
      return 0;
    }
    if (sscanf(str, "%" SCNu32, &num)) break;
    else printf("Invalid number!\n");
  }

  decompose(num);
}

void decompose(uint32_t n) {
  printf("%" PRIu32 " = ", n);
  for (int i = 0; n; i++) {
    printf("%d*10^%d", n % 10, i);
    n /= 10;
    if (n) printf(" + ");
  }
  printf("\n");
}
