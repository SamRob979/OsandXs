CC=gcc
CGFLAGS=-I

OsandXs: main.o boardfunctions.o gamefunctions.o
	$(CC) -o OsandXs main.o boardfunctions.o gamefunctions.o
