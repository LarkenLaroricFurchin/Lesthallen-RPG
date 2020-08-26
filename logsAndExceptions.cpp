#include "logsAndExceptions.h"
#include "characterOperations.h"
#include "LearningC++0.1.h"


	std::string logAndExceptionDirectory{ "C:/Users/LIAMF/Documents/C++ Projects/Learning C++/Log/" };
	std::string characterLogFile;

	

void writeLog(std::string eventToLog)
{
	characterLogFile = logAndExceptionDirectory.append(playerCharacter.characterName).append("Log.txt");
	std::ofstream logFile(characterLogFile, std::ios::app);
	std::string curTime = getTime();
	eventToLog = (curTime).append("]  ").append(eventToLog);
	logFile << "[" << eventToLog << "\n";
	logFile.close();
	logAndExceptionDirectory = "C:/Users/LIAMF/Documents/C++ Projects/Learning C++/Log/";
}