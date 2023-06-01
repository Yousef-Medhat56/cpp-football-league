// header files
#include "../include/league.h"

// cpp files
#include "../source/league.cpp"

int main()
{
    League league;
    cout << "## Entering clubs names" << endl;
    league.enterClubsNames();
    cout << "## Entering clubs info" << endl;
    league.enterClubsDetails();
    cout << "## Create the matches schedule" << endl;
    league.createMatchesSchedule();
    cout << "## Print the gameweeks table in sheets/gameweeks.csv" << endl;
    league.printGameweeksTable();
    return 0;
}