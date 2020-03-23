#include "change-base.h"

size_t change_base(uint8_t num[WIDTH], uint8_t from, uint8_t to, uint8_t* target) {
  if (from <= 1 || from > 10 || to <= 1 || to > 10) return (size_t)(-1);

  uint64_t sum = 0;
  uint64_t mul = 1;
  size_t res = (size_t)(-1);

  for (size_t n = 0; n < WIDTH; n++, mul *= from) {
    if (num[n] >= from) return (size_t)(-1);
    // overflow protection
    if (num[n] > UINT64_MAX / mul) return (size_t)(-1);
    if (num[n] * mul > UINT64_MAX - sum) return (size_t)(-1);
    sum += num[n] * mul;
  }

  for (size_t n = 0; n < WIDTH; n++) {
    target[n] = sum % to;
    sum /= to;
    if (sum == 0 && res == (size_t)(-1)) res = n;
  }

  return res;
}
