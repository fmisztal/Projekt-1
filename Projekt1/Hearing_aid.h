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

        static int objQuantity();

        Hearing_aid& operator=(const Hearing_aid &h);
        bool operator==(const Hearing_aid &h);    
        void operator[](int number);                    //shows the data of a chosen parameter
        operator string();                              //transfers year of production to string
        void operator++();                              //incrementation of battery lifespan (by 5)
        void operator--();

        Battery battery;
        Parameter *parameter=nullptr;
        string name;
        int number_of_parameters;
        int production_year;
        static int number_of_objects;
};

ostream& operator<<(ostream &s, Hearing_aid &h);        //allows to print the object's data
void operator>>(int x, Hearing_aid &h);                 //changes year of production

#endif // HEARING_AID_H

















