/**
 * @file collisions.c
 * @date 2024-09-07
 * @brief Arquivo que contém as funções para movimentar, verificar colisões e exibir a bola
*/

#include "prototype.h"

void atualizarJogo() {
    // Limpar a tela onde a peça estava
    limparTela(x * BLOCK_SIZE, y * BLOCK_SIZE, 4 * BLOCK_SIZE, 4 * BLOCK_SIZE, pixel_buffer);
    
    // Mover a peça para baixo
    if (!verificarColisao(tabuleiro, peca, x + 1, y)) {
        x++;
    } else {
        fixarPecaNoTabuleiro(tabuleiro, peca, x, y, pixel_buffer);
        removerLinhasCompletas(tabuleiro, pixel_buffer);
        gerarNovaPeca();
    }

bool verificarColisao(int tabuleiro[LINHAS][COLUNAS], int peca[4][4], int x, int y) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (peca[i][j] == 1) {
                int posX = x + i;
                int posY = y + j;

                if (posX < 0 || posX >= LINHAS || posY < 0 || posY >= COLUNAS) {
                    return true; // Colisão detectada
                }

                if (tabuleiro[posX][posY] == 1) {
                    return true; // Colisão detectada
                }
            }
        }
    }

    if (y >= LINHAS - 4) {
        return true; // Colisão com o fundo detectada
    }

    return false;
}
void fixarPecaNoTabuleiro(int tabuleiro[LINHAS][COLUNAS], int peca[4][4], int x, int y, alt_up_pixel_buffer_dma_dev* pixel_buffer) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (peca[i][j] == 1) {
                int posX = x + i;
                int posY = y + j;
                tabuleiro[posX][posY] = 1; // Marca como ocupado

                // Atualizar a tela
                desenharBloco(posY * BLOCK_SIZE, posX * BLOCK_SIZE, pixel_buffer, 0xFFFF); // Desenha a peça
            }
        }
    }
}
void removerLinhasCompletas(int tabuleiro[LINHAS][COLUNAS], alt_up_pixel_buffer_dma_dev* pixel_buffer) {
    for (int i = 0; i < LINHAS; i++) {
        bool linhaCompleta = true;
        for (int j = 0; j < COLUNAS; j++) {
            if (tabuleiro[i][j] == 0) {
                linhaCompleta = false;
                break;
            }
        }

        if (linhaCompleta) {
            // Move todas as linhas acima da linha completa uma linha para baixo
            for (int k = i; k > 0; k--) {
                for (int l = 0; l < COLUNAS; l++) {
                    tabuleiro[k][l] = tabuleiro[k - 1][l];
                    // Atualizar a tela
                    desenharBloco(l * BLOCK_SIZE, k * BLOCK_SIZE, pixel_buffer, (tabuleiro[k][l] == 1 ? 0xFFFF : 0x0000));
                }
            }
            // Limpa a primeira linha
            for (int l = 0; l < COLUNAS; l++) {
                tabuleiro[0][l] = 0;
                // Atualizar a tela
                desenharBloco(l * BLOCK_SIZE, 0, pixel_buffer, 0x0000);
            }
        }
    }
}
