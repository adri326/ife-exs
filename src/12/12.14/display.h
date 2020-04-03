#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdlib.h>

#ifdef NO_COLOR
  #define ANSI_CLEAR_LINE ""
  #define ANSI_UP ""
  #define ANSI_DOWN ""
  #define ANSI_COLOR_YELLOW ""
  #define ANSI_COLOR_NONE ""
  #define ANSI_COLOR_CYAN ""
  #define ANSI_COLOR_RED ""
  #define ANSI_COLOR_GREEN ""
#else
  #define ANSI_CLEAR_LINE "\x1b[2K"
  #define ANSI_UP "\x1b[F"
  #define ANSI_DOWN "\x1b[E"
  #define ANSI_COLOR_YELLOW "\x1b[93m"
  #define ANSI_COLOR_NONE "\x1b[0m"
  #define ANSI_COLOR_CYAN "\x1b[96m"
  #define ANSI_COLOR_RED "\x1b[91m"
  #define ANSI_COLOR_GREEN "\x1b[92m"
#endif // NO_COLOR

/** Prints a welcoming message
* @param n_nums - The number of numbers to memorize
* @param duration - The duration of the memorizing phase
*/
void welcome_message(const int n_nums, const int duration);

/** Prints the numbers to memorize
* @param array - The numbers to display
* @param length - The length of `array`
* @param nums_per_line - The number of integeres to display per line
* @param num_width - The width of the numbers
*/
void print_nums(const int* array, const size_t length, const size_t nums_per_line, const unsigned int num_width);

/** Let the user input numbers
* @param array - The array of valid numbers
* @param length - The length of `array`
*/
size_t input_nums(const int* array, const size_t length);

#endif // DISPLAY_H
