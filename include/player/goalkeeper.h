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
    GoalKeeper();
    GoalKeeper(string player_name);

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