#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

// Seconds into hours, minutes and seconds
int main(int argc, char* argv[]) {
  uint64_t s;
  printf("Enter an amount of seconds: ");
  scanf("%" SCNu64, &s);
  // If s was an `int`, you could've written:
  // scanf("%d", &s);

  uint64_t m = s / 60;
  s %= 60;

  uint64_t h = m / 60;
  m %= 60;

  printf("This is equal to %" PRIu64 " hours, %" PRIu64 " minutes and %" PRIu64 " seconds\n", h, m, s);
  // If s, m and h were `int`s, you could've written:
  // printf("This is equal to %d hours, %d minutes and %d seconds\n", h, m, s);

  return 0;
}
