/**
 * @file pikachu.c
 *
 * @brief This file contains the functions to print the pikachu status, its
 * feelings and the list of gifts given to pikachu.
 */

#include "linkedList.h" /* struct linked_list, print_list */

#include "pikachu.h" /* Show the list*/

#include <stdio.h>  /* printf, fgets, stdin */
#include <string.h> /* strcmp */

void print_pikachu_status(int *relationship, struct linked_list *given_gifts) {
  printf("\n%s", STATUS);
  printf("\nYour current relationship with Pikachu is: %d\n", *relationship);
  printf("Pikachu is feeling ");
  get_pikachu_feelings(*relationship);
  print_given_gifts_list(given_gifts);
  printf("\n");
}

void get_pikachu_feelings(int relationship) {
  switch (relationship) {
  case 0 ... 2500:
    printf("sad.\nPikachu is not happy with you.");
    break;

  case 2501 ... 5000:
    printf("annoyed.\nPikachu still does not trust you.");
    break;

  case 5001 ... 7500:
    printf("happy.\nPikachu now feels comfortable with you.");
    break;

  case 7501 ... 10000:
    printf("very happy.\nPikachu loves you!");
    break;
  }
}

void print_given_gifts_list(struct linked_list *given_gifts) {
  /* Get the size of the list */
  int size = get_list_size(given_gifts);

  /* If the list is empty, print a message */
  if (size == 0) {
    printf("\nNo gifts have been given to Pikachu yet.\n");
    return;
  } else {
    printf("\nGifts given to Pikachu:\n");
    print_list(given_gifts);
  }
}

void print_watts(int balance) {
  printf("\nCurrent Watts balance: %d\n\n", balance);
}
