/**
 * @file actions.c
 *
 * @brief This file contains the function that prints the actions
 * that the player can take and the function that takes the action
 * that the player wants to take.
 */

#include "actions.h" /* Actions enum and function prototypes */
#include "ascii.h"   /* Ascii art macros */

#include <ctype.h>  /* toLower */
#include <stdio.h>  /* printf, fgets, stdin */
#include <string.h> /* strcmp */

enum Actions get_action() {
  int tries = 0;   /* Number of tries */
  char action[10]; /* Action that the player wants to take */

  /* Actions that the player can take */
  char *actions[] = {"Time\n",    "Watts\n", "Shop\n",
                     "Pikachu\n", "Play\n",  "Back\n"};

  /* Loop for asking the action to the player */
  do {
    /* Print the actions*/
    printf("Available actions:\n");
    print_actions(actions);

    /* Take a action */
    printf("Enter your action: ");

    /* Label repeat, it is used for the invalid case*/
  repeat:
    fgets(action, sizeof(action), stdin);

    /* Check if the action is valid */
    if (get_index(action, actions, NUM_ACTIONS) != -1) {
      return get_index(action, actions, NUM_ACTIONS);
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

void print_actions(char *actions[]) {
  int i; /* Iterator */

  /* Print the actions*/
  for (i = 0; i < NUM_ACTIONS; i++) {
    printf("%d) %s", i + 1, *(actions + i));
  }
}

int get_index(char *action, char *actions[], int cota) {
  int i; /* Iterator */

  check_word(action);
  /* Search the action in the actions array */
  for (i = 0; i < cota; i++) {
    if (strcmp(action, actions[i]) == 0) {
      return i;
    }
  }
  return -1; /* The action is not valid */
}

void check_word(char *word) {
  int i; /* Iterator */

  /* Eliminates inconveniences with upper and lower case */
  for (i = 0; *(word + i) != '\n'; i++) {
    if (i == 0) {
      *(word + i) = toupper(*(word + i));
    } else {
      *(word + i) = tolower(*(word + i));
    }
  }
}

void print_letter(int index, char *objects[]) {
  /* Word to print */
  char *letter = objects[index];

  /* Letter by letter printing */
  while (*letter != '\n') {
    printf("%c", *letter);
    letter++;
  }
}
