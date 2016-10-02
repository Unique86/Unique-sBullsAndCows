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


// Global Variables
std::string Guess = "";
FBullCowGame BCGame;


// Intro function
void PrintIntro();

// Guess Function
std::string GetGuess();

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
    constexpr int WORD_LENGTH = 9;
    std::cout << " Welcome to bulls and Cows! a fun game. \n ";
    std::cout << " What is the word of isogram i'm thinking of? \n ";
    std::cout << std::endl;
    
    return;
}

void PlayGame()
{
    FBullCowGame BCGame;
    BCGame.Reset();
    //print out reset method
    int MaxTries = BCGame.GetMaxTries();


    // loop for number of turns
    for(int i = 0; i<MaxTries; i++)
    {
        GetGuess();
    }
    //TODO sumirize game
}

// get guess from user
std::string GetGuess()
{
    int CurentTries = BCGame.GetCurrentTry();
    std::cout << " Try " << CurentTries << " Enter your Guess. ";
    // the guess
    std::getline(std::cin, Guess);
    
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
    std::string Responce = "";
    std::getline(std::cin, Responce);
    std::cout << std::endl;
    
    return (Responce[0] == 'Y') || (Responce[0] == 'y');
    
}


