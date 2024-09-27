#include "interfaces.h"

void generateChar(int coordX, int coordY, char caracter, short color)
{

    switch (caracter)
    {

    case '^':

        video_box(coordX, coordY, coordX + 1, coordY + 9, color);
        video_box(coordX + 2, coordY + 1, coordX + 3, coordY + 8, color);
        video_box(coordX + 4, coordY + 2, coordX + 5, coordY + 7, color);
        video_box(coordX + 6, coordY + 3, coordX + 7, coordY + 6, color);
        video_box(coordX + 8, coordY + 4, coordX + 9, coordY + 5, color);

        break;

    case '<':

        video_box(coordX + 2, coordY + 4, coordX + 3, coordY + 5, color);
        video_box(coordX + 4, coordY + 2, coordX + 5, coordY + 3, color);
        video_box(coordX + 4, coordY + 6, coordX + 5, coordY + 7, color);
        video_box(coordX + 6, coordY, coordX + 7, coordY + 1, color);
        video_box(coordX + 6, coordY + 8, coordX + 7, coordY + 9, color);

        break;

    case '>':

        video_box(coordX + 2, coordY, coordX + 3, coordY + 1, color);
        video_box(coordX + 2, coordY + 8, coordX + 3, coordY + 9, color);
        video_box(coordX + 4, coordY + 2, coordX + 5, coordY + 3, color);
        video_box(coordX + 4, coordY + 6, coordX + 5, coordY + 7, color);
        video_box(coordX + 6, coordY + 4, coordX + 7, coordY + 5, color);

        break;

    case ':':

        video_box(coordX + 2, coordY + 2, coordX + 3, coordY + 3, color);
        video_box(coordX + 2, coordY + 6, coordX + 3, coordY + 7, color);

        break;

    case ';':

        video_box(coordX + 2, coordY + 2, coordX + 3, coordY + 3, color);
        video_box(coordX + 2, coordY + 6, coordX + 3, coordY + 9, color);

        break;

    case '0':

        video_box(coordX, coordY + 2, coordX + 1, coordY + 7, color);
        video_box(coordX + 2, coordY, coordX + 7, coordY + 1, color);
        video_box(coordX + 4, coordY + 4, coordX + 5, coordY + 5, color);
        video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, color);
        video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 7, color);

        break;

    case '1':

        video_box(coordX + 2, coordY, coordX + 3, coordY + 1, color);
        video_box(coordX + 4, coordY, coordX + 5, coordY + 7, color);
        video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, color);

        break;

    case '2':

        video_box(coordX, coordY + 2, coordX + 1, coordY + 3, color);
        video_box(coordX + 2, coordY, coordX + 7, coordY + 1, color);
        video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 3, color);
        video_box(coordX + 4, coordY + 4, coordX + 7, coordY + 5, color);
        video_box(coordX + 2, coordY + 6, coordX + 3, coordY + 7, color);
        video_box(coordX, coordY + 8, coordX + 9, coordY + 9, color);

        break;

    case '3':

        video_box(coordX, coordY + 2, coordX + 1, coordY + 3, color);
        video_box(coordX + 2, coordY, coordX + 7, coordY + 1, color);
        video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 3, color);
        video_box(coordX + 4, coordY + 4, coordX + 7, coordY + 5, color);
        video_box(coordX, coordY + 6, coordX + 1, coordY + 7, color);
        video_box(coordX + 8, coordY + 6, coordX + 9, coordY + 7, color);
        video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, color);

        break;

    case '4':

        video_box(coordX, coordY, coordX + 1, coordY + 5, color);
        video_box(coordX + 2, coordY + 6, coordX + 7, coordY + 7, color);
        video_box(coordX + 8, coordY, coordX + 9, coordY + 9, color);

        break;

    case '5':

        video_box(coordX, coordY, coordX + 9, coordY + 1, color);
        video_box(coordX, coordY + 2, coordX + 1, coordY + 3, color);
        video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, color);
        video_box(coordX + 8, coordY + 6, coordX + 9, coordY + 7, color);
        video_box(coordX, coordY + 8, coordX + 7, coordY + 9, color);

        break;

    case '6':

        video_box(coordX, coordY + 2, coordX + 1, coordY + 7, color);
        video_box(coordX + 2, coordY, coordX + 9, coordY + 1, color);
        video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, color);
        video_box(coordX + 8, coordY + 6, coordX + 9, coordY + 7, color);
        video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, color);

        break;

    case '7':

        video_box(coordX, coordY, coordX + 9, coordY + 1, color);
        video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 3, color);
        video_box(coordX + 6, coordY + 4, coordX + 7, coordY + 5, color);
        video_box(coordX + 4, coordY + 6, coordX + 5, coordY + 7, color);
        video_box(coordX + 2, coordY + 8, coordX + 3, coordY + 9, color);

        break;

    case '8':

        video_box(coordX + 2, coordY, coordX + 7, coordY + 1, color);
        video_box(coordX, coordY + 2, coordX + 1, coordY + 3, color);
        video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 3, color);
        video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, color);
        video_box(coordX, coordY + 6, coordX + 1, coordY + 7, color);
        video_box(coordX + 8, coordY + 6, coordX + 9, coordY + 7, color);
        video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, color);

        break;

    case '9':

        video_box(coordX + 2, coordY, coordX + 7, coordY + 1, color);
        video_box(coordX, coordY + 2, coordX + 1, coordY + 3, color);
        video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, color);
        video_box(coordX, coordY + 8, coordX + 7, coordY + 9, color);
        video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 7, color);

        break;

    case 'a':

        video_box(coordX, coordY + 2, coordX + 1, coordY + 9, color);
        video_box(coordX + 2, coordY, coordX + 7, coordY + 1, color);
        video_box(coordX + 2, coordY + 6, coordX + 7, coordY + 7, color);
        video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 9, color);

        break;

    case 'b':

        video_box(coordX, coordY, coordX + 1, coordY + 9, color);
        video_box(coordX + 2, coordY, coordX + 7, coordY + 1, color);
        video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, color);
        video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, color);
        video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 3, color);
        video_box(coordX + 8, coordY + 6, coordX + 9, coordY + 7, color);

        break;

    case 'c':

        video_box(coordX, coordY + 2, coordX + 1, coordY + 7, color);
        video_box(coordX + 2, coordY, coordX + 9, coordY + 1, color);
        video_box(coordX + 2, coordY + 8, coordX + 9, coordY + 9, color);

        break;

    case 'd':

        video_box(coordX, coordY, coordX + 1, coordY + 9, color);
        video_box(coordX + 2, coordY, coordX + 7, coordY + 1, color);
        video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, color);
        video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 7, color);

        break;

    case 'e':

        video_box(coordX, coordY, coordX + 1, coordY + 9, color);
        video_box(coordX + 2, coordY, coordX + 9, coordY + 1, color);
        video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, color);
        video_box(coordX + 2, coordY + 8, coordX + 9, coordY + 9, color);

        break;

    case 'f':

        video_box(coordX, coordY, coordX + 1, coordY + 9, color);
        video_box(coordX + 2, coordY, coordX + 9, coordY + 1, color);
        video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, color);

        break;

    case 'g':

        video_box(coordX, coordY + 2, coordX + 1, coordY + 7, color);
        video_box(coordX + 2, coordY, coordX + 9, coordY + 1, color);
        video_box(coordX + 4, coordY + 4, coordX + 9, coordY + 5, color);
        video_box(coordX + 8, coordY + 6, coordX + 9, coordY + 7, color);
        video_box(coordX + 2, coordY + 8, coordX + 9, coordY + 9, color);

        break;

    case 'h':

        video_box(coordX, coordY, coordX + 1, coordY + 9, color);
        video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, color);
        video_box(coordX + 8, coordY, coordX + 9, coordY + 9, color);

        break;

    case 'i':

        video_box(coordX + 2, coordY, coordX + 7, coordY + 1, color);
        video_box(coordX + 4, coordY + 2, coordX + 5, coordY + 7, color);
        video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, color);

        break;

    case 'j':

        video_box(coordX, coordY + 4, coordX + 1, coordY + 7, color);
        video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, color);
        video_box(coordX + 8, coordY, coordX + 9, coordY + 7, color);

        break;

    case 'k':

        video_box(coordX, coordY, coordX + 1, coordY + 9, color);
        video_box(coordX + 2, coordY + 4, coordX + 5, coordY + 5, color);
        video_box(coordX + 6, coordY + 2, coordX + 7, coordY + 3, color);
        video_box(coordX + 6, coordY + 6, coordX + 7, coordY + 7, color);
        video_box(coordX + 8, coordY, coordX + 9, coordY + 1, color);
        video_box(coordX + 8, coordY + 8, coordX + 9, coordY + 9, color);

        break;

    case 'l':

        video_box(coordX, coordY, coordX + 1, coordY + 7, color);
        video_box(coordX + 2, coordY + 8, coordX + 9, coordY + 9, color);

        break;

    case 'm':

        video_box(coordX, coordY, coordX + 1, coordY + 9, color);
        video_box(coordX + 2, coordY + 2, coordX + 3, coordY + 3, color);
        video_box(coordX + 4, coordY + 4, coordX + 5, coordY + 5, color);
        video_box(coordX + 6, coordY + 2, coordX + 7, coordY + 3, color);
        video_box(coordX + 8, coordY, coordX + 9, coordY + 9, color);

        break;

    case 'n':

        video_box(coordX, coordY, coordX + 1, coordY + 9, color);
        video_box(coordX + 2, coordY + 2, coordX + 3, coordY + 3, color);
        video_box(coordX + 4, coordY + 4, coordX + 5, coordY + 5, color);
        video_box(coordX + 6, coordY + 6, coordX + 7, coordY + 7, color);
        video_box(coordX + 8, coordY, coordX + 9, coordY + 9, color);

        break;

    case 'o':

        video_box(coordX, coordY + 2, coordX + 1, coordY + 7, color);
        video_box(coordX + 2, coordY, coordX + 7, coordY + 1, color);
        video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, color);
        video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 7, color);

        break;

    case 'p':

        video_box(coordX, coordY, coordX + 1, coordY + 9, color);
        video_box(coordX + 2, coordY, coordX + 7, coordY + 1, color);
        video_box(coordX + 2, coordY + 6, coordX + 7, coordY + 7, color);
        video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 5, color);

        break;

    case 'q':

        video_box(coordX, coordY + 2, coordX + 1, coordY + 7, color);
        video_box(coordX + 2, coordY, coordX + 7, coordY + 1, color);
        video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 5, color);
        video_box(coordX + 6, coordY + 6, coordX + 7, coordY + 7, color);
        video_box(coordX + 8, coordY + 8, coordX + 9, coordY + 9, color);
        video_box(coordX + 2, coordY + 8, coordX + 5, coordY + 9, color);

        break;

    case 'r':

        video_box(coordX, coordY, coordX + 1, coordY + 9, color);
        video_box(coordX + 2, coordY, coordX + 7, coordY + 1, color);
        video_box(coordX + 2, coordY + 6, coordX + 7, coordY + 7, color);
        video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 5, color);
        video_box(coordX + 8, coordY + 8, coordX + 9, coordY + 9, color);

        break;

    case 's':

        video_box(coordX + 2, coordY, coordX + 9, coordY + 1, color);
        video_box(coordX, coordY + 2, coordX + 1, coordY + 3, color);
        video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, color);
        video_box(coordX + 8, coordY + 6, coordX + 9, coordY + 7, color);
        video_box(coordX, coordY + 8, coordX + 7, coordY + 9, color);

        break;

    case 't':

        video_box(coordX, coordY, coordX + 9, coordY + 1, color);
        video_box(coordX + 4, coordY + 2, coordX + 5, coordY + 9, color);

        break;

    case 'u':

        video_box(coordX, coordY, coordX + 1, coordY + 7, color);
        video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, color);
        video_box(coordX + 8, coordY, coordX + 9, coordY + 7, color);

        break;

    case 'v':

        video_box(coordX, coordY, coordX + 1, coordY + 5, color);
        video_box(coordX + 2, coordY + 6, coordX + 3, coordY + 7, color);
        video_box(coordX + 4, coordY + 8, coordX + 5, coordY + 9, color);
        video_box(coordX + 6, coordY + 6, coordX + 7, coordY + 7, color);
        video_box(coordX + 8, coordY, coordX + 9, coordY + 5, color);

        break;

    case 'w':

        video_box(coordX, coordY, coordX + 1, coordY + 7, color);
        video_box(coordX + 4, coordY + 2, coordX + 5, coordY + 7, color);
        video_box(coordX + 8, coordY, coordX + 9, coordY + 7, color);
        video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, color);

        break;

    case 'x':

        video_box(coordX, coordY, coordX + 1, coordY + 3, color);
        video_box(coordX, coordY + 6, coordX + 1, coordY + 9, color);
        video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, color);
        video_box(coordX + 8, coordY, coordX + 9, coordY + 3, color);
        video_box(coordX + 8, coordY + 6, coordX + 9, coordY + 9, color);

        break;

    case 'y':

        video_box(coordX, coordY, coordX + 1, coordY + 3, color);
        video_box(coordX + 2, coordY + 4, coordX + 3, coordY + 5, color);
        video_box(coordX + 4, coordY + 6, coordX + 5, coordY + 9, color);
        video_box(coordX + 6, coordY + 4, coordX + 7, coordY + 5, color);
        video_box(coordX + 8, coordY, coordX + 9, coordY + 3, color);

        break;

    case 'z':

        video_box(coordX, coordY, coordX + 9, coordY + 1, color);
        video_box(coordX + 6, coordY + 2, coordX + 7, coordY + 3, color);
        video_box(coordX + 4, coordY + 4, coordX + 5, coordY + 5, color);
        video_box(coordX + 2, coordY + 6, coordX + 3, coordY + 7, color);
        video_box(coordX, coordY + 8, coordX + 9, coordY + 9, color);

        break;

    default:

        break;
    }
}

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
