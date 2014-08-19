//
//  Knight.h
//  Chess Engine
//
//  Created by Allen Sarkisyan on 8/17/14.
//  Copyright (c) 2014 Allen Sarkisyan. All rights reserved.
//

#ifndef Chess_Engine_Knight_h
#define Chess_Engine_Knight_h

#include "Piece.h"
#include <math.h>


class Knight: public Piece{
    
public:
    
    Knight():Piece(){
        symbol = "N";
    }
    
    Knight(int x, int y, bool color, bool active):Piece(x,y,color,active){
        symbol = "N";
    }
    
    bool isLegal(int mx, int my){
        
        int dx = abs(mx - x);
        int dy = abs(my - y);
        
        if((dx == 2 && dy == 1) || (dx == 1 && dy == 2)){
            return true;
        }
        else return false;
        
    }
    
};

#endif

