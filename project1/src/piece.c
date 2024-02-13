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
      user_pieces[i] = create_piece(KING, ((i + 1) * 6) + 2 * i, 30, WHITE);
      continue;
    }
    user_pieces[i] = create_piece(KNIGHT, ((i + 1) * 6) + 2 * i, 30, WHITE);
  }
  return user_pieces;
}

struct piece *create_computer_pieces() {
  struct piece *computer_pieces =
      (struct piece *)malloc(8 * sizeof(struct piece));
  for (int i = 0; i < 8; i++) {
    if (i == 4) {
      computer_pieces[i] = create_piece(KING, ((i + 1) * 6) + 2 * i, 2, BLACK);
      continue;
    }
    computer_pieces[i] = create_piece(KNIGHT, ((i + 1) * 6) + 2 * i, 2, BLACK);
  }
  return computer_pieces;
}

struct piece create_piece(enum piece_type type, int x, int y,
                          enum piece_color color) {
  struct piece p;
  p.status = INBOARD;
  p.type = type;
  p.x = x;
  p.y = y;
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
