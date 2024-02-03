/**
 * @file play.c
 *
 * @brief This file contains the implementation of the play action.
 */

#include "play.h"       /* play function */
#include "actions.h"    /* format_input */
#include "ascii.h"      /* ASCII art macros for pikachu victory or defeat */
#include "linkedList.h" /* struct linked_list */
#include "pause.h"      /* wait_for_key */
#include "pikachu.h"    /* print_given_gifts_list */

#include <stdio.h> /* printf, fgets, stdin */
#include <time.h>  /* time_t */

void play(int *relationship, int *balance, struct linked_list *given_gifts,
          time_t *last_update_time, int *choice_ptr) {
  char user_choice[6]; /* User's choice */

  printf(
      "\nPikachu is ready to play!\nPikachu will choose a random object from "
      "the list of gifts you have given him.\nTry to guess which object he "
      "will choose.\n\n");

  /* Loop to ask if the user wants to play */
  do {
    printf("Do you want to play with Pikachu? [y/N]: ");

    fgets(user_choice, sizeof(user_choice),
          stdin); /* Ask if the user wants to play */

    format_input(user_choice); /* Format the input */

    if (strcmp(user_choice, "Y\n") == 0) {
      /* The user wants to play */
      user_wants_to_play(relationship, balance, given_gifts, last_update_time,
                         choice_ptr);
    } else if (strcmp(user_choice, "N\n") == 0 ||
               strcmp(user_choice, "Back\n") == 0) {
      /* The user does not want to play */
      printf("\n");
      return;
    } else {
      /* Case where the input is not valid */
      printf("Invalid answer. Answer with [y/N].\n");
    }
  } while (1);
}

void user_wants_to_play(int *relationship, int *balance,
                        struct linked_list *given_gifts,
                        time_t *last_update_time, int *choice_ptr) {
  char user_choice[16]; /* User's choice */

  /* Prompt the user to guess the object */
  printf("\nChoose an object from the list below:");
  print_given_gifts_list(given_gifts);
  printf("Enter the name of the gift you think Pikachu will choose: ");
  fgets(user_choice, sizeof(user_choice), stdin);

  format_input(user_choice); /* Format the input */

  /* Get the random gift chosen by Pikachu */
  char *pikachu_choice = get_object_with_index(given_gifts, *choice_ptr);

  printf("\nYou chose: %s", user_choice);
  printf("Pikachu chose: %s\n", pikachu_choice);
  wait_for_key();
  printf("\n");
}
