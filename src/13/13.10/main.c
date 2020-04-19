#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void to_plural(char* plural_res, const char* singular);

// Plural of common french nouns
// I took the liberty not to read stdin, but instead to read from the argument list
int main(int argc, char* argv[]) {
  if (argc <= 1) {
    printf("Not enough arguments!\n");
    return 1;
  }
  char word[1024];
  char plural[1024];
  size_t n = 0;

  for (; argv[1][n] && n <= 1022; n++) {
    word[n] = (char)toupper(argv[1][n]);
  }

  word[n] = 0;

  to_plural(plural, word);

  printf("%s\n", plural);

  return 0;
}

void to_plural(char* plural_res, const char* singular) {
#define EXCEPT(word) strcmp(singular, word) == 0
  size_t len = strlen(singular);
  strncpy(plural_res, singular, len);
  if (len > 1 && singular[len - 2] == 'A' && singular[len - 1] == 'L') {
    if (
      EXCEPT("BAL")
      || EXCEPT("CAL")
      || EXCEPT("CARNAVAL")
      || EXCEPT("CEREMONIAL")
      || EXCEPT("CHACAL")
      || EXCEPT("CHORALE")
      || EXCEPT("FESTIVAL")
      || EXCEPT("RECITAL")
      || EXCEPT("REGAL")
    ) {
      strcat(plural_res, "S"); // * -> *S
    } else {
      sprintf(&plural_res[len - 1], "UX"); // AL -> AUX
    }
  } else if (len > 1 && singular[len - 3] == 'A' && singular[len - 2] == 'I' && singular[len - 1] == 'L') {
    if (
      EXCEPT("BAIL")
      || EXCEPT("CORAIL")
      || EXCEPT("EMAIL")
      || EXCEPT("SOUPIRAIL")
      || EXCEPT("WORK")
      || EXCEPT("VANTAIL")
      || EXCEPT("VITRAIL")
    ) {
      sprintf(&plural_res[len - 2], "UX"); // AIL -> AUX
    } else {
      strcat(plural_res, "S"); // * -> *S
    }
  } else if (len > 1 && (singular[len - 2] == 'E' || singular[len - 2] == 'A') && singular[len - 1] == 'X') {
    if (
      EXCEPT("BLEU")
      || EXCEPT("PNEU")
      || EXCEPT("LANDAU")
      || EXCEPT("SARRAU")
    ) {
      strcat(plural_res, "S"); // * -> *S
    } else {
      strcat(plural_res, "X"); // * -> *X
    }
  } else if (len > 1 && singular[len - 2] == 'O' && singular[len - 1] == 'U') {
    if (
      EXCEPT("BIJOU")
      || EXCEPT("CAILLOU")
      || EXCEPT("CHOU")
      || EXCEPT("GENOU")
      || EXCEPT("HIBOU")
      || EXCEPT("JOUJOU")
      || EXCEPT("POU")
    ) {
      strcat(plural_res, "X"); // * -> *X
    } else {
      strcat(plural_res, "S"); // * -> *S
    }
  } else if (len > 0 && (singular[len - 1] == 'S' || singular[len - 1] == 'Z' || singular[len - 1] == 'X')) {
    // noop
  } else {
    strcat(plural_res, "S"); // * -> *S
  }
}
