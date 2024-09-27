# Tetris Game

### Jogo inspirado no clássico Tetris, desenvolvido para o kit de desenvolvimento DE1-SoC utilizando linguagem C.

## Sobre o Projeto

Tetris é um jogo de quebra-cabeça clássico criado em 1984 por Alexey Pajitnov. O objetivo do jogo é encaixar peças de diferentes formatos, chamadas "tetraminós", em uma matriz vertical. O jogador pode girar e mover as peças para completar linhas horizontais. Quando uma linha é preenchida, ela é eliminada, e o jogador ganha pontos. O jogo termina quando as peças atingem o topo da tela. A simplicidade e o desafio crescente do Tetris o mantêm popular até os dias de hoje.

Este projeto recria o Tetris utilizando a placa DE1-SoC com as seguintes características:
* O código é escrito em C.
* O acelerômetro da placa é utilizado para capturar o movimento do jogador, movendo as peças lateralmente.
* Botões adicionais são usados para executar comandos no jogo, como girar as peças.
* A interface gráfica é exibida em um monitor CRT via conexão VGA.

## Requisitos do Sistema
- **Linguagem**: C
- **Placa de Desenvolvimento**: DE1-SoC
- **Entrada**: Acelerômetro e botões
- **Saída**: Monitor CRT via VGA

## Equipe

- [Alex da Fonseca Dantas Junior](https://github.com/Oguelo)
- [Bruno Campos de Oliveira Rocha](https://github.com/BRCZ1N)
- [Luis Eduardo Leite Azevedo](https://github.com/duasck)

## Sumário
- [Descrição dos Equipamentos e Software Utilizados](#equipamentos)
- [Arquitetura da placa DE1-SoC](#arq_CPU)
- [Drives de Dispositivos de Entrada e Saída (E/S)](#Drives)
- [Acelerômetro](#Acelerometro)
- [Interface Gráfica](#Interface-Grafica)
- [Dinâmica e Regras de Jogo](#Regras-de-jogo)
- [Algoritmos de Jogo](#Algoritmos)
- [Funcionamento do Jogo](#Funcionamento)
- [Conclusão](#Conclusao)

## Descrição dos Equipamentos e Software Utilizados <a name="equipamentos"></a>

### Kit de desenvolvimento DE1-SoC

A placa DE1-SoC combina um processador ARM Cortex-A9 com um FPGA Cyclone V, oferecendo uma plataforma poderosa para projetos de hardware e software. Os principais elementos utilizados neste projeto incluem:

| Categoria                                | Detalhes                                       |
| ---------------------------------------- | ---------------------------------------------- |
| **FPGA**                                 | Cyclone V SoC 5CSEMA5F31C6                     |
| Logic Elements                           | 85K                                            |
| Memória Embarcada                        | 4,450 Kbits                                    |
| Controladores de Memória                 | 2                                              |
| **Configuração e Depuração**             | EPCS128, USB Blaster II                        |
| **Memória**                              | 64MB SDRAM                                     |
| **Comunicação**                          | 2 Portas USB 2.0, Ethernet                     |
| **Display**                              | VGA DAC 24-bit                                 |
| **Botões, Interruptores e LEDs**         | 4 Teclas de Usuário (FPGA), 2 Botões de Reset (HPS) |

### Linguagem C

A escolha de C deve-se à sua eficiência e controle direto sobre o hardware, características ideais para projetos de sistemas embarcados.

### Compilador GNU (GCC)

Utilizado para compilar o código fonte, o GCC oferece suporte a várias linguagens, incluindo C, e permite personalização no processo de compilação.

### Visual Studio Code

O VSCode foi utilizado para desenvolver o código fonte do projeto, com seus recursos de realce de sintaxe, depuração e suporte a extensões.

### Monitor CRT

O monitor DELL M782p foi utilizado, oferecendo reprodução de cores vibrantes e tempo de resposta rápido, adequado para a execução do jogo em tempo real.

## Drivers de Dispositivos de Entrada e Saída (E/S) <a name="Drives"></a>

### Porta de Saída de Vídeo

O módulo `video` é responsável pela comunicação com a saída VGA. As funções principais incluem:
- `video_open`: Abre o dispositivo de vídeo VGA.
- `video_clear`: Limpa o buffer de pixels.
- `video_show`: Alterna os buffers de exibição no monitor.
- `video_box`: Desenha quadrados ou retângulos no buffer de vídeo.

### Botões

O módulo `KEYS` gerencia a interação com os botões da DE1-SoC:
- `KEY_open`: Abre o dispositivo de botões.
- `KEY_read`: Lê o estado dos botões.
- `KEY_close`: Fecha o dispositivo.

## Acelerômetro <a name="Acelerometro"></a>

O acelerômetro embutido é utilizado para mover as peças lateralmente, permitindo o controle por inclinação da placa. Movimentos detectados pelo acelerômetro são traduzidos em comandos no jogo.

## Interface do Usuário <a name="Interface-Grafica"></a>

A interface gráfica exibe o "score", o "high score" e o tabuleiro, com duas barras laterais e uma inferior. A função `drawboard` é utilizada para desenhar o tabuleiro na interface gráfica, enquanto `drawTetrominoTerminal` exibe o estado do jogo no terminal.

## Dinâmica e Regras de Jogo <a name="Regras-de-jogo"></a>

### Objetivo do Jogo
O objetivo é controlar as peças (Tetrominos) que caem e formar linhas completas. Quando uma linha é preenchida, ela é eliminada, e o jogador recebe pontos.

### Controles
- **Deslocamento Lateral**: O acelerômetro movimenta a peça para a esquerda ou direita.
- **Rotação de Peça**: Botões são usados para girar as peças.

### Colisões e Limitações
Peças colidem com o fundo do tabuleiro ou com outras peças, sendo fixadas quando atingem o limite. Linhas completas são removidas e a pontuação do jogador aumenta.

### Pontuação
A pontuação é baseada nas linhas eliminadas. Quanto mais linhas eliminadas simultaneamente, maior a pontuação.

### Fim de Jogo
O jogo termina quando as peças acumulam-se até o topo do tabuleiro.

### Tipos de Tetrominos
- **Tetromino Q (ou O)**: Quadrado 2x2, cor amarela.
- **Tetromino T**: Forma de "T", cor rosa.
- **Tetromino L**: Forma de "L", cor laranja.
- **Tetromino I**: Linha reta, cor ciano.

## Algoritmos de Jogo <a name="Algoritmos"></a>

### Algoritmo de Detecção de Colisão
Verifica colisões entre as peças e o tabuleiro, ou entre peças fixas, determinando quando uma peça deve parar de se mover e ser fixada.

### Algoritmo de Movimentação
Controla o movimento das peças com base na entrada do acelerômetro e nos ciclos de atualização do jogo. Movimenta as peças lateralmente ou para baixo.

### Algoritmo de Geração de Peças
Gera peças aleatoriamente no topo do tabuleiro e controla sua descida até serem fixadas ou o jogo terminar.

### Algoritmo de Remoção de Linhas
Remove linhas completas e move as linhas superiores para baixo, além de incrementar a pontuação do jogador.

## Funcionamento do Jogo <a name="Funcionamento"></a>

O jogo funciona através de um ciclo contínuo de geração de peças, movimento controlado pelo acelerômetro, detecção de colisões e remoção de linhas completas. O objetivo final é maximizar a pontuação até que o tabuleiro esteja cheio.

## Conclusão <a name="Conclusao"></a>

Este projeto implementa uma versão de Tetris em uma placa DE1-SoC, utilizando recursos de hardware como o acelerômetro e VGA. A combinação de controle por movimento e uma interface gráfica simples proporciona uma experiência imersiva e educativa, demonstrando a integração de software e hardware em sistemas embarcados.

