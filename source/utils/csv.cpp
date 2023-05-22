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

CSV::~CSV()
{
    file.close();
}