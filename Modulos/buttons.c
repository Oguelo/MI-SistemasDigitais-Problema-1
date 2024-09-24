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
        if (*pointerButtons == 2) 
        {
            *pointerStateGame = 2; 
        }
        break;

    case 2:
        if (*pointerButtons == 2) 
        {
            *pointerStateGame = 1;
        }
        break;
    }
}

void rotateTetromino(int *rotationState, int *pointerButtons)
{
    switch (*rotationState)
    {
    case 1: 
        if (*pointerButtons == 1) 
        { 
            *pointerButtons = 1;
            
        }
        break;

    case 2:
        if (*pointerButtons == 1) 
        { 
            *pointerButtons = 2;
            
        }
        break;
    case 3:
        if (*pointerButtons == 1) 
        { 
            *pointerButtons = 3;
            
        }
        break;
    case 4:
        if (*pointerButtons == 1) 
        { 
            *pointerButtons = 0;
            
        }
        break;
  
  }
}

