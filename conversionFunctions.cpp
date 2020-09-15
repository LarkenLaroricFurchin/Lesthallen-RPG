#include <string>
#include <sstream>
#include <iostream>
#include "mainFile.h"
#include "conversionFunctions.h"
#include "logsAndExceptions.h"


int stringToInteger()
{
	writeLog("String To Integer function", THREE);
	int intToReturn;
	std::string stringToConvert;
	std::getline(std::cin, stringToConvert);
	std::stringstream convertedString(stringToConvert); //stringstream converts integers within a string into actual integers
	convertedString >> intToReturn; //you have to access a stringstream the same way you access std::cin
	return intToReturn;
}