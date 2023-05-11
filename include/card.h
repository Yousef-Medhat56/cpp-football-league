#ifndef CARD_H
#define CARD_H

class Card
{
private:
    bool is_red; // false: yellow card. true: red card

public:
    Card();
    Card(bool);
    bool getColor();
    void setColor(bool);
};

#endif