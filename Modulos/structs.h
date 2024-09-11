#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

#include "prototype.h"


typedef struct {

    int pattern[4][4];
    unsigned int color;
    void (*generate)(struct Tetromino*);

} Tetromino;

typedef struct {

    int grid[LINES][COLUMNS];

} Board;

typedef struct {

    Board board;
    Tetromino currentTetromino;
    int x, y;

} Tetris;


#endif
