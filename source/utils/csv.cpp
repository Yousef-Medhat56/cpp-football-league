#include "../../include/utils/csv.h"

CSV::CSV(string name)
{
    this->filename = name;
    file.open("./sheets/" + filename + ".csv");
}

CSV::~CSV()
{
    file.close();
}