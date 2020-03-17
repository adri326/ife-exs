#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int execute_op(int a, int b, char operator);

// Simple operation
int main(int argc, char* argv[]) {
  int a, b;
  char c;

  printf("Enter an operation (eg. 2+3, without space): ");
  while (scanf("%d%c%d", &a, &c, &b) != 3) {
    printf("Invalid operation, try again: ");
  }

  printf("%d %c %d = %d\n", a, c, b, execute_op(a, b, c));

  return 0;
}

int execute_op(int a, int b, char operator) {
  switch (operator) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    case '%': return a % b;
    case '<': return a < b;
    case '>': return a > b;
    case '=': return a == b;
    case '^': return (int)(pow((double)a, (double)b));
    case '|': return a | b;
    case '&': return a & b;
    case '~': return a ^ b;
    default:
      printf("Unknown operator: '%c'\n", operator);
      return 0;
  }
}
