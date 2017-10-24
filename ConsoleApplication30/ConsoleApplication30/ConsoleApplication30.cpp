// ConsoleApplication30.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;
class fraction
{
    int numerator;
    int denominator;

public:
    fraction(int num = 0, int den = 1);
    friend ostream& operator<<(ostream &os, const fraction &fract);
    //fraction operator+(const fraction &fract1) const;
    // binary arithmatic
    friend fraction operator+(const fraction &fract1, const fraction &fract2);
    friend fraction operator-(const fraction &fract1, const fraction &fract2);
    friend fraction operator*(const fraction &fract1, const fraction &fract2);
    friend fraction operator/(const fraction &fract1, const fraction &fract2);
    // shorthand assignment
    friend fraction operator+=(fraction &fract1, const fraction &fract2);
    friend fraction operator-=(fraction &fract1, const fraction &fract2);
    friend fraction operator*=(fraction &fract1, const fraction &fract2);
    friend fraction operator/=(fraction &fract1, const fraction &fract2);
    // relational comparison
    friend bool operator<(const fraction &fract1, const fraction &fract2);
    friend bool operator<=(const fraction &fract1, const fraction &fract2);
    friend bool operator>(const fraction &fract1, const fraction &fract2);
    friend bool operator>=(const fraction &fract1, const fraction &fract2);
    friend bool operator==(const fraction &fract1, const fraction &fract2);
    friend bool operator!=(const fraction &fract1, const fraction &fract2);


};

ostream& operator<<(ostream &os, const fraction &fract)
{
    os << fract.numerator << '/' << fract.denominator;
    return os;
}





fraction::fraction(int num, int den)
{
    numerator = num;
    denominator = den;
}




/*
fraction fraction::operator+(const fraction &fract) const
{
    fraction temp;
    temp.numerator = (numerator * fract.denominator) + (fract.numerator * denominator);
    temp.denominator = (denominator * fract.denominator);
    return temp;
}
*/
fraction operator+(const fraction &fract1, const fraction &fract2)
{
    fraction sum;
    sum.numerator = (fract1.numerator * fract2.denominator) 
                  + (fract2.numerator * fract1.denominator);
    sum.denominator = (fract1.denominator * fract2.denominator);
    return sum;
}

fraction operator-(const fraction &fract1, const fraction &fract2)
{
    fraction diff;
    diff.numerator = (fract1.numerator * fract2.denominator) 
                  - (fract2.numerator * fract1.denominator);
    diff.denominator = (fract1.denominator * fract2.denominator);
    return diff;
}

fraction operator*(const fraction &fract1, const fraction &fract2)
{
    fraction prod;
    prod.numerator = (fract1.numerator * fract2.numerator);
    prod.denominator = (fract1.denominator *fract2.denominator);
    return prod;
}

fraction operator/(const fraction &fract1, const fraction &fract2)
{
    fraction quo;
    quo.numerator = (fract1.numerator * fract2.denominator);
    quo.denominator = (fract1.denominator *fract2.numerator);
    return quo;
}

fraction operator+=(fraction &fract1, const fraction &fract2)
{
    fract1 = (fract1 + fract2);
    return fract1;
}

fraction operator-=(fraction &fract1, const fraction &fract2)
{
    fract1 = (fract1 - fract2);
    return fract1;
}

fraction operator*=(fraction &fract1, const fraction &fract2)
{
    fract1 = (fract1 * fract2);
    return fract1;
}

fraction operator/=(fraction &fract1, const fraction &fract2)
{
    fract1 = (fract1 / fract2);
    return fract1;
}

bool operator<(const fraction &fract1, const fraction &fract2)
{
    if ((fract1.numerator * fract2.denominator) <
        (fract2.numerator * fract2.denominator))
    {
        return true;
    }
    return false;
}

bool operator<=(const fraction &fract1, const fraction &fract2)
{
    if ((fract1.numerator * fract2.denominator) <=
        (fract2.numerator * fract2.denominator))
    {
        return true;
    }
    return false;
}

bool operator>(const fraction &fract1, const fraction &fract2)
{
    if ((fract1.numerator * fract2.denominator) >
        (fract2.numerator * fract2.denominator))
    {
        return true;
    }
    return false;
}

bool operator>=(const fraction &fract1, const fraction &fract2)
{
    if ((fract1.numerator * fract2.denominator) >=
        (fract2.numerator * fract2.denominator))
    {
        return true;
    }
    return false;
}

bool operator==(const fraction &fract1, const fraction &fract2)
{
    if ((fract1.numerator * fract2.denominator) ==
        (fract2.numerator * fract2.denominator))
    {
        return true;
    }
    return false;
}

bool operator!=(const fraction &fract1, const fraction &fract2)
{
    return !(fract1 == fract2);
}

int main()
{
    fraction bob(4,8), joe(11);
    fraction hi;
    cout << (bob + joe);
    cout << endl;
    cout << (bob - joe);
    cout << endl;
    cout << (1 - bob);
    cout << endl;
    cout << (bob - 1);
    cout << endl;
    bob += 1;
    cout << bob;
}
