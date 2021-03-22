#pragma once
#include <iostream>
#include <cstring>
#include "Hearing_aid.h"

using namespace std;

int Hearing_aid::number_of_objects=0;

Hearing_aid::Hearing_aid()
{
    #ifdef _DEBUG
        cout << "Hearing_aid()" << endl;
    #endif

    parameter=0;
    number_of_objects++;
};


Hearing_aid::Hearing_aid(const char *name, const int production_year)
{
    #ifdef _DEBUG
        cout << "Hearing_aid(const char *name, const int production_year)" << endl;
    #endif

    strcpy(this->name, name);
    this->production_year=production_year;

    number_of_objects++;
};

Hearing_aid::Hearing_aid(const char *name, const int production_year, const int number_of_parameters)
{
    #ifdef _DEBUG
        cout << "Hearing_aid(const char *name, const int production_year, const int number_of_patrameters)" << endl;
    #endif

    strcpy(this->name, name);
    this->production_year=production_year;
    this->number_of_parameters=number_of_parameters;

    if(number_of_parameters>0)
        this->parameter=new Parameter[number_of_parameters];

    number_of_objects++;
};

Hearing_aid::Hearing_aid(const Hearing_aid &h)
{
    #ifdef _DEBUG
        cout << "Hearing_aid(const Hearing_aid &h)" << endl;
    #endif

    strcpy(name, h.name);
    production_year=h.production_year;
    number_of_parameters=h.number_of_parameters;

    if(h.parameter)
    {
        parameter=new Parameter[this->number_of_parameters];
        for(int i=0; i<number_of_parameters; i++)
            parameter[i]=h.parameter[i];

        battery.m_size=h.battery.m_size;
        battery.m_lifespan=h.battery.m_lifespan;
    }
    else
        parameter = nullptr;

    number_of_objects++;
};

Hearing_aid::~Hearing_aid()
{
    #ifdef _DEBUG
        cout << "~Hearing_aid()" << endl;
    #endif

    if (parameter != nullptr)
        delete[] parameter;

    number_of_objects--;
};

int Hearing_aid::operator[](int number)
{
    if(number>=number_of_parameters)
    {
        cout << "No such parameter" << endl;
        return 0;
    }
    cout << parameter[number] << endl;
    return 0;
};

Hearing_aid& Hearing_aid::operator=(const Hearing_aid &h)
{
    strcpy(name, h.name);
    production_year=h.production_year;
    number_of_parameters=h.number_of_parameters;

    if(parameter)
        delete[] parameter;

    if(h.parameter)
    {
        parameter=new Parameter[number_of_parameters];
        for(int i=0; i<number_of_parameters; i++)
            parameter[i]=h.parameter[i];
    }
    else
        parameter=0;

    battery.m_size=h.battery.m_size;
    battery.m_lifespan=h.battery.m_lifespan;
    return *this;
};

bool Hearing_aid::operator==(const Hearing_aid &h)
{
    if(battery==h.battery && strcmp(name, h.name)==0 && production_year==h.production_year)
        if(number_of_parameters==h.number_of_parameters)
        {
            int x=0;
            for(int i=0; i<number_of_parameters; i++)
                if(parameter[i]==h.parameter[i])
                    x++;
            if(x==number_of_parameters)
                return true;
        }
    return false;
};

void Hearing_aid::write()
{
    cout << "-----------------------------------------" << endl;
    cout  << "Name: " << name << ", Year of production: " << production_year << endl;
    cout << battery << "Others: ";
    for(int i=0; i<number_of_parameters; i++)
    {
        if(i!=0)
            cout << ", ";
        cout << parameter[i];
    }
    cout << endl << "-----------------------------------------" << endl;
};

void Hearing_aid::parQuantity()
{
    cout << "Number of parameters: " << number_of_parameters << endl;
};

ostream& operator<<(ostream &s, Hearing_aid &h)
{
    return s << "Name: " << h.name << ", Year of production: " << h.production_year << endl;
};
