#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

#include "prototype.h"


typedef struct {
    int matriz[4][4];
    int x, y;
    unsigned int cor;
    void (*gerar)(struct Tetromino*); // Ponteiro para a função de geração específica
} Tetromino;

typedef struct {
    int tabuleiro[LINHAS][COLUNAS];
} Board;

typedef struct {
    int board[LINHAS][COLUNAS];  // Representa o tabuleiro do jogo
   // Peca tetrominoAtual;  // O tetromino que está caindo
    int x, y;  // Coordenadas da peça atual
} Tetris;


#endif // STRUCTS_H_INCLUDED
