// Lesthallen RPG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//This will be where the games main menu is programmed.

#include <iostream>
#include <string>
#include <fstream>
#include <direct.h>
#include <ShlObj.h>//for system directory crap (the bit that gets %appdata%'s location
#include <algorithm>//for std::replace
#include <filesystem>
#include <thread>

#include "Lesthallen RPG.h"
#include "characterOperations.h"
#include "logsAndExceptions.h"
#include "gameWorldManager.h"
#include "currentGame.h"

void mainMenu();

namespace fs = std::filesystem;


void printLogo(int lines, std::string logoDir, bool animated)
{
   
    std::ifstream logoFile(logoDir);
    

    if (logoFile.is_open())
    {
        writeLog("Logo File [" + logoDir + "] Opened", TWO);

        std::string line{};
        int i;

        if (animated == true) //animates the logo so it appears line by line
        {

            for (i = 0; i < lines; i++)
            {
                std::getline(logoFile, line);
                std::cout << line << "\n";
                //_sleep(50);
                std::this_thread::sleep_for(std::chrono::milliseconds(50));
            }
            std::getline(logoFile, line);
            std::cout << line;
        }
        else if (animated == false)//loads the logo in as quick as it can (usually means instant)
        {
            for (i = 0; i < lines; i++)
            {
                std::getline(logoFile, line);
                std::cout << line << "\n";
            }
            std::getline(logoFile, line);
            std::cout << line;
        }



        logoFile.close();
        if (logoFile.is_open() == false)
        {
            writeLog("Logo File [" + logoDir + "] Closed", 2);
        }
        else
        {
            logoFile.close();
        }
        
    }
    else
    {
        std::cout << "Error!! File failed to open! Returning to Main Menu...\n";
        writeLog("File [" + logoDir + "] Failed to open", TWO);
        _sleep(1500);
        mainMenu();
    }

    
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

void settingsMenu();

void settingsMenuAutoSave()
{
    
    //std::string directory{ logoSettingsAutoSaveDirectory };
    //directory = directory.append("Settings1On.txt");

    std::string userInput{};
    std::getline(std::cin, userInput);

    if (userInput == "On" || userInput == "on")
    {
        autoSave = true;
        writeLog("Settings Auto Save Turned On", 2);
        system("CLS");
        currentASSetting = "/Settings1On";
        printLogo(21, settingsAutoSaveDirectoryOn, false);
        settingsMenuAutoSave();
    }
    else if (userInput == "Off" || userInput == "off")
    {
        autoSave = false;
        writeLog("Settings Auto Save Turned Off", 2);
        system("CLS");
        currentASSetting = "/Settings1Off";
        printLogo(21, settingsAutoSaveDirectoryOff, false);
        settingsMenuAutoSave();
    }
    else if (userInput == "Back" || userInput == "back")
    {
        settingsMenu();
    }
    else
    {
        writeLog("Incorrect Input in Settings Auto Save", 2);
        system("CLS");
        printLogo(21, settingsAutoSaveDirectoryError, false);
        _sleep(1500);

        settingsMenuAutoSave();
    }
}

void checkAutoSaveStatus()
{
    
}

void settingsMenuSaveGameHistory()
{
    std::string userInput{};
    std::getline(std::cin, userInput);

    if (userInput == "On" || userInput == "on")
    {
        saveGameHistory = true;
        writeLog("Settings Save Game History Turned On", 2);
        system("CLS");
        currentSGHSetting = "/Settings2On";
        printLogo(21, settingsSaveGameHistoryDirectoryOn, false);
        settingsMenuSaveGameHistory();
    }
    else if (userInput == "Off" || userInput == "off")
    {
        saveGameHistory = false;
        writeLog("Settings Save Game History Turned Off", 2);
        system("CLS");
        currentSGHSetting = "/Settings2Off";
        printLogo(21, settingsSaveGameHistoryDirectoryOff, false);
        settingsMenuSaveGameHistory();
    }
    else if (userInput == "Back" || userInput == "back")
    {
        settingsMenu();
    }
    else
    {
        writeLog("Incorrect Input in Settings Save Game History", 2);
        system("CLS");
        printLogo(21, settingsSaveGameHistoryDirectoryError, false);
        _sleep(1500);

        settingsMenuSaveGameHistory();
    }
}

void settingsMenuGameLoggingLevel()
{
    std::string userInput{};
    std::getline(std::cin, userInput);

    if (userInput == "Low" || userInput == "low")
    {
        systemLogLevel = 3;
        writeLog("Settings Game Logging Level Set To Low", 2);
        system("CLS");
        currentSGHSetting = "/Settings3Low";
        printLogo(23, settingsGameLoggingLevelDirectoryLow, false);
        settingsMenuGameLoggingLevel();
    }
    else if (userInput == "Medium" || userInput == "medium")
    {
        systemLogLevel = 2;
        writeLog("Settings Game Logging Level Set To Medium", 2);
        system("CLS");
        currentSGHSetting = "/Settings3Medium";
        printLogo(23, settingsGameLoggingLevelDirectoryMedium, false);
        settingsMenuGameLoggingLevel();
    }
    else if (userInput == "High" || userInput == "high")
    {
        systemLogLevel = 1;
        writeLog("Settings Game Logging Level Set To High", 2);
        system("CLS");
        currentSGHSetting = "/Settings3High";
        printLogo(23, settingsGameLoggingLevelDirectoryHigh, false);
        settingsMenuGameLoggingLevel();
    }
    else if (userInput == "Off" || userInput == "off")
    {
        systemLogLevel = 4;
        writeLog("Settings Game Logging Level Set To Off", 2);
        system("CLS");
        currentSGHSetting = "/Settings3Off";
        printLogo(23, settingsSaveGameHistoryDirectoryOff, false);
        settingsMenuGameLoggingLevel();
    }
    else if (userInput == "Back" || userInput == "back")
    {
        settingsMenu();
    }
    else
    {
        writeLog("Incorrect Input in Settings Game Logging Level", 2);
        system("CLS");
        printLogo(23, settingsGameLoggingLevelDirectoryError, false);
        _sleep(1500);

        settingsMenuGameLoggingLevel();
    }
}



void settingsMenu()
{
    system("CLS");

    printLogo(21, logoSettingsDirectory, true);

    int userInput{};
    std::string unconvertedUserInput{};
    std::getline(std::cin, unconvertedUserInput);
    std::stringstream convertedUserInput(unconvertedUserInput);
    convertedUserInput >> userInput;

    switch (userInput)
    {
    case 1:
        writeLog("Settings Auto Save Selected", TWO);
        system("CLS");
        std::cin.get();
        printLogo(21, settingsAutoSaveDirectory.append(currentASSetting), false); //currentASSetting is in "Lesthallen RPG.h"
        settingsMenuAutoSave();
        break;
    case 2:
        writeLog("Settings Save Game History Selected", TWO);
        system("CLS");
        printLogo(21, settingsSaveGameHistoryDirectory.append(currentSGHSetting), false);
        settingsMenuSaveGameHistory();
        break;
    case 3:
        writeLog("Settings Game Logging Level Selected", TWO);
        system("CLS");
        printLogo(23, settingsGameLoggingLevelDirectory.append(currentGLLSetting), false);
        settingsMenuGameLoggingLevel();
        break;
    case 4://if they choose Back
        mainMenu();
    }
}

std::string convertDirectory(std::string pathToConvert, char replace, char replaceWith)
{
    std::replace(pathToConvert.begin(), pathToConvert.end(), replace, replaceWith);//(where to start, where to end, what to replace, what to replace it with);

    return pathToConvert;
}


std::string replaceWordInString(std::string stringToEdit, std::string replace, int lengthOfWordToReplace, std::string replaceWith)
{
    while (stringToEdit.find(replace) != std::string::npos)
    {
        stringToEdit.replace(stringToEdit.find(replace), lengthOfWordToReplace, replaceWith);
    }
    return stringToEdit;
}


void credits()
{
    printLogo(35, creditsFile, false);
    std::cout << "Press Enter to return to the Main Menu...";
    std::cin.get();
    mainMenu();
}

void setDirectories()
{
    //set the games directories to the current location of the .exe
    //SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
    currentPath = convertDirectory(currentPath, '\\', '/');
    saveGamePath = currentPath + "/Lesthallen RPG/Saves";
    logoMainDirectory = currentPath + "/Lesthallen RPG/Main Menu/LOGO.txt";

    //settings
    settingsDirectory = currentPath + "/Lesthallen RPG/Main Menu/Settings";
    logoSettingsDirectory = settingsDirectory + "/SettingsMenu.txt";

    //Setting auto save
    settingsAutoSaveDirectory = settingsDirectory + "/Settings 1";
    settingsAutoSaveDirectoryError = settingsAutoSaveDirectory + "/Settings1Error.txt";
    settingsAutoSaveDirectoryOff = settingsAutoSaveDirectory + "/Settings1Off.txt";
    settingsAutoSaveDirectoryOn = settingsAutoSaveDirectory + "/Settings1On.txt";

    //Settings Save Game History
    settingsSaveGameHistoryDirectory = settingsDirectory + "/Settings 2";
    settingsSaveGameHistoryDirectoryError = settingsSaveGameHistoryDirectory + "/Settings2Error.txt";
    settingsSaveGameHistoryDirectoryOff = settingsSaveGameHistoryDirectory + "/Settings2Off.txt";
    settingsSaveGameHistoryDirectoryOn = settingsSaveGameHistoryDirectory + "/Settings2On.txt";

    //Settings Game Logging Level
    settingsGameLoggingLevelDirectory = settingsDirectory + "/Settings 3";
    settingsGameLoggingLevelDirectoryError = settingsGameLoggingLevelDirectory + "/Settings3Error.txt";
    settingsGameLoggingLevelDirectoryHigh = settingsGameLoggingLevelDirectory + "/Settings3High.txt";
    settingsGameLoggingLevelDirectoryMedium = settingsGameLoggingLevelDirectory + "/Settings3Medium.txt";
    settingsGameLoggingLevelDirectoryLow = settingsGameLoggingLevelDirectory + "/Settings3Low.txt";
    settingsGameLoggingLevelDirectoryOff = settingsGameLoggingLevelDirectory + "/Settings3Off.txt";


    creditsFile = currentPath + "/Lesthallen RPG/Main Menu/Credits.txt";
    gameStartUp = false;
}

void firstLoop() //checking to see if the game has just been started up; if it is then the game will run some neccessary functions to make sure everything is correct (directories etc...)
{
    if (gameStartUp == true)
    {
        setDirectories();
    }
}

void mainMenu()
{
    firstLoop();//Checks if this is the first time mainMenu has been called during the current life of the program

    //prints the main menu logo with the choices at the bottom.
    system("CLS");
    printLogo(20, logoMainDirectory, true);

    int userInput = stringToInteger();

    switch (userInput)
    {
    case 1:
        writeLog("New Game Selected", THREE);
        system("CLS");
        currentGame.newGame();
        break;
    case 2:
        writeLog("Load Game Selected", THREE);
        system("CLS");

        playerCharacter.characterName = getUserInput("Enter characters name: ");
        playerCharacter.loadCharacterDetails();
        
        std::cin.get();
        break;
    case 3:
        writeLog("Settings Selected", THREE);
        settingsMenu();
    case 4:
        credits();
    case 5:
        writeLog("Game Exited", THREE);
        exit(0);
        
    }
}

void newGame()
{

}

void loadGame()
{

}

int main()
{
    bool characterLoaded{ false };
    writeLog("Program Started", THREE);
    mainMenu();

    //exitGame();
}
