#ifndef CHANGE_BASE_H
#define CHANGE_BASE_H

#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>

#define WIDTH 64

/*! change_base(num: u8[WIDTH], from: u8, to: u8, target: u8[WIDTH])
  Converts `num` as a `from`-ary number to a `to`-ary number.
  The result of the conversion is stored in `target`.
  @returns The maximum non-zero index of the output array, -1 if the algorithm encountered any error.
*/
size_t change_base(uint8_t num[WIDTH], uint8_t from, uint8_t to, uint8_t* target);

#endif // CHANGE_BASE_H
