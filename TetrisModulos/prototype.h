#ifndef PROTOTYPE_H_INCLUDED
#define PROTOTYPE_H_INCLUDED

#include <intelfpgaup/video.h>
#include <intelfpgaup/accel.h>
#include <intelfpgaup/KEY.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "constants.h"
#include "structs.h"

void phrase           (int coordX, int coordY, char *list, int lenList, short cor);
void write_score      (int coordX, int coordY, int score);
void screen_defeat    (int score);
void create_menu      ();
void game_field       (Block blocksList[], int score, int state_game);
void title            (int coordX, int coordY);
void alphanumeric     (int coordX, int coordY, char caracter, short cor);
void change_state     (int *pointer_state, int *pointer_buttons);
void inicializarBoard(Board* board);
int verificarColisao(Board* board, Tetromino* tetromino, int x, int y);
void fixarTetrominoNoTabuleiro(Board* board, Tetromino* tetromino);
void removerLinhasCompletas(Board* board);
void desenharTabuleiro(Tetris* tetris);
void desenharTetromino(Tetris* tetris);
void iniciarTetris(Tetris* tetris);
void atualizarTetris(Tetris* tetris);
void moverTetromino(Tetris* tetris, int dx, int dy);
void aplicarGravidade(Tetris* tetris);
void gerarQ(Tetromino* tetromino);
void gerarL(Tetromino* tetromino);
void gerarI(Tetromino* tetromino);
void gerarIRotacionado(Tetromino* tetromino);

void gerarNovoTetromino(Tetromino* tetromino);






#endif // PROTOTYPE_H_INCLUDED
