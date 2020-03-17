#include <stdlib.h>
#include <stdio.h>

// Print the multiplication table for N ∈ [2; 10]
int main(int argc, char* argv[]) {
  int n;
  do {
    printf("Enter a number from 2 to 10: ");
    int res = scanf("%d", &n);

    if (res == 1) {
      if (n < 2 || n > 10) printf("The number must be between 2 and 10.\n");
    } else if (res == EOF) {
      printf("\n");
      return 0;
    } else {
      printf("Please enter a valid number.\n");
      scanf("%*[^\n]"); // "swallows" any non-10 character, as to clear the input buffer
    }
  } while (n < 2 || n > 10);

  for (int x = 1; x <= 10; x++) {
    printf("%d * %d = %d\n", n, x, n * x);
  }

  return 0;
}
