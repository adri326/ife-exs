#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 50

// Generate numbers from 1 to 49 until the user can't bear it anymore
int main(int argc, char* argv[]) {
  srand((unsigned int)time(0));

  while (true) {
    printf("%d\n", rand() % MAX);

    // Tricky yet necessary way to have a default value; scanf is not suited for any complex application
    printf("One more time? [Y/n] ");
    char c[3];
    if (fgets(c, 3, stdin) != NULL) {
      if (toupper(*c) != 'Y' && *c != '\n') break;
    } else break;

    /* An alternative would be:
    char c;
    scanf(" %c", &c);
    if (c != 'y') break;
    */
  }

  return 0;
}
