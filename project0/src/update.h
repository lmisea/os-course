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
 *
 * @param last_update_time Last time the watts balance and the relationship were
 * updated.
 * @param balance Pointer to the watts balance.
 * @param relationship Pointer to the relationship with pikachu.
 */
void update_game_status(time_t *last_update_time, int *balance,
                        int *relationship);

/**
 * @brief Increase the watts balance by the given amount.
 *
 * @param increment Amount to increase the watts balance by.
 * @param balance Pointer to the watts balance.
 */
void increase_watts(int increment, int *balance);

/**
 * @brief Decrease the watts balance by the given amount.
 *
 * @param decrement Amount to decrease the watts balance by.
 * @param balance Pointer to the watts balance.
 */
void decrease_watts(int decrement, int *balance);

/**
 * @brief Increase the relationship with pikachu by the given amount.
 * If the relationship plus the increment is greater than 10000, the
 * relationship will be set to 10000.
 *
 * @param increment Amount to increase the relationship by.
 * @param relationship Pointer to the relationship with pikachu.
 */
void increase_relationship(int increment, int *relationship);

/**
 * @brief Decrease the relationship with pikachu by the given amount.
 * If the decrement is greater than the current relationship, the relationship
 * will be set to 0.
 *
 * @param decrement Amount to decrease the relationship by.
 * @param relationship Pointer to the relationship with pikachu.
 */
void decrease_relationship(int decrement, int *relationship);

#endif /* UPDATE_H */
