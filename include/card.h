#ifndef CARD_H
#define CARD_H

class Card
{
private:
    int player_id;
    int club_id;
    int match_id;
    bool is_red; // false: yellow card. true: red card

public:
    Card(int,int,int,bool);

    bool getColor();
    int getPlayerId();
    int getClubId();
    int getMatchId();
    void setColor(bool);
};

#endif