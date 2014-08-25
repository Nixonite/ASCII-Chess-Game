//
//  Rook.h
//  Chess Engine
//
//  Created by Allen Sarkisyan on 8/17/14.
//  Copyright (c) 2014 Allen Sarkisyan. All rights reserved.
//

#ifndef Chess_Engine_Rook_h
#define Chess_Engine_Rook_h

#include <iostream>
#include <vector>
#include "Piece.h"

class Rook: public Piece{
    
public:
    
    Rook(): Piece(){
        symbol = "R";
    }
    
    Rook(int x, int y, bool color, bool active) : Piece(x,y,color,active){
        symbol = "R";
    }
    
    bool isLegal(int mx, int my, std::vector<Piece> * board){// returns true if legal, false if not
        
        if( ((x != mx) && (y == my)) || ((x == mx) && (y != my))){
            
            return true;
        }
        else{
            return false;
        }
    }
    
};

#endif /* defined(__Chess_Engine__File__) */


