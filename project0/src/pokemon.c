/**
 * @file pokemon.c
 *
 * @brief This is the entry point of the project and contains its main
 * function.
 */

#include "actions.h" /* Actions enum and get_action function */
#include "ascii.h"   /* Ascii art macros */

#include <stdio.h>  /* printf */
#include <stdlib.h> /* EXIT_SUCCESS */

int main(int argc, char const *argv[]) {
  /* Start a relationship with Pikachu */
  int relationship = 0;

  /* Print the ascii art corresponding to the relationship */
  print_ascii(relationship);

  /* Prompt the user to choose an action */
  switch (get_action()) {
  case TIME:
    printf("Se ha detectado la accion Time\n");
    break;

  case WATTS:
    printf("Se ha detectado la accion Watts\n");
    break;

  case SHOP:
    printf("Se ha detectado la accion Shop\n");
    break;

  case PIKACHU:
    printf("Se ha detectado la accion Pikachu\n");
    break;

  case PLAY:
    printf("Se ha detectado la accion Play\n");
    break;

  case BACK:
    printf("Pikachu says goodbye.\n");
    return EXIT_SUCCESS;

  default:
    printf("Se ha detectado la accion Time\n");
    break;
  }

  return EXIT_SUCCESS;
}
