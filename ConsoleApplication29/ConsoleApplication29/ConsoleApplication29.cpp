/* Myron Pow, CS2B, 6/29/2015, INST: Dave Harden, Intro to operator overloading
Class that stores a fraction, and enables relational operatoers
*/
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

void BasicTest();
void RelationTest();
void BinaryMathTest();
void MathAssignTest();
string boolString(bool convertMe);

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
    //incrementals
    fraction operator++();
    fraction operator++(int);
    fraction operator--();
    fraction operator--(int);


};

ostream& operator<<(ostream &os, const fraction &fract)
{
    os << fract.numerator << '/' << fract.denominator;
    return os;
}




// Assignment specifies that we use assert in constructor
// Is using it a violation of "do not change the client"?
// Why not have an if statement?
fraction::fraction(int num, int den)
{
    assert(denominator != 0);
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
        (fract2.numerator * fract1.denominator))
    {
        return true;
    }
    return false;
}

bool operator<=(const fraction &fract1, const fraction &fract2)
{
    if ((fract1.numerator * fract2.denominator) <=
        (fract2.numerator * fract1.denominator))
    {
        return true;
    }
    return false;
}

bool operator>(const fraction &fract1, const fraction &fract2)
{
    if ((fract1.numerator * fract2.denominator) >
        (fract2.numerator * fract1.denominator))
    {
        return true;
    }
    return false;
}

bool operator>=(const fraction &fract1, const fraction &fract2)
{
    if ((fract1.numerator * fract2.denominator) >=
        (fract2.numerator * fract1.denominator))
    {
        return true;
    }
    return false;
}

bool operator==(const fraction &fract1, const fraction &fract2)
{
    if ((fract1.numerator * fract2.denominator) ==
        (fract2.numerator * fract1.denominator))
    {
        return true;
    }
    return false;
}

bool operator!=(const fraction &fract1, const fraction &fract2)
{
    return !(fract1 == fract2);
}

fraction fraction::operator++()
{
    *this += 1;
    return *this;
}

fraction fraction::operator++(int)
{
    fraction temp;
    temp = *this;
    *this += 1;
    return temp;
}

fraction fraction::operator--()
{
    *this -= 1;
    return *this;
}

fraction fraction::operator--(int)
{
    fraction temp;
    temp = *this;
    *this -= 1;
    return temp;
}




int main()
{
    BasicTest();
    RelationTest();
    BinaryMathTest();
    MathAssignTest();
}





void BasicTest()
{
    cout << "\n----- Testing basic fraction creation & printing\n";
    
    const fraction fr[] = {fraction(4, 8), fraction(-15,21), 
                           fraction(10), fraction(12, -3),
                           fraction(), fraction(28, 6), fraction(0, 12)};
                                                   
    for (int i = 0; i < 7; i++){
        cout << "fraction [" << i <<"] = " << fr[i] << endl;
    }
        
        

}





string boolString(bool convertMe) {
	if (convertMe) {
		return "true";
	} else {
		return "false";
	}
}


void RelationTest()
{
    cout << "\n----- Testing relational operators between fractions\n";

    const fraction fr[] =  {fraction(3, 6), fraction(1,2), fraction(-15,30), 
                            fraction(1,10), fraction(0,1), fraction(0,2)};

    for (int i = 0; i < 5; i++) {
          cout << "Comparing " << fr[i] << " to " << fr[i+1] << endl;
          cout << "\tIs left < right? " << boolString(fr[i] < fr[i+1]) << endl;
          cout << "\tIs left <= right? " << boolString(fr[i] <= fr[i+1]) << endl;
          cout << "\tIs left > right? " << boolString(fr[i] > fr[i+1]) << endl;
          cout << "\tIs left >= right? " << boolString(fr[i] >= fr[i+1]) << endl;
          cout << "\tDoes left == right? " << boolString(fr[i] == fr[i+1]) << endl;
          cout << "\tDoes left != right ? " << boolString(fr[i] != fr[i+1]) << endl;
    }
 
    cout << "\n----- Testing relations between fractions and integers\n";
    fraction f(-3,6);
    int num = 2;
    cout << "Comparing " << f << " to " << num << endl;
    cout << "\tIs left < right? " << boolString(f < num) << endl;
    cout << "\tIs left <= right? " << boolString(f <= num) << endl;
    cout << "\tIs left > right? " << boolString(f > num) << endl;
    cout << "\tIs left >= right? " << boolString(f >= num) << endl;
    cout << "\tDoes left == right? " << boolString(f == num) << endl;
    cout << "\tDoes left != right ? " << boolString(f != num) << endl;
    
    fraction g(1,4);
    num = -3;
    cout << "Comparing " << num << " to " << g << endl;
    cout << "\tIs left < right? " << boolString(num < g) << endl;
    cout << "\tIs left <= right? " << boolString(num <= g) << endl;
    cout << "\tIs left > right? " << boolString(num > g) << endl;
    cout << "\tIs left >= right? " << boolString(num >= g) << endl;
    cout << "\tDoes left == right? " << boolString(num == g) << endl;
    cout << "\tDoes left != right ? " << boolString(num != g) << endl;  
}





void BinaryMathTest()
{    
    cout << "\n----- Testing binary arithmetic between fractions\n";
    
    const fraction fr[] = {fraction(1, 6), fraction(1,3), 
                           fraction(-2,3), fraction(5), fraction(-4,3)};

    for (int i = 0; i < 4; i++) {
          cout << fr[i] << " + " << fr[i+1] << " = " << fr[i] + fr[i+1] << endl;
          cout << fr[i] << " - " << fr[i+1] << " = " << fr[i] - fr[i+1] << endl;
          cout << fr[i] << " * " << fr[i+1] << " = " << fr[i] * fr[i+1] << endl;
          cout << fr[i] << " / " << fr[i+1] << " = " << fr[i] / fr[i+1] << endl;
    }

    cout << "\n----- Testing arithmetic between fractions and integers\n";
    fraction f(-1, 2);
    int num = 4;
    cout << f << " + " << num << " = " << f + num << endl;
    cout << f << " - " << num << " = " << f - num << endl;
    cout << f << " * " << num << " = " << f * num << endl;
    cout << f << " / " << num << " = " << f / num << endl;
     
    fraction g(-1, 2);
    num = 3;
    cout << num << " + " << g << " = " << num + g << endl;
    cout << num << " - " << g << " = " << num - g << endl;
    cout << num << " * " << g << " = " << num * g << endl;
    cout << num << " / " << g << " = " << num / g << endl;
}






void MathAssignTest()
{    
    cout << "\n----- Testing shorthand arithmetic assignment on fractions\n";
    
    fraction fr[] = {fraction(1, 6), fraction(4), 
                     fraction(-1,2), fraction(5)};

    for (int i = 0; i < 3; i++) {
          cout << fr[i] << " += " << fr[i+1] << " = ";
          cout << (fr[i] += fr[i+1]) << endl;
          cout << fr[i] << " -= " << fr[i+1] << " = ";
          cout << (fr[i] -= fr[i+1]) << endl;
          cout << fr[i] << " *= " << fr[i+1] << " = ";
          cout << (fr[i] *= fr[i+1]) << endl;
          cout << fr[i] << " /= " << fr[i+1] << " = ";
          cout << (fr[i] /= fr[i+1]) << endl;
    }
   
    cout << "\n----- Testing shorthand arithmetic assignment using integers\n";
    fraction f(-1, 3);
    int num = 3;
    cout << f << " += " << num << " = ";
    cout << (f += num) << endl;
    cout << f << " -= " << num << " = ";
    cout << (f -= num) << endl;
    cout << f << " *= " << num << " = ";
    cout << (f *= num) << endl;
    cout << f << " /= " << num << " = ";
    cout << (f /= num) << endl;

    cout << "\n----- Testing increment/decrement prefix and postfix\n";
    fraction g(-1, 3);
    cout << "Now g = " << g << endl;
    cout << "g++ = " << g++ << endl;
    cout << "Now g = " << g << endl;
    cout << "++g = " << ++g << endl;
    cout << "Now g = " << g << endl;
    cout << "g-- = " << g-- << endl;
    cout << "Now g = " << g << endl;
    cout << "--g = " << --g << endl;
    cout << "Now g = " << g << endl;
}


