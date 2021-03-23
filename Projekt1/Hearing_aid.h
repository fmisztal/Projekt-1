#ifndef HEARING_AID_H
#define HEARING_AID_H
#include "battery.h"
#include "parameters.h"

using namespace std;

class Hearing_aid{
    public:
        Hearing_aid(const Hearing_aid &h);
        Hearing_aid(const string name="", const int production_year=0, const int number_of_patrameters=0);
        ~Hearing_aid();

        void write();
        void parQuantity();
        void objQuantity();
        void batQuantity();

        bool operator==(const Hearing_aid &h);
        int operator[](int number);                     //shows the data of a chosen parameter
        Hearing_aid& operator=(const Hearing_aid &h);
        operator string();                              //transfers year of production to string

        Battery battery;
        Parameter *parameter;
        string name;
        int number_of_parameters;
        int production_year;
        static int number_of_objects;
};

ostream& operator<<(ostream &s, Hearing_aid &h);        //allows to print the object's data
void operator>>(int x, Hearing_aid &h);                 //changes year of production

#endif // HEARING_AID_H

















