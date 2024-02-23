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
  int cota = 0; 
  int fd_1[2]; // Descriptores de archivo para la tubería
  int fd_2[2]; // Descriptores de archivo para la tubería
  int fd_3[2]; // Descriptores de archivo para la tubería
  int fd_4[2]; // Descriptores de archivo para la tubería

  signal(SIGUSR1, eliminandoPiezaEnemiga);
  signal(SIGUSR2, eliminandoPiezaJugadora);
  signal(SIGTERM, ganaron);
  
  struct routine_Piece *hilos_Jugador;
  struct routine_Piece *hilos_Enemy;
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


  while(cota < 100) {
    cota++;
    hilos_Jugador = create_routine_pieces(user_pieces, chessboard);
    for (int i = 0; i < 8; ++i) {
      pipe(hilos_Jugador[i].pipe_1);
    }
    for (int i = 0; i < 8; ++i) {
      pipe(hilos_Jugador[i].pipe_2);
    }
    pid_t chessPlayer = fork();

    if (chessPlayer != 0) {
      // Father
      waitpid(chessPlayer, NULL, 0);

      for (int i = 0; i < 8; i++) {
        close(hilos_Jugador[i].pipe_1[1]);
        read(hilos_Jugador[i].pipe_1[0], &user_pieces[i].x, sizeof(user_pieces[i].x));
        read(hilos_Jugador[i].pipe_1[0], &user_pieces[i].y, sizeof(user_pieces[i].y));
        close(hilos_Jugador[i].pipe_1[0]);
      }

      for (int i = 0; i < 8; i++) {
        close(hilos_Jugador[i].pipe_2[1]);
        read(hilos_Jugador[i].pipe_2[0], &user_pieces[i].casillaX, sizeof(user_pieces[i].casillaX));
        read(hilos_Jugador[i].pipe_2[0], &user_pieces[i].casillaY, sizeof(user_pieces[i].casillaY));
        close(hilos_Jugador[i].pipe_2[0]);
      }
      chessboard = rewrite_chessboard(chessboard,user_pieces, computer_pieces);
      print_chessboard(chessboard);
      printf("Player turn is end\n");

      hilos_Enemy = create_routine_pieces(computer_pieces, chessboard);
      for (int i = 0; i < 8; ++i) {
        pipe(hilos_Enemy[i].pipe_1);
      }
      for (int i = 0; i < 8; ++i) {
        pipe(hilos_Enemy[i].pipe_2);
      } 
      pid_t chessEnemy = fork();
      
      if (chessEnemy != 0) {
        // Father
        waitpid(chessEnemy, NULL, 0);
        
        printf("INICIO SEGUNDO PROCESO\n");
        for (int i = 0; i < 8; i++) {
          close(hilos_Enemy[i].pipe_1[1]);
          read(hilos_Enemy[i].pipe_1[0], &computer_pieces[i].x, sizeof(computer_pieces[i].x));
          read(hilos_Enemy[i].pipe_1[0], &computer_pieces[i].y, sizeof(computer_pieces[i].y));
          close(hilos_Enemy[i].pipe_1[0]);
        }

        for (int i = 0; i < 8; i++) {
          close(hilos_Enemy[i].pipe_2[1]);
          read(hilos_Enemy[i].pipe_2[0], &computer_pieces[i].casillaX, sizeof(computer_pieces[i].x));
          read(hilos_Enemy[i].pipe_2[0], &computer_pieces[i].casillaY, sizeof(computer_pieces[i].y));
          close(hilos_Enemy[i].pipe_2[0]);
        } 
        chessboard = rewrite_chessboard(chessboard,user_pieces, computer_pieces);
        print_chessboard(chessboard);
        printf("Enemy turn is end\n");
      } else {
        // Child 2
        int i = generar_numero_0_o_7();
        
        if (i == 4) {
          pthread_create(&hilos_Enemy[i].hilo, NULL, &king_move, &hilos_Enemy[i]);
          sleep(1);
        } else {
          pthread_create(&hilos_Enemy[i].hilo, NULL, &horse_move, &hilos_Enemy[i]);
          sleep(1);
        }

        pthread_join(hilos_Enemy[i].hilo, NULL);

        pthread_create(&hilos_Enemy[i].hilo, NULL, &casilla_actual, &hilos_Enemy[i]);
        sleep(1);
  
        pthread_join(hilos_Enemy[i].hilo, NULL);

        printf("TERMINE PROCESO HIJO2\n");
        exit(EXIT_SUCCESS);
      }
    } else {
      // Child
      int i = generar_numero_0_o_7();
      if (i == 4) {
        pthread_create(&hilos_Jugador[i].hilo, NULL, &king_move, &hilos_Jugador[i]);
        sleep(1);
      } else {
        pthread_create(&hilos_Jugador[i].hilo, NULL, &horse_move, &hilos_Jugador[i]);
        sleep(1);
      }

      pthread_join(hilos_Jugador[i].hilo, NULL);

      pthread_create(&hilos_Jugador[i].hilo, NULL, &casilla_actual, &hilos_Jugador[i]);
      sleep(1);

      pthread_join(hilos_Jugador[i].hilo, NULL);

      printf("TERMINE PROCESO HIJO\n");
      exit(EXIT_SUCCESS);
    }
    
  }
  printf("GAME OVER, TO MUCH MOVEMENTS\n");
  return EXIT_SUCCESS;
}
