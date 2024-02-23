/**
 * @file pipe.h
 *
 * @brief Contains the pipe function.
 */

#ifndef PIPE_H
#define PIPE_H

/**
 * @brief reads the pipe buffers of each thread.
 * @param hilos contains a pointer to the structure that owns the threads.
 * @param pieces pointer to the set of pieces.
 * 
 */

void read_pipe(struct routine_Piece *hilos, struct piece *pieces);

/**
 * @brief Start the pipes of the thread structure
 * @param hilos contains a pointer to the structure that owns the threads.

 */

void init_pipe(struct routine_Piece *hilos);

#endif /* MOVEMENTS_H */