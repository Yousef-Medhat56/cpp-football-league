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
    this->homeFormation.goalkeeper = home->getSquad()->getMainPlayers().goalkeeper;
    this->homeFormation.defender = home->getSquad()->getMainPlayers().defender;
    this->homeFormation.striker = home->getSquad()->getMainPlayers().striker;
    validateHomeFormation();

    // Away formation
    this->awayFormation.goalkeeper = away->getSquad()->getMainPlayers().goalkeeper;
    this->awayFormation.defender = away->getSquad()->getMainPlayers().defender;
    this->awayFormation.striker = away->getSquad()->getMainPlayers().striker;
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

void Match::checkPlayerCards(Player *const &formation_player, Player *main_player, Player *substitute_player)
{

    int player_cards_count = main_player->getCardsCount();
    Card **player_cards = main_player->getCardsList();

    if (player_cards_count > 0)
    {
        Card *player_last_card = player_cards[player_cards_count - 1];

        if (player_last_card->isRed() && player_last_card->getGameweekId() + 1 == this->gameweek_id)
        {
            *formation_player = *substitute_player;
            return;
        }
        else if (player_cards_count > 1)
        {
            Card *player_last_card2 = player_cards[player_cards_count - 2];
            if (player_last_card->getGameweekId() + 1 == this->gameweek_id && player_last_card2->getGameweekId() + 2 == this->gameweek_id)
            {
                *formation_player = *substitute_player;
                return;
            }
        }
    }
}

void Match::validateHomeFormation()
{
    checkPlayerCards(getHomeFormation().goalkeeper, this->home->getSquad()->getMainPlayers().goalkeeper, this->home->getSquad()->getSubstitutes().goalkeeper);
    checkPlayerCards(getHomeFormation().defender, this->home->getSquad()->getMainPlayers().defender, this->home->getSquad()->getSubstitutes().defender);
    checkPlayerCards(getHomeFormation().striker, this->home->getSquad()->getMainPlayers().striker, this->home->getSquad()->getSubstitutes().striker);
}

void Match::validateAwayFormation()
{
    checkPlayerCards(getAwayFormation().goalkeeper, this->away->getSquad()->getMainPlayers().goalkeeper, this->away->getSquad()->getSubstitutes().goalkeeper);
    checkPlayerCards(getAwayFormation().defender, this->away->getSquad()->getMainPlayers().defender, this->away->getSquad()->getSubstitutes().defender);
    checkPlayerCards(getAwayFormation().striker, this->away->getSquad()->getMainPlayers().striker, this->away->getSquad()->getSubstitutes().striker);
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