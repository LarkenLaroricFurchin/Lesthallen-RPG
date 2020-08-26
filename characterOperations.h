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
//#include "Lesthallen RPG.h"

inline std::string defaultCharacterFileDir = "C:/Users/LIAMF/Documents/C++ Projects/Learning C++/Character Files/";
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

		std::cout << "Enter characters race: ";
		std::getline(std::cin, characterRace);

		std::cout << "Enter characters class: ";
		std::getline(std::cin, characterClass);

		std::cout << "Enter characters age: ";
		std::string age;
		std::getline(std::cin, age);
		std::stringstream convertedAge(age); //stringstream converts integers within a string into actual integers
		convertedAge >> characterAge;		 //you have to access a stringstream the same way you access std::cin

		characterExperience = 0;

		characterLevel = 0;

		characterArmourHead.itemID = 100;
		characterArmourTorso.itemID = 101;
		characterArmourLegs.itemID = 102;
		characterArmourFeet.itemID = 103;

		characterLoaded = true;

		writeLog("Character Created");

		saveCharacterDetails();
	}

	void saveCharacterDetails()
	{
		std::string characterDirectory = defaultCharacterFileDir.append(characterName).append(".txt"); //using .append() because just doing "string + string" is a big no no in classes.


		std::ofstream characterFile(characterDirectory);
		writeLog("Character File Opened");
		
		//if you add more lines to the write to file, make sure to end each line with a newline
		characterFile << characterName << "\n" << characterRace << "\n" << characterClass << "\n" << characterAge << "\n" << characterLevel << "\n" << characterExperience << "\n" << characterArmourHead.itemID << "\n";
		characterFile << characterArmourTorso.itemID << "\n" << characterArmourLegs.itemID << "\n" << characterArmourFeet.itemID;

		characterFile.close();

		writeLog("Character Saved");

		writeLog("Character File Close");
		
	}

	void loadCharacterDetails()
	{
		std::string characterDirectory = defaultCharacterFileDir.append(characterName).append(".txt");


		std::ifstream characterFile(characterDirectory);
		writeLog("Character File Opened");

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
				return;
			}
		}

		std::getline(characterFile, characterName);
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

		writeLog("Character Loaded");

		printCharacterDetails();

		characterLoaded = true;

		characterFile.close();
		writeLog("Character File Closed");
	}

	void printCharacterDetails()
	{
		std::cout << "[Name] "<<characterName << "\n" << "[Race] " << characterRace << "\n" << "[Class] " << characterClass << "\n" << "[Age] " << characterAge << "\n" << "[Level] " << characterLevel << "\n" << "[XP] " << characterExperience << std::endl;;
		std::cout << "[Head] " << characterArmourHead.armourName << "\n" << "[Torso] " << characterArmourTorso.armourName << "\n" << "[Legs] " << characterArmourLegs.armourName << "\n" << "[Feet] " << characterArmourFeet.armourName << std::endl;
		writeLog("Character Details Printed");
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
		writeLog(eventToLog);
	}

	void incrementCharacterLevel()
	{
		characterLevel++;
		writeLog("Character Level Incremented");
	}


};

#endif