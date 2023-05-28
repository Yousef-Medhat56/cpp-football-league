#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
using namespace std;

#include "../card.h"
#include "../../source/card.cpp"
#include "../utils/validator.h"
class Player
{
protected:
    int id;
    int club_id;
    bool is_main_player;
    string name;
    string position;
    int matches_played; // total number of matches that the player played
    int cards_count;    // total number of cards that the player has got
    int yellow_cards_count;
    int red_cards_count;
    Card **cards_list;

public:
    // Constructor
    Player(int player_id, int club_id, int matches_num);
    Player(int player_id, int club_id, string player_name, int matches_num);
    ~Player();

    // Getters
    int getId();
    int getClubId();
    bool isMainPlayer();
    string getName();
    string getPosition();
    int getCardsCount();
    int getYellowCardsCount();
    int getRedCardsCount();
    int getMatchesPlayed();
    Card **getCardsList();

    // Setters
    void setIsMain(bool);
    void setName(string name);
    void setPosition(string pos);

    // Other methods

    virtual void printDetails(string club_name);
    void playNewMatch(); // increase matches_played attribute by 1

    void addCard(int match_id, int gameweek_id, bool is_red_card); // creates a card object, then add it to the cards_list
    void addCard(Card *card_ptr);                                  // get a card object and add it the cards_list

    // check if card is red, increase the red_cards_count by 1 and so if the card is yellow
    void checkCardColor(Card *card_ptr);

    // Virtual methods
    virtual void scoreGoals(int goals){};
    virtual void addGoalsAgainst(int goals){};
    virtual void increaseCleansheets(){};
    virtual int getScoredGoals() { return 0; };
    virtual int getGoalsAgainst() { return 0; };
    virtual int getCleansheetsNum() { return 0; };
};

#endif