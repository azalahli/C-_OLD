
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