#pragma once
#include <iostream>
#include "battery.h"

using namespace std;

Battery::Battery()
{
    #ifdef _DEBUG
        cout << "Battery()" << endl;
    #endif
};

Battery::~Battery()
{
    #ifdef _DEBUG
        cout << "~Battery()" << endl;
    #endif
};

void Battery::addSize(int size)
{
    m_size=size;
}

void Battery::addLifespan(int lifespan)
{
    m_lifespan=lifespan;
}
