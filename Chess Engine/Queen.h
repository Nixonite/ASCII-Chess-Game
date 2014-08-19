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

    Queen():Piece(){
        symbol = "Q";
    }
    
    Queen(int x, int y, bool color, bool active): Piece(x, y, color, active){
        symbol = "Q";
    }
    
    bool isLegal(int mx, int my){
        
        float dx = abs(mx - x);
        float dy = abs(my - y);
        
        if( dx/dy == 1 || ((x != mx) && (y == my)) || ((x == mx) && (y != my))){
            return true;
        }
        else return false;
        
        
    }

};

#endif


