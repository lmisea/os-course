/**
 * @file time.c
 *
 * @brief This file is used to update the balance of the player
 * and contains the function to display the time of the game.
 */

#include "time.h" /* print_time, get_active_time */
#include <time.h> /* time_t, difftime, time, localtime, struct tm */

#include <stdio.h> /* printf */

void print_time(time_t start_time) {
  time_t time_active = get_active_time(start_time);

  /* Convert the time to hours, minutes and seconds */
  int hours = time_active / 3600;
  int minutes = (time_active % 3600) / 60;
  int seconds = (time_active % 3600) % 60;

  printf(
      "\nYou have been playing for: %d hours, %d minutes and %d seconds.\n\n",
      hours, minutes, seconds);
}

time_t get_active_time(time_t start_time) {
  time_t current_time = time(NULL);
  return difftime(current_time, start_time);
}
