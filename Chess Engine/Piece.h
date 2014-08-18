//
//  Piece.h
//  Chess Engine
//
//  Created by Allen Sarkisyan on 8/17/14.
//  Copyright (c) 2014 Allen Sarkisyan. All rights reserved.
//

#ifndef __Chess_Engine__Piece__
#define __Chess_Engine__Piece__

class Piece{
    
protected:
    int x;
    int y;
    int initX;
    int initY;
    bool active;
    bool color;
    
public:
    
    Piece(){
        x = 0;
        y = 0;
        initX = 0;
        initY = 0;
        active = true;
        color = true;
    }
    
    Piece(int mx, int my, bool mcolor, bool mactive){
        x = mx;
        initX = mx;
        y = my;
        initY = my;
        color = mcolor;
        active = mactive;
    }
    
    bool move(int mx, int my){// return true if success, false if error
        if(isLegal(mx,my)){
            x = mx;
            y = my;
            return true;
        }
        else{
            return false;
        }
        
    }
    
    virtual bool isLegal(int mx, int my){
        return true;
    }
    
    int getX(){
        return x;
    }
    
    void setX(int mx){
        x = mx;
    }
    
    int getY(){
        return y;
    }
    
    void setY(int my){
        y = my;
    }
    
    int getInitX(){
        return initX;
    }
    
    int getInitY(){
        return initY;
    }
    
    bool getColor(){
        return color;
    }
    
    bool getActive(){
        return active;
    }
    
    void setActive(bool mactive){
        active = mactive;
    }
    
};

#endif /* defined(__Chess_Engine__Piece__) */

