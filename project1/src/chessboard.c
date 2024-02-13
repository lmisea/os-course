/**
 * @file chessboard.c
 *
 * @brief This file contains the functions to create and print a chessboard.
 */

#include "chessboard.h"

#include <stdio.h> /* printf */

void init_chessboard(char chessboard[NUM_OF_ROWS][NUM_OF_COLUMNS]) {
  int rank_index = 0;
  for (int i = 0; i < NUM_OF_ROWS; i++) {
    for (int j = 0; j < NUM_OF_COLUMNS; j++) {
      switch (i % 4) {
      case 0:
        if (i == 0) {
          chessboard[i][j] = TOP_LINE[j];
        } else {
          chessboard[i][j] = BOTTOM_LINE[j];
        }
        break;
      case 1:
        if (i < NUM_OF_ROWS - 1) {
          chessboard[i][j] = MIDDLE_LINE[j];
        } else {
          chessboard[i][j] = FILE_LETTERS[j];
        }
        break;
      case 2:
        if (j == 0) {
          chessboard[i][j] = RANK_NUMBERS[rank_index++];
        } else {
          chessboard[i][j] = RANK_LINE[j - 1];
        }
        break;
      case 3:
        chessboard[i][j] = MIDDLE_LINE[j];
        break;
      }
    }
  }
}

void print_chessboard(char chessboard[NUM_OF_ROWS][NUM_OF_COLUMNS]) {
  for (int i = 0; i < NUM_OF_ROWS; i++) {
    for (int j = 0; j < NUM_OF_COLUMNS; j++) {
      printf("%c", chessboard[i][j]);
    }
  }
}
