#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
//====================[]====================
#include "Lesthallen RPG.h"
#include "itemHandler.h"
#include "characterOperations.h"



std::string defaultItemDirectory{ currentPath + "/Lesthallen RPG/Items" };
std::string consumable{"/Consumables/"};
std::string armour{ "/Armour/" };
std::string food{ "/Food/" };
std::string ingredients{ "/Ingredients/" };
std::string magicItems{ "/Magic Items/" };
std::string potions{ "/Potions/" };
std::string scrolls{ "/Scrolls/" };
std::string shields{ "/Shields/" };
std::string weapons{ "/Weapons/" };
std::string error{ "/error/" };

std::string checkItemID(int itemID)
{
	std::string stringItemID = std::to_string(itemID);
	char itemTypeID = stringItemID[0];

	switch (itemTypeID)
	{
	case '0':
		return armour;
	case '1':
		return food;
	case '2':
		return ingredients;
	case '3':
		return magicItems;
	case '4':
		return potions;
	case '5':
		return scrolls;
	case '6':
		return shields;
	case '7':
		return weapons;
	}
	return error;
}

void loadArmour(Item& selectedItemSlot)
{
	int armourID = selectedItemSlot.itemID; //these 3 lines just get the armourID from the class and create 1 string that is the directory of the items file
	std::string convertedID = std::to_string(armourID);
	std::string directory = defaultItemDirectory + armour + convertedID + ".txt";
	
	std::ifstream armourFile(directory);
	writeLog("Armour File [" + directory + "] Opened", TWO);

	std::string unconvertedArmourMaterial; //converts the number that's read from the file into an actual integer
	std::getline(armourFile, unconvertedArmourMaterial);
	std::stringstream convertedMaterial(unconvertedArmourMaterial);
	int armourMaterial;
	convertedMaterial >> armourMaterial;

	switch(armourMaterial)
	{
	case 1:
		selectedItemSlot.itemMaterial = Materials::CLOTH;
		break;
	case 5:
		selectedItemSlot.itemMaterial = Materials::LEATHER;
		break;
	case 10:
		selectedItemSlot.itemMaterial = Materials::WOOD;
		break;
	case 25:
		selectedItemSlot.itemMaterial = Materials::SOFTMETAL;
		break;
	case 40:
		selectedItemSlot.itemMaterial = Materials::HARDMETAL;
		break;
	case 50:
		selectedItemSlot.itemMaterial = Materials::COMPOSITE;
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
		selectedItemSlot.itemType = ItemType::PLAIN;
		break;
	case 5:
		selectedItemSlot.itemType = ItemType::PADDED;
		break;
	case 10:
		selectedItemSlot.itemType = ItemType::STUDDED;
		break;
	case 25:
		selectedItemSlot.itemType = ItemType::CHAINMAIL;
		break;
	case 40:
		selectedItemSlot.itemType = ItemType::PLATEMAIL;
		break;
	}

	writeLog("Armour Type Loaded", ONE);


	std::string unconvertedArmourQuality;
	std::getline(armourFile, unconvertedArmourQuality);
	std::stringstream convertedArmourQuality(unconvertedArmourQuality);
	int armourQuality;
	convertedArmourQuality >> armourQuality;
	selectedItemSlot.itemQuality = armourQuality;

	writeLog("Armour Quality Loaded", ONE);

	std::getline(armourFile, selectedItemSlot.itemName);

	writeLog("Armour Name Loaded", ONE);

	armourFile.close();
	writeLog("Armour File [" + directory + "] Closed", TWO);
}


void loadFood(Item& selectedItemSlot)
{
	int foodID = selectedItemSlot.itemID; //these 3 lines just get the armourID from the class and create 1 string that is the directory of the items file
	std::string convertedID = std::to_string(foodID);
	std::string directory = defaultItemDirectory + food + convertedID + ".txt";

	std::ifstream foodFile(directory);
	writeLog("Armour File [" + directory + "] Opened", TWO);

	std::string unconvertedFoodMaterial; //converts the number that's read from the file into an actual integer
	std::getline(foodFile, unconvertedFoodMaterial);
	/*
	std::stringstream convertedMaterial(unconvertedFoodMaterial);
	int foodMaterial;
	convertedMaterial >> foodMaterial;
	*/

	selectedItemSlot.itemMaterial = Materials::FOOD;

	writeLog("Food Material Loaded [itemID:" + convertedID + "]", ONE);

	/*
	std::string unconvertedFoodType;
	std::getline(foodFile, unconvertedFoodType);
	std::stringstream convertedFoodType(unconvertedFoodType);
	int foodType;
	convertedFoodType >> foodType;
	*/

	selectedItemSlot.itemType = ItemType::FOOD;

	writeLog("Food Type Loaded [itemID:" + convertedID + "]", ONE);


	std::string unconvertedFoodQuality;
	std::getline(foodFile, unconvertedFoodQuality);
	std::stringstream convertedFoodQuality(unconvertedFoodQuality);
	int foodQuality;
	convertedFoodQuality >> foodQuality;
	selectedItemSlot.itemQuality = foodQuality;

	writeLog("Food Quality Loaded [itemID:" + convertedID + "]", ONE);

	std::getline(foodFile, selectedItemSlot.itemName);

	writeLog("Food Name Loaded [itemID:" + convertedID + "]", ONE);

	foodFile.close();
	writeLog("Food File [" + directory + "] Closed", TWO);
}


void loadIngredient(Item& selectedItemSlot)
{
	int armourID = selectedItemSlot.itemID; //these 3 lines just get the armourID from the class and create 1 string that is the directory of the items file
	std::string convertedID = std::to_string(armourID);
	std::string directory = defaultItemDirectory + armour + convertedID + ".txt";

	std::ifstream armourFile(directory);
	writeLog("Armour File [" + directory + "] Opened", TWO);

	std::string unconvertedArmourMaterial; //converts the number that's read from the file into an actual integer
	std::getline(armourFile, unconvertedArmourMaterial);
	std::stringstream convertedMaterial(unconvertedArmourMaterial);
	int armourMaterial;
	convertedMaterial >> armourMaterial;

	switch (armourMaterial)
	{
	case 1:
		selectedItemSlot.itemMaterial = Materials::CLOTH;
		break;
	case 5:
		selectedItemSlot.itemMaterial = Materials::LEATHER;
		break;
	case 10:
		selectedItemSlot.itemMaterial = Materials::WOOD;
		break;
	case 25:
		selectedItemSlot.itemMaterial = Materials::SOFTMETAL;
		break;
	case 40:
		selectedItemSlot.itemMaterial = Materials::HARDMETAL;
		break;
	case 50:
		selectedItemSlot.itemMaterial = Materials::COMPOSITE;
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
		selectedItemSlot.itemType = ItemType::PLAIN;
		break;
	case 5:
		selectedItemSlot.itemType = ItemType::PADDED;
		break;
	case 10:
		selectedItemSlot.itemType = ItemType::STUDDED;
		break;
	case 25:
		selectedItemSlot.itemType = ItemType::CHAINMAIL;
		break;
	case 40:
		selectedItemSlot.itemType = ItemType::PLATEMAIL;
		break;
	}

	writeLog("Armour Type Loaded", ONE);


	std::string unconvertedArmourQuality;
	std::getline(armourFile, unconvertedArmourQuality);
	std::stringstream convertedArmourQuality(unconvertedArmourQuality);
	int armourQuality;
	convertedArmourQuality >> armourQuality;
	selectedItemSlot.itemQuality = armourQuality;

	writeLog("Armour Quality Loaded", ONE);

	std::getline(armourFile, selectedItemSlot.itemName);

	writeLog("Armour Name Loaded", ONE);

	armourFile.close();
	writeLog("Armour File [" + directory + "] Closed", TWO);
}


void loadMagicItem(Item& selectedItemSlot)
{
	int armourID = selectedItemSlot.itemID; //these 3 lines just get the armourID from the class and create 1 string that is the directory of the items file
	std::string convertedID = std::to_string(armourID);
	std::string directory = defaultItemDirectory + armour + convertedID + ".txt";

	std::ifstream armourFile(directory);
	writeLog("Armour File [" + directory + "] Opened", TWO);

	std::string unconvertedArmourMaterial; //converts the number that's read from the file into an actual integer
	std::getline(armourFile, unconvertedArmourMaterial);
	std::stringstream convertedMaterial(unconvertedArmourMaterial);
	int armourMaterial;
	convertedMaterial >> armourMaterial;

	switch (armourMaterial)
	{
	case 1:
		selectedItemSlot.itemMaterial = Materials::CLOTH;
		break;
	case 5:
		selectedItemSlot.itemMaterial = Materials::LEATHER;
		break;
	case 10:
		selectedItemSlot.itemMaterial = Materials::WOOD;
		break;
	case 25:
		selectedItemSlot.itemMaterial = Materials::SOFTMETAL;
		break;
	case 40:
		selectedItemSlot.itemMaterial = Materials::HARDMETAL;
		break;
	case 50:
		selectedItemSlot.itemMaterial = Materials::COMPOSITE;
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
		selectedItemSlot.itemType = ItemType::PLAIN;
		break;
	case 5:
		selectedItemSlot.itemType = ItemType::PADDED;
		break;
	case 10:
		selectedItemSlot.itemType = ItemType::STUDDED;
		break;
	case 25:
		selectedItemSlot.itemType = ItemType::CHAINMAIL;
		break;
	case 40:
		selectedItemSlot.itemType = ItemType::PLATEMAIL;
		break;
	}

	writeLog("Armour Type Loaded", ONE);


	std::string unconvertedArmourQuality;
	std::getline(armourFile, unconvertedArmourQuality);
	std::stringstream convertedArmourQuality(unconvertedArmourQuality);
	int armourQuality;
	convertedArmourQuality >> armourQuality;
	selectedItemSlot.itemQuality = armourQuality;

	writeLog("Armour Quality Loaded", ONE);

	std::getline(armourFile, selectedItemSlot.itemName);

	writeLog("Armour Name Loaded", ONE);

	armourFile.close();
	writeLog("Armour File [" + directory + "] Closed", TWO);
}


void loadPotion(Item& selectedItemSlot)
{
	int armourID = selectedItemSlot.itemID; //these 3 lines just get the armourID from the class and create 1 string that is the directory of the items file
	std::string convertedID = std::to_string(armourID);
	std::string directory = defaultItemDirectory + armour + convertedID + ".txt";

	std::ifstream armourFile(directory);
	writeLog("Armour File [" + directory + "] Opened", TWO);

	std::string unconvertedArmourMaterial; //converts the number that's read from the file into an actual integer
	std::getline(armourFile, unconvertedArmourMaterial);
	std::stringstream convertedMaterial(unconvertedArmourMaterial);
	int armourMaterial;
	convertedMaterial >> armourMaterial;

	switch (armourMaterial)
	{
	case 1:
		selectedItemSlot.itemMaterial = Materials::CLOTH;
		break;
	case 5:
		selectedItemSlot.itemMaterial = Materials::LEATHER;
		break;
	case 10:
		selectedItemSlot.itemMaterial = Materials::WOOD;
		break;
	case 25:
		selectedItemSlot.itemMaterial = Materials::SOFTMETAL;
		break;
	case 40:
		selectedItemSlot.itemMaterial = Materials::HARDMETAL;
		break;
	case 50:
		selectedItemSlot.itemMaterial = Materials::COMPOSITE;
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
		selectedItemSlot.itemType = ItemType::PLAIN;
		break;
	case 5:
		selectedItemSlot.itemType = ItemType::PADDED;
		break;
	case 10:
		selectedItemSlot.itemType = ItemType::STUDDED;
		break;
	case 25:
		selectedItemSlot.itemType = ItemType::CHAINMAIL;
		break;
	case 40:
		selectedItemSlot.itemType = ItemType::PLATEMAIL;
		break;
	}

	writeLog("Armour Type Loaded", ONE);


	std::string unconvertedArmourQuality;
	std::getline(armourFile, unconvertedArmourQuality);
	std::stringstream convertedArmourQuality(unconvertedArmourQuality);
	int armourQuality;
	convertedArmourQuality >> armourQuality;
	selectedItemSlot.itemQuality = armourQuality;

	writeLog("Armour Quality Loaded", ONE);

	std::getline(armourFile, selectedItemSlot.itemName);

	writeLog("Armour Name Loaded", ONE);

	armourFile.close();
	writeLog("Armour File [" + directory + "] Closed", TWO);
}


void loadScroll(Item& selectedItemSlot)
{
	int armourID = selectedItemSlot.itemID; //these 3 lines just get the armourID from the class and create 1 string that is the directory of the items file
	std::string convertedID = std::to_string(armourID);
	std::string directory = defaultItemDirectory + armour + convertedID + ".txt";

	std::ifstream armourFile(directory);
	writeLog("Armour File [" + directory + "] Opened", TWO);

	std::string unconvertedArmourMaterial; //converts the number that's read from the file into an actual integer
	std::getline(armourFile, unconvertedArmourMaterial);
	std::stringstream convertedMaterial(unconvertedArmourMaterial);
	int armourMaterial;
	convertedMaterial >> armourMaterial;

	switch (armourMaterial)
	{
	case 1:
		selectedItemSlot.itemMaterial = Materials::CLOTH;
		break;
	case 5:
		selectedItemSlot.itemMaterial = Materials::LEATHER;
		break;
	case 10:
		selectedItemSlot.itemMaterial = Materials::WOOD;
		break;
	case 25:
		selectedItemSlot.itemMaterial = Materials::SOFTMETAL;
		break;
	case 40:
		selectedItemSlot.itemMaterial = Materials::HARDMETAL;
		break;
	case 50:
		selectedItemSlot.itemMaterial = Materials::COMPOSITE;
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
		selectedItemSlot.itemType = ItemType::PLAIN;
		break;
	case 5:
		selectedItemSlot.itemType = ItemType::PADDED;
		break;
	case 10:
		selectedItemSlot.itemType = ItemType::STUDDED;
		break;
	case 25:
		selectedItemSlot.itemType = ItemType::CHAINMAIL;
		break;
	case 40:
		selectedItemSlot.itemType = ItemType::PLATEMAIL;
		break;
	}

	writeLog("Armour Type Loaded", ONE);


	std::string unconvertedArmourQuality;
	std::getline(armourFile, unconvertedArmourQuality);
	std::stringstream convertedArmourQuality(unconvertedArmourQuality);
	int armourQuality;
	convertedArmourQuality >> armourQuality;
	selectedItemSlot.itemQuality = armourQuality;

	writeLog("Armour Quality Loaded", ONE);

	std::getline(armourFile, selectedItemSlot.itemName);

	writeLog("Armour Name Loaded", ONE);

	armourFile.close();
	writeLog("Armour File [" + directory + "] Closed", TWO);
}


void loadShield(Item& selectedItemSlot)
{
	int armourID = selectedItemSlot.itemID; //these 3 lines just get the armourID from the class and create 1 string that is the directory of the items file
	std::string convertedID = std::to_string(armourID);
	std::string directory = defaultItemDirectory + armour + convertedID + ".txt";

	std::ifstream armourFile(directory);
	writeLog("Armour File [" + directory + "] Opened", TWO);

	std::string unconvertedArmourMaterial; //converts the number that's read from the file into an actual integer
	std::getline(armourFile, unconvertedArmourMaterial);
	std::stringstream convertedMaterial(unconvertedArmourMaterial);
	int armourMaterial;
	convertedMaterial >> armourMaterial;

	switch (armourMaterial)
	{
	case 1:
		selectedItemSlot.itemMaterial = Materials::CLOTH;
		break;
	case 5:
		selectedItemSlot.itemMaterial = Materials::LEATHER;
		break;
	case 10:
		selectedItemSlot.itemMaterial = Materials::WOOD;
		break;
	case 25:
		selectedItemSlot.itemMaterial = Materials::SOFTMETAL;
		break;
	case 40:
		selectedItemSlot.itemMaterial = Materials::HARDMETAL;
		break;
	case 50:
		selectedItemSlot.itemMaterial = Materials::COMPOSITE;
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
		selectedItemSlot.itemType = ItemType::PLAIN;
		break;
	case 5:
		selectedItemSlot.itemType = ItemType::PADDED;
		break;
	case 10:
		selectedItemSlot.itemType = ItemType::STUDDED;
		break;
	case 25:
		selectedItemSlot.itemType = ItemType::CHAINMAIL;
		break;
	case 40:
		selectedItemSlot.itemType = ItemType::PLATEMAIL;
		break;
	}

	writeLog("Armour Type Loaded", ONE);


	std::string unconvertedArmourQuality;
	std::getline(armourFile, unconvertedArmourQuality);
	std::stringstream convertedArmourQuality(unconvertedArmourQuality);
	int armourQuality;
	convertedArmourQuality >> armourQuality;
	selectedItemSlot.itemQuality = armourQuality;

	writeLog("Armour Quality Loaded", ONE);

	std::getline(armourFile, selectedItemSlot.itemName);

	writeLog("Armour Name Loaded", ONE);

	armourFile.close();
	writeLog("Armour File [" + directory + "] Closed", TWO);
}


void loadWeapon(Item& selectedItemSlot)
{
	int armourID = selectedItemSlot.itemID; //these 3 lines just get the armourID from the class and create 1 string that is the directory of the items file
	std::string convertedID = std::to_string(armourID);
	std::string directory = defaultItemDirectory + armour + convertedID + ".txt";

	std::ifstream armourFile(directory);
	writeLog("Armour File [" + directory + "] Opened", TWO);

	std::string unconvertedArmourMaterial; //converts the number that's read from the file into an actual integer
	std::getline(armourFile, unconvertedArmourMaterial);
	std::stringstream convertedMaterial(unconvertedArmourMaterial);
	int armourMaterial;
	convertedMaterial >> armourMaterial;

	switch (armourMaterial)
	{
	case 1:
		selectedItemSlot.itemMaterial = Materials::CLOTH;
		break;
	case 5:
		selectedItemSlot.itemMaterial = Materials::LEATHER;
		break;
	case 10:
		selectedItemSlot.itemMaterial = Materials::WOOD;
		break;
	case 25:
		selectedItemSlot.itemMaterial = Materials::SOFTMETAL;
		break;
	case 40:
		selectedItemSlot.itemMaterial = Materials::HARDMETAL;
		break;
	case 50:
		selectedItemSlot.itemMaterial = Materials::COMPOSITE;
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
		selectedItemSlot.itemType = ItemType::PLAIN;
		break;
	case 5:
		selectedItemSlot.itemType = ItemType::PADDED;
		break;
	case 10:
		selectedItemSlot.itemType = ItemType::STUDDED;
		break;
	case 25:
		selectedItemSlot.itemType = ItemType::CHAINMAIL;
		break;
	case 40:
		selectedItemSlot.itemType = ItemType::PLATEMAIL;
		break;
	}

	writeLog("Armour Type Loaded", ONE);


	std::string unconvertedArmourQuality;
	std::getline(armourFile, unconvertedArmourQuality);
	std::stringstream convertedArmourQuality(unconvertedArmourQuality);
	int armourQuality;
	convertedArmourQuality >> armourQuality;
	selectedItemSlot.itemQuality = armourQuality;

	writeLog("Armour Quality Loaded", ONE);

	std::getline(armourFile, selectedItemSlot.itemName);

	writeLog("Armour Name Loaded", ONE);

	armourFile.close();
	writeLog("Armour File [" + directory + "] Closed", TWO);
}


void loadItem(Item& selectedItemSlot)
{
	int itemID = selectedItemSlot.itemID; //these 3 lines just get the armourID from the class and create 1 string that is the directory of the items file
	std::string convertedID{ std::to_string(itemID) };
	std::string itemType = checkItemID(itemID);
	std::string directory{ defaultItemDirectory + itemType + ".txt" };

	if (itemType == armour)
	{
		loadArmour(selectedItemSlot);
	}
	else if (itemType == food)
	{
		loadFood(selectedItemSlot);
	}
	else if (itemType == ingredients)
	{
		loadIngredient(selectedItemSlot);
	}
	else if (itemType == magicItems)
	{
		loadMagicItem(selectedItemSlot);
	}
	else if (itemType == potions)
	{
		loadPotion(selectedItemSlot);
	}
	else if (itemType == scrolls)
	{
		loadScroll(selectedItemSlot);
	}
	else if (itemType == shields)
	{
		loadShield(selectedItemSlot);
	}
	else if (itemType == weapons)
	{
		loadWeapon(selectedItemSlot);
	}

	std::ifstream itemFile(directory);
	writeLog("Item File [" + directory + "] Opened", TWO);

	std::string fileInput{};
	std::getline(itemFile, fileInput);
	int materialType{ stringToInteger(fileInput) };

	
}