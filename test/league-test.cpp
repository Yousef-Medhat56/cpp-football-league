// header files
#include "../include/league.h"

// cpp files
#include "../source/league.cpp"

int main()
{
    League league;
    league.enterClubsNames();
    // league.enterClubsDetails();
    league.createMatches();
    league.printMatches();
    return 0;
}