#include "prototype.h"

/**
 *  Chamadas das funções de conexão do driver da VGA. Exibição de caracteres e imagens.
 */

/**
 * Exibição do título da tela inicial. O título exibe a palavra "TETRIS".
 *
 * @param coordX Coordenada X do canto superior esquerdo da região onde o título será exibido.
 * @param coordY Coordenada Y do canto superior esquerdo da região onde o título será exibido.
 * @return void
 */
// void title (int coordX, int coordY) {

//     short color1 = 0x3f9e;
//     short color2 = 0xf81f;

//     // Letra T

//     // video_box(coordX + 8, coordY     , coordX + 17, coordY +  7, color1);
//     // video_box(coordX + 18, coordY     , coordX + 19, coordY +  7, color2);
//     // video_box(coordX     , coordY +  8, coordX + 25, coordY + 13, color1);
//     // video_box(coordX + 26, coordY +  8, coordX + 27, coordY + 13, color2);
//     // video_box(coordX +  8, coordY + 14, coordX + 17, coordY + 33, color1);
//     // video_box(coordX + 18, coordY + 14, coordX + 19, coordY + 33, color2);

//     coordX += 30;

//     // Letra E

//     // video_box(coordX +  4, coordY +  8, coordX + 21, coordY + 13, color1);
//     // video_box(coordX + 22, coordY +  8, coordX + 23, coordY + 13, color2);
//     // video_box(coordX     , coordY + 14, coordX +  9, coordY + 27, color1);
//     // video_box(coordX + 10, coordY + 14, coordX + 11, coordY + 17, color2);
//     // video_box(coordX + 10, coordY + 24, coordX + 11, coordY + 27, color2);
//     // video_box(coordX + 10, coordY + 18, coordX + 25, coordY + 23, color1);
//     // video_box(coordX + 20, coordY + 14, coordX + 25, coordY + 17, color1);
//     // video_box(coordX + 26, coordY + 14, coordX + 27, coordY + 23, color2);
//     // video_box(coordX +  4, coordY + 28, coordX + 21, coordY + 33, color1);
//     // video_box(coordX + 22, coordY + 28, coordX + 23, coordY + 33, color2);

//     coordX += 30;

//     // Letra T

//     // video_box(coordX + 8, coordY     , coordX + 17, coordY +  7, color1);
//     // video_box(coordX + 18, coordY     , coordX + 19, coordY +  7, color2);
//     // video_box(coordX     , coordY +  8, coordX + 25, coordY + 13, color1);
//     // video_box(coordX + 26, coordY +  8, coordX + 27, coordY + 13, color2);
//     // video_box(coordX +  8, coordY + 14, coordX + 17, coordY + 33, color1);
//     // video_box(coordX + 18, coordY + 14, coordX + 19, coordY + 33, color2);

//     coordX += 30;

//     // Letra R

//     // video_box(coordX     , coordY +  8, coordX +  9, coordY + 33, color1);
//     // video_box(coordX + 10, coordY +  8, coordX + 11, coordY + 13, color2);
//     // video_box(coordX + 12, coordY +  8, coordX + 23, coordY + 13, color1);
//     // video_box(coordX + 24, coordY +  8, coordX + 25, coordY + 13, color2);
//     // video_box(coordX + 10, coordY + 14, coordX + 13, coordY + 19, color1);
//     // video_box(coordX + 14, coordY + 14, coordX + 15, coordY + 19, color2);
//     // video_box(coordX + 10, coordY + 20, coordX + 11, coordY + 33, color2);

//     coordX += 29;

//     // Letra I

//     // video_box(coordX +  4, coordY     , coordX +  5, coordY + 33, color1);
//     // video_box(coordX +  2, coordY +  8, coordX +  7, coordY +  9, color2);
//     // video_box(coordX +  2, coordY + 28, coordX +  7, coordY + 29, color2);

//     coordX += 10;

//     // Letra S

//     video_box(coordX    , coordY + 2, coordX + 1, coordY + 3, color1);
//     video_box(coordX + 2, coordY    , coordX + 7, coordY + 1, color1);
//     video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 3, color1);
//     video_box(coordX + 4, coordY + 4, coordX + 7, coordY + 5, color1);
//     video_box(coordX + 2, coordY + 6, coordX + 3, coordY + 7, color1);
//     video_box(coordX    , coordY + 8, coordX + 9, coordY + 9, color1);

// }

/**
 * Exibição de caracteres.
 *
 * @param coordX   Coordenada X do canto superior esquerdo da região onde o caractere será exibido.
 * @param coordY   Coordenada Y do canto superior esquerdo da região onde o caractere será exibido.
 * @param caracter Caractere que deve ser exibido.
 * @param color    Cor do caractere.
 * @return void
 */
// void alphanumeric(int coordX, int coordY, char caracter, short color) {

//     switch (caracter) {

//     case '^':

//         video_box(coordX    , coordY    , coordX + 1, coordY + 9, color);
//         video_box(coordX + 2, coordY + 1, coordX + 3, coordY + 8, color);
//         video_box(coordX + 4, coordY + 2, coordX + 5, coordY + 7, color);
//         video_box(coordX + 6, coordY + 3, coordX + 7, coordY + 6, color);
//         video_box(coordX + 8, coordY + 4, coordX + 9, coordY + 5, color);

//         break;

//     case '<':

//         video_box(coordX + 2, coordY + 4, coordX + 3, coordY + 5, color);
//         video_box(coordX + 4, coordY + 2, coordX + 5, coordY + 3, color);
//         video_box(coordX + 4, coordY + 6, coordX + 5, coordY + 7, color);
//         video_box(coordX + 6, coordY    , coordX + 7, coordY + 1, color);
//         video_box(coordX + 6, coordY + 8, coordX + 7, coordY + 9, color);

//         break;

//     case '>':

//         video_box(coordX + 2, coordY    , coordX + 3, coordY + 1, color);
//         video_box(coordX + 2, coordY + 8, coordX + 3, coordY + 9, color);
//         video_box(coordX + 4, coordY + 2, coordX + 5, coordY + 3, color);
//         video_box(coordX + 4, coordY + 6, coordX + 5, coordY + 7, color);
//         video_box(coordX + 6, coordY + 4, coordX + 7, coordY + 5, color);

//         break;

//     case ':':

//         video_box(coordX + 2, coordY + 2, coordX + 3, coordY + 3, color);
//         video_box(coordX + 2, coordY + 6, coordX + 3, coordY + 7, color);

//         break;

//     case ';':

//         video_box(coordX + 2, coordY + 2, coordX + 3, coordY + 3, color);
//         video_box(coordX + 2, coordY + 6, coordX + 3, coordY + 9, color);

//         break;

//     case '0':

//         video_box(coordX    , coordY + 2, coordX + 1, coordY + 7, color);
//         video_box(coordX + 2, coordY    , coordX + 7, coordY + 1, color);
//         video_box(coordX + 4, coordY + 4, coordX + 5, coordY + 5, color);
//         video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, color);
//         video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 7, color);

//         break;

//     case '1':

//         video_box(coordX + 2, coordY    , coordX + 3, coordY + 1, color);
//         video_box(coordX + 4, coordY    , coordX + 5, coordY + 7, color);
//         video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, color);

//         break;

//     case '2':

//         video_box(coordX    , coordY + 2, coordX + 1, coordY + 3, color);
//         video_box(coordX + 2, coordY    , coordX + 7, coordY + 1, color);
//         video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 3, color);
//         video_box(coordX + 4, coordY + 4, coordX + 7, coordY + 5, color);
//         video_box(coordX + 2, coordY + 6, coordX + 3, coordY + 7, color);
//         video_box(coordX    , coordY + 8, coordX + 9, coordY + 9, color);

//         break;

//     case '3':

//         video_box(coordX    , coordY + 2, coordX + 1, coordY + 3, color);
//         video_box(coordX + 2, coordY    , coordX + 7, coordY + 1, color);
//         video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 3, color);
//         video_box(coordX + 4, coordY + 4, coordX + 7, coordY + 5, color);
//         video_box(coordX    , coordY + 6, coordX + 1, coordY + 7, color);
//         video_box(coordX + 8, coordY + 6, coordX + 9, coordY + 7, color);
//         video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, color);

//         break;

//     case '4':

//         video_box(coordX    , coordY    , coordX + 1, coordY + 5, color);
//         video_box(coordX + 2, coordY + 6, coordX + 7, coordY + 7, color);
//         video_box(coordX + 8, coordY    , coordX + 9, coordY + 9, color);

//         break;

//     case '5':

//         video_box(coordX    , coordY    , coordX + 9, coordY + 1, color);
//         video_box(coordX    , coordY + 2, coordX + 1, coordY + 3, color);
//         video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, color);
//         video_box(coordX + 8, coordY + 6, coordX + 9, coordY + 7, color);
//         video_box(coordX    , coordY + 8, coordX + 7, coordY + 9, color);

//         break;

//     case '6':

//         video_box(coordX    , coordY + 2, coordX + 1, coordY + 7, color);
//         video_box(coordX + 2, coordY    , coordX + 9, coordY + 1, color);
//         video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, color);
//         video_box(coordX + 8, coordY + 6, coordX + 9, coordY + 7, color);
//         video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, color);

//         break;

//     case '7':

//         video_box(coordX    , coordY    , coordX + 9, coordY + 1, color);
//         video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 3, color);
//         video_box(coordX + 6, coordY + 4, coordX + 7, coordY + 5, color);
//         video_box(coordX + 4, coordY + 6, coordX + 5, coordY + 7, color);
//         video_box(coordX + 2, coordY + 8, coordX + 3, coordY + 9, color);

//         break;

//     case '8':

//         video_box(coordX + 2, coordY    , coordX + 7, coordY + 1, color);
//         video_box(coordX    , coordY + 2, coordX + 1, coordY + 3, color);
//         video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 3, color);
//         video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, color);
//         video_box(coordX    , coordY + 6, coordX + 1, coordY + 7, color);
//         video_box(coordX + 8, coordY + 6, coordX + 9, coordY + 7, color);
//         video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, color);

//         break;

//     case '9':

//         video_box(coordX + 2, coordY    , coordX + 7, coordY + 1, color);
//         video_box(coordX    , coordY + 2, coordX + 1, coordY + 3, color);
//         video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, color);
//         video_box(coordX    , coordY + 8, coordX + 7, coordY + 9, color);
//         video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 7, color);

//         break;

//     case 'a':

//         video_box(coordX, coordY + 2, coordX + 1, coordY + 9, color);
//         video_box(coordX + 2, coordY, coordX + 7, coordY + 1, color);
//         video_box(coordX + 2, coordY + 6, coordX + 7, coordY + 7, color);
//         video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 9, color);

//         break;

//     case 'b':

//         video_box(coordX, coordY, coordX + 1, coordY + 9, color);
//         video_box(coordX + 2, coordY, coordX + 7, coordY + 1, color);
//         video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, color);
//         video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, color);
//         video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 3, color);
//         video_box(coordX + 8, coordY + 6, coordX + 9, coordY + 7, color);

//         break;

//     case 'c':

//         video_box(coordX, coordY + 2, coordX + 1, coordY + 7, color);
//         video_box(coordX + 2, coordY, coordX + 9, coordY + 1, color);
//         video_box(coordX + 2, coordY + 8, coordX + 9, coordY + 9, color);

//         break;

//     case 'd':

//         video_box(coordX, coordY, coordX + 1, coordY + 9, color);
//         video_box(coordX + 2, coordY, coordX + 7, coordY + 1, color);
//         video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, color);
//         video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 7, color);

//         break;

//     case 'e':

//         video_box(coordX, coordY, coordX + 1, coordY + 9, color);
//         video_box(coordX + 2, coordY, coordX + 9, coordY + 1, color);
//         video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, color);
//         video_box(coordX + 2, coordY + 8, coordX + 9, coordY + 9, color);

//         break;

//     case 'f':

//         video_box(coordX, coordY, coordX + 1, coordY + 9, color);
//         video_box(coordX + 2, coordY, coordX + 9, coordY + 1, color);
//         video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, color);

//         break;

//     case 'g':

//         video_box(coordX, coordY + 2, coordX + 1, coordY + 7, color);
//         video_box(coordX + 2, coordY, coordX + 9, coordY + 1, color);
//         video_box(coordX + 4, coordY + 4, coordX + 9, coordY + 5, color);
//         video_box(coordX + 8, coordY + 6, coordX + 9, coordY + 7, color);
//         video_box(coordX + 2, coordY + 8, coordX + 9, coordY + 9, color);

//         break;

//     case 'h':

//         video_box(coordX, coordY, coordX + 1, coordY + 9, color);
//         video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, color);
//         video_box(coordX + 8, coordY, coordX + 9, coordY + 9, color);

//         break;

//     case 'i':

//         video_box(coordX + 2, coordY, coordX + 7, coordY + 1, color);
//         video_box(coordX + 4, coordY + 2, coordX + 5, coordY + 7, color);
//         video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, color);

//         break;

//     case 'j':

//         video_box(coordX, coordY + 4, coordX + 1, coordY + 7, color);
//         video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, color);
//         video_box(coordX + 8, coordY, coordX + 9, coordY + 7, color);

//         break;

//     case 'k':

//         video_box(coordX, coordY, coordX + 1, coordY + 9, color);
//         video_box(coordX + 2, coordY + 4, coordX + 5, coordY + 5, color);
//         video_box(coordX + 6, coordY + 2, coordX + 7, coordY + 3, color);
//         video_box(coordX + 6, coordY + 6, coordX + 7, coordY + 7, color);
//         video_box(coordX + 8, coordY, coordX + 9, coordY + 1, color);
//         video_box(coordX + 8, coordY + 8, coordX + 9, coordY + 9, color);

//         break;

//     case 'l':

//         video_box(coordX, coordY, coordX + 1, coordY + 7, color);
//         video_box(coordX + 2, coordY + 8, coordX + 9, coordY + 9, color);

//         break;

//     case 'm':

//         video_box(coordX, coordY, coordX + 1, coordY + 9, color);
//         video_box(coordX + 2, coordY + 2, coordX + 3, coordY + 3, color);
//         video_box(coordX + 4, coordY + 4, coordX + 5, coordY + 5, color);
//         video_box(coordX + 6, coordY + 2, coordX + 7, coordY + 3, color);
//         video_box(coordX + 8, coordY, coordX + 9, coordY + 9, color);

//         break;

//     case 'n':

//         video_box(coordX, coordY, coordX + 1, coordY + 9, color);
//         video_box(coordX + 2, coordY + 2, coordX + 3, coordY + 3, color);
//         video_box(coordX + 4, coordY + 4, coordX + 5, coordY + 5, color);
//         video_box(coordX + 6, coordY + 6, coordX + 7, coordY + 7, color);
//         video_box(coordX + 8, coordY, coordX + 9, coordY + 9, color);

//         break;

//     case 'o':

//         video_box(coordX, coordY + 2, coordX + 1, coordY + 7, color);
//         video_box(coordX + 2, coordY, coordX + 7, coordY + 1, color);
//         video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, color);
//         video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 7, color);

//         break;

//     case 'p':

//         video_box(coordX, coordY, coordX + 1, coordY + 9, color);
//         video_box(coordX + 2, coordY, coordX + 7, coordY + 1, color);
//         video_box(coordX + 2, coordY + 6, coordX + 7, coordY + 7, color);
//         video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 5, color);

//         break;

//     case 'q':

//         video_box(coordX, coordY + 2, coordX + 1, coordY + 7, color);
//         video_box(coordX + 2, coordY, coordX + 7, coordY + 1, color);
//         video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 5, color);
//         video_box(coordX + 6, coordY + 6, coordX + 7, coordY + 7, color);
//         video_box(coordX + 8, coordY + 8, coordX + 9, coordY + 9, color);
//         video_box(coordX + 2, coordY + 8, coordX + 5, coordY + 9, color);

//         break;

//     case 'r':

//         video_box(coordX, coordY, coordX + 1, coordY + 9, color);
//         video_box(coordX + 2, coordY, coordX + 7, coordY + 1, color);
//         video_box(coordX + 2, coordY + 6, coordX + 7, coordY + 7, color);
//         video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 5, color);
//         video_box(coordX + 8, coordY + 8, coordX + 9, coordY + 9, color);

//         break;

//     case 's':

//         video_box(coordX + 2, coordY, coordX + 9, coordY + 1, color);
//         video_box(coordX, coordY + 2, coordX + 1, coordY + 3, color);
//         video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, color);
//         video_box(coordX + 8, coordY + 6, coordX + 9, coordY + 7, color);
//         video_box(coordX, coordY + 8, coordX + 7, coordY + 9, color);

//         break;

//     case 't':

//         video_box(coordX, coordY, coordX + 9, coordY + 1, color);
//         video_box(coordX + 4, coordY + 2, coordX + 5, coordY + 9, color);

//         break;

//     case 'u':

//         video_box(coordX, coordY, coordX + 1, coordY + 7, color);
//         video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, color);
//         video_box(coordX + 8, coordY, coordX + 9, coordY + 7, color);

//         break;

//     case 'v':

//         video_box(coordX, coordY, coordX + 1, coordY + 5, color);
//         video_box(coordX + 2, coordY + 6, coordX + 3, coordY + 7, color);
//         video_box(coordX + 4, coordY + 8, coordX + 5, coordY + 9, color);
//         video_box(coordX + 6, coordY + 6, coordX + 7, coordY + 7, color);
//         video_box(coordX + 8, coordY, coordX + 9, coordY + 5, color);

//         break;

//     case 'w':

//         video_box(coordX, coordY, coordX + 1, coordY + 7, color);
//         video_box(coordX + 4, coordY + 2, coordX + 5, coordY + 7, color);
//         video_box(coordX + 8, coordY, coordX + 9, coordY + 7, color);
//         video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, color);

//         break;

//     case 'x':

//         video_box(coordX, coordY, coordX + 1, coordY + 3, color);
//         video_box(coordX, coordY + 6, coordX + 1, coordY + 9, color);
//         video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, color);
//         video_box(coordX + 8, coordY, coordX + 9, coordY + 3, color);
//         video_box(coordX + 8, coordY + 6, coordX + 9, coordY + 9, color);

//         break;

//     case 'y':

//         video_box(coordX, coordY, coordX + 1, coordY + 3, color);
//         video_box(coordX + 2, coordY + 4, coordX + 3, coordY + 5, color);
//         video_box(coordX + 4, coordY + 6, coordX + 5, coordY + 9, color);
//         video_box(coordX + 6, coordY + 4, coordX + 7, coordY + 5, color);
//         video_box(coordX + 8, coordY, coordX + 9, coordY + 3, color);

//         break;

//     case 'z':

//         video_box(coordX, coordY, coordX + 9, coordY + 1, color);
//         video_box(coordX + 6, coordY + 2, coordX + 7, coordY + 3, color);
//         video_box(coordX + 4, coordY + 4, coordX + 5, coordY + 5, color);
//         video_box(coordX + 2, coordY + 6, coordX + 3, coordY + 7, color);
//         video_box(coordX, coordY + 8, coordX + 9, coordY + 9, color);

//         break;

//     default:

//         break;
//     }
// }

void drawBoard(PartTetromino boardMatrix[LINES][COLUMNS])
{

    for (int i = 0; i < LINES; i++)
    {

        for (int j = 0; j < COLUMNS; j++)
        {

            if (boardMatrix[i][j].isNotEmpty != 0)
            {

                int x = j * BLOCK_SIZE;
                int y = i * BLOCK_SIZE;

                // video_box(x, y, x + BLOCK_SIZE, y + BLOCK_SIZE, boardMatrix[i][j].color);
            }
        }
    }
}

void drawTetromino(Tetromino* tetromino)
{

    for (int i = 0; i < 4; i++)
    {

        for (int j = 0; j < 4; j++)
        {

            if (tetromino->pattern[i][j] != 0)
            {
                // video_box(
                // tetris->x * SCREEN_X / 2,
                // tetris->y + i * BLOCK_SIZE,
                // tetris->x + (j+1) * BLOCK_SIZE,
                // tetris->y + (i+1) * BLOCK_SIZE,
                // tetris->currentTetromino.color
                //);
            }
        }
    }
}

void drawBoardTerminal(PartTetromino boardMatrix[LINES][COLUMNS]) {
    for (int i = 0; i < LINES; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (boardMatrix[i][j].isNotEmpty != 0) {
               
                printf("# ");
            } else {
                
                printf(". ");
            }
        }
        printf("\n");
    }
}

void drawCurrentTetrominoTerminal(Tetromino* tetromino) {
   
    printf("Cor: %u\n", tetromino->color);

    
    printf("Padrao:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (tetromino->pattern[i][j] != 0) {
                printf("# ");  
            } else {
                printf(". ");  
            }
        }
        printf("\n");  
    }
}



void updateTetris(Tetromino* tetromino, PartTetromino boardMatrix[LINES][COLUMNS])
{

    drawBoard(boardMatrix);
    drawTetromino(tetromino);
}
