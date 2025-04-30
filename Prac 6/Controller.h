// The Controller class
#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Plane.h"
#include "Passenger.h"
#include "Cargo.h"
#include "Exceptions.h"

// #include "Controller.cpp"
// See spec for inclusion strategy for templates
using namespace std;
template <class T>
class Controller
{
private:
    Plane<T> *plane;

public:
    Controller(Plane<T> *p);
    string loadOnPlane(T *);
    double getTotalValue();
    string getPlaneContents();
};
#include "Controller.cpp"
#endif