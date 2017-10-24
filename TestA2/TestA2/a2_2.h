/*
Myron Pow, Dave Harden, 1/18/2016 Assignment 2.2
Sparse Matricies
Creates a sparse matrix which defaults to a user-defined value
Program is a vector of lists, with the vector being the column and
the lists representing each row.


*/

/*MATNODE CLASS
It's a template for a node of any type

    int getCol() const { return col; }
    PRE: none
    POS: int, # node is in column

    const Object & operator=( const Object &x ) { return (data = x);}
    PRE: object x
    POS: sets data to x
*/



#ifndef SPARSEMAT_H
#define SPARSEMAT_H

#include "FHvector.h"
#include "FHlist.h"

template <class Object>
class MatNode
{
protected:
    int col;

public:
    Object data;
    // we need a default constructor for lists
    MatNode(int cl = 0, Object dt = Object()) : col(cl), data(dt) {}
    int getCol() const { return col; }

    const Object & operator=( const Object &x ) { return (data = x);}
};






/*SparseMat
Implementation of a sparse matrix w/ FHlist and FHvector
    SparseMat(int r, int c, const Object & def);
    PRE:(r)ow, (c)olumn, both ints, (def)ault as an object
    POS:Object of type SparseMat

    const Object & get(int r, int c) const;
    PRE:(r)ow, (c)olumn, both ints
    POS:object at that row&column

    bool set(int r, int c, const Object &x);
    PRE:(r)ow, (c)olumn, both ints, x, what that r/c will be set to
    POS:x will be added to the FHlist that constitues that row, at that col

    void clear();
    PRE:nil
    POS:empty matrix

    void showSubSquare(int start, int size);
    PRE:int for start(going from diagonals), int for size
    POS:shows sq matrix starting at start, and with dimensions size

    Class Invariant:
    List should always remain ordered
    Assumes that matrices are always positive

    MatRow
    is a typedef for a FHlist of MatNode(s)

    MasterCol
    is a typedef for a FHvector of MatRow(s)

    rows
    is a MasterCol, and is effectively the sparse matrix

    defaultVal
    is the default value that the sparse matrix is constructed with
*/
template <class Object>
class SparseMat
{

protected:
    typedef FHlist<MatNode<Object>> MatRow;
    typedef FHvector<MatRow> MasterCol;

    MasterCol rows;
    Object defaultVal;
    int rowSize, colSize;

public:
    //defaultVal renamed to def because loceff used it as object id
    SparseMat(int r, int c, const Object & def);
    const Object & get(int r, int c) const;
    bool set(int r, int c, const Object &x);
    void clear();
    void showSubSquare(int start, int size);
};





//FUNCTIONS BEGIN HERE

template <class Object>
SparseMat<Object>::SparseMat(int r, int c, const Object & def)
    : rowSize(r), colSize(c), defaultVal(def) 
{
    rows = MasterCol(rowSize);
};






template <class Object>
const Object & SparseMat<Object>::get(int r, int c) const
{
    if (c >= colSize || c < 0 || r >= rowSize || r < 0)
        throw defaultVal;

    for(typename MatRow::const_iterator iter = rows[r].begin(); iter != rows[r].end(); iter++)
    {
        if ((*iter).getCol() == c)
            return (*iter).data;
    }
    return defaultVal;
}






template <class Object>
bool SparseMat<Object>::set(int r, int c, const Object &x)
{
    if (c >= colSize || c < 0 || r >= rowSize || r < 0)
        return false;

    for (typename MatRow::iterator iter = rows[r].begin(); iter != rows[r].end(); iter++)
    {
        if ((*iter).getCol() == c)
        {
            rows[r].erase(iter);
            break;
        }
    }

    if (x == defaultVal)
        return false;

    MatNode<Object> * node = new MatNode<Object>(c, x);
    rows[r].push_back(*node);
    return true;
}






template <class Object>
void SparseMat<Object>::clear()
{
    rows = MasterCol(rowSize);
}






template <class Object>
void SparseMat<Object>::showSubSquare(int start, int size)
{
    for (int i = start; i < (start + size); i++)
    {
        for (int j = start; j < (start + size); j++)
        {
            cout << get(i, j) << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

#endif

/*RUN
0
35
21
oops
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  35  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  21  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  21  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0

0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  99

Press any key to continue . . .
*/