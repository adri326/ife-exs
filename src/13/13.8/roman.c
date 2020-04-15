#include "roman.h"

const static uint32_t ROMAN_VALUE[8] = {0, 1, 5, 10, 50, 100, 500, 1000};

size_t numeral_no(const char letter);
uint32_t calculate_value(const char* raw, size_t* pos, size_t max);

uint32_t roman_to_decimal(const char* raw, size_t length) {
  length--;
  return calculate_value(raw, &length, 8);
}

size_t numeral_no(const char letter) {
  switch (letter) {
    case 'I': return 1;
    case 'V': return 2;
    case 'X': return 3;
    case 'L': return 4;
    case 'C': return 5;
    case 'D': return 6;
    case 'M': return 7;
    default: return 0;
  }
}

uint32_t calculate_value(const char* raw, size_t* pos, size_t max) {
  const size_t my_no = numeral_no(raw[*pos]);
  if (my_no == 0) return 0; // ERROR

  uint32_t value = ROMAN_VALUE[my_no];

  while (*pos > 0 && numeral_no(raw[*pos - 1]) < my_no) {
    *pos -= 1;
    value -= calculate_value(raw, pos, my_no);
  }

  if (*pos > 0 && numeral_no(raw[*pos - 1]) < max) {
    *pos -= 1;
    return value + calculate_value(raw, pos, max);
  } else {
    return value;
  }
}
