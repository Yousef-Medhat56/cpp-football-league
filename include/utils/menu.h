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
    static void standings(League &league); //standings menu
    static void statistics(League &league); //statistics menu
    static void clubs(League &league); //Clubs info menu
    static void players(League &league); //Players info menu
    static void footer(League &league,function<void(League &league)> func);
};

#endif