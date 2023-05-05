#include "../include/league.h"

League::League()
{
    cout << "Club Number:";
    cin >> club_num;
}

League::~League()
{
}
void League::set_clubNum(int club_num)
{
    this->club_num = club_num;
}

int League::get_clubNum()
{
    return this->club_num;
}