
#include "prototype.h"
#include <stdio.h>

// cd ./TEC499/TP01/G02
// make -f makefile.txt

int main()
{
    /* Inicialização dos periféricos */

    /* Botões */
    int state_game, buttons;
    // KEY_open();
    // KEY_read(&buttons);

    int ready, tap, dtap, velX, velY, velZ, mg_per_lsb;
    // accel_open();
    // accel_init();
    // accel_calibrate();

    // video_open();

    int score = 0;
    Tetromino currentTetromino;
    PartTetromino boardMatrix[LINES][COLUMNS];
    int dx = 1, dy = 1;

    resetBoard(boardMatrix);
    state_game = 1;
    initTetromino(&currentTetromino, boardMatrix);

    while (1)
    {
        // printf("Tetris Terminal State:\n");
        // drawBoardTerminal(boardMatrix);
        // drawCurrentTetrominoTerminal(currentTetromino);

        // while (checkLose(&tetris))
        //{

        // KEY_read(&buttons);
        // change_state(&state_game, &buttons);

        // video_clear();
        // video_erase();

        if (state_game == 1)
        {
            // game_field(score, state_game);
            // accel_read(&ready, &tap, &dtap, &velX, &velY, &velZ, &mg_per_lsb);
            moveTetromino(boardMatrix, &currentTetromino, dx, dy);
            drawBoardTerminal(boardMatrix);
            drawTetrominoTerminal(currentTetromino);
            getchar();
            // updateTetris(&currentTetromino, boardMatrix);
            // video_show();
        }
        if (state_game == 0)
        { // Estado de pausa/menu

            // video_show();
        }
        //}

        // if (checkLose(&tetris) == 0)
        // {

        //     video_clear();
        //     video_erase();
        //     screen_defeat(score);
        //     video_show();

        // }
    }

    return 0;
}
