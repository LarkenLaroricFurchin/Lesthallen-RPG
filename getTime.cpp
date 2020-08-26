#include <string>
#include <ctime>
#include <chrono>
#include "getTime.h"

std::string getTime()
{

	auto measuredTime = std::chrono::system_clock::now();
	std::time_t curTime = std::chrono::system_clock::to_time_t(measuredTime);

	std::string finalTime = ctime(&curTime);
	finalTime = finalTime.substr(0, finalTime.length() - 1);
	return finalTime;

	/*
	auto measuredTime = std::chrono::system_clock::now(); //gets the current system time
	std::time_t curTime = std::chrono::system_clock::to_time_t(measuredTime); //converts the measured time into a readable format

	std::string finalTime = ctime(&curTime); //assigns the current, converted, time to the "finalTime" string
	finalTime = finalTime.substr(0, finalTime.length() - 1); //chops the newline off the end!
	//these two lines are there to simply cut the sodding newline off the end of "ctime(&curTime)" 
	return finalTime;
	*/
}