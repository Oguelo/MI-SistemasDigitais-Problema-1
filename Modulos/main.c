#include "prototype.h"
int16_t axis_x;
pthread_mutex_t lock;

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

    int state_game = 1, buttons, buttonValue, buttonValueRotate;
    int16_t mg_per_lsb = 4;

    srand(time(NULL));
    
    video_open();

    Tetromino currentTetromino;
    PartTetromino boardMatrix[LINES][COLUMNS];
    int dx = 0, dy = 1, moved = 1, score, hscore;
    char text_over[4] = "over";
    char text_paused[6] = "paused";
    char text_game[4] = "game";

    while (1)
    {

        video_clear();
        video_erase();
        video_close();

        score = 0;
        resetBoard(boardMatrix);
        initTetromino(&currentTetromino);
        int pointerStateGame = 1;

        while (!checkGameOver(boardMatrix, &currentTetromino))
        {
            buttonValue = buttonRead();

            changePauseState(&pointerStateGame, &buttonValue);

            if (pointerStateGame == 1)
            {

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
                dx = 0;
                if (!moved)
                {
                    removeFullLines(boardMatrix, &score);
                    initTetromino(&currentTetromino);
                }
                drawTetrominoTerminal(currentTetromino);
                video_open();
                video_clear();
                gameField(score, hscore);
                drawBoard(boardMatrix);
                video_show();
                video_close();
                usleep(150000);
            }
            else
            {
                video_open();
                video_clear();
                gameField(score, hscore);
                drawBoard(boardMatrix);
                generatePhrase(120, 2, text_paused, 6, COLOR_RED);
                video_show();
                video_close();
            }
            drawBoardTerminal(boardMatrix);
        }
        video_open();
        video_clear();
        gameField(score, hscore);
        drawBoard(boardMatrix);
        generatePhrase(2, 150, text_game, 4, COLOR_RED);
        generatePhrase(240, 150, text_over, 4, COLOR_RED);
        video_show();
        usleep(8000000);
        video_clear();
        video_close();
        hscore = score;
    }
}
