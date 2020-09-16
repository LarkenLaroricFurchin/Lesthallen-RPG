#ifndef GAMEWORLDMANAGER
#define GAMEWORLDMANAGER
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include "mainFile.h"
#include "Lesthallen RPG.h"
#include "conversionFunctions.h"

namespace fs = std::filesystem;

class GameWorldManager
{
private:
	std::string gameSaveName{"Default Save"};
	std::string gameSaveDirectory{currentPath};
	std::string characterUsed{"Liam Feasey"};
	std::string currentLocation{"Somewhere"};
public:

	void newGame()
	{
		writeLog("New Game Selected", ONE);

		system("CLS");
		std::cout << "Game save name: ";
		std::getline(std::cin, gameSaveName);
		writeLog("Game Save Name Entered", THREE);

		gameSaveDirectory = gameSaveDirectory + "/Lesthallen RPG/Saves/" + gameSaveName;

		system("CLS");
		std::cout << "Use previously created character?(Y/N): ";
		std::string userAnswer{};
		std::getline(std::cin, userAnswer);

		if (userAnswer == "Y" || userAnswer == "y" || userAnswer == "Yes" || userAnswer == "yes")
		{
			std::cout << "Enter the character's name: ";
			std::getline(std::cin, userAnswer);
			playerCharacter.characterName = userAnswer;
			characterUsed = playerCharacter.characterName;
			writeLog("Previous character saved selected", THREE);
			playerCharacter.loadCharacterDetails();
		}
		else if (userAnswer == "N" || userAnswer == "n" || userAnswer == "No" || userAnswer == "no")
		{
			writeLog("New character selected", THREE);
			system("CLS");
			playerCharacter.characterCreation();
			characterUsed = playerCharacter.characterName;
		}

		chooseStartLocation();
		system("CLS");
		createGameSaveDirectory();
		saveGame();
		displayGameStats();
		std::cin.get();
		mainMenu();

		//call the directory creation function for "gameSaveName", and characterUsed
		//Call the file creation function for "gameSaveName"
	}

	void chooseStartLocation()
	{
		writeLog("Choose Start Location started", THREE);
		std::cout << "Choose your start location:\n" << "[1][G.L.E]\n" << "[2][R.L.E]\n" << "[3][B.L.E]\n" << "[MM]:";
		

		int userInput = stringToInteger();

		if (userInput > 3)
		{
			std::cout << "Error, invalid input!";
			writeLog("Error! Invalid input received in chooseStartLocation()", TWO);
			_sleep(1500);
			chooseStartLocation();
		}

		switch (userInput)
		{
		case 1:
			currentLocation = "GLE";
			writeLog("Start location set to GLE", THREE);
			break;
		case 2:
			currentLocation = "RLE";
			writeLog("Start location set to RLE", THREE);
			break;
		case 3:
			currentLocation = "BLE";
			writeLog("Start location set to BLE", THREE);
			break;
		}
	}

	void loadGame()
	{
		system("CLS");
		
		std::cout << "Enter Game Save Name: ";

		std::getline(std::cin, gameSaveName);

		gameSaveDirectory = gameSaveDirectory + "/Lesthallen RPG/Saves/" + gameSaveName;

		std::ifstream gameSaveFile(gameSaveDirectory + "/world.txt");
		writeLog("Game Save File [" + gameSaveDirectory + "] Opened", TWO);

		std::getline(gameSaveFile, characterUsed);
		std::getline(gameSaveFile, currentLocation);
		
		gameSaveFile.close();
		writeLog("Game Save File [" + gameSaveDirectory + "] Closed", TWO);

		playerCharacter.characterName = characterUsed;
	}

	void displayGameStats()
	{
		printLogo(8, currentPath + "/Lesthallen RPG/GameStats.txt", false);
		std::cout << "Game Save Used: " << gameSaveName << "\n" << "Character Used: " << characterUsed << "\n" << "Current Location: " << currentLocation << std::endl;
		writeLog("Game Stats Printed", TWO);
		playerCharacter.loadCharacterDetails();
		playerCharacter.printCharacterDetails();
	}

	void saveGame()
	{
		std::ofstream gameSaveFile(gameSaveDirectory + "/world.txt");

		if (!gameSaveFile.is_open())
		{
			writeLog("Game Save File Failed To Open!", TWO);
		}
		else
		{
			writeLog("Game Save File Opened", TWO);
		}
		

		gameSaveFile << characterUsed << std::endl << currentLocation;

		gameSaveFile.close();
		
		if (!gameSaveFile.is_open())
		{
			writeLog("Game Save File Closed", TWO);
		}
		else
		{
			gameSaveFile.close();
			writeLog("Game Save File Closed", TWO);
		}
	}

	void createGameSaveDirectory()
	{
		writeLog("Game Save Directory creation started", TWO);
		std::string gameSaveDirectory{ saveGamePath + "/" + gameSaveName };
		fs::create_directory(gameSaveDirectory);
		if (fs::is_directory(gameSaveDirectory))
		{
			writeLog("Game Save Directory Created", ONE);
		}
		else
		{
			writeLog("Game Save Directory Failed To Create!", ONE);
		}
	}
};

#endif