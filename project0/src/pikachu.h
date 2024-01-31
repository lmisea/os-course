/**
 * @file pikachu.h
 *
 * @brief This file contains the functions to see the status of our pikachu, 
 * its relationship with us and the gifted objects..
 */

#ifndef PIKACHU_H
#define PIKACHU_H
#define STATUS                                                      \
"\
               $$                  $$                        \n\
               $$                  $$                        \n\
    $$$$$$$  $$$$$$     $$$$$$   $$$$$$    $$    $$   $$$$$$$\n\
   $$          $$            $$    $$      $$    $$  $$\n\
    $$$$$$     $$       $$$$$$$    $$      $$    $$   $$$$$$ \n\
         $$    $$  $$  $$    $$    $$  $$  $$    $$        $$\n\
  /$$$$$$$/     $$$$    $$$$$$$     $$$$    $$$$$$   $$$$$$$\n"

/**
 * @brief It shows us how Pikachu is, our current relationship and the 
 * list of gifts given.
 * 
 * @param relationship Relationship with pikachu.
 * @param balance The balance you have.
 * @param head List of purchased gifts.
 * @param objects Store items.
 */
void get_pikachu(int* relationship, int* balance, struct Nodo* head, char *objects[]);

/**
 * @brief Tell how pikachu feels
 * @param relationship Relationship with pikachu.
 */
void feelings(int relationship);
#endif /* PIKACHU_H*/