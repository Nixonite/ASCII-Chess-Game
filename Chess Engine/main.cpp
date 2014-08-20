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
    
    while(1){//test
        b.print();
        b.move();
    }
    
    
    return 0;
}