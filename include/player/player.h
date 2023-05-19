#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
using namespace std;

#include "../card.h"
#include "../../source/card.cpp"
class Player
{
protected:
    int id;
    int club_id;
    string name;
    string position;
    int matches_played; // total number of matches that the player played
    int cards_count;    // total number of cards that the player has got
    Card **cards_list;

public:
    // Constructor
    Player(int player_id, int club_id, int matches_num);
    Player(int player_id, int club_id, string player_name, int matches_num);
    ~Player();

    // Getters
    int getId();
    int getClubId();
    string getName();
    string getPosition();
    int getCardsCount();
    Card **getCardsList();

    // Setters
    void setName(string name);
    void setPosition(string pos);

    // other methods
    virtual void printDetails();
    void addCard(int match_id, int gameweek_id, bool is_red_card);
    virtual void scoreGoals(int goals){};
    virtual void addGoalsAgainst(int goals){};
    virtual void increaseCleansheets(){};
};

#endif