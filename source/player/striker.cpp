#include "../../include/player/striker.h"

Striker::Striker(int player_id, int club_id, int matches_num) : Player(player_id, club_id, matches_num)
{
    this->position = "Striker";

    // read player name
    cout << this->position << " name: ";
    cin.clear();
    cin.sync();
    getline(cin, this->name);
    this->goals_scored = 0;
};

Striker::Striker(int player_id, int club_id, string player_name, int matches_num) : Player(player_id, club_id, player_name, matches_num)
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
void Striker::printDetails(string club_name)
{
    Player::printDetails(club_name);
    cout << "Goals scored: " << this->goals_scored << endl;
}