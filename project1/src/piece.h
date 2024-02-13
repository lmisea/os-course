/**
 * @file piece.h
 *
 * @brief Header file for the piece struct and piece related functions
 */

#ifndef PIECE_H
#define PIECE_H

#define BLACK_KING "♚"
#define BLACK_KNIGHT "♞"
#define WHITE_KING "♔"
#define WHITE_KNIGHT "♘"

/**
 * @brief enum to represent the type of the piece
 */
enum piece_type { KING, KNIGHT };

/**
 * @brief enum to represent the color of the piece
 */
enum piece_color { WHITE, BLACK };

/**
 * @brief Struct to represent a piece
 */
struct piece {
  enum piece_type type;   /* Type of the piece */
  char *symbol;           /* Symbol of the piece */
  int x;                  /* X coordinate of the piece */
  int y;                  /* Y coordinate of the piece */
  enum piece_color color; /* Color of the piece */
};

/**
 * @brief Function to create a piece
 *
 * @param type Type of the piece
 * @param x X coordinate of the piece
 * @param y Y coordinate of the piece
 * @param color Color of the piece
 *
 * @return A piece with the given type, coordinates and color
 */
struct piece create_piece(enum piece_type type, int x, int y,
                          enum piece_color color);

/**
 * @brief Function to create the default pieces
 *
 * @param user_pieces Array of pieces for the user
 * @param computer_pieces Array of pieces for the computer
 */
void create_default_pieces(struct piece *user_pieces,
                           struct piece *computer_pieces);

/**
 * @brief Function to print a piece
 *
 * @param p Piece to be printed
 */
void print_piece(struct piece p);

#endif /* PIECE_H */