// header files
#include "../include/club.h"
#include "../include/utils/validator.h"

// cpp files
#include "../source/club.cpp"
#include "../source/utils/validator.cpp"

int main()
{
    int macthes_num = 10;
    int club_id = 1;
    string club_name = "Al-Ahly";

    Club club(club_id, club_name);

    cout << "## Enter Manager" << endl;
    club.enterManager();

    cout << "## Enter Squad" << endl;
    club.enterSquad(macthes_num);

    cout << "## Print club details" << endl;
    club.printDetails();

    cout << "## Print Manager details" << endl;
    club.getManager()->printDetails();

    cout << "## Print Squad details" << endl;
    club.getSquad()->printDetails(club_name);

    return 0;
}