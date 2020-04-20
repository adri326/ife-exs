#ifndef VERIFY_H
#define VERIFY_H

#include <inttypes.h>
#include <stdbool.h>

/** Append the letter to `attempted_letters` if it isn't attempted and bump the error count if it isn't in `word`
* @param word - The current word
* @param attempted_letters - Already inputted letters
* @param attempt - Inputted letter
* @param n_errs - Errors already made, will be modified
**/
void propose_letter(const char* word, char attempted_letters[27], char attempt, uint8_t* n_errs);

/** Returns wether or not the word has been guessed
* @param word - The current word
* @param attempted_letters - Already inputted letters
**/
bool is_complete(const char* word, char attempted_letters[27]);

#endif // VERIFY_H
