#ifndef TETRIS_H
#define TETRIS_H

#include "prototype.h"

#define LINHAS 20
#define COLUNAS 10
#define BLOCK_SIZE 16
#define LIMITE_ESQUERDA -10
#define LIMITE_DIREITA 10

typedef struct {
    int board[LINHAS][COLUNAS];  // Representa o tabuleiro do jogo
    Peca tetrominoAtual;  // O tetromino que está caindo
    int x, y;  // Coordenadas da peça atual
} Tetris;

/**
 * Inicializa o jogo Tetris.
 * @param tetris Estrutura do jogo
 */
void iniciarTetris(Tetris* tetris);

/**
 * Atualiza o estado do jogo Tetris.
 * @param tetris Estrutura do jogo
 */
void atualizarTetris(Tetris* tetris);

/**
 * Move o tetromino para a esquerda ou direita.
 * @param tetris Estrutura do jogo
 * @param dx Movimento no eixo X
 * @param dy Movimento no eixo Y
 */
void moverTetromino(Tetris* tetris, int dx, int dy);

/**
 * Aplica a gravidade ao tetromino.
 * @param tetris Estrutura do jogo
 */
void aplicarGravidade(Tetris* tetris);

#endif // TETRIS_H
