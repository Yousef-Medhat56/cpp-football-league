#include "../include/utils/console.h"

void Console::white()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 15); // change text color to white
}
void Console::success(std::string message)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 10); // change text color to green
    cout << message << endl;
    SetConsoleTextAttribute(hConsole, 15); // change text color to white
}

void Console::error(std::string message)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 12); // change text color to red
    cout << message << endl;
    SetConsoleTextAttribute(hConsole, 15); // change text color to white
}
void Console::divider()
{
    cout << "===================================" << endl;
}

void Console::clear()
{
    system("cls");
}

void Console::sleep()
{
    Sleep(1000); // sleep the terminal for 1 second
}