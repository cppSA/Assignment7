/**
*header file of class Coordinate
*Authors Alexey Titov and Shir Bentabou
*Version 1.0
**/
#pragma once
//library
#include <iostream>

class Coordinate{
    private:
        int row; //row position
        int col; //col position
    public:
        //Constructor that recieves two ints for the coordinates.
        Coordinate(int r, int c);
        //Returns the row of the coordinate object.
        int getRow() const;
        //Returns the column of the coordinate object.
        int getCol() const;
        //Sets both coordinate values
        void setCoors(Coordinate c);
        //Sets the row of the coordinate object.
        void setRow(int r);
        //Sets the column of the coordinate object.
        void setCol(int c);
};