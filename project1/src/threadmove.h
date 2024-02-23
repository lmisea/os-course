/**
 * @file threadmove.h
 *
 * @brief Contains the way the pieces move.
 */

#ifndef THREADMOVE_H
#define THREADMOVE_H

/**
 * @brief contains the movement of the horse
 *
 * @param arg contains a pointer to the structure that owns the threads.
 * 
 */
void *horse_move(void *arg);

/**
 * @brief contains the movement of the king
 *
 * @param arg contains a pointer to the structure that owns the threads.
 * 
 */
void *king_move(void *arg);

/**
 * @brief determines which square the piece is in.
 *
 * @param arg contains a pointer to the structure that owns the threads.
 * 
 */
void *casilla_actual(void *arg);

#endif /* THREADMOVE_H */