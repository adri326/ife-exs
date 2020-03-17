#include <stdlib.h>
#include <stdio.h>

// Congratulate the student on its mark (0-20)
int main(int argc, char* argv[]) {
  int mark;
  printf("Your mark: ");
  scanf("%d", &mark);

  if (mark >= 0 && mark < 10) printf("You'll have to work harder!\n");
  else if (mark == 10 || mark == 11) printf("Mmh okay.\n");
  else if (mark >= 12 && mark < 20) printf("Good job :)\n");
  else if (mark == 20) printf("Amazing!\n");
  else printf("That's not an actual mark...\n");

  return 0;
}

/* Using GNU case range extension:
switch (mark) {
  case 0 ... 9:
    printf("You'll have to work harder!\n");
    break;

  case 10:
  case 11:
    printf("Mmh okay.\n");
    break;

  case 12 ... 19:
    printf("Good job :)\n");
    break;

  case 20:
    printf("Amazing!\n");
    break;

  default:
    printf("That's not an actual mark...\n");
}
*/
