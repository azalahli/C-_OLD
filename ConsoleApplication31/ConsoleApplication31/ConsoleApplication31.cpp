// Myron Pow, CS2B, 6/29/15, Dave Harden, Fraction Class
// Introduction to operator overloading


/* NESSASARY CHANGES TO CLIENT
Two changes were made to the client: There was a "ø"
before #include <iostream>, creating an error.
Action:
Characters were removed.

function string boolString has tabs in it, not spaces
causing irregular spacing, and thus hindering readability
Action:
Tabs were replaced w/ spaces.

Assignment 1.2 Specifically states that we are to use assert
This goes against the statement on the bottom, that we will get
a 0 on the assignment for changing the client
Action:
#include <cassert> included in preprocessor
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



/* DESCRIPTION
Code allows for the creation and manipulation of symbolic
fractions.
At no point are fractions ever reduced.
At all times, fuctions behave as their more common
int-based counterparts
*/


class fraction
{
    int numerator;
    int denominator;
public:
    //constructor
    fraction(int num = 0, int den = 1);

    // stream combiner?
    friend ostream& operator<<(ostream &os, const fraction &fract);

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




//Adds two fractions/ints, types on either side of operator
fraction operator+(const fraction &fract1, const fraction &fract2)
{
    fraction sum;
    sum.numerator = (fract1.numerator * fract2.denominator) 
                  + (fract2.numerator * fract1.denominator);
    sum.denominator = (fract1.denominator * fract2.denominator);
    return sum;
}




//Subtracts two fractions/ints, types on either side of operator
fraction operator-(const fraction &fract1, const fraction &fract2)
{
    fraction diff;
    diff.numerator = (fract1.numerator * fract2.denominator) 
                  - (fract2.numerator * fract1.denominator);
    diff.denominator = (fract1.denominator * fract2.denominator);
    return diff;
}




//Multiplies two fractions/ints, types on either side of operator
fraction operator*(const fraction &fract1, const fraction &fract2)
{
    fraction prod;
    prod.numerator = (fract1.numerator * fract2.numerator);
    prod.denominator = (fract1.denominator *fract2.denominator);
    return prod;
}




//Division of fractions/ints, types on either side of operator
fraction operator/(const fraction &fract1, const fraction &fract2)
{
    fraction quo;
    quo.numerator = (fract1.numerator * fract2.denominator);
    quo.denominator = (fract1.denominator *fract2.numerator);
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
    if ((fract1.numerator * fract2.denominator) <
        (fract2.numerator * fract1.denominator))
    {
        return true;
    }
    return false;
}




//Relational operator, checks if fract1 <= fract2
bool operator<=(const fraction &fract1, const fraction &fract2)
{
    if ((fract1.numerator * fract2.denominator) <=
        (fract2.numerator * fract1.denominator))
    {
        return true;
    }
    return false;
}




//Relational operator, checks if fract1 > fract2
bool operator>(const fraction &fract1, const fraction &fract2)
{
    if ((fract1.numerator * fract2.denominator) >
        (fract2.numerator * fract1.denominator))
    {
        return true;
    }
    return false;
}




//Relational operator, checks if fract1 >= fract2
bool operator>=(const fraction &fract1, const fraction &fract2)
{
    if ((fract1.numerator * fract2.denominator) >=
        (fract2.numerator * fract1.denominator))
    {
        return true;
    }
    return false;
}




//Checks if fractions are numerically eqivalent
bool operator==(const fraction &fract1, const fraction &fract2)
{
    if ((fract1.numerator * fract2.denominator) ==
        (fract2.numerator * fract1.denominator))
    {
        return true;
    }
    return false;
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




/* RUN

----- Testing basic fraction creation & printing
fraction [0] = 4/8
fraction [1] = -15/21
fraction [2] = 10/1
fraction [3] = 12/-3
fraction [4] = 0/1
fraction [5] = 28/6
fraction [6] = 0/12

----- Testing relational operators between fractions
Comparing 3/6 to 1/2
        Is left < right? false
        Is left <= right? true
        Is left > right? false
        Is left >= right? true
        Does left == right? true
        Does left != right ? false
Comparing 1/2 to -15/30
        Is left < right? false
        Is left <= right? false
        Is left > right? true
        Is left >= right? true
        Does left == right? false
        Does left != right ? true
Comparing -15/30 to 1/10
        Is left < right? true
        Is left <= right? true
        Is left > right? false
        Is left >= right? false
        Does left == right? false
        Does left != right ? true
Comparing 1/10 to 0/1
        Is left < right? false
        Is left <= right? false
        Is left > right? true
        Is left >= right? true
        Does left == right? false
        Does left != right ? true
Comparing 0/1 to 0/2
        Is left < right? false
        Is left <= right? true
        Is left > right? false
        Is left >= right? true
        Does left == right? true
        Does left != right ? false

----- Testing relations between fractions and integers
Comparing -3/6 to 2
        Is left < right? true
        Is left <= right? true
        Is left > right? false
        Is left >= right? false
        Does left == right? false
        Does left != right ? true
Comparing -3 to 1/4
        Is left < right? true
        Is left <= right? true
        Is left > right? false
        Is left >= right? false
        Does left == right? false
        Does left != right ? true

----- Testing binary arithmetic between fractions
1/6 + 1/3 = 9/18
1/6 - 1/3 = -3/18
1/6 * 1/3 = 1/18
1/6 / 1/3 = 3/6
1/3 + -2/3 = -3/9
1/3 - -2/3 = 9/9
1/3 * -2/3 = -2/9
1/3 / -2/3 = 3/-6
-2/3 + 5/1 = 13/3
-2/3 - 5/1 = -17/3
-2/3 * 5/1 = -10/3
-2/3 / 5/1 = -2/15
5/1 + -4/3 = 11/3
5/1 - -4/3 = 19/3
5/1 * -4/3 = -20/3
5/1 / -4/3 = 15/-4

----- Testing arithmetic between fractions and integers
-1/2 + 4 = 7/2
-1/2 - 4 = -9/2
-1/2 * 4 = -4/2
-1/2 / 4 = -1/8
3 + -1/2 = 5/2
3 - -1/2 = 7/2
3 * -1/2 = -3/2
3 / -1/2 = 6/-1

----- Testing shorthand arithmetic assignment on fractions
1/6 += 4/1 = 25/6
25/6 -= 4/1 = 1/6
1/6 *= 4/1 = 4/6
4/6 /= 4/1 = 4/24
4/1 += -1/2 = 7/2
7/2 -= -1/2 = 16/4
16/4 *= -1/2 = -16/8
-16/8 /= -1/2 = -32/-8
-1/2 += 5/1 = 9/2
9/2 -= 5/1 = -1/2
-1/2 *= 5/1 = -5/2
-5/2 /= 5/1 = -5/10

----- Testing shorthand arithmetic assignment using integers
-1/3 += 3 = 8/3
8/3 -= 3 = -1/3
-1/3 *= 3 = -3/3
-3/3 /= 3 = -3/9

----- Testing increment/decrement prefix and postfix
Now g = -1/3
g++ = -1/3
Now g = 2/3
++g = 5/3
Now g = 5/3
g-- = 5/3
Now g = 2/3
--g = -1/3
Now g = -1/3
Press any key to continue . . .
*/