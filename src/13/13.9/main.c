#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>

/** Encodes a character into its ciphered variant
* @param input - The character to cipher
* @returns The ciphered version of `input`
*/
char encode(const char input);

/** Decodes a character into its deciphered variant
* @param input - The ciphered character
* @returns The deciphered version of `input`
*/
char decode(const char input);

// Simple ciphering and deciphering
int main(int argc, char* argv[]) {
  bool is_valid = false;
  char input[1024];

  srand((unsigned int)time(0));

  do {
    printf("Please enter a string, consisting only of alphanumeric characters and spaces:\n");
    printf("> ");

    fgets(input, sizeof input, stdin);

    is_valid = true;
    size_t n = 0;
    for (; input[n] != '\n' && input[n] != 0; n++) {
      input[n] = (char)toupper(input[n]);
      if (!( // <- notice the !
          (input[n] >= 'A' && input[n] <= 'Z')
          || (input[n] >= '0' && input[n] <= '9')
          || input[n] != ' '
          || input[n] != '-')
        ) {
        is_valid = false;
        break;
      }
    }
    if (input[n] == '\n') input[n] = 0;
  } while (!is_valid);

  printf("\n");

  printf("The encoded version is as follows:\n");
  for (size_t n = 0; input[n]; n++) {
    printf("%c", encode(input[n]));
  }
  printf("\n\n");

  printf("The decoded version is as follows:\n");
  for (size_t n = 0; input[n]; n++) {
    printf("%c", decode(input[n]));
  }
  printf("\n");

  return 0;
}

char encode(const char input) {
  if (input >= 'A' && input <= 'Z') {
    if (input == 'E') return ' ';
    if (input % 2) {
      return input + 6 <= 'Z' ? input + 6 : input - 20;
    } else {
      return input + 4 <= 'Z' ? input + 4 : input - 22;
    }
  }
  if (input == ' ') return '0' + (char)(rand() % 10);
  else return '-';
}

char decode(const char input) {
  if (input == ' ') return 'E';
  if (input >= '0' && input <= '9') return ' ';
  if (input >= 'A' && input <= 'Z') {
    if (input % 2) {
      return input - 6 >= 'A' ? input - 6 : input + 20;
    } else {
      return input + 4 >= 'A' ? input - 4 : input + 22;
    }
  }
  return '-';
}
