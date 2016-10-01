//
//  FBullCowGame.hpp
//  BullsAndCows
//
//  Created by C Abraham on 10/1/16.
//  Copyright © 2016 C Abraham. All rights reserved.
//

#ifndef FBullCowGame_hpp
#define FBullCowGame_hpp

#include <stdio.h>
#include <string>

#endif /* FBullCowGame_hpp */

class FBullCowGame
{
public:
    void Reset();// TODO get a Rich Return
    int GetMaxTries();
    int GetCurrentTry();
    bool isGameWon();
    bool CheckGuessValidity(std::string);// TODO get a Rich Return
    
    
    
private:
    int myCurrentTry = 1;
    int MyMaxTries = 5;
};
