#include "../include/card.h"

Card::Card(int player_id, int club_id, int match_id, bool val = false)
{
    this->player_id = player_id;
    this->club_id = club_id;
    this->match_id = match_id;
    this->is_red = val;
};

int Card::getPlayerId()
{
    return this->player_id;
}

int Card::getClubId()
{
    return this->club_id;
}

int Card::getMatchId()
{
    return this->match_id;
}

bool Card::getColor()
{
    return this->is_red;
}

void Card::setColor(bool val)
{
    this->is_red = val;
}