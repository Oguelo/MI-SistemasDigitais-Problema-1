#include "renderer.h"

// Função para desenhar o tabuleiro
void desenharTabuleiro(Tetris* tetris) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (tetris->board.matriz[i][j] != 0) {
                // Calcula a posição na tela
                int x = j * BLOCK_SIZE;
                int y = i * BLOCK_SIZE;
                
                // Desenha o bloco
                video_box(x, y, x + BLOCK_SIZE, y + BLOCK_SIZE, tetris->board.matriz[i][j]);
            }
        }
    }
}

// Função para desenhar o tetromino
void desenharTetromino(Tetris* tetris) {
    for (int i = 0; i < 4; i++) { // Supondo que o tetromino é uma matriz 4x4
        for (int j = 0; j < 4; j++) {
            if (tetris->tetrominoAtual.matriz[i][j] != 0) {
                // Calcula a posição na tela
                int x = (tetris->tetrominoAtual.x + j) * BLOCK_SIZE;
                int y = (tetris->tetrominoAtual.y + i) * BLOCK_SIZE;
                
                // Desenha o bloco
                video_box(x, y, x + BLOCK_SIZE, y + BLOCK_SIZE, tetris->tetrominoAtual.cor);
            }
        }
    }
}

// // Função para atualizar a tela
// void atualizarTela(Tetris* tetris) {
//     desenharTabuleiro(tetris);
//     desenharTetromino(tetris);
// }
