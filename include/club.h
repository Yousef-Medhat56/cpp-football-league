#ifndef CLUB_H
#define CLUB_H

#include "./squad.h"
#include "./manager.h"

#include "../source/squad.cpp"
#include "../source/manager.cpp"

class Club
{
public:
    Club();
    Club(string club_name);
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
    Manager *getManager();
    Squad *getSquad();

    // Other functions
    void enterManager();
    void enterSquad();
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
    Squad *squad;
};

#endif // CLUB_H