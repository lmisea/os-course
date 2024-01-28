/*
 * This program allows the user to register a sequence of flights. It asks the
 * user for the information of each flight and stores it in a sequence of
 * flights. Finally, it prints the information of the flights.
 */

#include <stdio.h>  /* printf, fprintf, scanf */
#include <stdlib.h> /* EXIT_SUCCESS, EXIT_FAILURE, malloc */
#include <string.h> /* strcspn */
#include <time.h>   /* time_t, struct tm, mktime */

#include "sequence_of_flights.h"

int main(int argc, char const *argv[]) {
  int num_flights; /* The number of flights */
  /* Ask how many flights the user wants to register */
  printf("How many flights do you want to register? ");
  scanf("%d", &num_flights);

  /* Create the sequence of flights */
  struct sequence_of_flights *sequence =
      create_sequence_of_flights(num_flights);

  /* Print the sequence of flights */
  print_sequence_of_flights(sequence);
  return EXIT_SUCCESS;
}

struct sequence_of_flights *create_sequence_of_flights(int num_flights) {
  struct sequence_of_flights *sequence; /* The sequence of flights */

  /* Allocate memory for the sequence of flights */
  sequence = malloc(sizeof(struct sequence_of_flights));
  /* Check if the memory was allocated */
  if (sequence == NULL) {
    fprintf(stderr, "Error: memory allocation failed\n");
    exit(EXIT_FAILURE);
  }

  /* Allocate memory for the flights */
  sequence->flights = malloc(num_flights * sizeof(struct flight));
  /* Check if the memory was allocated */
  if (sequence->flights == NULL) {
    fprintf(stderr, "Error: memory allocation failed\n");
    exit(EXIT_FAILURE);
  }

  /* Store the number of flights */
  sequence->num_flights = num_flights;

  /* Ask the user for the information of each flight */
  for (int i = 0; i < num_flights; i++) {
    printf("Enter the information of flight %d\n", i + 1);
    get_flight_info(&sequence->flights[i], i);
  }
  return sequence;
}

void get_flight_info(struct flight *flight, int flight_number) {
  int class; /* The class of the flight */

  /* Ask the user for the information of the flight */
  printf("Origin: ");
  scanf("%s", flight->origin);
  printf("Destination: ");
  scanf("%s", flight->destination);
  printf("Flight code: ");
  scanf("%s", flight->flight_code);
  printf("Class (0: Economy, 1: Business, 2: First): ");
  scanf("%d", &class);

  /* Store the class of the flight */
  switch (class) {
  case 0:
    flight->flight_class = ECON;
    break;

  case 1:
    flight->flight_class = BUS;
    break;

  case 2:
    flight->flight_class = FIRST;
    break;

  default:
    flight->flight_class = ECON;
  }

  printf("Airplane seat: ");
  scanf("%s", flight->airplane_seat);
  /* Get the time of departure */
  flight->departure_time = get_time("departure");

  /* Check if the flight is European or American */
  if (flight_number % 2 == 0) {
    /* The flight departs from America and arrives in Europe */
    printf("Departure terminal letter: ");
    scanf(" %c", &flight->departure_terminal.terminal_letter);
  }
  /* The flight departs from Europe and arrives in America */
  else {
    printf("Departure terminal number: ");
    scanf("%d", &flight->departure_terminal.terminal_number);
  }

  printf("Departure gate: ");
  scanf("%d", &flight->departure_gate);
  /* Get the time of arrival */
  flight->arrival_time = get_time("arrival");

  /* Check if the flight is European or American */
  if (flight_number % 2 == 0) {
    /* The flight departs from America and arrives in Europe */
    printf("Arrival terminal number: ");
    scanf("%d", &flight->arrival_terminal.terminal_number);
  }
  /* The flight departs from Europe and arrives in America */
  else {
    printf("Arrival terminal letter: ");
    scanf(" %c", &flight->arrival_terminal.terminal_letter);
  }

  printf("Arrival gate: ");
  scanf("%d", &flight->arrival_gate);
  printf("\n");
}

time_t get_time(char *time_name) {
  int day, month, year;      /* The date to store */
  int hour, minute, seconds; /* The hour, minute and seconds to store */
  time_t time;               /* The time to return. */

  /* Ask the user for the time of departure */
  printf("Enter the date of %s (dd/mm/yyyy): ", time_name);
  scanf("%d/%d/%d", &day, &month, &year);
  printf("Enter the time of %s (hh:mm:ss): ", time_name);
  scanf("%d:%d:%d", &hour, &minute, &seconds);

  /* Store the time */
  struct tm time_tm = {.tm_year = year - 1900,
                       .tm_mon = month - 1,
                       .tm_mday = day,
                       .tm_hour = hour,
                       .tm_min = minute,
                       .tm_sec = seconds};

  /* Convert the time into a time_t */
  time = mktime(&time_tm);
  return time;
}

void print_sequence_of_flights(const struct sequence_of_flights *sequence) {
  /* Print the information of each flight */
  for (int i = 0; i < sequence->num_flights; i++) {
    printf("Flight %d\n", i + 1);
    print_flight_info(&sequence->flights[i], i);
    printf("\n");
  }
}

void print_flight_info(const struct flight *flight, int flight_number) {
  /* Format:
   * Flight <flight_number>
   * Departure  Arrival       Flight Code   Class          Seat
   * <origin>  <destination> <flight_code> <flight_class> <airplane_seat>
   * Departure time            Departure terminal   Departure gate
   * <departure_time>         <departure_terminal> <departure_gate>
   * Arrival time              Arrival terminal     Arrival gate
   * <arrival_time>           <arrival_terminal>   <arrival_gate>
   */
  const char *class_str;    /* The class of the flight */
  char *departure_time_str; /* The time of departure */
  char *arrival_time_str;   /* The time of arrival */

  /* Store the class of the flight */
  switch (flight->flight_class) {
  case ECON:
    class_str = "ECON";
    break;
  case BUS:
    class_str = "BUS";
    break;
  case FIRST:
    class_str = "FIRST";
    break;
  default:
    class_str = "Unknown";
  }

  printf("%s\t%s\t%s\t%s\t%s\n", "Departure", "Arrival", "Flight Code", "Class",
         "Seat");
  printf("%s\t\t%s\t%s\t\t%s\t%s\n", flight->origin, flight->destination,
         flight->flight_code, class_str, flight->airplane_seat);
  printf("%s\t\t\t%s\n", "Departure time", "Departure gate");

  /* Remove the trailing newline character in the time of departure */
  departure_time_str = ctime(&flight->departure_time);
  departure_time_str[strcspn(departure_time_str, "\n")] = 0;

  /* Check if the flight is European or American */
  if (flight_number % 2 == 0) {
    /* The flight departs from America and arrives in Europe */
    printf("%s\t%c%d\n", departure_time_str,
           flight->departure_terminal.terminal_letter, flight->departure_gate);
  } else {
    /* The flight departs from Europe and arrives in America */
    printf("%s\tT%d P%d\n", departure_time_str,
           flight->departure_terminal.terminal_number, flight->departure_gate);
  }

  printf("%s\t\t\t%s\n", "Arrival time", "Arrival gate");

  /* Remove the trailing newline character in the time of arrival */
  arrival_time_str = ctime(&flight->arrival_time);
  arrival_time_str[strcspn(arrival_time_str, "\n")] = 0;

  if (flight_number % 2 == 0) {
    /* The flight departs from America and arrives in Europe */
    printf("%s\tT%d P%d\n", arrival_time_str,
           flight->arrival_terminal.terminal_number, flight->arrival_gate);
  } else {
    /* The flight departs from Europe and arrives in America */
    printf("%s\t%c%d\n", arrival_time_str,
           flight->arrival_terminal.terminal_letter, flight->arrival_gate);
  }
}
