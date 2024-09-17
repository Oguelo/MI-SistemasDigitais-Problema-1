#include "prototype.h"

void resetBoard(PartTetromino boardMatrix[LINES][COLUMNS])
{
    for (int i = 0; i < LINES; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            boardMatrix[i][j].isNotEmpty = 0;
            boardMatrix[i][j].color = COLOR_WHITE;
        }
    }
}

int verifyCollision(PartTetromino boardMatrix[LINES][COLUMNS], Tetromino *tetromino)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (tetromino->pattern[i][j] == 1)
            {
                int posX = tetromino->x + j;
                int posY = tetromino->y + i;

                if (posX < 0 || posX >= COLUMNS || posY < 0 || posY >= LINES || boardMatrix[posY][posX].isNotEmpty)
                {
                    return 1;
                }
            }
        }
    }

    return 0;
}

void fixTetromino(PartTetromino boardMatrix[LINES][COLUMNS], Tetromino *tetromino, int x, int y)
{

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (tetromino->pattern[i][j] == 1)
            {
                int posX = x + j;
                int posY = y + i;


                if (posX >= 0 && posY < LINES && posY >= 0 && posX < COLUMNS)
                {
                    boardMatrix[posY][posX].isNotEmpty = 1;
                    boardMatrix[posY][posX].color = tetromino->color;
                }
            }
        }
    }
}

void clearTetromino(PartTetromino boardMatrix[LINES][COLUMNS], Tetromino *tetromino)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (tetromino->pattern[i][j] == 1)
            {
                int posX = tetromino->x + j;
                int posY = tetromino->y + i;

                if (posX >= 0 && posX < COLUMNS && posY >= 0 && posY < LINES)
                {
                    boardMatrix[posY][posX].isNotEmpty = 0;
                    boardMatrix[posY][posX].color = 0;
                }
            }
        }
    }
}

void removeFullLines(PartTetromino boardMatrix[LINES][COLUMNS])
{
    for (int i = 0; i < LINES; i++)
    {
        int fullLine = 1;
        for (int j = 0; j < COLUMNS; j++)
        {
            if (boardMatrix[i][j].isNotEmpty == 0)
            {
                fullLine = 0;
                break;
            }
        }

        if (fullLine)
        {
            for (int k = i; k > 0; k--)
            {
                for (int l = 0; l < COLUMNS; l++)
                {
                    boardMatrix[k][l] = boardMatrix[k - 1][l];
                }
            }
            for (int l = 0; l < COLUMNS; l++)
            {
                boardMatrix[0][l].isNotEmpty = 0;
                boardMatrix[0][l].color = COLOR_WHITE;
            }
        }
    }
}
