#ifndef MATCH_H
#define MATCH_H

#include "./club.h"
#include "../source/club.cpp"

class Match
{
private:
    int gameweek_num;
    Club* home;
    Club* away;
    int home_goals;
    int away_goals;

public:
    // Constructor
    Match(int gameweek,Club* home, Club *away);

    // Getters
    int getGameWeekNum();
    int getHomeGoals();
    int getAwayGoals();
    Club* getHomeTeam();
    Club* getAwayTeam();

    // Setters
    void setGameWeekNum(int gameweek);
    void setHomeGoals(int goals);
    void setAwayGoals(int goals);

    // other methods
    void printDetails();
    // void enterResults;
};

#endif