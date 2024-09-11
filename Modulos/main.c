
#include "prototype.h"

int main()
{
    /* Inicialização dos periféricos */

    /* Botões */
    int state_game, buttons;
    KEY_open();
    KEY_read(&buttons);

    /* Acelerômetro */
    int ready, tap, dtap, velX, velY, velZ, mg_per_lsb;
    accel_open();
    accel_init();
    accel_calibrate();

    /*Vídeo*/
    video_open();

    /* Inicializar os elementos do jogo */
    int score;
    Tetris tetris;

    /* Loop principal do jogo */
    while (1)
    {

        state_game = 0;
        iniciarTetris(&tetris);

        /* Loop da partida do jogo */
       // while (checkLose(&tetris))
       // {
            // Leitura dos botões e do acelerômetro
            KEY_read(&buttons);
            change_state(&state_game, &buttons);

            video_clear();
            video_erase();

            if (state_game == 1)
            {
                game_field(score, state_game);
                accel_read(&ready, &tap, &dtap, &velX, &velY, &velZ, &mg_per_lsb);

                video_show();

                         // Movimenta a peça com base no acelerômetro
               // aplicarGravidade(&tetris); // Aplica a gravidade
            }
            if (state_game == 0)
            { // Estado de pausa/menu
                // Lógica para exibir o menu inicial ou pausa
                video_show();
            }
       // }

        /* Finalização do jogo */
       // if (checkLose(&tetris) == 0)
       // {
            // Exibe tela de derrota
           // video_clear();
           // video_erase();
            //screen_defeat(score);
           // video_show();
       // }
       // else
       // {
        //    screen_victory();
       // }
    }

    return 0;
}
