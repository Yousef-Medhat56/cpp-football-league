#ifndef GAMEWEEK_H
#define GAMEWEEK_H
#include"./match.h"

class Gameweek
{
    public:
        Gameweek();
        virtual ~Gameweek();
       void setId(int id);
       int getId();

    protected:
    int id;
    //Match *matches;

    private:
};

#endif // GAMEWEEK_H