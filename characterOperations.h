#ifndef CHARACTEROPERATIONS
#define CHARACTEROPERATIONS
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <ctime>  //used to make the stuff in "getTime()" work
#include <chrono> //used to make the stuff in "getTime()" work
#include <exception>

#include "logsAndExceptions.h"
#include "itemHandler.h"
#include "mainFile.h"
#include "conversionFunctions.h"

inline std::string defaultCharacterFileDir = currentPath + "/Lesthallen RPG/CharacterFiles/";
inline bool characterLoaded;
namespace fs = std::filesystem;



class CharacterOperations
{
private:
	std::string characterGameSaveDirectory{ currentPath + "/Lesthallen RPG/CharacterFiles/" + characterName };
	int nextLevel{ 20 };
public:
	std::string characterName{ "Name Name" };
	std::string characterRace{ "Race" };
	std::string characterClass{ "Class" };
	short characterAge{ 0 };
	short characterLevel{ 0 };
	int characterExperience{ 0 };

	int characterGold{ 0 };
	int characterSilver{ 0 };
	int characterCopper{ 10 };

	int characterHealth{ 10 };
	int characterMaxHealth{ 10 };

	int characterStamina{ 10 };
	int characterMaxStamina{ 10 };

	int characterMagic{ 10 };
	int characterMaxMagic{ 10 };

	short maxInventorySize{10};//max 40 for now


	Item inventory[40]{ };//slot 0 = Primary slot. Slot 1 = Secondary slot. Slots 2-5 = Armour Slots. Slots 6-39 = inventory slots.

	void characterCreation() //gets user input to create a new character
	{
		std::cout << "Enter characters name: ";
		std::getline(std::cin, characterName);
		std::system("CLS");

		characterGameSaveDirectory = currentPath + "/Lesthallen RPG/CharacterFiles/" + characterName;

		writeLog("Character Save Directory [" + characterGameSaveDirectory + "]", ONE);

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

		std::system("CLS");


		inventory[0].itemID = 8000;//Primary Slot

		inventory[1].itemID = 7000;//Secondary Slot

		inventory[2].itemID = 1000;//Armour Head Slot

		inventory[3].itemID = 1001;//Armour Torso Slot

		inventory[4].itemID = 1002;//Armour Legs Slot

		inventory[5].itemID = 1003;//Armour Feet Slot

		inventory[6].itemID = 2000;//Inventory Slot 1 (inventory slot 6 to the system, inventory slot 1 to the player) Stale Bread is being placed here

		inventory[7].itemID = 0;//Inventory Slot 2 (inventory slot 7 to the system, inventory slot 2 to the player)

		inventory[8].itemID = 0;//Inventory Slot 3 (inventory slot 8 to the system, inventory slot 3 to the player)

		inventory[9].itemID = 0;//Inventory Slot 4 (inventory slot 9 to the system, inventory slot 4 to the player)
		//for now the remaining slots just have food in them, once the starting inventories for specific classes have been sorted only one slot shall be taken.


		std::cout << "Choose your class:\n" << "[1][Sorcerer]\n" << "[2][Wizard]\n" << "[3][Druid]\n" << "[4][Cleric]\n" << "[5][Paladin]\n" << "[6][Bounty Hunter]\n" << "[7][Rogue]\n" << "[8][Barbarian]\n" << "[9][Hunter]\n" << "[MM]:";

		UserInput = stringToIntegerGL();

		switch (UserInput)
		{
		case 1:
			characterClass = "Sorcerer";
			sorcererCreation();
			break;
		case 2:
			characterClass = "Wizard";
			wizardCreation();
			break;
		case 3:
			characterClass = "Druid";
			druidCreation();
			break;
		case 4:
			characterClass = "Cleric";
			clericCreation();
			break;
		case 5:
			characterClass = "Paladin";
			paladinCreation();
			break;
		case 6:
			characterClass = "Bounty Hunter";
			bountyHunterCreation();
			break;
		case 7:
			characterClass = "Rogue";
			rogueCreation();
			break;
		case 8:
			characterClass = "Barbarian";
			barbarianCreation();
			break;
		case 9:
			characterClass = "Hunter";
			hunterCreation();
			break;
		}

		std::system("CLS");


		std::cout << "Enter characters age: ";
		characterAge = stringToIntegerGL();
		std::system("CLS");

		characterExperience = 0;

		characterLevel = 0;

		
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

		characterSaveDirectoryCreation();
		saveCharacterDetails();
	}

	void sorcererCreation()
	{
		inventory[7].itemID = 4000;//Inventory Slot 2 (inventory slot 7 to the system, inventory slot 2 to the player) enchanted paper

		inventory[8].itemID = 4001;//Inventory Slot 3 (inventory slot 8 to the system, inventory slot 3 to the player) paper magic focus
	}

	void wizardCreation()
	{
		inventory[7].itemID = 6000;//Inventory Slot 2 (inventory slot 7 to the system, inventory slot 2 to the player) Magic Punch

		inventory[8].itemID = 5000;//Inventory Slot 3 (inventory slot 8 to the system, inventory slot 3 to the player) Crappy Health Potion
	}

	void druidCreation()
	{
		inventory[7].itemID = 4002;//Inventory Slot 2 (inventory slot 7 to the system, inventory slot 2 to the player)

		inventory[8].itemID = 6001;//Inventory Slot 3 (inventory slot 8 to the system, inventory slot 3 to the player)
	}

	void clericCreation()
	{
		inventory[7].itemID = 4002;//Inventory Slot 2 (inventory slot 7 to the system, inventory slot 2 to the player)

		inventory[8].itemID = 5000;//Inventory Slot 3 (inventory slot 8 to the system, inventory slot 3 to the player)
	}

	void paladinCreation()
	{
		inventory[3].itemID = 1009;//Armour Torso Slot. Leather Padded Jacket

		inventory[7].itemID = 8001;//Inventory Slot 2 (inventory slot 7 to the system, inventory slot 2 to the player) copper dagger

		inventory[8].itemID = 7001;//Inventory Slot 3 (inventory slot 8 to the system, inventory slot 3 to the player)
	}

	void bountyHunterCreation()
	{
		inventory[7].itemID = 8001;//Inventory Slot 2 (inventory slot 7 to the system, inventory slot 2 to the player)

		inventory[8].itemID = 5001;//Inventory Slot 3 (inventory slot 8 to the system, inventory slot 3 to the player) crappy poison potion
	}

	void rogueCreation()
	{
		inventory[7].itemID = 8001;//Inventory Slot 2 (inventory slot 7 to the system, inventory slot 2 to the player)

		inventory[8].itemID = 3000;//Inventory Slot 3 (inventory slot 8 to the system, inventory slot 3 to the player)
	}

	void barbarianCreation()
	{
		inventory[3].itemID = 1005;//Armour Torso Slot. Leather Jacket

		inventory[7].itemID = 8000;//Inventory Slot 2 (inventory slot 7 to the system, inventory slot 2 to the player)

		inventory[8].itemID = 2001;//Inventory Slot 3 (inventory slot 8 to the system, inventory slot 3 to the player)
	}

	void hunterCreation()
	{
		inventory[7].itemID = 8002;//Inventory Slot 2 (inventory slot 7 to the system, inventory slot 2 to the player)

		inventory[8].itemID = 2001;//Inventory Slot 3 (inventory slot 8 to the system, inventory slot 3 to the player)
	}

	void characterSaveDirectoryCreation()
	{
		try
		{
			writeLog("Character Save Directory creation started", TWO);

			fs::create_directory(characterGameSaveDirectory);
			if (fs::is_directory(characterGameSaveDirectory))
			{
				writeLog("Character Save Directory Created", ONE);
			}
			else
			{
				writeLog("Character Save Directory Failed To Create!", ONE);
			}
		}
		catch (std::exception& e)
		{
			std::string curTime = getTime();
			std::string caughtException = e.what();
			writeException("[" + curTime + "] Error! Creating directory failed [" + caughtException);
		}

	}

	void saveCharacterDetails()
	{
		std::string characterDirectory = characterGameSaveDirectory + "/" + characterName + ".txt";

		writeLog("Character Save File [" + characterDirectory + "]", ONE);

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
		characterFile << characterName << "\n" << characterRace << "\n" << characterClass << "\n" << characterAge << "\n" << characterLevel << "\n" << characterExperience << "\n" << characterGold << "\n" << characterSilver << "\n" << characterCopper << "\n";
		characterFile << characterHealth << "\n" << characterStamina << "\n" << characterMagic << "\n" << inventory[0].itemID << "\n" << inventory[1].itemID << "\n";
		characterFile << inventory[2].itemID << "\n" << inventory[3].itemID << "\n" << inventory[4].itemID << "\n" << inventory[5].itemID << "\n";

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
		characterGameSaveDirectory = "/Lesthallen RPG/CharacterFiles/" + characterName;
		std::string characterDirectory = currentPath + characterGameSaveDirectory + "/" + characterName + ".txt";

		writeLog("Character File [" + characterDirectory + "]", ONE);

		std::ifstream characterFile(characterDirectory);
		
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
		
		characterLoaded = true;
		

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

		std::string gold;
		std::getline(characterFile, gold);
		std::stringstream convertedGold(gold);
		convertedGold >> characterGold;

		std::string silver;
		std::getline(characterFile, silver);
		std::stringstream convertedSilver(silver);
		convertedSilver >> characterSilver;

		std::string copper;
		std::getline(characterFile, copper);
		std::stringstream convertedCopper(copper);
		convertedCopper >> characterCopper;

		std::string health;
		std::getline(characterFile, health);
		std::stringstream convertedHealth(health);
		convertedHealth >> characterHealth;

		std::string stamina;
		std::getline(characterFile, stamina);
		std::stringstream convertedStamina(stamina);
		convertedStamina >> characterStamina;

		std::string magic;
		std::getline(characterFile, magic);
		std::stringstream convertedMagic(magic);
		convertedMagic >> characterMagic;


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
		std::cout << "[Gold] " << characterGold << "\n" << "[Silver] " << characterSilver << "\n" << "[Copper] " << characterCopper << "\n" << "[Health] " << characterHealth << "\n" << "[Stamina] " << characterStamina << "\n" << "[Magic] " << characterMagic << "\n";
		std::cout << "[Head] " << inventory[2].itemName << "\n" << "[Torso] " << inventory[3].itemName << "\n" << "[Legs] " << inventory[4].itemName << "\n" << "[Feet] " << inventory[5].itemName << "\n";
		std::cout << "[Primary Slot] " << inventory[0].itemName << "\n" << "[Secondary Slot] " << inventory[1].itemName << std::endl;
		
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
		nextLevel = nextLevel * 2;
		writeLog("Character Level Incremented", TWO);
	}


};

#endif