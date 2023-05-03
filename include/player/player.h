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
    int shirt_num;

public:
    // Constructor
    Player();
    Player(string player_name, int player_num);

    // Getters
    string getName();
    string getPosition();
    int getShirtNum();

    // Setters
    void setName(string name);
    void setPosition(string pos);
    void setShirtNum(int num);

    // other methods
    virtual void printDetails();
};

#endif