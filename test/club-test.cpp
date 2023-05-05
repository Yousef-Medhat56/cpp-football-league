// header files
#include "../include/club.h"

// cpp files
#include "../source/club.cpp"

int main()
{
    Club club;
    
    cout << "## Enter Manager" << endl;
    club.enterManager();

    cout << "## Enter Squad" << endl;
    club.enterSquad();

    cout << "## Print club details" << endl;
    club.printDetails();

    cout << "## Print Manager details" << endl;
    club.getManager()->printDetails();

    cout << "## Print Squad details" << endl;
    club.getSquad()->printDetails();

    return 0;
}