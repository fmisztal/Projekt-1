#ifndef HEARING_AID_H
#define HEARING_AID_H
#include "battery.h"
#include "parameters.h"

using namespace std;

class Hearing_aid{
    public:
        Hearing_aid();
        Hearing_aid(const char *name, const int production_year);
        Hearing_aid(const char *name, const int production_year, const int number_of_patrameters);
        ~Hearing_aid();

        void write();

        Battery battery;
        Parameter *parameter;

    private:
        static int number_of_objects;
        int number_of_patrameters;
        char name[1024];
        int production_year;

};

#endif // HEARING_AID_H
