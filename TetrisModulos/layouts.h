#ifndef DISPLAY_H
#define DISPLAY_H

#include "prototype.h"
#include "constants.h"

/**
 * Desenha uma frase na tela.
 *
 * Esta função desenha uma frase na tela do dispositivo de vídeo VGA, onde cada caractere
 * é desenhado em escala 10x10.
 * A frase deve estar em uma lista com esse formato:
 * char letras[] = {'H', 'e', 'l', 'l', 'o'};
 *
 * @param coordX A coordenada X do canto superior esquerdo da região onde a frase será desenhada.
 * @param coordY A coordenada Y do canto superior esquerdo da região onde a frase será desenhada.
 * @param list Um ponteiro para a string contendo a frase a ser desenhada.
 * @param lenList O tamanho da lista contendo a frase.
 * @param color A cor dos caracteres da frase.
 * @return void
 */
void phrase(int coordX, int coordY, char *list, int lenList, short color);

/**
 * Exibição do valor do score.
 * 
 * Converte o valor do score do tipo inteiro para um vetor do tipo char. Cada caractere do vetor
 * é percorrido e enviado para a função que irá exibir cada um dos valores.
 * 
 * @param coordX A coordenada X do canto superior esquerdo da região onde o valor será exibido.
 * @param coordY A coordenada Y do canto superior esquerdo da região onde o valor será exibido.
 * @param score Valor do score que deve ser exibido.
 * @return void
 */
void write_score(int coordX, int coordY, int score);

/**
 * Exibe a tela de derrota. 
 * 
 * São exibidas as frases "game over" e o valor do score alcançado, utilizando as funções 
 * de escrita de frase e exibição do valor do score. Dependendo de quantos algorismos o 
 * score possui, a coordenada inicial de X é alterada.
 * 
 * @param score Valor do score alcançado na rodada.
 * @return void
 */
void screen_defeat(int score);

/**
 * Exibe a tela inicial do jogo
 * 
 * É exibido o título do jogo e a frase "start game", utilizando a função de exibição do título 
 * e de exibição de frase.
 * 
 * @return void
 */
void create_menu(void);

/**
 * Exibe o campo de jogo. 
 * 
 * São mostradas: as linhas que delimitam a área de jogo; todos os blocos não destruídos; 
 * a bola e a barra, nas suas determinadas posições; o valor do score; e a mensagem indicando 
 * se o jogo está pausado e se a opção a ser selecionada no momento é de continuar o jogo ou 
 * voltar para a tela inicial.
 * 
 * @param score Valor do score a ser exibido.
 * @param state_game Estado do jogo indicando pausa ou não.
 * @return void
 */
void game_field(int score, int state_game);

#endif // DISPLAY_H
