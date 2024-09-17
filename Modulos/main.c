
#include "prototype.h"
#include <stdio.h>

// cd ./TEC499/TP01/G02
// make -f makefile.txt

int main()
{
    /* Inicialização dos periféricos */

    /* Botões */
    int state_game = 1, buttons;
    // KEY_open();
    // KEY_read(&buttons);

    int ready, tap, dtap, velX, velY, velZ, mg_per_lsb;
    // accel_open();
    // accel_init();
    // accel_calibrate();

    // video_open();

    Tetromino currentTetromino;
    PartTetromino boardMatrix[LINES][COLUMNS];
    int dx = 1, dy = 1, moved = 1, score;

    while (1)
    {
        
        // drawBoardTerminal(boardMatrix);
        // drawCurrentTetrominoTerminal(currentTetromino);

        // while (checkLose(&tetris))
        //{

        // KEY_read(&buttons);
        // change_state(&state_game, &buttons);

        // video_clear();
        // video_erase();

        score = 0;
        resetBoard(boardMatrix);
        initTetromino(&currentTetromino, boardMatrix);

        while (!checkGameOver(boardMatrix))
        {
            // game_field(score, state_game);
            // accel_read(&ready, &tap, &dtap, &velX, &velY, &velZ, &mg_per_lsb);
            if (!moved)
            {
                initTetromino(&currentTetromino, boardMatrix);
            }
            drawBoardTerminal(boardMatrix);
            moveTetromino(boardMatrix, &currentTetromino, dx, dy, &moved);
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
