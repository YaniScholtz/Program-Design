// The Passenger implementation file
#include <iostream>
#include "Passenger.h"
using namespace std;

Passenger::Passenger(string id, double w, double t)
{
    ID = id;
    weight = w;
    ticketPrice = t;
}

string Passenger::describe()
{
    string message;
    stringstream desc;
    desc << ID << " <" << ticketPrice << "> (" << weight << ")";
    getline(desc, message);
    return message;
}

double Passenger::getWeight() const
{
    return weight;
}

double Passenger::getValue() const
{
    return ticketPrice;
}
