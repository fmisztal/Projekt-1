#pragma once
#include <iostream>
#include <cstring>
#include "parameters.h"

using namespace std;

int Parameter::number_of_objects=0;

Parameter::Parameter(const string name, const int value)
{
    number_of_objects++;

    #ifdef _DEBUG
        cout << "Parameter(const string name, const int value) [" << number_of_objects << "]" << endl;
    #endif

    m_name=name;
    m_value=value;
};

Parameter::~Parameter()
{
    number_of_objects--;

    #ifdef _DEBUG
        cout << "~Parameter() [" << number_of_objects << "]" << endl;
    #endif
};

void Parameter::addName(string name)
{
    m_name= name;
};

void Parameter::addValue(int value)
{
    m_value=value;
};

bool Parameter::operator==(const Parameter &p)
{
    #ifdef _DEBUG
        cout << "operator==" << endl;
    #endif

    return m_name==p.m_name && m_value==p.m_value;
};

ostream& operator<<(ostream &s, Parameter &p)
{
    #ifdef _DEBUG
        cout << "operator<<" << endl;
    #endif

    if(p.m_name=="")
        return s << "";

    if(p.m_value==0)
        return s << p.m_name;

    return s << p.m_name << "- " << p.m_value;
};
