#ifndef HEARING_AID_H
#define HEARING_AID_H
#include "battery.h"
#include "parameters.h"

using namespace std;

class Hearing_aid{
    public:
        Hearing_aid();
        Hearing_aid(const Hearing_aid &h);
        Hearing_aid(const char *name, const int production_year);
        Hearing_aid(const char *name, const int production_year, const int number_of_patrameters);
        ~Hearing_aid();

        void write();
        void parQuantity();
        void objQuantity();

        bool operator==(const Hearing_aid &h);
        int operator[](int number);                     //shows the data of a chosen parameter
        Hearing_aid& operator=(const Hearing_aid &h);
        operator string();                              //transfers year of production to string

        Battery battery;
        Parameter *parameter;
        static int number_of_objects;
        int number_of_parameters;
        char name[1024];
        int production_year;
};

ostream& operator<<(ostream &s, Hearing_aid &h);        //allows to print the object's data
void operator>>(int x, Hearing_aid &h);                 //changes year of production

#endif // HEARING_AID_H

















