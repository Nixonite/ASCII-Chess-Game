//
//  Board.h
//  Chess Engine
//
//  Created by Allen Sarkisyan on 8/17/14.
//  Copyright (c) 2014 Allen Sarkisyan. All rights reserved.
//

#ifndef __Chess_Engine__Board__
#define __Chess_Engine__Board__

#include <iostream>
#include "Rook.h"
#include "Queen.h"
#include "Bishop.h"
#include "Pawn.h"
#include "King.h"
#include "Knight.h"

class Board{
    
private:
    
    Piece *board[8][8];
    
public:
    
    Board(){
        
        //white pieces
        board[0][0] = new Rook(0,0,true,true);
        board[1][0] = new Knight(1,0,true,true);
        board[2][0] = new Bishop(2,0,true,true);
        board[3][0] = new Queen(3,0,true,true);
        board[4][0] = new King(4,0,true,true);
        board[5][0] = new Bishop(5,0,true,true);
        board[6][0] = new Knight(6,0,true,true);
        board[7][0] = new Rook(7,0,true,true);
        
        for(int i = 0; i < 7; i++){// white pawns
            board[i][1] = new Pawn(i,1,true,true);
        }
        
        for(int i = 0; i < 7; i++){//black pawns
            board[i][6] = new Pawn(i,6,false,true);
        }
        
        //black pieces
        board[0][7] = new Rook(0,7,false,true);
        board[1][7] = new Knight(1,7,false,true);
        board[2][7] = new Bishop(2,7,false,true);
        board[3][7] = new Queen(3,7,false,true);
        board[4][7] = new King(4,7,false,true);
        board[5][7] = new Bishop(5,7,false,true);
        board[6][7] = new Knight(6,7,false,true);
        board[7][7] = new Rook(7,7,false,true);
        
    }
    
    void print(){
        
        for(int i=0; i<7;i++){
            for(int j=0;j<7;j++){
                if(board[i][j]!=NULL){
                    std::cout<< *board[i][j]->getSymbol();
                }
            }
        }
        
    }
    
};

#endif /* defined(__Chess_Engine__Board__) */


