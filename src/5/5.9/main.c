#include <stdlib.h>
#include <stdio.h>

// Prints the consumption and average speed of a vehicle, given the travel distance, the time it took and how much fuel it consumed
int main(int argc, char* argv[]) {
  float k, h, m, l;
  printf("Distance (km): ");
  scanf("%f", &k);

  printf("Time (hours minutes): ");
  scanf("%f%f", &h, &m);

  printf("Fuel consumed (liters): ");
  scanf("%f", &l);

  printf("Average consumption (L/100km): %f\n", l / k * 100);
  printf("Average speed (km/h): %f\n", k / (h + m / 60));

  return 0;
}
