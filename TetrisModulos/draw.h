/**
 *  Chamadas das funções de conexão do driver da VGA. Exibição de caracteres e imagens.
 */

/**
 * Exibição do título da tela inicial. O título exibe a palavra "breakout".
 * 
 * @param coordX Coordenada X do canto superior esquerdo da região onde o título será exibido.
 * @param coordY Coordenada Y do canto superior esquerdo da região onde o título será exibido.
 * @return void
 */
void title(int coordX, int coordY);

/**
 * Exibição de caracteres.
 * 
 * @param coordX   Coordenada X do canto superior esquerdo da região onde o caractere será exibido.
 * @param coordY   Coordenada Y do canto superior esquerdo da região onde o caractere será exibido.
 * @param caracter Caractere que deve ser exibido.
 * @param color    Cor do caractere. 
 * @return void
 */
void alphanumeric(int coordX, int coordY, char caracter, short color);

