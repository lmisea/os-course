/**
 * @file piece.h
 *
 * @brief Header file for the piece struct and piece related functions
 */

#ifndef PIECE_H
#define PIECE_H

#include <pthread.h>

#define BLACK_KING 'x'
#define BLACK_KNIGHT 'z'
#define WHITE_KING 'K'
#define WHITE_KNIGHT 'N'

/**
 * @brief enum to represent the type of the piece
 */
enum piece_type { KING, KNIGHT };

/**
 * @brief enum to represent the color of the piece
 */
enum piece_color { WHITE, BLACK };

/**
 * @brief enum to represent if the piece is inboard or captured
 */
enum piece_status { INBOARD, CAPTURED };

/**
 * @brief Struct to represent a piece
 */
struct piece {
  enum piece_status status; /* Status of the piece */
  enum piece_type type;     /* Type of the piece */
  char symbol;              /* Symbol of the piece */
  int x;                    /* X coordinate of the piece */
  int y;                    /* Y coordinate of the piece */
  int casillaX;
  int casillaY;
  enum piece_color color;   /* Color of the piece */
};

/**
 * @brief Struct to represent a thread
 */
struct routine_Piece
{
  char ** chessboard;
  struct piece *pieces; 
  int pipe_1[2];
  int pipe_2[2];
  int id;
  int paciencia;
  pthread_t hilo;
};

/**
 * @brief Function to create the pieces for the user
 *
 * @return Array of pieces for the user
 */
struct piece *create_user_pieces();

/**
 * @brief Function to create the pieces for the computer
 *
 * @return Array of pieces for the computer
 */
struct piece *create_computer_pieces();

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
struct piece create_piece(enum piece_type type, int x, int y, int casillaX, int casillaY,
                          enum piece_color color);

/**
 * @brief Function to create a routine_piece
 *
 * @param piece The array of pieces .
 * @param chessboard Used chess board
 *
 * @return Arrangement containing the threads of each piece
 */
struct routine_Piece *create_routine_pieces(struct piece *piece, char ** chessboard);

/**
 * @brief Function to print a piece
 *
 * @param p Piece to be printed
 */
void print_piece(struct piece p);

#endif /* PIECE_H */
