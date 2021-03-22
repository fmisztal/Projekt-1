#include <iostream>
#include "Hearing_aid.h"

using namespace std;

int main()
{
    Hearing_aid p1("NAME", 2011, 2);
    p1.battery.addSize(4000);
    p1.battery.addLifespan(100);
    p1.parameter[0].addName("ITC");
    p1.parameter[1].addName("size");
    p1.parameter[1].addValue(25);

    Hearing_aid p2("TEST", 2001, 1);
    p2.battery.addSize(3000);
    p2.battery.addLifespan(50);
    p2.parameter[0].addName("wef");

    Hearing_aid p3=p2;
    p3=p1;
    Hearing_aid p4=p1;
    Hearing_aid p5;
    p4=p2;
    p5=p2;
    p5=p1;


    if(p4==p3)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    p1.write();

    p2[1];
    p2[3];

    cout << "........" << endl;
    cout << p1.number_of_objects << ", " << p1.battery.number_of_objects << ", " << p1.parameter->number_of_objects << endl;
    cout << "........" << endl;

    return 0;
}
