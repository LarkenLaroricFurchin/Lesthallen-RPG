#include <string>
#include "characterOperations.h"
#include "itemHandler.h"

int getArmourScore(int material, int type, int quality)
{
	int armourScore = (material + type) * quality;
	return armourScore;
}

std::string getArmourClass(int armourScore)
{
	if (armourScore >= 9000)
	{
		return "A";
	}
	else if (armourScore >= 8400)
	{
		return "B";
	}
	else if (armourScore >= 7800)
	{
		return "C";
	}
	else if (armourScore >= 7200)
	{
		return "D";
	}
	else if (armourScore >= 6600)
	{
		return "E";
	}
	else if (armourScore >= 6000)
	{
		return "F";
	}
	else if (armourScore >= 5700)
	{
		return "G";
	}
	else if (armourScore >= 5400)
	{
		return "H";
	}
	else if (armourScore >= 5100)
	{
		return "I";
	}
	else if (armourScore >= 4800)
	{
		return "J";
	}
	else if (armourScore >= 4500)
	{
		return "K";
	}
	else if (armourScore >= 4200)
	{
		return "L";
	}
	else if (armourScore >= 3900)
	{
		return "M";
	}
	else if (armourScore >= 3600)
	{
		return "N";
	}
	else if (armourScore >= 3300)
	{
		return "O";
	}
	else if (armourScore >= 3000)
	{
		return "P";
	}
	else if (armourScore >= 2700)
	{
		return "Q";
	}
	else if (armourScore >= 2400)
	{
		return "R";
	}
	else if (armourScore >= 2100)
	{
		return "S";
	}
	else if (armourScore >= 1800)
	{
		return "T";
	}
	else if (armourScore >= 1500)
	{
		return "U";
	}
	else if (armourScore >= 1200)
	{
		return "V";
	}
	else if (armourScore >= 900)
	{
		return "W";
	}
	else if (armourScore >= 600)
	{
		return "X";
	}
	else if (armourScore >= 300)
	{
		return "Y";
	}
	else if (armourScore >= 0)
	{
		return "Z";
	}
	return "Z";
}