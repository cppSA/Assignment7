/**
*cpp file of class TicTacToe
*Authors Alexey Titov and Shir Bentabou
*Version 2.0
**/
//libraries
#include "TicTacToe.h"
#include <string>

    //Constructor
    TicTacToe::TicTacToe(int s):gameBoard(s){
        this->size = s;
    }
        
    //This functions checks if the game is over - if a player won or if there was a tie (board is full)
    int TicTacToe::gameover(char ch){
        uint i,j;
        int victory = 1;

        for(i = 0; i< this->size; i++){
            victory = 1;
            for(j = 0; j<this->size; j++){
                if(this->gameBoard[{i,j}] != ch){
                    victory = 0;
                    break;
                }
            }
            if(victory)
                return 1;
            victory = 1;
            for(j = 0; j<this->size; j++){
                if(this->gameBoard[{j,i}] != ch){
                    victory = 0;
                    break;
                }
            }
            if(victory) 
                return 1;
        }
        victory = 1;
        for(i = 0; i< this->size; i++){
            if(this->gameBoard[{i,i}] != ch){
                victory = 0;
                break;
            }
        }
        if(victory)
            return 1;
        victory = 1;
        for(i = 0; i< this->size; i++){
            if(this->gameBoard[{this->size-i-1,i}] != ch){
                victory = 0;
                break;
            }
        }

        return victory;
    }

    //This function executes a whole game of tic-tac-toe, and uses player and winner functions of this class.
    void TicTacToe::play(Player& xPlayer, Player& oPlayer){
        int board_size = this->size*this->size;
        xPlayer.setChar('X');
        oPlayer.setChar('O');
        Coordinate c(0,0);
        this->gameBoard ='.';
        for (int i=1; i<=board_size; i+=2){
            try{
                c.setCoors(xPlayer.play(this->gameBoard));
                if(this->gameBoard[c]=='.')
                    this->gameBoard[c] = xPlayer.getChar();
                else{
                    this->champ = &oPlayer; 
                    return;
                }
            }catch(const string& msg){
                if(this->gameBoard[{0,0}]=='.')
                    this->gameBoard[{0,0}] = xPlayer.getChar();
                this->champ = &oPlayer; 
                return;
            }
            if (gameover('X')){
                this->champ=&xPlayer;
                return;
            }
            try{
                c.setCoors(oPlayer.play(this->gameBoard));
                if(this->gameBoard[c]=='.')
                    this->gameBoard[c] = oPlayer.getChar();
                else{
                    this->champ = &xPlayer; 
                    return;
                }
            }catch(const string& msg){
                if(this->gameBoard[{0,0}]=='.')
                    this->gameBoard[{0,0}] = oPlayer.getChar();
                this->champ = &xPlayer; 
                return;
            }
            if (gameover('O')){
                this->champ=&oPlayer;
                return;
            }
        }
        //if it's a tie, oPlayer wins
        this->champ=&oPlayer;
    }

    //This function returns the board when the game has ended
    Board TicTacToe::board() const{
        return this->gameBoard;
    }

    //This function returns the player that won the game
    Player& TicTacToe::winner() const{
        return *this->champ;
    }
