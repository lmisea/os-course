/**
 * @file play.c
 *
 * @brief This file contains the implementation of the play action.
 */

#include "play.h"       /* play function */
#include "ascii.h"      /* ASCII art macros for pikachu victory or defeat */
#include "linkedList.h" /* struct linked_list */

#include <stdio.h> /* printf */
#include <time.h>  /* time_t */

void play(int *relationship, int *balance, struct linked_list *given_gifts,
          time_t *last_update_time) {
  printf("Pikachu is ready to play!\nPikachu will choose a random object from "
         "the list of gifts you have given him.\nTry to guess which object he "
         "will choose.\n");
  /* Prompt the user to guess the object */
  printf("Choose an object from the list below:\n");
  printf("Enter the name of the gift you think Pikachu will choose: ");
}
