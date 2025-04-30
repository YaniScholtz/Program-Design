
#include <iostream>

using namespace std;

template <class T>
void SortList<T>::add(SortNode<T> *a)
{

    if (!head)
    {

        head = a;
        a->next = NULL;
        a->prev = NULL;
        tail = a;
    }

    else
    {

        tail->next = a;
        a->prev = tail;
        a->next = NULL;
        tail = a;
    }
}

template <class T>
SortNode<T> *SortList<T>::remove(T val)
{

    SortNode<T> *Ptr;
    Ptr = head;

    while (Ptr->getValue() != val && Ptr)
    {
        Ptr = Ptr->next;
    }

    if (Ptr == head)
    {

        if (head == NULL)
        {
            return NULL;
        }

        if (head->next == NULL)
        {
            head = NULL;
            return Ptr;
        }

        else
        {

            head = head->next;
            head->prev = NULL;
            return Ptr;
        }
    }

    else if (Ptr == tail)
    {

        if (tail == NULL)
        {
            return NULL;
        }

        if (tail->prev == NULL)
        {
            tail = NULL;
            return Ptr;
        }

        else
        {

            tail = tail->prev;
            tail->next = NULL;
            return Ptr;
        }
    }

    else if (Ptr != tail && Ptr != head)
    {

        if (Ptr)
        {

            Ptr->prev->next = Ptr->next;
            Ptr->next->prev = Ptr->prev;
        }

        return Ptr;
    }

    return NULL;
}

template <class T>
SortNode<T> *SortList<T>::getHead()
{

    return head;
}

template <class T>
SortList<T>::SortList(bool asc)
{

    ascending = asc;
}

template <class T>
void SortList<T>::setAsc(bool a)
{

    ascending = a;
    sort();
}
template <class T>
void SortList<T>::sort()
{

    SortNode<T> *Ptr = head;

    if (head == NULL)
    {
        return;
    }
    if (ascending == true)
    {

        SortNode<T> *small;
        SortList<T> *List2 = new SortList<T>(1);
        while (Ptr)
        {

            small = head;

            while (Ptr)
            {

                if (Ptr->getValue() < small->getValue())
                {

                    small = Ptr;
                }

                Ptr = Ptr->next;
            }

            List2->add(remove(small->getValue()));
            Ptr = head;
        }

        head = List2->getHead();
        Ptr = head;

        while (Ptr->next)
        {

            Ptr = Ptr->next;
        }
        tail = Ptr;
    }
    else
    {

        SortNode<T> *small;
        SortList<T> *List2 = new SortList<T>(1);
        while (Ptr)
        {

            small = head;

            while (Ptr)
            {

                if (Ptr->getValue() > small->getValue())
                {

                    small = Ptr;
                }

                Ptr = Ptr->next;
            }

            List2->add(remove(small->getValue()));
            Ptr = head;
        }

        head = List2->getHead();
        Ptr = head;

        while (Ptr->next)
        {

            Ptr = Ptr->next;
        }
        tail = Ptr;
    }
}

template <class T>
string SortList<T>::print()
{

    SortNode<T> *ptr;
    ptr = head;
    string temp;
    stringstream tempprint;

    while (ptr)
    {

        if (ptr == head)
        {

            tempprint << ptr->getValue();
        }

        else
        {

            tempprint << "," << ptr->getValue();
        }

        ptr = ptr->next;
    }

    getline(tempprint, temp);

    return tempprint.str();
}
