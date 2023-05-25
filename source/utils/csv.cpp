#include "../../include/utils/csv.h"

CSV::CSV(string name)
{
    this->filename = name;
    file.open("./sheets/" + filename + ".csv");
}

template <class myType>
void CSV::addCell(myType val)
{
    file << val << ", ";
}

void CSV::newRow()
{
    file << "\n";
}

string CSV::getFileName(){
    return this->filename;
}

CSV::~CSV()
{
    file.close();
}