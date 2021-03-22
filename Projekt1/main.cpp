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

    cout << "_______________________________________________" << endl;

    Hearing_aid p2("TEST", 2001, 1);
    p2.battery.addSize(3000);
    p2.battery.addLifespan(50);
    p2.parameter[0].addName("Wireless");

    cout << "_______________________________________________" << endl;

    Hearing_aid p3=p1;

    cout << "_______________________________________________" << endl;

    Hearing_aid p4;
    p4=p2;

    cout << "_______________________________________________" << endl;

    if(p4==p3)
        cout << "EQUAL" << endl;
    else
        cout << "DIFFERENT" << endl;

    cout << "_______________________________________________" << endl;

    p4=p1;

    if(p4==p3)
        cout << "EQUAL" << endl;
    else
        cout << "DIFFERENT" << endl;

    cout << "_______________________________________________" << endl;

    p2[0];
    p2[3];

    cout << "_______________________________________________" << endl;

    p1.objQuantity();

    cout << "_______________________________________________" << endl;

    string s = (string)p1 + " ADDITIONAL TEXT";
    cout << s << endl;

    cout << "_______________________________________________" << endl;

    1999>>p1;
    p1.write();

    cout << "_______________________________________________" << endl;

    cout << p1.number_of_objects << ", " << p1.battery.number_of_objects << ", " << p1.parameter->number_of_objects << endl;

    cout << "_______________________________________________" << endl;

    return 0;
}
