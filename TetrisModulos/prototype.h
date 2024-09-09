#ifndef PROTOTYPE_H_INCLUDED
#define PROTOTYPE_H_INCLUDED

#include <intelfpgaup/video.h>
#include <intelfpgaup/accel.h>
#include <intelfpgaup/KEY.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "constants.h"

// Lógica do layout
void phrase           (int coordX, int coordY, char *list, int lenList, short cor);
void write_score      (int coordX, int coordY, int score);
void screen_defeat    (int score);
void create_menu      ();
void game_field       (Block blocksList[], int score, int state_game);

// Escrita na tela
void title            (int coordX, int coordY);
void alphanumeric     (int coordX, int coordY, char caracter, short cor);

// Blocos
void makeBlocks       (Block blocksList[]);
void removeBlocks     (Block blocksList[], int *score,  Ball *ball);
 
// Bola
int  detect_collision (int x_rect, int y_rect, int length_rect, int width_rect,  
                      int x_boll, int y_boll, int ray, int *x_point, int *y_point);
int  getTypeCollision (Ball *ball, Block blocksList[], Bar *bar);
int  getMoveBall      (Ball *ball, Block blocksList[], Bar *bar);
void moveBall         (Ball *ball, Block blocksList[], Bar *bar);

// Barra
void moveBar          (Bar *bar, int accelX);

// Botões
void change_state     (int *pointer_state, int *pointer_buttons);

#endif // PROTOTYPE_H_INCLUDED
