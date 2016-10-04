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
    
    const FString MY_HIDDENWORD = "ant";
    MyHiddenWord = MY_HIDDENWORD;
    
    MyCurrentTry = 1;
    
    return;
}
int32 FBullCowGame::GetMaxTries()const{ return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry()const{ return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength()const{ return (int32)MyHiddenWord.length(); }

bool FBullCowGame::isGameWon()const
{
    return false;
}
EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess)const
{
    if(false)//if game isn't an isogram
    {
        return EGuessStatus::Not_Isogram;
    }else if(false) //if the game isn't all lowercase
    {
        return EGuessStatus::Not_Lowercase;
    }else if(Guess.length() != GetHiddenWordLength())  //if the guess length is wrong
    {
        return EGuessStatus::Wrong_Length;
    }else
    {
        return EGuessStatus::Ok;
    }
    
    
    
}

// recieves valid guess, incriments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
    //incriment the turn number
    MyCurrentTry++;
    
    //setup a return Varible
    FBullCowCount BullCowCount;
    
    // loop threw all the letters in the guess
    int32 HiddenWordLength = (int32)MyHiddenWord.length();
    //compare letters that go with hidden word
    for(int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++)
    {
        //compare letters against hidden word
        for(int32 GChar = 0; GChar < HiddenWordLength; GChar++)
        {
            //if they match then
            if(Guess[GChar] == MyHiddenWord[MHWChar])
            {
                
                if(MHWChar == GChar)    //if they're in the same place
                {
                    
                    BullCowCount.Bulls++; //incriment bulls
                }else
                {
                   
                     BullCowCount.Cows++; //incriment cows
                    
                }
            }
            
        }
    }
    
    return BullCowCount;
}


