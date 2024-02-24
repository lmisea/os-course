/**
 * @file movements.h
 *
 * @brief Contains the way the pieces move.
 */

#ifndef MOVEMENTS_H
#define MOVEMENTS_H

/**
 * @return returns 0 or 1
 */
int generar_numero_0_o_1();

/**
 * @return returns an integer between 0 and 8
 */
int generar_numero_0_o_8();

/**
 * @return returns an integer between 0 and 7
 */
int generar_numero_0_o_7();

/**
 * @brief Verify that the movement is valid.
 *
 * @param x position in x.
 * @param y position in y.
 *
 * @return returns 0 or 1
 */
int esValida(int x, int y);

/**
 * @brief Select a thread to initialize it.
 *
 * @param hilos pointer to the structure containing the threads
 */

void move_piece(struct routine_Piece *hilos);

/**
 * @brief Enter the new position and write it in the pipe.
 *
 * @param select pointer to the structure containing the threads.
 * @param move_X new position in X.
 * @param move_Y new position in Y.
 * @param i position of the thread to work.
 *
 */
void rewrite_position(struct routine_Piece *select, int move_X, int move_Y,
                      int i);

#endif /* MOVEMENTS_H */
