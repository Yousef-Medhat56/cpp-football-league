// header files
#include "../include/match.h"

// cpp files
#include "../source/match.cpp"

int main()
{
    Club home(1, "Ahly");
    Club away(2, "Pyramids");
    home.enterSquad(10);
    away.enterSquad(10);
    home.getSquad()->getMainPlayers().defender->addCard(1, 0);
    home.getSquad()->getMainPlayers().defender->addCard(2, 1);
    home.getSquad()->getMainPlayers().goalkeeper->addCard(2, 1,true);
    away.getSquad()->getMainPlayers().striker->addCard(2, 1,true);
    Match match(3, 2, &home, &away);
    
    match.setHomeGoals(1);
    match.setAwayGoals(0);

    match.printDetails();
    match.printHomeFormation();
    match.printAwayFormation();
    return 0;
}