#include "../../include/utils/csv.h"

CSV::CSV(string name)
{
    this->filename = name;
    file.open("./sheets/" + filename + ".csv");
}

void CSV::addCell(string val)
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