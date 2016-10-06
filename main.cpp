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
FBullCowGame BCGame;


// Intro function
void PrintIntro();

// Guess Function
FText GetValidGuess();

// Print Input
void PrintInput();

// Play the Game
void PlayGame();
//win the game or lose the game
void PrintGameSummary();

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
    std::cout << "[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]\n";
    std::cout << "*********************BULLS$$$$$$$$$$$$$$$$$$$$$$$\n";
    std::cout << "**                                             $$\n";
    std::cout << "**                     &                       $$\n";
    std::cout << "**                                             $$\n";
    std::cout << "*********************COWS$$$$$$$$$$$$$$$$$$$$$$$$\n";
    std::cout << "**              ENJOY THE GAME!!               $$\n";
    std::cout << "**                                             $$\n";
    std::cout << "{{{{{{{{{{{{{{{{{{{{{{{{{{{{}}}}}}}}}}}}}}}}}}}}}\n";
    std::cout << std::endl;
    
    std::cout << "\n\n Welcome to bulls and Cows! a fun game. \n ";
    std::cout << "Can you Guess The " << BCGame.GetHiddenWordLength();
    std::cout << " letter isogram I'm thinking of ";
    std::cout << std::endl;
    
    return;
}

void PlayGame()
{
    FBullCowGame BCGame;// why have a global varible if this is here...
    BCGame.Reset();
    int32 MaxTries = BCGame.GetMaxTries();
   
    
    // loop ask for guesses for while the game is NOT won
        //and their are strill tries remaining
   while(!BCGame.isGameWon() && BCGame.GetCurrentTry() <= MaxTries)    //TODO change from for to while loop once we are validating tries
    {    FText Guess = GetValidGuess();
        
        //print numbeer of bulls and cows
        FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
        std::cout << " Bulls = " << BullCowCount.Bulls;
        std::cout << " Cows = " << BullCowCount.Cows << "\n" "\n";
        
        
    }
 
    PrintGameSummary();
    return;
}



// loop Continually until user gives valid guess
FText GetValidGuess()
{
    FText Guess = "";
    EGuessStatus Status = EGuessStatus::Invalid_Status;
    do{
        
        int32 CurrentTry = BCGame.GetCurrentTry();
        std::cout << " Try " << CurrentTry << " of " << BCGame.GetMaxTries() << " Enter your Guess. ";
        // the guess
        std::getline(std::cin, Guess);// user inputs the guess
        
        Status = BCGame.CheckGuessValidity(Guess);
        
        switch(Status)
        {
            case EGuessStatus::Wrong_Length:
                std::cout << " Please Enter a " << BCGame.GetHiddenWordLength() << " Letter word. \n\n ";
                break;
            case EGuessStatus::Not_Lowercase:
                std::cout << " Please Enter a Lower case Isogram \n\n ";
                break;
            case EGuessStatus::Not_Isogram:
                std::cout << "Please enter a word without repeating letters. \n\n";
                break;
                
            default:
              
                break;
             
        }
        
    } while(Status != EGuessStatus::Ok);//keep looping until we get no errors
    return Guess;
}

void PrintInput()
{
    FText Guess = "Correct!!";
    // print guess
    std::cout << "your Guess Was \n " << Guess << std::endl;
    std::cout << std::endl;
    
    return;
    
}

bool AskToPlayAgain()
{
    std::cout << " Do you want to play again? with the same word y/n \n ";
    FText Responce = "";
    std::getline(std::cin, Responce);//user answers the question
    std::cout << std::endl;
    
    return (Responce[0] == 'Y') || (Responce[0] == 'y');
    
}

void PrintGameSummary()
{
    if(BCGame.isGameWon())
    {
        std::cout << " YOU WON THE GAME!!!!\n ";
    }else
    {
         std::cout << " Sorry you Lost\n ";
    }
    
    return;
}
