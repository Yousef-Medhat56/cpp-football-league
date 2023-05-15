#ifndef GAMEWEEK_H
#define GAMEWEEK_H
#include "./match.h"
#include "../source/match.cpp"

class Gameweek
{
public:
    Gameweek(int gameweek_id, int matches_num);
    virtual ~Gameweek();
    int getId();
    int getMatchesPlayed();
    void addMatch(Match *new_match);
    Match **getMatches();
    void printMatches();

private:
    int id;
    int matches_num;
    int matches_count;
    int matches_played;
    Match **matches;
};

#endif // GAMEWEEK_H