#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Acquisition of a number between 5 and 15 or equal to 20
int main(int argc, char* argv[]) {
  int num = 0;

  while (true) {
    printf("Please enter a non-zero number from 5 to 15 or 20: ");

    const int res = scanf("%d", &num);
    if (res == 1 && (num == 20 || (num >= 5 && num <= 15))) break;
    else if (res == EOF) {
      printf("\n");
      return 0;
    } else {
      printf("The number you entered is not valid!\n");
      if (res == 0) scanf("%*[^\n]");
    }
  }

  printf("Good human!\n");

  return 0;
}
