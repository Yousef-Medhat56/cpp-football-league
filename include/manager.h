#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <string>
using namespace std;

#include "./utils/validator.h"

class Manager
{
private:
    string name;

public:
    // Constructor
    Manager();
    Manager(string manager_name);

    // Getters
    string getName();

    // Setters
    void setName(string name);

    // other methods
    void printDetails();
};

#endif