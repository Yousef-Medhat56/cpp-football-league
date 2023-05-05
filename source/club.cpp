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

Club::Club(string club_name)
{
    this->name = club_name;
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
Manager *Club::getManager()
{
    return manager;
}
Squad *Club::getSquad()
{
    return squad;
}

void Club::enterManager()
{
    manager = new Manager();
}

void Club::enterSquad()
{
    this->squad = new Squad();
}

void Club::printDetails()
{
    cout << "Club name: " << this->name << endl;
    cout << "Points: " << this->points << endl;
    cout << "Goals for: " << this->goals_for << endl;
    cout << "Goals against: " << this->goals_against << endl;
}

Club::~Club()
{
    delete manager;
    delete squad;
}