/**
*header file of class Champion
*Authors Alexey Titov and Shir Bentabou
*Version 1.0
**/
#pragma once
//library
#include "Player.h"

class Champion: public Player {
    public:
        //We are winner
	const string name() const override{
            return "Alexey Titov + Shir Bentabou"; 
        };
        
        //we need change, set our algorithms
	const Coordinate play(const Board& board) override;
};
