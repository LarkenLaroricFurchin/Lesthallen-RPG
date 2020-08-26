// Lesthallen RPG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//This will be where the games main menu is programmed.

#include <iostream>
#include <string>
#include <fstream>

#include "Lesthallen RPG.h"
#include "characterOperations.h"
#include "logsAndExceptions.h"


void printLogo()
{
    std::string logoDirectory{ "C:/Users/LIAMF/Documents/C++ Projects/Lesthallen/Main Menu/LOGO.txt" };

    std::ifstream logoFile(logoDirectory);
    writeLog("Logo File Opened");

    std::string line{};

    int i;
    for (i = 0; i < 19; i++)
    {
        std::getline(logoFile, line);
        std::cout << line << std::endl;
        _sleep(50);
        
    }
    std::getline(logoFile, line);
    std::cout << line;

    logoFile.close();
    writeLog("Logo File Closed");
}

std::string getUserInput(std::string textToDisplay)
{
    std::cout << textToDisplay;

    std::string userInput;
    std::getline(std::cin, userInput);
    return userInput;
}

int getUserInputInt(std::string textToDisplay) //the same as getUserInput but for if you want to get the input back as an integer
{
    std::cout << textToDisplay;

    int userInput;
    std::string unconvertedInput;
    std::getline(std::cin, unconvertedInput);
    std::stringstream convertedInput(unconvertedInput);
    convertedInput >> userInput;
    return userInput;
}

int main()
{
    bool characterLoaded{ false };
    writeLog("Program Started");
    printLogo();

    int userInput{1};
    std::string uInput;
    std::getline(std::cin, uInput);
    std::stringstream convertedInput(uInput);
    convertedInput >> userInput;

    switch (userInput)
    {
    case 1:
        writeLog("New Game Selected");
        playerCharacter.characterCreation();
        break;
    case 2:
        writeLog("Load Game Selected");

        
        playerCharacter.characterName = getUserInput("Enter characters name: ");
        playerCharacter.loadCharacterDetails();
        break;
    case 5:
        writeLog("Game Exited");
        break;
    }
}
