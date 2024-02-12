/**
 * @file chessboard.h
 *
 * @brief Header file for the chessboard-related functions.
 */

#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#define TOP_RANK                                                               \
  "\
   _____ _____ _____ _____ _____ _____ _____ _____\n\
  |     |     |     |     |     |     |     |     |\n"

#define MIDDLE_RANK                                                            \
  "\
|     |     |     |     |     |     |     |     |\n"

#define BOTTOM_RANK                                                            \
  "\
  |     |     |     |     |     |     |     |     |\n\
  |_____|_____|_____|_____|_____|_____|_____|_____|\n"

#define FILE_LETTERS "     a     b     c     d     e     f     g     h\n"

/**
 * @brief Print the specified rank of the chessboard.
 *
 * @param rank The rank to be printed.
 */
void print_rank(int rank);

/**
 * @brief Print the entire chessboard.
 */
void print_chessboard();

#endif /* CHESSBOARD_H */
