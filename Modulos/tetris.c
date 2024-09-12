#include "prototype.h"


void initTetris(Tetris* tetris) {

    initBoard(&tetris->board);
    generateTetromino(&tetris->currentTetromino);
    tetris->x = SCREEN_X/2;
    tetris->y = COLUMNS / 2;

}

// void updateTetris(Tetris* tetris) {
    
//     desenharBloco(tetris->x * BLOCK_SIZE, tetris->y * BLOCK_SIZE, pixel_buffer, 0x0000); // Limpa a área ocupada

//     if (!verifyCollision(&tetris->board, &tetris->currentTetromino, tetris->x + 1, tetris->y)) {

//         tetris->x++;

//     } else {

//         fixTetromino(&tetris->board, &tetris->currentTetromino, &tetris->x, &tetris->y);
//         removeFullLines(&tetris->board);
//         generateTetromino(&tetris->currentTetromino);

//     }
    
//     desenharTetromino(tetris->x, tetris->y, &tetris->currentTetromino, pixel_buffer);

// }

void moveTetromino(Tetris* tetris, int dx, int dy) {

    if (!verifyCollision(&tetris->board, &tetris->currentTetromino, tetris->x + dx, tetris->y + dy)) {

        tetris->x += dx;
        tetris->y += dy;

    }
}


void applyGravity(Tetris* tetris) {

    if (!verifyCollision(&tetris->board, &tetris->currentTetromino, tetris->x, tetris->y+1)) {

        tetris->y++;

    } else {

        fixTetromino(&tetris->board, &tetris->currentTetromino, &tetris->x, &tetris->y);
        removeFullLines(&tetris->board);
        generateTetromino(&tetris->currentTetromino);

    }
}
