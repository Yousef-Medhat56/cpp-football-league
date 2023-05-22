// header files
#include "../include/match.h"

// cpp files
#include "../source/match.cpp"

int main()
{
    // create club objetcs
    Club home(1, "Ahly");
    Club away(2, "Zamalek");

    cout << "## Enter home squad" << endl;
    home.enterSquad(10);

    cout << "## Enter away squad" << endl;
    away.enterSquad(10);

    // add cards to players
    home.getSquad()->getMainPlayers().defender->addCard(1, 0);
    home.getSquad()->getMainPlayers().defender->addCard(2, 1);
    home.getSquad()->getMainPlayers().goalkeeper->addCard(2, 1, true);
    away.getSquad()->getMainPlayers().striker->addCard(2, 1, true);
 home.getSquad()->printDetails();
    //    create match object
    Match match(3, 2, &home, &away);

    cout << "## Print home formation" << endl;

    match.printTeamFormation(true);
    cout << "## Print away formation" << endl;
    match.printTeamFormation(false);

    cout << "## Enter match results" << endl;
    match.enterResults();

    cout << "## Print match results" << endl;
    match.printDetails();

    cout << "## Print home squad details" << endl;
    home.getSquad()->printDetails();

    cout << "## Print away squad details" << endl;
    away.getSquad()->printDetails();
 
    return 0;
}