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
  int relationship = 0;                  /* Start a relationship with Pikachu */
  time_t start_time = time(NULL);        /* Start the time */
  time_t last_checked_time = time(NULL); /* Record the last time the balance was
                                            checked */
  int balance = 0;                       /* Start the watts balance */
  struct Node *head = NULL;              /* Start the gift list */
  /* Start the objects list */
  char *objects[] = {"Baya\n",         "Bayamarga\n",      "Pokeball\n",
                     "Antiparabaya\n", "Baya misterio\n",  "Baya milagro\n",
                     "Baya dorada\n",  "Baya importada\n", "Caramelo raro\n"};

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
      add_time_to_watts(&last_checked_time, &balance);
      print_watts(balance);
      wait_for_key();
      break;

    case SHOP:
      increase_watts(10, &balance);
      add_time_to_watts(&last_checked_time, &balance);
      get_shop(&relationship, &balance, &head, objects, &last_checked_time);
      break;

    case PIKACHU:
      increase_watts(10, &balance);
      add_time_to_watts(&last_checked_time, &balance);
      get_pikachu(&relationship, &balance, head, objects);
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
  } while (relationship != -1);
  return EXIT_SUCCESS;
}
