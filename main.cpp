//
//  main.cpp
//  BullsAndCows
//
//  Created by C Abraham on 9/30/16.
//  Copyright © 2016 C Abraham. All rights reserved.
//

# include <iostream>
# include <string>
# include "FBullCowGame.hpp"
using FText = std::string;
using int32 = int;


// Global Variables
FText Guess = "";// TODO see if i need this varible here...
FBullCowGame BCGame;


// Intro function
void PrintIntro();

// Guess Function
FText GetGuess();

// Print Input
void PrintInput();

// Play the Game
void PlayGame();

// Ask To Play
bool AskToPlayAgain();






int main()
{
    bool bPlayAgain = false;
    do{
        PrintIntro();
        PlayGame();
        PrintInput();
        bPlayAgain =  AskToPlayAgain();
    }while(bPlayAgain);
    
    return 0;
    
    
}

void PrintIntro()
{
    
    // Game Intro
    std::cout << " Welcome to bulls and Cows! a fun game. \n ";
    std::cout << " Can you Guess The " << BCGame.GetHiddenWordLength();
    std::cout << " letter isogram I'm thinking of ";
    std::cout << std::endl;
    
    return;
}

void PlayGame()
{
    FBullCowGame BCGame;// why have a global varible if this is here...
    BCGame.Reset();
    int32 MaxTries = BCGame.GetMaxTries();


    // loop for number of turns asking for guesses
    //TODO change from for to while loop once we are validating tries
    for(int32 i = 0; i<MaxTries; i++)
    {
        GetGuess();//TODO check for Valid guesess
        
        //submit valid guess to the game
        FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
        //print numbeer of bulls and cows
        std::cout << " Bulls = " << BullCowCount.Bulls;
        std::cout << " Cows = " << BullCowCount.Cows << std::endl;
        
        
    }
    //TODO sumirize game
}

// get guess from user
FText GetGuess()
{
    int32 CurentTries = BCGame.GetCurrentTry();
    std::cout << " Try " << CurentTries << " Enter your Guess. ";
    // the guess
    std::getline(std::cin, Guess);// user inputs the guess
    
    return Guess;
}

void PrintInput()
{
    // print guess
    std::cout << "your Guess Was \n " << Guess << std::endl;
    std::cout << std::endl;
    
    return;
    
}

bool AskToPlayAgain()
{
    std::cout << " Do you want to play again? y/n \n ";
    FText Responce = "";
    std::getline(std::cin, Responce);//user answers the question
    std::cout << std::endl;
    
    return (Responce[0] == 'Y') || (Responce[0] == 'y');
    
}


