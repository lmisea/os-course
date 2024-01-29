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

  /* Support variables*/
  int i;
  char action[10];

  /* Player actions */
  char *actions_player[] = {"Time\n", "Watts\n", "Shop\n", "Pikachu\n", "Play\n", "Back\n"};

  do {
    /* Print the initial ascii art */
    print_ascii(relationship);
    printf("Relationship: %d\n", relationship);

    /* Print the actions*/
    for (i = 0; i < sizeof(actions_player)/sizeof(actions_player[0]) -1; i++)
    {
      printf("%d) %s", i+1, *(actions_player+i));
    }

    i = 0;
    /* Take a action */
    printf("Enter your action: ");
    
    /* Label repeat, it is used for the invalid case*/
  repeat:
    fgets(action, sizeof(action), stdin);
    
    if (strcmp(action, actions_player[0]) == 0) {

      printf("Se ha detectado la accion Time\n");

    } else if(strcmp(action, actions_player[1]) == 0) {

      printf("Se ha detectado la accion Watts\n");

    } else if(strcmp(action, actions_player[2]) == 0) {

      printf("Se ha detectado la accion Shop\n");

    } else if(strcmp(action, actions_player[3]) == 0) {

      printf("Se ha detectado la accion Pikachu\n");

    } else if(strcmp(action, actions_player[4]) == 0) {

      printf("Se ha detectado la accion Play\n");

    } else if(strcmp(action, actions_player[5]) == 0) {

      printf("Se ha detectado la accion Back\n");
      continue;

    } else {
      printf("Action Invalid\n");
      printf("Please enter a valid action: ");
      i++;
      if(i == 5) {
        break;
      }
      goto repeat;
    }

  } while (strcmp(action, actions_player[5]) != 0);

  return EXIT_SUCCESS;
}

