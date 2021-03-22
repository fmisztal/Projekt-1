#ifndef BATTERY_H
#define BATTERY_H
#include <iostream>

using namespace std;

class Battery{
    public:
        Battery();
        ~Battery();

        void addSize(int size);
        void addLifespan(int lifespan);

        int m_size;
        int m_lifespan;

        bool operator==(const Battery &b);

        static int number_of_objects;
};

ostream& operator<<(ostream &s, Battery &b);

#endif // BATTERY_H
