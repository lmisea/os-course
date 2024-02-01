/**
 * @file play.c
 *
 * @brief This file contains the implementation of the play action.
 */

#include "play.h"       /* play function */
#include "ascii.h"      /* Ascii art macros */
#include "linkedList.h" /* List of purchased items */

#include <stdio.h> /* printf */
#include <time.h>  /* time_t */

void play(int *relationship, int *balance, struct Node *head, char *objects[],
          time_t *last_checked_time) {
  printf("Pikachu is ready to play!\nPikachu will choose a random object from "
         "the list of gifts you have given him.\nTry to guess which object he "
         "will choose.\n");
  /* Prompt the user to guess the object */
  printf("Choose an object from the list below:\n");
  print_object_list(head, objects);
  printf("Enter the name of the gift you think Pikachu will choose: ");
}
