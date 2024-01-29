/**
 * @file pokemon.c
 *
 * @brief This is the entry point of the project and contains its main
 * function.
 */

#include "ascii.h"  /* Ascii art macros */
#include <stdio.h>  /* printf */
#include <stdlib.h> /* EXIT_SUCCESS */

int main(int argc, char const *argv[]) {
  /* Start a relationship with Pikachu */
  int relationship = 0;

  /* Print the initial ascii art */
  printf("Initial relationship: %d\n", relationship);
  print_ascii(relationship);

  /* Print the eating ascii art */
  printf("\nPikachu eating ascii art:\n");
  print_eating_ascii();

  /* Print the surprised ascii art */
  printf("\nPikachu surprised ascii art:\n");
  print_surprised_ascii();

  return EXIT_SUCCESS;
}
