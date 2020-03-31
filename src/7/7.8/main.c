#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>

// N first prime numbers
int main(int argc, char* argv[]) {
  uint64_t N;

  while (true) { // Input N
    printf("Enter how many prime numbers you want (5-100): ");
    const int res = scanf("%" SCNu64, &N);
    if (res == 1) {
      if (N >= 5 && N <= 100) break;
      else {
        printf("Must be between 5 and 100!\n");
      }
    } else if (res == 0) {
      printf("Not a valid number!\n");
      scanf("%*[^\n]");
    } else {
      printf("\n");
      return 0;
    }
  }

  printf("2\n");
  printf("3\n");

  for (uint64_t n = 5, found = 2; found < N; n += 2) { // loop over the odd natural numbers
    bool is_prime = n % 3 != 0;
    for (uint64_t div = 5; div * div <= n; div += 6) { // optimized prime sieve
      if (n % div == 0 || n % (div + 2) == 0) {
        is_prime = false;
        break;
      }
    }
    if (is_prime) {
      printf("%" PRIu64 "\n", n);
      found++;
    }
  }

  return 0;
}
