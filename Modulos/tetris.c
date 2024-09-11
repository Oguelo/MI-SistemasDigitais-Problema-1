#include "prototype.h"


void initTetris(Tetris* tetris) {

    initBoard(&tetris->board);
    generateTetromino(&tetris->currentTetromino);
    tetris->x = 0;
    tetris->y = COLUNAS / 2;

}

void updateTetris(Tetris* tetris) {
    
    desenharBloco(tetris->x * BLOCK_SIZE, tetris->y * BLOCK_SIZE, pixel_buffer, 0x0000); // Limpa a área ocupada

    if (!verifyCollision(&tetris->board, &tetris->tetrominoAtual, tetris->x + 1, tetris->y)) {

        tetris->x++;

    } else {

        fixTetromino(&tetris->board, &tetris->currentTetromino, &tetris->x, &tetris->y);
        removeFullLines(&tetris->board);
        generateTetromino(&tetris->currentTetromino);

    }
    
    desenharTetromino(tetris->x, tetris->y, &tetris->tetrominoAtual, pixel_buffer);

}

void moveTetromino(Tetris* tetris, int dx, int dy) {

    if (!verificarColisao(&tetris->board, &tetris->tetrominoAtual, tetris->x + dx, tetris->y + dy)) {

        tetris->x += dx;
        tetris->y += dy;

    }
}


void applyGravity(Tetris* tetris) {

    if (!verifyCollision(&tetris->board, &tetris->tetrominoAtual, tetris->x, tetris->y+1)) {

        tetris->y++;

    } else {

        fixTetromino(&tetris->board, &tetris->tetrominoAtual);
        removeFullLines(&tetris->board);
        gerarNovoTetromino(&tetris->currentTetromnino);

    }
}
