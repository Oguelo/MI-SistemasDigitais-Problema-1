#ifndef PROTOTYPE_H_INCLUDED
#define PROTOTYPE_H_INCLUDED

#include <intelfpgaup/video.h> 
#include <intelfpgaup/KEY.h>
#include <intelfpgaup/SW.h>

#include <pthread.h>    
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "constants.h"
#include "structs.h"
#include "acelerometro.h"
#include <unistd.h>

void execTetris();
int checkGameOver(PartTetromino boardMatrix[LINES][COLUMNS]);
void generatePhrase(int coordX, int coordY, char *list, int lenList, short cor);
void drawScore(int coordX, int coordY, int score);
void gamerOverScreen(int score);
void gameField(int score, int state_game, int hscore);
void generateTitle(int coordX, int coordY);
void generateChar(int coordX, int coordY, char caracter, short cor);
void changeGameState(int *pointer_state, int *pointer_buttons);
void initBoard(PartTetromino boardMatrix[LINES][COLUMNS]);
int verifyCollision(PartTetromino boardMatrix[LINES][COLUMNS], Tetromino *tetromino);
void fixTetromino(PartTetromino boardMatrix[LINES][COLUMNS], Tetromino *tetromino, int x, int y);
void removeFullLines(PartTetromino boardMatrix[LINES][COLUMNS], int *score);
void drawBoard(PartTetromino boardMatrix[LINES][COLUMNS]);
void drawBoardTerminal(PartTetromino boardMatrix[LINES][COLUMNS]);
void drawTetromino(Tetromino *tetromino);
void drawTetrominoTerminal(Tetromino tetromino);
void initTetris(PartTetromino boardMatrix[LINES][COLUMNS], Tetromino *tetromino);
void updateTetris(PartTetromino boardMatrix[LINES][COLUMNS], Tetromino tetromino);
void moveTetromino(PartTetromino boardMatrix[LINES][COLUMNS], Tetromino *tetromino, int dx, int dy, int *moved);
void generateQPattern(Tetromino *tetromino);
void generateLPattern(Tetromino *tetromino);
void generateIPattern(Tetromino *tetromino);
void gerarIPatternRotate(Tetromino *tetromino);
void generateTetromino(Tetromino *tetromino);
void clearTetromino(PartTetromino boardMatrix[LINES][COLUMNS], Tetromino *tetromino);
int buttonRead();
int keyRead();
void changePauseState(int *pointerStateGame, int *pointerButtons);
void rotateTetromino(int *rotationState, int *pointerButtons);

//Variaveis globais para o acelerometro 
int16_t axis_x;
pthread_mutex_t lock;

#endif
