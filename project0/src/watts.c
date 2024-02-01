/**
 * @file watts.c
 *
 * @brief This file contains the function to convert the active time of
 * the program into the watts currency used in the program.
 */

#include "watts.h" /* Function prototypes */
#include "time.h"  /* get_active_time, update_last_checked_time */

#include <stdio.h> /* printf */
#include <time.h>  /* time_t */

void add_time_to_watts(time_t *last_checked_time, int *balance) {
  /* Get the time since the last time the balance was checked */
  time_t time_active = get_time_difference(last_checked_time);

  /* Update the last checked time to the current time */
  update_last_checked_time(last_checked_time);

  /* Add the seconds to the balance */
  increase_watts(time_active, balance);
}

void increase_watts(int increment, int *balance) { *balance += increment; }

void decrease_watts(int decrement, int *balance) { *balance -= decrement; }

void print_watts(int balance) {
  printf("\nCurrent Watts balance: %d\n\n", balance);
}
