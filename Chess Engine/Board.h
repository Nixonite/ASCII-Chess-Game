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
    
    void print(){
        
        bool found = false;
        
        for(int i=7;i>=0;i--){
            
            for(int z=0;z<11;z++){
                std::cout<<"---";
            }
            std::cout<<std::endl;
            
            std::cout<<"| ";
            
            for(int j=0;j<8;j++){
                
                for(int k=0;k<board.size();k++){
                    if(board.at(k).getX()==j && board.at(k).getY()==i){
                        std::cout<< board.at(k).getSymbol() << " | ";
                        found = true;
                    }
                }
                if(found == false){
                    std::cout<<"  | ";
                }
                found = false;
                
            }
            
            std::cout<<std::endl;
            
        }
        
        for(int z=0;z<11;z++){
            std::cout<<"---";
        }
        
        for(int i=0;i<5;i++){
            std::cout<<std::endl;
        }
    }
    
    void move(){
        
        int * coords = parseMove(getMove());
        movePiece(coords[0],coords[1],coords[2],coords[3]);
        
    }
    
    std::string getMove(){
        std::cout<<"\nEnter Move: ";
        std::string move;
        std::getline(std::cin,move);
        std::transform(move.begin(), move.begin()+1, move.begin(), ::toupper);
        std::cout<< "\n";
        return move;
    }
    
    void movePiece(int mx, int my, int newx, int newy){
        
        for(int i = 0; i<board.size();i++){
            if(board.at(i).getX()==mx && board.at(i).getY()==my){
                if(board.at(i).positionIsSame(newx, newy)){
                    std::cout<<"Same position\n";
                }
                else{
                    board.at(i).move(newx, newy);
                }
            }
        }
    }
    
    int translateBoardLetter(std::string s){
        if(s == "a"){
            return 0;
        }
        else if(s=="b"){
            return 1;
        }
        else if(s=="c"){
            return 2;
        }
        else if(s=="d"){
            return 3;
        }
        else if(s=="e"){
            return 4;
        }
        else if(s=="f"){
            return 5;
        }
        else if(s=="g"){
            return 6;
        }
        else if(s=="h"){
            return 7;
        }
        else {
            std::cout<< "\nBad translateBoardLetter() error for string:" << s << std::endl;
        }
        return -1;
    }
    
    int translateBoardNumber(std::string n){
        return atoi(n.c_str())-1; //-1 because index starts at 0, but chess board starts at 1
    }
    
    void splitInput(std::string move, std::string *f, std::string *s){// splits a string into two, deliminator being whitespace.
        
        bool splitSuccess = false;
        int splitIndex = 0;
        for(int i=1;i<move.length();i++){
            if(move.substr(i,1)==" "){
                splitIndex = i;
                splitSuccess = true;
                break;
            }
        }
        
        if(splitSuccess == false){
            std::cout<<"\nsplitInput() failed, bad input.\n";
        }
        
        *f = move.substr(0,splitIndex);
        *s = move.substr(splitIndex+1,move.length());
        
    }
    
    int * parseMove(std::string move){
        // move contains two items: the piece at a specific position, and the piece with the desired position.
        //e.g. Pa2 Pa4 would be a valid input. Separate out via whitespace.
        
        std::string first;
        std::string second;
        
        splitInput(move, &first, &second);
        
        if(first.substr(0,1) != second.substr(0,1)){
            std::cout<<"\nError, different pieces in input.\n";
        }
        else{
            
            int firstX = translateBoardLetter(first.substr(1,1));
            int firstY = translateBoardNumber(first.substr(2,1));
            
            int secondX = translateBoardLetter(second.substr(1,1));
            int secondY = translateBoardNumber(second.substr(2,1));
            
            bool found = false;
            
            for(int i=0; i<board.size();i++){
                if((board.at(i).getSymbol() == first.substr(0,1)) && (board.at(i).getX()==firstX && board.at(i).getY()==firstY)){// find moving piece
                    
                    if(board.at(i).isLegal(secondX,secondY)){
                        
                        found = true;
                        
                        int moveParameters[] = {firstX, firstY, secondX, secondY};
                        int *parameters = moveParameters;
                        
                        return parameters;
                    }
                    else{
                        std::cout<<"\nIllegal Move for piece:"<<first<<std::endl;
                    }
                }
            }
            if(found == false){
                std::cout<<"\nCannot parse input, no piece '" << move.substr(0,1) << "' found\n";
            }
        }
        return 0;
    }

    
};

#endif /* defined(__Chess_Engine__Board__) */


