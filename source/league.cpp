#include "../include/league.h"

League::League()
{
    cout << "Enter number of clubs: ";
    cin >> this->clubs_num;
    gameweek_count = 0;
    current_gameweek = 0;
    matches_count = 0;
    matches_played = 0;
    gameweeks_num = clubs_num * 2 - 2;
    matches_num = gameweeks_num * clubs_num / 2;
    matches_num_in_gameweek = clubs_num / 2;
    gameWeeks = new Gameweek *[gameweeks_num];
    clubs = new Club *[clubs_num];
    matches = new Match *[matches_num];
}

void League::enterClubsNames()
{
    for (int i = 0; i < clubs_num; i++)
    {
        string club_name;
        cout << "Enter Club #" << i + 1 << " name: ";
        cin >> club_name;
        Club *new_club = new Club(club_name);
        clubs[i] = new_club;
    }
}

void League::enterClubsDetails()
{
    for (int i = 0; i < clubs_num; i++)
    {
        cout << "\n## Club " << clubs[i]->getName() << endl;
        clubs[i]->enterSquad(matches_num);
    }
}

void League::printMatches()
{
    for (int i = 0; i < matches_count; i++)
    {
        cout << "----" << endl;
        matches[i]->printDetails();
    }
}
League::~League()
{
    for (int i = 0; i < clubs_num; i++)
    {
        delete clubs[i];
    }
    delete[] clubs;
    for (int i = 0; i < matches_count; i++)
    {
        delete matches[i];
    }
    delete[] matches;
    for (int i = 0; i < gameweek_count; i++)
    {
        delete gameWeeks[i];
    }
    delete[] gameWeeks;
}

int League::getClubsNum()
{
    return this->clubs_num;
}