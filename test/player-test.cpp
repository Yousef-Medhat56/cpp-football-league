// header files
#include "../include/player/player.h"
#include "../include/player/goalkeeper.h"
#include "../include/player/defender.h"
#include "../include/player/striker.h"

// cpp files
#include "../source/player/player.cpp"
#include "../source/player/goalkeeper.cpp"
#include "../source/player/defender.cpp"
#include "../source/player/striker.cpp"

int main()
{

    int total_matches = 10;
    // Goal keeper
    GoalKeeper gk(1, 1, "Essam ElHadry", total_matches);
    gk.addCard(false);
    gk.addGoalsAgainst(3);
    gk.increaseCleansheets();
    gk.increaseCleansheets();

    // Defender
    Defender def(2, 1, "Wael Gomaa", total_matches);
    def.increaseCleansheets();
    def.increaseCleansheets();

    // Striker
    Striker striker(3, 1, "Abu Trika", total_matches);
    striker.scoreGoals(3);

    gk.printDetails();
    cout << "-" << endl;
    def.printDetails();
    cout << "-" << endl;
    striker.printDetails();

    return 0;
}