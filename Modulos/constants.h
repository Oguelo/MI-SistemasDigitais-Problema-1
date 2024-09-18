#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED

#define SCREEN_X 320
#define SCREEN_Y 240
#define WALL_WIDHT_X 3  // Aumentar
#define WALL_WIDHT_Y 15 // Diminuir um pouco
#define BLOCK_LENGTH 37
#define BLOCK_WIDHT 12
#define LINES 20
#define COLUMNS 10
#define BLOCK_SIZE 5
#define MAX_ROTATIONS 4
//ALEX TESTES
#define CELL_WIDTH ((208 - 108) / COLUMNS)
#define CELL_HEIGHT 220 / LINES
#define INITIAL_LIMIT_X 112
#define FINAL_LIMIT_X 212
#define INITIAL_LIMIT_Y 18

#define COLOR_WHITE 0xFFFF
#define COLOR_YELLOW 0xFFE0
#define COLOR_RED 0xF800
#define COLOR_GREEN 0x07E0
#define COLOR_BLUE 0x041F
#define COLOR_CYAN 0x07FF
#define COLOR_MAGENTA 0xF81F
#define COLOR_GREY 0xC618
#define COLOR_PINK 0xFC18
#define COLOR_ORANGE 0xFC00

typedef enum
{
    TETROMINO_Q = 0,
    TETROMINO_L = 1,
    TETROMINO_I = 2,
} TetrominoTipo;

#endif
