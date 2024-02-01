/**
 * @file play.h
 *
 * @brief This file contains the function prototype for the play action.
 */

#ifndef PLAY_H
#define PLAY_H

#include "linkedList.h" /* List of purchased items */

#include <time.h> /* time_t */

/**
 * @brief This function is used to play the game.
 *
 * @param head The head of the list of purchased items.
 */
void play(int *relationship, int *balance, struct Node *head, char *objects[],
          time_t *last_checked_time);

#endif /* PLAY_H */
