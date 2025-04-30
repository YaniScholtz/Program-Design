
#include <sstream>

class Object
{
protected:
    char icon;
    int xPos;
    int yPos;

public:
    Object *nextHroiz;
    Object *nextVert;
    Object *prevHoriz;
    Object *prevVert;
    Object *above;
    Object *below;
    Object(int x, int y);
    char getIcon();
    int getCoord(bool dimension);
    Object *getNext(bool dimension);
    Object *getPrev(bool dimension);
    void setNext(Object *obj, bool dim);
    void setPrev(Object *obj, bool dim);
};
