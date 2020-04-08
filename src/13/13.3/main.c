#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define N_STRINGS 15
#define STR_LEN 128

int main(int argc, char** argv) {
  char names[N_STRINGS][STR_LEN];
  char* martin = "Martin";

  printf("Please enter %d names:\n", N_STRINGS);
  for (size_t n = 0; n < N_STRINGS; n++) {
    printf("[%02zu]> ", n + 1);
    if (fgets(names[n], STR_LEN, stdin) == NULL) return 1;
    if (names[n][0] == '\n') { // Empty string: loop again
      n--;
      continue;
    }
  }

  size_t n_martins = 0;
  for (size_t n = 0; n < N_STRINGS; n++) {
    for (size_t x = 0; names[n][x] != 0 && names[n][x] != '\n'; x++) {
      if (toupper(names[n][x]) == martin[x]) n_martins++;
    }
  }

  printf("There are %zu %ss in the group!\n", n_martins, martin);
}
