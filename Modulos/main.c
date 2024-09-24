#include "prototype.h"

int main()
{

    pthread_t thread1, thread2, thread3;

    pthread_mutex_init(&lock, NULL);

    pthread_create(&thread1, NULL, execAccel, NULL);

    pthread_create(&thread2, NULL, execTetris, NULL);

    pthread_create(&thread3, NULL, buttonRead, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    pthread_mutex_destroy(&lock);

    return 0;
}
void execTetris(){
    /* Inicialização dos periféricos */

    /* Botões */
    int state_game = 1, buttons, buttonValue, buttonValueRotate;
    int16_t mg_per_lsb = 4;
    // KEY_open();
    // KEY_read(&buttons);

    video_open();

    Tetromino currentTetromino;
    PartTetromino boardMatrix[LINES][COLUMNS];
    int dx = 0, dy = 1, moved = 1, score, hscore;

    while (1)
    {

        video_clear();
        video_erase();

        score = 0;
        resetBoard(boardMatrix);
        initTetromino(&currentTetromino, boardMatrix);
        int pointerStateGame = 1, pointerRotateTetromino = 0, rotateFlagAnt = 0;

        while (!checkGameOver(boardMatrix))
        {
            buttonValue = buttonRead();
            changePauseState(&pointerStateGame, &buttonValue);
            buttonValueRotate = buttonRead();
       
            if (pointerStateGame == 1)
            {

                buttonValue = buttonRead();
                currentTetromino.prevRotation = currentTetromino.currentRotation;
                rotateTetromino(&pointerRotateTetromino, &buttonValueRotate);
                currentTetromino.currentRotation = pointerRotateTetromino;
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
                dx = 0;
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
            }else{
                video_open();
                char text_game[6] = "paused";
                generatePhrase(120, 2, text_game, 9,COLOR_RED);
                video_show(); 
                video_close();
            }
        }
        video_open();
        char text_game[4] = "game";
        generatePhrase(2, 150, text_game, 9,COLOR_RED);
        char text_over[4] = "over";
        generatePhrase(240, 150, text_over, 9,COLOR_RED);
        video_show(); 
        usleep(8000000);
        video_close();
        hscore = score;
    }

    
}

int buttonRead(){

   int readValue;
   KEY_open();
   KEY_read(&readValue);
   KEY_close();

   return readValue;

}