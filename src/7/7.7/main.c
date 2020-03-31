#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Sum of the N numbers
int main(int argc, char* argv[]) {
  size_t N;

  while (true) { // Input N
    printf("Enter how many numbers you'd like to input (3-10): ");
    int res = scanf("%zu", &N);
    if (res == 1) {
      if (N > 2 && N < 11) break;
      else {
        printf("Must be between 3 and 10!\n");
      }
    } else if (res == 0) {
      printf("Not a valid number!\n");
      scanf("%*[^\n]");
    } else {
      printf("\n");
      return 0;
    }
  }

  int sum = 0;

  for (size_t i = 0; i < N; i++) { // input each number and add it to sum
    int n;
    printf("%zu-th number: ", i + 1);

    const int res = scanf("%d", &n);
    if (res == 0) {
      printf("Not a valid number!\n");
      scanf("%*[^\n]");
      i--;
    } else if (res == EOF) {
      printf("\n");
      return 0;
    } else {
      sum += n;
    }
  }

  printf("The sum of these numbers is %d.\n", sum);

  return 0;
}
