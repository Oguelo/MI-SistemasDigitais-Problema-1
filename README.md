<h1 align="center"> Tetris game</h1>
<h3 align="center"> Jogo inspirado no clássico Tetris, desenvolvido para o kit de desenvolvimento DE1-SoC utilizando linguagem C </h3>

<div align="justify"> 
<div id="sobre-o-projeto"> 
<h2> Sobre o Projeto</h2>

Tetris é um clássico jogo de quebra-cabeça criado em 1984 pelo programador russo Alexey Pajitnov. Tedo como objetivo do jogo encaixar peças de diferentes formatos, chamadas "tetraminós", em uma matriz vertical. Tendo as opções de girar e posicionar as peças que caem para formar linhas horizontais completas. Quando uma linha é preenchida, ela é eliminada, e o jogador ganha pontos. O jogo termina quando as peças se acumulam e atingem o topo da tela. Tetris é amplamente reconhecido por sua simplicidade, desafio crescente e apelo universal, permanecendo popular até os dias de hoje.

Este projeto tem como objetivo desenvolver um jogo inspirado no clássico Tetris, utilizando a placa FPGA DE1-SoC para execução do sistema e controle do usuário. O jogo incorpora um acelerômetro embutido na placa, permitindo captar os movimentos desejados pelo jogador, enquanto botões são utilizados para comandos adicionais. A interface gráfica do jogo é transmitida via cabo VGA para um monitor CRT, que exibe as telas e interações ao usuário, proporcionando uma experiência de jogo fluida e integrada com os dispositivos de controle.

Os requisitos para elaboração do sistema são apresentados a seguir:

* O código carregado na DE1-SoC deve ser feito em linguagem C;
* Um acelerômetro deve captar a movimentação feita na placa para alterar a posição da barra que irá colidir com a bola;
* Os botões devem ser utilizados para executar comandos no jogo;
* Os dados de imagem devem ser transmitidos de um cabo VGA para um monitor CRT.

</div>

<h2>  Equipe: <br></h2>
<uL> 
  <li><a href="https://github.com/Oguelo">Alex da Fonseca Dantas Junior</a></li>
  <li><a href="https://github.com/BRCZ1N">Bruno Campos de Oliveira Rocha</a></li>
 
</ul>

<h1 align="center"> Sumário </h1>
<div id="sumario">
	<ul>
        <li><a href="#equipamentos">  Descrição dos Equipamentos e Software Utilizados</a></li>
        <li><a href="#arq_CPU">  Arquitetura da placa DE1-SoC</a></li>
        <li><a href="#Drives"> Drives de Dispositivos de Entrada e Saída (E/S) </a></li>
        <li><a href="#Inteface-Grafica"> Interface do Usuário </a></li>
        <li><a href="#Regras-de-jogo"> Dinâmica e Regras de Jogo </a></li>
    
	</ul>	
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



<div id="Drives"> 
<h2> Drives de Dispositivos de Entrada e Saída (E/S)</h2>
<div align="justify">

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

Se o conjunto de tetrominos atingirem a margem superior da tela, a partida é encerrada, assim, a tela de derrota é exibida com a frase "game over" e o score alcançado. 

# Interface do Usuário

// pra fazer
--- 


</div>

<div id="Regras-de-jogo"> 
<h2> Dinâmica e Regras de Jogo </h2>
<div align="justify">

O objetivo principal do jogo Tetris é alcançar um score alto, fazendo os tetrominos formarem linhas em uma matriz. O jogador assume o controle de uma tetrominos  que eles caiam e formem um conjuntos ou conjuntos de linhas,Para garantir uma experiência dinâmica e desafiadora, o jogo conta com uma série de regras que serão apresentadas nesta seção.

<h2> Controles</h2>
<h3>Deslocamento Lateral: </h3>
O jogador inclina a placa para a direita ou esquerda com o acelerometro, o que move a peça na direção correspondente dentro do tabuleiro, respeitando as barreiras laterais.

<h3>Rotação da Peça:   </h3>
Um dos botões disponíveis na placa é responsável por rotacionar a peça em 90 graus.


<h3>Colisões e Limitações  </h3>

As peças podem se mover livremente enquanto não colidem com outras peças já fixadas ou com as bordas do tabuleiro. Ao atingir o fundo ou outras peças, a peça é "fixada" no local, e uma nova peça é gerada.

Se uma linha inteira do tabuleiro for preenchida com peças, essa linha é removida, liberando espaço e aumentando a pontuação do jogador. O jogo termina quando não há mais espaço para novas peças no topo do tabuleiro.

 <h3> Pontuação </h3>

A pontuação no Tetris é acumulada conforme as linhas completas são removidas. Quanto mais linhas forem eliminadas simultaneamente, maior será a pontuação recebida, sendo ela contada de 1 em 1, no final um hi score é gerado após o game over.
<h3> Game over  </h3>
O game over é definido quando uma das posições da matriz principal na linha 0 esta ocupada e outra peça gerada está a disputar o mesmo espaço, assim o game over será definido e uma representação será exibida na tela.

</div>
<div id="Algoritmos"> 
<h2> Algoritmos de Jogo </h2>
<div align="justify">

<h3> Algoritmo de Colisão </h3>

Este algoritmo permite que as peças reconheçam quando colidem com o fundo do tabuleiro, com outras peças ou com a lateral do tabuleiro. Como cada parte de uma peça é um ponto numa matriz, foi desenvolvido um algoritmo clássico de detecção de colisão entre peças e o tabuleiro .

A lógica do algoritmo baseia-se em verificar a posição de cada bloco da peça atual e comparar com o estado do tabuleiro. Quando uma peça tenta mover-se para uma nova posição, o algoritmo checa se essa posição já está ocupada por outro bloco ou se ultrapassa os limites do tabuleiro. Se uma colisão é detectada, o movimento da peça é interrompido, e ela é fixada em sua posição final no tabuleiro.

Em seguida, o algoritmo verifica se alguma linha foi completamente preenchida. Caso positivo, a linha é eliminada e as linhas acima dela descem, mantendo o espaço para novas peças.

<h3> Algoritmo de Verificação Contínua </h3>

O movimento contínuo das peças no Tetris é essencial para a jogabilidade. Para garantir que as peças se movam suavemente, o algoritmo de movimentação contínua foi implementado. Este algoritmo atualiza a posição das peças a cada intervalo de tempo, movendo-as automaticamente para baixo até que uma colisão seja detectada.

Durante a queda contínua, o jogador pode mover a peça para os lados ou rotacioná-la. O algoritmo de movimentação contínua verifica se o movimento lateral ou a rotação são válidos, checando se há espaço suficiente no tabuleiro para realizar a ação desejada.

Se uma colisão for detectada durante o movimento da peça, ela é fixada em sua posição atual, e uma nova peça é gerada no topo do tabuleiro, reiniciando o ciclo.
