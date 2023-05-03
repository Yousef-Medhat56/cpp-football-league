#include "../../include/player/player.h"

Player::Player()
{
    cout << "Player name: ";
    cin.clear();
    cin.sync();
    getline(cin, this->name);
    cout << "Player shirt number: ";
    cin >> this->shirt_num;
};

Player::Player(string player_name, int player_num)
{
    this->name = player_name;
    this->shirt_num = player_num;
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

int Player::getShirtNum()
{
    return this->shirt_num;
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

void Player::setShirtNum(int num)
{
    this->shirt_num = num;
}

// print player details
void Player::printDetails()
{
    cout << "Player name: " << this->name << endl;
    cout << "Player position: " << this->position << endl;
}
