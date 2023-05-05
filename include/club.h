#ifndef CLUB_H
#define CLUB_H

#include "./player/player.h"
#include "./manager.h"
#include "./match.h"

#include "../source/player/player.cpp"
#include "../source/manager.cpp"
#include "../source/match.cpp"

class Club
{
public:
    Club();
    virtual ~Club();
    // Setters and Getters
    void setName(string name);
    string getName();
    void setPoints(int points);
    int getPoints();
    void set_goalsFor(int goals_for);
    int get_goalsFor();
    void set_goalsAgainst(int goals_against);
    int get_goalsAgainst();
    Manager* getManager();

    //Other functions
    void enterManager();
    void enterPlayers();
    void winMatch();
    void drawMatch();
    void loseMatch();
    void printDetails();

protected:
    string name;
    int points;
    int goals_for;
    int goals_against;
    Manager *manager;
    // Player *players;
    // Match *matches;
private:
};

#endif // CLUB_H