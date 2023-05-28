#ifndef MATCH_H
#define MATCH_H

#include <conio.h>
using namespace std;
#include "./utils/validator.h"
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

    // Other methods

    // print match details
    void printDetails();

    // check if the main player can play the match or not, and return the valid player
    Player *getValidPlayer(Player *main_player, Player *substitute_player);

    // pick the team formation for the match
    void pickTeamFormation(bool is_home_team);

    // print the team formation
    void printTeamFormation(bool is_home_team);

    // increase number of matches played by the participated players in the match
    void incPlayersMatchesCount();
    
    // enter match results
    void enterResults();

    // enter cards
    void enterCards(bool is_home_team);

    // add card to a player
    Card *addCardToPlayer(Player *player_ptr, bool is_home_team);
    
    //print players in the cards menu
    void printPlayerInCardsMenu(int choice_num, Player *player_ptr, int club_cards_count, Card **club_card_list);
    
    //ask the user to choose if the card is red or not
    void chooseCardColor(Card *card, bool is_home_team);
    
    //check if the player has already got a card
    bool checkPlayerGotCard(int player_id, int club_cards_count, Card **club_card_list);
    
    //update goals statistics for players: goals for, goal against, cleansheets
    void updateGoalsStats();
    
    //determine which club won the match
    void determineWinner();
};

#endif