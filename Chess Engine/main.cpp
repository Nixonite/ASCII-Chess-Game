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
    
    cout<<"Instructions:\n";
    cout<<"The program takes two words as input: The initial piece symbol and position, and the final piece symbol and position.\n";
    cout<<"Example:Pa2 Pa4\n";
    cout<<"That statement moves the pawn on a2 to a4.\n";
    cout<<"The program only recognizes input with two words and one space in between.\n";
    cout<<"This program is incomplete, this is just a test.\n";
    cout<<"Have fun!"<<endl;
    
    while(1){//test
        b.print();
        b.move();
    }
    
    
    return 0;
}