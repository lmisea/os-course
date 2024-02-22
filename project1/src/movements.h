/**
 * @file movements.h
 *
 * @brief Contains the way the pieces move.
 */

#ifndef MOVEMENTS_H
#define MOVEMENTS_H

/**
 * @brief Form of horse movements
 *
 */


int generar_numero_0_o_1();
void sendPosition(struct piece *pieces, int i, int *fd);
void receivePosition(struct piece *pieces, int i, int *fd);

void *horse_move(void *arg);

void sendMatrix(int fd[], char **chessboard);
void receiveMatrix(int fd[] ,char **chessboard);
#endif /* MOVEMENTS_H */