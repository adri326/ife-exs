#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include "query.h"
#include "extrema.h"

// Very basic student mark processing tool
int main(int argc, char** argv) {
  // Ask how many students will be processed
  const size_t n_students = (size_t)query_int("How many students to process? ", 10, 100);

  uint8_t* notes = (uint8_t*)malloc(sizeof(uint8_t) * n_students);
  char* first_name_initials = (char*)malloc(sizeof(char) * n_students);
  char* last_name_initials = (char*)malloc(sizeof(char) * n_students);

  // Prompt for each student
  for (size_t n = 0; n < n_students; n++) {
    char student_prompt[128];
    sprintf(student_prompt, "Please enter student %zu's mid-term mark: ", n + 1);
    notes[n] = (uint8_t)query_int(student_prompt, 0, 20);
    query_initials(&first_name_initials[n], &last_name_initials[n]);
  }

  // Get minimum and maximum indexes
  const size_t min_index = find_minimum(notes, n_students);
  const size_t max_index = find_maximum(notes, n_students);

  printf("\n");

  printf("The smallest note is %" PRIu8 ".\n", notes[min_index]);
  printf("The highest note is %" PRIu8 ", it was obtained by %c%c.\n", notes[max_index], first_name_initials[max_index], last_name_initials[max_index]);

  return 0;
}
