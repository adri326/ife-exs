#include "cswap.h"

void cswap2(int* a, int* b, int* c) {
  const int d = *a;
  *a = *b;
  *b = *c;
  *c = d;
}
