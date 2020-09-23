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

	short maxInventorySize{10};//max 40

	Item characterArmourHead{};
	Item characterArmourTorso{};
	Item characterArmourLegs{};
	Item characterArmourFeet{};

	Item primarySlot{};
	Item secondarySlot{};

	Item inventory[40]{ primarySlot, secondarySlot, characterArmourHead, characterArmourTorso, characterArmourLegs, characterArmourFeet };

	void characterCreation() //gets user input to create a new character
	{
		std::cout << "Enter characters name: ";
		std::getline(std::cin, characterName);
		system("CLS");

		std::cout << "Choose your race:\n" << "[1][Human]\n" << "[2][Lesthallen]\n" << "[MM]:";

		int UserInput = stringToIntegerGL();

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

		UserInput = stringToIntegerGL();

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
		characterAge = stringToIntegerGL();
		system("CLS");

		characterExperience = 0;

		characterLevel = 0;

		characterArmourHead.itemID = 1000;

		characterArmourTorso.itemID = 1001;

		characterArmourLegs.itemID = 1002;

		characterArmourFeet.itemID = 1003;

		primarySlot.itemID = 8000;

		secondarySlot.itemID = 7000;
		
		int i{};

		/*
		for (i = 6; i <= 39 - 1; i++)
		{
			inventory[i].itemID = 0;
		}
		*/
		for (i = 0; i <= maxInventorySize - 1; i++)
		{
			loadItem(inventory[i]);
		}

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
		characterFile << characterName << "\n" << characterRace << "\n" << characterClass << "\n" << characterAge << "\n" << characterLevel << "\n" << characterExperience << "\n" << primarySlot.itemID << "\n" << secondarySlot.itemID << "\n";
		characterFile << characterArmourHead.itemID << "\n" << characterArmourTorso.itemID << "\n" << characterArmourLegs.itemID << "\n" << characterArmourFeet.itemID << "\n";

		int i{};//saves the inventory to the character file
		for (i = 6; i <= maxInventorySize - 1; i++)
		{//primary weapon = slot 0, secondary weapon = slot 1, armour pieces = slots 2-5, everything else is slots 6-39
			characterFile << inventory[i].itemID << "\n";
		}

		characterFile.close();

		writeLog("Character Saved", TWO);

		writeLog("Character File Close", TWO);
		
	}
	
	void loadCharacterDetails()
	{
		//printLogo(8, currentPath + ("/Lesthallen RPG/CharacterFiles/CharacterStats.txt"), false);
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
		/*
		std::string primaryWeaponID;
		std::getline(characterFile, primaryWeaponID);
		std::stringstream convertedPrimaryWeaponID(primaryWeaponID);
		convertedPrimaryWeaponID >> primarySlot.itemID;

		std::string secondaryWeaponID;
		std::getline(characterFile, secondaryWeaponID);
		std::stringstream convertedSecondaryWeaponID(secondaryWeaponID);
		convertedSecondaryWeaponID >> secondarySlot.itemID;

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
		*/

		int i{};
		for (i = 0; i <= maxInventorySize - 1; i++)
		{
			int currentItemID;
			std::string currentUnconvertedItemID{};
			std::getline(characterFile, currentUnconvertedItemID);
			currentItemID = stringToInteger(currentUnconvertedItemID);
			inventory[i].itemID = currentItemID;
			loadItem(inventory[i]);
		}

		writeLog("Character Loaded", TWO);

		characterFile.close();
		writeLog("Character File Closed", TWO);
	}

	void printCharacterDetails()
	{
		std::cout << "[Name] "<<characterName << "\n" << "[Race] " << characterRace << "\n" << "[Class] " << characterClass << "\n" << "[Age] " << characterAge << "\n" << "[Level] " << characterLevel << "\n" << "[XP] " << characterExperience << std::endl;;
		std::cout << "[Head] " << characterArmourHead.itemName << "\n" << "[Torso] " << characterArmourTorso.itemName << "\n" << "[Legs] " << characterArmourLegs.itemName << "\n" << "[Feet] " << characterArmourFeet.itemName << "\n";
		std::cout << "[Primary Slot] " << primarySlot.itemName << "\n" << "[Secondary Slot] " << secondarySlot.itemName << std::endl;
		int i{};
		for (i = 6; i <= maxInventorySize - 1; i++)
		{
			std::cout << "[Inventory Slot " << i << "] " << inventory[i].itemName << "\n";
		}
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