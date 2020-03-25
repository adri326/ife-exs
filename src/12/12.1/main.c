#include <stdlib.h>
#include <stdio.h>

// Simple array initialization
int main(int argc, char** argv) {
  int T[10];
  int R[5];

  for (size_t n = 0; n < 10; n++) {
    T[n] = 0;
  }
  for (size_t n = 0; n < 5; n++) {
    R[n] = 10;
  }

  for (size_t n = 0; n < 10; n++) {
    printf("%d ", T[n]);
  }
  printf("\n");
  for (size_t n = 0; n < 5; n++) {
    printf("%d ", R[n]);
  }
  printf("\n");
}
