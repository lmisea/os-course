/**
 * @file watts.h
 *
 * @brief This file contains the function prototypes for the watts function.
 */

#ifndef WATTS_H
#define WATTS_H

#include <time.h> /* time_t */

/**
 * @brief This function updates the watts balance by as much seconds
 * as the program has been active since the last time the watts balance was
 * updated.
 *
 * @param last_update_time The last time the watts balance was updated.
 * @param balance The current watts balance.
 */
void add_time_to_watts(time_t *last_update_time, int *balance);

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

#endif /* WATTS_H */
