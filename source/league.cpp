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
        Club *new_club = new Club(i, club_name);
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

void League::createMatches()
{
    while (gameweek_count < gameweeks_num)
    {
        // First gameweek
        if (gameweek_count == 0)
        {
            Gameweek *first_gameweek = new Gameweek(gameweek_count, matches_num_in_gameweek);
            for (int i = 0; i < clubs_num / 2; i++)
            {
                Club *home = clubs[i];
                Club *away = clubs[clubs_num - i - 1];
                Match *new_match = new Match(matches_count, gameweek_count, home, away);
                matches[i] = new_match;
                first_gameweek->addMatch(new_match);
                matches_count++;
            }
            gameWeeks[0] = first_gameweek;
            gameweek_count++;
        }
        else
        {
            // first half of the gameweeks
            if (gameweek_count < gameweeks_num / 2)
            {
                Gameweek *new_gameweek = new Gameweek(gameweek_count, matches_num_in_gameweek);
                Match **last_gameweek_matches = gameWeeks[gameweek_count - 1]->getMatches();

                // first match in the gameweek
                Club *first_match_home = (gameweek_count % 2) ? clubs[clubs_num - 1] : last_gameweek_matches[matches_num_in_gameweek - 1]->getAwayTeam();
                Club *first_match_away = (gameweek_count % 2) ? last_gameweek_matches[matches_num_in_gameweek - 1]->getAwayTeam() : clubs[clubs_num - 1];
                Match *first_match = new Match(matches_count, gameweek_count, first_match_home, first_match_away);
                matches[matches_count++] = first_match;
                new_gameweek->addMatch(first_match);

                for (int i = matches_num_in_gameweek; i > 2; i--)
                {

                    Club *home = last_gameweek_matches[i - 2]->getAwayTeam();
                    Club *away = last_gameweek_matches[i - 1]->getHomeTeam();
                    Match *new_match = new Match(matches_count, gameweek_count, home, away);
                    matches[matches_count++] = new_match;
                    new_gameweek->addMatch(new_match);
                }

                // last match in the gameweek
                Club *last_match_home = (gameweek_count % 2) ? last_gameweek_matches[0]->getHomeTeam() : last_gameweek_matches[0]->getAwayTeam();
                Club *last_match_away = last_gameweek_matches[1]->getHomeTeam();
                Match *last_match = new Match(matches_count, gameweek_count, last_match_home, last_match_away);
                matches[matches_count++] = last_match;
                new_gameweek->addMatch(last_match);

                gameWeeks[gameweek_count] = new_gameweek;
                gameweek_count++;
            }
            else
            {
                // second half of the gameweeks
                for (int i = 0; i < gameweeks_num / 2; i++)
                {
                    Gameweek *new_gameweek = new Gameweek(gameweek_count + 1, matches_num_in_gameweek);
                    for (int j = 0; j < matches_num_in_gameweek; j++)
                    {
                        Club *home = gameWeeks[i]->getMatches()[j]->getAwayTeam();
                        Club *away = gameWeeks[i]->getMatches()[j]->getHomeTeam();
                        Match *new_match = new Match(matches_count, gameweek_count, home, away);
                        matches[matches_count++] = new_match;
                        new_gameweek->addMatch(new_match);
                    }
                    gameWeeks[gameweek_count] = new_gameweek;
                    gameweek_count++;
                }
            }
        }
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