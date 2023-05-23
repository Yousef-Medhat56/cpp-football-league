#ifndef MENU_H
#define MENU_H

#include <conio.h>
#include <functional>
#include "../league.h"
#include "../../source/league.cpp"
using namespace std;
class Menu
{
public:
    Menu(){};

    static void header();
    static void main(League &league);
    static void gameweeks(League &league); //gameweeks menu
    static void clubs(League &league); //Clubs info menu
    static void footer(League &league,function<void(League &league)> func);
};

#endif