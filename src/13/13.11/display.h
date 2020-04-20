#ifndef DISPLAY_H
#define DISPLAY_H

#include <inttypes.h>

#ifdef NO_COLOR
  #define ANSI_CLEAR_LINE ""
  #define ANSI_UP ""
  #define ANSI_COLOR_YELLOW ""
  #define ANSI_COLOR_NONE ""
  #define ANSI_COLOR_RED ""
  #define ANSI_COLOR_GREEN ""
#else
  #define ANSI_CLEAR_LINE "\x1b[2K"
  #define ANSI_UP "\x1b[F"
  #define ANSI_COLOR_YELLOW "\x1b[93m"
  #define ANSI_COLOR_NONE "\x1b[0m"
  #define ANSI_COLOR_RED "\x1b[91m"
  #define ANSI_COLOR_GREEN "\x1b[92m"
#endif // NO_COLOR

#define HANGING_MAN_HEIGHT 7

/** Displays a colored hanging man
* @param n_errs - The number of errors made
**/
void display_hanging_man(const uint8_t n_errs);

/** Displays the word with `attempted_letters` uncovered
* @param word - The word to print
* @param attempted_letters - The letters already inputed
*/
void display_word(const char* word, char attempted_letters[27]);

/** Runs `display_hanging_man` and `display_word`
* @param word - The word to print
* @param attempted_letters - The letters already inputed
* @param n_errs - The number of errors made
*/
void display(const char* word, char attempted_letters[27], const uint8_t n_errs);

/** Clears the lines written by `display` */
void clear(void);

#endif // DISPLAY_H
