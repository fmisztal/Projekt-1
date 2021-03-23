#include <iostream>
#include "Hearing_aid.h"

using namespace std;

void Separator(string text)
{
    cout << "________________________________________________________________________________________________" << endl;
    cout << text << endl << endl;
};

void objectTesting()
{
    Separator("Creating p1 and p2 with different number of parameters: ");

    Hearing_aid p1("EarMax", 2011, 2);
    p1.battery.addSize(4000);
    p1.battery.addLifespan(100);
    p1.parameter[0].addName("LCE");
    p1.parameter[1].addName("size");
    p1.parameter[1].addValue(25);

    Hearing_aid p2("ITTC", 2001, 1);
    p2.battery.addSize(3000);
    p2.battery.addLifespan(50);
    p2.parameter[0].addName("Wireless");

    Separator("Creating p3 as a copy of p2: ");

    Hearing_aid p3=p2;

    Separator("Creating dynamic object px and deleting it: ");

    Hearing_aid *px=new Hearing_aid;
    delete px;

    Separator("Creating and printing empty p4: ");

    Hearing_aid p4("", 0, 5);
    p4.write();

    Separator("Checking current number of objects: ");

    p1.parQuantity();
    p1.batQuantity();
    p1.objQuantity();

    cout << endl;
};

void operatorTesting()
{
    Separator("Creating p1 and p2 with different number of parameters and p3 as a copy of p1: ");

    Hearing_aid p1("EarMax", 2011, 2);
    p1.battery.addSize(4000);
    p1.battery.addLifespan(100);
    p1.parameter[0].addName("LCE");
    p1.parameter[1].addName("size");
    p1.parameter[1].addValue(25);

    Hearing_aid p2("ITTC", 2001, 1);
    p2.battery.addSize(3000);
    p2.battery.addLifespan(50);
    p2.parameter[0].addName("Wireless");

    Hearing_aid p3(p1);

    Separator("Printing p1 and p2: ");

    p1.write();
    p2.write();

    Separator("Testing operator = by creating empty p4, assigning it to p2, then to p1 and printing it: ");

    Hearing_aid p4;
    p4=p2;
    p4=p1;
    p4.write();

    Separator("Testing operator == (if(p1==p2) -false): ");

    if(p1==p2)
        cout << "EQUAL" << endl;
    else
        cout << "DIFFERENT" << endl;

    Separator("Testing operator == (if(p1==p3)) -true): ");

    if(p1==p3)
        cout << "EQUAL" << endl;
    else
        cout << "DIFFERENT" << endl;

    Separator("Testing operator [] on full parameter and an empty one: ");

    p2[0];
    cout << endl;
    p2[3];

    Separator("Testing operator <<: ");

    cout << p1 << endl;

    Separator("Testing operator (string): ");     //kinda useless, i didn't have any ideas for that operator

    cout << p1.production_year << endl;
    string s = (string)p1 + " + ADDITIONAL TEXT";
    cout << s << endl;

    Separator("Testing operator >> (changing the year of production): ");

    cout << p1.production_year << endl;
    1999>>p1;
    cout << p1.production_year << endl << endl;
};

int main()
{
    objectTesting();

    #ifdef _DEBUG
    operatorTesting();
    #endif

    return 0;
}




