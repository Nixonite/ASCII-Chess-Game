//
//  Queen.h
//  Chess Engine
//
//  Created by Allen Sarkisyan on 8/17/14.
//  Copyright (c) 2014 Allen Sarkisyan. All rights reserved.
//

#ifndef Chess_Engine_Queen_h
#define Chess_Engine_Queen_h

#include "Piece.h"
#include <math.h>

class Queen: public Piece{
    
public:
    
    const char symbol[2] = "Q";
    
    Queen():Piece(){
        
    }
    
    Queen(int x, int y, bool color, bool active): Piece(x, y, color, active){
        
    }
    
    bool isLegal(int mx, int my){
        
        float dx = abs(mx - x);
        float dy = abs(my - y);
        
        if( dx/dy == 1 || ((x != mx) && (y == my)) || ((x == mx) && (y != my))){
            return true;
        }
        else return false;
        
        
    }
    
    const char* getSymbol(){
        return symbol;
    }
    
};

#endif


