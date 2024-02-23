/**
 * @file piece.c
 *
 * @brief This file contains the functions to create and print a piece.
 */

#include "piece.h" /* struct piece */

#include <stdio.h>  /* printf */
#include <stdlib.h> /* malloc */

struct piece *create_user_pieces() {
  struct piece *user_pieces = (struct piece *)malloc(8 * sizeof(struct piece));
  for (int i = 0; i < 8; i++) {
    if (i == 4) {
      user_pieces[i] = create_piece(KING, ((i + 1) * 6) + 2 * i, 30, i+1, 1, WHITE);
      continue;
    }
    user_pieces[i] = create_piece(KNIGHT, ((i + 1) * 6) + 2 * i, 30, i+1, 1, WHITE);
  }
  return user_pieces;
}

struct piece *create_computer_pieces() {
  struct piece *computer_pieces =
      (struct piece *)malloc(8 * sizeof(struct piece));
  for (int i = 0; i < 8; i++) {
    if (i == 4) {
      computer_pieces[i] = create_piece(KING, ((i + 1) * 6) + 2 * i, 2, i+1, 8 ,BLACK);
      continue;
    }
    computer_pieces[i] = create_piece(KNIGHT, ((i + 1) * 6) + 2 * i, 2, i+1, 8, BLACK);
  }
  return computer_pieces;
}

struct routine_Piece *create_routine_pieces(struct piece *piece, char ** chessboard /*int *pipe1, int *pipe2*/) {
  struct routine_Piece *routine_pieces =
      (struct routine_Piece *)malloc(8 * sizeof(struct routine_Piece));
  for (int i = 0; i < 8; i++) {
    routine_pieces[i].chessboard = chessboard;
    routine_pieces[i].pieces = piece;
    //routine_pieces[i].pipe_1 = pipe1;
    //routine_pieces[i].pipe_2 = pipe2;
    routine_pieces[i].id = i;
  }
  return routine_pieces;
}

struct piece create_piece(enum piece_type type, int x, int y, int casillaX, int casillaY,
                          enum piece_color color) {
  struct piece p;
  p.status = INBOARD;
  p.type = type;
  p.x = x;
  p.y = y;
  p.casillaX = casillaX;
  p.casillaY = casillaY;
  p.color = color;
  switch (type) {
  case KING:
    p.symbol = (color == WHITE) ? WHITE_KING : BLACK_KING;
    break;
  case KNIGHT:
    p.symbol = (color == WHITE) ? WHITE_KNIGHT : BLACK_KNIGHT;
    break;
  }
  return p;
}

void print_piece(struct piece p) { printf("%c", p.symbol); }
