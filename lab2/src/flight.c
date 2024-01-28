/*
 * This program asks the user for the time of departure of its flight and
 * prints how much time is left until the departure.
 */

#include <stdio.h>  /* printf, scanf */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <time.h>   /* time, localtime, time_t, struct tm, mktime, difftime */

#define MINUTE 60          /* Define a minute in seconds */
#define HOUR (60 * MINUTE) /* Define an hour in seconds */
#define DAY (24 * HOUR)    /* Define a day in seconds */
#define MONTH (30 * DAY)   /* Define a month in seconds */
#define YEAR (365 * DAY)   /* Define a year in seconds */

time_t get_departure_time(void); /* Function prototype */
void print_time_left(time_t time_left,
                     struct tm *time_left_local); /* Function prototype */

int main(int argc, char const *argv[]) {
  time_t departure_time;           /* The time of departure */
  struct tm *departure_local_time; /* The local time of departure */
  time_t now;                      /* The current time */
  struct tm *local_time;           /* The local time */
  time_t time_left;                /* The time left until the departure */
  struct tm *time_left_local;      /* The local time left until the departure */

  /* Ask the user for the time of departure */
  departure_time = get_departure_time();
  /* Get the local time of departure */
  departure_local_time = localtime(&departure_time);

  /* Get the current time */
  now = time(NULL);
  local_time = localtime(&now);

  /* Calculate the seconds left until the departure */
  time_left = (time_t)difftime(departure_time, now);
  /* Covert the time left into a local time */
  time_left_local = localtime(&time_left);

  /* Print the time left until the departure */
  print_time_left(time_left, time_left_local);
  return EXIT_SUCCESS;
}

/* Get the time of departure */
time_t get_departure_time(void) {
  int day, month, year;  /* The date of departure */
  int hour, minute;      /* The hour and minute of departure */
  time_t departure_time; /* The time of departure */

  /* Ask the user for the time of departure */
  printf("Enter the date of departure (dd/mm/yyyy): ");
  scanf("%d/%d/%d", &day, &month, &year);
  printf("Enter the time of departure (hh:mm): ");
  scanf("%d:%d", &hour, &minute);

  struct tm departure_tm = {.tm_year = year - 1900,
                            .tm_mon = month - 1,
                            .tm_mday = day,
                            .tm_hour = hour,
                            .tm_min = minute,
                            .tm_sec = 0};

  /* Store the flight time */
  departure_time = mktime(&departure_tm);
  return departure_time;
}

/* Print the time left until the departure */
void print_time_left(time_t time_left, struct tm *time_left_local) {
  /* Print the time left until the departure */
  if (time_left < 0) {
    printf("The flight has already departed.\n");
  }
  /* If the flight departs in less than a minute */
  else if (time_left < MINUTE) {
    printf("The flight departs in less than a minute.\n");
  }
  /* If the flight departs in less than an hour */
  else if (time_left < HOUR) {
    printf("The flight departs in %d minutes.\n", time_left_local->tm_min);
  }
  /* If the flight departs in less than a day */
  else if (time_left < DAY) {
    printf("The flight departs in %d hours and %d minutes.\n",
           time_left_local->tm_hour, time_left_local->tm_min);
  }
  /* If the flight departs in less than a month */
  else if (time_left < MONTH) {
    printf("The flight departs in %d days, %d hours and %d minutes.\n",
           time_left_local->tm_mday, time_left_local->tm_hour,
           time_left_local->tm_min);
  }
  /* If the flight departs in less than a year */
  else if (time_left < YEAR) {
    printf("The flight departs in %d months, %d days, %d hours and %d"
           " minutes.\n",
           time_left_local->tm_mon, time_left_local->tm_mday,
           time_left_local->tm_hour, time_left_local->tm_min);
  }
  /* If the flight departs in more than a year */
  else {
    printf("The flight departs in %d years, %d months, %d days, %d hours and %d"
           " minutes.\n",
           time_left_local->tm_year, time_left_local->tm_mon,
           time_left_local->tm_mday, time_left_local->tm_hour,
           time_left_local->tm_min);
  }
}
