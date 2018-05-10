#include <string>
#include "Board.h"

using namespace std;

class TicTacToe{
    private:
        int size;
        Board gameBoard;
        Player champ;
    public:
        //Constructor
        TicTacToe(int s){
            this->size = s;
            this->gameBoard(s);
        }
        
        //This functions checks if the game is over - if a player won or if there was a tie (board is full)
        int gameover(char ch){
            int answer=1; //counts the index we are in
            int victory=0;
            int i=0;
            int j=0;
            char input = ch;

            //search up-down
            for (i=row+1; this->gameBoard[{i,col}].getValue()==input && i<cols; i++,answer++); //passes down and counts
            for (i=row-1; this->gameBoard[{i,col}].getValue()==input && i>=0; i--,answer++); //passes up and counts
            if (answer>=3)
                victory=1;
            else{
                printf("answer is %d \n", answer);
                answer=1;
            }
            //search left-right
            for (i=col+1; this->gameBoard[{row,i}].getValue()==input && i<cols; i=i+1,answer++); 
            for (i=col-1; this->gameBoard[{row,i}].getValue()==input && i>0; i=i-1,answer++);//left
            if (answer>=3)
                victory=1;
            else
                answer=1;
           
            //search upleft-downright
            for (i=row+1, j=col+1;  this->gameBoard[{i,j}].getValue()==input && i<rows && j<cols; i++, j=j+1, answer++);
            for (i=row-1, j=col-1;  this->gameBoard[{i,j}].getValue()==input && i>=0 && j>=0; i--, j=j-1, answer++);
            if (answer>=3)
                victory=1;
            else
                answer=1;
            
            //search downleft-upright
            for (i=row-1, j=col+1;  this->gameBoard[{i,j}].getValue()==input && i>=0 && j<cols; i--, j=j+1, answer++);
            for (i=row+1, j=col-1;  this->gameBoard[{i,j}].getValue()==input && i<rows && j>=0; i++, j=j-1, answer++);
            if (answer>=3)
                victory=1;
            else
                answer=1;
            return victory;
        }

        //This function executes a whole game of tic-tac-toe, and uses player and winner functions of this class.
        void play(Player xPlayer, Player oPlayer){
            //if it's a tie, oPlayer wins
            int board_size = this->size*this->size;
            Coordinate c(0,0);
            for (int i=1; i<=board_size; i++){
                if (i%2==1){
                    c.setCoors(xPlayer.play(this->gameBoard));
                }else{
                    c.setCoors(oPlayer.play(this->gameBoard));
                }
                if (gameover()){
                    if (i%2==1)
                        this->champ=xPlayer;
                    else
                        this->champ=xPlayer;
                    break;
                }
            }
        }

        //This function returns the board when the game has ended
        Board& board(){
            return this->gameBoard;
        }

        //This function returns the player that won the game
        Player& winner(){
            return this->champ;
        }
}