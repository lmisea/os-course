/**
 * @file pause.h
 *
 * @brief Function prototype for the wait_for_key function
 */

#ifndef PAUSE_H
#define PAUSE_H

/**
 * @brief Pause the program until the user presses a key (Windows) or
 * enter (Linux).
 */
void wait_for_key(void);

/**
 * @brief Clear the input buffer.
 */
void clear_input_buffer(void);

#endif /* PAUSE_H */
