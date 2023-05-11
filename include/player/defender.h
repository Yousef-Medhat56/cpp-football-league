#ifndef DEFENDER_H
#define DEFENDER_H

#include "./player.h"

class Defender : public Player
{
private:
    int cleansheets_num;

public:
    // Constructor
    Defender(int matches_num);
    Defender(string player_name,int matches_num);

    // Getters
    int getCleansheetsNum();

    // Setters
    void increaseCleansheets();

    // other methods
   void printDetails();
};

#endif