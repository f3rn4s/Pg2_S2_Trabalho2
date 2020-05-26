MYFLAGS=-c -std=c99 -Wall -g
PROGNAME=app.out
LIBNAME=libmp3tag.a

all: app.o $(LIBNAME)
	gcc app.o -lmp3tag -L. -o $(PROGNAME)

libmp3tag.a: tag.o setdata.o listfiles.o name_format.o
	ar -vq $(LIBNAME) tag.o setdata.o listfiles.o name_format.o

app.o: app.c
	gcc app.c $(MYFLAGS)
	
tag.o: tag.c
	gcc tag.c $(MYFLAGS)
	
setdata.o: setdata.c
	gcc setdata.c $(MYFLAGS)

listfiles.o: listfiles.c
	gcc listfiles.c $(MYFLAGS)

name_format.o: name_format.c
	gcc name_format.c $(MYFLAGS)

#comment
clean:
	clear
	rm *.o
	rm *.out
	rm *.a

