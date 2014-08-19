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
    
    std::vector<Piece> board;
    
public:
    
    Board(){
        
        board.reserve(32);
        
        //white pieces

        board.push_back(Rook(0,0,true,true));
        board.push_back(Knight(1,0,true,true));
        board.push_back(Bishop(2,0,true,true));
        board.push_back(Queen(3,0,true,true));
        board.push_back(King(4,0,true,true));
        board.push_back(Bishop(5,0,true,true));
        board.push_back(Knight(6,0,true,true));
        board.push_back(Rook(7,0,true,true));
        
        for(int i = 0; i < 8; i++){// white pawns
            board.push_back(Pawn(i,1,true,true));
        }
        
        for(int i = 0; i < 8; i++){//black pawns
            board.push_back(Pawn(i,6,false,true));
        }
        
        //black pieces
        board.push_back(Rook(0,7,false,true));
        board.push_back(Knight(1,7,false,true));
        board.push_back(Bishop(2,7,false,true));
        board.push_back(Queen(3,7,false,true));
        board.push_back(King(4,7,false,true));
        board.push_back(Bishop(5,7,false,true));
        board.push_back(Knight(6,7,false,true));
        board.push_back(Rook(7,7,false,true));
        
    }
    
    void test(){
        
        std::cout<<board.at(0).getSymbol();
    }
    
    void print(){
        
        bool found = false;
        
        for(int i=8;i>=0;i--){
            for(int j=0;j<8;j++){
                
                for(int k=0;k<board.size();k++){
                    if(board.at(k).getX()==j && board.at(k).getY()==i){
                        std::cout<<board.at(k).getSymbol() << " ";
                        found = true;
                    }
                }
                if(found == false){
                    std::cout<<"  ";
                }
                found = false;
                
            }
            
            std::cout<<std::endl;
        }
        
        for(int i=0;i<5;i++){
            std::cout<<std::endl;
        }
    }
    
    void getMove(){
        std::string move;
        std::cin>>move;
        std::transform(move.begin(), move.end(), move.begin(), ::tolower);
        std::cout<< move << std::endl;
    }
    
    void movePiece(int mx, int my, int newx, int newy){
        
        for(int i = 0; i<board.size();i++){
            if(board.at(i).getX()==mx && board.at(i).getY()==my){
                board.at(i).move(newx, newy);
            }
        }
    }

    
};

#endif /* defined(__Chess_Engine__Board__) */


