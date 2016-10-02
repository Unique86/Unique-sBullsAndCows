//
//  FBullCowGame.cpp
//  BullsAndCows
//
//  Created by C Abraham on 10/1/16.
//  Copyright © 2016 C Abraham. All rights reserved.
//

#include "FBullCowGame.hpp"
using int32 = int;

FBullCowGame::FBullCowGame(){Reset();}

 void FBullCowGame::Reset()
{
    constexpr int32 MAX_TRIES = 8;
    MyMaxTries = MAX_TRIES;
    
    const FString MY_HIDDENWORD = "planet";
    MyHiddenWord = MY_HIDDENWORD;
    
    MyCurrentTry = 1;
   
    return;
}
int32 FBullCowGame::GetMaxTries()const{ return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry()const{ return MyCurrentTry; }

bool FBullCowGame::isGameWon()const
{
    return false;
}
bool FBullCowGame::CheckGuessValidity(FString)
{
    return false;
}

// recieves valid guess, incriments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString)
{
    //incriment the turn number
    MyCurrentTry++;
    //setup a return Varible
    FBullCowCount BullCowCount;
    // loop threw all the letters in the guess
        //compare letters against hidden word
    return BullCowCount;
}





