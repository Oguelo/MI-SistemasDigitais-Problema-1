#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

#include "prototype.h"

typedef struct
{

    int x, y, currentRotation, prevRotation;
    int pattern[MAX_ROTATIONS][4][4];
    unsigned int color;
    unsigned int colorShadow;
    void (*generate)(struct Tetromino *);

} Tetromino;

typedef struct
{

    int isNotEmpty;
    unsigned int color;
    unsigned int colorShadow;

} PartTetromino;

#endif
