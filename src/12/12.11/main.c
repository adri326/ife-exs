#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>

#define N_BITS 8

void input_binary(bool* target, const size_t length, const char* prompt);
bool sum_binary(const bool* a, const bool* b, const size_t length, bool* result);

// Software-implemented binary addition
int main(int argc, char** argv) {
  bool a[N_BITS];
  bool b[N_BITS];
  bool sum[N_BITS];

  // Input the numbers
  printf("Please enter a and b as %d-bit binary numbers\n", N_BITS);
  input_binary(a, N_BITS, "a = ");
  input_binary(b, N_BITS, "b = ");
  bool overflow = sum_binary(a, b, N_BITS, sum);

  printf("\u03a3 = ");
  // Print the carry bit if necessary
  if (overflow) printf("1");
  // Print each bit (back in big endian)
  for (size_t n = 0; n < N_BITS; n++) {
    printf("%c", sum[N_BITS - n - 1] ? '1' : '0');
  }
  printf("\n");

#if N_BITS <= 64
  // Convert the number in base 10
  uint64_t sum_b10 = 0;
  for (size_t n = 0; n < N_BITS; n++) {
    sum_b10 |= (uint64_t)sum[n] << n;
  }
  printf("  = %" PRIu64 "\n", sum_b10);
#endif

  return 0;
}

// Inputs a binary number in big endian and puts it into `target` in little endian
void input_binary(bool* target, const size_t length, const char* prompt) {
  char input[1024]; // should be plenty enough

  bool is_valid = false;
  while (!is_valid) {
    printf("%s", prompt);
    if (!fgets(input, (int)(length + 2), stdin)) exit(1);

    is_valid = true;

    for (size_t n = 0; n < length && is_valid; n++) {
      if (input[n] == '0') target[length - n - 1] = false;
      else if (input[n] == '1') target[length - n - 1] = true;
      else is_valid = false;
    }
  }
}

// Performs the binary sum of `a` and `b`, puts its result into `result` and returns the carry bit (aka overflow bit) of that sum
bool sum_binary(const bool* a, const bool* b, const size_t length, bool* result) {
  bool carry = false;
  for (size_t n = 0; n < length; n++) {
    bool a_xor_b = (a[n] || b[n]) && !(a[n] && b[n]); // a ^ b
    result[n] = (a_xor_b || carry) && !(a_xor_b && carry); // (a ^ b) ^ carry
    carry = (a_xor_b && carry) || (a[n] && b[n]); // (a ^ b) ^ carry | a & b
  }
  return carry;
}
