/*
 * This program receives a user name as argument from the command line
 * and prints a greeting message.
 */

#include <stdio.h>  // printf, fprintf
#include <stdlib.h> // EXIT_SUCCESS, EXIT_FAILURE

int main(int argc, char const *argv[]) {
  // Check if the user name was provided
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <user name>\n", argv[0]);
    return EXIT_FAILURE;
  }
  printf("Hello %s!\n", argv[1]);
  return EXIT_SUCCESS;
}
