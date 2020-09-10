#ifndef MAINFILE
#define MAINFILE
#include <string>
#include <filesystem>

//system settings
inline std::filesystem::path path = std::filesystem::current_path();
inline std::string currentPath = path.string();
inline bool firstTimeRun{ true };
inline bool gameStartUp{ true };
inline bool autoSave{ true };
inline short systemLogLevel{ 1 }; //1 is highest, then 2, then 3 at the bottom (4 turns it off completely)

void printLogo(int lines, std::string logoDir, bool animated);
void mainMenu();

//main menu
inline std::string logoMainDirectory;


//settings

inline std::string logoSettingsDirectory;


//Settings Auto Save
inline std::string settingsDirectory;
inline std::string settingsAutoSaveDirectory;
inline std::string settingsAutoSaveDirectoryError;
inline std::string settingsAutoSaveDirectoryOff;
inline std::string settingsAutoSaveDirectoryOn;
inline std::string currentASSetting{ "/Settings1On.txt" };

//Settings Save Game History
inline std::string settingsSaveGameHistoryDirectory;
inline std::string settingsSaveGameHistoryDirectoryError;
inline std::string settingsSaveGameHistoryDirectoryOff;
inline std::string settingsSaveGameHistoryDirectoryOn;

//Settings Game Logging Level
inline std::string settingsGameLoggingLevelDirectory;
inline std::string settingsGameLoggingLevelDirectoryError;
inline std::string settingsGameLoggingLevelDirectoryHigh;
inline std::string settingsGameLoggingLevelDirectoryMedium;
inline std::string settingsGameLoggingLevelDirectoryLow;

//Credits
inline std::string creditsFile;

#endif