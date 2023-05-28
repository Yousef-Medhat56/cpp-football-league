#ifndef GAMEWEEK_H
#define GAMEWEEK_H

#include "./utils/console.h"
#include "./match.h"
#include "../source/match.cpp"

class Gameweek
{

private:
    int id;
    int matches_num;
    int matches_count;
    int matches_played;
    Match **matches;

public:
    Gameweek(int gameweek_id, int matches_num);
    virtual ~Gameweek();

    // Getters
    int getId();
    int getMatchesPlayed();
    Match **getMatches();

    // enter matches results
    void enterMatchesResults();
    
    // add a match object to the matches list
    void addMatch(Match *new_match);

    void printMatches();
};

#endif // GAMEWEEK_H