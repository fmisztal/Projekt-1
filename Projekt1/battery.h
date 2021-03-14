#ifndef BATTERY_H
#define BATTERY_H

using namespace std;

class Battery{
    public:
        Battery();
        ~Battery();

        void addSize(int size);
        void addLifespan(int lifespan);

        int m_size;
        int m_lifespan;

    private:
        static int number_of_objects;

};

#endif // BATTERY_H
