#ifndef FRACTION
#define FRACTION

#include <iostream> 
#include <string>

using namespace std;

class Fraction {
  private:
    long numerator;
    long denominator;

  public:
    Fraction(const long& n = 0, const long& d = 1) 
        : numerator(n)
        , denominator(d) {normalize(); reduce();}

    const long& getNumerator() const { return numerator; }
    const long& getDenominator() const { return denominator; }

    void setNumerator(const long& n) { numerator = n; }
    void setDenominator(const long& d) { denominator = d; }

    void normalize();
    void reduce();

    Fraction& operator=  (const int& val);  // f =  i
    Fraction& operator+= (const int& val);  // f += i 
    Fraction& operator-= (const int& val);  // f -= i 
    Fraction& operator*= (const int& val);  // f *= i 
    Fraction& operator/= (const int& val);  // f /= i 

    Fraction& operator=  (const Fraction& rhs);  // f =  i
    Fraction& operator+= (const Fraction& rhs);  // f += i 
    Fraction& operator-= (const Fraction& rhs);  // f -= i 
    Fraction& operator*= (const Fraction& rhs);  // f *= i 
    Fraction& operator/= (const Fraction& rhs);  // f /= i 

    Fraction& operator++ ();  // ++f
    Fraction& operator-- ();  // --f 

    string operator() () const; // returns the string version of this fraction
    Fraction& operator* (); // behave like a pointer, returns *this

    // [s] returns the numerator if s==ẗop; otherwise returns denominator
    long& operator[] (const string& s);
    const long& operator[] (const string s) const;

    Fraction operator+ () const; // +f
    Fraction operator- () const; // -f

    Fraction operator++ (int);  // f++
    Fraction operator-- (int);  // f--
};

Fraction operator+ (const Fraction& lhs, const Fraction& rhs);  // f + f
Fraction operator+ (const Fraction& lhs, const int& rhs);  // f + i
Fraction operator+ (const int& lhs, const Fraction& rhs);  // i + f

Fraction operator- (const Fraction& lhs, const Fraction& rhs);  // f - f
Fraction operator- (const Fraction& lhs, const int& rhs);  // f - i
Fraction operator- (const int& lhs, const Fraction& rhs);  // i - f

Fraction operator* (const Fraction& lhs, const Fraction& rhs);  // f * f
Fraction operator* (const Fraction& lhs, const int& rhs);  // f * i
Fraction operator* (const int& lhs, const Fraction& rhs);  // i * f

Fraction operator/ (const Fraction& lhs, const Fraction& rhs);  // f / f
Fraction operator/ (const Fraction& lhs, const int& rhs);  // f / i
Fraction operator/ (const int& lhs, const Fraction& rhs);  // i / f

bool operator== (const Fraction& lhs, const Fraction& rhs);  // f == f
bool operator== (const Fraction& lhs, const int& rhs);  // f == i
bool operator== (const int& lhs, const Fraction& rhs);  // i == f

bool operator!= (const Fraction& lhs, const Fraction& rhs);  // f != f
bool operator!= (const Fraction& lhs, const int& rhs);  // f != i
bool operator!= (const int& lhs, const Fraction& rhs);  // i != f

bool operator< (const Fraction& lhs, const Fraction& rhs);  // f < f
bool operator< (const Fraction& lhs, const int& rhs);  // f < i
bool operator< (const int& lhs, const Fraction& rhs);  // i < f

bool operator<= (const Fraction& lhs, const Fraction& rhs);  // f <= f
bool operator<= (const Fraction& lhs, const int& rhs);  // f <= i
bool operator<= (const int& lhs, const Fraction& rhs);  // i <= f

bool operator> (const Fraction& lhs, const Fraction& rhs);  // f > f
bool operator> (const Fraction& lhs, const int& rhs);  // f > i
bool operator> (const int& lhs, const Fraction& rhs);  // i > f

bool operator>= (const Fraction& lhs, const Fraction& rhs);  // f >= f
bool operator>= (const Fraction& lhs, const int& rhs);  // f >= i
bool operator>= (const int& lhs, const Fraction& rhs);  // i >= f

bool operator== (const Fraction& lhs, const Fraction& rhs);  // f == f
bool operator== (const Fraction& lhs, const int& rhs);  // f == i
bool operator== (const int& lhs, const Fraction& rhs);  // i == f

istream& operator>> (istream& istr, Fraction& rhs);
ostream& operator<< (ostream& ostr, const Fraction& rhs);

#endif
