#include "prototype.h"

void generateQPattern(Tetromino *tetromino)
{

    int q[4][4] = {
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}};

    for (int i = 0; i < MAX_ROTATIONS; i++)
    {
        memcpy(tetromino->pattern[i], q, sizeof(q));
    }

    tetromino->color = COLOR_YELLOW;
    tetromino->colorShadow = COLOR_YELLOW_DARK;
    tetromino->currentRotation = 0; 
}
void generateTPattern(Tetromino *tetromino)
{

    int t0[4][4] = {
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 0, 0}};

    int t90[4][4] = {
        {0, 0, 1, 0},
        {1, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0}};

    int t180[4][4] = {
        {0, 1, 0, 0},
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 0, 0, 0}};

    int t270[4][4] = {
        {1, 0, 0, 0},
        {1, 1, 1, 0},
        {1, 0, 0, 0},
        {0, 0, 0, 0}};

    memcpy(tetromino->pattern[0], t0, sizeof(t0));
    memcpy(tetromino->pattern[1], t90, sizeof(t90));
    memcpy(tetromino->pattern[2], t180, sizeof(t180));
    memcpy(tetromino->pattern[3], t270, sizeof(t270));

    tetromino->color = COLOR_PINK;
    tetromino->colorShadow = COLOR_PINK_DARK;
    tetromino->currentRotation = 0;
}

void generateLPattern(Tetromino *tetromino)
{

    int l0[4][4] = {
        {1, 0, 0, 0},
        {1, 1, 1, 1},
        {0, 0, 0, 0},
        {0, 0, 0, 0}};

    int l90[4][4] = {
        {0, 1, 1, 0},
        {0, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 0, 0}};

    int l180[4][4] = {
        {1, 1, 1, 1},
        {0, 0, 0, 1},
        {0, 0, 0, 0},
        {0, 0, 0, 0}};

    int l270[4][4] = {
        {0, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0}};

    memcpy(tetromino->pattern[0], l0, sizeof(l0));
    memcpy(tetromino->pattern[1], l90, sizeof(l90));
    memcpy(tetromino->pattern[2], l180, sizeof(l180));
    memcpy(tetromino->pattern[3], l270, sizeof(l270));

    tetromino->color = COLOR_ORANGE;
    tetromino->colorShadow = COLOR_ORANGE_DARK;
    tetromino->currentRotation = 0;
}

void generateIPattern(Tetromino *tetromino)
{

    int i0[4][4] = {
        {1, 1, 1, 1},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}};

    int i90[4][4] = {
        {1, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 0, 0, 0}};

    memcpy(tetromino->pattern[0], i0, sizeof(i0));
    memcpy(tetromino->pattern[1], i90, sizeof(i90));
    memcpy(tetromino->pattern[2], i0, sizeof(i0));
    memcpy(tetromino->pattern[3], i90, sizeof(i90));

    tetromino->color = COLOR_CYAN;
    tetromino->colorShadow = COLOR_CYAN_DARK;
    tetromino->currentRotation = 0;
}

void generateTetromino(Tetromino *tetromino)
{

    srand(time(NULL));
    int tipo = rand() % 4;

    switch (tipo)
    {
    case TETROMINO_Q:
        tetromino->generate = generateQPattern;
        break;
    case TETROMINO_L:
        tetromino->generate = generateLPattern;
        break;
    case TETROMINO_I:
        tetromino->generate = generateIPattern;
        break;
    case TETROMINO_T:
        tetromino->generate = generateIPattern;
        break;
    }
    
    
    

    tetromino->generate(tetromino);
}

void initTetromino(Tetromino *tetromino)
{

    generateTetromino(tetromino);
    tetromino->x = (COLUMNS / 2) - 2;
    tetromino->y = 0;
    tetromino->currentRotation = 1;
}

void moveTetromino(PartTetromino boardMatrix[LINES][COLUMNS], Tetromino *tetromino, int dx, int dy, int *moved)
{

    int movedX = 1;
    int movedY = 1;

    clearTetromino(boardMatrix, tetromino);

    tetromino->x += dx;

    if (verifyCollision(boardMatrix, tetromino))
    {

        tetromino->x -= dx;
        movedX = 0;
    }

    tetromino->y += dy;

    if (verifyCollision(boardMatrix, tetromino))
    {

        tetromino->y -= dy;
        movedY = 0;
        if(dx == 0){

            movedX = 0;

        }
    }

    fixTetromino(boardMatrix, tetromino, tetromino->x, tetromino->y);

    *moved = movedX || movedY;
    
}
