/**
 * @file chessboard.h
 *
 * @brief Header file for the chessboard-related functions and constants.
 */

#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "piece.h" /* struct piece */

/**
 * @brief The top line of the chessboard.
 */
#define TOP_LINE                                                               \
  "   _______ _______ _______ _______ _______ _______ _______ _______ \n"

/**
 * @brief An empty line in the middle of the chessboard.
 */
#define MIDDLE_LINE                                                            \
  "  |       |       |       |       |       |       |       |       |\n"

/**
 * @brief The bottom line of a square in the chessboard.
 */
#define BOTTOM_LINE                                                            \
  "  |_______|_______|_______|_______|_______|_______|_______|_______|\n"

/**
 * @brief The file letters of the chessboard, displayed at the bottom of the
 * chessboard.
 */
#define FILE_LETTERS                                                           \
  "      a       b       c       d       e       f       g       h    \n"

/**
 * @brief The rank numbers of the chessboard, displayed at the left of the
 * chessboard.
 */
#define RANK_NUMBERS "87654321"

/**
 * @brief The number of rows in the chessboard.
 */
#define NUM_OF_ROWS 34

/**
 * @brief The number of columns in the chessboard.
 */
#define NUM_OF_COLUMNS 68

#define NUM_HILOS 8

/**
 * @brief Allocate memory for the chessboard and initialize it.
 *
 * @param user_pieces The array of pieces for the user.
 * @param computer_pieces The array of pieces for the computer.
 *
 * @return The pointer to the chessboard 2D array newly created.
 */
char **create_chessboard(struct piece *user_pieces,
                         struct piece *computer_pieces);

/**
 * @brief Initialize the chessboard by adding the chessboard lines and the
 * file letters and rank numbers.
 *
 * @param chessboard The chessboard 2D array to be initialized.
 */
void init_chessboard(char **chessboard);

/**
 * @brief Add the pieces to the chessboard.
 *
 * @param chessboard The chessboard 2D array to add the pieces to.
 * @param user_pieces The array of pieces for the user.
 * @param computer_pieces The array of pieces for the computer.
 */
void add_default_pieces_to_chessboard(char **chessboard,
                                      struct piece *user_pieces,
                                      struct piece *computer_pieces);

/**
 * @brief Add a piece to the chessboard.
 *
 * @param chessboard The chessboard 2D array to add the piece to.
 * @param p The piece to be added to the chessboard.
 */
void add_piece_to_chessboard(char **chessboard, struct piece p);

/**
 * @brief Print the chessboard.
 *
 * @param chessboard The chessboard 2D array to be printed.
 */
void print_chessboard(char **chessboard);

#endif /* CHESSBOARD_H */
