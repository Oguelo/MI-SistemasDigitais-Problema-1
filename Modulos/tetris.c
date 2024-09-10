#include "prototype.h"


void iniciarTetris(Tetris* tetris) {
    inicializarBoard(&tetris->board);
    gerarNovoTetromino(&tetris->tetrominoAtual);
    tetris->x = 0;
    tetris->y = COLUNAS / 2;
}

void atualizarTetris(Tetris* tetris) {
    
    desenharBloco(tetris->x * BLOCK_SIZE, tetris->y * BLOCK_SIZE, pixel_buffer, 0x0000); // Limpa a área ocupada

    if (!verificarColisao(&tetris->board, &tetris->tetrominoAtual, tetris->x + 1, tetris->y)) {
        tetris->x++;
    } else {
        fixarTetrominoNoTabuleiro(&tetris->board, &tetris->tetrominoAtual);
        removerLinhasCompletas(&tetris->board);
        gerarNovoTetromino(&tetris->tetrominoAtual);
    }
    // Desenhar o tetromino atual na tela
    desenharTetromino(tetris->x, tetris->y, &tetris->tetrominoAtual, pixel_buffer);
}

void moverTetromino(Tetris* tetris, int dx, int dy) {
    if (!verificarColisao(&tetris->board, &tetris->tetrominoAtual, tetris->x + dx, tetris->y + dy)) {
        tetris->x += dx;
        tetris->y += dy;
    }
}

void aplicarGravidade(Tetris* tetris) {
    if (!verificarColisao(&tetris->board, &tetris->tetrominoAtual, tetris->x + 1, tetris->y)) {
        tetris->x++;
    } else {
        fixarTetrominoNoTabuleiro(&tetris->board, &tetris->tetrominoAtual);
        removerLinhasCompletas(&tetris->board);
        gerarNovoTetromino(&tetris->tetrominoAtual);
    }
}
