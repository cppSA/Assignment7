/**
*header file of class Player
*Authors Alexey Titov and Shir Bentabou
*Version 1.0
**/
#pragma once
//libraries
#include <string>
#include "Board.h"

class Player{
    public:
        char myChar;
        //Constructor
        /*Player(char s){
            if (s=='X' || s=='O' )
                this->myChar = s;
            else{
                IllegalCharException ce;
                ce.setCh(s);
                throw ce;
            }
        }
        //Copy constructor 
        Player(const Player& p){
                this->myChar =p.myChar;
        }*/
        //Get the player's char (myChar)
        char getChar(){
            return myChar;
        }
        //Set the player's char (myChar)
        void setChar(char ch){
            myChar = ch;
        }
        //Pure virtual function - must me implemented in classes that inherit from Player.
	    virtual const string name() const = 0;

        //Pure virtual function - must me implemented in classes that inherit from Player.
	    virtual const Coordinate play(const Board& board) = 0;
};