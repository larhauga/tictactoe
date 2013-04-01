
all: classes
	g++ tictactoe.cpp class*.o -o tictactoe

classes:
	g++ -c class*.cpp

