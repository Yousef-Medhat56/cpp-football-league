#include "../../include/player/goalkeeper.h"

GoalKeeper::GoalKeeper(int player_id, int club_id, int matches_num) : Player(player_id, club_id, matches_num)
{
    this->position = "Goalkeeper";

    // read player name
    cout << this->position << " name: ";
    cin.clear();
    cin.sync();
    getline(cin, this->name);

    this->goals_against = 0;
    this->cleansheets_num = 0;
};

GoalKeeper::GoalKeeper(int player_id, int club_id, string player_name, int matches_num) : Player(player_id, club_id, player_name, matches_num)
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
void GoalKeeper::printDetails(string club_name)
{
    Player::printDetails(club_name);
    cout << "Goals against: " << this->goals_against << endl;
    cout << "Clean sheets number: " << this->cleansheets_num << endl;
}