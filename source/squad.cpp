#include "../include/squad.h"

Squad::Squad()
{
    // Enter main players
    cout << "Enter main players: " << endl;
    cout << "===============================" << endl;

    this->mainPlayers.goalkeeper = new GoalKeeper();
    this->mainPlayers.defender = new Defender();
    this->mainPlayers.striker = new Striker();

    // Enter substitutes
    cout << "\nEnter substitute players: " << endl;
    cout << "===============================" << endl;

    this->subsitutes.goalkeeper = new GoalKeeper();
    this->subsitutes.defender = new Defender();
    this->subsitutes.striker = new Striker();
}

Players Squad::getMainPlayers()
{
    return this->mainPlayers;
}

Players Squad::getSubstitutes()
{
    return this->subsitutes;
}

void Squad::setMainPlayers(GoalKeeper *gk, Defender *def, Striker *str)
{
    this->mainPlayers.goalkeeper = gk;
    this->mainPlayers.defender = def;
    this->mainPlayers.striker = str;
}

void Squad::setSubstitutes(GoalKeeper *gk, Defender *def, Striker *str)
{
    this->subsitutes.goalkeeper = gk;
    this->subsitutes.defender = def;
    this->subsitutes.striker = str;
}

void Squad::printDetails()
{
    cout << "Main players info" << endl;
    cout << "===============================" << endl;
    this->mainPlayers.goalkeeper->printDetails();
    cout << endl;
    this->mainPlayers.defender->printDetails();
    cout << endl;
    this->mainPlayers.striker->printDetails();

    cout << "\nSubstitute players info" << endl;
    cout << "===============================" << endl;
    this->subsitutes.goalkeeper->printDetails();
    cout << endl;
    this->subsitutes.defender->printDetails();
    cout << endl;
    this->subsitutes.striker->printDetails();
}
Squad::~Squad()
{
    delete this->mainPlayers.goalkeeper;
    delete this->mainPlayers.defender;
    delete this->mainPlayers.striker;
    delete this->subsitutes.goalkeeper;
    delete this->subsitutes.defender;
    delete this->subsitutes.striker;
}
