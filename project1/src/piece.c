/**
 * @file piece.c
 *
 * @brief This file contains the functions to create and print a piece.
 */

#include "piece.h" /* struct piece */

#include <stdio.h> /* printf */

struct piece create_piece(enum piece_type type, int x, int y,
                          enum piece_color color) {
  struct piece p;
  p.type = type;
  p.x = x;
  p.y = y;
  p.color = color;
  switch (type) {
  case KING:
    p.symbol = (color == WHITE) ? WHITE_KING : BLACK_KING;
    break;
  case NIGHT:
    p.symbol = (color == WHITE) ? WHITE_NIGHT : BLACK_NIGHT;
    break;
  }
  return p;
}

void print_piece(struct piece p) { printf("%s", p.symbol); }
