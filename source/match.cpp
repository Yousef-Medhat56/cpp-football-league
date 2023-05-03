#include "../include/match.h"

Match::Match(int gameweek)
{
    this->gameweek_num = gameweek;
    this->home_goals = 0;
    this->away_goals = 0;
};

// Getters
int Match::getGameWeekNum()
{
    return this->gameweek_num;
}

int Match::getHomeGoals()
{
    return this->home_goals;
}

int Match::getAwayGoals()
{
    return this->away_goals;
}

// Setters
void Match::setGameWeekNum(int gameweek)
{
    this->gameweek_num = gameweek;
}

void Match::setHomeGoals(int goals)
{
    this->home_goals = goals;
}

void Match::setAwayGoals(int goals)
{
    this->away_goals = goals;
}

// print player details
void Match::printDetails()
{
    cout << "Gameweek " << this->gameweek_num << endl;
    cout << "Home: " << this->home_goals << endl;
    cout << "Away: " << this->home_goals << endl;
}
