/**
 * @file chessboard.c
 *
 * @brief This file contains the functions to create and print a chessboard.
 */

#include "chessboard.h" /* NUM_OF_ROWS, NUM_OF_COLUMNS, TOP_LINE, MIDDLE_LINE,
                           BOTTOM_LINE, FILE_LETTERS, RANK_NUMBERS */

#include <stdio.h>  /* printf */
#include <stdlib.h> /* malloc */

char **create_chessboard() {
  /* Pointer to the chessboard */
  char **chessboard = (char **)malloc(NUM_OF_ROWS * sizeof(char *));
  for (int i = 0; i < NUM_OF_ROWS; i++) {
    chessboard[i] = (char *)malloc(NUM_OF_COLUMNS * sizeof(char));
  }

  /* Initialize the chessboard */
  init_chessboard(chessboard);
  return chessboard;
}

void init_chessboard(char **chessboard) {
  int rank_index = 0;
  for (int i = 0; i < NUM_OF_ROWS; i++) {
    for (int j = 0; j < NUM_OF_COLUMNS; j++) {
      switch (i % 4) {
      case 0:
        if (i == 0) {
          /* Add the top line of the chessboard */
          chessboard[i][j] = TOP_LINE[j];
        } else {
          /* Add the bottom line of a square in the chessboard */
          chessboard[i][j] = BOTTOM_LINE[j];
        }
        break;
      case 2:
        if (j == 0) {
          /* Add the rank number at the left of the chessboard */
          chessboard[i][j] = RANK_NUMBERS[rank_index++];
          break;
        }
        /* Once the rank number is added, add a middle line by falling through*/
      case 3: /* Fall through to print the middle line */
      case 1:
        if (i < NUM_OF_ROWS - 1) {
          /* Add the middle line of a square in the chessboard */
          chessboard[i][j] = MIDDLE_LINE[j];
        } else {
          /* Add the file letters at the bottom of the chessboard */
          chessboard[i][j] = FILE_LETTERS[j];
        }
        break;
      }
    }
  }
}

void print_chessboard(char **chessboard) {
  for (int i = 0; i < NUM_OF_ROWS; i++) {
    for (int j = 0; j < NUM_OF_COLUMNS; j++) {
      printf("%c", chessboard[i][j]);
    }
  }
}
