#include "../include/card.h"

Card::Card() {}

Card::Card(bool val)
{
    this->is_red = val;
};

bool Card::getColor()
{
    return this->is_red;
}

void Card::setColor(bool val)
{
    this->is_red = val;
}