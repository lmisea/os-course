/**
 * @file play.h
 *
 * @brief This file contains the function prototype for the play action.
 */

#ifndef PLAY_H
#define PLAY_H

#include "linkedList.h" /* struct linked_list */

#include <time.h> /* time_t */

/**
 * @brief This function is used to play with Pikachu.
 *
 * @param relationship Relationship with Pikachu.
 * @param balance Watts balance.
 * @param given_gifts List of gifts given to Pikachu.
 * @param last_update_time Last time the watts balance was updated.
 */
void play(int *relationship, int *balance, struct linked_list *given_gifts,
          time_t *last_update_time);

#endif /* PLAY_H */
