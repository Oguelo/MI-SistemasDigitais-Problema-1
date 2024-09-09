#ifndef TETROMINO_H
#define TETROMINO_H

#include "constants.h" // Incluir o arquivo de constantes

typedef enum {
    TETROMINO_Q,         // Quadrado
    TETROMINO_L,         // L
    TETROMINO_I,         // I em pé
    TETROMINO_I_ROTACIONADO // I rotacionado
} TetrominoTipo;

typedef struct {
    int matriz[4][4];
    int x, y;
    unsigned int cor;
    void (*gerar)(struct Tetromino*); // Ponteiro para a função de geração específica
} Tetromino;

void gerarQ(Tetromino* tetromino);
void gerarL(Tetromino* tetromino);
void gerarI(Tetromino* tetromino);
void gerarIRotacionado(Tetromino* tetromino);

void gerarNovoTetromino(Tetromino* tetromino);

#endif // TETROMINO_H
