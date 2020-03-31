#include <stdlib.h>
#include <stdio.h>

size_t ask_length(void);
float ask_note(const size_t n);
float get_mean(const float* arr, const size_t length);

// Enter `length` notes in adynamically-allocated array and calculate their mean
int main(int argc, char** argv) {
  size_t length = ask_length();
  float* array = (float*)malloc(sizeof(float) * length);

  for (size_t n = 0; n < length; n++) {
    array[n] = ask_note(n);
  }

  printf("The mean is %.2f.\n", get_mean(array, length));
  free(array);

  return 0;
}

size_t ask_length() {
  size_t res = 0;
  int scanf_res = 0;

  while (scanf_res != 1) {
    printf("How many notes to enter? ");
    scanf_res = scanf("%zu", &res);
    if (scanf_res == EOF) {
      printf("\n");
      exit(0);
    } else if (scanf_res != 1 || res == 0) {
      printf("Invalid length!\n");
      scanf("%*[^\n]");
    }
  }

  return res;
}

float ask_note(const size_t n) {
  float res = 0;
  int scanf_res = 0;

  while (scanf_res != 1) {
    printf("Please enter note [%zu]: ", n + 1);
    scanf_res = scanf("%f", &res);
    if (scanf_res == EOF) {
      printf("\nExpected a note.\n");
      exit(1);
    } else if (scanf_res != 1 || res < 0 || res > 20) {
      printf("Invalid note!\n");
      scanf("%*[^\n]");
    }
  }

  return res;
}

float get_mean(const float* arr, const size_t length) {
  float sum = 0.0;
  for (size_t n = 0; n < length; n++) {
    sum += arr[n];
  }
  return sum / (float)length;
}
