#include "../../include/utils/validator.h"

template <class numericType>
void Validator::readNum(string message, numericType &input)
{
    while (cout << message && !(cin >> input))
    {
        cin.clear();                                                   // clear bad input flag
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard input
        Console::error("Invalid input; please re-enter.");
    }
}

template <class numericType>
void Validator::readPositiveNumOrZero(string message, numericType &input)
{
    bool non_negative = false;
    do
    {
        readNum<numericType>(message, input);
        if (input >= 0)
            non_negative = true;
        else
            Console::error("Invalid input; please enter non-negative integer.");
    } while (!non_negative);
}

template <class numericType>
void Validator::readPositiveNum(string message, numericType &input)
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
void Validator::readPositiveEvenNum(string message, numericType &input)
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
void Validator::readNumInRange(string message, numericType &input, numericType min, numericType max)
{
    bool in_range = false;
    do
    {
        readNum<numericType>(message, input);
        if (input >= min && input <= max)
            in_range = true;
        else
        {
            string err_message = "Invalid input; please enter value from " + to_string(min) + " to " + to_string(max);
            Console::error(err_message);
        }
    } while (!in_range);
}

void Validator::readNonEmptyStr(string message, string &input)
{
    bool is_empty = true;

    do
    {
        cout << message;
        cin.clear();
        cin.sync();
        getline(cin, input);
        if (input.length() > 0)
            is_empty = false;
        else
            Console::error("Invalid input; please re-enter.");

    } while (is_empty);
}
