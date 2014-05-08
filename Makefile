CC=c++

all: Mastermind clean

Mastermind: main1.o Mastermind.o
        $(CC) main1.o Mastermind.o -o Mastermind

main1.o: main1.cpp
        $(CC) -c main1.cpp
        
Mastermind.o: Mastermind.cpp Mastermind.h
        $(CC) -c Mastermind.cpp Mastermind.h
        
.PHONY: clean
clean:
        rm -rf *.o *.gch
