/* Myron Pow, CS2B, 7/7/2015, Dave Harden, Fraction.cpp
Program simulates fractional symbolics.
No input is provided by a user, as it is preprepared in a client,
and the output is printed streams throughly testing the class
*/


#include "fraction.h"
#include <iostream>
#include <cassert>
using namespace std;
namespace cs2b_fraction
{
// "Improved" << operator
// Debatable, since its really horribly written IMO
// checks each case sucessively in order to determine the ending
// format of the ostream
//NEEDS LOTS OF IMPROVEMENT
std::ostream& operator<<(std::ostream &os, const fraction &fract1)
{
    int mixnum;
    mixnum = (fract1.numerator / fract1.denominator);
    int tempnum;
    tempnum = (fract1.numerator - (mixnum * fract1.denominator));
    if ((mixnum == 0) && (tempnum == 0))
    {
        os << mixnum;
        return os;
    }
    if ((mixnum == 0) && (fract1.denominator < 0))
    {
        os << '-' << fract1.numerator << '/' << abs(fract1.denominator);
        return os;
    }
    if (mixnum == 0)
    {
        os << fract1.numerator << '/' << fract1.denominator;
        return os;
    }

    if (tempnum == 0)
    {
        os << mixnum;
        return os;
    }
    os << mixnum << '+' << abs(tempnum) << '/' << abs(fract1.denominator);
    return os;
}





//Constructor, simplifies inputs
fraction::fraction(int num, int den)
{

    assert(den != 0);
    numerator = num;
    denominator = den;
    simplify();
}




//Adds two fractions/ints, types on either side of operator
fraction operator+(const fraction &fract1, const fraction &fract2)
{
    fraction sum;
    sum.numerator = (fract1.numerator * fract2.denominator) 
                  + (fract2.numerator * fract1.denominator);
    sum.denominator = (fract1.denominator * fract2.denominator);
    sum.simplify();
    return sum;
}




//Subtracts two fractions/ints, types on either side of operator
fraction operator-(const fraction &fract1, const fraction &fract2)
{
    fraction diff;
    diff.numerator = (fract1.numerator * fract2.denominator) 
                  - (fract2.numerator * fract1.denominator);
    diff.denominator = (fract1.denominator * fract2.denominator);
    diff.simplify();
    return diff;
}




//Multiplies two fractions/ints, types on either side of operator
fraction operator*(const fraction &fract1, const fraction &fract2)
{
    fraction prod;
    prod.numerator = (fract1.numerator * fract2.numerator);
    prod.denominator = (fract1.denominator *fract2.denominator);
    prod.simplify();
    return prod;
}




//Division of fractions/ints, types on either side of operator
fraction operator/(const fraction &fract1, const fraction &fract2)
{
    fraction quo;
    quo.numerator = (fract1.numerator * fract2.denominator);
    quo.denominator = (fract1.denominator *fract2.numerator);
    quo.simplify();
    return quo;
}




//Quick addition and assignment
fraction operator+=(fraction &fract1, const fraction &fract2)
{
    fract1 = (fract1 + fract2);
    return fract1;
}




//Quick subtraction and assignment
fraction operator-=(fraction &fract1, const fraction &fract2)
{
    fract1 = (fract1 - fract2);
    return fract1;
}




//Quick Multiplication and assignment
fraction operator*=(fraction &fract1, const fraction &fract2)
{
    fract1 = (fract1 * fract2);
    return fract1;
}




//Quick Division and assignment
fraction operator/=(fraction &fract1, const fraction &fract2)
{
    fract1 = (fract1 / fract2);
    return fract1;
}




//Relational operator, checks if fract1 < fract2
bool operator<(const fraction &fract1, const fraction &fract2)
{
    return ((fract1.numerator * fract2.denominator) <
        (fract2.numerator * fract1.denominator));
}




//Relational operator, checks if fract1 <= fract2
bool operator<=(const fraction &fract1, const fraction &fract2)
{
    return ((fract1.numerator * fract2.denominator) <=
        (fract2.numerator * fract1.denominator));
}




//Relational operator, checks if fract1 > fract2
bool operator>(const fraction &fract1, const fraction &fract2)
{
    return ((fract1.numerator * fract2.denominator) >
        (fract2.numerator * fract1.denominator));
}




//Relational operator, checks if fract1 >= fract2
bool operator>=(const fraction &fract1, const fraction &fract2)
{
    return ((fract1.numerator * fract2.denominator) >=
        (fract2.numerator * fract1.denominator));
}




//Checks if fractions are numerically eqivalent
bool operator==(const fraction &fract1, const fraction &fract2)
{
    return ((fract1.numerator * fract2.denominator) ==
        (fract2.numerator * fract1.denominator));
}




//Checks if fractions are not numerically equivalent
bool operator!=(const fraction &fract1, const fraction &fract2)
{
    return !(fract1 == fract2);
}




//Fraction equivalent of ++temp
fraction fraction::operator++()
{
    *this += 1;
    return *this;
}




//Fraction equivalent of temp++
fraction fraction::operator++(int)
{
    fraction temp;
    temp = *this;
    *this += 1;
    return temp;
}




//Fraction equivalent of --temp
fraction fraction::operator--()
{
    *this -= 1;
    return *this;
}




//Fraction equivalent of temp--
fraction fraction::operator--(int)
{
    fraction temp;
    temp = *this;
    *this -= 1;
    return temp;
}




//Finds the lowest common denominator by finding the 
//Bigger of num/deno, and increments down until it finds LCD
void fraction::simplify()
{
    for (int k = max(numerator, denominator); k > 1; k--)
    {
        if ((numerator % k == 0) && (denominator % k == 0))
        {
            numerator /= k;
            denominator /= k;
        }
    }
}





//Attempt at an overloaded >> operator
// I will admit that it went far better than I expected it to
// It has problems evaluating some mixed fractions
//NEEDS LOTS OF IMPROVEMENT
std::istream& operator>>(std::istream &is, fraction &fract1)
{
    int temp;
    is >> temp;
    //broken, does not compute :D
    if (is.peek() == '+')
    {
        int wholenum;
        wholenum = temp;
        is.ignore();
        fract1.numerator = temp;
        is.ignore();
        fract1.denominator = temp;
        fract1.numerator += (wholenum * fract1.denominator);
    }
// these guys work as far as I can see
    else if(is.peek() == '/')
    {
        fract1.numerator = temp;
        is.ignore();
        is >> fract1.denominator;
    }
    else
    {
        fract1.numerator = temp;
        fract1.denominator = 1;
    }
    fract1.simplify();
    return is;
}

}