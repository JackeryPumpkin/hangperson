# makefile for BagTester using ArrayBag

CXX = g++

CFLAGS = -g -std=c++11

RM = rm

OBJS = GameClient.o HangLogic.o Hangman.o

EXES = GameClient

all: $(EXES)

GameClient: $(OBJS)
	$(CXX) $(CFLAGS) -o $@ $^

%.o:	%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(EXES) *.o

echo:
	echo $(CFLAGS)




	
	
	
