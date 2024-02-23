/**
 * @file pipe.c
 *
 * @brief Contains the way the pieces move.
 */
#include "piece.h" /* struct piece */
#include "chessboard.h" /* Chess*/

#include <stdio.h>  /* printf */
#include <stdlib.h> /* rand*/

#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

void read_pipe(struct routine_Piece *hilos, struct piece *pieces) {
    // Read with the pipes if there were changes in the positions of the player's pieces
    for (int i = 0; i < 8; i++) {
    close(hilos[i].pipe_1[1]);
    read(hilos[i].pipe_1[0], &pieces[i].x, sizeof(pieces[i].x));
    read(hilos[i].pipe_1[0], &pieces[i].y, sizeof(pieces[i].y));
    close(hilos[i].pipe_1[0]);
    }

    for (int i = 0; i < 8; i++) {
    close(hilos[i].pipe_2[1]);
    read(hilos[i].pipe_2[0], &pieces[i].casillaX, sizeof(pieces[i].casillaX));
    read(hilos[i].pipe_2[0], &pieces[i].casillaY, sizeof(pieces[i].casillaY));
    close(hilos[i].pipe_2[0]);
    }
}

void init_pipe(struct routine_Piece *hilos) {
    for (int i = 0; i < 8; ++i) {
      pipe(hilos[i].pipe_1);
    }
    for (int i = 0; i < 8; ++i) {
      pipe(hilos[i].pipe_2);
    }
}
