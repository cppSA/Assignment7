CXX=clang++-5.0
CXXFLAGS=-std=c++17

all: old new

make: all main.o
	$(CXX) $(CXXFLAGS) *.o
	./a.out

old: Board.cpp Cell.cpp OurException.cpp Board.h Cell.h OurException.h
	$(CXX) $(CXXFLAGS) --compile Board.cpp -o Board.o
	$(CXX) $(CXXFLAGS) --compile Cell.cpp -o Cell.o
	$(CXX) $(CXXFLAGS) --compile OurException.cpp -o OurException.o

new: Coordinate.cpp Champion.cpp DummyPlayers.cpp TicTacToe.cpp TicTacToe.h Champion.h Coordinate.h DummyPlayers.h Board.h Player.h
	$(CXX) $(CXXFLAGS) --compile Coordinate.cpp -o Coordinate.o
	$(CXX) $(CXXFLAGS) --compile Champion.cpp -o Champion.o
	$(CXX) $(CXXFLAGS) --compile TicTacToe.cpp -o TicTacToe.o
	$(CXX) $(CXXFLAGS) --compile DummyPlayers.cpp -o DummyPlayers.o

main.o: main.cpp TicTacToe.h Champion.h DummyPlayers.h
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm *.o a.out