/**
 * @file signalP.c
 *
 * @brief Contains the signal.
 */

#include <stdio.h>  /* printf */
#include <stdlib.h> /* rand*/
#include <signal.h>

// SEÑALES 
void eliminate_piece_enemy(int sig) {
    printf("Eliminaron una pieza enemiga\n");
}
void eliminate_piece_player(int sig){
    printf("Eliminaron una pieza aliada\n");
}
void win(int sig){
    printf("Eliminaron un REY\n");
}