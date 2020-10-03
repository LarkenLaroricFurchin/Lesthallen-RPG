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
std::string material{"/Lesthallen RPG/System/Materials"};

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

void loadMaterial(Item& selectedItemSlot)
{
	std::string materialName{ selectedItemSlot.itemMaterial.materialName };

	std::ifstream materialFile(currentPath + "/" + material + "/" + materialName + ".txt");
	writeLog("Material File [" + currentPath + "/" + material + "/" + materialName + ".txt" + "] Opened", TWO);


	std::getline(materialFile, selectedItemSlot.itemMaterial.materialType);
	writeLog("Material Type ["+ selectedItemSlot.itemMaterial.materialType + "] Loaded", TWO);


	std::string unconvertedMaterialQuality{};
	std::getline(materialFile, unconvertedMaterialQuality);
	int materialQuality{ stringToInteger(unconvertedMaterialQuality) };
	selectedItemSlot.itemMaterial.materialQuality = materialQuality;
	writeLog("Material Quality [" + std::to_string(materialQuality) + "] Loaded", TWO);


	std::string unconvertedMaterialStrength{};
	std::getline(materialFile, unconvertedMaterialStrength);
	int materialStrength{ stringToInteger(unconvertedMaterialStrength) };
	selectedItemSlot.itemMaterial.materialStrength = materialStrength;
	writeLog("Material Strength [" + std::to_string(materialStrength) + "] Loaded", TWO);


	std::string unconvertedMaterialWeight{};
	std::getline(materialFile, unconvertedMaterialWeight);
	int materialWeight{ stringToInteger(unconvertedMaterialWeight) };
	selectedItemSlot.itemMaterial.materialWeight = materialWeight;
	writeLog("Material Weight [" + std::to_string(materialWeight) + "] Loaded", TWO);


	materialFile.close();
	writeLog("Material File [" + currentPath + "/" + material + "/" + materialName + ".txt" + "] Closed", TWO);
}
/*
void loadArmour(Item& selectedItemSlot)
{
	int armourID = selectedItemSlot.itemID; //these 3 lines just get the armourID from the class and create 1 string that is the directory of the items file
	std::string convertedID = std::to_string(armourID);
	std::string directory = currentPath + defaultItemDirectory + armour + convertedID + ".txt";
	
	std::ifstream armourFile(directory);
	writeLog("Armour File [" + directory + "] Opened", TWO);

	//Load the armours material
	std::getline(armourFile, selectedItemSlot.itemMaterial.materialName);
	loadMaterial(selectedItemSlot);
	writeLog("Armour Material Loaded [itemID:" + convertedID + "]", ONE);

	//Load the armours type
	std::getline(armourFile, selectedItemSlot.itemType);
	writeLog("Armour Type Loaded [itemID:" + convertedID + "]", ONE);

	//Load the armours sub type
	std::getline(armourFile, selectedItemSlot.itemSubType);
	writeLog("Armour Sub Type Loaded [itemID:" + convertedID + "]", ONE);

	//Load the armours quality
	std::string unconvertedArmourQuality{};
	std::getline(armourFile, unconvertedArmourQuality);
	int armourQuality{ stringToInteger(unconvertedArmourQuality) };
	selectedItemSlot.itemQuality = armourQuality;
	writeLog("Armour Quality Loaded [itemID:" + convertedID + "]", ONE);

	//Load the armours damage - This should always be 0 for armour, but it's loaded anyways as part of the item struct
	std::string unconvertedArmourDamage{};
	std::getline(armourFile, unconvertedArmourDamage);
	int armourDamage{ stringToInteger(unconvertedArmourDamage) };
	selectedItemSlot.itemDamage = armourDamage;
	writeLog("Armour Damage Loaded [itemID:" + convertedID + "]", ONE);

	//Load the armours durability
	std::string unconvertedArmourDurability{};
	std::getline(armourFile, unconvertedArmourDurability);
	int armourDurability{ stringToInteger(unconvertedArmourDurability) };
	selectedItemSlot.itemDurability = armourDurability;
	writeLog("Armour Durability Loaded [itemID:" + convertedID + "]", ONE);

	//Load the armours Stackable state
	std::string unconvertedArmourStackability{};
	std::getline(armourFile, unconvertedArmourStackability);
	bool armourStackability{ stringToInteger(unconvertedArmourStackability) };
	selectedItemSlot.itemIsStackable = armourStackability;
	writeLog("Armour Stackable State Loaded [itemID:" + convertedID + "]", ONE);

	//Load the armours stack size
	std::string unconvertedArmourStackSize{};
	std::getline(armourFile, unconvertedArmourStackSize);
	int armourStackSize{ stringToInteger(unconvertedArmourStackSize) };
	selectedItemSlot.itemStackSize = armourStackSize;
	writeLog("Armour Stack Size Loaded [itemID:" + convertedID + "]", ONE);

	//Load the armours enchantments
	std::string unconvertedArmourDurability{};
	std::getline(armourFile, selectedItemSlot.itemEnchantment[0].enchantmentName);
	writeLog("Armour Enchantments Loaded [itemID:" + convertedID + "]", ONE);

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
*/
void loadEmpty(Item& selectedItemSlot)
{
	std::string directory = currentPath + "/Lesthallen RPG/Items/empty";

	std::ifstream emptyFile(directory);
	writeLog("Empty File [" + directory + "] Opened", TWO);

	//Load the armours material
	std::getline(emptyFile, selectedItemSlot.itemMaterial.materialName);
	loadMaterial(selectedItemSlot);
	writeLog("Empty Material Loaded", ONE);

	//Load the armours type
	std::getline(emptyFile, selectedItemSlot.itemType);
	writeLog("Empty Type Loaded", ONE);

	//Load the armours sub type
	std::getline(emptyFile, selectedItemSlot.itemSubType);
	writeLog("Empty Sub Type Loaded", ONE);

	//Load the armours quality
	std::string unconvertedEmptyQuality{};
	std::getline(emptyFile, unconvertedEmptyQuality);
	int emptyQuality{ stringToInteger(unconvertedEmptyQuality) };
	selectedItemSlot.itemQuality = emptyQuality;
	writeLog("Empty Quality Loaded", ONE);

	//Load the armours damage - This should always be 0 for armour, but it's loaded anyways as part of the item struct
	std::string unconvertedArmourDamage{};
	std::getline(emptyFile, unconvertedArmourDamage);
	int armourDamage{ stringToInteger(unconvertedArmourDamage) };
	selectedItemSlot.itemDamage = armourDamage;
	writeLog("Empty Damage Loaded", ONE);

	//Load the armours durability
	std::string unconvertedArmourDurability{};
	std::getline(emptyFile, unconvertedArmourDurability);
	int armourDurability{ stringToInteger(unconvertedArmourDurability) };
	selectedItemSlot.itemDurability = armourDurability;
	writeLog("Empty Durability Loaded", ONE);

	//Load the armours Stackable state
	std::string unconvertedArmourStackability{};
	std::getline(emptyFile, unconvertedArmourStackability);
	bool armourStackability{ static_cast<bool>(stringToInteger(unconvertedArmourStackability)) };
	selectedItemSlot.itemIsStackable = armourStackability;
	writeLog("Empty Stackable State Loaded", ONE);

	//Load the armours stack size
	std::string unconvertedArmourStackSize{};
	std::getline(emptyFile, unconvertedArmourStackSize);
	int armourStackSize{ stringToInteger(unconvertedArmourStackSize) };
	selectedItemSlot.itemStackSize = armourStackSize;
	writeLog("Empty Stack Size Loaded", ONE);

	//Load the armours enchantments
	//std::string unconvertedArmourEnchantment{};
	std::getline(emptyFile, selectedItemSlot.itemEnchantment[0].enchantmentName);
	writeLog("Empty Enchantments Loaded", ONE);

	writeLog("Empty Name [" + selectedItemSlot.itemName + "] Loaded", ONE);

	emptyFile.close();
	writeLog("Empty File [" + directory + "] Closed", TWO);
}

void loadItem(Item& selectedItemSlot)//Don't think I need individual functions to load different item types any more, just can't be arsed to change the names of the variables.
{
	
	int itemID = selectedItemSlot.itemID; //these 3 lines just get the armourID from the class and create 1 string that is the directory of the items file
	std::string itemType = checkItemID(itemID);

	std::string convertedID = std::to_string(itemID);

	std::string directory = currentPath + defaultItemDirectory + armour + convertedID + ".txt";

	writeLog("Item Type: " + itemType, ONE);

	if (itemType == armour)
	{
		directory = currentPath + defaultItemDirectory + armour + convertedID + ".txt";
	}
	else if (itemType == food)
	{
		directory = currentPath + defaultItemDirectory + food + convertedID + ".txt";
	}
	else if (itemType == ingredients)
	{
		directory = currentPath + defaultItemDirectory + ingredients + convertedID + ".txt";
	}
	else if (itemType == magicItems)
	{
		directory = currentPath + defaultItemDirectory + magicItems + convertedID + ".txt";
	}
	else if (itemType == potions)
	{
		directory = currentPath + defaultItemDirectory + potions + convertedID + ".txt";
	}
	else if (itemType == scrolls)
	{
		directory = currentPath + defaultItemDirectory + scrolls + convertedID + ".txt";
	}
	else if (itemType == shields)
	{
		directory = currentPath + defaultItemDirectory + shields + convertedID + ".txt";
	}
	else if (itemType == weapons)
	{
		directory = currentPath + defaultItemDirectory + weapons + convertedID + ".txt";
	}
	else if (itemType == empty)
	{
		directory = currentPath + defaultItemDirectory + "/" + empty;
	}

	

	std::ifstream armourFile(directory);
	writeLog("Item File [" + directory + "] Opened", TWO);

	//Load the armours material
	std::getline(armourFile, selectedItemSlot.itemMaterial.materialName);
	loadMaterial(selectedItemSlot);
	writeLog("Item Material Loaded [" + selectedItemSlot.itemMaterial.materialName + "]", ONE);

	//Load the armours type
	std::getline(armourFile, selectedItemSlot.itemType);
	writeLog("Item Type Loaded [" + selectedItemSlot.itemType + "]", ONE);

	//Load the armours sub type
	std::getline(armourFile, selectedItemSlot.itemSubType);
	writeLog("Item Sub Type Loaded [" + selectedItemSlot.itemSubType + "]", ONE);

	//Load the armours quality
	std::string unconvertedArmourQuality{};
	std::getline(armourFile, unconvertedArmourQuality);
	int armourQuality{ stringToInteger(unconvertedArmourQuality) };
	selectedItemSlot.itemQuality = armourQuality;
	writeLog("Item Quality Loaded [" + unconvertedArmourQuality + "]", ONE);

	//Load the armours damage - This should always be 0 for armour, but it's loaded anyways as part of the item struct
	std::string unconvertedArmourDamage{};
	std::getline(armourFile, unconvertedArmourDamage);
	int armourDamage{ stringToInteger(unconvertedArmourDamage) };
	selectedItemSlot.itemDamage = armourDamage;
	writeLog("Item Damage Loaded [" + unconvertedArmourDamage + "]", ONE);

	//Load the armours durability
	std::string unconvertedArmourDurability{};
	std::getline(armourFile, unconvertedArmourDurability);
	int armourDurability{ stringToInteger(unconvertedArmourDurability) };
	selectedItemSlot.itemDurability = armourDurability;
	writeLog("Item Durability Loaded [" + unconvertedArmourDurability + "]", ONE);

	//Load the armours Stackable state
	std::string unconvertedArmourStackability{};
	std::getline(armourFile, unconvertedArmourStackability);
	bool armourStackability{ static_cast<bool>(stringToInteger(unconvertedArmourStackability)) };
	selectedItemSlot.itemIsStackable = armourStackability;
	writeLog("Item Stackable State Loaded [" + unconvertedArmourStackability + "]", ONE);

	//Load the armours stack size
	std::string unconvertedArmourStackSize{};
	std::getline(armourFile, unconvertedArmourStackSize);
	int armourStackSize{ stringToInteger(unconvertedArmourStackSize) };
	selectedItemSlot.itemStackSize = armourStackSize;
	writeLog("Item Stack Size Loaded [" + unconvertedArmourStackSize + "]", ONE);

	//Load the armours enchantments
	//std::string unconvertedArmourDurability{};
	std::getline(armourFile, selectedItemSlot.itemEnchantment[0].enchantmentName);
	writeLog("Item Enchantments Loaded [" + selectedItemSlot.itemEnchantment[0].enchantmentName + "]", ONE);

	std::getline(armourFile, selectedItemSlot.itemName);

	writeLog("Item Name [" + selectedItemSlot.itemName + "] Loaded", ONE);

	armourFile.close();
	writeLog("Item File [" + directory + "] Closed", TWO);


	/*
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
	*/
}