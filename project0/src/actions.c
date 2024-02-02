/**
 * @file actions.c
 *
 * @brief This file contains the function that prints the actions
 * that the player can take and the function that takes the action
 * that the player wants to take.
 */

#include "actions.h" /* enum actions, NUM_OF_ACTIONS, functions prototypes */
#include "ascii.h"   /* Ascii art macros */

#include <ctype.h>  /* toLower */
#include <stdio.h>  /* printf, fgets, stdin */
#include <string.h> /* strcmp */

enum actions get_action() {
  int tries = 0;   /* Number of tries */
  char action[10]; /* Action that the player wants to take */

  /*
   + Array containing the actions that the player can take.
   * static is used to crate only one instance of the array
   * and not one for each function call.
   */
  static const char *actions[] = {"Time\n",    "Watts\n", "Shop\n",
                                  "Pikachu\n", "Play\n",  "Back\n"};

  /* Loop for asking the action to the player */
  do {
    /* Print the actions*/
    printf("Available actions:\n");
    print_actions(actions);

    /* Ask the user for the action to take */
    printf("Enter your action: ");

    /* Label repeat, it is used for the invalid case*/
  repeat:
    fgets(action, sizeof(action), stdin);
    format_input(action); /* Convert user input to correct format */

    /* Check if the action is valid */
    if (get_action_index(action, actions) != -1) {
      return get_action_index(action, actions);
    } else {
      printf("Action Invalid\n");
      printf("Please enter a valid action: ");
      tries++; /* Increase the number of tries */
      /* If the player enters an invalid action 5 times, Pikachu gets tired */
      if (tries == 5) {
        printf("Too many tries. Pikachu is tired.\n");
        return BACK;
      }
      goto repeat;
    }
  } while (1);
}

void print_actions(const char *actions[]) {
  int i; /* Iterator */

  /* Print the actions*/
  for (i = 0; i < NUM_OF_ACTIONS; i++) {
    printf("%d) %s", i + 1, *(actions + i));
  }
}

int get_action_index(char *action, const char *actions[]) {
  int i; /* Iterator */

  /* Search the action in the actions array */
  for (i = 0; i < NUM_OF_ACTIONS; i++) {
    if (strcmp(action, actions[i]) == 0) {
      return i;
    }
  }
  return -1; /* The action is not valid */
}

void format_input(char *input) {
  int i; /* Iterator */

  /* Eliminates inconveniences with upper and lower case */
  for (i = 0; *(input + i) != '\n'; i++) {
    if (i == 0) {
      *(input + i) = toupper(*(input + i));
    } else {
      *(input + i) = tolower(*(input + i));
    }
  }
}
