#include "../include/club.h"

Club::Club()
{
    cout << "Club name: ";
    cin.clear();
    cin.sync();
    getline(cin, this->name);
    this->points = 0;
    this->goals_for = 0;
    this->goals_against = 0;
}

void Club::setName(string name)
{
    this->name = name;
}
void Club::setPoints(int points)
{

    this->points += points;
}
void Club::set_goalsFor(int goals_for)
{

    this->goals_for += goals_for;
}
void Club::set_goalsAgainst(int goals_against)
{

    this->goals_against += goals_against;
}
string Club::getName()
{
    return this->name;
}
int Club::getPoints()
{
    return this->points;
}
int Club::get_goalsFor()
{
    return this->goals_for;
}
int Club::get_goalsAgainst()
{
    return this->goals_against;
}
Manager* Club::getManager()
{
    return manager;
}

void Club::enterManager()
{
    manager = new Manager();
}

Club::~Club()
{
    delete manager;
}