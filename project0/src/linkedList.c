/**
 * @file linkedList.c
 *
 * @brief This file contains the functions of linked list.
 */

#include "linkedList.h" /* struct linked_list, struct node */

#include <stdio.h>  /* printf */
#include <stdlib.h> /* NULL */

struct linked_list *create_linked_list() {
  /* Create a space in memory to store the list */
  struct linked_list *list =
      (struct linked_list *)malloc(sizeof(struct linked_list));

  /* Initialize the list */
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;

  return list;
}

void insert_node(struct linked_list *list, char *object) {
  /* Create a space in memory to store the new node */
  struct node *new_node = (struct node *)malloc(sizeof(struct node));

  /* Check if the new node is the head */
  if (list->head == NULL) {
    list->head = new_node;
    list->tail = new_node;
    new_node->index = 0;
    list->size = 1;
  }
  /* If the list is not empty, add the new node to the end */
  else {
    /* Set the new node as the last node */
    new_node->index = list->tail->index + 1;
    list->tail->next_node = new_node;
    list->tail = new_node;
    list->size++;
  }

  /* Set the object of the new node */
  new_node->object = object;
}

void print_list(struct linked_list *list) {
  /* Create a pointer to the node to be printed */
  struct node *node = list->head;

  /* Get the size of the list */
  int size = get_list_size(list);

  /* Print the list */
  int i; /* Iterator */
  for (i = 0; i < size; i++) {
    printf("%d) %s", i + 1, node->object);
    /* Go to the next node */
    node = node->next_node;
  }
}

int get_list_size(struct linked_list *list) { return list->size; }

int is_object_in_list(struct linked_list *list, char *object) {
  /* Create a pointer to the node to be checked */
  struct node *node = list->head;

  /* Get the size of the list */
  int size = get_list_size(list);

  /* Check if the object is in the list */
  int i; /* Iterator */
  for (i = 0; i < size; i++) {
    if (strcmp(node->object, object) == 0) {
      return 1;
    }
    node = node->next_node;
  }
  return 0;
}

char *get_object_with_index(struct linked_list *list, int index) {
  /* Create a pointer to the node to be returned */
  struct node *node = list->head;

  /* Get the size of the list */
  int size = get_list_size(list);

  /* Get the object with the index */
  int i; /* Iterator */
  for (i = 0; i < size; i++) {
    if (node->index == index) {
      return node->object;
    }
    node = node->next_node;
  }

  /* Return NULL if the index is not in the list */
  return NULL;
}
