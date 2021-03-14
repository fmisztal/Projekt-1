#pragma once
#include <iostream>
#include <cstring>
#include "Hearing_aid.h"

using namespace std;

Hearing_aid::Hearing_aid()
{
    #ifdef _DEBUG
        cout << "Hearing_aid()" << endl;
    #endif
};


Hearing_aid::Hearing_aid(const char *name, const int production_year)
{
    #ifdef _DEBUG
        cout << "Hearing_aid(const char *name, const int production_year)" << endl;
    #endif

    strcpy(this->name, name);
    this->production_year=production_year;
};

Hearing_aid::Hearing_aid(const char *name, const int production_year, const int number_of_patrameters)
{
    #ifdef _DEBUG
        cout << "Hearing_aid(const char *name, const int production_year, const int number_of_patrameters)" << endl;
    #endif

    strcpy(this->name, name);
    this->production_year=production_year;
    this->number_of_patrameters=number_of_patrameters;

    if(number_of_patrameters>0)
        this->parameter=new Parameter[number_of_patrameters];

};

Hearing_aid::~Hearing_aid()
{
    #ifdef _DEBUG
        cout << "~Hearing_aid()" << endl;
    #endif

    if (parameter != nullptr)
        delete[] parameter;
};

void Hearing_aid::write()
{
    cout << name << ", " << production_year << "r.:" << endl;
    cout << "    " << battery.m_size << ", " << battery.m_lifespan << endl << "    ";
    for (int i=0; i<number_of_patrameters; i++)
    {
        if(i!=0)
            cout << ", ";
        parameter[i].writeParameter();
    }
    cout << endl;
};
