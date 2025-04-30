#include "Object.h"

using namespace std;

Object::Object(int x, int y)
{
    xPos = x;
    yPos = y;
    icon = '?';
}

char Object::getIcon()
{




    return icon ; 
}