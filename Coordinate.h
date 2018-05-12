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
        uint row; //row position
        uint col; //col position
    public:
        //Constructor that recieves two ints for the coordinates.
        Coordinate(uint r, uint c);
        //Returns the row of the coordinate object.
        int getRow() const;
        //Returns the column of the coordinate object.
        int getCol() const;
        //Sets both coordinate values
        void setCoors(Coordinate c);
        //Sets the row of the coordinate object.
        void setRow(uint r);
        //Sets the column of the coordinate object.
        void setCol(uint c);
};
