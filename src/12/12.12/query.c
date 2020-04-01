#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "query.h"

int query_int(const char* prompt, const int minimum, const int maximum) {
  while (true) {
    char str[1024];
    int res = 0;

    printf("%s", prompt);

    if (!fgets(str, 1024, stdin)) exit(1);

    const int scanf_res = sscanf(str, "%d", &res);

    if (scanf_res != 1) {
      printf("Invalid number entered!\n");
      scanf("%*[^\n]");
    } else if (res < minimum || res > maximum) {
      printf("Invalid number entered!\n");
    } else {
      return res;
    }
  }
}

void query_initials(char* first_name, char* last_name) {
  while (true) {
    char str[1024];
    printf("What are their initials? ");
    if (!fgets(str, 1024, stdin)) exit(1);
    if (str[0] == '\n') continue;
    if (
      toupper(str[0]) < 'A' || toupper(str[0]) > 'Z'
      || toupper(str[1]) < 'A' || toupper(str[1]) > 'Z'
    ) {
      printf("Invalid initials!\n");
    } else {
      *first_name = (char)toupper(str[0]);
      *last_name = (char)toupper(str[1]);
      return;
    }
  }
}
