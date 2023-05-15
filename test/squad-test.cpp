// header files
#include "../include/squad.h"

// cpp files
#include "../source/squad.cpp"

int main()
{
    int macthes_num = 10;

    Squad squad(1, macthes_num);

    // give red card to the main defender
    squad.getMainPlayers().defender->addCard(1,true);

    cout << "## Print Squad details" << endl;
    squad.printDetails();

    return 0;
}