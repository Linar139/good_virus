#include <windows.h>

int main(){
    FreeConsole();
    MessageBoxW(NULL, L"ВЫ ЗАРАЗИЛИСЬ ВИРУСОМ!", L"ПРЕДУПРЕЖДЕНИЕ", MB_ICONWARNING | MB_OK);
    system("start https://linar139.github.io/good_virus/");
    return 0;
}