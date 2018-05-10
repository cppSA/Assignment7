/**
*header file of class Board
*Authors Alexey Titov and Shir Bentabou
*Version 1.0
**/
//libraries
#include <iostream>
#include <string>
#include <list>
#include "Cell.h"
#include "Coordinate.h"
#include "OurException.h"
using namespace std;

class Board{
private:
    int bound;
    Cell **board;

public:
    //Constructor that receives an int that defines the board size wanted
    Board(int b);

    //A copy constructor that receives a Board object and makes a deep copy to another Board object.
    Board(Board& copy);

    //Distructor for Board object - deletes everything we allocated memory for.
    ~Board();
    
    //This function helps to delete a Board class object (used in distructor and '=' operator function).
    void delBoard();

    //Returns board size - written for assignment 7
    int size();

    //Operator [] overloading for Board class - for a specific cell inside the board.
    Cell& operator[](list<int> lst);

    //Operator [] overloading for Board class (using Coordinate class!) - for a specific cell inside the board.
    Cell& Board::operator[](Coordinate c);

    //Operator '=' overloading for Board class. Inserts value to whole board if '.'. Else throws exception.
    Board& operator=(char c);

    //Operator '=' overloading for Board class. Copies another Board object.
    Board& operator=(Board& copy);

    //----------------------------------
    // friend global IO operators
    //----------------------------------
    friend ostream& operator<< (ostream& os, const Board& b);

};

//----------------------------------------
// friend global IO operators
//----------------------------------------
//Operator '<<' overlaoding for board class.
ostream& operator<< (ostream& os, const Board& b);



