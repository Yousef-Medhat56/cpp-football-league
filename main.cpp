#include "./include/league.h"
#include "./include/utils/menu.h"
#include "./source/utils/menu.cpp"
#include <direct.h>

int main()
{
    // create sheets directory
    mkdir("./sheets");

    Console::white();
    Menu::header();

    League league;

    // enter clubs data
    league.enterClubsNames();
    league.enterClubsDetails();

    // create the matches schedule
    league.createMatchesSchedule();

    // pick the teams formation for the first gameweek
    league.pickMatchesFormation();

    Console::success("Going to the dashboard...");
    Console::sleep();

    // show the main menu
    Menu::main(league);

    return 0;
}