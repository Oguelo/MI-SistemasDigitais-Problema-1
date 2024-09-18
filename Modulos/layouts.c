#include "prototype.h"

 /**
  * Desenha uma frase na tela.
  *
  * Esta função desenha uma frase na tela do dispositivo de vídeo VGA, onde cada caractere
  * é desenhado em escala 10x10.
  * A frase deve esta em uma lista com esse formato:
  * char letras[] = {'H', 'e', 'l', 'l', 'o'};
  *
  * @param coordX A coordenada X do canto superior esquerdo da região onde a frase será desenhada.
  * @param coordY A coordenada Y do canto superior esquerdo da região onde a frase será desenhada.
  * @param lista Um ponteiro para a string contendo a frase a ser desenhada.
  * @param tamanhoLista O tamanho da lista contendo a frase.
  * @param cor A cor dos caracteres da frase.
  * @return void
  */
 void phrase(int coordX, int coordY, char *list, int lenList, short color)
 {

     int X;

     for (int i = 0; i < lenList; ++i)
     {

         if (list[i] != ' ')
         {

             X = coordX + i * 13;
             alphanumeric(X, coordY, list[i], color);
         }
     }
 }

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
 void write_score(int coordX, int coordY, int score)
 {

     char number_str[10];

     sprintf(number_str, "%d", score);

     int len = strlen(number_str);

     for (int i = 0; i < len; i++)
     {

         alphanumeric(coordX + (13 * i), coordY, number_str[i], COLOR_YELLOW);
     }
 }

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
 void screen_defeat(int score)
 {

     char defeat_message[9] = "game over";
     char score_message[6] = "score:";
     int sub_coordX = 0;

     if (score > 100)
     {

         sub_coordX = 10;
     }
     else if (score > 10)
     {

         sub_coordX = 5;
     }

     phrase(100, 110, defeat_message, 9, COLOR_RED);
     phrase(110 - sub_coordX, 145, score_message, 6, COLOR_YELLOW);
     write_score(188 - sub_coordX, 145, score);
 }

 /**
  * Exibe o campo de jogo.
  *
  * São mostradas: as linhas que delimitam a área de jogo; todos os blocos não destruídos;
  * a bola e a barra, nas suas determinadas posições; o valor do score; e a mensagem indicando
  * se o jogo está pausado e se a opção a ser selecionada no momento é de continuar o jogo ou
  * voltar para a tela inicial.
  *
  * @return void
  */
 void game_field(int score, int state_game)
 {

     char text_score[6] = "score:";

     phrase(0, 0, text_score, 6, COLOR_WHITE);
     write_score(78, 0, score);

     if (state_game == 1)
     {

         char text_pause[11] = "";
         phrase(177, 0, text_pause, 11, COLOR_WHITE);
     }
     else if (state_game == 2)
     {

         char text_pause[11] = "pause<play>";
         phrase(177, 0, text_pause, 11, COLOR_WHITE);
     }
     else if (state_game == 3)
     {

         char text_pause[11] = "pause<exit>";
         phrase(177, 0, text_pause, 11, COLOR_WHITE);
     }

     video_box(103, 18, 105, 239, COLOR_BLUE);   //LADO ESQUERDO
     video_box(105, 234, 213, 239, COLOR_BLUE);  //CENTRO
     video_box(213, 18, 215, 239, COLOR_BLUE);   //Lado direito
 }
