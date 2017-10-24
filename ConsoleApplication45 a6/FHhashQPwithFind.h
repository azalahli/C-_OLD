/* Myron Pow, Dave Harden, CS2C, 2/17/2016
find() for hash table, derived from FHhashQP
Meant to deal with dummied ebook entries
*/
/*CLASS INVARIANT
protected:

    int myHashKey(const KeyType & key) const;
    PRE:key
    POS:hash table indicies

    int findPosKey(const KeyType & key) const;
    PRE:hash key
    POS:index of data
    USES QUADRATIC PROBING

public:

    const Object find(const KeyType & key);
    PRE:key
    POS:data of that key, or exception thrown

    class NotFoundException{};
    This is just a dummy class for exceptions

*/
#ifndef FHHASHFIND_H
#define FHHASHFIND_H
#include "FHhashQP.h"

template <class Object, typename KeyType>
class FHhashQPwFind : public FHhashQP<Object>
{
protected:
    int myHashKey(const KeyType & key) const;
    int findPosKey(const KeyType & key) const;

public:
    const Object find(const KeyType & key);
    class NotFoundException{};
};






//PUBLIC
template <class Object, typename KeyType>
const Object FHhashQPwFind<Object, KeyType>::find(const KeyType & key) 
{
    typename FHhashQP<Object>::HashEntry found;
    found = mArray[findPosKey(key)];
    if (found.state == FHhashQP<Object>::ACTIVE)
        return found.data;
    else
        throw NotFoundException();
}






//PROTECTED
template <class Object, typename KeyType>
int FHhashQPwFind<Object, KeyType>::myHashKey(const KeyType & key) const
{
    int hashVal;

    hashVal = Hash(key) % this->mTableSize;
    if (hashVal < 0)
        hashVal += this->mTableSize;

    return hashVal;
}






template <class Object, typename KeyType>
int FHhashQPwFind<Object, KeyType>::findPosKey(const KeyType & key) const
{
    int kthOddNum = 1;
    int index = myHashKey(key);

    while (this->mArray[index].state != FHhashQP<Object>::EMPTY
        && getKey(this->mArray[index].data) != key)
    {
        index += kthOddNum;  // k squared = (k-1) squared + kth odd #
        kthOddNum += 2;   // compute next odd #
        if (index >= this->mTableSize)
            index -= this->mTableSize;
    }

    return index;
}
#endif