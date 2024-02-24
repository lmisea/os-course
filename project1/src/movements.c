/**
 * @file movements.h
 *
 * @brief Contains the move of piece.
 */
#include "chessboard.h" /* Chess*/
#include "piece.h"      /* struct piece */
#include "threadmove.h" /* king_move, horse_move, casilla_actual */

#include <stdio.h>  /* printf */
#include <stdlib.h> /* rand*/

#include <pthread.h>
#include <signal.h> /* kill */
#include <sys/types.h>
#include <unistd.h>

int generar_numero_0_o_1() {
  srand(time(NULL));
  return rand() % 2;
}

int generar_numero_0_o_8() {
  srand(time(NULL));
  return rand() % 9;
}

int generar_numero_0_o_7() {
  srand(time(NULL));
  return rand() % 8;
}

void move_piece(struct routine_Piece *hilos) {
  int i = generar_numero_0_o_7();

  if (i == 4) {
    pthread_create(&hilos[i].hilo, NULL, &king_move, &hilos[i]);
    sleep(1);
  } else {
    pthread_create(&hilos[i].hilo, NULL, &horse_move, &hilos[i]);
    sleep(1);
  }

  pthread_join(hilos[i].hilo, NULL);

  pthread_create(&hilos[i].hilo, NULL, &casilla_actual, &hilos[i]);
  sleep(1);

  pthread_join(hilos[i].hilo, NULL);
}

void rewrite_position(struct routine_Piece *select, int move_X, int move_Y,
                      int i) {
  if (select->pieces[i].color == 0) {
    // JUGADOR
    if (select->chessboard[move_Y][move_X] == 'z') {
      select->chessboard[select->pieces[i].y][select->pieces[i].x] = ' ';
      select->pieces[i].y = move_Y;
      select->pieces[i].x = move_X;
      select->chessboard[select->pieces[i].y][select->pieces[i].x] =
          select->pieces[i].symbol;
      kill(getppid(), SIGUSR1);
    } else if (select->chessboard[move_Y][move_X] == 'x') {
      select->chessboard[select->pieces[i].y][select->pieces[i].x] = ' ';
      select->pieces[i].y = move_Y;
      select->pieces[i].x = move_X;
      select->chessboard[select->pieces[i].y][select->pieces[i].x] =
          select->pieces[i].symbol;
      printf("The enemy king was eliminated\n");
      kill(getppid(), SIGKILL);

    } else if (select->chessboard[move_Y][move_X] != 'N' &&
               select->chessboard[move_Y][move_X] != 'K') {
      select->chessboard[select->pieces[i].y][select->pieces[i].x] = ' ';
      select->pieces[i].y = move_Y;
      select->pieces[i].x = move_X;
      select->chessboard[select->pieces[i].y][select->pieces[i].x] =
          select->pieces[i].symbol;
    }
  } else {
    // ENEMIGO
    if (select->chessboard[move_Y][move_X] == 'N') {
      select->chessboard[select->pieces[i].y][select->pieces[i].x] = ' ';
      select->pieces[i].y = move_Y;
      select->pieces[i].x = move_X;
      select->chessboard[select->pieces[i].y][select->pieces[i].x] =
          select->pieces[i].symbol;
      kill(getppid(), SIGUSR2);
    } else if (select->chessboard[move_Y][move_X] == 'K') {
      select->chessboard[select->pieces[i].y][select->pieces[i].x] = ' ';
      select->pieces[i].y = move_Y;
      select->pieces[i].x = move_X;
      select->chessboard[select->pieces[i].y][select->pieces[i].x] =
          select->pieces[i].symbol;
      printf("The player king was eliminated\n");
      kill(getppid(), SIGKILL);

    } else if (select->chessboard[move_Y][move_X] != 'z' &&
               select->chessboard[move_Y][move_X] != 'x') {
      select->chessboard[select->pieces[i].y][select->pieces[i].x] = ' ';
      select->pieces[i].y = move_Y;
      select->pieces[i].x = move_X;
      select->chessboard[select->pieces[i].y][select->pieces[i].x] =
          select->pieces[i].symbol;
    }
  }
}

int esValida(int x, int y) {
  if (y < 34 && y > 0) {
    if (x < 68 && x > 2) {
      return 0;
    }
  }
  return 1;
}
