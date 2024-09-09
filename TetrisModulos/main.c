#include "tetris.h"
#include "board.h"
#include "constants.h"
#include <intelfpgaup/video.h>
#include <intelfpgaup/accel.h>
#include <intelfpgaup/KEY.h>


int main() {
    /* Inicialização dos periféricos */
    // Vídeo
    video_open();
    
    /* Botões */
    int state_game, buttons;
    KEY_open();
    KEY_read(&buttons);
    
    /* Acelerômetro */
    int ready, tap, dtap, velX, velY, velZ, mg_per_lsb;
    accel_open();
    accel_init();
    accel_calibrate();
    
    /* Inicializar os elementos do jogo */
    int score;
    Tetris tetris;
    iniciarTetris(&tetris);

    /* Loop principal do jogo */
    while (1) {
        /* Resetar os dados e iniciar a máquina de estado */
        state_game = 0;
        iniciarTetris(&tetris);

        /* Loop da partida do jogo */
        while (checkLose(&tetris)) {
            // Leitura dos botões e do acelerômetro
            KEY_read(&buttons);
            accel_read(&ready, &tap, &dtap, &velX, &velY, &velZ, &mg_per_lsb);
            
            video_clear();
            video_erase();

            if (state_game == 1) {  // Estado do jogo
                moverTetromino(&tetris, (velX < -LIMITE_ESQUERDA) ? -1 : (velX > LIMITE_DIREITA) ? 1 : 0, 0);  // Movimenta a peça com base no acelerômetro
                aplicarGravidade(&tetris);  // Aplica a gravidade
                video_show();
            }

            if (state_game == 0) {  // Estado de pausa/menu
                // Lógica para exibir o menu inicial ou pausa
                video_show();
            }
        }

        /* Finalização do jogo */
        if (checkLose(&tetris) == 0) {
            // Exibe tela de derrota
            video_clear();
            video_erase();
            screen_defeat(score);
            video_show();
        } else {
            screen_victory();
        }
    }

    return 0;
}
