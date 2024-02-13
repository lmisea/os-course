/**
 * @file chessboard.h
 *
 * @brief Header file for the chessboard-related functions.
 */

#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#define TOP_LINE                                                               \
  "   _______ _______ _______ _______ _______ _______ _______ _______ \n"

#define MIDDLE_LINE                                                            \
  "  |       |       |       |       |       |       |       |       |\n"

#define RANK_LINE                                                              \
  " |       |       |       |       |       |       |       |       |\n"

#define BOTTOM_LINE                                                            \
  "  |_______|_______|_______|_______|_______|_______|_______|_______|\n"

#define FILE_LETTERS                                                           \
  "      a       b       c       d       e       f       g       h    \n"

#define RANK_NUMBERS "87654321"

#define NUM_OF_ROWS 34
#define NUM_OF_COLUMNS 68

/**
 * @brief Initialize the chessboard.
 *
 * @param chessboard The chessboard to be initialized.
 */
void init_chessboard(char chessboard[NUM_OF_ROWS][NUM_OF_COLUMNS]);

/**
 * @brief Print the chessboard.
 *
 * @param chessboard The chessboard to be printed.
 */
void print_chessboard(char chessboard[NUM_OF_ROWS][NUM_OF_COLUMNS]);

#endif /* CHESSBOARD_H */
