#include <iostream>
#include "Hearing_aid.h"

using namespace std;

int main()
{
    Hearing_aid p1("NAME2", 2011, 2);
    p1.battery.addSize(10);
    p1.battery.addLifespan(200);
    p1.parameter[0].addName("ALA");
    p1.parameter[0].addValue(123);
    p1.parameter[1].addName("KUBA");
    p1.parameter[1].addValue(420);
    p1.write();
    return 0;
}
