#ifndef DEFENDER_H
#define DEFENDER_H

#include "./player.h"

class Defender : public Player
{
private:
    int cleansheets_num;

public:
    // Constructor
    Defender(int player_id, int club_id,int matches_num);
    Defender(int player_id, int club_id,string player_name,int matches_num);

    // Getters
    int getCleansheetsNum();

    // Setters
    void increaseCleansheets();

    // other methods
   void printDetails();
};

#endif