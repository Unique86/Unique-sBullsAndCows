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
using FString = std::string;;
using int32 = int;

#endif /* FBullCowGame_hpp */

enum EGuessStatus
{
    Invalid_Status,
    Ok,
    Not_Isogram,
    Wrong_Length,
    Not_Lowercase
    
};

struct FBullCowCount
{
    int32 Bulls = 0;
    int32 Cows  = 0;
};

class FBullCowGame
{
public:
    FBullCowGame();// consructor
    
    int32 GetMaxTries() const;
    int32 GetCurrentTry()const;
    int32 GetHiddenWordLength()const;
    bool isGameWon()const;
    EGuessStatus CheckGuessValidity(FString)const;// TODO get a Rich Return
    
    void Reset();// TODO get a Rich Return
    FBullCowCount SubmitGuess(FString);
    
    
    
private:
    //see Constructor for intialisation
    int32 MyCurrentTry;
    int32 MyMaxTries;
    FString MyHiddenWord;
};
