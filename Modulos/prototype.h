#ifndef PROTOTYPE_H_INCLUDED
#define PROTOTYPE_H_INCLUDED

/*
 * prototype.h
 *
 * Este arquivo contém as declarações de funções e variáveis globais utilizadas no 
 * jogo Tetris. Inclui bibliotecas necessárias para manipulação de vídeo, 
 * controle de threads, e funções de suporte ao jogo.
 */

#include <intelfpgaup/video.h>
#include <intelfpgaup/KEY.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "constants.h"
#include "structs.h"
#include "acelerometro.h"
#include <unistd.h>

// Declarações das funções do jogo Tetris
void execTetris(); // Função que executa a lógica do jogo Tetris.
int checkGameOver(PartTetromino boardMatrix[LINES][COLUMNS], Tetromino *tetromino); // Verifica se o jogo acabou.
void generatePhrase(int coordX, int coordY, char *list, int lenList, short cor); // Gera uma frase na tela.
void drawScore(int coordX, int coordY, int score); // Desenha a pontuação na tela.
void gameField(int score, int hscore); // Desenha o campo de jogo, incluindo pontuação e alta pontuação.
void generateChar(int coordX, int coordY, char caracter, short cor); // Gera um único caractere na tela.
void changeGameState(int *pointer_state, int *pointer_buttons); // Altera o estado do jogo com base nos botões pressionados.
void initBoard(PartTetromino boardMatrix[LINES][COLUMNS]); // Inicializa o tabuleiro do jogo.
int verifyCollision(PartTetromino boardMatrix[LINES][COLUMNS], Tetromino *tetromino); // Verifica colisões do tetromino.
void fixTetromino(PartTetromino boardMatrix[LINES][COLUMNS], Tetromino *tetromino, int x, int y); // Fixa o tetromino no tabuleiro.
void removeFullLines(PartTetromino boardMatrix[LINES][COLUMNS], int *score); // Remove linhas completas do tabuleiro e atualiza a pontuação.
void drawBoard(PartTetromino boardMatrix[LINES][COLUMNS]); // Desenha o tabuleiro do jogo.
void drawBoardTerminal(PartTetromino boardMatrix[LINES][COLUMNS]); // Desenha o tabuleiro em modo terminal.
void drawTetrominoTerminal(Tetromino tetromino); // Desenha o tetromino em modo terminal.
void moveTetromino(PartTetromino boardMatrix[LINES][COLUMNS], Tetromino *tetromino, int dx, int dy, int *moved); // Move o tetromino.
void generateQPattern(Tetromino *tetromino); // Gera o padrão Q do tetromino.
void generateLPattern(Tetromino *tetromino); // Gera o padrão L do tetromino.
void generateIPattern(Tetromino *tetromino); // Gera o padrão I do tetromino.
void gerarIPatternRotate(Tetromino *tetromino); // Gera o padrão I rotacionado do tetromino.
void generateTetromino(Tetromino *tetromino); // Gera um novo tetromino.
void initTetromino(Tetromino *tetromino); // Inicializa um tetromino.
void clearTetromino(PartTetromino boardMatrix[LINES][COLUMNS], Tetromino *tetromino); // Limpa um tetromino do tabuleiro.
int buttonRead(); // Lê o estado dos botões.
void changePauseState(int *pointerStateGame, int *pointerButtons); // Altera o estado de pausa do jogo.

// Variáveis globais para o acelerômetro
extern int16_t axis_x; // Eixo X do acelerômetro.
extern pthread_mutex_t lock; // Mutex para controle de acesso a recursos compartilhados.

#endif
