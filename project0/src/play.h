/**
 * @file play.h
 *
 * @brief This file contains the functions prototypes for the play action.
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
 * @param choice_ptr Pointer to Pikachu's choice.
 */
void play(int *relationship, int *balance, struct linked_list *given_gifts,
          time_t *last_update_time, int *choice_ptr);

/**
 * @brief This function is used when the user chooses to play with Pikachu.
 *
 * @param relationship Relationship with Pikachu.
 * @param balance Watts balance.
 * @param given_gifts List of gifts given to Pikachu.
 * @param last_update_time Last time the watts balance was updated.
 * @param choice_ptr Pointer to Pikachu's choice.
 */
void user_wants_to_play(int *relationship, int *balance,
                        struct linked_list *given_gifts,
                        time_t *last_update_time, int *choice_ptr);

#endif /* PLAY_H */
