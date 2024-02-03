/**
 * @file shop.h
 *
 * @brief This file contains the functions to see the store and buy objects.
 *
 * The store ASCII banner art was created with:
 * https://www.asciiart.eu/text-to-ascii-art.
 */

#ifndef SHOP_H
#define SHOP_H

#include <time.h> /* time_t */

#define PRICE(p) (100 + (p * 100))  /* Price of the object*/
#define EFFECT(e) (100 + (e * 150)) /* Effect of the object*/
#define NUM_OBJECTS 9

/**
 * @brief ASCII art that appears when the user goes to the store.
 */
#define STORE                                                                  \
  "\
  $$$$$$$            $$                            $$\n\
  $$    $$           $$                            $$\n\
  $$    $$  $$$$$$   $$    $$   $$$$$$    $$$$$$$  $$$$$$$    $$$$$$    $$$$$$\n\
  $$$$$$$  $$    $$  $$   $$   $$    $$  $$        $$    $$  $$    $$  $$    $$\n\
  $$       $$    $$  $$$$$$    $$$$$$$$   $$$$$$   $$    $$  $$    $$  $$    $$\n\
  $$       $$    $$  $$   $$   $$              $$  $$    $$  $$    $$  $$    $$\n\
  $$        $$$$$$   $$    $$   $$$$$$$  $$$$$$$   $$    $$   $$$$$$/  $$$$$$$\n\
                                                                       $$\n\
                                                                       $$\n"

/**
 * @brief Show the pokeshop and ask if the user wants to buy something.
 *
 * @param relationship Relationship with Pikachu.
 * @param balance Watts balance.
 * @param given_gifts List of gifts given to Pikachu.
 * @param last_update_time Last time the game status was updated.
 */
void go_to_shop(int *relationship, int *balance,
                struct linked_list *given_gifts, time_t *last_update_time);

/**
 * @brief Shows the table of items, prices and effects.
 *
 * @param items Array of items in the store.
 */
void show_the_store(char *items[]);

/**
 * @brief Print an item from the store.
 *
 * @param item Item to print.
 */
void print_item(char *item);

/**
 * @brief Function that is displayed if you want to buy.
 *
 * @param relationship Relationship with pikachu.
 * @param balance The balance you have.
 * @param given_gifts List of gifts given to pikachu.
 * @param items Array of items in the store.
 * @param last_update_time Last time the game status was updated.
 */
void buy_object(int *relationship, int *balance,
                struct linked_list *given_gifts, char *items[],
                time_t *last_update_time);

#endif /* SHOP_H */
