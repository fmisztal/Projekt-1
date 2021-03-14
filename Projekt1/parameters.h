#ifndef PARAMETERS_H
#define PARAMETERS_H

using namespace std;

class Parameter{
    public:
        Parameter();
        ~Parameter();

        void addName(char *name);
        void addValue(int value);
        void writeParameter();

    private:
        static int number_of_objects;
        char m1_name[1024];
        int m_value;
};

#endif // PARAMETERS_H
