/* Myron Pow, CS 2B, 8/1/2012, Dave Harden, linkedList.h
*/
#ifndef LINKEDLIST
#define LINKEDLIST


namespace cs2b_linkedlist  {
    template<class T>
    class linkedList
    {
        private:
            struct node 
            {
                T data;
                node* next;
            };
            int size;
            node* first;
            void deleteList();
            void copyList(const linkedList<T> &rightDTA);
        public:
            linkedList();
            linkedList(const linkedList  &rightDTA);
            ~linkedList();
            int getSize() const;
            void addEntry(T input);
            bool deleteEntry(T input);
            T getEntry(int index) const;
            linkedList operator=(const linkedList &rightDTA);

    };
}
#include "linkedlist.cpp"
#endif