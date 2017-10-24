/*Myron Pow, Dave Harden, CS2C, 2/3/2016
FHlazySearchTree.h
This is an implementation of a binary search tree, with lazy deletion
BST is always sorted so that left child is less than the root, and
right child is greater than the root. It won't accept the insertion of a node
equal to one already within the tree. 
Notable bug was the fact that mSizeHard would not update due to a bad
copy constructor
I still can't believe that took me 3 hours to find, and this is not even that big
I can't imagine the effort that can go into finding bugs in things like FB&google
*/
/*
// ---------------------- FHs_treeNode Prototype --------------------------
class FHs_treeNode:
Node is mostly manipulated via FHsearch_tree
Can store any data which can be compared, and stores a boolean
which determines if that particular node is part of the tree

// ---------------------- FHsearch_tree Prototype --------------------------
class FHsearch_tree:


Protected Variables:

    mSize:
    Stores the number of undeleted nodes
    
    *mRoot;
    This is the root of the binary search tree.
    
    mSizeHard;
    This stores the actual number of nodes in the BST


Constructors&Destructor(Public):

Default:
    FHsearch_tree() {mSize = 0; mRoot = NULL; mSizeHard = 0;}
Copy:
    FHsearch_tree(const FHsearch_tree &rhs) 
    {mRoot = NULL; mSize = 0; mSizeHard = 0; *this = rhs;}
Destuctor:
    ~FHsearch_tree() { clear(); }

    Publicly avalible methods:

These find the a value based on their name:
    const Comparable &findMin() const;
    Finds the smallest leaf of the tree, recursive

    const Comparable &findMax() const;
    Finds the largest leaf of the tree, recursive
    
    const Comparable &find(const Comparable &x) const;
    Finds a specified value of the tree

    bool empty() const {return (mSize == 0);}
    Returns an empty tree, or a tree of size 0

    int size() const {return mSize;}
    returns the size of the tree

    void clear() {makeEmpty(mRoot);}
    calls makeEmpty, to clear the tree

    const FHsearch_tree & operator=(const FHsearch_tree &rhs);
    Overloaded = operator for trees

    bool insert(const Comparable &x);
    Inserts a value into the tree

    bool remove(const Comparable &x);
    Lazily deletes a node, aka sets the deleted value to true

    bool contains(const Comparable &x) const {return find(mRoot, x) != NULL;}
    checks if tree contains a value, returns t/f based on that

Added to FHsearch_tree
    
    void collectGarbage();
    PRE: a BST w/ nodes marked deleted
    POST a BST with all deleted nodes removed

    int sizeHard() const {return mSizeHard;}
    PRE: N/A
    POS: int value of all nodes that are part of BST

Traverse & Misc

    template <class Processor>
    void traverse(Processor func) const {traverse(mRoot, func);}
    PRE: A BST
    POS: a BST which has moved its focus

    int showHeight() const {return findHeight(mRoot);}
    We don't need to care about this, but it gives the height of the tree

protected:

Recursive Methods for finding stuff in BST:

    FHs_treeNode<Comparable> *clone(FHs_treeNode<Comparable> *root) const;
    PRE: takes a BST
    POS: makes a copy of BST, preserves deleted state

    FHs_treeNode<Comparable> *findMin(FHs_treeNode<Comparable> *root) const;
    PRE:takes a node
    POS: finds the lowest valued node of the tree

    FHs_treeNode<Comparable> *findMax(FHs_treeNode<Comparable> *root) const;
    PRE:takes a node
    POS: finds the highest valued node of the tree

    FHs_treeNode<Comparable> *find(FHs_treeNode<Comparable> *root,
        const Comparable &x) const;
    PRE:takes a tree, and a value to find
    POS: finds the node with that exact value

    bool insert(FHs_treeNode<Comparable> * &root,
        const Comparable &x);
    PRE:takes a tree, and a value
    POS:adds that value to a node, and places it into BST(while retaining sort order)

    bool remove(FHs_treeNode<Comparable> * &root, const Comparable &x);
    PRE:takes a tree and a value to remove
    POS:does a lazy deletion of the value to be removed

    void makeEmpty(FHs_treeNode<Comparable> * &subtreeToDelete);
    PRE: takes a tree
    POS: deletes the BST completely(not lazily)

    template <class Processor>
    void traverse(FHs_treeNode<Comparable> *treeNode, 
        Processor func, int level = -1) const;
    PRE:tree, and a function
    POS:Applies the function to the data in the node?
    This one I'm not too sure about, seems like it should be called a Functor instead

    int findHeight(FHs_treeNode<Comparable> *treeNode, int height = -1) const;
    PRE:Probably a tree
    POS:an int for the Height of the tree?

Functions added to FHsearch_tree
    void collectGarbage(FHs_treeNode<Comparable> * &root);
    PRE:a tree with nodes marked deleted
    POS:a tree with those nodes completely deleted

    bool removeHard(FHs_treeNode<Comparable> * &root);
    PRE: node to be removed
    POS: tree without that node
public:
These are exception handlers:
    class EmptyTreeException {};
    class NotFoundException {};
};

*/
#ifndef FHSEARCHTREE_H
#define FHSEARCHTREE_H

// ---------------------- FHs_treeNode Prototype --------------------------
template <class Comparable>
class FHs_treeNode
{
public:
    FHs_treeNode( const Comparable & d = Comparable(), 
        FHs_treeNode *lt = NULL, 
        FHs_treeNode *rt = NULL)
        : lftChild(lt), rtChild(rt), data(d), deleted(false)
    { }

    FHs_treeNode *lftChild, *rtChild;
    Comparable data;
    //added
    bool deleted;

    // for use only with AVL Trees
    virtual int getHeight() const { return 0; }
    virtual bool setHeight(int height) { return true; }
}; 

// ---------------------- FHsearch_tree Prototype --------------------------
template <class Comparable>
class FHsearch_tree
{
protected:
    int mSize;
    FHs_treeNode<Comparable> *mRoot;
    //added
    int mSizeHard;
public:
    FHsearch_tree() {mSize = 0; mRoot = NULL; mSizeHard = 0;}
    FHsearch_tree(const FHsearch_tree &rhs) 
    {mRoot = NULL; mSize = 0; mSizeHard = 0; *this = rhs;}
    ~FHsearch_tree() { clear(); }

    const Comparable &findMin() const;
    const Comparable &findMax() const;
    const Comparable &find(const Comparable &x) const;

    bool empty() const {return (mSize == 0);}
    int size() const {return mSize;}
    void clear() {makeEmpty(mRoot);}
    const FHsearch_tree & operator=(const FHsearch_tree &rhs);

    bool insert(const Comparable &x);
    bool remove(const Comparable &x);
    bool contains(const Comparable &x) const {return find(mRoot, x) != NULL;}
    //added
    void collectGarbage();
    int sizeHard() const {return mSizeHard;}

    template <class Processor>
    void traverse(Processor func) const {traverse(mRoot, func);}
    int showHeight() const {return findHeight(mRoot);}

protected:
    FHs_treeNode<Comparable> *clone(FHs_treeNode<Comparable> *root) const;
    FHs_treeNode<Comparable> *findMin(FHs_treeNode<Comparable> *root) const;
    FHs_treeNode<Comparable> *findMax(FHs_treeNode<Comparable> *root) const;
    FHs_treeNode<Comparable> *find(FHs_treeNode<Comparable> *root,
        const Comparable &x) const;
    bool insert(FHs_treeNode<Comparable> * &root,
        const Comparable &x);
    bool remove(FHs_treeNode<Comparable> * &root, const Comparable &x);
    void makeEmpty(FHs_treeNode<Comparable> * &subtreeToDelete);
    template <class Processor>
    void traverse(FHs_treeNode<Comparable> *treeNode, 
        Processor func, int level = -1) const;
    int findHeight(FHs_treeNode<Comparable> *treeNode, int height = -1) const;
    //added
    void collectGarbage(FHs_treeNode<Comparable> * &root);
    bool removeHard(FHs_treeNode<Comparable> * &root);

public:
    // for exception throwing
    class EmptyTreeException {};
    class NotFoundException {};
};

// FHsearch_tree public method definitions -----------------------------
template <class Comparable>
const Comparable & FHsearch_tree<Comparable>::findMin() const
{
    if (mRoot == NULL || mSize == 0)
        throw EmptyTreeException();
    return findMin(mRoot)->data;
}






template <class Comparable>
const Comparable & FHsearch_tree<Comparable>::findMax() const
{
    if (mRoot == NULL || mSize == 0)
        throw EmptyTreeException();
    return findMax(mRoot)->data;
}






template <class Comparable>
const Comparable &FHsearch_tree<Comparable>::find(
    const Comparable &x) const
{ 
    FHs_treeNode<Comparable> *resultNode;
    resultNode = find(mRoot, x);
    if (resultNode == NULL)
        throw NotFoundException();
    return resultNode->data;
}






template <class Comparable>
const FHsearch_tree<Comparable> &FHsearch_tree<Comparable>::operator=
    (const FHsearch_tree &rhs)
{
    if (&rhs != this) 
    {
        clear();
        mRoot = clone(rhs.mRoot);
        mSize = rhs.size();
        mSizeHard = rhs.mSizeHard;
    }
    return *this;
}






template <class Comparable>
bool FHsearch_tree<Comparable>::insert(const Comparable &x)
{
    if (insert(mRoot, x))
    {
        mSize++;
        return true;
    }
    return false;
}






template <class Comparable>
bool FHsearch_tree<Comparable>::remove(const Comparable &x)
{
    if (remove(mRoot, x))
    {
        mSize--;
        return true;
    }
    return false;
}






template <class Comparable>
template <class Processor>
void FHsearch_tree<Comparable>::traverse( FHs_treeNode<Comparable> *treeNode,
                                         Processor func, int level) const
{
    if (treeNode == NULL)
        return;
    traverse(treeNode->lftChild, func, level + 1);
    if (!treeNode->deleted)
        func(treeNode->data);
    traverse(treeNode->rtChild, func, level + 1);
}






template <class Comparable>
void FHsearch_tree<Comparable>::collectGarbage()
{
    if (mSize < mSizeHard)
        collectGarbage(mRoot);
}






// FHsearch_tree private method definitions -----------------------------
template <class Comparable>
FHs_treeNode<Comparable> *FHsearch_tree<Comparable>::clone(
    FHs_treeNode<Comparable> *root) const
{
    if (root == NULL)
        return NULL;
    FHs_treeNode<Comparable> *newNode;
    newNode =  new FHs_treeNode<Comparable>
        (
        root->data, 
        clone(root->lftChild), clone(root->rtChild)
        );
    newNode->deleted = root->deleted;
    return newNode;
}






template <class Comparable>
FHs_treeNode<Comparable> *FHsearch_tree<Comparable>::findMin(
    FHs_treeNode<Comparable> *root) const

{
    if (root == NULL)
        return NULL;

    if (findMin(root->lftChild) == NULL) 
    {
        if (root->deleted)
            return findMin(root->rtChild);
        return root;
    }
    return findMin(root->lftChild);
}






template <class Comparable>
FHs_treeNode<Comparable> *FHsearch_tree<Comparable>::findMax(
    FHs_treeNode<Comparable> *root) const
{
    if (root == NULL) 
        return NULL;

    if (findMax(root->rtChild) == NULL) 
    {
        if (root->deleted)
            return findMax(root->lftChild);
        return root;
    }
    return findMax(root->rtChild);
}






template <class Comparable>
FHs_treeNode<Comparable>* FHsearch_tree<Comparable>::find(
    FHs_treeNode<Comparable> *root, const Comparable &x) const
{

    if (root == NULL)
        return NULL;
    if (x < root->data)
        return find(root->lftChild, x);
    if (root->data < x)
        return find(root->rtChild, x);
    if (root->deleted)
        return NULL;

    return root;
}






template <class Comparable>
bool FHsearch_tree<Comparable>::insert(
    FHs_treeNode<Comparable> * &root, const Comparable &x)
{
    if (root == NULL)
    {
        mSizeHard++;
        root = new FHs_treeNode<Comparable>(x, NULL, NULL);
        return true;
    }
    else if (x < root->data)
        return insert(root->lftChild, x);
    else if (root->data < x)
        return insert(root->rtChild, x);
    else if (root->deleted) 
    {
        root->deleted = false;
        return true;
    }
    return false;
}






template <class Comparable>
bool FHsearch_tree<Comparable>::remove(
    FHs_treeNode<Comparable> * &root, const Comparable &x)
{
    if (root == NULL)
        return false;
    if (x < root->data)
        return remove(root->lftChild, x);
    if (root->data < x)
        return remove(root->rtChild, x);
    if (root->deleted)
        return false;

    root->deleted = true;
    return true;
}






template <class Comparable>
void FHsearch_tree<Comparable>::makeEmpty(
    FHs_treeNode<Comparable> * &subtreeToDelete)
{
    if (subtreeToDelete == NULL)
        return;

    makeEmpty(subtreeToDelete->lftChild);
    makeEmpty(subtreeToDelete->rtChild);

    if (subtreeToDelete->deleted)
    {
        mSizeHard--;
    }
    else {
        mSizeHard--;
        mSize--;
    }
    delete subtreeToDelete;
    subtreeToDelete = NULL;

}






template <class Comparable>
int FHsearch_tree<Comparable>::findHeight( FHs_treeNode<Comparable> *treeNode,
                                          int height ) const
{
    int leftHeight, rightHeight;

    if (treeNode == NULL)
        return height;
    height++;
    leftHeight = findHeight(treeNode->lftChild, height);
    rightHeight = findHeight(treeNode->rtChild, height);
    return (leftHeight > rightHeight)? leftHeight : rightHeight;
}






template <class Comparable>
void FHsearch_tree<Comparable>::collectGarbage(FHs_treeNode<Comparable> * &root)
{
    if (root == NULL)
        return;

    collectGarbage(root->lftChild);
    collectGarbage(root->rtChild);

    if (root->deleted)
        removeHard(root);
}






template <class Comparable>
bool FHsearch_tree<Comparable>::removeHard(
    FHs_treeNode<Comparable> * &root)
{
    if (root == NULL)
        return false;

    if (root->lftChild != NULL && root->rtChild != NULL)
    {
        FHs_treeNode<Comparable> *minNode = findMin(root->rtChild);
        root->data = minNode->data;
        root->deleted = false;
        minNode->deleted = true;
        removeHard(root->rtChild);
    }
    else
    {
        FHs_treeNode<Comparable> *nodeToRemove = root;
        if (root->lftChild != NULL)
            root = root->lftChild;
        else root = root->rtChild;
        delete nodeToRemove;
        mSizeHard--;
    }
    return true;
}


#endif