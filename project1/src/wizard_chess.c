/**
 * @file wizard_chess.c
 *
 * @brief This file contains the main function of the project.
 */

#include "chessboard.h" /* create_chessboard, print_chessboard */
#include "piece.h" /* create_user_pieces, create_computer_pieces, struct piece */
#include "movements.h" /* thread move */
#include "pipe.h" /* init_pipe*/
#include "signalP.h" /*elimnate_piece_enemy, eliminate_piece_player, win*/
  
#include <stdio.h>  /* printf */
#include <stdlib.h> /* EXIT_SUCCESS */

#include <sys/wait.h> /* Wait*/
#include <unistd.h>   /* Comand UNIX*/
#include <pthread.h>  /* pthread.create, pthread.join */
#include <signal.h> /* signal */

int main(int argc, char const *argv[]) {
  struct piece *user_pieces = create_user_pieces(); // Create user pieces
  struct piece *computer_pieces = create_computer_pieces(); // Create enemy piece
  char **chessboard = create_chessboard(user_pieces, computer_pieces); // Create chessboard
  struct routine_Piece *hilos_Jugador;
  struct routine_Piece *hilos_Enemy;
  int cota = 0; 

  signal(SIGUSR1,eliminate_piece_enemy);
  signal(SIGUSR2,eliminate_piece_player);
  signal(SIGTERM, win);
  
  while(cota < 100) {
    cota++; // number of plays
    hilos_Jugador = create_routine_pieces(user_pieces, chessboard); // Create the threads of the player pieces
    printf("//////////////////////////////////////////////////////////////////\n");
    printf("PLAYER TURN INIT\n");
    // Start the pipes 
    init_pipe(hilos_Jugador);

    // Create a first process for the player pieces
    pid_t chessPlayer = fork();

    if (chessPlayer != 0) {
      // Father

      // Wait for the child process to finish
      waitpid(chessPlayer, NULL, 0);

      //Check the pipe player
      read_pipe(hilos_Jugador, user_pieces);

      // Create the new keyboard with the changed parts
      chessboard = rewrite_chessboard(chessboard,user_pieces, computer_pieces);
      print_chessboard(chessboard);
      printf("PLAYER TURN END\n");
      printf("//////////////////////////////////////////////////////////////////\n");
      sleep(2);

      printf("//////////////////////////////////////////////////////////////////\n");
      printf("ENEMY TURN INIT\n");

      hilos_Enemy = create_routine_pieces(computer_pieces, chessboard);
      init_pipe(hilos_Enemy);
      pid_t chessEnemy = fork();
      
      if (chessEnemy != 0) {
        // Father
        waitpid(chessEnemy, NULL, 0);

        // Check the pipe enemy
        read_pipe(hilos_Enemy, computer_pieces);
        chessboard = rewrite_chessboard(chessboard,user_pieces, computer_pieces);
        print_chessboard(chessboard);

        printf("ENEMY TURN END\n");
        printf("//////////////////////////////////////////////////////////////////\n");
      } else {
        // Child 2
        move_piece(hilos_Enemy);
        exit(EXIT_SUCCESS);
      }
    } else {
      // Child
      move_piece(hilos_Jugador);
      exit(EXIT_SUCCESS);
    }
    
  }
  printf("GAME OVER, TO MUCH MOVEMENTS\n");
  return EXIT_SUCCESS;
}
