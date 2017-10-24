/* Myron Pow, CS2B, 7/7/2015, Dave Harden, Fraction.h
Program simulates fractional symbolics.
No input is provided by a user, as it is preprepared in a client,
and the output is printed streams throughly testing the class
*/

/*
Precondition:
Constructor of the fraction class. It can take up to two ints
and the ints will be used as the numerator and the denominator respectively.
Poscondition:
The constructor will output a fraction with the two ints,
with a default value of 0/1

    fraction(int num = 0, int den = 1);



Precondition: The input must be an object of the fraction class
Postcondition: The output is a ostream formatted and ready for printing(no endl)

    friend std::ostream& operator<<(std::ostream &os, const fraction &fract1);



Precondition: It takes data of type istream
Postcondition: It attempts to format the istream into a fraction.
Has mixed results interacting with mixed fractions

    friend std::istream& operator>>(std::istream &is, fraction &fract1);



Precondition: Any input should be numerical data
Postcondition: result will be in the form of a simple improper fraction

    friend fraction operator+(const fraction &fract1, const fraction &fract2);



Precondition: Any input should be numerical data
Postcondition: result will be in the form of a simple improper fraction

    friend fraction operator-(const fraction &fract1, const fraction &fract2);



Precondition: Any input should be numerical data
Postcondition: result will be in the form of a simple improper fraction

    friend fraction operator*(const fraction &fract1, const fraction &fract2);



Precondition: Any input should be numerical data
Postcondition: result will be in the form of a simple improper fraction

    friend fraction operator/(const fraction &fract1, const fraction &fract2);



Precondition: left hand side of operator should be a fraction
Postcondition: result should be a fraction object (simple & improper)

    friend fraction operator+=(fraction &fract1, const fraction &fract2);



Precondition: left hand side of operator should be a fraction
Postcondition: result should be a fraction object (simple & improper)

    friend fraction operator-=(fraction &fract1, const fraction &fract2);



Precondition: left hand side of operator should be a fraction
Postcondition: result should be a fraction object (simple & improper)

    friend fraction operator*=(fraction &fract1, const fraction &fract2);



Precondition: left hand side of operator should be a fraction
Postcondition: result should be a fraction object (simple & improper)

    friend fraction operator/=(fraction &fract1, const fraction &fract2);



Precondition: Numerical data only, on either side
Postcondition, boolean(t/f) relationship 

    friend bool operator<(const fraction &fract1, const fraction &fract2);



    Precondition: Numerical data only, on either side
Postcondition, boolean(t/f) relationship 

    friend bool operator<=(const fraction &fract1, const fraction &fract2);



Precondition: Numerical data only, on either side
Postcondition, boolean(t/f) relationship 

    friend bool operator>(const fraction &fract1, const fraction &fract2);



Precondition: Numerical data only, on either side
Postcondition, boolean(t/f) relationship 

    friend bool operator>=(const fraction &fract1, const fraction &fract2);



Precondition: Numerical data only, on either side
Postcondition, boolean(t/f) relationship 

    friend bool operator==(const fraction &fract1, const fraction &fract2);



Precondition: Numerical data only, on either side
Postcondition, boolean(t/f) relationship 

    friend bool operator!=(const fraction &fract1, const fraction &fract2);



Precondition: Object of type fraction
Postcondition: increment of 1, positive, before eval

    fraction operator++();



Precondition: Object of type fraction
Postcondition: increment of +1 post eval

    fraction operator++(int);



Precondition: Object of type fraction
Postcondition: increment of -1, pre-eval

    fraction operator--();



Precondition: Object of type fraction
Postcondition: increment of 1, negative, post eval

    fraction operator--(int);




Precondition: Fraction Object
Postcondition: Simplfied Fraction object

    void simplify();

*/
#include <iostream>
#ifndef fract
#define fract
namespace cs2b_fraction
{

class fraction
{
    int numerator;
    int denominator;
public:
    //constructor
    fraction(int num = 0, int den = 1);

    // stream combiner?
    friend std::ostream& operator<<(std::ostream &os, const fraction &fract1);

    // extraction operator
    friend std::istream& operator>>(std::istream &is, fraction &fract1);

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

    //Simplfiy fractions
    void simplify();
};
}
#endif

/* RUN
----- Testing basic fraction creation & printing
(fractions should be in reduced form, and as mixed numbers.)
fraction [0] = 1/2
fraction [1] = -5/7
fraction [2] = 10
fraction [3] = -4
fraction [4] = 0
fraction [5] = 4+2/3
fraction [6] = 0

----- Now reading fractions from file
Read fraction = 1/3
Read fraction = 1/2
Read fraction = 3/4
Read fraction = -4/5
Read fraction = 6
Read fraction = 5
Read fraction = -8
Read fraction = 1+2/5
Read fraction = -16+2/3
Read fraction = 2
Read fraction = -858993460

----- Testing relational operators between fractions
Comparing 1/2 to 1/2
        Is left < right? false
        Is left <= right? true
        Is left > right? false
        Is left >= right? true
        Does left == right? true
        Does left != right ? false
Comparing 1/2 to -1/2
        Is left < right? false
        Is left <= right? false
        Is left > right? true
        Is left >= right? true
        Does left == right? false
        Does left != right ? true
Comparing -1/2 to 1/10
        Is left < right? true
        Is left <= right? true
        Is left > right? false
        Is left >= right? false
        Does left == right? false
        Does left != right ? true
Comparing 1/10 to 0
        Is left < right? false
        Is left <= right? false
        Is left > right? true
        Is left >= right? true
        Does left == right? false
        Does left != right ? true
Comparing 0 to 0
        Is left < right? false
        Is left <= right? true
        Is left > right? false
        Is left >= right? true
        Does left == right? true
        Does left != right ? false

----- Testing relations between fractions and integers
Comparing -1/2 to 2
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
1/6 + 1/3 = 1/2
1/6 - 1/3 = -1/6
1/6 * 1/3 = 1/18
1/6 / 1/3 = 1/2
1/3 + -2/3 = -1/3
1/3 - -2/3 = 1
1/3 * -2/3 = -2/9
1/3 / -2/3 = -1/2
-2/3 + 5 = 4+1/3
-2/3 - 5 = -5+2/3
-2/3 * 5 = -3+1/3
-2/3 / 5 = -2/15
5 + -1+1/3 = 3+2/3
5 - -1+1/3 = 6+1/3
5 * -1+1/3 = -6+2/3
5 / -1+1/3 = -3+3/4

----- Testing arithmetic between fractions and integers
-1/2 + 4 = 3+1/2
-1/2 - 4 = -4+1/2
-1/2 * 4 = -2
-1/2 / 4 = -1/8
3 + -1/2 = 2+1/2
3 - -1/2 = 3+1/2
3 * -1/2 = -1+1/2
3 / -1/2 = -6

----- Testing shorthand arithmetic assignment on fractions
1/6 += 4 = 4+1/6
4+1/6 -= 4 = 1/6
1/6 *= 4 = 2/3
2/3 /= 4 = 1/6
4 += -1/2 = 3+1/2
3+1/2 -= -1/2 = 4
4 *= -1/2 = -2
-2 /= -1/2 = 4
-1/2 += 5 = 4+1/2
4+1/2 -= 5 = -1/2
-1/2 *= 5 = -2+1/2
-2+1/2 /= 5 = -1/2

----- Testing shorthand arithmetic assignment using integers
-1/3 += 3 = 2+2/3
2+2/3 -= 3 = -1/3
-1/3 *= 3 = -1
-1 /= 3 = -1/3

----- Testing increment/decrement prefix and postfix
Now g = -1/3
g++ = -1/3
Now g = 2/3
++g = 1+2/3
Now g = 1+2/3
g-- = 1+2/3
Now g = 2/3
--g = -1/3
Now g = -1/3
Press any key to continue . . .
*/