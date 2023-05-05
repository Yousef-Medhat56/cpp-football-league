#include "../../include/player/player.h"

Player::Player(){};

Player::Player(string player_name)
{
    this->name = player_name;
};

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
    // cout << "Player position: " << this->position << endl;
}
