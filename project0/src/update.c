/**
 * @file update.c
 *
 * @brief This file contains the function to update the watts balance and the
 * relationship with Pikachu, depending on the time that has passed since the
 * last time an update was made.
 */

#include "update.h" /* Function prototypes */
#include "time.h"   /* get_active_time, update_last_checked_time */

#include <stdio.h> /* printf */
#include <time.h>  /* time_t */

void update_game_status(time_t *last_update_time, int *balance,
                        int *relationship) {
  /* Get the time since the last time the balance was checked */
  time_t time_active = get_time_difference(last_update_time);

  /* Update the last time the watts balance was updated */
  update_last_update_time(last_update_time);

  /* Add the seconds to the balance */
  increase_watts(time_active, balance);

  /* Subtract the seconds from the relationship */
  decrease_relationship(time_active, relationship);
}

void increase_watts(int increment, int *balance) { *balance += increment; }

void decrease_watts(int decrement, int *balance) { *balance -= decrement; }

void print_watts(int balance) {
  printf("\nCurrent Watts balance: %d\n\n", balance);
}

void increase_relationship(int increment, int *relationship) {
  *relationship += increment;
}

void decrease_relationship(int decrement, int *relationship) {
  /* Check if the decrement is greater than the current relationship */
  if (*relationship - decrement < 0) {
    *relationship = 0;
  } else {
    *relationship -= decrement;
  }
}
