#ifndef MATCH_H
#define MATCH_H

#include <iostream>
#include <string>
using namespace std;

class Match
{
private:
    int gameweek_num;
    // Club home;
    // Club away;
    int home_goals;
    int away_goals;

public:
    // Constructor
    Match(int gameweek);

    // Getters
    int getGameWeekNum();
    int getHomeGoals();
    int getAwayGoals();

    // Setters
    void setGameWeekNum(int gameweek);
    void setHomeGoals(int goals);
    void setAwayGoals(int goals);

    // other methods
    void printDetails();
    // void enterResults;
};

#endif