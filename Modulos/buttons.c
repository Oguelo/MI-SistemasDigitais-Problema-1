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

int rotateTetromino(int *rotationState, int *pointerButtons) {
    printf("\n entrou na func \n");
    printf("\n valor da rotacao é %d \n", *rotationState);
        if (*rotationState == 0 & *pointerButtons == 1) {
            printf("entrou na 0\n");
            return 1;
        }
        if (*rotationState == 1 & *pointerButtons == 1) {
            printf("entrou na 1\n");
            return 2;
        }
        if (*rotationState == 2 & *pointerButtons == 1) {
            printf("entrou na 2\n");
            return 3;
        }
        if (*rotationState == 3 & *pointerButtons == 1) {
            printf("entrou na 3\n");
            return 0;
        }
    
}

int buttonRead(){

   int readValue;
   KEY_open();
   KEY_read(&readValue);
   KEY_close();

   return readValue;

}

