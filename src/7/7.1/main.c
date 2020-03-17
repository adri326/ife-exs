#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define N_NUMS 6
#define MAX 50

// Generate 6 numbers from 1 to 49
int main(int argc, char* argv[]) {
  srand((unsigned int)time(0));

  for (int i = 0; i < N_NUMS; i++) {
    printf("%d\n", rand() % MAX);
  }

  return 0;
}
