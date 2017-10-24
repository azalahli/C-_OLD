/*Myron Pow, Dave Harden, CS2C, 2/10/2016
This is an implmentation of splayed trees,
optimal for dealing with nodes that are 
repeatedly accessed
*/
/*Class Invariant
The object of type Comparable must have its "<" operator overloaded
public:

    bool insert(const Comparable &x);
    PRE:object of type Comparable, splaytree
    POS:x is now the root node of the splay tree


    bool remove(const Comparable &x);
    PRE: splaytree, Comparable obj
    POS: remove that value from splaytree

    bool contains(const Comparable &x);
    PRE: Comparable, splaytree
    POS: bool t/f if tree contains that value

    const Comparable & find(const Comparable &x);
    PRE:splaytree, Comparable to find
    POS:data, or exception
    
    const Comparable &showRoot();
    PRE: splaytree
    POS: returns master root data, or a default object

protected:

    void splay(FHs_treeNode<Comparable> * & root, const Comparable & x);
    PRE:a splaytree, object to find
    POS:makes x the root of tree

    void rotateWithLeftChild(FHs_treeNode<Comparable> * & k2);
    PRE: treenode to be rotated
    POS: rotated tree
    
    void rotateWithRightChild(FHs_treeNode<Comparable> * & k2);
    PRE: treenode to be rotated
    POS: rotated tree

*/
#ifndef FHSPLAY_TREE
#define FHSPLAY_TREE
#include "FHsearch_tree.h"

template <class Comparable>
class FHsplayTree : public FHsearch_tree<Comparable>
{
public:
    bool insert(const Comparable &x);
    bool remove(const Comparable &x);
    bool contains(const Comparable &x);
    const Comparable & find(const Comparable &x);
    const Comparable &showRoot();

protected:
    void splay(FHs_treeNode<Comparable> * & root, const Comparable & x);
    void rotateWithLeftChild(FHs_treeNode<Comparable> * & k2);
    void rotateWithRightChild(FHs_treeNode<Comparable> * & k2);
};





//Public definitions
template <class Comparable>
bool FHsplayTree<Comparable>::insert(const Comparable &x)
{
    if (this->mRoot == NULL) 
    {
        this->mRoot = new FHs_treeNode<Comparable>(x);
        return true;
    }
    else 
    {
        splay(this->mRoot, x);
        //case1 x < root
        if (x < this->mRoot->data)
        {
            mRoot = new FHs_treeNode<Comparable>(x, this->mRoot->lftChild, this->mRoot);
            return true;
        }
        //case2 x > root
        else if (this->mRoot->data < x) 
        {
            mRoot = new FHs_treeNode<Comparable>(x, this->mRoot, this->mRoot->rtChild);
            return true;
        }
        //case3 x in tree
        else
            return false;
    }
}






template <class Comparable>
bool FHsplayTree<Comparable>::remove(const Comparable &x)
{
    FHs_treeNode<Comparable> *newRoot = NULL;
    if (this->mRoot == NULL)
        return false;
    else 
    {
        splay(this->mRoot, x);
        //case1 x != root
        if (this->mRoot->data < x || x < this->mRoot->data)
            return false;
        //case2 mRoot->lftchild == NULL
        if (this->mRoot->lftChild == NULL)
            newRoot = this->mRoot->rtChild;
        //case3 lftchild exists
        else 
        {
            newRoot = this->mRoot->lftChild;
            splay(newRoot, x);
            newRoot->rtChild = this->mRoot->rtChild;
        }
        delete mRoot;
        mRoot = newRoot;
        return true;
    }
}






template <class Comparable>
bool FHsplayTree<Comparable>::contains(const Comparable &x)
{
    try
    {
        find(x);
    }
    catch (NotFoundException)
    {
        return false;
    }
    return true;
}






template <class Comparable>
const Comparable & FHsplayTree<Comparable>::find(const Comparable &x)
{
    splay(this->mRoot, x);
    if (this->mRoot->data < x || x < this->mRoot->data)
        throw typename FHsearch_tree<Comparable>::NotFoundException();
    else
        return this->mRoot->data;
}






template <class Comparable>
const Comparable & FHsplayTree<Comparable>::showRoot() 
{
    if (this->mRoot != NULL)
        return this->mRoot->data;
    else
        return Comparable();
}





//Protected definitions
template <class Comparable>
void FHsplayTree<Comparable>::splay(FHs_treeNode<Comparable> * & root, const Comparable & x)
{
    FHs_treeNode<Comparable> *rightTree = NULL, *leftTree = NULL;
    FHs_treeNode<Comparable> *rightTreeMin = NULL, *leftTreeMax = NULL;
    while (root != NULL)
    {
        //case1 x < root
        if (x < root->data) 
        {
            if (root->lftChild == NULL)
                break;
            if (x < root->lftChild->data)
            {
                rotateWithLeftChild(root);
                if (root->lftChild == NULL)
                    break;
            }
            if (rightTree == NULL)
                rightTree = root;
            else
                rightTreeMin->lftChild = root;
            rightTreeMin = root;
            root = root->lftChild;
        }
        //case2 x > root
        else if (root->data < x)
        {
            if (root->rtChild == NULL)
                break;
            if (root->rtChild->data < x)
            {
                rotateWithRightChild(root);
                if (root->rtChild == NULL)
                    break;
            }
            if (leftTree == NULL)
                leftTree = root;
            else
                leftTreeMax->rtChild = root;
            leftTreeMax = root;
            root = root->rtChild;
        }
        //case3 x == root
        else 
            break;
    }
    if (leftTree != NULL)
    {
        leftTreeMax->rtChild = root->lftChild;
        root->lftChild = leftTree;
    }
    if (rightTree != NULL)
    {
        rightTreeMin->lftChild = root->rtChild;
        root->rtChild = rightTree;
    }
}






template <class Comparable>
void FHsplayTree<Comparable>::rotateWithLeftChild(FHs_treeNode<Comparable> * & k2)
{
    FHs_treeNode<Comparable> *k1 = k2->lftChild;
    k2->lftChild = k1->rtChild;
    k1->rtChild = k2;
    k2 = k1;
}






template <class Comparable>
void FHsplayTree<Comparable>::rotateWithRightChild(FHs_treeNode<Comparable> * & k2)
{
    FHs_treeNode<Comparable> *k1 = k2->rtChild;
    k2->rtChild = k1->lftChild;
    k1->lftChild = k2;
    k2 = k1;
}
#endif
/*RUN
Initial size: 0
New size: 0

Traversal:
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32

 oops splay -1 --> root: 1 height: 16
 oops splay 0 --> root: 1 height: 16
splay 1 --> root: 1 height: 16
splay 2 --> root: 2 height: 9
splay 3 --> root: 3 height: 6
splay 4 --> root: 4 height: 6
splay 5 --> root: 5 height: 5
splay 6 --> root: 6 height: 6
splay 7 --> root: 7 height: 6
splay 8 --> root: 8 height: 7
splay 9 --> root: 9 height: 8
Press any key to continue . . .
*/