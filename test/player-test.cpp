//header files
#include "../include/player/player.h"
#include "../include/player/goalkeeper.h"
#include "../include/player/defender.h"
#include "../include/player/striker.h"

//cpp files
#include "../source/player/player.cpp"
#include "../source/player/goalkeeper.cpp"
#include "../source/player/defender.cpp"
#include "../source/player/striker.cpp"

int main(){

int total_matches = 10;
    //Goal keeper
    GoalKeeper gk("Essam ElHadry",total_matches);
    gk.addCard(false);
    gk.addGoalsAgainst(3);
    gk.increaseCleansheets();
    gk.increaseCleansheets();

    //Defender
    Defender def("Wael Gomaa",total_matches);
    def.increaseCleansheets();
    def.increaseCleansheets();

    //Striker
    Striker striker("Abu Trika",total_matches);
    striker.scoreGoals(3);

    gk.printDetails();
    cout<<"-"<<endl;
    def.printDetails();
    cout<<"-"<<endl;
    striker.printDetails();

    return 0;
}