#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
//====================[]====================
#include "Lesthallen RPG.h"
#include "itemHandler.h"
#include "characterOperations.h"



std::string defaultItemDirectory{ "/Lesthallen RPG/Items" };
std::string consumable{"/Consumables/"};
std::string armour{ "/Armour/" };
std::string food{ "/Food/" };
std::string ingredients{ "/Ingredients/" };
std::string magicItems{ "/Magic Items/" };
std::string potions{ "/Potions/" };
std::string scrolls{ "/Scrolls/" };
std::string shields{ "/Shields/" };
std::string weapons{ "/Weapons/" };
std::string empty{"/empty.txt"};
std::string error{ "/error/" };

std::string checkItemID(int itemID)
{
	std::string stringItemID = std::to_string(itemID);
	char itemTypeID = stringItemID[0];

	switch (itemTypeID)
	{
	case '0':
		return empty;
	case '1':
		return armour;
	case '2':
		return food;
	case '3':
		return ingredients;
	case '4':
		return magicItems;
	case '5':
		return potions;
	case '6':
		return scrolls;
	case '7':
		return shields;
	case '8':
		return weapons;
	}
	return error;
}

void loadArmour(Item& selectedItemSlot)
{
	int armourID = selectedItemSlot.itemID; //these 3 lines just get the armourID from the class and create 1 string that is the directory of the items file
	std::string convertedID = std::to_string(armourID);
	std::string directory = currentPath + defaultItemDirectory + armour + convertedID + ".txt";
	
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
	writeLog("Armour Material Loaded [itemID:" + convertedID + "]", ONE);


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

	writeLog("Armour Type Loaded [itemID:" + convertedID + "]", ONE);


	std::string unconvertedArmourQuality;
	std::getline(armourFile, unconvertedArmourQuality);
	std::stringstream convertedArmourQuality(unconvertedArmourQuality);
	int armourQuality;
	convertedArmourQuality >> armourQuality;
	selectedItemSlot.itemQuality = armourQuality;

	writeLog("Armour Quality Loaded [itemID:" + convertedID + "]", ONE);

	std::getline(armourFile, selectedItemSlot.itemName);

	writeLog("Armour Name [" + selectedItemSlot.itemName + "] Loaded [itemID:" + convertedID + "]", ONE);

	armourFile.close();
	writeLog("Armour File [" + directory + "] Closed", TWO);
}
//Loads Armour - Done

void loadFood(Item& selectedItemSlot)
{
	int foodID = selectedItemSlot.itemID; //these 3 lines just get the armourID from the class and create 1 string that is the directory of the items file
	std::string convertedID = std::to_string(foodID);
	std::string directory = currentPath + defaultItemDirectory + food + convertedID + ".txt";

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

	
	std::string unconvertedFoodType;
	std::getline(foodFile, unconvertedFoodType);
	std::stringstream convertedFoodType(unconvertedFoodType);
	int foodType;
	convertedFoodType >> foodType;
	

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
//Loads Food - Done

void loadIngredient(Item& selectedItemSlot)
{
	int ingredientID = selectedItemSlot.itemID; //these 3 lines just get the armourID from the class and create 1 string that is the directory of the items file
	std::string convertedID = std::to_string(ingredientID);
	std::string directory = currentPath + defaultItemDirectory + ingredients + convertedID + ".txt";

	std::ifstream ingredientFile(directory);
	writeLog("Ingredient File [" + directory + "] Opened", TWO);
	
	std::string unconvertedIngredientMaterial; //converts the number that's read from the file into an actual integer
	std::getline(ingredientFile, unconvertedIngredientMaterial);
	std::stringstream convertedMaterial(unconvertedIngredientMaterial);
	int ingredientMaterial;
	convertedMaterial >> ingredientMaterial;
	

	selectedItemSlot.itemMaterial = Materials::INGREDIENT;
	writeLog("Ingredient Material Loaded [itemID:" + convertedID + "]", ONE);


	std::string unconvertedIngredientType;
	std::getline(ingredientFile, unconvertedIngredientType);
	std::stringstream convertedIngredientType(unconvertedIngredientType);
	int ingredientType;
	convertedIngredientType >> ingredientType;

	switch (ingredientType)
	{
	case 1:
		selectedItemSlot.itemType = ItemType::LOWINGREDIENT;
		break;
	case 5:
		selectedItemSlot.itemType = ItemType::MEDIUMINGREDIENT;
		break;
	case 10:
		selectedItemSlot.itemType = ItemType::HIGHINGREDIENT;
		break;
	}

	writeLog("Ingredient Type Loaded [itemID:" + convertedID + "]", ONE);


	std::string unconvertedIngredientQuality;
	std::getline(ingredientFile, unconvertedIngredientQuality);
	std::stringstream convertedIngredientQuality(unconvertedIngredientQuality);
	int ingredientQuality;
	convertedIngredientQuality >> ingredientQuality;
	selectedItemSlot.itemQuality = ingredientQuality;

	writeLog("Ingredient Quality Loaded [itemID:" + convertedID + "]", ONE);

	std::getline(ingredientFile, selectedItemSlot.itemName);

	writeLog("Ingredient Name Loaded [itemID:" + convertedID + "]", ONE);

	ingredientFile.close();
	writeLog("Ingredient File [" + directory + "] Closed", TWO);
}
//Loads Ingredients - Done

void loadMagicItem(Item& selectedItemSlot)
{
	int magicItemID = selectedItemSlot.itemID; //these 3 lines just get the armourID from the class and create 1 string that is the directory of the items file
	std::string convertedID = std::to_string(magicItemID);
	std::string directory = currentPath + defaultItemDirectory + magicItems + convertedID + ".txt";

	std::ifstream magicItemFile(directory);
	writeLog("Armour File [" + directory + "] Opened", TWO);

	std::string unconvertedMagicItemMaterial; //converts the number that's read from the file into an actual integer
	std::getline(magicItemFile, unconvertedMagicItemMaterial);
	std::stringstream convertedMaterial(unconvertedMagicItemMaterial);
	int magicItemMaterial;
	convertedMaterial >> magicItemMaterial;

	switch (magicItemMaterial)
	{
	case 1:
		selectedItemSlot.itemMaterial = Materials::PAPER;
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
	writeLog("Magic Item Material Loaded [itemID:" + convertedID + "]", ONE);

	
	std::string unconvertedMagicItemType;
	std::getline(magicItemFile, unconvertedMagicItemType);
	std::stringstream convertedMagicItemType(unconvertedMagicItemType);
	int magicItemType;
	convertedMagicItemType >> magicItemType;
	
	selectedItemSlot.itemType = ItemType::MAGICITEM;

	writeLog("Magic Item Type Loaded [itemID:" + convertedID + "]", ONE);


	std::string unconvertedMagicItemQuality;
	std::getline(magicItemFile, unconvertedMagicItemQuality);
	std::stringstream convertedMagicItemQuality(unconvertedMagicItemQuality);
	int magicItemQuality;
	convertedMagicItemQuality >> magicItemQuality;
	selectedItemSlot.itemQuality = magicItemQuality;

	writeLog("Magic Item Quality Loaded [itemID:" + convertedID + "]", ONE);

	std::getline(magicItemFile, selectedItemSlot.itemName);

	writeLog("Armour Name Loaded", ONE);

	magicItemFile.close();
	writeLog("Magic Item File [" + directory + "] Closed", TWO);
}
//Loads Magic Items - Done

void loadPotion(Item& selectedItemSlot)
{
	int potionID = selectedItemSlot.itemID; //these 3 lines just get the armourID from the class and create 1 string that is the directory of the items file
	std::string convertedID = std::to_string(potionID);
	std::string directory = currentPath + defaultItemDirectory + potions + convertedID + ".txt";

	std::ifstream potionFile(directory);
	writeLog("Potion File [" + directory + "] Opened", TWO);
	
	std::string unconvertedPotionMaterial; //converts the number that's read from the file into an actual integer
	std::getline(potionFile, unconvertedPotionMaterial);
	std::stringstream convertedPotionMaterial(unconvertedPotionMaterial);
	int potionMaterial;
	convertedPotionMaterial >> potionMaterial;
	

	selectedItemSlot.itemMaterial = Materials::GLASS;

	writeLog("Potion Material Loaded [itemID:" + convertedID + "]", ONE);

	
	std::string unconvertedPotionType;
	std::getline(potionFile, unconvertedPotionType);
	std::stringstream convertedPotionType(unconvertedPotionType);
	int potionType;
	convertedPotionType >> potionType;
	
	selectedItemSlot.itemType = ItemType::POTION;

	writeLog("Potion Type Loaded [itemID:" + convertedID + "]", ONE);


	std::string unconvertedPotionQuality;
	std::getline(potionFile, unconvertedPotionQuality);
	std::stringstream convertedPotionQuality(unconvertedPotionQuality);
	int potionQuality;
	convertedPotionQuality >> potionQuality;
	selectedItemSlot.itemQuality = potionQuality;

	writeLog("Potion Quality Loaded [itemID:" + convertedID + "]", ONE);

	std::getline(potionFile, selectedItemSlot.itemName);

	writeLog("Potion Name Loaded [itemID:" + convertedID + "]", ONE);

	potionFile.close();
	writeLog("Potion File [" + directory + "] Closed", TWO);
}
//Loads Potions - Done

void loadScroll(Item& selectedItemSlot)
{
	int scrollID = selectedItemSlot.itemID; //these 3 lines just get the armourID from the class and create 1 string that is the directory of the items file
	std::string convertedID = std::to_string(scrollID);
	std::string directory = currentPath + defaultItemDirectory + scrolls + convertedID + ".txt";

	std::ifstream scrollFile(directory);
	writeLog("Scroll File [" + directory + "] Opened", TWO);

	std::string unconvertedScrollMaterial; //converts the number that's read from the file into an actual integer
	std::getline(scrollFile, unconvertedScrollMaterial);
	std::stringstream convertedScrollMaterial(unconvertedScrollMaterial);
	int scrollMaterial;
	convertedScrollMaterial >> scrollMaterial;

	switch (scrollMaterial)
	{
	case 1:
		selectedItemSlot.itemMaterial = Materials::PAPER;
		break;
	case 5:
		selectedItemSlot.itemMaterial = Materials::LEATHER;
		break;
	case 50:
		selectedItemSlot.itemMaterial = Materials::COMPOSITE;
		break;
	}
	writeLog("Scroll Material Loaded [itemID:" + convertedID + "]", ONE);

	
	std::string unconvertedScrollType;
	std::getline(scrollFile, unconvertedScrollType);
	std::stringstream convertedScrollType(unconvertedScrollType);
	int scrollType;
	convertedScrollType >> scrollType;
	
	selectedItemSlot.itemType = ItemType::SCROLL;

	writeLog("Scroll Type Loaded [itemID:" + convertedID + "]", ONE);


	std::string unconvertedScrollQuality;
	std::getline(scrollFile, unconvertedScrollQuality);
	std::stringstream convertedScrollQuality(unconvertedScrollQuality);
	int scrollQuality;
	convertedScrollQuality >> scrollQuality;
	selectedItemSlot.itemQuality = scrollQuality;

	writeLog("Scroll Quality Loaded [itemID:" + convertedID + "]", ONE);

	std::getline(scrollFile, selectedItemSlot.itemName);

	writeLog("Scroll Name Loaded [itemID:" + convertedID + "]", ONE);

	scrollFile.close();
	writeLog("Scroll File [" + directory + "] Closed", TWO);
}
//Loads Scrolls - Done

void loadShield(Item& selectedItemSlot)
{
	int shieldID = selectedItemSlot.itemID; //these 3 lines just get the armourID from the class and create 1 string that is the directory of the items file
	std::string convertedID = std::to_string(shieldID);
	std::string directory = currentPath + defaultItemDirectory + shields + convertedID + ".txt";

	std::ifstream shieldFile(directory);
	writeLog("Shield File [" + directory + "] Opened", TWO);

	std::string unconvertedShieldMaterial; //converts the number that's read from the file into an actual integer
	std::getline(shieldFile, unconvertedShieldMaterial);
	std::stringstream convertedShieldMaterial(unconvertedShieldMaterial);
	int shieldMaterial;
	convertedShieldMaterial >> shieldMaterial;

	switch (shieldMaterial)
	{
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
	writeLog("Shield Material Loaded [itemID:" + convertedID + "]", ONE);


	std::string unconvertedShieldType;
	std::getline(shieldFile, unconvertedShieldType);
	std::stringstream convertedShieldType(unconvertedShieldType);
	int shieldType;
	convertedShieldType >> shieldType;

	switch (shieldType)
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
	}

	writeLog("Shield Type Loaded [itemID:" + convertedID + "]", ONE);


	std::string unconvertedShieldQuality;
	std::getline(shieldFile, unconvertedShieldQuality);
	std::stringstream convertedShieldQuality(unconvertedShieldQuality);
	int shieldQuality;
	convertedShieldQuality >> shieldQuality;
	selectedItemSlot.itemQuality = shieldQuality;

	writeLog("Shield Quality Loaded [itemID:" + convertedID + "]", ONE);

	std::getline(shieldFile, selectedItemSlot.itemName);

	writeLog("Shield Name Loaded [itemID:" + convertedID + "]", ONE);

	shieldFile.close();
	writeLog("Shield File [" + directory + "] Closed", TWO);
}
//Loads Shields - Done

void loadWeapon(Item& selectedItemSlot)
{
	int weaponID = selectedItemSlot.itemID; //these 3 lines just get the armourID from the class and create 1 string that is the directory of the items file
	std::string convertedID = std::to_string(weaponID);
	std::string directory = currentPath + defaultItemDirectory + weapons + convertedID + ".txt";

	std::ifstream weaponFile(directory);
	writeLog("Weapon File [" + directory + "] Opened", TWO);

	std::string unconvertedWeaponMaterial; //converts the number that's read from the file into an actual integer
	std::getline(weaponFile, unconvertedWeaponMaterial);
	std::stringstream convertedWeaponMaterial(unconvertedWeaponMaterial);
	int weaponMaterial;
	convertedWeaponMaterial >> weaponMaterial;

	switch (weaponMaterial)
	{
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
	writeLog("Weapon Material Loaded [itemID:" + convertedID + "]", ONE);


	std::string unconvertedWeaponType;
	std::getline(weaponFile, unconvertedWeaponType);
	int weaponType{ stringToInteger(unconvertedWeaponType) };

	switch (weaponType)
	{
	case 3:
		selectedItemSlot.itemType = ItemType::CLUB;
		break;
	case 5:
		selectedItemSlot.itemType = ItemType::DAGGER;
		break;
	case 10:
		selectedItemSlot.itemType = ItemType::SHORTSWORD;
		break;
	case 12:
		selectedItemSlot.itemType = ItemType::SHORTBOW;
		break;
	case 20:
		selectedItemSlot.itemType = ItemType::LONGSWORD;
		break;
	case 30:
		selectedItemSlot.itemType = ItemType::GREATSWORD;
		break;
	}

	writeLog("Weapon Type Loaded [itemID:" + convertedID + "]", ONE);


	std::string unconvertedWeaponQuality;
	std::getline(weaponFile, unconvertedWeaponQuality);
	int weaponQuality{ stringToInteger(unconvertedWeaponQuality) };
	selectedItemSlot.itemQuality = weaponQuality;

	writeLog("Weapon Quality Loaded [itemID:" + convertedID + "]", ONE);

	std::getline(weaponFile, selectedItemSlot.itemName);

	writeLog("Weapon Name Loaded [itemID:" + convertedID + "]", ONE);

	weaponFile.close();
	writeLog("Weapon File [" + directory + "] Closed", TWO);
}
//Loads Weapons - Done

void loadEmpty(Item& selectedItemSlot)
{
	int emptyID = 0; //these 3 lines just get the armourID from the class and create 1 string that is the directory of the items file
	std::string convertedID = std::to_string(emptyID);
	std::string directory = currentPath + defaultItemDirectory + empty;

	std::ifstream emptyFile(directory);
	writeLog("Weapon File [" + directory + "] Opened", TWO);

	std::string unconvertedEmptyMaterial; //converts the number that's read from the file into an actual integer
	std::getline(emptyFile, unconvertedEmptyMaterial);
	std::stringstream convertedEmptyMaterial(unconvertedEmptyMaterial);
	int emptyMaterial;
	convertedEmptyMaterial >> emptyMaterial;

	selectedItemSlot.itemMaterial = Materials::EMPTY;
	writeLog("Empty Material Loaded [itemID:" + convertedID + "]", ONE);


	std::string unconvertedEmptyType;
	std::getline(emptyFile, unconvertedEmptyType);
	int emptyType{ stringToInteger(unconvertedEmptyType) };

	selectedItemSlot.itemType = ItemType::EMPTY;

	writeLog("Empty Type Loaded [itemID:" + convertedID + "]", ONE);


	std::string unconvertedEmptyQuality;
	std::getline(emptyFile, unconvertedEmptyQuality);
	int emptyQuality{ stringToInteger(unconvertedEmptyQuality) };
	selectedItemSlot.itemQuality = emptyQuality;

	writeLog("Empty Quality Loaded [itemID:" + convertedID + "]", ONE);

	std::getline(emptyFile, selectedItemSlot.itemName);

	writeLog("Empty Name Loaded [itemID:" + convertedID + "]", ONE);

	emptyFile.close();
	writeLog("Empty File [" + directory + "] Closed", TWO);
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
	else if (itemType == empty)
	{
		loadEmpty(selectedItemSlot);
	}
}