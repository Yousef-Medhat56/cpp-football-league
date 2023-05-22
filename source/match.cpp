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
    this->home_cards_num = 0;
    this->away_cards_num = 0;
    this->home_cards_count = 0;
    this->away_cards_count = 0;
    this->home_cards_list = new Card *[3];
    this->away_cards_list = new Card *[3];

    // Home formation
    pickHomeFormation();

    // Away formation
    pickAwayFormation();
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

Player *Match::getValidPlayer(Player *main_player, Player *substitute_player)
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

void Match::pickHomeFormation()
{
    homeFormation.goalkeeper = getValidPlayer(home->getSquad()->getMainPlayers().goalkeeper, home->getSquad()->getSubstitutes().goalkeeper);
    homeFormation.defender = getValidPlayer(home->getSquad()->getMainPlayers().defender, home->getSquad()->getSubstitutes().defender);
    homeFormation.striker = getValidPlayer(home->getSquad()->getMainPlayers().striker, home->getSquad()->getSubstitutes().striker);
}

void Match::pickAwayFormation()
{
    awayFormation.goalkeeper = getValidPlayer(away->getSquad()->getMainPlayers().goalkeeper, away->getSquad()->getSubstitutes().goalkeeper);
    awayFormation.defender = getValidPlayer(away->getSquad()->getMainPlayers().defender, away->getSquad()->getSubstitutes().defender);
    awayFormation.striker = getValidPlayer(away->getSquad()->getMainPlayers().striker, away->getSquad()->getSubstitutes().striker);
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

void Match::enterCards(bool is_home_team)
{
    
    Club *club_obj = (is_home_team) ? &*home : &*away;
    Formation *team_formation = (is_home_team) ? &homeFormation : &awayFormation;
    int *cards_num = (is_home_team) ? &this->home_cards_num : &this->away_cards_num;
    int *cards_count = (is_home_team) ? &this->home_cards_count : &this->away_cards_count;
    Card **cards_list = (is_home_team) ? &*this->home_cards_list : &*this->away_cards_list;

    cout << "How many cards did " << club_obj->getName() << " get(0-3): ";
    cin >> *cards_num;

    if (*cards_num > 0)
    {
        while (*cards_count < *cards_num)
        {
            Card *new_card;

            printPlayerInCardsMenu(1, team_formation->goalkeeper, *cards_count, cards_list);
            printPlayerInCardsMenu(2, team_formation->defender, *cards_count, cards_list);
            printPlayerInCardsMenu(3, team_formation->striker, *cards_count, cards_list);

            cout << "Which player got the card: ";
            bool exit_loop;
            do
            {
                char c = getch();
                exit_loop = true;
                switch (c)
                {
                case '1':
                    if (!checkPlayerGotCard(team_formation->goalkeeper->getId(), *cards_count, cards_list))
                    {
                        cout << c << endl;
                        new_card = this->addCardToPlayer(team_formation->goalkeeper);
                    }
                    else
                        exit_loop = false;
                    break;
                case '2':
                    if (!checkPlayerGotCard(team_formation->defender->getId(), *cards_count, cards_list))
                    {
                        cout << c << endl;
                        new_card = this->addCardToPlayer(team_formation->defender);
                    }
                    else
                        exit_loop = false;
                    break;
                case '3':
                    if (!checkPlayerGotCard(team_formation->striker->getId(), *cards_count, cards_list))
                    {
                        cout << c << endl;
                        new_card = this->addCardToPlayer(team_formation->striker);
                    }
                    else
                        exit_loop = false;
                    break;

                default:
                    exit_loop = false;
                }
            } while (!exit_loop);
            cards_list[*cards_count] = new_card;
            *cards_count += 1;
        }
    }
}

Card *Match::addCardToPlayer(Player *player_ptr)
{
    Card *new_card = new Card(player_ptr->getId(), player_ptr->getClubId(), this->id, this->gameweek_id);
    this->chooseCardColor(new_card);
    player_ptr->addCard(new_card);
    return new_card;
}

void Match::chooseCardColor(Card *card)
{
    cout << "Is the card red (y/n): ";
    bool exit_loop;
    do
    {
        char c = getch();
        exit_loop = true;
        switch (c)
        {
        case 'y':
            cout << c << endl;
            card->setColor(true);
            break;
        case 'n':
            cout << c << endl;
            card->setColor(false);
            break;
        default:
            exit_loop = false;
        }
    } while (!exit_loop);
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
    this->enterCards(true);
    this->enterCards(false);
}

bool Match::checkPlayerGotCard(int player_id, int cards_count, Card **cards_list)
{
    if (cards_count > 0)
    {
        for (int i = 0; i < cards_count; i++)
        {
            if (player_id == cards_list[i]->getPlayerId())
                return true;
        }
    }
    return false;
}

void Match::printPlayerInCardsMenu(int choice_num, Player *player_ptr, int cards_count, Card **card_list)
{
    if (!checkPlayerGotCard(player_ptr->getId(), cards_count, card_list))
    {
        cout << choice_num << ". " << player_ptr->getName() << endl;
    }
}

Match::~Match()
{
    for (int i = 0; i < home_cards_count; i++)
        delete home_cards_list[i];
    delete[] home_cards_list;

    for (int i = 0; i < away_cards_count; i++)
        delete away_cards_list[i];
    delete[] away_cards_list;
}