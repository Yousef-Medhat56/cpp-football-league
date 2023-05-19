#include "../include/club.h"

Club::Club(int id)
{
    this->id = id;
    cout << "Club name: ";
    cin.clear();
    cin.sync();
    getline(cin, this->name);
    this->matches_played = 0;
    this->wins = 0;
    this->draws = 0;
    this->losses = 0;
    this->points = 0;
    this->goals_for = 0;
    this->goals_against = 0;
}

Club::Club(int id, string club_name)
{
    this->id = id;
    this->name = club_name;
    this->matches_played = 0;
    this->wins = 0;
    this->draws = 0;
    this->losses = 0;
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

void Club::enterSquad(int matches_num)
{
    this->squad = new Squad(this->id, matches_num);
}

void Club::winMatch()
{
    this->matches_played++;
    this->wins++;
    this->points += 3;
}

void Club::drawMatch()
{
    this->matches_played++;
    this->draws++;
    this->points++;
}

void Club::loseMatch()
{
    this->matches_played++;
    this->losses++;
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