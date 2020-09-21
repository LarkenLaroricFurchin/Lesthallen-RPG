#include <string>
#include <sstream>
#include <iostream>
#include "mainFile.h"
#include "conversionFunctions.h"
#include "logsAndExceptions.h"


int stringToIntegerGL()
{
	writeLog("String To Integer Get Line function", THREE);
	int intToReturn;
	std::string stringToConvert;
	std::getline(std::cin, stringToConvert);
	std::stringstream convertedString(stringToConvert); //stringstream converts integers within a string into actual integers
	convertedString >> intToReturn; //you have to access a stringstream the same way you access std::cin
	return intToReturn;
}

int stringToInteger(std::string stringToConvert)
{
	writeLog("String To Integer function", THREE);
	int intToReturn;
	std::stringstream convertedString(stringToConvert); //stringstream converts integers within a string into actual integers
	convertedString >> intToReturn; //you have to access a stringstream the same way you access std::cin
	return intToReturn;
}