/**
 * @file wizard_chess.c
 *
 * @brief This file contains the main function of the project.
 */

#include "chessboard.h" /* create_chessboard, print_chessboard */
#include "piece.h" /* create_user_pieces, create_computer_pieces, struct piece */

#include <stdio.h>  /* printf */
#include <stdlib.h> /* EXIT_SUCCESS */

int main(int argc, char const *argv[]) {
  struct piece *user_pieces = create_user_pieces();
  struct piece *computer_pieces = create_computer_pieces();

  char **chessboard = create_chessboard(user_pieces, computer_pieces);
  print_chessboard(chessboard);

  return EXIT_SUCCESS;
}
