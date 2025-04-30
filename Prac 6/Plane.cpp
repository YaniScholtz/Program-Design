// The Plane implementation file
#include <iostream>
using namespace std;

template <>
double Plane<SecretCargo>::calculateValue()
{
    if (cargo.empty())
    {
        throw EmptyEx();
    }

    else
    {
        throw UnauthorisedEx();
    }
}
template <>
string Plane<SecretCargo>::getDescription()
{
    if (cargo.empty())
        throw EmptyEx();
    else
    {
        throw UnauthorisedEx();
    }
}
template <class T>
Plane<T>::Plane(double max)
{
    maxWeight = max;
}

template <class T>
Plane<T>::~Plane()
{
    for (int i = 0; i < cargo.size(); i++)
    {
        cargo.erase(cargo.begin() + 1);
    }
}

template <class T>
void Plane<T>::add(T *item)
{
    double total = 0;

    for (int i = 0; i < int(cargo.size()); i++)
    {
        total = total + cargo[i]->getWeight();
    }

    if (total + item->getWeight() > maxWeight)
    {
        throw AboveWeightEx(total + item->getWeight() - maxWeight);
    }
    else
    {
        cargo.push_back(item);
    }
}

template <class T>
void Plane<T>::remove(T *item)
{
    if (cargo.size() == 0)
    {
        throw EmptyEx();
    }
    bool found = false;
    for (int i = 0; i < int(cargo.size()); i++)
    {
        if (item == cargo[i])
        {
            cargo.erase(cargo.begin() + i);
            found = true;
            break;
        }
    }
    if (!found)
    {
        throw NotFoundEx<T>(item);
    }
}

template <class T>
string Plane<T>::getDescription()
{
    string description;

    if (cargo.size() == 0)
    {

        throw EmptyEx();
    }
    else
    {

        for (int i = 0; i < int(cargo.size()); i++)
        {

            if (i == int(cargo.size()) - 1)
            {
                description = description + cargo[i]->describe();
            }
            else
                description = description + cargo[i]->describe() + "\n";
        }
    }
    return description;
}

template <class T>
double Plane<T>::calculateValue()
{
    if (cargo.size() == 0)
        throw EmptyEx();

    if (cargo.size() == 1)
    {
        return cargo[0]->getWeight();
    }

    double min = cargo[0]->getValue();
    double seondmin = cargo[1]->getValue();
    double sum = min + secondmin;
    int pos = 0;

    if (min > secondmin)
    {
        double temp = min;
        min = secondmin;
        secondmin = temp;
        pos = 1;
    }

    if (cargo.size() != 2)
    {
        for (int i = 2; i < int(cargo.size()); i++)
        {
            if (cargo[i]->getValue() < min)
            {
                secondmin = min;
                min = cargo[i]->getValue();
                pos = i;
            }
            else if (cargo[i]->getValue() < secondmin)
            {
                secondmin = cargo[i]->getValue();
            }

            sum = sum + cargo[i]->getValue();
        }
    }

    if (min < (secondmin / 2))
    {
        sum = sum - min;
        throw UndervaluedEx<T>(cargo[pos], sum);
    }
    else
    {
        return sum;
    }
}
