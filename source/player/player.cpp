#include "../../include/player/player.h"

Player::Player(int player_id, int club_id, int matches_num)
{
    this->id = player_id;
    this->club_id = club_id;
    this->cards_count = 0;
    this->matches_played = 0;
    this->cards_list = new Card *[matches_num];
};

Player::Player(int player_id, int club_id, string player_name, int matches_num) : Player(player_id, club_id, matches_num)
{
    this->name = player_name;
};

Player::~Player()
{
    for (int i = 0; i < cards_count; i++)
    {
        delete cards_list[i];
    }
    delete[] cards_list;
}

// Getters
int Player::getId()
{
    return this->id;
}

int Player::getClubId()
{
    return this->club_id;
}
string Player::getName()
{
    return this->name;
}

string Player::getPosition()
{
    return this->position;
}

Card **Player::getCardsList()
{
    return this->cards_list;
}

int Player::getCardsCount()
{
    return this->cards_count;
}
// Setters
void Player::setName(string name)
{
    this->name = name;
}

void Player::setPosition(string pos)
{
    this->position = pos;
}

// print player details
void Player::printDetails()
{
    cout << this->position << " id: " << this->id << endl;
    cout << this->position << " name: " << this->name << endl;
    cout << this->position << " cards: " << this->cards_count << endl;
    // cout << "Player position: " << this->position << endl;
}

void Player::addCard(int match_id, int gameweek_id, bool is_red_card = false)
{
    cards_list[cards_count] = new Card(this->id, this->club_id, match_id, gameweek_id, is_red_card);
    this->cards_count++;
}

void Player::addCard(Card *card_ptr)
{
    cards_list[cards_count] = card_ptr;
    this->cards_count++;
}