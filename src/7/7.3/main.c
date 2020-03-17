#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

#define N_NUMS 6
#define MAX 50

// Generate 6 numbers from 1 to 49 anx ask the user if they wish to roll one more time
int main(int argc, char* argv[]) {
  srand((unsigned int)time(0));
  for (int i = 0; i < N_NUMS; i++) {
    printf("%d\n", rand() % MAX);
  }

  // Tricky yet necessary way to have a default value; scanf is not suited for any complex application
  printf("One more time? [Y/n] ");
  char c[3]; // [<char>] <endl> \0
  if (fgets(c, 3, stdin) != NULL) {
    if (toupper(*c) == 'Y' || *c == '\n') printf("%d\n", rand() % MAX);
  }

  /* An alternative would be:
  char c;
  scanf("%c", &c);
  if (c == 'y') printf("%d\n", rand() % MAX);
  */

  return 0;
}
