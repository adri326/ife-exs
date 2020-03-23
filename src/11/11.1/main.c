#include <stdlib.h>
#include <stdio.h>

// Random function
int main(int argc, char** argv) {
  int a = 3;
  int b = 10;
  int c, *pa, *pb, *pc;
  pa = &a;
  *pa = *pa * 2;
  pb = &b;
  c = 3 * (*pb - *pa);
  pc = pb;
  pa = pb;
  pb = pc;

  printf("a = %d\nb = %d\n*pa = %d\n*pb = %d\n*pc = %d\n", a, b, *pa, *pb, *pc);

  return 0;
}
