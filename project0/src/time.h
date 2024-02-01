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
 */
void print_time(time_t start_time);

/**
 * @brief Get the time since the start time in seconds
 */
time_t get_active_time(time_t start_time);

#endif /* TIME_FILE_H */
