#include "../include/gameweek.h"

Gameweek::Gameweek(int gameweek_id, int matches_num)
{
    id = gameweek_id;
    this->matches_num = matches_num;
    matches_count = 0;
    matches_played = 0;
    matches = new Match *[matches_num];
}

Gameweek::~Gameweek()
{
    for (int i = 0; i < matches_count; i++)
    {
        delete matches[i];
    }
    delete[] matches;
}

int Gameweek::getId()
{
    return this->id;
}

int Gameweek::getMatchesPlayed()
{
    return this->matches_played;
}

void Gameweek::addMatch(Match *new_match )
{
    if (matches_count < matches_num)
    {
        matches[matches_count] = new_match;
        matches_count++;
    }
}

Match **Gameweek::getMatches(){
    return matches;
}
// void Gameweek::printMatches() {
//     cout << "Matches for gameweek " << id << ":\n";
//     for (int i = 0; i < arr_size; i++) {
//         if (matches[i] != nullptr) {
//             cout << "- Match " << i + 1 << ":\n";
//             matches[i]->printDetails();
//         }
//     }}