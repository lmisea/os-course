/**
 * @file ascii.c
 *
 * @brief This file contains the functions that print the ascii art
 * of Pikachu.
 */

#include "ascii.h" /* Ascii art macros */
#include <stdio.h> /* printf */

void print_pikachu_banner() { printf("%s", PIKACHU_BANNER); }

void print_ascii(int relationship) {
  switch (relationship) {
  case 0 ... 2500:
    printf("%s", SAD_PIKACHU);
    break;

  case 2501 ... 5000:
    printf("%s", ANNOYED_PIKACHU);
    break;

  case 5001 ... 7500:
    printf("%s", HAPPY_PIKACHU);
    break;

  case 7501 ... 10000:
    printf("%s", REALLY_HAPPY_PIKACHU);
    break;

  default:
    printf("%s", SAD_PIKACHU);
    break;
  }
}

void print_eating_ascii() { printf("Pikachu ate it.\n%s", PIKACHU_EATING); }

void print_victory_ascii() { printf("%s", PIKACHU_WON); }

void print_defeat_ascii() { printf("%s", PIKACHU_LOST); }
