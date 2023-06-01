// header files
#include "../include/match.h"
#include "../include/utils/validator.h"

// cpp files
#include "../source/match.cpp"
#include "../source/utils/validator.cpp"

int main()
{
    int macthes_num = 10;
    int home_id = 1;
    string home_name = "Al-Ahly";
    int away_id = 2;
    string away_name = "Zamalek";

    // create club objetcs
    Club home(home_id, home_name);
    Club away(away_id, away_name);

    cout << "## Enter home squad" << endl;
    home.enterSquad(macthes_num);

    cout << "## Enter away squad" << endl;
    away.enterSquad(macthes_num);

    // add cards to players

    // add 2 yellow cards to the home main defender
    home.getSquad()->getMainPlayers().defender->addCard(1, 0);
    home.getSquad()->getMainPlayers().defender->addCard(2, 1);

    // add a red card to the home main goalkeeper
    home.getSquad()->getMainPlayers().goalkeeper->addCard(2, 1, true);

    // add a red card to the away main striker
    away.getSquad()->getMainPlayers().striker->addCard(2, 1, true);

    // create match object
    Match match(3, 2, &home, &away);

    cout << "## Pick home formation" << endl;
    match.pickTeamFormation(true);
    cout << "## Pick away formation" << endl;
    match.pickTeamFormation(false);

    cout << "## Print home formation" << endl;
    match.printTeamFormation(true);

    cout << "## Print away formation" << endl;
    match.printTeamFormation(false);

    cout << "## Enter match results" << endl;
    match.enterResults();

    cout << "## Print match results" << endl;
    match.printDetails();

    cout << "## Print home squad details" << endl;
    home.getSquad()->printDetails(home_name);

    cout << "## Print away squad details" << endl;
    away.getSquad()->printDetails(away_name);

    return 0;
}