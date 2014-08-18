//
//  Pawn.h
//  Chess Engine
//
//  Created by Allen Sarkisyan on 8/17/14.
//  Copyright (c) 2014 Allen Sarkisyan. All rights reserved.
//

#ifndef Chess_Engine_Pawn_h
#define Chess_Engine_Pawn_h

#include "Piece.h"
#include <math.h>

class Pawn: public Piece{
    
public:
    
    const char symbol[2] = "P";
    
    Pawn():Piece(){
        
    }
    
    Pawn(int x, int y, bool color, bool active): Piece( x, y, color, active){
        
    }
    
    bool isLegal(int mx, int my){
        
        int dx = abs(mx - x);
        int dy = abs(my - y);
        
        if(dy == 2 && dx == 0){
            if(x == initX && y == initY){
                return true;
            }
            else return false;
        }
        else if(dy == 1 && dx == 0){
            return true;
        }
        else return false;
        
    }
    
    const char* getSymbol(){
        return symbol;
    }
    
};

#endif