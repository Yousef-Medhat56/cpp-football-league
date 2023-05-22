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

void Gameweek::addMatch(Match *new_match)
{
    if (matches_count < matches_num)
    {
        matches[matches_count] = new_match;
        matches_count++;
    }
}

Match **Gameweek::getMatches()
{
    return matches;
}
void Gameweek::enterMatchesResults()
{
    for (int i = 0; i < matches_num; i++)
    {
        cout << "Match #" << i + 1 << ": ";
        this->getMatches()[i]->enterResults();
    }
}
void Gameweek::printMatches()
{
     for (int i = 0; i < matches_num; i++)
    {
        cout << "Match #" << i + 1 << ": ";
        this->getMatches()[i]->printDetails();
        Console::divider();
        cout << endl;
    }
}