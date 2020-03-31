#include <stdlib.h>
#include <stdio.h>

int fct(int p, const int n);
void f(const int n, const int p);

// Completely random functions
int main(int argc, char* argv[]) {
  int n = 2;
  const int p = 5;
  int q;
  f(p, n);
  n = fct(p, n);
  q = p * n;
  f(q, n);
  printf("[A] - in `main`, n=%d, p=%d, q=%d\n", n, p, q);
  return 0;
}

int fct(int p, const int n) {
  int q = 2 * p + n;
  printf("[B] - in `fct`, n=%d, p=%d, q=%d\n", n, p, q);
  p = p + 2;
  return 2 * q + p;
}

void f(const int n, const int p) {
  int q = 3 * p + n;
  printf("[C] - in `f`, n=%d, p=%d, q=%d\n", n, p, q);
}
