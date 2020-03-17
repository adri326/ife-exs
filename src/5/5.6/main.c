#include <stdlib.h>
#include <stdio.h>

// Print the division of a by b and b by a
int main(int argc, char* argv[]) {
  int a, b;
  printf("a = ");
  scanf("%d", &a);
  printf("b = ");
  scanf("%d", &b);

  printf("%d / %d = %d\n", a, b, a / b);
  printf("%d / %d = %d\n", b, a, b / a);

  return 0;
}
