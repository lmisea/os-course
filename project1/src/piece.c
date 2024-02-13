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
  case KNIGHT:
    p.symbol = (color == WHITE) ? WHITE_KNIGHT : BLACK_KNIGHT;
    break;
  }
  return p;
}

void print_piece(struct piece p) { printf("%s", p.symbol); }

void create_default_pieces(struct piece *user_pieces,
                           struct piece *computer_pieces) {
  for (int i = 0; i < 8; i++) {
    if (i == 5) {
      user_pieces[i] = create_piece(KING, (i + 1) * 6, 4, WHITE);
      computer_pieces[i] = create_piece(KING, (i + 1) * 6, 32, BLACK);
      continue;
    }
    user_pieces[i] = create_piece(KNIGHT, (i + 1) * 6, 4, WHITE);
    computer_pieces[i] = create_piece(KNIGHT, (i + 1) * 6, 32, BLACK);
  }
}
