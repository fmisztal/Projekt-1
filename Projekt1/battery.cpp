#pragma once
#include <iostream>
#include "battery.h"

using namespace std;

int Battery::number_of_objects=0;

Battery::Battery(const int size, const int lifespan)
{
    #ifdef _DEBUG
        cout << "Battery(const int size, const int lifespan)" << endl;
    #endif

    m_size=size;
    m_lifespan=lifespan;

    number_of_objects++;
};

Battery::~Battery()
{
    #ifdef _DEBUG
        cout << "~Battery()" << endl;
    #endif

    number_of_objects--;
};

void Battery::addSize(int size)
{
    m_size=size;
}

void Battery::addLifespan(int lifespan)
{
    m_lifespan=lifespan;
}

bool Battery::operator==(const Battery &b)
{
    return m_size==b.m_size && m_lifespan==b.m_lifespan;
};

ostream& operator<<(ostream &s, Battery &b)
{
    return s << "Battery: size- " << b.m_size << ", Lifespan- " << b.m_lifespan << " hours" << endl;
};
