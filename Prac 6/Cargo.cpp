// The Cargo implementation file
#include <iostream>
#include "Cargo.h"
using namespace std;
#include <sstream>
Cargo::Cargo(double w, double ppw)
{
    weight = w;
    value = ppw * w;
}

string Cargo::describe()
{
    string message;
    stringstream describe;
    describe << "Generic cargo <" << value << "> (" << weight << ")";
    getline(describe, message);
    return message;
}

double Cargo::getWeight() const
{
    return weight;
}

double Cargo::getValue() const
{
    return value;
}
