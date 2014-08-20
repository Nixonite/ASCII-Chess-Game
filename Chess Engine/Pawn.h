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

    Pawn():Piece(){
        symbol = "P";
    }
    
    Pawn(int x, int y, bool color, bool active): Piece( x, y, color, active){
        symbol = "P";
    }
    
    bool isLegal(int mx, int my){
        
        int dx = mx - x;
        int dy = my - y;
        
        if(color == true){
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
        else{
            if(dy == -2 && dx == 0){
                if(x == initX && y == initY){
                    return true;
                }
                else return false;
            }
            else if(dy == -1 && dx == 0){
                return true;
            }
            else return false;
        }
        
        
    }

};

#endif