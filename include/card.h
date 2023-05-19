#ifndef CARD_H
#define CARD_H

class Card
{
private:
    int player_id;
    int club_id;
    int match_id;
    int gameweek_id;
    bool is_red; // false: yellow card. true: red card

public:
    Card(int,int,int,int,bool);

    bool isRed();
    int getPlayerId();
    int getClubId();
    int getMatchId();
    int getGameweekId();
    void setColor(bool);
};

#endif