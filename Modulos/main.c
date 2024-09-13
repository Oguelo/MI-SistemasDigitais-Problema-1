
#include "prototype.h"

// cd ./TEC499/TP01/G02 
// make -f makefile.txt

int main()
{
    /* Inicialização dos periféricos */

    /* Botões */
    int state_game, buttons;
    //KEY_open();
    //KEY_read(&buttons);

    int ready, tap, dtap, velX, velY, velZ, mg_per_lsb;
    //accel_open();
    //accel_init();
    //accel_calibrate();

    //video_open();

    int score = 0;
    Tetromino currentTetromino;
    PartTetromino boardMatrix[LINES][COLUMNS];

    resetBoard(boardMatrix);
    state_game = 1;

    while (1)
    {
        initTetromino(&currentTetromino, boardMatrix);
        printf("Tetris Terminal State:\n");
        drawBoardTerminal(boardMatrix);
        drawCurrentTetrominoTerminal(currentTetromino);
        sleep(5000);
        
        //while (checkLose(&tetris))
        //{

            //KEY_read(&buttons);
            change_state(&state_game, &buttons);

            //video_clear();
            //video_erase();

            if (state_game == 1)
            {
                game_field(score, state_game);
                //accel_read(&ready, &tap, &dtap, &velX, &velY, &velZ, &mg_per_lsb);

                updateTetris(&currentTetromino, boardMatrix);


                //video_show();
                //applyGravity(&tetris); // Aplica a gravidade
            }
            if (state_game == 0)
            { // Estado de pausa/menu
                
                //video_show();
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
