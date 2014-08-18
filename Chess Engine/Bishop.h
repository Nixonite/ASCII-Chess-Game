//
//  Bishop.h
//  Chess Engine
//
//  Created by Allen Sarkisyan on 8/17/14.
//  Copyright (c) 2014 Allen Sarkisyan. All rights reserved.
//

#ifndef Chess_Engine_Bishop_h
#define Chess_Engine_Bishop_h

#include "Piece.h"
#include <math.h>

class Bishop: public Piece{
public:
    
    const char symbol[2] = "B";
    
    Bishop():Piece(){
        
    }
    
    Bishop(int x, int y, bool color, bool active) : Piece(x, y, color, active){
        
    }
    
    bool isLegal(int mx, int my){
        float dx = abs(mx - x);
        float dy = abs(my - y);
        
        if( dx/dy != 1){
            return false;
        }
        else return true;
        
    }
    
    const char* getSymbol(){
        return symbol;
    }
    
    
};

#endif



