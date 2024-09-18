#include "prototype.h"

// cd ./TEC499/TP01/G02
// make -f makefile.txt

// int getch(void)
// {
//     struct termios oldt, newt;
//     int ch;
//     tcgetattr(STDIN_FILENO, &oldt); // Pega os atributos atuais do terminal
//     newt = oldt;
//     newt.c_lflag &= ~(ICANON | ECHO);        // Desliga o modo canônico e de eco
//     tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Aplica as mudanças
//     ch = getchar();
//     tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restaura o modo antigo
//     return ch;
// }

void handleArrowKeys(int ch, int *dx) {
    switch (ch) {
        case 75: // Seta para esquerda
            *dx = -1;
            break;
        case 77: // Seta para direita
            *dx = 1;
            break;
        default:
            *dx = 0;
            break;
    }
}

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
    int dx = 0, dy = 1, moved = 1, score;

    while (1)
    {
        int ch;
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
            // accel_read(&ready, &tap, &dtap, &velX, &velY, &velZ, &mg_per_lsb);
            // ch = getch();
            // if (ch == 27)
            // {
            //     if (getch() == 91)
            //     {
            //         switch (getch())
            //         {
            //         case 65: // Seta para cima
            //             break;
            //         case 66: // Seta para baixo
            //             break;
            //         case 67: // Seta para direita
            //             dx = 1;
            //             break;
            //         case 68: // Seta para esquerda
            //             dx = -1;
            //             break;
            //         default:
            //             dx = 0;
            //             break;
            //         }
            //     }
            // }
            if (_kbhit()) { // Verifica se há uma tecla pressionada
            ch = _getch(); // Captura a tecla pressionada
            if (ch == 0 || ch == 224) { // Teclas especiais (setas)
                ch = _getch(); // Captura o código da seta
                handleArrowKeys(ch, &dx);
            } 
            }
            Sleep(50);

            drawBoardTerminal(boardMatrix);
            moveTetromino(boardMatrix, &currentTetromino, dx, dy, &moved);
            dx = 0;
            if (!moved)
            {
                removeFullLines(boardMatrix,&score);
                initTetromino(&currentTetromino, boardMatrix);
            }
            drawTetrominoTerminal(currentTetromino);
            // video_open();
            // video_clear();
            // game_field(score, state_game);
            // drawBoard(boardMatrix);
            // video_show();
            // video_close();
            usleep(500000);
            //  updateTetris(&currentTetromino, boardMatrix);
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
