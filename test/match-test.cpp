// header files
#include "../include/match.h"

// cpp files
#include "../source/match.cpp"

int main()
{
    Club club1("Ahly");
    Club club2("Pyramids");
    
   
    Match match(1,&club1,&club2);
    
    match.setHomeGoals(1);
    match.setAwayGoals(0);
    
    match.printDetails();
    return 0;
}