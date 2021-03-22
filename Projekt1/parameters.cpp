#pragma once
#include <iostream>
#include <cstring>
#include "parameters.h"

using namespace std;

int Parameter::number_of_objects=0;

Parameter::Parameter()
{
    #ifdef _DEBUG
        cout << "Parameter()" << endl;
    #endif

    number_of_objects++;
};

Parameter::~Parameter()
{
    #ifdef _DEBUG
        cout << "~Parameter()" << endl;
    #endif

    number_of_objects--;
};

void Parameter::addName(char *name)
{
    strcpy(m_name, name);
};

void Parameter::addValue(int value)
{
    m_value=value;
};

bool Parameter::operator==(const Parameter &p)
{
    return strcmp(m_name, p.m_name)==0 && m_value==p.m_value;
};

ostream& operator<<(ostream &s, Parameter &p)
{
    if(p.m_value==0)
        return s << p.m_name;
    return s << p.m_name << "- " << p.m_value;
};
