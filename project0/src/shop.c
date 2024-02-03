/**
 * @file shop.c
 *
 * @brief This is the shop file
 */
#include "linkedList.h" /* List of purchased items*/

#include "actions.h" /* format_input */
#include "ascii.h"   /* ASCII art macros */
#include "pause.h"   /* Function to pause the execution of the program */
#include "shop.h"    /* Ascii art macros */
#include "update.h"  /* Functions to update the balance of the player */

#include <stdio.h>  /* printf */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <string.h> /* strlen, strcmp */
#include <time.h>   /* time_t */

void go_to_shop(int *relationship, int *balance,
                struct linked_list *given_gifts, time_t *last_update_time) {
  /*
   + Array of items in the store.
   * static is used to crate only one instance of the array
   * and not one for each function call.
   */
  static char *items[] = {
      "Baya\n",         "Bayamarga\n",      "Pokeball\n",
      "Antiparabaya\n", "Baya misterio\n",  "Baya milagro\n",
      "Baya dorada\n",  "Baya importada\n", "Caramelo raro\n"};

  char user_choice[6]; /* User choice */

  printf("\n");
  printf("%s", STORE);

repeat:
  update_game_status(last_update_time, balance,
                     relationship);        /* Update the game status */
  show_the_store(items);                   /* Show the items*/
  printf("Watts balance: %d\n", *balance); /* Show the balance*/

  /* Loop to ask if the user wants to buy */
  do {
    printf("Do you want to buy a gift? [y/N]: ");

    fgets(user_choice, sizeof(user_choice),
          stdin); /* Ask if the user wants to buy */

    format_input(user_choice); /* Convert user input to correct format */

    if (strcmp(user_choice, "Y\n") == 0) {
      /* The user wants to buy */
      buy_object(relationship, balance, given_gifts, items, last_update_time);
      goto repeat; /* Show the store again */
    } else if (strcmp(user_choice, "N\n") == 0 ||
               strcmp(user_choice, "Back\n") == 0) {
      /* Exit the store */
      printf("\n");
      break;
    } else {
      /* Invalid answer */
      printf("Invalid answer. Answer with [y/N].\n");
    }
  } while (1);
}

void show_the_store(char *items[]) {
  /* Iterator */
  int i;
  int j;
  printf("*||||||||||||||||||||||||||||||||||||*\n");
  printf("* Gifts         ||Price     ||Effect *\n");
  for (i = 0; i < 9; i++) {
    printf("* ");
    print_item(items[i]); /* Print an object */

    /* Fill with spaces if the word is less than 15 */
    if (strlen(items[i]) < 15) {
      for (j = strlen(items[i]); j < 15; j++) {
        printf(" ");
      }
    }
    /* Shows its price and the effect on pikachu */
    if (i <= 5) {
      printf("||%d Watts ||+%d   *\n", PRICE(i), EFFECT(i));
    } else {
      printf("||%d Watts ||+%d  *\n", PRICE(i), EFFECT(i));
    }
  }
  printf("*||||||||||||||||||||||||||||||||||||*\n");
  printf("\n");
}

void buy_object(int *relationship, int *balance,
                struct linked_list *given_gifts, char *items[],
                time_t *last_update_time) {
  /* Iterators */
  int i;
  int j = 0;

  char item_name[16]; /* Item the user wants to buy */

  do {
    i = 0;

    /* Ask the item to buy */
    printf("Enter the name of the item: ");
    fgets(item_name, sizeof(item_name), stdin);

    format_input(item_name); /* Convert user input to correct format */

    /* Check if you want to return to the previous screen */
    if (strcmp(item_name, "Back\n") == 0) {
      break;
    }

    update_game_status(last_update_time, balance,
                       relationship); /* Update the game status */

    /* Check if the object is in the items array */
    while (i < NUM_OBJECTS) {
      if (strcmp(item_name, items[i]) == 0) {
        break;
      }
      i++;
      if (i == NUM_OBJECTS) {
        i = -1;
      }
    }

    if (i == -1) {
      /* The object was not obtained */
      printf("Object not found, try again\n");
      j++;
    } else {
      /* The object was obtained */
      if (*balance - PRICE(i) < 0) {
        /* You don't have enough money to buy it */
        printf("\nYou don't have enough watts to buy it.\n");
        wait_for_key(); /* Wait for the user to press a key */
        printf("\n");
        break;
      } else {
        /* You have enough money to buy it */
        /* Update the balance and the relationship */
        decrease_watts(PRICE(i), balance);
        increase_relationship(EFFECT(i), relationship);
        /* Add the item to the given gifts list */
        insert_node(given_gifts, items[i]);
        /* Remove the \n from the name of the item */
        item_name[strlen(item_name) - 1] = '\0';
        printf("\nSuccessfully purchased %s.\n", item_name);
        /* Print pikachu eating if the object is not a pokeball */
        if (i != 2) {
          print_eating_ascii();
        }
        /* Print the effect of the item */
        printf("Effect: relationship +%d\n\n", EFFECT(i));
        wait_for_key(); /* Wait for the user to press a key */
        printf("\n");
        break;
      }
    }
  } while (j < 3);
}

void print_item(char *item) {
  int i; /* Iterator */

  for (i = 0; i < strlen(item) - 1; i++) {
    printf("%c", item[i]);
  }
}
