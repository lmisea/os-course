/**
 * @file linkedList.h
 *
 * @brief This file contains the structure and some functions of linked list.
 */

#ifndef LIST_H
#define LIST_H

/**
 * @brief This struct contains stucture of a node (element of a linked list).
 */
struct node {
  int index;              /* Position of the element in the object array */
  char *object;           /* Name of the object stored in the node */
  struct node *next_node; /* Pointer to the next node */
};

/**
 * @brief This struct contains the structure of the linked list.
 */
struct linked_list {
  struct node *head; /* Pointer to the first node */
  struct node *tail; /* Pointer to the last node */
  int size;          /* Size of the list */
};

/**
 * @brief Initialize the list
 *
 * @param list Linked list to be initialized.
 */
void initialize_list(struct linked_list *list);

/**
 * @brief Insert a node to the list
 *
 * @param list Linked list where the node will be inserted.
 * @param object Name of the object to be stored in the node.
 */
void insert_node(struct linked_list *list, char *object);

/**
 * @brief Print the list
 *
 * @param list Linked list to be printed.
 */
void print_list(struct linked_list *list);

/**
 * @brief Get the size of the list
 *
 * @param list Linked list to be consulted.
 * @return int Size of the list.
 */
int get_list_size(struct linked_list *list);

/**
 * @brief Check if an object is in the list
 *
 * @param list Linked list to be consulted.
 * @param object Name of the object to be checked.
 * @return int 1 if the object is in the list, 0 if not.
 */
int is_object_in_list(struct linked_list *list, char *object);

/**
 * @brief Get the object of the node in the index position
 *
 * @param list Linked list to be consulted.
 * @param index Position of the object in the list.
 * @return char* Name of the object in the index position. NULL if the index is
 * invalid.
 */
char *get_object_with_index(struct linked_list *list, int index);

#endif /* LIST_H */
