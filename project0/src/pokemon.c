/**
 * @file pokemon.c
 *
 * @brief This is the entry point of the project and contains its main
 * function.
 */

#include "actions.h"    /* Actions enum and get_action function */
#include "ascii.h"      /* Ascii art macros */
#include "linkedList.h" /* List of purchased items*/
#include "pause.h"      /* Function to pause the execution of the program */
#include "pikachu.h"    /* Teach the relationship and list of pikachu */
#include "shop.h"       /* Shop database and function */
#include "time.h"       /* Function to display the active time of the game */
#include "watts.h"      /* Function to update the watts balance of the player */

#include <stdio.h>  /* printf */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <time.h>   /* time_t */

int main(int argc, char const *argv[]) {
  int relationship = 0;           /* Relationship with pikachu */
  time_t start_time = time(NULL); /* Time when the game started */
  int balance = 0;                /* Watts balance */
  struct linked_list given_gifts; /* List of gifts given to Pikachu */
  initialize_list(&given_gifts);  /* Initialize the list */
  /* Last time the watts balance was updated */
  time_t last_update_time = time(NULL);

  /* Prompt the user to choose an action */
  do {
    /* Print the ascii art corresponding to the relationship */
    print_ascii(relationship);

    switch (get_action()) {
    case TIME:
      increase_watts(10, &balance);
      print_time(&start_time);
      wait_for_key();
      break;

    case WATTS:
      increase_watts(10, &balance);
      add_time_to_watts(&last_update_time, &balance);
      print_watts(balance);
      wait_for_key();
      break;

    case SHOP:
      increase_watts(10, &balance);
      add_time_to_watts(&last_update_time, &balance);
      go_to_shop(&relationship, &balance, &given_gifts, &last_update_time);
      break;

    case PIKACHU:
      increase_watts(10, &balance);
      print_pikachu_status(&relationship, &given_gifts);
      wait_for_key();
      break;

    case PLAY:
      printf("Se ha detectado la accion Play\n");
      wait_for_key();
      break;

    case BACK:
      printf("Pikachu says goodbye.\n");
      return EXIT_SUCCESS;

    default:
      break;
    }
  } while (1);
  return EXIT_SUCCESS;
}
