#ifndef STRIKER_H
#define STRIKER_H

#include "./player.h"

class Striker : public Player
{
private:
    int goals_scored;

public:
    // Constructor
    Striker(int player_id, int club_id, int matches_num);
    Striker(int player_id, int club_id, string player_name, int matches_num);

    // Getters
    int getScoredGoals();

    // Setters
    void scoreGoals(int goals);

    // other methods
    void printDetails(string club_name);
};

#endif