#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <limits>
using namespace std;

#include "./console.h"
#include "../../source/utils/console.cpp"
class Validator
{
public:
    Validator(){};

    // read input that its datatype is number
    template <class numericType> // int or float
    static void readNum(string message, numericType &input);

    template <class numericType>
    // read positive number or zero from terminal
    static void readPositiveNumOrZero(string message, numericType &input);

    template <class numericType>
    // read positive number from terminal
    static void readPositiveNum(string message, numericType &input);

    template <class numericType>
    // read positive even number from terminal
    static void readPositiveEvenNum(string message, numericType &input);

    template <class numericType>
    // read positive even number from terminal
    static void readNumInRange(string message, numericType &input, numericType min, numericType max);

    // read non empty string
    static void readNonEmptyStr(string message, string &input);
};

#endif