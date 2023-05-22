#ifndef CONSOLE_H
#define CONSOLE_H


#include <iostream>
#include <string>
#include <windows.h>
#include <limits>
using namespace std;
class Console
{
public:
    Console(){};

    // change text color to white
    static void white();

    // print success message
    static void success(string message);

    // print error message
    static void error(string message);

    // print divider
    static void divider();

    // clear the terminal
    static void clear();

    // sleep the terminal
    static void sleep();

    //read input that its datatype is number
    template <class numericType> //int or float
    static void readNum(string message, numericType &input);
    
    template <class numericType>
    //read positive number from terminal
    static void readPositiveNum(string message, numericType &input);
    
    template <class numericType>
    //read positive even number from terminal
    static void readPositiveEvenNum(string message, numericType &input);
};

#endif