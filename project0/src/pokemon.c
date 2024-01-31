/**
 * @file pokemon.c
 *
 * @brief This is the entry point of the project and contains its main
 * function.
 */

#include "actions.h" /* Actions enum and get_action function */
#include "linkedList.h" /* List of purchased items*/
#include "pikachu.h" /* Teach the relationship and list of pikachu */
#include "shop.h"  /* Shop database and function */
#include "ascii.h"   /* Ascii art macros */

#include <stdio.h>  /* printf */
#include <stdlib.h> /* EXIT_SUCCESS */
    
int main(int argc, char const *argv[]) {
  
  int relationship = 0; /* Start a relationship with Pikachu */
  int balance = 1000;   /* Start your balance */
  struct Nodo *head = NULL; /* Start the gift list */
  /* Start the objects list */
  char *objects[] = { "Baya\n", "Bayamarga\n", "Pokeball\n", "Antiparabaya\n", "Baya misterio\n", 
        "Baya milagro\n", "Baya dorada\n" ,"Baya importada\n", "Caramelo raro\n"};  

  /* Prompt the user to choose an action */
  do {
    /* Print the ascii art corresponding to the relationship */
    print_ascii(relationship);

    switch (get_action()) {
    case TIME:
      printf("Se ha detectado la accion Time\n");
      break;

    case WATTS:
      printf("Se ha detectado la accion Watts\n");
      break;

    case SHOP:
      get_shop(&relationship, &balance, &head, objects);
      break;

    case PIKACHU:
      get_pikachu(&relationship, &balance, head, objects);
      break;

    case PLAY:
      printf("Se ha detectado la accion Play\n");
      break;

    case BACK:
      printf("Pikachu says goodbye.\n");
      return EXIT_SUCCESS;

    default:
      printf("Se ha detectado la accion Time\n");
      break;
    }
  } while(relationship != 1);
  return EXIT_SUCCESS;
}
