

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
    #include <cassert>
    assert(den != 0);
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
