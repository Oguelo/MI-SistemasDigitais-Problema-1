#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED

#define SCREEN_X                320
#define SCREEN_Y                240
#define WALL_WIDHT_X            3 //Aumentar
#define WALL_WIDHT_Y            15 //Diminuir um pouco
#define BLOCK_LENGTH            37 
#define BLOCK_WIDHT             12
#define LINES                   20
#define COLUMNS                 10
#define BLOCK_SIZE              20

#define COLOR_WHITE             0xFFFF
#define COLOR_YELLOW            0xFFE0
#define COLOR_RED               0xF800
#define COLOR_GREEN             0x07E0
#define COLOR_BLUE              0x041F
#define COLOR_CYAN              0x07FF
#define COLOR_MAGENTA           0xF81F
#define COLOR_GREY              0xC618
#define COLOR_PINK              0xFC18
#define COLOR_ORANGE            0xFC00

typedef enum {
    TETROMINO_Q,         
    TETROMINO_L,        
    TETROMINO_I,         
    TETROMINO_I_ROTACIONADO 
} TetrominoTipo;

#endif
