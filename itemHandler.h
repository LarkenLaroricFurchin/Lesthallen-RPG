#ifndef ITEMHANDLER
#define ITEMHANDLER
#include <string>



int getArmourScore(int, int, int);
std::string getArmourClass(int armourScore);


enum class Materials //the values of these materials will be used to calculate the stats of items created using them
{
	CLOTH = 1,
	LEATHER = 5,
	WOOD = 10,
	SOFTMETAL = 25,
	HARDMETAL = 40,
	COMPOSITE = 50,
};

enum class ArmourType
{
	PLAIN = 1,
	PADDED = 5,
	STUDDED = 10,
	CHAINMAIL = 25,
	PLATEMAIL = 40,
};

struct Armour
{
	short itemID{ 100 };
	Materials armourMaterial{ Materials::CLOTH };
	ArmourType armourType{ ArmourType::PLAIN };
	short armourQuality{ 1 };
	int armourScore{ getArmourScore(static_cast<int>(armourMaterial), static_cast<int>(armourType), armourQuality) };
	std::string armourClass{ getArmourClass(armourScore) };
	std::string armourName{"Cloth Cap"};
};

void loadArmour(Armour& selectedArmourSlot);
#endif