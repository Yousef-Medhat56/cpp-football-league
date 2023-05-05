#include "../../include/player/striker.h"

Striker::Striker() : Player()
{
    this->position = "Striker";

    //read player name
    cout << this->position << " name: ";
    cin.clear();
    cin.sync();
    getline(cin, this->name);
    this->goals_scored = 0;
};

Striker::Striker(string player_name) : Player(player_name)
{
    this->position = "Striker";
    this->goals_scored = 0;
};

// Getters
int Striker::getScoredGoals()
{
    return this->goals_scored;
}

// Setters
void Striker::scoreGoals(int goals)
{
    this->goals_scored += goals;
}

// print goalkeeper details
void Striker::printDetails()
{
    Player::printDetails();
    cout << "Goals scored: " << this->goals_scored << endl;
}