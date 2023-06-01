// header files
#include "../include/player/player.h"
#include "../include/player/goalkeeper.h"
#include "../include/player/defender.h"
#include "../include/player/striker.h"
#include "../include/utils/validator.h"

// cpp files
#include "../source/player/player.cpp"
#include "../source/player/goalkeeper.cpp"
#include "../source/player/defender.cpp"
#include "../source/player/striker.cpp"
#include "../source/utils/validator.cpp"

int main()
{
    int total_matches = 10;
    int club_id = 1;
    string club_name = "Al-Ahly";

    // Goal keeper
    GoalKeeper gk(1, club_id, "Essam ElHadry", total_matches);
    cout << "## Adding card to player" << endl;
    gk.addCard(1, 1, false);
    cout << "## Scoring goals against the goalkeeper" << endl;
    gk.addGoalsAgainst(3);
    gk.increaseCleansheets();
    cout << "## Increase the goalkeeper clean sheets" << endl;
    gk.increaseCleansheets();

    // Defender
    Defender def(2, club_id, "Wael Gomaa", total_matches);
    cout << "## Increase the defender clean sheets" << endl;
    def.increaseCleansheets();
    def.increaseCleansheets();

    // Striker
    Striker striker(3, club_id, "Abu Trika", total_matches);
    cout << "## Scoring goals by the striker" << endl;
    striker.scoreGoals(3);

    cout << "## Print players details" << endl;
    gk.printDetails(club_name);
    cout << "-" << endl;
    def.printDetails(club_name);
    cout << "-" << endl;
    striker.printDetails(club_name);

    return 0;
}