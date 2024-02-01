/**
 * @file pikachu.c
 *
 * @brief This file contains the functions to see the status of our pikachu,
 * its relationship with us and the gifted objects.
 */

#include "linkedList.h" /* Show the list*/

#include "pikachu.h" /* Show the list*/

#include <stdio.h>  /* printf, fgets, stdin */
#include <string.h> /* strcmp */

void get_pikachu(int *relationship, int *balance, struct Nodo *head,
                 char *objects[]) {
  *balance = *balance + 10;
  printf("\n%s", STATUS);
  printf("\nYour current relationship with Pikachu is: %d\n", *relationship);
  printf("Pikachu is ");
  feelings(*relationship);
  toString(head, objects);
  printf("\n");
}

void feelings(int relationship) {
  switch (relationship) {
  case 0 ... 2500:
    printf("sad\n");
    break;

  case 2501 ... 5000:
    printf("annoyed\n");
    break;

  case 5001 ... 7500:
    printf("happy\n");
    break;

  case 7501 ... 10000:
    printf("really happy\n");
    break;
  default:
    break;
  }
}
