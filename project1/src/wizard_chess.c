/**
 * @file wizard_chess.c
 *
 * @brief This file contains the main function of the project.
 */

#include "chessboard.h" /* create_chessboard, print_chessboard */
#include "piece.h"      /* struct piece, create_default_pieces */

#include <stdio.h>  /* printf */
#include <stdlib.h> /* EXIT_SUCCESS */

int main(int argc, char const *argv[]) {
  struct piece user_pieces[8];
  struct piece computer_pieces[8];
  create_default_pieces(user_pieces, computer_pieces);

  char **chessboard = create_chessboard();
  print_chessboard(chessboard);

  return EXIT_SUCCESS;
}
