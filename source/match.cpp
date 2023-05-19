#include "../include/match.h"

Match::Match(int match_id, int gameweek_id, Club *home, Club *away)
{
    this->id = match_id;
    this->gameweek_id = gameweek_id;
    this->home = home;
    this->away = away;
    this->is_finshed = false;
    this->home_goals = 0;
    this->away_goals = 0;

    // Home formation
    validateHomeFormation();

    // Away formation
    validateAwayFormation();
};

// Getters
int Match::getGameWeekNum()
{
    return this->gameweek_id;
}

int Match::getHomeGoals()
{
    return this->home_goals;
}

int Match::getAwayGoals()
{
    return this->away_goals;
}

Club *Match::getHomeTeam()
{
    return this->home;
}

Club *Match::getAwayTeam()
{
    return this->away;
}
Formation Match::getHomeFormation()
{
    return this->homeFormation;
}

Formation Match::getAwayFormation()
{
    return this->awayFormation;
}

// Setters
void Match::setGameWeekNum(int gameweek)
{
    this->gameweek_id = gameweek;
}

void Match::setHomeGoals(int goals)
{
    this->home_goals = goals;
}

void Match::setAwayGoals(int goals)
{
    this->away_goals = goals;
}

Player *Match::checkPlayerCards(Player *main_player, Player *substitute_player)
{

    int player_cards_count = main_player->getCardsCount();
    Card **player_cards = main_player->getCardsList();

    if (player_cards_count > 0)
    {
        Card *player_last_card = player_cards[player_cards_count - 1];

        if (player_last_card->isRed() && player_last_card->getGameweekId() + 1 == this->gameweek_id)
        {

            return substitute_player;
        }
        else if (player_cards_count > 1)
        {
            Card *player_last_card2 = player_cards[player_cards_count - 2];
            if (player_last_card->getGameweekId() + 1 == this->gameweek_id && player_last_card2->getGameweekId() + 2 == this->gameweek_id)
            {
                return substitute_player;
            }
        }
    }
    return main_player;
}

void Match::validateHomeFormation()
{
    this->homeFormation.goalkeeper = checkPlayerCards(this->home->getSquad()->getMainPlayers().goalkeeper, this->home->getSquad()->getSubstitutes().goalkeeper);
    this->homeFormation.defender = checkPlayerCards(this->home->getSquad()->getMainPlayers().defender, this->home->getSquad()->getSubstitutes().defender);
    this->homeFormation.striker = checkPlayerCards(this->home->getSquad()->getMainPlayers().striker, this->home->getSquad()->getSubstitutes().striker);
}

void Match::validateAwayFormation()
{
    this->awayFormation.goalkeeper = checkPlayerCards(this->away->getSquad()->getMainPlayers().goalkeeper, this->away->getSquad()->getSubstitutes().goalkeeper);
    this->awayFormation.defender = checkPlayerCards(this->away->getSquad()->getMainPlayers().defender, this->away->getSquad()->getSubstitutes().defender);
    this->awayFormation.striker = checkPlayerCards(this->away->getSquad()->getMainPlayers().striker, this->away->getSquad()->getSubstitutes().striker);
}

// print player details
void Match::printDetails()
{
    cout << "Gameweek #" << this->gameweek_id << endl;
    cout << "Match #" << this->id << endl;
    cout << this->home->getName() << " " << home_goals << " - " << this->away->getName() << " " << away_goals << endl;
}

void Match::printHomeFormation()
{
    cout << "Home Gk: " << this->homeFormation.goalkeeper->getName() << endl;
    cout << "Home Def: " << this->homeFormation.defender->getName() << endl;
    cout << "Home ST: " << this->homeFormation.striker->getName() << endl;
}

void Match::printAwayFormation()
{
    cout << "Away Gk: " << this->awayFormation.goalkeeper->getName() << endl;
    cout << "Away Def: " << this->awayFormation.defender->getName() << endl;
    cout << "Away ST: " << this->awayFormation.striker->getName() << endl;
}

void Match::determineWinner()
{
    if (home_goals > away_goals)
    {
        home->winMatch();
        away->loseMatch();
    }
    else if (home_goals == away_goals)
    {
        home->drawMatch();
        away->drawMatch();
    }
    else
    {
        home->loseMatch();
        away->winMatch();
    }
}

void Match::updateGoalsStats()
{
    // Home team
    home->addGoalsFor(home_goals);
    home->addGoalsAgainst(away_goals);
    homeFormation.striker->scoreGoals(home_goals);
    homeFormation.goalkeeper->addGoalsAgainst(away_goals);

    // Away team
    away->addGoalsFor(away_goals);
    away->addGoalsAgainst(home_goals);
    awayFormation.striker->scoreGoals(away_goals);
    awayFormation.goalkeeper->addGoalsAgainst(home_goals);

    // cleansheets
    if (away_goals == 0)
    {
        homeFormation.goalkeeper->increaseCleansheets();
        homeFormation.defender->increaseCleansheets();
    }
    else if (home_goals == 0)
    {
        awayFormation.goalkeeper->increaseCleansheets();
        awayFormation.defender->increaseCleansheets();
    }
}

void Match::enterResults()
{
    this->is_finshed = true;
    cout << home->getName() << " goals: ";
    cin >> home_goals;
    cout << away->getName() << " goals: ";
    cin >> away_goals;
    this->updateGoalsStats();
    this->determineWinner();
}