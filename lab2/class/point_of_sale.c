/*
 * This program simulates a point of sale that can only print 5 digits
 * at a time. It receives a number from the command line and prints it
 * in as many lines as necessary.
 */

#include <stdio.h>  /* printf, fprintf */
#include <stdlib.h> /* EXIT_SUCCESS, EXIT_FAILURE, atol */

int main(int argc, char const *argv[]) {
  long number; /* The number provided by the user */

  /* Check if the user provided the number */
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <number>.\n", argv[0]);
    return EXIT_FAILURE;
  }

  /* Convert the number from string to long */
  number = atol(argv[1]);

  /* Convert the long number into as many int as necessary */
  while (number > 0) {
    int line = number % 100000;
    printf("%5d\n", line); /* Print the int with 5 digits */
    number /= 100000;
  }
  return EXIT_SUCCESS;
}
