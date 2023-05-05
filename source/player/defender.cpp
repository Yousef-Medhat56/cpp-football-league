#include "../../include/player/defender.h"

Defender::Defender() : Player()
{
    this->position = "Defender";

    // read player name
    cout << this->position << " name: ";
    cin.clear();
    cin.sync();
    getline(cin, this->name);
    
    this->cleansheets_num = 0;
};

Defender::Defender(string player_name) : Player(player_name)
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