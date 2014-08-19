//
//  main.cpp
//  Chess Engine
//
//  Created by Allen Sarkisyan on 8/16/14.
//  Copyright (c) 2014 Allen Sarkisyan. All rights reserved.
//

#include <iostream>
#include "Board.h"

using namespace std;

int main(int argc, const char * argv[])
{
    
    Board b = Board();
    b.print();
    b.movePiece(4,1,4,3);
    b.print();
    b.movePiece(4,6,4,4);
    b.print();
    b.movePiece(6,0,5,2);
    b.print();
    
    
    return 0;
}