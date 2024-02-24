/**
 * @file threadmove.c
 *
 * @brief Contains the way the pieces move.
 */
#include "chessboard.h" /* Chess*/
#include "movements.h"  /* generar_numero, esValidaa */
#include "piece.h"      /* struct piece */

#include <stdio.h>  /* printf */
#include <stdlib.h> /* rand*/

#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>

// HILOS
void *horse_move(void *arg) {
  struct routine_Piece *select = (struct routine_Piece *)arg;
  int move_Y;
  int move_X;
  int i = select->id;

  int num_entre_0_y_1 = generar_numero_0_o_1();

  if (num_entre_0_y_1 == 0) {
    move_X = -8;
  } else {
    move_X = 8;
  }

  move_X = select->pieces[i].x + move_X;
  if (select->pieces[i].color == 0) {
    // JUGADOR
    move_Y = -8;
    move_Y = select->pieces[i].y + move_Y;
  } else {
    // ENEMIGO
    move_Y = 8;
    move_Y = select->pieces[i].y + move_Y;
  }

  if (esValida(move_X, move_Y) == 0) {
    rewrite_position(select, move_X, move_Y, i);
  }
  close(select->pipe_1[0]);
  write(select->pipe_1[1], &select->pieces[i].x, sizeof(select->pieces[i].x));
  write(select->pipe_1[1], &select->pieces[i].y, sizeof(select->pieces[i].y));
  close(select->pipe_1[1]);

  return NULL;
}

void *king_move(void *arg) {
  struct routine_Piece *select = (struct routine_Piece *)arg;
  int move_Y;
  int move_X;
  int i = select->id;
  int num_entre_0_y_8;
  // srand(time(NULL));
  do {
    num_entre_0_y_8 = generar_numero_0_o_8();
  } while (num_entre_0_y_8 == 4);

  // printf("Este fue el numero %d\n", num_entre_0_y_8);
  if (num_entre_0_y_8 == 0) {
    move_X = -8;
    move_Y = -4;
  } else if (num_entre_0_y_8 == 1) {
    move_X = 0;
    move_Y = -4;
  } else if (num_entre_0_y_8 == 2) {
    move_X = 8;
    move_Y = -4;
  } else if (num_entre_0_y_8 == 3) {
    move_X = -8;
    move_Y = 0;
  } else if (num_entre_0_y_8 == 5) {
    move_X = 8;
    move_Y = 0;
  } else if (num_entre_0_y_8 == 6) {
    move_X = -8;
    move_Y = 4;
  } else if (num_entre_0_y_8 == 7) {
    move_X = 8;
    move_Y = 4;
  } else {
    move_X = 8;
    move_Y = 4;
  }

  move_X = select->pieces[i].x + move_X;
  move_Y = select->pieces[i].y + move_Y;
  //&& acompañado(select->pieces[i].x, select->pieces[i].y, )
  if (esValida(move_X, move_Y) == 0) {
    rewrite_position(select, move_X, move_Y, i);
  }
  close(select->pipe_1[0]);
  write(select->pipe_1[1], &select->pieces[i].x, sizeof(select->pieces[i].x));
  write(select->pipe_1[1], &select->pieces[i].y, sizeof(select->pieces[i].y));
  close(select->pipe_1[1]);

  return NULL;
}

void *casilla_actual(void *arg) {
  struct routine_Piece *select = (struct routine_Piece *)arg;
  int i = select->id;
  int casillaY = select->pieces[i].y;
  int casillaX = select->pieces[i].x;
  int casilla_Y_actualizada = 8;
  int casilla_X_actualizada = 1;
  // REVISO Y
  // printf("ANTES PC2 ID: %d, Casilla en x:%d y en y:%d\n", i,
  // select->pieces[i].casillaX, select->pieces[i].casillaY);
  for (int k = 1; k <= 32; k += 4) {
    int limite_superior = k + 4 - 1;
    if (casillaY >= i && casillaY <= limite_superior) {
      select->pieces[i].casillaY = casilla_Y_actualizada;
      break;
    }
    casilla_Y_actualizada--;
  }
  // REVISO X
  for (int k = 2; k < 66; k += 8) {
    int limite_superior = k + 8 - 1;
    if (casillaX >= k && casillaX <= limite_superior) {
      select->pieces[i].casillaX = casilla_X_actualizada;
      break;
    }
    casilla_X_actualizada++;
  }
  // printf("PC2 ID: %d, Casilla en x:%d y en y:%d\n", i,
  // select->pieces[i].casillaX, select->pieces[i].casillaY); printf("\n");
  close(select->pipe_2[0]);
  write(select->pipe_2[1], &select->pieces[i].casillaX,
        sizeof(select->pieces[i].casillaX));
  write(select->pipe_2[1], &select->pieces[i].casillaY,
        sizeof(select->pieces[i].casillaY));
  close(select->pipe_2[1]);

  return NULL;
}
