
#include "prototype.h"

int main()
{
    /* Inicialização dos periféricos */

    /* Botões */
    int state_game, buttons;
    KEY_open();
    KEY_read(&buttons);

    int ready, tap, dtap, velX, velY, velZ, mg_per_lsb;
    accel_open();
    accel_init();
    accel_calibrate();

    video_open();

    int score = 0;
    Tetris tetris;

    while (1)
    {

        state_game = 1;
        initTetris(&tetris);

        //while (checkLose(&tetris))
        //{

            KEY_read(&buttons);
            change_state(&state_game, &buttons);

            video_clear();
            video_erase();

            if (state_game == 1)
            {
                game_field(score, state_game);
                accel_read(&ready, &tap, &dtap, &velX, &velY, &velZ, &mg_per_lsb);

                video_show();
                //applyGravity(&tetris); // Aplica a gravidade
            }
            if (state_game == 0)
            { // Estado de pausa/menu
                // Lógica para exibir o menu inicial ou pausa
                video_show();
            }
        //}

        // if (checkLose(&tetris) == 0)
        // {

        //     video_clear();
        //     video_erase();
        //     screen_defeat(score);
        //     video_show();

        // }
    }

    return 0;
}
