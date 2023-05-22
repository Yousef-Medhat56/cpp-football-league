#ifndef CSV_H
#define CSV_H

#include <string>
#include <fstream>
using namespace std;
class CSV
{
private:
    string filename;
    ofstream file;

public:
    CSV(string name);

    ~CSV();
};
#endif
