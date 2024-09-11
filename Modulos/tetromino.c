#include "prototype.h"


void generateQPattern(Tetromino* tetromino) {
    
    int q[4][4] = {
        {1, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    tetromino->color = COLOR_YELLOW; 
    memcpy(tetromino->pattern, q, sizeof(q));

}

void generateLPattern(Tetromino* tetromino) {
    
    int l[4][4] = {
        {1, 0, 0, 0},
        {1, 1, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    tetromino->color = COLOR_ORANGE; 
    memcpy(tetromino->pattern, l, sizeof(l)); 

}

void generateIPattern(Tetromino* tetromino) {
    
    int i[4][4] = {
        {1, 1, 1, 1},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    tetromino->color = COLOR_CYAN;
    memcpy(tetromino->pattern, i, sizeof(i));

}

void generateIPatternRotate(Tetromino* tetromino) {
    
    int iRotate[4][4] = {
        {1, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 0, 0, 0}
    };
    tetromino->color = COLOR_CYAN; 
    memcpy(tetromino->pattern, iRotate, sizeof(iRotate));

}

void generateTetromino(Tetromino* tetromino) {
    
    int tipo = rand() % 4;

    switch (tipo) {
        case TETROMINO_Q:
            tetromino->generate = generateQPattern;
            break;
        case TETROMINO_L:
            tetromino->generate = generateLPattern;
            break;
        case TETROMINO_I:
            tetromino->generate = generateIPattern;
            break;
        case TETROMINO_I_ROTACIONADO:
            tetromino->generate = generateIPatternRotate;
            break;
    }

    tetromino->generate(tetromino);
}
