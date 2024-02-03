/**
 * @file pokemon.c
 *
 * @brief This is the entry point of the project and contains its main
 * function.
 */

#include "actions.h"    /* Actions enum and get_action function */
#include "ascii.h"      /* ASCII art macros */
#include "linkedList.h" /* List of purchased items*/
#include "pause.h"      /* Function to pause the execution of the program */
#include "pikachu.h"    /* Teach the relationship and list of pikachu */
#include "play.h"       /* Function to play with pikachu */
#include "shop.h"       /* Shop database and function */
#include "time.h"       /* Function to display the active time of the game */
#include "update.h"     /* Function to update the watts balance and the
                           relationship */

#include <stdio.h>  /* printf */
#include <stdlib.h> /* EXIT_SUCCESS, srand, rand */
#include <time.h>   /* time_t, time */

int main(int argc, char const *argv[]) {
  int relationship = 0;           /* Relationship with pikachu */
  time_t start_time = time(NULL); /* Time when the game started */
  int balance = 0;                /* Watts balance */
  /* List of gifts given to Pikachu */
  struct linked_list *given_gifts = create_linked_list();
  /* Last time the watts balance and the relationship were updated */
  time_t last_update_time = time(NULL);

  srand(start_time);                 /* Seed for the random number generator */
  int pikachu_choice;                /* Pikachu's choice */
  int *choice_ptr = &pikachu_choice; /* Pointer to pikachu_choice */

  /* Greet the user and explain quickly the game */
  print_pikachu_banner();
  printf(
      "\nWelcome to the Pikachu game!\n\n"
      "In this game you will have to take care of Pikachu and make him happy.\n"
      "You can do this by giving him gifts and playing with him.\n\n"
      "Buy gifts at the store with the watts you earn every second.\n"
      "(There is a rumor that says that consulting the available options "
      "from time to time is a good idea for your watts balance).\n\n"
      "Be careful! If you don't take care of Pikachu, he will get angry and "
      "the relationship will decrease.\n\n");

  wait_for_key();
  printf("Let's start!\n");

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
      update_game_status(&last_update_time, &balance, &relationship);
      print_watts(balance);
      wait_for_key();
      break;

    case SHOP:
      increase_watts(10, &balance);
      update_game_status(&last_update_time, &balance, &relationship);
      go_to_shop(&relationship, &balance, given_gifts, &last_update_time);
      break;

    case PIKACHU:
      increase_watts(10, &balance);
      update_game_status(&last_update_time, &balance, &relationship);
      print_pikachu_status(&relationship, given_gifts);
      wait_for_key();
      break;

    case PLAY:
      /* Check if Pikachu has received at least two gifts */
      if (get_list_size(given_gifts) < 2) {
        printf("\nPikachu is not in the mood to play. Give him at least two "
               "gifts.\n");
        wait_for_key();
        break;
      }
      *choice_ptr = rand() % get_list_size(given_gifts);
      play(&relationship, &balance, given_gifts, &last_update_time, choice_ptr);
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
