#pragma once
#include <iostream>
#include <cstring>
#include "parameters.h"

using namespace std;

Parameter::Parameter()
{
    #ifdef _DEBUG
        cout << "Parameter()" << endl;
    #endif
};

Parameter::~Parameter()
{
    #ifdef _DEBUG
        cout << "~Parameter()" << endl;
    #endif
};

void Parameter::addName(char *name)
{
    strcpy(m1_name, name);
};

void Parameter::addValue(int value)
{
    m_value=value;
};

void Parameter::writeParameter()
{
    cout << m1_name;
    if(m_value!=0)
        cout << "- " << m_value;
};
