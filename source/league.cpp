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
    players_list = new Player *[clubs_num * 6];
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
    assignPlayersList();
}

// push players objects to the players list
void League::assignPlayersList()
{
    for (int i = 0; i < clubs_num; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            int player_index = j + (i * 6);
            this->players_list[player_index] = clubs[i]->getPlayersList()[j];
        }
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

int League::getClubsNum()
{
    return this->clubs_num;
}
int League::getCurrentGameweekNum()
{
    return this->current_gameweek;
}

void League::enterCurrGameweekResults()
{

    gameWeeks[current_gameweek]->enterMatchesResults();
    current_gameweek++;
    this->pickMatchesFormation();
}

void League::pickMatchesFormation()
{
    if (current_gameweek < gameweeks_num - 1)
    {
        for (int i = 0; i < matches_num_in_gameweek; i++)
        {
            // home formation
            gameWeeks[current_gameweek]->getMatches()[i]->pickTeamFormation(true);
            // away formation
            gameWeeks[current_gameweek]->getMatches()[i]->pickTeamFormation(false);
        }
    }
}

Gameweek *League::getCurrentGameweek()
{
    return gameWeeks[current_gameweek];
}
void League::printGameweeksTable()
{
    CSV table("gameweeks");

    for (int i = 0; i < gameweeks_num; i++)
    {
        string gameweek_num = to_string(i + 1);
        table.addCell("Gameweek #" + gameweek_num);
        table.newRow();

        // table header
        table.addCell("Match");
        table.addCell("Home goals");
        table.addCell("Away goals");
        table.addCell("Home yellow cards");
        table.addCell("Home yellow carded players");
        table.addCell("Away yellow cards");
        table.addCell("Away yellow carded players");
        table.addCell("Home red cards");
        table.addCell("Home red carded players");
        table.addCell("Away red cards");
        table.addCell("Away red carded players");

        table.newRow();
        for (int j = 0; j < matches_num_in_gameweek; j++)
        {
            Match *match_ptr = gameWeeks[i]->getMatches()[j];
            bool is_finished = match_ptr->isFinished(); // is the match finished or not

            string home_name = match_ptr->getHomeTeam()->getName();
            string away_name = match_ptr->getAwayTeam()->getName();
            string home_goals = is_finished ? to_string(match_ptr->getHomeGoals()) : " - ";
            string away_goals = is_finished ? to_string(match_ptr->getAwayGoals()) : " - ";
            string home_yellow_cards = is_finished ? to_string(match_ptr->getHomeYellowCards()) : " - ";
            string away_yellow_cards = is_finished ? to_string(match_ptr->getAwayYellowCards()) : " - ";
            string home_yellow_carded_players = match_ptr->getHomeYellowCards() ? match_ptr->getCardHoldersNames(true, false) : " - ";
            string away_yellow_carded_players = match_ptr->getAwayYellowCards() ? match_ptr->getCardHoldersNames(false, false) : " - ";
            string home_red_cards = is_finished ? to_string(match_ptr->getHomeRedCards()) : " - ";
            string away_red_cards = is_finished ? to_string(match_ptr->getAwayRedCards()) : " - ";
            string home_red_carded_players = match_ptr->getHomeRedCards() ? match_ptr->getCardHoldersNames(true, true) : " - ";
            string away_red_carded_players = match_ptr->getAwayRedCards() ? match_ptr->getCardHoldersNames(false, true) : " - ";

            table.addCell(home_name + " - " + away_name);
            table.addCell(home_goals);
            table.addCell(away_goals);
            table.addCell(home_yellow_cards);
            table.addCell(home_yellow_carded_players);
            table.addCell(away_yellow_cards);
            table.addCell(away_yellow_carded_players);
            table.addCell(home_red_cards);
            table.addCell(home_red_carded_players);
            table.addCell(away_red_cards);
            table.addCell(away_red_carded_players);
            table.newRow();
        }
    }
}

void League::printClubsTable()
{
    CSV table("clubs");

    // table header
    table.addCell("Club id");
    table.addCell("Club name");
    // table.addCell("Manager");
    table.addCell("Main GoalKeeper");
    table.addCell("Main Defender");
    table.addCell("Main Striker");
    table.addCell("Substitute GoalKeeper");
    table.addCell("Substitute Defender");
    table.addCell("Substitute Striker");
    table.newRow();

    for (int i = 0; i < clubs_num; i++)
    {
        int club_id = clubs[i]->getId();
        string club_name = clubs[i]->getName();
        // string manager_name = clubs[i]->getManager()->getName();

        table.addCell(club_id);
        table.addCell(club_name);
        // table.addCell(manager_name);

        // print players
        for (int j = 0; j < 6; j++)
        {
            string player_name = clubs[i]->getPlayersList()[j]->getName();
            table.addCell(player_name);
        }

        table.newRow();
    }
}
void League::printPlayersTable()
{
    CSV table("players");

    // table header
    table.addCell("Player id");
    table.addCell("Player name");
    table.addCell("Club");
    table.addCell("Position");
    table.addCell("Role");
    table.addCell("Matches played");
    table.addCell("Goals for");
    table.addCell("Goals against");
    table.addCell("Cleansheets");
    table.addCell("Total cards");
    table.addCell("Yellow cards");
    table.addCell("Red cards");

    table.newRow();

    for (int i = 0; i < clubs_num; i++)
    {
        int club_id = clubs[i]->getId();
        string club_name = clubs[i]->getName();

        // players
        for (int j = 0; j < 6; j++)
        {
            Player *player_ptr = clubs[i]->getPlayersList()[j];
            int player_id = player_ptr->getId() + (club_id * 6);
            string player_name = player_ptr->getName();
            string player_pos = player_ptr->getPosition();
            string role = player_ptr->isMainPlayer() ? "Main" : "Substitute";
            int matches_played = player_ptr->getMatchesPlayed();
            string goals_for = player_pos == "Striker" ? to_string(player_ptr->getScoredGoals()) : " - ";
            string goals_against = player_pos == "Goalkeeper" ? to_string(player_ptr->getGoalsAgainst()) : " - ";
            string cleansheets = player_pos == "Goalkeeper" || player_pos == "Defender" ? to_string(player_ptr->getCleansheetsNum()) : " - ";
            int cards_count = player_ptr->getCardsCount();
            int y_cards_count = player_ptr->getYellowCardsCount();
            int r_cards_count = player_ptr->getRedCardsCount();

            table.addCell(player_id);
            table.addCell(player_name);
            table.addCell(club_name);
            table.addCell(player_pos);
            table.addCell(role);
            table.addCell(matches_played);
            table.addCell(goals_for);
            table.addCell(goals_against);
            table.addCell(cleansheets);
            table.addCell(cards_count);
            table.addCell(y_cards_count);
            table.addCell(r_cards_count);

            table.newRow();
        }
    }
}

int League::findClubIndex()
{

    string val;
    cout << "Enter club name or id: ";
    cin.clear();
    cin.sync();
    getline(cin, val);

    bool found = false;
    int club_index;

    // try to convert val to int
    try
    {

        // check if Val after converting it to int still have the same length
        if (to_string(stoi(val)).length() < val.length())
            throw "Val is not integer";

        else if (stoi(val) <= clubs_num)
        {
            club_index = stoi(val);
            found = true;
        }
    }

    catch (...)
    {
        for (int i = 0; i < clubs_num; i++)
        {
            if (clubs[i]->getName() == val)
            {
                club_index = i;
                found = true;
                break;
            }
        }
        if (!found)
        {
            Console::error("\nClub doesn't exist");
            club_index = -1;
        }
        return club_index;
    }
    if (!found)
    {
        Console::error("\nClub doesn't exist");
        club_index = -1;
    }
    return club_index;
}

void League::searchForClub()
{
    // find the club index
    int index = this->findClubIndex();
    if (index >= 0)
    {
        cout << endl;
        clubs[index]->printDetails();
        Console::success("\nClub has been found successfully");
    }
}

int League::findPlayerIndex()
{

    string val;
    cout << "Enter player name or id: ";
    cin.clear();
    cin.sync();
    getline(cin, val);

    bool found = false;
    int player_index;
    int players_num = clubs_num * 6;

    // try to convert val to int
    try
    {

        // check if Val after converting it to int still have the same length
        if (to_string(stoi(val)).length() < val.length())
            throw "Val is not integer";

        else if (stoi(val) <= players_num)
        {
            player_index = stoi(val);
            found = true;
        }
    }

    catch (...)
    {
        for (int i = 0; i < players_num; i++)
        {
            if (players_list[i]->getName() == val)
            {
                player_index = i;
                found = true;
                break;
            }
        }
        if (!found)
        {
            Console::error("\nPlayer doesn't exist");
            player_index = -1;
        }
        return player_index;
    }
    if (!found)
    {
        Console::error("\nPlayer doesn't exist");
        player_index = -1;
    }
    return player_index;
}

void League::searchForPlayer()
{
    // find the player index
    int index = this->findPlayerIndex();
    Player *player_ptr = players_list[index];
    string club_name = clubs[player_ptr->getClubId()]->getName();

    if (index >= 0)
    {
        cout << endl;
        player_ptr->printDetails(club_name);
        Console::success("\nPlayer has been found successfully");
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
    delete[] players_list;
}
