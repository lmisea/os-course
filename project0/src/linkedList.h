/**
 * @file linkedList.h
 *
 * @brief This file contains the structure and some functions of linked list.
 */

#ifndef LIST_H
#define LIST_H

/**
 * @brief This struct contains stucture of the nodo.
 */
struct Node {
  int index;
  struct Node *next_node;
};

/**
 * @brief Insert a node to the list
 *
 * @param index Position in the list of objects
 * @param head_reference List Head Pointer Pointer.
 */
void insert_node(int index, struct Node **head_reference);

/**
 * @brief Shows list items
 *
 * @param head_reference List Head Pointer .
 * @param objects Arrangement with available objects.
 */
void print_object_list(struct Node *head_reference, char *objects[]);

/**
 * @brief Indicates how many elements are in the list
 *
 * @param head_reference List Head Pointer .
 * @return Return how many elements there are.
 */
int count_list(struct Node *head_reference);

/**
 * @brief Shows the store and asks if you want to buy
 *
 * @param cota Indicates how far to search.
 * @param head_reference List Head Pointer .
 *
 * @return Returns the position of the element in the object array.
 */
int search_node(int cota, struct Node *head_reference);

#endif /* LIST_H */
