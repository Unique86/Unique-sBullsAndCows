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
    FBullCowGame();// consructor
    
    int GetMaxTries() const;
    int GetCurrentTry()const;
    bool isGameWon()const;
    
    void Reset();// TODO get a Rich Return
    bool CheckGuessValidity(std::string);// TODO get a Rich Return
    
    
    
private:
    //see Constructor for intialisation
    int MyCurrentTry;
    int MyMaxTries;
};
