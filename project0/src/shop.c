/**
 * @file shop.c
 *
 * @brief This is the shop file
 */
#include "linkedList.h" /* List of purchased items*/

#include "actions.h" /* check_word */
#include "pause.h"   /* Function to pause the execution of the program */
#include "shop.h"    /* Ascii art macros */
#include "watts.h"   /* Functions to update the balance of the player */

#include <stdio.h>  /* printf */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <string.h> /* strlen, strcmp */
#include <time.h>   /* time_t */

void get_shop(int *relationship, int *balance, struct Node **head,
              char *objects[], time_t *last_checked_time) {
  char buyer[6]; /*Player's word*/

  printf("\n");
  printf("%s", STORE);

repeat:
  add_time_to_watts(last_checked_time, balance); /* Update the balance */
  show_the_store(objects);                       /* Show the items*/
  printf("Watts balance: %d\n", *balance);       /* Show the balance*/
  do {
    printf("Do you want to buy a gift? [y/N]: ");

  repeat_question:
    fgets(buyer, sizeof(buyer), stdin); /* Ask if you want to buy */
    check_word(buyer);                  /* Check if I accept or not */

    if (strcmp(buyer, "Y\n") == 0) {
      /* Case where you accept */
      buy_object(relationship, objects, balance, head);
      goto repeat; /* Show the store again */

    } else if (strcmp(buyer, "N\n") == 0 || strcmp(buyer, "Back\n") == 0) {
      /* Case not accepted */
      printf("\n");
      break;
    } else {
      /* Invalid word */
      printf("Invalid answer\n");
      printf("Try again: ");
      goto repeat_question; /* Give it one more try */
    }
  } while (1);
}

void show_the_store(char *objects[]) {
  /* Iterator */
  int i;
  int j;
  printf("*||||||||||||||||||||||||||||||||||||*\n");
  printf("* Gifts         ||Price     ||Effect *\n");
  for (i = 0; i < 9; i++) {
    printf("* ");
    print_letter(i, objects); /* Print an object */

    /* Fill with spaces if the word is less than 15 */
    if (strlen(objects[i]) < 15) {
      for (j = strlen(objects[i]); j < 15; j++) {
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

void buy_object(int *relationship, char *objects[], int *balance,
                struct Node **head) {
  /* Iterators */
  int i;
  int j = 0;
  /* Object you want to buy */
  char name_object[16];
  do {
    i = 0;
    /* Ask the item to buy */
    printf("Enter the name of the object: ");
    fgets(name_object, sizeof(name_object), stdin);

    /* Eliminate lowercase and uppercase letters */
    check_word(name_object);

    /* Get the position of the object in the list */
    i = get_index(name_object, objects, NUM_OBJECTS);

    /* Check if you want to return to the previous screen */
    if (strcmp(name_object, "Back\n") == 0) {
      break;
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
        /* Update the values and the list */
        decrease_watts(PRICE(i), balance);
        *relationship = EFFECT(i) + *relationship;
        insert_node(i, head);
        printf("\nSuccessfully purchased item.\n");
        wait_for_key(); /* Wait for the user to press a key */
        printf("\n");
        break;
      }
    }
  } while (j < 3);
}
