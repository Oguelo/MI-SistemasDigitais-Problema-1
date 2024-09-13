#ifndef PROTOTYPE_H_INCLUDED
#define PROTOTYPE_H_INCLUDED

//#include <intelfpgaup/video.h>
//#include <intelfpgaup/accel.h>
//#include <intelfpgaup/KEY.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "constants.h"
#include "structs.h"

void phrase(int coordX, int coordY, char *list, int lenList, short cor);
void write_score(int coordX, int coordY, int score);
void screen_defeat(int score);
void create_menu();
void game_field(int score, int state_game);
void title(int coordX, int coordY);
void alphanumeric(int coordX, int coordY, char caracter, short cor);
void change_state(int *pointer_state, int *pointer_buttons);
void initBoard(PartTetromino boardMatrix[LINES][COLUMNS]);
int verifyCollision(PartTetromino boardMatrix[LINES][COLUMNS], Tetromino* tetromino, int x, int y);
void fixTetromino(PartTetromino boardMatrix[LINES][COLUMNS], Tetromino* tetromino, int x, int y); 
void removeFullLines(PartTetromino boardMatrix[LINES][COLUMNS]);
void drawBoard(PartTetromino boardMatrix[LINES][COLUMNS]);
void drawBoardTerminal(PartTetromino boardMatrix[LINES][COLUMNS]);
void drawTetromino(Tetromino* tetromino);
void initTetris(Tetromino* tetromino, PartTetromino boardMatrix[LINES][COLUMNS]);
void updateTetris(Tetromino* tetromino, PartTetromino boardMatrix[LINES][COLUMNS]);
void moveTetromino(PartTetromino boardMatrix[LINES][COLUMNS], Tetromino* tetromino, int dx, int dy);
void applyGravity(PartTetromino boardMatrix[LINES][COLUMNS], Tetromino* tetromino);
void generateQPattern(Tetromino* tetromino);
void generateLPattern(Tetromino* tetromino);
void generateIPattern(Tetromino* tetromino);
void gerarIPatternRotate(Tetromino* tetromino);
void generateTetromino(Tetromino* tetromino);

#endif 
