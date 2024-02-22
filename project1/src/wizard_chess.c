/**
 * @file wizard_chess.c
 *
 * @brief This file contains the main function of the project.
 */

#include "chessboard.h" /* create_chessboard, print_chessboard */
#include "piece.h" /* create_user_pieces, create_computer_pieces, struct piece */
#include "movements.h" /**/

#include <stdio.h>  /* printf */
#include <stdlib.h> /* EXIT_SUCCESS */

#include <sys/types.h>  /* Comandos para Hilos*/
#include <sys/wait.h> /* Wait*/
#include <unistd.h>   /* Comandos de UNIX*/
#include <pthread.h>
#include <signal.h>
// primero de leer segundo de escribir
int main(int argc, char const *argv[]) {
  struct piece *user_pieces = create_user_pieces();
  struct piece *computer_pieces = create_computer_pieces(); 
  char **chessboard = create_chessboard(user_pieces, computer_pieces);
  
  int fd_1[2]; // Descriptores de archivo para la tubería
  int fd_2[2]; // Descriptores de archivo para la tubería
  int fd_3[2]; // Descriptores de archivo para la tubería
  int fd_4[2]; // Descriptores de archivo para la tubería

  struct routine_Piece *hilos_Jugador = create_routine_pieces(user_pieces, chessboard/*fd_1, fd_2*/);
  //struct routine_Piece *hilos_Enemy = create_routine_pieces(computer_pieces, chessboard, fd_3, fd_4);
  // Crear el pipe
  if (pipe(fd_1) == -1) {
    perror("Error al crear el pipe");
    exit(EXIT_FAILURE);
  }
  if (pipe(fd_2) == -1) {
    perror("Error al crear el pipe");
    exit(EXIT_FAILURE);
  }
  if (pipe(fd_3) == -1) {
    perror("Error al crear el pipe");
    exit(EXIT_FAILURE);
  }
  if (pipe(fd_4) == -1) {
    perror("Error al crear el pipe");
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < 8; ++i) {
    pipe(hilos_Jugador[i].pipe_1);
  }
  pid_t chessPlayer = fork();

  if (chessPlayer != 0) {
    // Father
  
    waitpid(chessPlayer, NULL, 0);
    close(fd_1[1]);

    for (int i = 0; i < 8; i++) {
      close(hilos_Jugador[i].pipe_1[1]);
      read(hilos_Jugador[i].pipe_1[0], &user_pieces[i].x, sizeof(user_pieces[i].x));
      read(hilos_Jugador[i].pipe_1[0], &user_pieces[i].y, sizeof(user_pieces[i].y));
      close(hilos_Jugador[i].pipe_1[0]);
    }

    // Cerrar extremos de escritura de las tuberías en el proceso padre
  
    /*for (int i = 0; i < NUM_HILOS; i++) {
      printf("Posicion x: %d y posicion y: %d\n", user_pieces[i].x, user_pieces[i].y);
    }*/
    for (int i = 0; i < 8; ++i) {
    printf("Este es mi valor de hilos jugador %d\n", hilos_Jugador[i].id);
    printf("Posicion x:%d\n", hilos_Jugador[i].pieces[i].x);
    }

    
    // Cerrar el extremo de escritura del pipe en el proceso padre
    for (int i = 0; i < NUM_OF_ROWS; i++) {
      read(fd_1[0], chessboard[i], NUM_OF_COLUMNS * sizeof(char));
    }
    close(fd_1[0]); 
    print_chessboard(chessboard);
  

  } else {
    // Child
     // Cerrar extremos de escritura de las tuberías en el proceso hijo
    close(fd_1[0]);
    for (int i = 0; i < 8; ++i) {
      //close(hilos_Jugador[i].pipe_1[1]);
      if (i == 4) {
        continue;
      }
      pthread_create(&hilos_Jugador[i].hilo, NULL, &horse_move, &hilos_Jugador[i]);
      sleep(1);
    }

    for (int i = 0; i < 8; ++i) {
      pthread_join(hilos_Jugador[i].hilo, NULL);
    }

    printf("TERMINE PROCESO HIJO\n");

    
    for (int i = 0; i < NUM_OF_ROWS; i++) {
      write(fd_1[1], hilos_Jugador[0].chessboard[i], NUM_OF_COLUMNS * sizeof(char));
    } // Enviar la matriz
    close(fd_1[1]); // Cerrar el extremo de escritura del pipe en el proceso padre
    exit(1);
  }
  
  return EXIT_SUCCESS;
}
