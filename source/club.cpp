#include "../include/club.h"

Club::Club(int id)
{
    this->id = id;
    Validator::readNonEmptyStr("Club name: ", this->name);
    this->matches_played = 0;
    this->wins = 0;
    this->draws = 0;
    this->losses = 0;
    this->points = 0;
    this->goals_for = 0;
    this->goals_against = 0;
    this->players_list = new Player *[6];
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
    this->players_list = new Player *[6];
}

void Club::setName(string name)
{
    this->name = name;
}
void Club::setPoints(int points)
{

    this->points += points;
}
void Club::addGoalsFor(int goals_for)
{

    this->goals_for += goals_for;
}
void Club::addGoalsAgainst(int goals_against)
{

    this->goals_against += goals_against;
}
string Club::getName()
{
    return this->name;
}
int Club::getId()
{
    return this->id;
}
int Club::getPoints()
{
    return this->points;
}
int Club::getGoalsFor()
{
    return this->goals_for;
}
int Club::getGoalsAgainst()
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

int Club::getWins()
{
    return this->wins;
}
int Club::getDraws()
{
    return this->draws;
}
int Club::getLosses()
{
    return this->losses;
}
Player **Club::getPlayersList()
{
    return this->players_list;
}

void Club::enterManager()
{
    manager = new Manager();
}

void Club::enterSquad(int matches_num)
{
    this->squad = new Squad(this->id, matches_num);

    // add players to the players list
    this->players_list[0] = squad->getMainPlayers().goalkeeper;
    this->players_list[1] = squad->getMainPlayers().defender;
    this->players_list[2] = squad->getMainPlayers().striker;
    this->players_list[3] = squad->getSubstitutes().goalkeeper;
    this->players_list[4] = squad->getSubstitutes().defender;
    this->players_list[5] = squad->getSubstitutes().striker;
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
    cout << "Club id: " << this->id << endl;
    cout << "Club name: " << this->name << endl;
    cout << "Points: " << this->points << endl;
    cout << "Goals for: " << this->goals_for << endl;
    cout << "Goals against: " << this->goals_against << endl;
    // print players
    for (int i = 0; i < 6; i++)
    {
        string player_name = this->players_list[i]->getName();
        string player_pos = this->players_list[i]->getPosition();
        string player_role = this->players_list[i]->isMainPlayer() ? "Main" : "Substitute";
        cout << player_role << " " << player_pos << ": " << player_name << endl;
    }
}

int Club::getTotalCards()
{
    int total_cards = 0;
    for (int i = 0; i < 6; i++)
    {
        Player *player_ptr = this->players_list[i];
        total_cards += player_ptr->getCardsCount();
    }
    return total_cards;
}

int Club::getTotalRedCards()
{
    int red_cards = 0;
    for (int i = 0; i < 6; i++)
    {
        Player *player_ptr = this->players_list[i];
        red_cards += player_ptr->getRedCardsCount();
    }
    return red_cards;
}

int Club::getTotalYellowCards()
{
    int yellow_cards = 0;
    for (int i = 0; i < 6; i++)
    {
        Player *player_ptr = this->players_list[i];
        yellow_cards += player_ptr->getYellowCardsCount();
    }
    return yellow_cards;
}

Club::~Club()
{
    delete manager;
    delete squad;
    delete[] players_list;
}