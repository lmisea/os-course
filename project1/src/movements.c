/**
 * @file movements.h
 *
 * @brief Contains the way the pieces move.
 */
#include "piece.h" /* struct piece */
#include "chessboard.h" /* Chess*/

#include <stdio.h>  /* printf */
#include <stdlib.h> /* rand*/

#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>

int generar_numero_0_o_1() {
    return rand() % 2;
}

// PROCESOS

void sendPosition(struct piece *pieces, int i, int *fd) {
    write(fd[0], &pieces[i], sizeof(struct piece));
    //return 0;
}

void receivePosition(struct piece *pieces, int i, int *fd) {
    read(fd[0], &pieces[i], sizeof(struct piece));
}

void sendMatrix(int fd[], char **chessboard) {
    for (int i = 0; i < NUM_OF_ROWS; i++) {
        write(fd[1], chessboard[i], NUM_OF_COLUMNS * sizeof(char));
    }
    //return 0;
}

void receiveMatrix(int fd[],char **chessboard) {
    for (int i = 0; i < NUM_OF_ROWS; i++) {
        read(fd[0], chessboard[i], NUM_OF_COLUMNS * sizeof(char));
    }
    printf("termine en move\n");
}

void *horse_move(void *arg) {
    struct routine_Piece *select = (struct routine_Piece *)arg;
    int move_Y;
    int move_X; 
    int i = select->id;
    if (select->pieces[i].color == 0) {
        // JUGADOR
        move_Y = -8;
        move_Y = select->pieces[i].y + move_Y;
    } else {
        // ENEMIGO
        move_Y = 8;
        move_Y = select->pieces[i].y + move_Y;
    }
    
    srand(time(NULL));
    int num_entre_0_y_1 = generar_numero_0_o_1();
    printf("esto salio %d\n",num_entre_0_y_1);

    if (num_entre_0_y_1 == 0) {
        move_X = -8;
    } else {
        move_X = 8;
    }
    move_X = select->pieces[i].x + move_X;
    printf("Se obtuvo que y:%d y x:%d \n", move_Y, move_X);
    printf("PH Posicion x: %d y posicion y: %d\n", select->pieces[i].x, select->pieces[i].y);
    if (move_Y < 34 && move_Y > 0) {
        if (move_X < 68 && move_X > 2) {
            select->chessboard[select->pieces[i].y][select->pieces[i].x] = ' ';
            select->pieces[i].y = move_Y;
            select->pieces[i].x = move_X;
            select->chessboard[select->pieces[i].y][select->pieces[i].x] = select->pieces[i].symbol;
        }
    }
    printf("HILO %d\n",select->id);
    print_chessboard(select->chessboard);
    printf("PH POST Posicion x: %d y posicion y: %d\n", select->pieces[i].x, select->pieces[i].y);
    close(select->pipe_1[0]);
    write(select->pipe_1[1], &select->pieces[i].x, sizeof(select->pieces[i].x));
    write(select->pipe_1[1], &select->pieces[i].y, sizeof(select->pieces[i].y));
    close(select->pipe_1[1]);
}

// HILOS