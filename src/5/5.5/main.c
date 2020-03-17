#include <stdlib.h>
#include <stdio.h>

// Print the module of a by b
int main(int argc, char* argv[]) {
  int nb, div;
  printf("nb = ");
  scanf("%d", &nb);
  printf("div = ");
  scanf("%d", &div);

  if (nb % div == 0) {
    printf("The number %d is a multiple of %d as %d modulo %d equals 0\n", nb, div, nb, div);
  } else {
    printf("The number %d is not a multiple of %d as %d modulo %d equals %d\n", nb, div, nb, div, nb % div);
  }

  return 0;
}
