#ifndef QUERY_H
#define QUERY_H

/** Asks the user to input an integer between `minimum` and `maximum`
* @param prompt - What text to display
* @param minimum - Minimum allowed value for the prompted integer
* @param maximum - Maximum allowed value for the prompted integer
* @returns The prompted integer
*/
int query_int(const char* prompt, const int minimum, const int maximum);

/** Asks the user to input their two initials
* @param first_name - Char pointer to where the first name's initial will be put
* @param last_name - Char pointer to where the last name's initial will be put
*/
void query_initials(char* first_name, char* last_name);

#endif // QUERY_H
