#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define STR_LEN 1024

/** Filters letters out of `from`, and puts them into `to` */
size_t filter_letters(const char* from, char* to);

/** Returns wether or not `string` is a palindrome (case-insensitive).
* This function compares the string with itself, instead of creating a new, reversed string.
* @param string - The string to check
* @param length - The length of the string
*/
bool is_palindrome(const char* string, const size_t length);

// Palindrome detection (soft)
// The exercise proposed a method which involved creating a reverse of the string and comparing it letter by letter.
// One of the examples contained characters which are not in the 7-bit ASCII range. I don't do any unicode in C.
int main(int argc, char** argv) {
  char string[STR_LEN];
  char filtered_string[STR_LEN];

  printf("Give me a string and I will tell you if it is a palindrome: ");
  fgets(string, STR_LEN, stdin);

  size_t length = filter_letters(string, filtered_string);

  if (is_palindrome(filtered_string, length)) {
    printf("It is indeed a palindrome.\n");
  } else {
    printf("It isn't a palindrome.\n");
  }

  return 0;
}

size_t filter_letters(const char* from, char* to) {
  size_t o = 0;
  for (size_t n = 0; from[n]; n++) {
    if ((from[n] >= 'A' && from[n] <= 'Z') || (from[n] >= 'a' && from[n] <= 'z')) {
      to[o++] = from[n];
    }
  }
  to[o] = 0;
  return o;
}

bool is_palindrome(const char* string, const size_t length) {
  for (size_t n = 0; n < length / 2; n++) {
    if (tolower(string[n]) != tolower(string[length - n - 1])) return false;
  }
  return true;
}
