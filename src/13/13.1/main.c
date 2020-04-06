#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define STR_LEN 20

// Uppercase conversion
int main(int argc, char** argv) {
  char str[STR_LEN];
  printf("Give me a word and I will make it bigger: ");

  // Only put the first STR_LEN characters in our string
  if (fgets(str, STR_LEN, stdin) == NULL) return 1;

  // Alternatives are:
  // scanf("%19s", str); // We have STR_LEN characters available in our string, but one will be used by the null character
  // scanf_s("%s", str, STR_LEN); // introduced by Microsoft and described in the C11 standard, very sparsely implemented as of today (neither gcc nor clang implement it for instance)

  for (size_t n = 0; n < STR_LEN; n++) {
    str[n] = (char)toupper(str[n]);
  }

  printf("%s\n", str);
  return 0;
}
