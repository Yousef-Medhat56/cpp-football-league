#ifndef MENU_H
#define MENU_H

#include <conio.h>
#include <functional>
#include "./console.h"
#include "../league.h"
#include "../../source/league.cpp"
using namespace std;
class Menu
{
public:
    Menu(){};

    static void header();
    static void main(League &league);
    static void footer(League &league,function<void(League &league)> func);
};

#endif