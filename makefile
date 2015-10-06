all	: godori.o
	gcc -lncurses -o godori godori.c
clean:
	rm *.o
