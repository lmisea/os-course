/**
 * @file linkedList.c
 *
 * @brief This file contains the functions of linked list.
 */

#include "linkedList.h" /* struct Node*/
#include "actions.h"    /* print_letter()*/

#include <stdio.h>  /* printf */
#include <stdlib.h> /* NULL */

void insert_node(int index, struct Node **head_reference) {

  /* Create a space in memory to store the new node */
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

  /* Enter the values of the new node */
  new_node->index = index;
  new_node->next_node = (*head_reference);

  /* Change the head to the entered node */
  (*head_reference) = new_node;
}

void print_object_list(struct Node *head_refence, char *objects[]) {
  struct Node *p = head_refence;
  printf("These are the gifts given: { ");

  /* Print each node until one points to null */
  while (p != NULL) {
    print_letter(p->index, objects);
    printf(" ");
    p = p->next_node;
  }
  printf("}\n");
}

int count_list(struct Node *head_refence) {
  int count = 0;
  struct Node *p = head_refence;

  /* Count each node until one points to null */
  while (p != NULL) {
    count++;
    p = p->next_node;
  }
  return count;
}

int search_node(int cota, struct Node *head_refence) {
  int i;
  int identifier; /* Will contain the index in the array*/
  struct Node *p = head_refence;
  for (i = 0; i < cota; i++) {
    identifier = p->index;
    p = p->next_node;
  }
  return identifier;
}
