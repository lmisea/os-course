/* Program that pauses the execution of the program until the user presses a
key. It works on both Windows and Linux. */

#include <stdio.h>  // printf, fflush, getchar
#include <stdlib.h> // EXIT_SUCCESS

int main() {
  /* The #if directive allows conditional compilation. The code between #if and
  #endif is compiled only if the condition is true. This allows the program to
  be compiled differently on Windows and Linux. */
#if defined(WINDOWS) || defined(_WIN32) || defined(_WIN64)
  system("pause");
#else
  printf("Press any key to continue . . .");
  fflush(stdout);
  getchar();
#endif
  /* EXIT_SUCCESS is a macro defined in stdlib.h that is used to indicate
  successful termination of a program, regardless of the operating system. */
  return EXIT_SUCCESS;
}
