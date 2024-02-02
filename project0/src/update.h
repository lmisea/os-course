/**
 * @file update.h
 *
 * @brief This file contains the function prototypes for updating the watts
 * balance and the relationship with pikachu.
 */

#ifndef UPDATE_H
#define UPDATE_H

#include <time.h> /* time_t */

/**
 * @brief This function updates the game status.
 * More specifically, it updates the watts balance and the relationship with
 * pikachu, depending on the time that has passed since the last time an update
 * was made.
 */
void update_game_status(time_t *last_update_time, int *balance,
                        int *relationship);

/**
 * @brief Increase the watts balance by the given amount.
 */
void increase_watts(int amount, int *balance);

/**
 * @brief Decrease the watts balance by the given amount.
 */
void decrease_watts(int amount, int *balance);

/**
 * @brief Print the current watts balance.
 */
void print_watts(int balance);

/**
 * @brief Increase the relationship with pikachu by the given amount.
 */
void increase_relationship(int amount, int *relationship);

/**
 * @brief Decrease the relationship with pikachu by the given amount.
 */
void decrease_relationship(int amount, int *relationship);

#endif /* UPDATE_H */
