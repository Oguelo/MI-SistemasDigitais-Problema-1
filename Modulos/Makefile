all:
	clear
	gcc -w -Wall main.c board.c ADXL345.c buttons.c draw.c layouts.c tetromino.c -o tetris -pthread -lintelfpgaup -lm -std=c99
	sudo ./tetris