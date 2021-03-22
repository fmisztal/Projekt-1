#ifndef PARAMETERS_H
#define PARAMETERS_H
#include <iostream>
#include <cstring>

using namespace std;

class Parameter{
    public:
        Parameter();
        ~Parameter();

        void addName(char *name);
        void addValue(int value);

        bool operator==(const Parameter &p);

        static int number_of_objects;

        char m_name[1024];
        int m_value=0;
};

ostream& operator<<(ostream &s, Parameter &p);

#endif // PARAMETERS_H
