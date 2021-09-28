all:
	gcc calc.c -lm -lncurses -o calc
	./calc
