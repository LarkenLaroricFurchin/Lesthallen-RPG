#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
//====================[]====================
#include "Lesthallen RPG.h"
#include "itemHandler.h"
#include "characterOperations.h"


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


std::string defaultItemDirectory{ currentPath + "/Lesthallen RPG/Items" };
std::string armour{ "/Armour/" };
std::string food{ "/Food/" };
std::string Ingredients{ "/Ingredients/" };
std::string magicItems{ "/Magic Items/" };
std::string potions{ "/Potions/" };
std::string scrolls{ "/Scrolls/" };
std::string shields{ "/Shields/" };
std::string weapons{ "/Weapons/" };

void loadArmour(Armour& selectedArmourSlot)
{
	int armourID = selectedArmourSlot.itemID; //these 3 lines just get the armourID from the class and create 1 string that is the directory of the items file
	std::string convertedID = std::to_string(armourID);
	std::string directory = defaultItemDirectory + armour + convertedID + ".txt";
	
	std::ifstream armourFile(directory);
	writeLog("Armour File Opened", TWO);

	std::string unconvertedArmourMaterial; //converts the number thatrs read from the file into an actual integer
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
	writeLog("Armour Material Loaded", ONE);


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

	writeLog("Armour Type Loaded", ONE);


	std::string unconvertedArmourQuality;
	std::getline(armourFile, unconvertedArmourQuality);
	std::stringstream convertedArmourQuality(unconvertedArmourQuality);
	int armourQuality;
	convertedArmourQuality >> armourQuality;
	selectedArmourSlot.armourQuality = armourQuality;

	writeLog("Armour Quality Loaded", ONE);

	std::getline(armourFile, selectedArmourSlot.armourName);

	writeLog("Armour Name Loaded", ONE);

	armourFile.close();
	writeLog("Armour File Closed", TWO);
	//defaultItemDirectory = currentPath + "/Lesthallen RPG/Items";
}

void loadItem(int itemType)
{
	switch(itemType)
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