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
    constexpr int32 MAX_TRIES = 3;
    MyMaxTries = MAX_TRIES;
    
    const FString MY_HIDDENWORD = "ant";
    MyHiddenWord = MY_HIDDENWORD;
    bIsGameWon = false;
    MyCurrentTry = 1;
    
    return;
}
int32 FBullCowGame::GetMaxTries()const{ return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry()const{ return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength()const{ return (int32)MyHiddenWord.length(); }
bool FBullCowGame::isGameWon()const{return bIsGameWon;}


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
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
    
    MyCurrentTry++;
    FBullCowCount BullCowCount;
      int32 WordLength = (int32)MyHiddenWord.length();// assuming the same length as guess
    
    // loop threw all the letters in the hidden word
  
    //compare letters that go with the guess
    for(int32 MHWChar = 0; MHWChar < WordLength; MHWChar++)
    {
        //compare letters against hidden word
        for(int32 GChar = 0; GChar < WordLength; GChar++)
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
    
    if(BullCowCount.Bulls == WordLength)
        {
        bIsGameWon = true;
        }
    else
        {
        bIsGameWon = false;
        }
    
    return BullCowCount;
}


