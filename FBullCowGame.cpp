//
//  FBullCowGame.cpp
//  BullsAndCows
//
//  Created by C Abraham on 10/1/16.
//  Copyright © 2016 C Abraham. All rights reserved.
//
#pragma once
#include "FBullCowGame.hpp"
#include <map>
#define TMap std::map
using int32 = int;


FBullCowGame::FBullCowGame(){Reset();}//Constructor
int32 FBullCowGame::GetCurrentTry()const{ return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength()const{ return (int32)MyHiddenWord.length(); }
bool FBullCowGame::isGameWon()const{return bIsGameWon;}

int32 FBullCowGame::GetMaxTries()const
{
    TMap<int32, int32> WordLengthToMaxTries{{3,4}, {4,7}, {5,10}, {6,15}};
    return WordLengthToMaxTries[(int32)MyHiddenWord.length()];
}







void FBullCowGame::Reset()
{
    const FString MY_HIDDENWORD = "dragon";
    MyHiddenWord = MY_HIDDENWORD;
    bIsGameWon = false;
    MyCurrentTry = 1;
    
    return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess)const
{
    if(!IsIsogram(Guess))//if game isn't an isogram
    {
        return EGuessStatus::Not_Isogram;
    }else if(!IsLowerCase(Guess))
    {
        return EGuessStatus::Not_Lowercase;
    }else if(Guess.length() != GetHiddenWordLength())
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
    
    MyCurrentTry++;//bug 1 come back to this in the future
    FBullCowCount BullCowCount;
      int32 Length = (int32)MyHiddenWord.length();
    
    // loop threw all the letters in the hidden word
  
    //compare letters that go with the guess
    for(int32 MHWChar = 0; MHWChar < Length; MHWChar++)
    {
        //compare letters against hidden word
        for(int32 GChar = 0; GChar < Length; GChar++)
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
    
    if(BullCowCount.Bulls == Length)//bug 2 come back to this in the future
        {
            
        bIsGameWon = true;
            
        }
  
    
    return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word)const
{
    // treat 0 and 1 letter words as isograms
    if(Word.length() <= 1){ return true;}
    TMap <char, bool> LetterSeen; //set up map
    for(auto Letter : Word)//for all letters in the word
    {
        Letter = tolower(Letter);//handle mix case
       if(LetterSeen[Letter])
       { //if the letter is on the map
           return false;
       }else
       {
           LetterSeen[Letter] = true;//add the letter to the map as seen

       }
      
        
    }
    return true;
}

bool FBullCowGame::IsLowerCase(FString Word)const
{
    for(auto Letter : Word )
    {
      if(!islower(Letter))//if not lowercase
          return false;
        
    }
    
    return true;
}


