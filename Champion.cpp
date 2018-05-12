/**
*cpp file of class Champion
*Authors Alexey Titov and Shir Bentabou
*Version 2.0
**/
//library
#include "Champion.h"

//we need change, set our algorithm
const Coordinate Champion::play(const Board& board){
	for (uint x=0; x<board.size(); ++x){
		uint tmp=board.size()-1-x;
        	Coordinate c{tmp,x};
		tmp=board.size()-1;
	        if(x==1 && board[{0,tmp}] == '.'){
			c.setRow(0);
			c.setCol(board.size()-1);
		}
		if(board[c]=='.') {
			return c;
        	}	
	}
	return {0,0};  // did not find an empty square - play on the top-left
}
