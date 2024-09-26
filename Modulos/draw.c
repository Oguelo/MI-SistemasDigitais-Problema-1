#include "interfaces.h"

void drawBoard(PartTetromino boardMatrix[LINES][COLUMNS])
{

    for (int i = 0; i < LINES; i++)
    {

        for (int j = 0; j < COLUMNS; j++)
        {

            if (boardMatrix[i][j].isNotEmpty)
            {

                int initialX1 = INITIAL_LIMIT_X + j * (BLOCK_SIZE + SPACING);
                int initialY1 = INITIAL_LIMIT_Y + i * (BLOCK_SIZE + SPACING);
                int finalX2 = initialX1 + BLOCK_SIZE;
                int finalY2 = initialY1 + BLOCK_SIZE;
                video_box(initialX1, initialY1, finalX2, finalY2, boardMatrix[i][j].color);
            }
        }
    }
}

void drawBoardTerminal(PartTetromino boardMatrix[LINES][COLUMNS])
{
    for (int i = 0; i < LINES; i++)
    {
        printf("%.2d", i + 1);
        for (int j = 0; j < COLUMNS; j++)
        {
            if (boardMatrix[i][j].isNotEmpty != 0)
            {

                printf("# ");
            }
            else
            {

                printf(". ");
            }
        }
        printf("\n");
    }
}

void drawTetrominoTerminal(Tetromino tetromino)
{

    printf("Padrao:\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (tetromino.pattern[tetromino.currentRotation][i][j] != 0)
            {
                printf("# ");
            }
            else
            {
                printf(". ");
            }
        }
        printf("\n");
    }
}
