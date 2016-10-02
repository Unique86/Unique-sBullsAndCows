//
//  FBullCowGame.cpp
//  BullsAndCows
//
//  Created by C Abraham on 10/1/16.
//  Copyright © 2016 C Abraham. All rights reserved.
//

#include "FBullCowGame.hpp"

FBullCowGame::FBullCowGame(){Reset();}

 void FBullCowGame::Reset()
{
    constexpr int MAX_TRIES = 8;
    MyMaxTries = MAX_TRIES;
    
    MyCurrentTry = 1;
   
    return;
}
int FBullCowGame::GetMaxTries()const{ return MyMaxTries; }
int FBullCowGame::GetCurrentTry()const{ return MyCurrentTry; }

bool FBullCowGame::isGameWon()const
{
    return false;
}
bool FBullCowGame::CheckGuessValidity(std::string)
{
    return false;
}





