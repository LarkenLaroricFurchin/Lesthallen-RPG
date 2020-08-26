#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
//====================[]====================
#include "itemHandler.h"
#include "characterOperations.h"
#include "LearningC++0.1.h"


enum ItemType
{
	WEAPON,
	ARMOUR,
	SHIELD,
	POTION,
	INGREDIENT,
	SCROLL,
	MAGICITEM,
	FOOD,
};


std::string defaultItemDirectory{ "C:/Users/LIAMF/Documents/C++ Projects/Lesthallen/Items/" };
std::string armour{ "Armour/" };

void loadArmour(Armour& selectedArmourSlot)
{
	int armourID = playerCharacter.characterArmourHead.itemID;
	std::string convertedID = std::to_string(armourID);
	std::string directory = defaultItemDirectory.append(armour).append(convertedID);
	
	std::ifstream armourFile(directory);
	writeLog("Armour File Opened");

	std::string unconvertedArmourMaterial;
	std::getline(armourFile, unconvertedArmourMaterial);
	std::stringstream convertedMaterial(unconvertedArmourMaterial);
	int armourMaterial;
	convertedMaterial >> armourMaterial;

	

	switch(armourMaterial)
	{
	case 1:
		selectedArmourSlot.armourMaterial = Materials::CLOTH;
		break;
	case 5:
		selectedArmourSlot.armourMaterial = Materials::LEATHER;
		break;
	case 10:
		selectedArmourSlot.armourMaterial = Materials::WOOD;
		break;
	case 25:
		selectedArmourSlot.armourMaterial = Materials::SOFTMETAL;
		break;
	case 40:
		selectedArmourSlot.armourMaterial = Materials::HARDMETAL;
		break;
	case 50:
		selectedArmourSlot.armourMaterial = Materials::COMPOSITE;
		break;
	}
	writeLog("Armour Material Loaded");

	std::string unconvertedArmourType;
	std::getline(armourFile, unconvertedArmourType);
	std::stringstream convertedArmourType(unconvertedArmourType);
	int armourType;
	convertedArmourType >> armourType;

	switch (armourType)
	{
	case 1:
		selectedArmourSlot.armourType = ArmourType::PLAIN;
		break;
	case 5:
		selectedArmourSlot.armourType = ArmourType::PADDED;
		break;
	case 10:
		selectedArmourSlot.armourType = ArmourType::STUDDED;
		break;
	case 25:
		selectedArmourSlot.armourType = ArmourType::CHAINMAIL;
		break;
	case 40:
		selectedArmourSlot.armourType = ArmourType::PLATEMAIL;
		break;
	}

	writeLog("Armour Type Loaded");

	std::string unconvertedArmourQuality;
	std::getline(armourFile, unconvertedArmourQuality);
	std::stringstream convertedArmourQuality(unconvertedArmourQuality);
	int armourQuality;
	convertedArmourQuality >> armourQuality;
	selectedArmourSlot.armourQuality = armourQuality;

	writeLog("Armour Quality Loaded");

	std::getline(armourFile, selectedArmourSlot.armourName);

	writeLog("Armour Name Loaded");

	armourFile.close();
	writeLog("Armour File Closed");
}

void loadItem(int iType) //iType is just item type but made different enough to be distinguishable
{
	switch(iType)
	{
	case 0:
		std::cout << "WEAPON";
		break;
	case 1:
		std::cout << "ARMOUR";
		break;
	case 2:
		std::cout << "SHIELD";
		break;
	case 3:
		std::cout << "POTION";
		break;
	case 4:
		std::cout << "INGREDIENT";
		break;
	case 5:
		std::cout << "SCROLL";
		break;
	case 6:
		std::cout << "MAGICITEM";
		break;
	case 7:
		std::cout << "FOOD";
		break;
	}
}