#ifndef ITEMHANDLER
#define ITEMHANDLER
#include <string>



int getItemScore(int material, int type, int quality);
std::string getItemClass(int itemScore);



enum class Materials //the values of these materials will be used to calculate the stats of items created using them
{
	EMPTY = 0,
	CLOTH = 1,
	PAPER = 1,
	GLASS = 1,
	FOOD = 1,
	INGREDIENT = 1,
	LEATHER = 5,
	WOOD = 10,
	SOFTMETAL = 25,
	HARDMETAL = 40,
	COMPOSITE = 50,
};

enum class ItemType
{
	EMPTY = 0,
	POTION = 1,
	FOOD = 1,
	SCROLL = 1,
	PLAIN = 1,//plain armour
	LOWINGREDIENT = 1,//low level ingredient
	INGREDIENT = 3,
	CLUB = 3,//smack your enemies!!
	MAGICITEM = 5,//wands, staffs etc...
	SHIELD = 5,
	DAGGER = 5,
	MEDIUMINGREDIENT = 5,//medium level ingredient
	SHORTSWORD = 10,
	SHORTBOW = 12,
	LONGSWORD = 20,
	GREATSWORD = 30,
	PADDED = 5, //padded armour
	STUDDED = 10, //studded armour
	HIGHINGREDIENT = 10,//high level ingredient
	CHAINMAIL = 25,
	PLATEMAIL = 40,
};

struct Armour
{
	short itemID{ 0000 };
	Materials armourMaterial{ Materials::CLOTH };
	ItemType itemType{ ItemType::PLAIN };
	short armourQuality{ 1 };
	int armourScore{ getItemScore(static_cast<int>(armourMaterial), static_cast<int>(itemType), armourQuality) };
	std::string armourClass{ getItemClass(armourScore) };
	std::string armourName{"Cloth Cap"};
};



struct Item
{
	short itemID{ 0000 };
	Materials itemMaterial{ Materials::CLOTH };
	ItemType itemType{ ItemType::PLAIN };
	short itemQuality{ 1 };
	int itemScore{ getItemScore(static_cast<int>(itemMaterial), static_cast<int>(itemType), itemQuality) };
	double itemDamage{0};
	std::string itemClass{ getItemClass(itemScore) };
	std::string itemName{"Cloth Cap"};
};

void loadArmour(Item& selectedItemSlot);
void loadFood(Item& selectedItemSlot);
void loadIngredient(Item& selectedItemSlot);
void loadMagicItem(Item& selectedItemSlot);
void loadPotion(Item& selectedItemSlot);
void loadScroll(Item& selectedItemSlot);
void loadShield(Item& selectedItemSlot);
void loadWeapon(Item& selectedItemSlot);
void loadItem(Item& selectedItemSlot);
#endif