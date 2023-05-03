#include "../include/manager.h"

Manager::Manager()
{
    cout << "Manager name: ";
    cin.clear();
    cin.sync();
    getline(cin, this->name);
};

Manager::Manager(string manager_name)
{
    this->name = manager_name;
};

// Getters
string Manager::getName()
{
    return this->name;
}

// Setters
void Manager::setName(string name)
{
    this->name = name;
}

// print manager details
void Manager::printDetails()
{
    cout << "Manager name: " << this->name << endl;
}
