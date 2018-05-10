/**
*cpp file of class Coordinate
*Authors Alexey Titov and Shir Bentabou
*Version 1.0
**/

#include "Board.h"

//Constructor that recieves two ints for the coordinates.
Coordinate::Coordinate(int r, int c){
    this->row = r;
    this->col = c;
}
//Returns the row of the coordinate object.
int Coordinate::getRow(){
    return this->row;
}
//Returns the column of the coordinate object.
int Coordinate::getCol(){
    return this->col;
}
//Sets the row of the coordinate object.
void Coordinate::setRow(int r){
    this->row = r;
}
//Sets the column of the coordinate object.
void Coordinate::setCol(int c){
    this->col = c;
}
