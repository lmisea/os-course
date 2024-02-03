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
#include "update.h"     /* update_game_status */

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
      update_game_status(last_update_time, balance, relationship);
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
      clear_input_buffer(); /* Clear the input buffer */
    }
  } while (1);
}

void user_wants_to_play(int *relationship, int *balance,
                        struct linked_list *given_gifts,
                        time_t *last_update_time, int *choice_ptr) {
  char user_choice[16]; /* User's choice */
  int user_bet;         /* User's bet */

  /* Explain the betting system */
  printf(
      "\nFor each game, you can bet a certain amount of watts.\n"
      "If you guess the gift Pikachu will choose, Pikachu will charge your "
      "watts balance adding twice the amount of watts you bet.\nIf you don't "
      "guess the gift, Pikachu will consume the amount of watts you bet and "
      "convert them into relationship points.\n\n");

  /* Prompt the user to bet */
  printf("How much watts do you want to bet?: ");
  scanf("%d", &user_bet);

  clear_input_buffer(); /* Clear the input buffer */

  /* Check if the user has enough watts to bet */
  if (user_bet > *balance) {
    printf("You don't have enough watts to bet.\n");
    return;
  }

  /* Print how much the user bet */
  printf("You bet %d watts.\n", user_bet);

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

  /* Check if the user guessed the gift */
  if (strcmp(user_choice, pikachu_choice) == 0) {
    /* The user guessed the gift */
    printf("Congratulations! You guessed the gift Pikachu chose!\n");
    increase_watts(user_bet * 2, balance);
    /* Pikachu lost the game */
    printf("Pikachu lost the game and charged you %d watts back.\n",
           user_bet * 2);
    print_defeat_ascii(); /* This is an extra credit feature */
  } else {
    /* The user did not guess the gift */
    printf("You didn't guess the gift Pikachu chose.\n");
    decrease_watts(user_bet, balance);
    increase_relationship(user_bet, relationship);
    /* Pikachu won the game */
    printf("Pikachu won the game and consumed %d watts.\n", user_bet);
    print_victory_ascii(); /* This is an extra credit feature */
  }
  wait_for_key();
  printf("\n");
}
