#include <string>
#include <sstream>
#include <iostream>
#include "mainFile.h"
#include "conversionFunctions.h"
#include "logsAndExceptions.h"


int stringToIntegerGL()
{
	int intToReturn;
	std::string stringToConvert;
	std::getline(std::cin, stringToConvert);
	std::stringstream convertedString(stringToConvert); //stringstream converts integers within a string into actual integers
	convertedString >> intToReturn; //you have to access a stringstream the same way you access std::cin
	return intToReturn;
}

int stringToInteger(std::string stringToConvert)
{
	int intToReturn;
	std::stringstream convertedString(stringToConvert); //stringstream converts integers within a string into actual integers
	convertedString >> intToReturn; //you have to access a stringstream the same way you access std::cin
	return intToReturn;
}