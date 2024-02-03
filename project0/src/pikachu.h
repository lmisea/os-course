/**
 * @file pikachu.h
 *
 * @brief This file contains the STATUS macro and the function prototypes for
 * showing the pikachu status and its feelings.
 *
 * The status ASCII banner art was created with:
 * https://www.asciiart.eu/text-to-ascii-art.
 */

#ifndef PIKACHU_H
#define PIKACHU_H

#include "linkedList.h" /* struct linked_list */

/**
 * ASCII art that appears when checking the pikachu status.
 */
#define STATUS                                                                 \
  "\
               $$                  $$                        \n\
               $$                  $$                        \n\
    $$$$$$$  $$$$$$     $$$$$$   $$$$$$    $$    $$   $$$$$$$\n\
   $$          $$            $$    $$      $$    $$  $$\n\
    $$$$$$     $$       $$$$$$$    $$      $$    $$   $$$$$$ \n\
         $$    $$  $$  $$    $$    $$  $$  $$    $$        $$\n\
  /$$$$$$$/     $$$$    $$$$$$$     $$$$    $$$$$$   $$$$$$$\n"

/**
 * @brief Print the relationship status with pikachu and its feelings, along
 * with the list of gifts that have been given to pikachu.
 *
 * @param relationship Relationship with pikachu.
 * @param given_gifts List of gifts that have been given to pikachu.
 */
void print_pikachu_status(int *relationship, struct linked_list *given_gifts);

/**
 * @brief Print the pikachu feelings based on the relationship.
 *
 * @param relationship Relationship with pikachu.
 */
void get_pikachu_feelings(int relationship);

/**
 * @brief Print the list of gifts that have been given to pikachu.
 *
 * @param given_gifts List of gifts that have been given to pikachu.
 */
void print_given_gifts_list(struct linked_list *given_gifts);

/**
 * @brief Print the current watts balance.
 *
 * @param balance Current watts balance.
 */
void print_watts(int balance);

#endif /* PIKACHU_H*/
