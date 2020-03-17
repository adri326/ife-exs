#include <stdlib.h>
#include <stdio.h>

#define N_INT 4

// Print the biggest value among 4 integers
int main(int argc, char* argv[]) {
  int a[N_INT];

  for (size_t i = 0; i < N_INT; i++) {
    printf("%lu-th number: ", i + 1);
    scanf("%d", &a[i]);
  }

  int max = 0;
  for (size_t i = 0; i < N_INT; i++) {
    if (a[i] > max) max = a[i];
  }

  printf("The biggest number is %d.\n", max);

  return 0;
}

/* Alternative, less idiomatic nor ideal way:
  int a, b, c, d;
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  scanf("%d", &d);

  int max = 0;

  if (a > max) max = a;
  if (b > max) max = b;
  if (c > max) max = c;
  if (d > max) max = d;

  printf("The biggest number is %d.\n", max);
*/
