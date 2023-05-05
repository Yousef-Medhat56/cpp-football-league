#include "../include/gameweek.h"

Gameweek::Gameweek()
{
    cout << "ID: ";
    cin >> id;
}

Gameweek::~Gameweek()
{
    // dtor
}
void Gameweek::setId(int id)
{

    this->id = id;
}
int Gameweek::getId()
{
    return this->id;
}