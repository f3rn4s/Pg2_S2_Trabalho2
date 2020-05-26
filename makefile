MYFLAGS=-c -std=c99 -Wall -g
PROGNAME=app.out
LIBNAME=libmp3tag.a

all: app.o $(LIBNAME)
	gcc app.o -lmp3tag -L. -o $(PROGNAME)

libmp3tag.a: *.o
	ar -vq $(LIBNAME) *.o

*.o: *.c
	gcc *.c $(MYFLAGS)

#comment
clean:
	clear
	rm *.o
	rm *.out
	rm *.a

