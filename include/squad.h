#ifndef SQUAD_H
#define SQUAD_H

#include "./player/player.h"
#include "./player/goalkeeper.h"
#include "./player/defender.h"
#include "./player/striker.h"

#include "../source/player/player.cpp"
#include "../source/player/goalkeeper.cpp"
#include "../source/player/defender.cpp"
#include "../source/player/striker.cpp"

typedef struct formation
{
    GoalKeeper *goalkeeper;
    Defender *defender;
    Striker *striker;

} Players;

class Squad
{
private:
    Players mainPlayers; // main players
    Players subsitutes;  // substitute players

public:
    // Constructor
    Squad();

  // Getters
    Players getMainPlayers();
    Players getSubstitutes();
    
    // Setters
    void setMainPlayers(GoalKeeper *, Defender *, Striker *);
    void setSubstitutes(GoalKeeper *, Defender *, Striker *);

    // Destructor
    ~Squad();

    // other methods
    void printDetails();
};

#endif