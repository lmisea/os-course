#ifndef TIME_FILE_H
#define TIME_FILE_H

#include <time.h> /* time_t */

/**
 * @brief Print the time the program was run
 */
void print_time(time_t start_time);

/**
 * @brief Get the time since the start time
 */
time_t get_active_time(time_t start_time);

#endif /* TIME_FILE_H */
