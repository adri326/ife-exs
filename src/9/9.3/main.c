#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

double f2c(double fahrenheit);
double c2f(double celsius);

// Degrees to fahrenheit and back to degrees
int main(int argc, char* argv[]) {
  double value;

  while (true) {
    printf("Please input a value: ");
    char str[50];
    if (fgets(str, 50, stdin) == NULL) {
      printf("\n");
      return 0;
    }
    if (sscanf(str, "%lf", &value)) break;
    else printf("Invalid number!\n");
  }

  bool is_celsius;
  printf("Is this value in celsius or fahrenheit? [C/f] ");
  char c[3];
  if (fgets(c, 3, stdin) != NULL) {
    is_celsius = toupper(*c) == 'C' || *c == '\n';
  } else {
    printf("\n");
    return 0;
  }

  if (is_celsius) {
    printf("%.3lf°C = %.3lf°F\n", value, c2f(value));
  } else {
    printf("%.3lf°F = %.3lf°C\n", value, f2c(value));
  }

  return 0;
}

double f2c(double fahrenheit) {
  return (fahrenheit - 32.0) * 5.0 / 9.0;
}

double c2f(double celsius) {
  return celsius * 9.0 / 5.0 + 32.0;
}
