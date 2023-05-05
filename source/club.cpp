#include "../include/club.h"

Club::Club()
{
    cout<<"Club name:";
    cin.clear();
    cin.sync();
    getline(cin, this->name);
    cout<<"\nPoints : ";
    cin>>points;
    cout<<"\nGoals for: ";
    cin>>goals_for;
    cout<<"\nGoals Against: ";
    cin>>goals_against;
}

Club::~Club()
{
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