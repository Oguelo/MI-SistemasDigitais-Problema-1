#ifndef BUTTONS_H
#define BUTTONS_H

/**
 * Função de alteração do estado do jogo com base nos sinais dos botões.
 *
 * Utiliza o estado atual do jogo e as alterações dos sinais dos botões para indicar qual será o próximo estado.
 *
 * @param pointer_state   Ponteiro indicando o endereço que armazena o estado atual do jogo.
 * @param pointer_buttons Ponteiro indicando o endereço que armazena os sinais lidos dos botões.
 * @return void
 */
void change_state(int *pointer_state, int *pointer_buttons);

#endif // BUTTONS_H
