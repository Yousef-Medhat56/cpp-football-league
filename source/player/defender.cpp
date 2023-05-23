#include "../../include/player/defender.h"

Defender::Defender(int player_id, int club_id, int matches_num) : Player(player_id, club_id, matches_num)
{
    this->position = "Defender";

    // read player name
    cout << this->position << " name: ";
    cin.clear();
    cin.sync();
    getline(cin, this->name);
    
    this->cleansheets_num = 0;
};

Defender::Defender(int player_id, int club_id, string player_name, int matches_num) : Player(player_id, club_id, player_name, matches_num)
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
void Defender::printDetails(string club_name)
{
    Player::printDetails(club_name);
    cout << "Clean sheets number: " << this->cleansheets_num << endl;
}