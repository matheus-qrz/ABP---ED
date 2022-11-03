SRC=ABP.c
all: ABP
ABP: ABP.o main.o 
        gcc -o ABP ABP.o main.o

ABP.o: ABP.c
        gcc -o ABP.o -c ABP.c -W -Wall -ansi -pedantic

clean:
        rm -rf *.o

mrproper: clean
        rm -rf ABP