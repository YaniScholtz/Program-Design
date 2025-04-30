#include "Calendar.h"

using namespace std;

Calendar::Calendar()
{
    head = NULL;
}

Calendar::Calendar(vector<event_data> input)
{
    head = NULL;

    for (int i = 0; i < int(input.size()); i++)
    {
        createEvent(input[i]);
    }
}

Calendar::~Calendar()
{
    clearCalendar();
}

Event *Calendar::getUpcomingEvent(long int now)
{
    Event *curr = head;

    if (head == NULL)
        return NULL;
    if (now < head->start)
    {
        return head;
    }
    while (curr->next != NULL)
    {
        curr = curr->next;
        if (curr->start > now)
        {
            return curr;
        }
    }
    return NULL;
}

vector<Event> Calendar::filterEvents(int *id, long int *start, long int *end, string *type)
{
    vector<Event> newVec;

    Event *nodeptr;
    nodeptr = head;
    int count = 0;
    if (id != NULL)
    {
        count++;
    }
    if (start != NULL)
        count++;

    if (end != NULL)
        count++;

    if (type != NULL)
        count++;
    int flag;
    while (nodeptr)
    {
        flag = 0;
        if (id)
        {
            if (nodeptr->id == *id)
            {
                flag++;
            }
        }
        if (start)
        {
            if (nodeptr->start >= *start)
            {
                flag++;
            }
        }
        if (end)
        {
            if (nodeptr->end <= *end)
            {
                flag++;
            }
        }
        if (type)
        {
            if (nodeptr->type == *type)
            {
                flag++;
            }
        }

        if (count == flag)
        {
            newVec.push_back(*nodeptr);
        }
        nodeptr = nodeptr->next;
    }

    return newVec;
}

void Calendar::alterEvent(int id, long int *end, string *type)
{

    Event *curr = head;
    while (curr != NULL)
    {
        if (curr->id == id)
        {
            if (end)
            {
                curr->end = *end;
            }
            if (type)
            {
                curr->type = *type;
            }
        }

        curr = curr->next;
    }
}

void Calendar::removeEvent(int id)
{
    Event *nodePtr;
    Event *prev;

    if (!head)
    {
        return;
    }

    if (head->id == id)
    {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    else
    {
        nodePtr = head;
        nodePtr = head;
        while (nodePtr != NULL && nodePtr->id != id)
        {
            prev = nodePtr;
            nodePtr = nodePtr->next;
        }
        if (nodePtr)
        {
            prev->next = nodePtr->next;
            delete nodePtr;
        }
    }
}

void Calendar::createEvent(event_data data)
{

    Event *newNode;
    Event *nodePtr;
    newNode = new Event(data.start, data.end, data.id, data.type);
    nodePtr = head;
    if (!head)
    {
        head = newNode;
    }
    else if (head->start > data.start)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        if (!head->next)
        {
            head->next = newNode;
            return;
        }
        while (nodePtr->next)
        {
            if (nodePtr->next->start > newNode->start)
            {

                newNode->next = nodePtr->next;
                nodePtr->next = newNode;
                return;
            }
            nodePtr = nodePtr->next;
        }
        nodePtr->next = newNode;
    }
}

void Calendar::clearCalendar()
{
    Event *nodeptr;
    Event *nextnode;
    nodeptr = head;

    while (nodeptr != NULL)
    {
        nextnode = nodeptr->next;
        delete nodeptr;
        nodeptr = nextnode;
    }
    head = NULL;
}

Event *Calendar::getFirstEvent()
{
    return head;
}
ostream &operator<<(ostream &out, Calendar &calendar)
{

    int Eventnewline = 0;
    Event *nodeptr = calendar.head;
    while (nodeptr)
    {
        out << Eventnewline << ": " << *nodeptr << endl;
        Eventnewline++;
        nodeptr = nodeptr->next;
    }

    return out;
}
