#include "../../include/player/striker.h"

Striker::Striker() : Player()
{
    this->position = "Striker";
    this->goals_scored = 0;
};

Striker::Striker(string player_name, int player_num) : Player(player_name, player_num)
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