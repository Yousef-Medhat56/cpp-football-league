#include "../../include/player/player.h"

Player::Player(int matches_num)
{
    cards_count = 0;
    matches_played = 0;
    this->cards_list = new Card *[matches_num];
};

Player::Player(string player_name, int matches_num) : Player(matches_num)
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
string Player::getName()
{
    return this->name;
}

string Player::getPosition()
{
    return this->position;
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
    cout << this->position << " name: " << this->name << endl;
    cout<<this->position << " cards: " << this->cards_count<<endl;
    // cout << "Player position: " << this->position << endl;
}

void Player::addCard(bool is_red_card = false){
    cards_list[cards_count] = new Card(is_red_card);
    this->cards_count++;
}
