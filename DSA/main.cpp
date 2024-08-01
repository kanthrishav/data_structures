// DSA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "list.h"

int main()
{
    int i;
    int val[5] = { 5, 6, 2, 0, 3 };
    LinearLL * list = new LinearLL;

    for(i = 0; i < 5; i++)
        list->insertAtStart(val[i]);
    list->print();

    delete list;
}

