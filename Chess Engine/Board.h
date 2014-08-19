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
#include <vector>

#include "Rook.h"
#include "Queen.h"
#include "Bishop.h"
#include "Pawn.h"
#include "King.h"
#include "Knight.h"

class Board{
    
private:
    
    Piece board[8][8];
    
public:
    
    Board(){
        
        //white pieces
        board[0][0] = Rook(0,0,true,true);
        board[1][0] = Knight(1,0,true,true);
        board[2][0] = Bishop(2,0,true,true);
        board[3][0] = Queen(3,0,true,true);
        board[4][0] = King(4,0,true,true);
        board[5][0] = Bishop(5,0,true,true);
        board[6][0] = Knight(6,0,true,true);
        board[7][0] = Rook(7,0,true,true);
        
        for(int i = 0; i < 8; i++){// white pawns
            board[i][1] = Pawn(i,1,true,true);
        }
        
        for(int i = 0; i < 8; i++){//black pawns
            board[i][6] = Pawn(i,6,false,true);
        }
        
        //black pieces
        board[0][7] = Rook(0,7,false,true);
        board[1][7] = Knight(1,7,false,true);
        board[2][7] = Bishop(2,7,false,true);
        board[3][7] = Queen(3,7,false,true);
        board[4][7] = King(4,7,false,true);
        board[5][7] = Bishop(5,7,false,true);
        board[6][7] = Knight(6,7,false,true);
        board[7][7] = Rook(7,7,false,true);
        
    }
    
    void print(){
        
        for(int i=0;i<50;i++){//nice clearing of space
            std::cout<<std::endl;
        }
        
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                std::cout<< board[j][i].getSymbol() << " ";
            }
            std::cout<< "\n";
        }
        
        for(int i=0;i<5;i++){//lets not have the board on the bottom
            std::cout<<std::endl;
        }
    }
    
    void getMove(){
        std::string move;
        std::cin>>move;
        std::transform(move.begin(), move.end(), move.begin(), ::tolower);
        std::cout<< move << std::endl;
        
    }
    
    

    
};

#endif /* defined(__Chess_Engine__Board__) */


