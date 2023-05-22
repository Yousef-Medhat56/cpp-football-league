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

template <class numericType>
void Console::readNum(string message, numericType &input)
{
    while (cout << message && !(cin >> input))
    {
        cin.clear();                                                   // clear bad input flag
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard input
        Console::error("Invalid input; please re-enter.");
    }
}

template <class numericType>
void Console::readPositiveNum(string message, numericType &input)
{
    bool is_positive = false;
    do
    {
        readNum<numericType>(message, input);
        if (input > 0)
            is_positive = true;
        else
            Console::error("Invalid input; please enter positive integer.");
    } while (!is_positive);
}

template <class numericType>
void Console::readPositiveEvenNum(string message, numericType &input)
{
    bool is_even = false;
    do
    {
        readPositiveNum<numericType>(message, input);
        if (input % 2 == 0)
            is_even = true;
        else
            Console::error("Invalid input; please enter even integer.");
    } while (!is_even);
}

template <class numericType>
void Console::readNumInRange(string message, numericType &input, numericType min, numericType max)
{
    bool in_range = false;
    do
    {
        readNum<numericType>(message, input);
        if (input >= min && input <= max)
            in_range = true;
        else
        {
            string err_message = "Invalid input; please enter value from " + min + " to " + max;
            Console::error(err_message);
        }
    } while (!in_range);
}
