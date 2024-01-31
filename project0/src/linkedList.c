/**
 * @file linkedList.c
 *
 * @brief This file contains the functions of linked list.
 */


#include "linkedList.h" /* struct Nodo*/
#include "actions.h" /* print_letter()*/

#include <stdio.h>  /* printf */
#include <stdlib.h> /* NULL */

void insertNodo(int index, struct Nodo** head_reference) {

    /* Create a space in memory to store the new node */
    struct Nodo *new_nodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    
    /* Enter the values of the new node */
    new_nodo->index = index;
    new_nodo -> nextNodo = (*head_reference);

    /* Change the head to the entered node */
    (*head_reference) = new_nodo;
}

void toString(struct Nodo* head_refence, char *objects[]) {
    struct Nodo *p = head_refence;
    printf("These are the gifts given: { ");

    /* Print each node until one points to null */
    while (p != NULL) {
        print_letter(p->index, objects);
        printf(" ");
        p = p->nextNodo;
    }
    printf("}\n");
}

int countList(struct Nodo* head_refence) {
    int count = 0;
    struct Nodo *p = head_refence;

    /* Count each node until one points to null */
    while (p != NULL) {
        count++;
        p = p->nextNodo;
    }
    return count;
}

int searchNodo(int cota, struct Nodo* head_refence) {
    int i;
    int identifier; /* Will contain the index in the array*/
    struct Nodo *p = head_refence;
    for (i = 0; i < cota; i++) {
        identifier = p->index;
        p = p->nextNodo;
    }
    return identifier;
}