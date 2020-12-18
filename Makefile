CFLAGS = --std=c11 -g -Wall -Wextra -pedantic

# dependencies
main: tdnote.o liste.o
tdnote.o: tdnote.c tdnote.h liste.o
liste.o: liste.c liste.h

clean:
	rm -f *.o main
