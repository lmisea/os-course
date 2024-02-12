/**
 * @file chessboard.c
 *
 * @brief This file contains the functions to create and print a chessboard.
 */

#include "chessboard.h"

#include <stdio.h> /* printf */

void print_rank(int rank) {
  if (rank == 8) {
    printf("%s", TOP_RANK);
  } else {
    printf("  %s", MIDDLE_RANK);
  }
  printf("%d %s", rank, MIDDLE_RANK);
  printf("%s", BOTTOM_RANK);
}

void print_chessboard() {
  for (int i = 8; i > 0; i--) {
    print_rank(i);
  }
  printf("%s", FILE_LETTERS);
}
