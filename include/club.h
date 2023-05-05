#ifndef CLUB_H
#define CLUB_H
#include "./player/player.h"
#include "./manager.h"
#include "./match.h"

class Club
{
public:
    Club();
    virtual ~Club();
    void enterPlayers();
    void enterManager();
    void winMatch();
    void drawMatch();
    void loseMatch();
    void printDetails();
    void setName(string name);
    string getName();
    void setPoints(int points);
    int getPoints();
    void set_goalsFor(int goals_for);
    int get_goalsFor();
    void set_goalsAgainst(int goals_against);
    int get_goalsAgainst();

protected:
    string name;
    // Manager manager;
    // Player *players
    int points;
    int goals_for;
    int goals_against;
    // Match *matches;
private:
};

#endif // CLUB_H