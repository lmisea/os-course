/**
 * @file pause.c
 *
 * @brief This file contains the function to pause the execution of the program
 * until the user presses a key (Windows) or enter (Linux).
 */

#include "pause.h" /* wait_for_key */
#include <stdio.h> /* printf, fflush, getchar, stdin, stdout */

void wait_for_key() {
  /* The #if directive allows is used to conditionally compile code. */
#if defined(WINDOWS) || defined(_WIN32) || defined(_WIN64)
  system("pause");
#else
  printf("Press enter to continue . . .");
  fflush(stdout);
  clear_input_buffer();
#endif
}

void clear_input_buffer(void) {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
}
