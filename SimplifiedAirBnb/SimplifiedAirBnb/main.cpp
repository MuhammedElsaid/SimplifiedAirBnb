// SimplifiedAirBnb.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "database.h"

int main()
{
    Dataset dataset("dataset.txt");

    auto dataItem = new DataItem();
    dataItem->AddField("name", "Muhammed");
    dataItem->AddField("age", "24");
    dataItem->AddField("location", "Cairo");

    dataset.Push(dataItem); 
    
    dataset.Save();

}