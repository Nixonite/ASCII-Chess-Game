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
#include "Piece.h"

class Rook: public Piece{
    
public:
    
    const char symbol[2] = "R";
    
    Rook(): Piece(){
        
    }
    
    Rook(int x, int y, bool color, bool active) : Piece(x,y,color,active){
        
    }
    
    bool isLegal(int mx, int my){// returns true if legal, false if not
        if( ((x != mx) && (y == my)) || ((x == mx) && (y != my))){
            return true;
        }
        else{
            return false;
        }
    }
    
    const char* getSymbol(){
        return symbol;
    }
    
};

#endif /* defined(__Chess_Engine__File__) */


