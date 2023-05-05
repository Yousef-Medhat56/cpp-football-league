#ifndef STRIKER_H
#define STRIKER_H

#include "./player.h"

class Striker : public Player
{
private:
    int goals_scored;

public:
    // Constructor
    Striker();
    Striker(string player_name);

    // Getters
    int getScoredGoals();

    // Setters
    void scoreGoals(int goals);

    // other methods
   void printDetails();
};

#endif