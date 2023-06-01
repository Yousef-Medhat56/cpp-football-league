#ifndef LEAGUE_H
#define LEAGUE_H

#include <filesystem>
#include "./club.h"
#include "./gameweek.h"
#include "./utils/csv.h"
#include "../source/gameweek.cpp"
#include "./utils/validator.h"
#include "../source/utils/validator.cpp"
#include "../source/utils/csv.cpp"
class League
{
private:
    int clubs_num;     // total number of clubs
    int gameweeks_num; // total number of gameweeks
    int gameweek_count;
    int current_gameweek; // number of the current gameweek
    int matches_num;      // total number of matches in the league
    int matches_count;
    int matches_played; //number of played matches
    int matches_num_in_gameweek; // total number of matches in the gameweek
    Club **clubs_list;
    Gameweek **gameweeks_list;
    Match **matches_list;
    Player **players_list;

public:
    League();
    ~League();

    // Getters
    int getClubsNum();
    int getGameweeksNum();
    int getCurrentGameweekNum();
    Gameweek *getCurrentGameweek();

    // enter clubs names
    void enterClubsNames();

    // enter clubs info (Manager and squad)
    void enterClubsDetails();

    // add players to the players list
    void assignPlayersList();

    // create the schedule of matches
    void createMatchesSchedule();

    // enter matches' results of the current gameweek
    void enterCurrGameweekResults();

    // pick teams formations for the next gameweek
    void pickMatchesFormation();

    void printGameweeksTable(); // gameweeks table csv
    void printClubsTable();     // clubs table csv
    void printPlayersTable();   // players table csv
    void printStandingsTable(); // standings table csv

    // search for clubs
    void searchForClub();

    // find club index by name or id
    int findClubIndex();

    // search for players
    
    void searchForPlayer();
    // find player index by name or id
    int findPlayerIndex();

    // sort clubs list by points
    void sortClubsByPoints();

    // sort clubs list by club id
    void sortClubsById();

    // SORT PLAYERS

    // sort and print top strikers
    void printTopStrikers();
    // sort and print top defenders
    void printTopDefenders();
    // sort and print top goalkeepers
    void printTopGoalkeepers();
    // sort and print top carded players
    void printTopCarded();
    // sort players list by player id
    void sortPlayersById();
};

#endif // LEAGUE_H