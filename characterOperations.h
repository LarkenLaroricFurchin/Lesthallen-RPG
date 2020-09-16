#ifndef CHARACTEROPERATIONS
#define CHARACTEROPERATIONS
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <ctime>  //used to make the stuff in "getTime()" work
#include <chrono> //used to make the stuff in "getTime()" work

#include "logsAndExceptions.h"
#include "itemHandler.h"
#include "mainFile.h"
#include "conversionFunctions.h"

inline std::string defaultCharacterFileDir = currentPath + "/Lesthallen RPG/CharacterFiles/";
inline bool characterLoaded;



class CharacterOperations
{
private:
	int nextLevel{ 20 };
public:
	std::string characterName{ "Name Name" };
	std::string characterRace{ "Race" };
	std::string characterClass{ "Class" };
	short characterAge{ 0 };
	short characterLevel{ 0 };
	int characterExperience{ 0 };

	Armour characterArmourHead{};
	Armour characterArmourTorso{};
	Armour characterArmourLegs{};
	Armour characterArmourFeet{};

	void characterCreation() //gets user input to create a new character
	{
		std::cout << "Enter characters name: ";
		std::getline(std::cin, characterName);
		system("CLS");

		std::cout << "Choose your race:\n" << "[1][Human]\n" << "[2][Lesthallen]\n" << "[MM]:";

		int UserInput = stringToInteger();

		switch (UserInput)
		{
		case 1:
			characterRace = "Human";
			break;
		case 2:
			characterRace = "Lesthallen";
			break;
		}

		system("CLS");


		std::cout << "Choose your class:\n" << "[1][Sorcerer]\n" << "[2][Wizard]\n" << "[3][Druid]\n" << "[4][Bounty Hunter]\n" << "[5][Hunter]\n" << "[6][Cleric]\n" << "[7][Rogue]\n" << "[MM]:";

		UserInput = stringToInteger();

		switch (UserInput)
		{
		case 1:
			characterClass = "Sorcerer";
			break;
		case 2:
			characterClass = "Wizard";
			break;
		case 3:
			characterClass = "Druid";
			break;
		case 4:
			characterClass = "Bounty Hunter";
			break;
		case 5:
			characterClass = "Hunter";
			break;
		case 6:
			characterClass = "Cleric";
			break;
		case 7:
			characterClass = "Rogue";
			break;
		}

		system("CLS");


		std::cout << "Enter characters age: ";
		characterAge = stringToInteger();
		system("CLS");

		characterExperience = 0;

		characterLevel = 0;

		characterArmourHead.itemID = 100;
		loadArmour(characterArmourHead);

		characterArmourTorso.itemID = 101;
		loadArmour(characterArmourTorso);

		characterArmourLegs.itemID = 102;
		loadArmour(characterArmourLegs);

		characterArmourFeet.itemID = 103;
		loadArmour(characterArmourFeet);
		

		characterLoaded = true;

		writeLog("Character Created", THREE);

		saveCharacterDetails();
	}

	void saveCharacterDetails()
	{
		std::string characterDirectory = defaultCharacterFileDir + characterName + ".txt"; //using .append() because just doing "string + string" is a big no no in classes.


		std::ofstream characterFile(characterDirectory);
		if (characterFile.is_open())
		{
			writeLog("Character File Opened", TWO);
		}
		else
		{
			writeLog("Character File Failed To Open!", TWO);
		}
		
		//if you add more lines to the write to file, make sure to end each line with a newline
		characterFile << characterName << "\n" << characterRace << "\n" << characterClass << "\n" << characterAge << "\n" << characterLevel << "\n" << characterExperience << "\n" << characterArmourHead.itemID << "\n";
		characterFile << characterArmourTorso.itemID << "\n" << characterArmourLegs.itemID << "\n" << characterArmourFeet.itemID;

		characterFile.close();

		writeLog("Character Saved", TWO);

		writeLog("Character File Close", TWO);
		
	}
	
	void loadCharacterDetails()
	{
		system("CLS");
		printLogo(8, currentPath + ("/Lesthallen RPG/CharacterFiles/CharacterStats.txt"), false);
		std::string characterDirectory = defaultCharacterFileDir + characterName + ".txt";


		std::ifstream characterFile(characterDirectory);

		characterLoaded = true;

		if (characterFile.is_open() == false)
		{
			std::cout << "File not found. Do you wish to create it?(Y/N): ";
			std::string userAnswer;
			std::getline(std::cin, userAnswer);

			if (userAnswer == "yes" || userAnswer == "Yes" || userAnswer == "y" || userAnswer == "Y")
			{
				characterCreation();
			}
			else
			{
				std::cout << "Exiting\n";
				writeLog("Game Exited", THREE);
				return;
			}
		}
		

		

		std::getline(characterFile, characterName);

		writeLog("Character File Opened", TWO);

		std::getline(characterFile, characterRace);
		std::getline(characterFile, characterClass);

		std::string age;
		std::getline(characterFile, age);
		std::stringstream convertedAge(age);
		convertedAge >> characterAge;

		std::string level;
		std::getline(characterFile, level);
		std::stringstream convertedLevel(level);
		convertedLevel >> characterLevel;

		std::string xp;
		std::getline(characterFile, xp);
		std::stringstream convertedXp(xp);
		convertedXp >> characterExperience;

		std::string headArmourID;
		std::getline(characterFile, headArmourID);
		std::stringstream convertedHeadID(headArmourID);
		convertedHeadID >> characterArmourHead.itemID;

		std::string torsoArmourID;
		std::getline(characterFile, torsoArmourID);
		std::stringstream convertedTorsoID(torsoArmourID);
		convertedTorsoID >> characterArmourTorso.itemID;

		std::string legArmourID;
		std::getline(characterFile, legArmourID);
		std::stringstream convertedLegID(legArmourID);
		convertedLegID >> characterArmourLegs.itemID;

		std::string feetArmourID;
		std::getline(characterFile, feetArmourID);
		std::stringstream convertedFeetID(feetArmourID);
		convertedFeetID >> characterArmourFeet.itemID;
		
		loadArmour(characterArmourHead);
		loadArmour(characterArmourTorso);
		loadArmour(characterArmourLegs);
		loadArmour(characterArmourFeet);

		writeLog("Character Loaded", TWO);

		printCharacterDetails();

		

		characterFile.close();
		writeLog("Character File Closed", TWO);
		std::cin.get();
		mainMenu();
	}

	void printCharacterDetails()
	{
		std::cout << "[Name] "<<characterName << "\n" << "[Race] " << characterRace << "\n" << "[Class] " << characterClass << "\n" << "[Age] " << characterAge << "\n" << "[Level] " << characterLevel << "\n" << "[XP] " << characterExperience << std::endl;;
		std::cout << "[Head] " << characterArmourHead.armourName << "\n" << "[Torso] " << characterArmourTorso.armourName << "\n" << "[Legs] " << characterArmourLegs.armourName << "\n" << "[Feet] " << characterArmourFeet.armourName << std::endl;
		std::cout << "Press enter to continue...";
		writeLog("Character Details Printed", TWO);
	}

	void incrementCharacterXP(short modifier)
	{
		characterExperience += modifier * 1;
		if (characterExperience >= nextLevel)
		{
			incrementCharacterLevel();
		}
		characterExperience += modifier * 1;
		std::string eventToLog{"Character Experience Incremented by: "};
		eventToLog = eventToLog.append(std::to_string(characterExperience += modifier * 1));
		writeLog(eventToLog, TWO);
	}

	void incrementCharacterLevel()
	{
		characterLevel++;
		writeLog("Character Level Incremented", TWO);
	}


};

#endif