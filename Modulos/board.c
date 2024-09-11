#include "prototype.h"


void initBoard(Board* board) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            board->grid[i][j] = 0;
        }
    }
}


int verifyCollision(Board* board, Tetromino* tetromino, int x, int y) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (tetromino->pattern[i][j] == 1) {
                int posX = x + i;
                int posY = y + j;

                if (posX < 0 || posX >= LINHAS || posY < 0 || posY >= COLUNAS) {
                    return 1; 
                }

                if (board->grid[posX][posY] == 1) {
                    return 1; 
                }
            }
        }
    }

    return 0; 
}

void fixTetromino(Board* board, Tetromino* tetromino, int x, int y) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (tetromino->pattern[i][j] == 1) {
                int posX = x + i;
                int posY = y + j;
                board->grid[posX][posY] = 1;
            }
        }
    }
}

void removeFullLines(Board* board) {
    for (int i = 0; i < LINHAS; i++) {
        int fullLine = 1;
        for (int j = 0; j < COLUNAS; j++) {
            if (board->grid[i][j] == 0) {
                fullLine = 0;
                break;
            }
        }

        if (fullLine) {
            for (int k = i; k > 0; k--) {
                for (int l = 0; l < COLUNAS; l++) {
                    board->grid[k][l] = board->grid[k - 1][l];
                }
            }
            for (int l = 0; l < COLUNAS; l++) {
                board->grid[0][l] = 0;
            }
        }
    }
}
