/* Myron Pow, CS 2B, 8/1/2012, Dave Harden, linkedList.h
*/

/*
I do not understand why we do not have a helper function that deletes a node
as that is used in more places than deleting the whole list at once is
*/
#include <cassert>
#include <stdlib.h>
// My compiler needed stdlib for NULL
using namespace std;

namespace cs2b_linkedlist {



    template<class T>
    linkedList<T>::linkedList()
    {
        first = NULL;
        size = 0;
    }





    template<class T>
    linkedList<T>::linkedList(const linkedList<T> &rightDTA)
    {
        this->copyList(rightDTA);
    }





    template<class T>
    linkedList<T>::~linkedList()
    {
        this->deleteList();
    }






    template<class T>
    int linkedList<T>::getSize() const
    {
        return size;
    }





    template<class T>
    void linkedList<T>::addEntry(T input)
    {
        node *entry = new node;
        entry->data = input;
        entry->next = first;
        first = entry;
        size++;
    }





    template<class T>
    bool linkedList<T>::deleteEntry(T input)
    {
        int intsize = size;
        node *current = first;
        for (int k = 0; k < size; k++)
        {
            cout << "hi";
            if (current->data == input)
            {
                cout << "HIIIII";
            node *temp = current->next;
            delete current;
            current = temp;
            size--;
            }
            else current = current -> next;
        }
    return (intsize != size);
    }


    //
    template<class T>
    T linkedList<T>::getEntry(int index) const
    {
        assert(index >= 0 && index < size);
        node *current = first;
        for (int k = 0; (current != NULL) && (k < index); k++)
        {
            current = current ->next;
        }
        return (current->data);
    }




    template<class T>
    linkedList<T> linkedList<T>::operator=(const linkedList<T> &rightDTA)
    {
        this->deleteList();
        this->copyList(rightDTA);
        return *this;
    }




    template<class T> 
    void linkedList<T>::copyList(const linkedList<T> &rightDTA)
    {
        node* current;
        current = rightDTA.first;
        for (int k = 0; (k < (size-1)); k++)
        {
            addEntry(rightDTA.first->data);
            current = rightDTA.first->next;
        }
        size = rightDTA.size;
        first = current;
    }





    template<class T>
    void linkedList<T>::deleteList()
    {
        for (int k = 1; (k < (this->size-(k + 1))); k++)
        {
            node* temp = first->next;
            delete this->first;
            first = temp;
        }
        size = 0;
    }


}
