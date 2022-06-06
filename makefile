# Variables to control Makefile operation
 
CC = g++
CFLAGS = -Wall -g
 
# ****************************************************
# Targets needed to bring the executable up to date
 
main: main.o NeuralNetwork.o
	$(CC) $(CFLAGS) -o main main.o NeuralNetwork.o
 
# The main.o target can be written more simply
 
main.o: main.cpp NeuralNetwork.hpp
	$(CC) $(CFLAGS) -c main.cpp
 
NeuralNetwork.o: NeuralNetwork.hpp

clean:
	rm -f *.o main
