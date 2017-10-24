/* Myron Pow, CS2B, 7/11/2015, Dave Harden, mystring.h
Program is an implementation of dynamic cstring(s).
No input is provided by a user, as it is preprepared in a client,
and the output is printed streams throughly after testing the class
*/
#include <iostream>
#ifndef mystring
namespace cs2b_mystring
{
/* NOTES
NEEDS SORTING
CLASS myString is a dynamic c string
Not sure if there are actual benefits to running this
over <string> or a normal cstring
*/

/* DESC
Pre none(default constructor)
Post myString obj ""
    myString();

Pre cstring(array of chars)
Post myString copy of cstring
    myString(const char *cstr);

Pre myString obj
Post deepcopy of myString obj
    myString(const  myString &rhs);

Pre myString obj, int in(dex)
Post char at in, rd only
    char operator [](int id) const;

Pre mystring obj, int in(dex)
Post char at in, modifiable(spelling?)
    char &operator [](int id);

Pre myString obj
Post stream of chars ready for cout
    friend std::ostream& operator<<(std::ostream &out, const myString str1);

Pre myString obj
Post int #of chars in myString
    int length() const;

Destructor
    ~myString();

Pre myString object
Post deepcopy of object
    myString operator=(const myString &rhs);

Pre lhs is myString, rhs is myString, cstring
Post bool result of comparison, eqiv <
    friend bool operator<(const myString &lhs, const myString &rhs);

Pre lhs is myString, rhs is myString, cstring
Post bool result of comparison, eqiv <=
    friend bool operator<=(const myString &lhs, const myString &rhs);

Pre lhs is myString, rhs is myString, cstring
Post bool result of comparison, eqiv >
    friend bool operator>(const myString &lhs, const myString &rhs);

Pre lhs is myString, rhs is myString, cstring
Post bool result of comparison, eqiv >=
    friend bool operator>=(const myString &lhs, const myString &rhs);

Pre lhs is myString, rhs is myString, cstring
Post bool result of comparison, eqiv ==
    friend bool operator==(const myString &lhs, const myString &rhs);

Pre lhs is myString, rhs is myString, cstring
Post bool result of comparison, eqiv !=
    friend bool operator!=(const myString &lhs, const myString &rhs);

Pre lhs myString, rhs cstring/myString obj
Post strings combined into one string
    friend myString operator+(const myString &lhs, const myString &rhs);

Pre lhs myString, rhs cstring/myString 
Post myString with myString+rhs
    myString operator+=(const myString &rhs);

Pre istream with string, lim 128 chars
Post myString of text
    friend std::istream& operator>>(std::istream &in, myString &str1);

Pre istream, char to terminate on, max 127
post myString w/ string in istream
    void read(std::istream &in, char lim);

*/

class myString
{
    char *name;

public:
    ~myString();
    myString();
    myString(const char *cstr);
    myString(const  myString &rhs);
    char operator [](int id) const;
    char &operator [](int id);
    friend std::ostream& operator<<(std::ostream &out, const myString str1);
    int length() const;

    myString operator=(const myString &rhs);
    friend bool operator<(const myString &lhs, const myString &rhs);
    friend bool operator<=(const myString &lhs, const myString &rhs);
    friend bool operator>(const myString &lhs, const myString &rhs);
    friend bool operator>=(const myString &lhs, const myString &rhs);
    friend bool operator==(const myString &lhs, const myString &rhs);
    friend bool operator!=(const myString &lhs, const myString &rhs);

    friend myString operator+(const myString &lhs, const myString &rhs);
    myString operator+=(const myString &rhs);
    friend std::istream& operator>>(std::istream &in, myString &str1);
    void read(std::istream &in, char lim);

};

}
#endif

/*RUN
----- Testing basic String creation & printing
string [0] = Wow
string [1] = C++ is neat!
string [2] =
string [3] = a-z

----- Now reading myStrings from file

----- first, word by word
Read string = The
Read string = first
Read string = time
Read string = we
Read string = will
Read string = read
Read string = individual
Read string = words,
Read string = next
Read string = we
Read string = read
Read string = whole
Read string = lines

----- now, line by line
Read string = The  first  time  we  will
Read string =     read individual words, next
Read string = we read whole lines

----- Testing access to characters (using const)
Whole string is abcdefghijklmnopqsrtuvwxyz
now char by char: abcdefghijklmnopqsrtuvwxyz
----- Testing access to characters (using non-const)
Start with abcdefghijklmnopqsrtuvwxyz and convert to ABCDEFGHIJKLMNOPQSRTUVWXYZ

----- Testing relational operators between myStrings
Comparing app to apple
        Is left < right? true
        Is left <= right? true
        Is left > right? false
        Is left >= right? false
        Does left == right? false
        Does left != right ? true
Comparing apple to
        Is left < right? false
        Is left <= right? false
        Is left > right? true
        Is left >= right? true
        Does left == right? false
        Does left != right ? true
Comparing  to Banana
        Is left < right? true
        Is left <= right? true
        Is left > right? false
        Is left >= right? false
        Does left == right? false
        Does left != right ? true
Comparing Banana to Banana
        Is left < right? false
        Is left <= right? true
        Is left > right? false
        Is left >= right? true
        Does left == right? true
        Does left != right ? false

----- Testing relations between myStrings and char *
Comparing he to hello
        Is left < right? true
        Is left <= right? true
        Is left > right? false
        Is left >= right? false
        Does left == right? false
        Does left != right ? true
Comparing why to wackity
        Is left < right? false
        Is left <= right? false
        Is left > right? true
        Is left >= right? true
        Does left == right? false
        Does left != right ? true

----- Testing concatentation on myStrings
outrageous + milk = outrageousmilk
milk +  = milk
 + cow = cow
cow + bell = cowbell

----- Testing concatentation between myString and char *
abcde + XYZ = abcdeXYZ
XYZ + abcde = XYZabcde

----- Testing shorthand concat/assign on myStrings
who += what = whowhatandwhowhat
what += WHEN = whatWHENandwhatWHEN
WHEN += Where = WHENWhereandWHENWhere
Where += why = WherewhyandWherewhy

----- Testing shorthand concat/assign using char *
I love  += programming = I love programming

----- Testing copy constructor and operator= on myStrings
original is cake, copy is fake
original is cake, copy is fake
after self assignment, copy is Copy Cat
Testing pass & return myStrings by value and ref
after calling Append, sum is BinkyBoo
val is winky
after assign,  val is BinkyBoo
Press any key to continue . . .
*/