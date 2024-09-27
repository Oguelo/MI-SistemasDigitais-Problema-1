#include "interfaces.h"


void generatePhrase(int coordX, int coordY, char *list, int lenList, short color)
{

    int X;

    for (int i = 0; i < lenList; ++i)
    {

        if (list[i] != ' ')
        {

            X = coordX + i * 13;
            generateChar(X, coordY, list[i], color);
        }
    }
}


void drawScore(int coordX, int coordY, int score)
{

    char number_str[10];

    sprintf(number_str, "%d", score);

    int len = strlen(number_str);

    for (int i = 0; i < len; i++)
    {

        generateChar(coordX + (13 * i), coordY, number_str[i], COLOR_YELLOW);
    }
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
void gameField(int score, int hscore)
{

    char text_score[6] = "score:";
    generatePhrase(2, 2, text_score, 6, COLOR_WHITE);
    drawScore(78, 2, score);

    char text_highscore[7] = "hscore:";
    generatePhrase(220, 2, text_highscore, 7, COLOR_WHITE);
    drawScore(310, 2, hscore);

    video_box(105, 18, 110, 239, COLOR_BLUE);  // LADO ESQUERDO
    video_box(106, 234, 212, 239, COLOR_BLUE); // CENTRO
    video_box(210, 18, 215, 239, COLOR_BLUE);  // Lado direito
}