// The SecretCargo implementation file
#include <iostream>
#include "SecretCargo.h"
using namespace std;

SecretCargo::SecretCargo(double w)
{
    weight = w;
}

double SecretCargo::getWeight() const
{
    return weight;
}