#include "prototype.h"

int main()
{

    pthread_t thread1, thread2;

    pthread_mutex_init(&lock, NULL);

    pthread_create(&thread1, NULL, execAccel, NULL);

    pthread_create(&thread2, NULL, execTetris, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&lock);

    return 0;
}
void execTetris()
{
    /* Inicialização dos periféricos */

    /* Botões */
    int state_game = 1, buttons;
    int16_t mg_per_lsb = 4;
    // KEY_open();
    // KEY_read(&buttons);

    video_open();

    Tetromino currentTetromino;
    PartTetromino boardMatrix[LINES][COLUMNS];
    int dx = 0, dy = 1, moved = 1, score, hscore;

    while (1)
    {

        // KEY_read(&buttons);
        // changeGameState(&state_game, &buttons);

        video_clear();
        video_erase();

        score = 0;
        resetBoard(boardMatrix);
        initTetromino(&currentTetromino, boardMatrix);

        while (!checkGameOver(boardMatrix))
        {
            drawBoardTerminal(boardMatrix);
            pthread_mutex_lock(&lock);
            if (axis_x * mg_per_lsb >= 100)
            {

                dx = 1;
            }
            else if (axis_x * mg_per_lsb <= -100)
            {

                dx = -1;
            }
            else
            {

                dx = 0;
            }
            pthread_mutex_unlock(&lock);
            moveTetromino(boardMatrix, &currentTetromino, dx, dy, &moved);
            if (!moved)
            {
                removeFullLines(boardMatrix, &score);
                initTetromino(&currentTetromino, boardMatrix);
            }
            drawTetrominoTerminal(currentTetromino);
            video_open();
            video_clear();
            gameField(score, state_game, hscore);
            drawBoard(boardMatrix);
            video_show();
            video_close();
            usleep(350000);
        }
        hscore = score;
    }
}
