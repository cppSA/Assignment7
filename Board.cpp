/**
*cpp file of class Board
*Authors Alexey Titov and Shir Bentabou
*Version 1.0
**/
//library
#include "Board.h"

//Constructor that receives an int that defines the board size wanted
Board::Board(int b){
    this->bound=b;
    this->board=new Cell*[b];
    for (int i=0; i<b; i++){
        this->board[i]=new Cell[b];
    }
    for (int i=0; i<this->bound; i++){
        for (int j=0; j<this->bound;j++){
            this->board[i][j].setValue('.');
        }
    }
}

//Empty constructor.
Board::Board(){}

//A copy constructor that receives a Board object and makes a deep copy to another Board object.
Board::Board(const Board& copy){
    this->bound=copy.bound;
    this->board=new Cell*[this->bound];
    for (int i=0; i<this->bound; i++){
        this->board[i]=new Cell[this->bound];
    }
    for (int i=0; i<this->bound; i++){
        for (int j=0; j<this->bound;j++){
            this->board[i][j]=copy.board[i][j];
        }
    }
}

//This function helps to delete a Board class object (used in distructor and '=' operator function).
void Board::delBoard(){
    for (int i=0; i<this->bound; i++){
        delete[] this->board[i];
    }
    delete[] this->board;
}

//Distructor for Board object - deletes everything we allocated memory for.
Board::~Board(){
    delBoard();
}

//Returns board size - written for assignment 7
int Board::size() const{
    return bound;
}


//Operator [] overloading for Board class (using List!) - for a specific cell inside the board.
Cell& Board::operator[](list<int> lst){
    int r=lst.front(), c=lst.back();
    if (r<this->bound && c<this->bound){
        return this->board[r][c];
    }
    else{
        IllegalCoordinateException ce(r,c);
        throw ce;
    }
}

//Operator [] overloading for Board class (using Coordinate class!) - for a specific cell inside the board.
Cell& Board::operator[](const Coordinate& c) const{
    int row = c.getRow();
    int col = c.getCol();
    if (row<this->bound && col<this->bound){
        return this->board[row][col];
    }
    else{
        IllegalCoordinateException ce(row,col);
        throw ce;
    }
}

//Operator '=' overloading for Board class. Inserts value to whole board if '.'. Else throws exception.
Board& Board::operator=(char c){
    if (c=='.'){
        for (int i=0; i<this->bound; i++){
            for (int j=0; j<this->bound;j++){
                this->board[i][j].setValue(c);
            }
        }
	return *this;
    }
    else{
        IllegalCharException ce;
        ce.setCh(c);
        throw ce;
    }
}

//Operator '=' overloading for Board class. Copies another Board object.
Board& Board::operator=(const Board& copy){
    delBoard();
    this->bound=copy.bound;
    this->board=new Cell*[this->bound];
    for (int i=0; i<this->bound; i++){
        this->board[i]=new Cell[this->bound];
    }
    for (int i=0; i<this->bound; i++){
        for (int j=0; j<this->bound;j++){
            this->board[i][j]=copy.board[i][j];
        }
    }
    return *this; 
}


//----------------------------------------
// friend global IO operators
//----------------------------------------
//Operator '<<' overlaoding for board class.
ostream& operator<< (ostream& os, const Board& b){
    for (int i=0; i<b.bound; i++){
        for (int j=0; j<b.bound;j++){
            os<<b.board[i][j].getValue();
        }
        os <<endl;
    }
    return os;
}