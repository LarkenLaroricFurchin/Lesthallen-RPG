#ifndef MAINFILE
#define MAINFILE
#include <string>
#include <filesystem>

void printLogo(int lines, std::string logoDir, bool animated);
void mainMenu();

//main menu
inline std::string logoMainDirectory{ "C:/Users/LIAMF/source/repos/Lesthallen RPG/Debug/Lesthallen RPG/Main Menu/LOGO.txt" };

//settings

inline std::string logoSettingsDirectory{ "C:/Users/LIAMF/source/repos/Lesthallen RPG/Debug/Lesthallen RPG/Main Menu/Settings/SettingsMenu.txt" };

//Settings Auto Save
inline std::string logoSettingsAutoSaveDirectory{ "C:/Users/LIAMF/source/repos/Lesthallen RPG/Debug/Lesthallen RPG/Main Menu/Settings/Settings 1/" };
inline std::string currentASSetting{ "Settings1On" };

//system settings
inline std::filesystem::path path = std::filesystem::current_path();
inline std::string currentPath = path.string();
inline bool firstTimeRun{ true };
inline bool autoSave{ true };
inline short systemLogLevel{ 1 }; //1 is highest, then 2, then 3 at the bottom
#endif