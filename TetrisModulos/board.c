#include "board.h"
#include "tetromino.h"

// Inicializa o tabuleiro
void inicializarBoard(Board* board) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            board->tabuleiro[i][j] = 0;
        }
    }
}

// Verifica se há colisão
int verificarColisao(Board* board, Tetromino* tetromino, int x, int y) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (tetromino->matriz[i][j] == 1) {
                int posX = x + i;
                int posY = y + j;

                if (posX < 0 || posX >= LINHAS || posY < 0 || posY >= COLUNAS) {
                    return 1; // Colisão com bordas
                }

                if (board->tabuleiro[posX][posY] == 1) {
                    return 1; // Colisão com outras peças
                }
            }
        }
    }

    return 0; // Sem colisão
}

// Fixar o tetromino no tabuleiro
void fixarTetrominoNoTabuleiro(Board* board, Tetromino* tetromino) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (tetromino->matriz[i][j] == 1) {
                int posX = tetromino->x + i;
                int posY = tetromino->y + j;
                board->tabuleiro[posX][posY] = 1;
            }
        }
    }
}

// Remove linhas completas
void removerLinhasCompletas(Board* board) {
    for (int i = 0; i < LINHAS; i++) {
        int linhaCompleta = 1;
        for (int j = 0; j < COLUNAS; j++) {
            if (board->tabuleiro[i][j] == 0) {
                linhaCompleta = 0;
                break;
            }
        }

        if (linhaCompleta) {
            for (int k = i; k > 0; k--) {
                for (int l = 0; l < COLUNAS; l++) {
                    board->tabuleiro[k][l] = board->tabuleiro[k - 1][l];
                }
            }
            for (int l = 0; l < COLUNAS; l++) {
                board->tabuleiro[0][l] = 0;
            }
        }
    }
}
