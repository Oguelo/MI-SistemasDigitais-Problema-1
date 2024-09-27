<h1 align="center"> Tetris game</h1>
<h3 align="center"> Jogo inspirado no clássico Tetris, desenvolvido para o kit de desenvolvimento DE1-SoC utilizando linguagem C </h3>

<div align="justify"> 
<div id="sobre-o-projeto"> 
<h2> Sobre o Projeto</h2>

Tetris é um clássico jogo de quebra-cabeça criado em 1984 pelo programador russo Alexey Pajitnov. Tedo como objetivo do jogo encaixar peças de diferentes formatos, chamadas "tetraminós", em uma matriz vertical. Tendo as opções de girar e posicionar as peças que caem para formar linhas horizontais completas. Quando uma linha é preenchida, ela é eliminada, e o jogador ganha pontos. O jogo termina quando as peças se acumulam e atingem o topo da tela. Tetris é amplamente reconhecido por sua simplicidade, desafio crescente e apelo universal, permanecendo popular até os dias de hoje.

Este projeto tem como objetivo desenvolver um jogo inspirado no clássico Tetris, utilizando a placa FPGA DE1-SoC para execução do sistema e controle do usuário. O jogo incorpora um acelerômetro embutido na placa, permitindo captar os movimentos desejados pelo jogador, enquanto botões são utilizados para comandos adicionais. A interface gráfica do jogo é transmitida via cabo VGA para um monitor CRT, que exibe as telas e interações ao usuário, proporcionando uma experiência de jogo fluida e integrada com os dispositivos de controle.

Os requisitos para elaboração do sistema são apresentados a seguir:

* O código carregado na DE1-SoC deve ser feito em linguagem C;
* Um acelerômetro deve captar a movimentação feita na placa para alterar a posição das peças que irão cair no tabuleiro.
* Os botões devem ser utilizados para executar comandos no jogo;
* Os dados de imagem devem ser transmitidos de um cabo VGA para um monitor CRT.

</div>

<h2>  Equipe: <br></h2>
<uL> 
  <li><a href="https://github.com/Oguelo">Alex da Fonseca Dantas Junior</a></li>
  <li><a href="https://github.com/BRCZ1N">Bruno Campos de Oliveira Rocha</a></li>
  <li><a href="https://github.com/duasck">Luis Eduardo Leite Azevedo</a></li>
 
</ul>

<h1 align="center"> Sumário </h1>
<div id="sumario">
	<ul>
        <li><a href="#equipamentos">  Descrição dos Equipamentos e Software Utilizados</a></li>
        <li><a href="#arq_CPU">  Arquitetura da placa DE1-SoC</a></li>
        <li><a href="#Drives"> Drives de Dispositivos de Entrada e Saída (E/S) </a></li>
        <li><a href="#Acelerometro"> Acelerometro </a></li>
        <li><a href="#Inteface-Grafica"> Interface do Usuário </a></li>
        <li><a href="#Regras-de-jogo"> Dinâmica e Regras de Jogo </a></li>
        <li><a href="#Algoritmos"> Algoritmos de Jogo </a></li>
         <li><a href="#Funcionamento"> Funcionamento do jogo </a></li>
          <li><a href="#conclusao"> Conclusão </a></li>
        
    

</div>

<div id="equipamentos"> 
<h2> Descrição dos Equipamentos e Software Utilizados</h2>
<div align="justify"> 

Nesta seção, são apresentados os equipamentos e software utilizados durante o desenvolvimento do projeto.

<h3>Kit de desenvolvimento DE1-SoC</h3>

A placa DE1-SoC é um kit de desenvolvimento que integra um processador ARM Cortex-A9 dual-core com um FPGA Cyclone V da Intel, proporcionando uma poderosa plataforma para projetos que combinam software e hardware. Com uma ampla variedade de periféricos, como portas VGA, Ethernet, USB, e áudio, a DE1-SoC é ideal para aplicações em sistemas embarcados e FPGA. Devido à sua versatilidade, essa placa é amplamente utilizada em ambientes educacionais e de pesquisa, facilitando o aprendizado e o desenvolvimento de projetos em ambas as áreas.
Abaixo estão os elementos utilizados na construção desse projeto:

| Categoria                               | Detalhes                                       |
| --------------------------------------- | ---------------------------------------------- |
| **FPGA**                          | Cyclone V SoC 5CSEMA5F31C6                     |
| Logic Elements                          | 85K                                            |
| Memória Embarcada                      | 4,450 Kbits                                    |
| PLLs Fracionais                         | 6                                              |
| Controladores de Memória               | 2                                              |
| **Configuração e Depuração**  | Dispositivo de Configuração Serial (EPCS128) |
| On-Board                                | USB Blaster II                                 |
| **Memória**                      | 64MB SDRAM                                     |
| DDR3 SDRAM                              | 1GB                                            |
| Micro SD                                | Sim                                            |
| **Comunicação**                 | 2 Portas USB 2.0                               |
| Ethernet                                | 10/100/1000                                    |
| **Display**                       | VGA DAC 24-bit                                 |
| Entrada de Vídeo                       | Decodificador TV                               |
| **Botões, Interruptores e LEDs** | 
4 Teclas de Usuário (FPGA)                    |
| 2 Botões de Reset (HPS)                |                                                |
| **Energia**                       | Entrada DC 12V                                 |

<h3> Linguagem C</h3>
A linguagem C foi escolhida por sua eficiência, portabilidade e ampla aplicação em sistemas embarcados. Com uma sintaxe simples, ela oferece controle preciso sobre o hardware, além de contar com bibliotecas padrão e ferramentas que facilitam o desenvolvimento de código compacto e otimizado, ideal para dispositivos com recursos limitados.

<h3> Compilador GNU</h3>

O GCC, abreviação de "GNU Compiler Collection" (Coleção de Compiladores GNU), é uma popular distribuição de compiladores que oferece suporte a diversas linguagens de programação, como C, C++, Objective-C, Fortran e Ada. Quando executado, o GCC realiza várias etapas, incluindo pré-processamento, compilação, montagem e vinculação. Ele também disponibiliza uma ampla variedade de opções de linha de comando, permitindo que o desenvolvedor personalize o processo de compilação conforme suas necessidades específicas

<h3>Vistual Studio Code</h3>

O Visual Studio Code, conhecido como VSCode, é um ambiente de desenvolvimento amplamente usado. Desenvolvido pela Microsoft, é um editor de código gratuito e de código aberto com recursos como realce de sintaxe, conclusão de código e depuração integrada. Suporta várias linguagens e possui extensões para personalização. No projeto ele foi utilizado para desenvolver o código fonte do jogo.

<h3> Monitor CRT</h3>

O monitor utilizado no projeto foi o DELL M782p, um modelo de CRT que utiliza tubo de raios catódicos para exibição de imagens. Com uma tela de 17 polegadas e resolução máxima de 1280x1024 pixels, ele oferece uma interface VGA para conexão com computadores ou placas de desenvolvimento. Os monitores CRT, como o DELL M782p, são conhecidos por sua reprodução de cores vibrantes e tempos de resposta rápidos, tornando-os ideais para projetos que exigem interação em tempo real, como jogos e simulações.


Abaixo estão dados detalhados sobre o monitor usado:

|            Características            |      Detalhes      |
| :------------------------------------: | :----------------: |
|       **Tipo de Display**       |      Vertical      |
| **Tamanho da Tela (Horizontal)** |      32,4 cm      |
|  **Tamanho da Tela (Vertical)**  |      24,6 cm      |
|  **Tamanho da Tela (Diagonal)**  |      40,6 cm      |
|      **Varredura Vertical**      |    50 - 160 Hz    |
|     **Varredura Horizontal**     |    30 - 70 kHz    |
|  **Tamanho da Tela (Diagonal)**  |   43,2 cm (17")   |
|          **Dot Pitch**          |  0,270 x 0,270 mm  |
|     **Resolução Máxima**     | 1280 x 1024 pixels |
|    **Resolução do Display**    | 1024 x 768 pixels |

</div>
</div>

# Drivers de Dispositivos de Entrada e Saída (E/S)

Para realizar a comunicação com os dispositivos periféricos de hardware, este projeto utiliza drivers, que são módulos de software responsáveis por fornecer a interface de controle sobre esses dispositivos. Abaixo estão descritos os módulos e funções de cada driver utilizado.

## Porta de Saída de Vídeo

O módulo identificado como `video` é responsável pela comunicação com o dispositivo de saída VGA. As funções utilizadas são:

- `video_open`: Abre o dispositivo de vídeo VGA.
- `video_clear`: Limpa o buffer de pixels que não está sendo transmitido para o monitor.
- `video_erase`: Limpa todos os dados de caracteres da tela.
- `video_show`: Alterna entre os buffers, modificando qual será transmitido para o monitor VGA.
- `video_box`: Desenha um quadrado ou retângulo no buffer de vídeo não transmitido. As coordenadas das extremidades e a cor são passadas como parâmetros.

## Botões

O módulo identificado como `KEYS` é responsável pela leitura dos botões da placa DE1-SoC. As funções disponíveis são:

- `KEY_open`: Abre o dispositivo responsável pelos botões.
- `KEY_read`: Lê o estado dos botões e atualiza o endereço de memória fornecido. A leitura indica se os botões foram pressionados desde a última verificação, sendo necessário limpar os dados antes de iniciar novas interações.
- `KEY_close`: Fecha o dispositivo de botões, liberando os recursos alocados para ele durante a execução.


O campo de jogo possui os seguintes elementos: o valor do score atual exibido na parte superior esquerda; O valor do hi-score exibido no canto direito; as linhas laterais e inferio para delimitar a área que os tetrominos podem percorrer;


Quando uma linha é feita de tetrominos ela é destruída, e sua respectiva pontuação é somada no score. 

Se o conjunto de tetrominos atingirem a margem superior da tela, a partida é encerrada, assim, a tela de derrota é exibida com a frase "game over" e o score alcançado. 7

 <div id="Acelerometro"> 
<h2>Acelerometro</h2>
<div align="justify">

<div id="Inteface-Grafica"> 
<h2>Interface do usuário</h2>
<div align="justify">
A interface de usuário exibe o "score", o  "high-score" e foi criado um tabuleiro com duas barras laterais e uma inferior utilizado o video_box na construção dessas imagens, centralizados na tela, foram utilizados duas funções  para exibir o estado do jogo: uma para desenhar o tabuleiro no vídeo (interface gráfica) e outra para desenhá-lo no terminal (interface de texto). Essas funções utilizam uma matriz chamada boardMatrix que representa o estado atual do tabuleiro do jogo.
A função `drawboard` desenha o tabuleiro usando a interface gráfica, onde cada célula ocupada (isNotEmpty for diferente de zero) é desenhada como um quadrado colorido. E a drawTetrominoTerminal, é usada para exibir um Tetromino individual (a peça atual em queda) no terminal.



</div>

<div id="Regras-de-jogo"> 
<h2> Dinâmica e Regras de Jogo </h2>
<div align="justify">

O objetivo principal do jogo Tetris é alcançar um score alto, fazendo os tetrominos formarem linhas em uma matriz. O jogador assume o controle de uma tetrominos  que eles caiam e formem um conjuntos ou conjuntos de linhas,Para garantir uma experiência dinâmica e desafiadora, o jogo conta com uma série de regras que serão apresentadas nesta seção.

<h2> Controles</h2>
<h3>Deslocamento Lateral: </h3>
O jogador inclina a placa para a direita ou esquerda com o acelerometro, o que move a peça na direção correspondente dentro do tabuleiro, respeitando as barreiras laterais.

<h3>Colisões e Limitações  </h3>

As peças podem se mover livremente enquanto não colidem com outras peças já fixadas ou com as bordas do tabuleiro. Ao atingir o fundo ou outras peças, a peça é "fixada" no local, e uma nova peça é gerada.

Se uma linha inteira do tabuleiro for preenchida com peças, essa linha é removida, liberando espaço e aumentando a pontuação do jogador. O jogo termina quando não há mais espaço para novas peças no topo do tabuleiro.

 <h3> Pontuação </h3>

A pontuação no Tetris é acumulada conforme as linhas completas são removidas. Quanto mais linhas forem eliminadas simultaneamente, maior será a pontuação recebida na rodada, sendo ela incrementada unitariamente, além disso ao final da rodada é armazenado e exibido a maior pontuação.

<h3> Final de jogo(Game over)  </h3>

O final de jogo é definido quando há uma colisão de peças no limite máximo inicial do tabuleiro, isto é, quando outra peça é gerada e a mesma executa a tentativa de se inserir na posição inicial, com isso 
o estado de fim de jogo(Game Over) será definido e uma representação será exibida na tela.

<h3> Tetrominos </h3>

No jogo, as peças fazem parte do ciclo natural do jogo são chamadas de Tetrominos. Elas são compostas por quatro blocos que podem ser conectados de diferentes formas.

No código fornecido, foram implementados quatro tipos de Tetrominos:

`Tetromino Q (ou O):`

Formato de um quadrado, composto por quatro blocos dispostos em uma matriz 2x2.
Cor: Amarelo.

`Tetromino T:`

Formato de uma letra "T", com três blocos na base e um bloco no centro superior.
Cor: Rosa.

`Tetromino L:`

Formato de uma letra "L", composto por três blocos em linha e um bloco adicional no final da linha.
Cor: Laranja.

`Tetromino I:`

Formato de uma linha reta composta por quatro blocos em sequência.
Cor: Ciano.

Esses Tetrominos são gerados aleatoriamente através da função 'generateTetromino'.

</div>
<div id="Algoritmos"> 
<h2> Algoritmos de Jogo </h2>
<div align="justify">

<h3>Algoritmo de detecção de colisão</h3>

Este algoritmo permite que as peças reconheçam quando colidem com o fundo do tabuleiro, outras peças ou a lateral do tabuleiro. Como cada parte de uma peça é um ponto numa matriz, foi desenvolvido um algoritmo de detecção de colisão entre peças e o tabuleiro. A lógica do algoritmo baseia-se em verificar a posição de cada bloco da peça atual e comparar com o estado do tabuleiro. Quando uma peça tenta mover-se para uma nova posição, o algoritmo checa se essa posição já está ocupada por outro bloco ou se ultrapassa os limites do tabuleiro. Se uma colisão é detectada, o movimento da peça é interrompido, e ela é fixada em sua posição final no tabuleiro.

<h3>Algoritmo de movimentação de peça</h3>

Este algoritmo é responsável por gerenciar o movimento da peça atual dentro do tabuleiro. A peça se move automaticamente para baixo a cada ciclo de atualização do jogo, e o jogador pode controlar a peça lateralmente via acelerômetro. Para isso, o algoritmo precisa verificar se os movimentos solicitados são válidos, sem ultrapassar os limites do tabuleiro ou colidir com outras peças. A lógica do algoritmo baseia-se em aplicar o movimento solicitado pela peça, seja para a esquerda ou direita, sendo esse direcionamento de deslocamento influenciado pela coordenada fornecida pelo acelerômetro. Antes de realizar o movimento, o algoritmo utiliza o algoritmo de detecção de colisão para garantir que a nova posição não esteja ocupada por outro bloco ou fora dos limites do tabuleiro. Se o movimento for permitido, a peça é deslocada; caso contrário, o movimento é bloqueado. Quando a peça atinge o fundo do tabuleiro ou colide com outra peça, ela é fixada no local, e uma nova peça é gerada no topo do tabuleiro.

<h3>Algoritmo de geração de peças</h3>

Este algoritmo é responsável por criar novas peças (tetrominos) que aparecerão no topo do tabuleiro assim que a peça anterior for fixada. As peças são geradas aleatoriamente a partir de um conjunto pré-definido de formas, e cada nova peça começa sua trajetória no topo do tabuleiro, descendo automaticamente. A lógica do algoritmo baseia-se na geração aleatória de uma peça a partir de um conjunto de tetrominos. Após a fixação de uma peça no tabuleiro, o algoritmo seleciona a próxima peça e a posiciona na parte superior central do tabuleiro. A peça começa a descer automaticamente, e o processo de movimentação e detecção de colisão se repete até que a peça seja fixada ou o jogo termine, caso o tabuleiro esteja cheio.

<h3>Algoritmo de remoção de linhas completas</h3>

Esse algoritmo é responsável por verificar se uma ou mais linhas do tabuleiro foram completamente preenchidas por blocos após a fixação de uma peça. Quando uma linha é completamente preenchida, ela é removida do tabuleiro, e todas as linhas superiores são deslocadas para baixo, liberando espaço para novas peças.A lógica do algoritmo baseia-se em percorrer cada linha do tabuleiro e verificar se todas as células daquela linha estão ocupadas por blocos. Quando uma linha completa é detectada, o algoritmo a remove, esvaziando-a, e depois desloca todas as linhas acima dela para baixo, além disso a linha removida existe o incremento da pontuação do jogador. Esse processo é repetido até que todas as linhas completas tenham sido removidas. O objetivo é liberar espaço e aumentar a pontuação do jogador, tornando o jogo mais desafiador à medida que o campo de jogo se enche novamente.

<div id="Funcionamento"> 
<h2> Funcionamento do jogo</h2>
<div align="justify">

<div id="conclusao"> 
<h2> Conclusão</h2>
<div align="justify">
