#ifndef LOGSANDEXCEPTIONS
#define LOGSANDEXCEPTIONS
#include <string>
#include <fstream>
#include "getTime.h"

enum LogLevels
{
	ONE = 1,
	TWO = 2,
	THREE = 3,
};

void writeLog(std::string eventToLog, int logLevel);
void writeException(std::string eventToLog);


#endif