#pragma once
#include <iostream>
#include <cstring>
#include "Hearing_aid.h"

using namespace std;

int Hearing_aid::number_of_objects=0;

Hearing_aid::Hearing_aid(const string name, const int production_year, const int number_of_parameters)
{
    number_of_objects++;

    #ifdef _DEBUG
        cout << "Hearing_aid(const string name, const int production_year, const int number_of_parameters) [" << number_of_objects << "]" << endl;
    #endif

    this->name=name;
    this->production_year=production_year;
    this->number_of_parameters=number_of_parameters;

    if(number_of_parameters>0)
        this->parameter=new Parameter[number_of_parameters];
    else
        parameter=0;
};

Hearing_aid::Hearing_aid(const Hearing_aid &h)
{
    number_of_objects++;

    #ifdef _DEBUG
        cout << "Hearing_aid(const Hearing_aid &h) [" << number_of_objects << "]" << endl;
    #endif

    name=h.name;
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
};

Hearing_aid::~Hearing_aid()
{
    number_of_objects--;

    #ifdef _DEBUG
        cout << "~Hearing_aid() [" << number_of_objects << "]" << endl;
    #endif

    if (parameter != nullptr)
        delete[] parameter;
};

int Hearing_aid::objQuantity()
{
    return number_of_objects;
};

Hearing_aid& Hearing_aid::operator=(const Hearing_aid &h)
{
    #ifdef _DEBUG
        cout << "operator=" << endl;
    #endif

    name=h.name;
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
    #ifdef _DEBUG
        cout << "operator==" << endl;
    #endif

    if(battery==h.battery && name==h.name && production_year==h.production_year)
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

ostream& operator<<(ostream &s, Hearing_aid &h)
{
    #ifdef _DEBUG
        cout << "operator<<" << endl;
    #endif

    s << "-----------------------------------------" << endl;
    s  << "Name: " << h.name << ", Year of production: " << h.production_year << endl;
    s << h.battery << "Others: ";
    for(int i=0; i<h.number_of_parameters; i++)
    {
        if(i!=0)
            cout << ", ";
        cout << h.parameter[i];
    }
    s << endl << "-----------------------------------------" << endl;
    return s;
};

Hearing_aid::operator string()
{
    #ifdef _DEBUG
        cout << "operator string()" << endl;
    #endif

    return "Year of production: " + to_string(production_year);
};

void Hearing_aid::operator[](int number)
{
    #ifdef _DEBUG
        cout << "operator[]" << endl;
    #endif

    if(number>=number_of_parameters)
    {
        cout << "No such parameter" << endl;
        return;
    }
    cout << parameter[number] << endl;
    return;
};

void Hearing_aid::operator++()
{
    #ifdef _DEBUG
        cout << "operator++" << endl;
    #endif

    battery.m_lifespan+=5;
};

void Hearing_aid::operator--()
{
    #ifdef _DEBUG
        cout << "operator--" << endl;
    #endif

    battery.m_lifespan-=5;
};

void operator>>(int x, Hearing_aid &h)
{
    #ifdef _DEBUG
        cout << "operator>>" << endl;
    #endif

    h.production_year = x;
};



