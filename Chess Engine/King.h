//
//  King.h
//  Chess Engine
//
//  Created by Allen Sarkisyan on 8/17/14.
//  Copyright (c) 2014 Allen Sarkisyan. All rights reserved.
//

#ifndef Chess_Engine_King_h
#define Chess_Engine_King_h

#include "Piece.h"
#include <math.h>

class King: public Piece{
    
public:
    
    const char symbol[2] = "K";
    
    King():Piece(){
        
    }
    
    King(int x, int y, bool color, bool active) : Piece(x,y,color,active){
        
    }
    
    bool isLegal(int mx, int my){
        
        int dx = abs(mx-x);
        int dy = abs(my-y);
        
        if(dx <= 1 && dy <= 1){
            return true;
        }
        else return false;
    }
    
    const char* getSymbol(){
        return symbol;
    }
    
};

#endif



