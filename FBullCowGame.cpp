//
//  FBullCowGame.cpp
//  BullsAndCows
//
//  Created by C Abraham on 10/1/16.
//  Copyright © 2016 C Abraham. All rights reserved.
//

#include "FBullCowGame.hpp"

void FBullCowGame::Reset()
{
    return;
}

int FBullCowGame::GetMaxTries()
{
    return MyMaxTries;
}

int FBullCowGame::GetCurrentTry()
{
    return myCurrentTry;
}

bool FBullCowGame::isGameWon()
{
    return false;
}

bool FBullCowGame::CheckGuessValidity(std::string)
{
    return false;
}


