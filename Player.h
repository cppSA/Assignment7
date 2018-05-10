/**
*header file of class Player
*Authors Alexey Titov and Shir Bentabou
*Version 1.0
**/
#pragma once
#include <string>
#include <iostream>
#include "Board.h"
using namespace std;

class Player{

    public:

        char myChar;

        //Constructor
        Player(char s){
            if (s=='X' || s=='O' )
                this->myChar = s;
            else{
                IllegalCharException ce;
                ce.setCh(s);
                throw ce;
            }
        }
        //Get the player's char (myChar)
        char getmyChar(){
            return this->myChar;
        }

        //Pure virtual function - must me implemented in classes that inherit from Player.
	    virtual const string name() const = 0;

        //Pure virtual function - must me implemented in classes that inherit from Player.
	    virtual const Coordinate play(const Board& board) = 0;
};