#include <stdlib.h>
#include <stdio.h>

// Errorless acquisition of a number between -10 and 10
int main(int argc, char* argv[]) {
  int num = 0;

  do {
    printf("Please enter a non-zero number from -10 to 10: ");
    scanf("%d", &num);
  } while (num == 0 || num < -10 || num > 10);

  printf("Good human!\n");

  return 0;
}
