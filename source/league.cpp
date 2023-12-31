#include "../include/league.h"

League::League()
{
    Validator::readPositiveEvenNum("Enter number of clubs in the league: ", this->clubs_num);
    gameweek_count = 0;
    current_gameweek = 0;
    matches_count = 0;
    matches_played = 0;
    gameweeks_num = clubs_num * 2 - 2;
    matches_num = gameweeks_num * clubs_num / 2;
    matches_num_in_gameweek = clubs_num / 2;
    gameweeks_list = new Gameweek *[gameweeks_num];
    clubs_list = new Club *[clubs_num];
    matches_list = new Match *[matches_num];
    players_list = new Player *[clubs_num * 6];
}

void League::enterClubsNames()
{
    cout<<endl;
    for (int i = 0; i < clubs_num; i++)
    {
        string club_name;
        string message = "Club #" + to_string(i + 1) + " name: ";
        Validator::readNonEmptyStr(message, club_name);
        Club *new_club = new Club(i, club_name);
        clubs_list[i] = new_club;
    }
}

void League::enterClubsDetails()
{
    for (int i = 0; i < clubs_num; i++)
    {
        cout << "\n- " << clubs_list[i]->getName() << " Club Info" << endl;
        Console::divider();
        clubs_list[i]->enterManager();
        cout << endl;
        clubs_list[i]->enterSquad(matches_num);
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
            this->players_list[player_index] = clubs_list[i]->getPlayersList()[j];
        }
    }
}
void League::createMatchesSchedule()
{
    while (gameweek_count < gameweeks_num)
    {
        // First gameweek
        if (gameweek_count == 0)
        {
            Gameweek *first_gameweek = new Gameweek(gameweek_count, matches_num_in_gameweek);
            for (int i = 0; i < clubs_num / 2; i++)
            {
                Club *home = clubs_list[i];
                Club *away = clubs_list[clubs_num - i - 1];
                Match *new_match = new Match(matches_count, gameweek_count, home, away);
                matches_list[i] = new_match;
                first_gameweek->addMatch(new_match);
                matches_count++;
            }
            gameweeks_list[0] = first_gameweek;
            gameweek_count++;
        }
        else
        {
            // first half of the gameweeks
            if (gameweek_count < gameweeks_num / 2)
            {
                Gameweek *new_gameweek = new Gameweek(gameweek_count, matches_num_in_gameweek);
                Match **last_gameweek_matches = gameweeks_list[gameweek_count - 1]->getMatches();

                // first match in the gameweek
                Club *first_match_home = (gameweek_count % 2) ? clubs_list[clubs_num - 1] : last_gameweek_matches[matches_num_in_gameweek - 1]->getAwayTeam();
                Club *first_match_away = (gameweek_count % 2) ? last_gameweek_matches[matches_num_in_gameweek - 1]->getAwayTeam() : clubs_list[clubs_num - 1];
                Match *first_match = new Match(matches_count, gameweek_count, first_match_home, first_match_away);
                matches_list[matches_count++] = first_match;
                new_gameweek->addMatch(first_match);

                for (int i = matches_num_in_gameweek; i > 2; i--)
                {

                    Club *home = last_gameweek_matches[i - 2]->getAwayTeam();
                    Club *away = last_gameweek_matches[i - 1]->getHomeTeam();
                    Match *new_match = new Match(matches_count, gameweek_count, home, away);
                    matches_list[matches_count++] = new_match;
                    new_gameweek->addMatch(new_match);
                }

                // last match in the gameweek
                Club *last_match_home = (gameweek_count % 2) ? last_gameweek_matches[0]->getHomeTeam() : last_gameweek_matches[0]->getAwayTeam();
                Club *last_match_away = last_gameweek_matches[1]->getHomeTeam();
                Match *last_match = new Match(matches_count, gameweek_count, last_match_home, last_match_away);
                matches_list[matches_count++] = last_match;
                new_gameweek->addMatch(last_match);

                gameweeks_list[gameweek_count] = new_gameweek;
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
                        Club *home = gameweeks_list[i]->getMatches()[j]->getAwayTeam();
                        Club *away = gameweeks_list[i]->getMatches()[j]->getHomeTeam();
                        Match *new_match = new Match(matches_count, gameweek_count, home, away);
                        matches_list[matches_count++] = new_match;
                        new_gameweek->addMatch(new_match);
                    }
                    gameweeks_list[gameweek_count] = new_gameweek;
                    gameweek_count++;
                }
            }
        }
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
int League::getGameweeksNum()
{
    return this->gameweeks_num;
}

void League::enterCurrGameweekResults()
{
    gameweeks_list[current_gameweek]->enterMatchesResults();
    matches_played += matches_num_in_gameweek;
    current_gameweek++;
    this->pickMatchesFormation();
}

void League::pickMatchesFormation()
{
    if (current_gameweek < gameweeks_num)
    {
        for (int i = 0; i < matches_num_in_gameweek; i++)
        {
            // home formation
            gameweeks_list[current_gameweek]->getMatches()[i]->pickTeamFormation(true);
            // away formation
            gameweeks_list[current_gameweek]->getMatches()[i]->pickTeamFormation(false);
        }
    }
}

Gameweek *League::getCurrentGameweek()
{
    return gameweeks_list[current_gameweek];
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
        table.addCell("Home formation");
        table.addCell("Away formation");
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
            Match *match_ptr = gameweeks_list[i]->getMatches()[j];
            bool is_finished = match_ptr->isFinished(); // is the match finished or not
            string home_name = match_ptr->getHomeTeam()->getName();
            string away_name = match_ptr->getAwayTeam()->getName();
            string home_goals = is_finished ? to_string(match_ptr->getHomeGoals()) : " - ";
            string away_goals = is_finished ? to_string(match_ptr->getAwayGoals()) : " - ";
            string home_form = i <= current_gameweek ? match_ptr->getFormationPlayersNames(true) : " - ";
            string away_form = i <= current_gameweek ? match_ptr->getFormationPlayersNames(false) : " - ";
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
            table.addCell(home_form);
            table.addCell(away_form);
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
    string dir_path = filesystem::current_path().generic_string();
    Console::success("Gameweeks table has been created \nin " + dir_path + "/sheets/" + table.getFileName() + ".csv");
}

void League::printClubsTable()
{
    CSV table("clubs");

    // table header
    table.addCell("Club id");
    table.addCell("Club name");
    table.addCell("Manager");
    table.addCell("Main GoalKeeper");
    table.addCell("Main Defender");
    table.addCell("Main Striker");
    table.addCell("Substitute GoalKeeper");
    table.addCell("Substitute Defender");
    table.addCell("Substitute Striker");
    table.newRow();

    for (int i = 0; i < clubs_num; i++)
    {
        int club_id = clubs_list[i]->getId();
        string club_name = clubs_list[i]->getName();
        string manager_name = clubs_list[i]->getManager()->getName();

        table.addCell(club_id);
        table.addCell(club_name);
        table.addCell(manager_name);

        // print players
        for (int j = 0; j < 6; j++)
        {
            string player_name = clubs_list[i]->getPlayersList()[j]->getName();
            table.addCell(player_name);
        }

        table.newRow();
    }

    string dir_path = filesystem::current_path().generic_string();
    Console::success("Clubs table has been created \nin " + dir_path + "/sheets/" + table.getFileName() + ".csv");
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
        int club_id = clubs_list[i]->getId();
        string club_name = clubs_list[i]->getName();

        // players
        for (int j = 0; j < 6; j++)
        {
            Player *player_ptr = clubs_list[i]->getPlayersList()[j];
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

    string dir_path = filesystem::current_path().generic_string();
    Console::success("Players table has been created \nin " + dir_path + "/sheets/" + table.getFileName() + ".csv");
}

int League::findClubIndex()
{

    string val;
    Validator::readNonEmptyStr("Enter club name or id: ", val);
    bool found = false;
    int club_index;

    // try to convert val to int
    try
    {

        // check if Val after converting it to int still have the same length
        if (to_string(stoi(val)).length() < val.length())
            throw "Val is not integer";

        // check if the input could be the club_id
        else if (stoi(val) < clubs_num)
        {
            club_index = stoi(val);
            found = true;
        }
    }

    catch (...)
    {
        for (int i = 0; i < clubs_num; i++)
        {
            if (clubs_list[i]->getName() == val)
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
        clubs_list[index]->printDetails();
        Console::success("\nClub has been found successfully");
    }
}

int League::findPlayerIndex()
{

    string val;
    Validator::readNonEmptyStr("Enter player name or id: ", val);
    bool found = false;
    int player_index;
    int players_num = clubs_num * 6;

    // try to convert val to int
    try
    {

        // check if Val after converting it to int still have the same length
        if (to_string(stoi(val)).length() < val.length())
            throw "Val is not integer";

        // check if the input could be the player_id
        else if (stoi(val) < players_num)
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

    if (index >= 0)
    {
        Player *player_ptr = players_list[index];
        string club_name = clubs_list[player_ptr->getClubId()]->getName();
        cout << endl;
        player_ptr->printDetails(club_name);
        Console::success("\nPlayer has been found successfully");
    }
}

void League::sortClubsByPoints()
{
    int max;
    Club *temp;
    for (int i = 0; i < clubs_num - 1; i++)
    {
        max = i;
        for (int j = i + 1; j < clubs_num; j++)
            if (clubs_list[j]->getPoints() > clubs_list[max]->getPoints())
                max = j;

            // if the points are equal, sort by goals difference
            else if (clubs_list[j]->getPoints() == clubs_list[max]->getPoints())
            {
                int club1_goals_diff = clubs_list[j]->getGoalsFor() - clubs_list[j]->getGoalsAgainst();
                int club2_goals_diff = clubs_list[max]->getGoalsFor() - clubs_list[max]->getGoalsAgainst();
                if (club1_goals_diff > club2_goals_diff)
                    max = j;
            }

        temp = clubs_list[i];
        clubs_list[i] = clubs_list[max];
        clubs_list[max] = temp;
    }
}

void League::sortClubsById()
{
    int min;
    Club *temp;
    for (int i = 0; i < clubs_num - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < clubs_num; j++)
            if (clubs_list[j]->getId() < clubs_list[min]->getId())
                min = j;

        temp = clubs_list[i];
        clubs_list[i] = clubs_list[min];
        clubs_list[min] = temp;
    }
}

void League::printStandingsTable()
{
    // sort clubs by points
    this->sortClubsByPoints();

    CSV table("standings");

    // table header
    table.addCell("Club id");
    table.addCell("Club name");
    table.addCell("Points");
    table.addCell("Goals diff.");
    table.addCell("Goals for");
    table.addCell("Goals against");
    table.addCell("Wins");
    table.addCell("Draws");
    table.addCell("Losses");
    table.addCell("Total cards");
    table.addCell("Yellow cards");
    table.addCell("Red cards");
    table.newRow();

    for (int i = 0; i < clubs_num; i++)
    {
        int id = clubs_list[i]->getId();
        string name = clubs_list[i]->getName();
        int points = clubs_list[i]->getPoints();
        int goals_for = clubs_list[i]->getGoalsFor();
        int goals_against = clubs_list[i]->getGoalsAgainst();
        int goals_diff = goals_for - goals_against;
        int wins = clubs_list[i]->getWins();
        int draws = clubs_list[i]->getDraws();
        int losses = clubs_list[i]->getLosses();
        int total_cards = clubs_list[i]->getTotalCards();
        int yellow_cards = clubs_list[i]->getTotalYellowCards();
        int red_cards = clubs_list[i]->getTotalRedCards();

        table.addCell(id);
        table.addCell(name);
        table.addCell(points);
        table.addCell(goals_diff);
        table.addCell(goals_for);
        table.addCell(goals_against);
        table.addCell(wins);
        table.addCell(draws);
        table.addCell(losses);
        table.addCell(total_cards);
        table.addCell(yellow_cards);
        table.addCell(red_cards);
        table.newRow();
    }
    // sort clubs by their id
    this->sortClubsById();

    string dir_path = filesystem::current_path().generic_string();
    Console::success("Standings table has been created \nin " + dir_path + "/sheets/" + table.getFileName() + ".csv");
}

void League::printTopStrikers()
{
    int strikers_num = clubs_num * 2;
    Player *strikers_list[strikers_num];

    // create strikers list
    for (int i = 0; i < clubs_num; i++)
    {
        Player *main_st = clubs_list[i]->getSquad()->getMainPlayers().striker;
        Player *substitue_st = clubs_list[i]->getSquad()->getSubstitutes().striker;
        strikers_list[i * 2] = main_st;
        strikers_list[i * 2 + 1] = substitue_st;
    }

    // sort strikers by scored goals
    int max;
    Player *temp;
    for (int i = 0; i < strikers_num - 1; i++)
    {
        max = i;
        for (int j = i + 1; j < strikers_num; j++)
            if (strikers_list[j]->getScoredGoals() > strikers_list[max]->getScoredGoals())
                max = j;

        temp = strikers_list[i];
        strikers_list[i] = strikers_list[max];
        strikers_list[max] = temp;
    }

    // print top strikers
    int counter = 0;
    int printed_players = 0;
    while (counter < strikers_num)
    {
        Player *player_ptr = strikers_list[counter];

        if (player_ptr->getMatchesPlayed() > 0 && player_ptr->getScoredGoals() > 0)
        {
            int club_id = player_ptr->getClubId();
            string club_name = clubs_list[club_id]->getName();
            player_ptr->printDetails(club_name);
            Console::divider();
            cout << endl;
            printed_players++;
        }

        counter++;

        if (printed_players == 3)
            break;
        if (counter == strikers_num - 1 && printed_players == 0)
            Console::error("There are no enough data");
    }
}

void League::printTopDefenders()
{
    int defenders_num = clubs_num * 2;
    Player *defenders_list[defenders_num];

    // create defenders list
    for (int i = 0; i < clubs_num; i++)
    {
        Player *main_def = clubs_list[i]->getSquad()->getMainPlayers().defender;
        Player *substitue_def = clubs_list[i]->getSquad()->getSubstitutes().defender;
        defenders_list[i * 2] = main_def;
        defenders_list[i * 2 + 1] = substitue_def;
    }

    // sort defenders by cleansheets
    int max;
    Player *temp;
    for (int i = 0; i < defenders_num - 1; i++)
    {
        max = i;
        for (int j = i + 1; j < defenders_num; j++)
            if (defenders_list[j]->getCleansheetsNum() > defenders_list[max]->getCleansheetsNum())
                max = j;

        temp = defenders_list[i];
        defenders_list[i] = defenders_list[max];
        defenders_list[max] = temp;
    }

    // print top defenders
    int counter = 0;
    int printed_players = 0;
    while (counter < defenders_num)
    {
        Player *player_ptr = defenders_list[counter];

        if (player_ptr->getMatchesPlayed() > 0 > 0 && player_ptr->getCleansheetsNum() > 0)
        {
            int club_id = player_ptr->getClubId();
            string club_name = clubs_list[club_id]->getName();
            player_ptr->printDetails(club_name);
            Console::divider();
            cout << endl;
            printed_players++;
        }

        counter++;

        if (printed_players == 3)
            break;
        if (counter == defenders_num - 1 && printed_players == 0)
            Console::error("There are no enough data");
    }
}
void League::printTopGoalkeepers()
{
    int goalkeepers_num = clubs_num * 2;
    Player *goalkeepers_list[goalkeepers_num];

    // create goalkeepers list
    for (int i = 0; i < clubs_num; i++)
    {
        Player *main_gk = clubs_list[i]->getSquad()->getMainPlayers().goalkeeper;
        Player *substitue_gk = clubs_list[i]->getSquad()->getSubstitutes().goalkeeper;
        goalkeepers_list[i * 2] = main_gk;
        goalkeepers_list[i * 2 + 1] = substitue_gk;
    }

    // sort goalkeepers by goals against asc
    int min;
    Player *temp;
    for (int i = 0; i < goalkeepers_num - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < goalkeepers_num; j++)
            if (goalkeepers_list[j]->getGoalsAgainst() < goalkeepers_list[min]->getGoalsAgainst())
                min = j;
            // if the against goals are equal, sort by cleansheets
            else if (goalkeepers_list[j]->getGoalsAgainst() == goalkeepers_list[min]->getCleansheetsNum())
            {
                if (goalkeepers_list[j]->getCleansheetsNum() > goalkeepers_list[min]->getCleansheetsNum())
                    min = j;
            }

        temp = goalkeepers_list[i];
        goalkeepers_list[i] = goalkeepers_list[min];
        goalkeepers_list[min] = temp;
    }

    // print top goalkeepers
    int counter = 0;
    int printed_players = 0;
    while (counter < goalkeepers_num)
    {
        Player *player_ptr = goalkeepers_list[counter];

        if (player_ptr->getMatchesPlayed() > 0)
        {
            int club_id = player_ptr->getClubId();
            string club_name = clubs_list[club_id]->getName();
            player_ptr->printDetails(club_name);
            Console::divider();
            cout << endl;
            printed_players++;
        }

        counter++;

        if (printed_players == 3)
            break;
        if (counter == goalkeepers_num - 1 && printed_players == 0)
            Console::error("There are no enough data");
    }
}

void League::printTopCarded()
{
    int players_num = clubs_num * 6;
    int max;
    Player *temp;

    // sort players by cards count
    for (int i = 0; i < players_num; i++)
    {
        max = i;
        for (int j = i + 1; j < players_num; j++)
            if (players_list[j]->getCardsCount() > players_list[max]->getCardsCount())
                max = j;
            // if the cards count are equal, sort by red cards count
            else if (players_list[j]->getCardsCount() == players_list[max]->getCardsCount())
            {
                if (players_list[j]->getRedCardsCount() > players_list[max]->getRedCardsCount())
                    max = j;
            }
        temp = players_list[i];
        players_list[i] = players_list[max];
        players_list[max] = temp;
    }

    // print top carded players
    int counter = 0;
    int printed_players = 0;
    while (counter < players_num)
    {
        Player *player_ptr = players_list[counter];

        if (player_ptr->getMatchesPlayed() > 0 && player_ptr->getCardsCount())
        {
            int club_id = player_ptr->getClubId();
            string club_name = clubs_list[club_id]->getName();
            player_ptr->printDetails(club_name);
            Console::divider();
            cout << endl;
            printed_players++;
        }

        counter++;

        if (printed_players == 3)
            break;
        if (counter == players_num - 1 && printed_players == 0)
            Console::error("There are no carded players");
    }

    // sort players list by the player id
    this->sortPlayersById();
}
void League::sortPlayersById()
{
    int players_num = clubs_num * 6;
    int min;
    Player *temp;
    for (int i = 0; i < players_num; i++)
    {
        min = i;
        for (int j = i + 1; j < players_num; j++)
            if (players_list[j]->getId() < players_list[min]->getId())
                min = j;

        temp = players_list[i];
        players_list[i] = players_list[min];
        players_list[min] = temp;
    }
}

League::~League()
{
    for (int i = 0; i < clubs_num; i++)
    {
        delete clubs_list[i];
    }
    delete[] clubs_list;
    for (int i = 0; i < matches_count; i++)
    {
        delete matches_list[i];
    }
    delete[] matches_list;
    for (int i = 0; i < gameweek_count; i++)
    {
        delete gameweeks_list[i];
    }
    delete[] gameweeks_list;
    delete[] players_list;
}
