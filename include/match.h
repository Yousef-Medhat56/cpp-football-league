#ifndef MATCH_H
#define MATCH_H

#include "./club.h"
#include "../source/club.cpp"

class Match
{
private:
    int id;
    int gameweek_id;
    bool is_finshed;
    Club *home;
    Club *away;
    Formation homeFormation;
    Formation awayFormation;
    int home_goals;
    int away_goals;

public:
    // Constructor
    Match(int match_id, int gameweek_id, Club *home, Club *away);

    // Getters
    int getGameWeekNum();
    int getHomeGoals();
    int getAwayGoals();
    Club *getHomeTeam();
    Club *getAwayTeam();
    Formation getHomeFormation();
    Formation getAwayFormation();

    // Setters
    void setGameWeekNum(int gameweek);
    void setHomeGoals(int goals);
    void setAwayGoals(int goals);

    // other methods
    void printDetails();
    void printHomeFormation();
    void printAwayFormation();
    Player * checkPlayerCards( Player *main_player, Player *substitute_player);
    void validateHomeFormation();
    void validateAwayFormation();
    void enterResults();
    void updateGoalsStats();
    void determineWinner();
};

#endif