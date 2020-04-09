#include <stdlib.h>
#include <stdio.h>

size_t my_strlen(char* str);

int main(int argc, char** argv) {
  char* strings[1024] = {
    "bread",
    "The night sky is bright.",
    "Are we there yet?",
    "🐺"
  };

  for (size_t n = 0; n < 4; n++) {
    printf("'%s' is %zu characters long.\n", strings[n], my_strlen(strings[n]));
  }

  return 0;
}

size_t my_strlen(char* str) {
  size_t n = 0;
  while (str[++n]); /* noop, n is incremented within the condition */
  return n;
}
