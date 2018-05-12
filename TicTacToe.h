/**
*header file of class TicTacToe
*Authors Alexey Titov and Shir Bentabou
*Version 1.0
**/
#pragma once
//libraries
#include "Board.h"
#include "Player.h"
using namespace std;

class TicTacToe{
    public:
        int size;
        Board gameBoard;
        Player *champ;
    public:
        //Constructor
        TicTacToe(int s);
        
        //This functions checks if the game is over - if a player won or if there was a tie (board is full)
        int gameover(char ch);

        //This function executes a whole game of tic-tac-toe, and uses player and winner functions of this class.
        void play(Player& xPlayer, Player& oPlayer);

        //This function returns the board when the game has ended
        Board board() const;

        //This function returns the player that won the game
        Player& winner() const;
};