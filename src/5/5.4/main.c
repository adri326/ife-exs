#include <stdlib.h>
#include <stdio.h>

// Print a character and its code
int main(int argc, char* argv[]) {
  char c;
  printf("Please enter a character: ");
  scanf("%c", &c);
  printf("The character %c has as code %hhu\n", c, c);

  return 0;
}
