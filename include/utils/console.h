#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <string>
#include <windows.h>
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
};

#endif