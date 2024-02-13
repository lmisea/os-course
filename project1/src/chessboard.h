/**
 * @file chessboard.h
 *
 * @brief Header file for the chessboard-related functions and constants.
 */

#ifndef CHESSBOARD_H
#define CHESSBOARD_H

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

/**
 * @brief Allocate memory for the chessboard and initialize it.
 *
 * @return The pointer to the newly created chessboard.
 */
char **create_chessboard();

/**
 * @brief Initialize the chessboard by adding the chessboard lines and the
 * file letters and rank numbers.
 *
 * @param chessboard The chessboard 2D array to be initialized.
 */
void init_chessboard(char **chessboard);

/**
 * @brief Print the chessboard.
 *
 * @param chessboard The chessboard 2D array to be printed.
 */
void print_chessboard(char **chessboard);

#endif /* CHESSBOARD_H */
