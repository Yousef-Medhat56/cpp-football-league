#ifndef LEAGUE_H
#define LEAGUE_H
#include "./club.h"

class League
{
public:
    League();
    virtual ~League();
    void set_clubNum(int club_num);
    int get_clubNum();
    void enterClubs();
    void createGameweeksSchedule();
    void printStandings();
    void printAllGameweeks();
    void printWinnerClub();
    void printBestGk();
    void printBestDefender();
    void printBestStriker();

protected:
    int club_num;
    // Gameweek *gameWeeks;

private:
};

#endif // LEAGUE_H