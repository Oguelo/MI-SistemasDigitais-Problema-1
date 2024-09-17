#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

#include "prototype.h"

typedef struct
{

    int x, y, currentRotation;
    int pattern[MAX_ROTATIONS][4][4];
    unsigned int color;
    void (*generate)(struct Tetromino *);

} Tetromino;

typedef struct
{

    int isNotEmpty;
    unsigned int color;

} PartTetromino;

#endif
