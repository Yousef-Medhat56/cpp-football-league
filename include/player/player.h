#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
using namespace std;

class Player
{
protected:
    string name;
    string position;

public:
    // Constructor
    Player();
    Player(string player_name);

    // Getters
    string getName();
    string getPosition();

    // Setters
    void setName(string name);
    void setPosition(string pos);

    // other methods
    virtual void printDetails();
};

#endif