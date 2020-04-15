#ifndef ROMAN_H
#define ROMAN_H

#include <stdlib.h>
#include <inttypes.h>

const static char ROMAN_NUMERALS[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

uint32_t roman_to_decimal(const char* raw, size_t length);

#endif // ROMAN_H
