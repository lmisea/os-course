/**
 * @file wizard_chess.c
 *
 * @brief This file contains the main function of the project.
 */

#include "chessboard.h" /* print_chessboard */
#include "piece.h"      /* create_default_pieces */

#include <stdio.h>  /* printf */
#include <stdlib.h> /* EXIT_SUCCESS */

int main(int argc, char const *argv[]) {
  struct piece user_pieces[8];
  struct piece computer_pieces[8];
  create_default_pieces(user_pieces, computer_pieces);

  char chessboard[NUM_OF_ROWS][NUM_OF_COLUMNS];
  init_chessboard(chessboard);
  print_chessboard(chessboard);

  return EXIT_SUCCESS;
}
