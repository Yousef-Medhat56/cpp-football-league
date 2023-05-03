#include "../../include/player/goalkeeper.h"

GoalKeeper::GoalKeeper() : Player()
{
    this->position = "Goalkeeper";
    this->goals_against = 0;
    this->cleansheets_num = 0;
};

GoalKeeper::GoalKeeper(string player_name, int player_num) : Player(player_name, player_num)
{
    this->position = "Goalkeeper";
    this->goals_against = 0;
    this->cleansheets_num = 0;
};

// Getters
int GoalKeeper::getGoalsAgainst()
{
    return this->goals_against;
}
int GoalKeeper::getCleansheetsNum()
{
    return this->cleansheets_num;
}

// Setters
void GoalKeeper::addGoalsAgainst(int goals)
{
    this->goals_against += goals;
}
void GoalKeeper::increaseCleansheets()
{
    this->cleansheets_num++;
}

// print goalkeeper details
void GoalKeeper::printDetails()
{
    Player::printDetails();
    cout << "Goals against: " << this->goals_against << endl;
    cout << "Clean sheets number: " << this->cleansheets_num << endl;
}