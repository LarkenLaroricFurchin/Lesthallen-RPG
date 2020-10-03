#ifndef ITEMHANDLER
#define ITEMHANDLER
#include <string>



int getItemQuality(int materialQuality, std::string type, int quality);



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



class Material
{
public:
	std::string materialName{"Cloth"};//Just the name of the material
	std::string materialType{"Fabric"};//used to detirmine what the material can be used for when crafting is implemented
	short materialQuality{1};//1 = extremelly poor quality, very bad stats. 99 = extremelly high quality, very good stats
	short materialStrength{1};//0 = breaks if interacted with. 1 = very fine, could rip with barely any effort. 99 = Extremely strong, would take a nuclear bomb or the hottest furnace to break.
	short materialWeight{1};//1 = extremelly light, starting strngth is more than enough for this. 99 = extremelly heavy, will need very high strength stat to carry items made from this material
};


class enchantment
{
public:
	std::string enchantmentName{"Fire Protection"};
	double enchantmentDamageMultiplier{0.0};
	std::string enchantmentDamageProtectionType{"Fire"};
	double enchantmentDamageProtectionMultiplier{0.5};
};

struct Item
{
	int itemID{ 0000 };
	Material itemMaterial{};
	std::string itemType{ "Armour" };
	std::string itemSubType{ "Plain" };
	int itemQuality{ 1 };
	double itemDamage{ 0 };
	double itemDurability{ 10 };
	bool itemIsStackable{ 1 };
	int itemStackSize{ 1 };
	int itemWeight{1};
	enchantment itemEnchantment[10]{};
	std::string itemName{"Cloth Cap"};
};

class Material;
void loadMaterial(Item& selectedItemSlot);
/*
void loadArmour(Item& selectedItemSlot);
void loadFood(Item& selectedItemSlot);
void loadIngredient(Item& selectedItemSlot);
void loadMagicItem(Item& selectedItemSlot);
void loadPotion(Item& selectedItemSlot);
void loadScroll(Item& selectedItemSlot);
void loadShield(Item& selectedItemSlot);
void loadWeapon(Item& selectedItemSlot);
*/
void loadItem(Item& selectedItemSlot);
#endif