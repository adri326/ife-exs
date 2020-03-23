#include <stdlib.h>
#include <stdio.h>
#include "cswap.h"

// 3-variable rotation
int main(int argc, char** argv) {
  int a = 1;
  int b = 2;
  int c = 3;
  cswap(int, a, b, c)
  printf("%d, %d, %d\n", a, b, c);
  cswap2(&a, &b, &c);
  printf("%d, %d, %d\n", a, b, c);
}
