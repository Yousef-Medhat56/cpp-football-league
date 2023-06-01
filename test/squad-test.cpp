// header files
#include "../include/squad.h"
#include "../include/utils/validator.h"

// cpp files
#include "../source/squad.cpp"
#include "../source/utils/validator.cpp"

int main()
{
    int macthes_num = 10;
    int club_id = 1;
    string club_name = "Al-Ahly";
    
    Squad squad(club_id, macthes_num);

    // give red card to the main defender
    cout << "## Get a player from the squad" << endl;
    squad.getMainPlayers().defender->addCard(1, true);

    cout << "## Print Squad details" << endl;
    squad.printDetails(club_name);

    return 0;
}