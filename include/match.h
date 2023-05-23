#ifndef MATCH_H
#define MATCH_H

#include <conio.h>
using namespace std;
#include "./club.h"
#include "../source/club.cpp"

class Match
{
private:
    int id;
    int gameweek_id;
    bool is_finished;
    Club *home;
    Club *away;
    Formation homeFormation;
    Formation awayFormation;
    int home_goals;
    int away_goals;
    int home_cards_num;
    int away_cards_num;
    int home_cards_count;
    int away_cards_count;
    int home_yellow_cards;
    int away_yellow_cards;
    int home_red_cards;
    int away_red_cards;
    Card **home_cards_list;
    Card **away_cards_list;

public:
    // Constructor
    Match(int match_id, int gameweek_id, Club *home, Club *away);

    ~Match();
    // Getters
    int getGameWeekNum();
    int getHomeGoals();
    int getAwayGoals();
    Club *getHomeTeam();
    Club *getAwayTeam();
    Formation getHomeFormation();
    Formation getAwayFormation();
    bool isFinished();
    int getHomeCardsNum();
    int getAwayCardsNum();
    string getCardHoldersNames(bool is_home_team, bool is_red);
    int getHomeYellowCards();
    int getHomeRedCards();
    int getAwayYellowCards();
    int getAwayRedCards();

    // Setters
    void setGameWeekNum(int gameweek);
    void setHomeGoals(int goals);
    void setAwayGoals(int goals);

    // other methods
    void printDetails();
    void printTeamFormation(bool is_home_team);
    Player *getValidPlayer(Player *main_player, Player *substitute_player);
    void pickTeamFormation(bool is_home_team);
    void incPlayersMatchesCount(); //increase number of matches played by the players
    void enterResults();
    void enterCards(bool is_home_team);
    Card *addCardToPlayer(Player *player_ptr,bool is_home_team);
    void printPlayerInCardsMenu(int choice_num, Player *player_ptr, int club_cards_count, Card **club_card_list);
    void chooseCardColor(Card *card, bool is_home_team);
    bool checkPlayerGotCard(int player_id, int club_cards_count, Card **club_card_list);
    void updateGoalsStats();
    void determineWinner();
};

#endif