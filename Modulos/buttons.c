#include "prototype.h"

/**
 * Alteração do estado atual do jogo.
 *
 * Utiliza o estado atual do jogo e as alterações dos sinais dos botões para indicar qual será o próximo estado.
 *
 * @param pointerStateGame   Ponteiro indicando o endereço que armazena o estado atual do jogo.
 * @param pointerButtons Ponteiro indicando o endereço que armazena o sinais lidos dos botões.
 * @return void
 */
void changePauseState(int *pointerStateGame, int *pointerButtons)
{

    switch (*pointerStateGame)
    {
    case 1: 
        if (*pointerButtons == 0) 
        {
            *pointerStateGame = 2; 
        }
        break;

    case 2:
        if (*pointerButtons == 0) 
        {
            *pointerStateGame = 1;
        }
        break;
    }
}

void rotateTetromino(int *rotationState, int *pointerButtons)
{

    if (*pointerButtons == 0) 
    {
        *rotationState = (*rotationState + 1) % 4; 
    }
}

