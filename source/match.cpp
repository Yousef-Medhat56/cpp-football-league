#include "../include/match.h"

Match::Match(int gameweek, Club *home, Club *away)
{
    this->gameweek_num = gameweek;
    this->home = home;
    this->away = away;
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

Club *Match::getHomeTeam()
{
    return this->home;
}

Club *Match::getAwayTeam()
{
    return this->away;
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
    cout << "Gameweek #" << this->gameweek_num << endl;
    cout << this->home->getName() << " " << home_goals << " - " << this->away->getName() << " " << away_goals << endl;
}
