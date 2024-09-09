#include <stdlib.h>   // Para rand() e srand()
#include <string.h>   // Para memcpy()
#include <time.h>     // Para srand(time(NULL)) se for necessário gerar números aleatórios com semente
#include "tetris.h"   // Para Tetromino, constantes de cores, dimensões e macros do jogo

void gerarQ(Tetromino* tetromino) {
    int q[4][4] = {
        {1, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    tetromino->cor = COLOR_YELLOW; // Define a cor do quadrado
    memcpy(tetromino->matriz, q, sizeof(q)); // Copia a matriz do quadrado para o Tetromino
}

void gerarL(Tetromino* tetromino) {
    int l[4][4] = {
        {1, 0, 0, 0},
        {1, 1, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    tetromino->cor = COLOR_ORANGE; // Define a cor do L
    memcpy(tetromino->matriz, l, sizeof(l)); // Copia a matriz do L para o Tetromino
}

void gerarI(Tetromino* tetromino) {
    int i[4][4] = {
        {1, 1, 1, 1},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    tetromino->cor = COLOR_CYAN; // Define a cor do I em pé
    memcpy(tetromino->matriz, i, sizeof(i)); // Copia a matriz do I em pé para o Tetromino
}

void gerarIRotacionado(Tetromino* tetromino) {
    int i_rotacionado[4][4] = {
        {1, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 0, 0, 0}
    };
    tetromino->cor = COLOR_CYAN; // Define a cor do I rotacionado
    memcpy(tetromino->matriz, i_rotacionado, sizeof(i_rotacionado)); // Copia a matriz do I rotacionado para o Tetromino
}

void gerarNovoTetromino(Tetromino* tetromino) {
    int tipo = rand() % 4; // Gera um número aleatório entre 0 e 3 para escolher um Tetromino

    // Define a função de geração com base no tipo
    switch (tipo) {
        case TETROMINO_Q:
            tetromino->gerar = gerarQ;
            break;
        case TETROMINO_L:
            tetromino->gerar = gerarL;
            break;
        case TETROMINO_I:
            tetromino->gerar = gerarI;
            break;
        case TETROMINO_I_ROTACIONADO:
            tetromino->gerar = gerarIRotacionado;
            break;
    }

    // Gera o Tetromino específico
    tetromino->gerar(tetromino);

    // Configura a posição inicial
    tetromino->x = 0;
    tetromino->y = SCREEN_X / 2; // Ajustado para usar SCREEN_X em vez de COLUNAS
}
