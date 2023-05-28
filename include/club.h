#ifndef CLUB_H
#define CLUB_H

#include "./squad.h"
#include "./manager.h"

#include "../source/squad.cpp"
#include "../source/manager.cpp"

class Club
{
private:
    int id;
    string name;
    int matches_played;
    int wins;
    int draws;
    int losses;
    int points;
    int goals_for;
    int goals_against;
    Manager *manager;
    Squad *squad;
    Player **players_list;

public:
    Club(int id);
    Club(int id, string club_name);
    virtual ~Club();

    // Getters

    string getName();
    int getId();
    int getPoints();
    int getGoalsFor();
    int getGoalsAgainst();
    int getWins();
    int getDraws();
    int getLosses();
    Manager *getManager();
    Squad *getSquad();
    Player **getPlayersList();

    // Setters
    void setName(string name);
    
    void setPoints(int points);
    
    // Other functions

    // enter manager
    void enterManager();

    // enter players
    void enterSquad(int matches_num);

    //increase goals_for
    void addGoalsFor(int goals_for);

    //increase goals_against
    void addGoalsAgainst(int goals_against);

    void winMatch();
    void drawMatch();
    void loseMatch();
    void printDetails();
};

#endif // CLUB_H