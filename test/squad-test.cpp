// header files
#include "../include/squad.h"

// cpp files
#include "../source/squad.cpp"

int main()
{
    int macthes_num = 10;
    
    Squad squad(macthes_num);

    //give red card to the main defender
    squad.getMainPlayers().defender->addCard(true);
    
    cout << "## Print Squad details" << endl;
    squad.printDetails();

    return 0;
}