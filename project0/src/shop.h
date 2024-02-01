/**
 * @file shop.h
 *
 * @brief This file contains the functions to see the store and buy objects.
 */

#ifndef SHOP_H
#define SHOP_H

#define PRICE(p) (100 + (p * 100))  /* Price of the object*/
#define EFFECT(e) (100 + (e * 150)) /* Effect of the object*/
#define NUM_OBJECTS 9
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
 * @brief Shows the store and asks if you want to buy
 *
 * @param relationship Relationship with pikachu.
 * @param balance The balance you have.
 * @param head List of purchased gifts.
 * @param objects Store items.
 */
void get_shop(int *relationship, int *balance, struct Nodo **head,
              char *objects[]);

/**
 * @brief Shows the table of objects, prices and relationship.
 * @param objects Store items.
 */
void show_the_store(char *objects[]);

/**
 * @brief Function that is displayed if you want to buy.
 *
 * @param relationship Relationship with pikachu.
 * @param balance The balance you have.
 * @param head List of purchased gifts.
 * @param objects Store items.
 */
void buy_object(int *relationship, char *objects[], int *balance,
                struct Nodo **head);

#endif /* SHOP_H */
