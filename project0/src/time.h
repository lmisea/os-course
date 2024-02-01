/**
 * @file time.h
 *
 * @brief Function prototypes for the functions that print the time since the
 * program started and get the time since the program started
 */

#ifndef TIME_FILE_H
#define TIME_FILE_H

#include <time.h> /* time_t */

/**
 * @brief Print the time since the program started in hours, minutes, and
 * seconds
 *
 * @param start_time The time the program started.
 */
void print_time(time_t *start_time);

/**
 * @brief Get the time since the start time in seconds
 *
 * @param time_to_compare The time to compare to the start time.
 * @return The time since the start time in seconds.
 */
time_t get_time_difference(time_t *time_to_compare);

/**
 * @brief Update the last checked time to the current time
 *
 * @param last_checked_time The last time the balance was checked.
 */
void update_last_checked_time(time_t *last_checked_time);

#endif /* TIME_FILE_H */
