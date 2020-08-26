#include "Lesthallen RPG.h"
#include "logsAndExceptions.h"
#include "characterOperations.h"



	std::string logAndExceptionDirectory{ "C:/Users/LIAMF/Documents/C++ Projects/Learning C++/Log/" };
	std::string LogFile;

	

void writeLog(std::string eventToLog)
{
	if (characterLoaded == false)
	{
		LogFile = logAndExceptionDirectory.append("Log.txt");
	}
	else
	{
		LogFile = logAndExceptionDirectory.append(playerCharacter.characterName).append("Log.txt");
	}
	
	std::ofstream logFile(LogFile, std::ios::app);
	std::string curTime = getTime();
	eventToLog = (curTime).append("]  ").append(eventToLog);
	logFile << "[" << eventToLog << "\n";
	logFile.close();
	logAndExceptionDirectory = "C:/Users/LIAMF/Documents/C++ Projects/Learning C++/Log/";
}