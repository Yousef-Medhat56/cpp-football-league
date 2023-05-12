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
    string name;
    string position;
    int matches_played; // total number of matches that the player played
    int cards_count;    // total number of cards that the player has got
    Card **cards_list;

public:
    // Constructor
    Player(){};
    Player(int matches_num);
    Player(string player_name, int matches_num);
    ~Player();

    // Getters
    string getName();
    string getPosition();

    // Setters
    void setName(string name);
    void setPosition(string pos);

    // other methods
    virtual void printDetails();
    void addCard(bool is_red_card);
};

#endif