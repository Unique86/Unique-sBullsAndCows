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
//FText Guess = "";// TODO see if i need this varible here...
FBullCowGame BCGame;


// Intro function
void PrintIntro();

// Guess Function
FText GetValidGuess();

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
    FText Guess = "";

    // loop for number of turns asking for guesses
    for(int32 i = 0; i<MaxTries; i++)    //TODO change from for to while loop once we are validating tries
    {    GetValidGuess();
        
             //print numbeer of bulls and cows
        FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
        std::cout << " Bulls = " << BullCowCount.Bulls;
        std::cout << " Cows = " << BullCowCount.Cows << "\n" "\n";
        
        
    }
    //TODO sumirize game
}

// loop Continually until user gives valid guess
FText GetValidGuess()
{
     FText Guess = "";
    EGuessStatus Status = EGuessStatus::Invalid_Status;
do{
   
    int32 CurentTry = BCGame.GetCurrentTry();
    std::cout << " Try " << CurentTry << " Enter your Guess. ";
    // the guess
    std::getline(std::cin, Guess);// user inputs the guess
    
   Status = BCGame.CheckGuessValidity(Guess);
    
    switch(Status)
    {
        case EGuessStatus::Wrong_Length:
            std::cout << " Please Enter a " << BCGame.GetHiddenWordLength() << " Letter word. \n ";
            break;
        case EGuessStatus::Not_Lowercase:
            std::cout << " Please Enter a Lower case Isogram \n ";
            break;
        case EGuessStatus::Not_Isogram:
            std::cout << "This Word is not an Isogram. \n";
            break;
           
        default:
            std::cout << std::endl;
                return Guess;
    }
    
} while(Status != EGuessStatus::Ok);//keep looping until we get no errors
    return Guess;
}

void PrintInput()
{
    FText Guess = "";
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


