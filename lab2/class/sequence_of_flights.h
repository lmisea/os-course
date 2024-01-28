#ifndef SEQUENCE_OF_FLIGHTS_H
#define SEQUENCE_OF_FLIGHTS_H

#include <time.h> /* time_t */

/**
 * Represents the class of a flight.
 *
 * The possible values are:
 * - ECON: Economy class.
 * - BUS: Business class.
 * - FIRST: First class.
 */
enum clases { ECON, BUS, FIRST };

/**
 * Represents a terminal in an airport.
 *
 * Each terminal has the following properties:
 * - terminal_number: The number of the terminal for European airports.
 * - terminal_letter: The letter of the terminal for American airports.
 */
union terminal {
  int terminal_number;  /* Number of the terminal for European airports */
  char terminal_letter; /* Letter of the terminal for American airports */
};

/**
 * Represents a flight in a sequence of flights.
 *
 * Each flight has the following properties:
 * - origin: A 3-character string representing the IATA code of the origin
 * airport.
 * - destination: A 3-character string representing the IATA code of the
 * destination airport.
 * - flight_code: A 5-character string representing the flight code.
 * - flight_class: An enum value representing the class of the flight (ECONOMY,
 * BUSINESS, FIRST).
 * - airplane_seat: A 3-character string representing the seat number on the
 * airplane.
 * - departure_time: A time_t value representing the departure time of the
 * flight.
 * - arrival_time: A time_t value representing the arrival time of the flight.
 * - departure_terminal: A union value representing the terminal of departure.
 * It can be either a number for European airports or a letter for American
 * airports.
 * - departure_gate: An integer representing the gate of departure.
 * - arrival_terminal: A union value representing the terminal of arrival. It
 * can be either a number for European airports or a letter for American
 * airports.
 * - arrival_gate: An integer representing the gate of arrival.
 */
struct flight {
  char origin[4];                    /* The origin of the flight */
  char destination[4];               /* The destination of the flight */
  char flight_code[6];               /* The flight code */
  enum clases flight_class;          /* The class of the flight */
  char airplane_seat[4];             /* The seat of the airplane */
  time_t departure_time;             /* The time of departure */
  time_t arrival_time;               /* The time of arrival */
  union terminal departure_terminal; /* The terminal of departure */
  int departure_gate;                /* The gate of departure */
  union terminal arrival_terminal;   /* The terminal of arrival */
  int arrival_gate;                  /* The gate of arrival */
};

/**
 * Represents a sequence of flights.
 *
 * Each sequence of flights has the following properties:
 * - flights: An array of flight structures.
 * - num_flights: The number of flights in the sequence.
 */
struct sequence_of_flights {
  struct flight *flights; /* The array of flights */
  int num_flights;        /* The number of flights */
};

/* Function prototypes */

/**
 * Creates a sequence of flights.
 *
 * @param num_flights: The number of flights in the sequence.
 *
 * @return A pointer to a sequence of flights structure.
 */
struct sequence_of_flights *create_sequence_of_flights(int num_flights);

/**
 * Prompts the user for flight information and stores it in the provided flight
 * structure.
 *
 * @param flight: A pointer to a flight structure where the flight information
 * will be stored. This structure must be allocated before calling this
 * function.
 *
 * @param flight_number: The number of the flight in the sequence. This is used
 * to determine the origin of the flight.
 *                       - If flight_number is even, the flight is assumed to
 * depart from an American airport.
 *                       - If flight_number is odd, the flight is assumed to
 * depart from a European airport.
 */
void get_flight_info(struct flight *flight, int flight_number);

/**
 * Prompts the user for the time of departure or arrival of a flight.
 *
 * @param time_name: The name of the time to be prompted. This is used to
 * allow the function to be used for both departure and arrival times.
 * It can be either "departure" or "arrival".
 *
 * @return The time in seconds since the Epoch.
 */
time_t get_time(char *time_name);

/**
 * Prints the information of a sequence of flights, flight by flight.
 *
 * @param sequence: A pointer to a sequence of flights structure.
 */
void print_sequence_of_flights(const struct sequence_of_flights *sequence);

/**
 * Prints the information of a flight.
 *
 * @param flight: A pointer to a flight structure.
 *
 * @param flight_number: The number of the flight in the sequence. This is used
 * to determine the origin of the flight.
 *                       - If flight_number is even, the flight is assumed to
 * depart from an American airport.
 *                       - If flight_number is odd, the flight is assumed to
 * depart from a European airport.
 */
void print_flight_info(const struct flight *flight, int flight_number);

#endif /* SEQUENCE_OF_FLIGHTS_H */
