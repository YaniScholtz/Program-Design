// The Controller implementation file

#include <iostream>
using namespace std;

template <class T>
Controller<T>::Controller(Plane<T> *p)
{
    plane = p;
}

template <class T>
string Controller<T>::loadOnPlane(T *t)
{
    try
    {

        plane->add(t);
        return "Success";
    }
    catch (AboveWeightEx k)
    {
        string message;
        stringstream mes;
        mes << "Could not load item, above max weight by " << k.getDifference();
        getline(mes, message);
        return message;
    }
}

template <class T>
double Controller<T>::getTotalValue()
{
    double final;
    try
    {
        final = plane->calculateValue();
    }
    // catch (EmptyEx)
    // {
    //     return 0;
    // }
    catch (UnauthorisedEx k)
    {
        return 0;
    }
    catch (UndervaluedEx<T> k)
    {

        plane->remove(k.getUndervalued());
        return k.getSum();
    }
    return final;
}

template <class T>
string Controller<T>::getPlaneContents()
{
    try
    {
        return plane->getDescription();
    }
    catch (EmptyEx)
    {
        return "Nothing to report";
    }
    catch (UnauthorisedEx)
    {
        return "Not permitted";
    }
}