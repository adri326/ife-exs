#include <stdlib.h>
#include <stdio.h>

// Swap two integers
int main(int argc, char* argv[]) {
  int a = 1;
  int b = 3;

  {
    const int c = a; // temporary value to hold the old value of a
    a = b;
    b = c;
    // note that in a language where assignement returns the previous value, this could have been written `a = b = a`
  }

  printf("%d, %d\n", a, b);

  return 0;
}
