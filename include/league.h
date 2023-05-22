#ifndef LEAGUE_H
#define LEAGUE_H
#include "./club.h"
#include "./gameweek.h"
#include "../source/gameweek.cpp"
#include "./utils/validator.h"
#include "../source/utils/validator.cpp"

class League
{
public:
    League();
    League(int);
    virtual ~League();

    // Getters
    int getCurrentGameweek();
    int getClubsNum();
    int getGameweeksNum();
    int getMatchesNum();
    int getMatchesNumInGameweek();

    // Setters
    void setClubsNum(int clubs_num);
    void calcGameweeksNum();
    void calcMatchesNum();
    void calcMatchesNumInGameweek();

    // other
    void enterClubsNames();
    void enterClubsDetails();
    void createMatches();
    void printMatches();
    void enterCurrGameweekResults();
    void printCurrGameweekMatches();
    void createGameweeksSchedule();
    void printStandings();
    void printAllGameweeks();
    void printWinnerClub();
    void printBestGk();
    void printBestDefender();
    void printBestStriker();

private:
    int clubs_num;     // total number of clubs
    int gameweeks_num; // total number of gameweeks
    int gameweek_count;
    int current_gameweek; // number of the current gameweek
    int matches_num; // total number of matches in the league
    int matches_count;
    int matches_played;
    int matches_num_in_gameweek; // total number of matches in the gameweek
    Club **clubs;
    Gameweek **gameWeeks;
    Match **matches;
};

#endif // LEAGUE_H