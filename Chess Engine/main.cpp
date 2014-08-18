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
    Rook r = Rook();
    cout<<r.getSymbol() <<r.getX();
    
    return 0;
}

