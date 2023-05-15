#ifndef GOALKEEPER_H
#define GOALKEEPER_H

#include "./player.h"

class GoalKeeper : public Player
{
private:
    int goals_against;
    int cleansheets_num;

public:
    // Constructor
    GoalKeeper(int player_id, int club_id, int matches_num);
    GoalKeeper(int player_id, int club_id, string player_name, int matches_num);

    // Getters
    int getGoalsAgainst();
    int getCleansheetsNum();

    // Setters
    void addGoalsAgainst(int goals);
    void increaseCleansheets();

    // other methods
    void printDetails();
};

#endif