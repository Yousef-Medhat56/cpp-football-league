#include "../include/squad.h"

Squad::Squad(int club_id, int matches_num)
{
    this->club_id = club_id;
    int player_id = -1;
    // Enter main players
    cout << "Enter main players: " << endl;
    cout << "===============================" << endl;

    this->mainPlayers.goalkeeper = new GoalKeeper(++player_id, club_id, matches_num);
    this->mainPlayers.defender = new Defender(++player_id, club_id, matches_num);
    this->mainPlayers.striker = new Striker(++player_id, club_id, matches_num);

    // Enter substitutes
    cout << "\nEnter substitute players: " << endl;
    cout << "===============================" << endl;

    this->substitutes.goalkeeper = new GoalKeeper(++player_id, club_id, matches_num);
    this->substitutes.goalkeeper->setIsMain(false);

    this->substitutes.defender = new Defender(++player_id, club_id, matches_num);
    this->substitutes.defender->setIsMain(false);

    this->substitutes.striker = new Striker(++player_id, club_id, matches_num);
    this->substitutes.striker->setIsMain(false);
}

Formation Squad::getMainPlayers()
{
    return this->mainPlayers;
}

Formation Squad::getSubstitutes()
{
    return this->substitutes;
}

void Squad::setMainPlayers(GoalKeeper *gk, Defender *def, Striker *str)
{
    this->mainPlayers.goalkeeper = gk;
    this->mainPlayers.defender = def;
    this->mainPlayers.striker = str;
}

void Squad::setSubstitutes(GoalKeeper *gk, Defender *def, Striker *str)
{
    this->substitutes.goalkeeper = gk;
    this->substitutes.defender = def;
    this->substitutes.striker = str;
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
    this->substitutes.goalkeeper->printDetails();
    cout << endl;
    this->substitutes.defender->printDetails();
    cout << endl;
    this->substitutes.striker->printDetails();
}
Squad::~Squad()
{
    delete this->mainPlayers.goalkeeper;
    delete this->mainPlayers.defender;
    delete this->mainPlayers.striker;
    delete this->substitutes.goalkeeper;
    delete this->substitutes.defender;
    delete this->substitutes.striker;
}
