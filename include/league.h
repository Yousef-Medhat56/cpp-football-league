#ifndef LEAGUE_H
#define LEAGUE_H
#include "./club.h"
#include "./gameweek.h"
#include "./utils/csv.h"
#include "../source/gameweek.cpp"
#include "./utils/validator.h"
#include "../source/utils/validator.cpp"
#include "../source/utils/csv.cpp"

class League
{
public:
    League();
    League(int);
    virtual ~League();

    // Getters
    int getCurrentGameweekNum();
    int getClubsNum();
    int getGameweeksNum();
    int getMatchesNum();
    int getMatchesNumInGameweek();
    Gameweek *getCurrentGameweek();

    // Setters
    void setClubsNum(int clubs_num);
    void calcGameweeksNum();
    void calcMatchesNum();
    void calcMatchesNumInGameweek();
    void assignPlayersList();

    // other
    void enterClubsNames();
    void enterClubsDetails();
    void createMatches();
    void printMatches();
    void enterCurrGameweekResults();
    void printCurrGameweekMatches();
    void pickMatchesFormation(); // pick matches formation of the next gameweek
    void createGameweeksSchedule();
    void printGameweeksTable();
    void printClubsTable(); //clubs table csv
    void printPlayersTable(); //players table csv
    void printStandingsTable(); //standings table csv
    void printStandings();
    void printAllGameweeks();
    void printWinnerClub();
    void printBestGk();
    void printBestDefender();
    void printBestStriker();

    // search for clubs
    int findClubIndex();
    void searchForClub();

    // search for players
    int findPlayerIndex();
    void searchForPlayer();

    //sort clubs list by points
    void sortClubsByPoints();
    //sort clubs list by club_id
    void sortClubsById();

    //SORT PLAYERS
    //sort and print top strikers
    void printTopStrikers();
    //sort and print top defenders
    void printTopDefenders();
    //sort and print top goalkeepers
    void printTopGoalkeepers();
    //sort and print top carded players
    void printTopCarded();
    //sort players list by player id
    void sortPlayersById();


private:
    int clubs_num;     // total number of clubs
    int gameweeks_num; // total number of gameweeks
    int gameweek_count;
    int current_gameweek; // number of the current gameweek
    int matches_num;      // total number of matches in the league
    int matches_count;
    int matches_played;
    int matches_num_in_gameweek; // total number of matches in the gameweek
    Club **clubs;
    Gameweek **gameWeeks;
    Match **matches;
    Player **players_list;
};

#endif // LEAGUE_H