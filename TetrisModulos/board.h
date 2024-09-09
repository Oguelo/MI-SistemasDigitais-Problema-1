#ifndef BOARD_H
#define BOARD_H

#define LINHAS 20
#define COLUNAS 10

#include "tetromino.h"

// Estrutura para o tabuleiro
typedef struct {
    int tabuleiro[LINHAS][COLUNAS];
} Board;

// Funções relacionadas ao tabuleiro
void inicializarBoard(Board* board);
int verificarColisao(Board* board, Tetromino* tetromino, int x, int y);
void fixarTetrominoNoTabuleiro(Board* board, Tetromino* tetromino);
void removerLinhasCompletas(Board* board);

#endif // BOARD_H

