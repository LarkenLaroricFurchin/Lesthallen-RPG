#include <string>
#include "characterOperations.h"
#include "itemHandler.h"

int getItemScore(int material, int type, int quality)
{
	int itemScore = (material + type) * quality;
	return itemScore;
}

std::string getItemClass(int itemScore)
{
	/*
	if (itemScore >= 9000)
	{
		return "A";
	}
	else if (itemScore >= 8400)
	{
		return "B";
	}
	else if (itemScore >= 7800)
	{
		return "C";
	}
	else if (itemScore >= 7200)
	{
		return "D";
	}
	else if (itemScore >= 6600)
	{
		return "E";
	}
	else if (itemScore >= 6000)
	{
		return "F";
	}
	else if (itemScore >= 5700)
	{
		return "G";
	}
	else if (itemScore >= 5400)
	{
		return "H";
	}
	else if (itemScore >= 5100)
	{
		return "I";
	}
	else if (itemScore >= 4800)
	{
		return "J";
	}
	else if (itemScore >= 4500)
	{
		return "K";
	}
	else if (itemScore >= 4200)
	{
		return "L";
	}
	else if (itemScore >= 3900)
	{
		return "M";
	}
	else if (itemScore >= 3600)
	{
		return "N";
	}
	else if (itemScore >= 3300)
	{
		return "O";
	}
	else if (itemScore >= 3000)
	{
		return "P";
	}
	else if (itemScore >= 2700)
	{
		return "Q";
	}
	else if (itemScore >= 2400)
	{
		return "R";
	}
	else if (itemScore >= 2100)
	{
		return "S";
	}
	else if (itemScore >= 1800)
	{
		return "T";
	}
	else if (itemScore >= 1500)
	{
		return "U";
	}
	else if (itemScore >= 1200)
	{
		return "V";
	}
	else if (itemScore >= 900)
	{
		return "W";
	}
	else if (itemScore >= 600)
	{
		return "X";
	}
	else if (itemScore >= 300)
	{
		return "Y";
	}
	else if (itemScore >= 0)
	{
		return "Z";
	}
	*/
	std::string itemClasses[27]{"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", };

	int itemScores[27]{9000, 8400, 7800, 7200, 6600, 6000, 57,00, 5400, 5100, 4800, 4500, 4200, 3900, 3600, 3300, 3000, 2700, 2400, 2100, 1800, 1500, 1200, 900, 600, 300, 0};

	int i{};

	for (i = 0; i < 27; i++)
	{
		if (itemScore >= itemScores[i])
		{
			return itemClasses[i];
		}
	}
	return "Z";
}