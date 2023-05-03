#include "../../include/player/defender.h"

Defender::Defender() : Player()
{
    this->position = "Defender";
    this->cleansheets_num = 0;
};

Defender::Defender(string player_name, int player_num) : Player(player_name, player_num)
{
    this->position = "Defender";
    this->cleansheets_num = 0;
};

// Getters
int Defender::getCleansheetsNum()
{
    return this->cleansheets_num;
}

// Setters
void Defender::increaseCleansheets()
{
    this->cleansheets_num++;
}

// print goalkeeper details
void Defender::printDetails()
{
    Player::printDetails();
    cout << "Clean sheets number: " << this->cleansheets_num << endl;
}