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

void mainMenu();

namespace fs = std::filesystem;


void printLogo(int lines, std::string logoDir, bool animated)
{
   
    std::ifstream logoFile(logoDir);
    

    if (logoFile.is_open())
    {
        writeLog("Logo File [" + currentASSetting + "] Opened", TWO);

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
            writeLog("Logo File [" + currentASSetting + "] Closed", 2);
        }
        else
        {
            logoFile.close();
        }
        
    }
    else
    {
        std::cout << "Error!! File failed to open! Returning to Main Menu...\n";
        writeLog("File [" + currentASSetting + "] Failed to open", TWO);
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
        currentASSetting = "Settings1On";
        printLogo(21, "C:/Users/LIAMF/Documents/C++ Projects/Lesthallen/Main Menu/Settings/Settings 1/Settings1On.txt", false);
        settingsMenuAutoSave();
    }
    else if (userInput == "Off" || userInput == "off")
    {
        autoSave = false;
        writeLog("Settings Auto Save Turned Off", 2);
        system("CLS");
        currentASSetting = "Settings1Off";
        printLogo(21, "C:/Users/LIAMF/Documents/C++ Projects/Lesthallen/Main Menu/Settings/Settings 1/Settings1Off.txt", false);
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
        printLogo(21, "C:/Users/LIAMF/Documents/C++ Projects/Lesthallen/Main Menu/Settings/Settings 1/Settings1Error.txt", false);
        _sleep(1500);

        settingsMenuAutoSave();
    }
}

void checkAutoSaveStatus()
{
    
}

void settingsMenuSaveGameHistory()
{

}

void settingsMenuGameLoggingLevel()
{

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
        printLogo(21, logoSettingsAutoSaveDirectory.append(currentASSetting), false); //currentASSetting is in "Lesthallen RPG.h"
        settingsMenuAutoSave();
        break;
    case 2:
        settingsMenuSaveGameHistory();
        break;
    case 3:
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

std::string getSystemPath(_In_ int csidl)
{
    WCHAR szPath[_MAX_PATH]; //wide char sodding array
    SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, szPath); //1st: . 2nd: folder path to be retrieved. 3rd: a folder access token, set to NULL. 4th:specifies that path to be returned. 5th:pszPath receives the path that was asked for.

    //some weird voodoo to covnert from sodding WCHAR to Char, to string.
    char ch[260]; //narrow char array, me likey
    char DefChar = ' '; //no clue what this bit is for
    WideCharToMultiByte(CP_ACP, 0, szPath, -1, ch, 260, &DefChar, NULL); //does the weird converting
    std::string convertedPath{ ch }; //converts the narrow char to a string!!

    return convertedPath;
}


std::string replaceWordInString(std::string stringToEdit, std::string replace, int lengthOfWordToReplace, std::string replaceWith)
{
    while (stringToEdit.find(replace) != std::string::npos)
    {
        stringToEdit.replace(stringToEdit.find(replace), lengthOfWordToReplace, replaceWith);
    }
    return stringToEdit;
}

/*
void createDirectories()
{
    std::string convertedPath = getSystemPath(CSIDL_APPDATA);

    convertedPath = convertDirectory(convertedPath, '\\', '/');

    convertedPath = replaceWordInString(convertedPath, "Roaming", 7, "Local");

    std::string path{ "/Lesthallen RPG/" };
    convertedPath += path; 

    //char gameDirectory[1024];//The final path that can be used to create the rest of the directories
    //strncpy(gameDirectory, convertedPath.c_str(), sizeof(gameDirectory)); //(source, destination, size); copies the "convertedPath" string into the char array "gameDirectory" because _mkdir wants to be a fiend

    if (fs::exists(convertedPath))//create the main directory
    {
        writeLog("Directory [" + convertedPath + "] Already Exists!", ONE);
    }
    else
    {
        fs::create_directory(convertedPath);
        writeLog("Attempting to create [" + convertedPath + "]", ONE);
        if (fs::exists(convertedPath))
        {
            writeLog("Directory [" + convertedPath + "] Created Sucessfully", ONE);
        }
        else
        {
            writeLog("Directory [" + convertedPath + "] Failed to be created. You may not have the correct permissions!", ONE);
        }
    }

    convertedPath += "Saves";

    if (fs::exists(convertedPath))//create the main directory
    {
        writeLog("Directory [" + convertedPath + "] Already Exists!", ONE);
    }
    else
    {
        fs::create_directory(convertedPath);
        writeLog("Attempting to create [" + convertedPath + "]", ONE);
        if (fs::exists(convertedPath))
        {
            writeLog("Directory [" + convertedPath + "] Created Sucessfully", ONE);
        }
        else
        {
            writeLog("Directory [" + convertedPath + "] Failed to be created. You may not have the correct permissions!", ONE);
        }
    }

    /*
    int createDirResult = _mkdir(gameDirectory);//creates the base game directory where the other directories will be places
    if (createDirResult == 0) //if the directory was created then it will return 0, otherwise it returns -1
    {
        writeLog("Directory created successfully", ONE);
    }
    else if (createDirResult == -1)
    {
        writeLog("Directory failed to be created!", ONE);
    }

    char gameSavesDirectory[1024];
    
}
*/
void credits()
{
    printLogo(34, currentPath.append("/Debug/Lesthallen RPG/Main Menu/Credits.txt"), false);
    std::cout << "Press Enter to return to the Main Menu...";
    std::cin.get();
    mainMenu();
}

void mainMenu()
{
    //prints the main menu logo with the choices at the bottom.
    system("CLS");
    currentPath = convertDirectory(currentPath, '\\', '/');
    printLogo(20, logoMainDirectory, true);

    int userInput{ 1 };
    std::string uInput;
    std::getline(std::cin, uInput);
    std::stringstream convertedInput(uInput);
    convertedInput >> userInput;

    switch (userInput)
    {
    case 1:
        writeLog("New Game Selected", THREE);
        system("CLS");
        playerCharacter.characterCreation();
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

int main()
{
    bool characterLoaded{ false };
    writeLog("Program Started", THREE);
    mainMenu();

    //exitGame();
}
