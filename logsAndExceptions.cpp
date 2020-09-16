#include "Lesthallen RPG.h"
#include "logsAndExceptions.h"
#include "characterOperations.h"



	std::string logAndExceptionDirectory{ currentPath + "/Lesthallen RPG/System/Logs/" };
	std::string LogFile;

	

void writeLog(std::string eventToLog, int logLevel)
{
	if (characterLoaded == false)
	{
		LogFile = logAndExceptionDirectory + "Log.txt";
	}
	else
	{
		LogFile = logAndExceptionDirectory + playerCharacter.characterName + "Log.txt";
	}
	
	if (logLevel >= systemLogLevel)
	{
		std::ofstream logFile(LogFile, std::ios::app);
		std::string curTime = getTime();
		eventToLog = curTime + "]  " + eventToLog;
		logFile << "[" << eventToLog << "\n";
		logFile.close();
	}
}