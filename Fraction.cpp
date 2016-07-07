#include "Fraction.h"

Fraction& Fraction::operator=  (const int& val) {
    numerator = val;
    denominator = 1;
    return *this;
}

Fraction& Fraction::operator+= (const int& val) {
    numerator += (denominator * val);
    reduce();
    return *this;
}

Fraction& Fraction::operator-= (const int& val) { 
    numerator -= (denominator * val);
    normalize();
    reduce();
    return *this;
}

Fraction& Fraction::operator*= (const int& val) {
    numerator *= val;
    normalize();
    reduce();
    return *this;
}

Fraction& Fraction::operator/= (const int& val) {
    denominator *= val;
    normalize();
    reduce();
    return *this;
}

Fraction& Fraction::operator=  (const Fraction& rhs) {
    numerator = rhs.numerator;
    denominator = rhs.denominator;
    return *this;
}

Fraction& Fraction::operator+= (const Fraction& rhs) {
    numerator = (numerator * rhs.denominator) 
        + (rhs.numerator * denominator);
    denominator = denominator * rhs.denominator;
    normalize();
    reduce();
    return *this;
}

Fraction& Fraction::operator-= (const Fraction& rhs) {
    numerator = (numerator * rhs.denominator) 
        - (rhs.numerator * denominator);
    denominator = denominator * rhs.denominator;
    normalize();
    reduce();
    return *this;
}

Fraction& Fraction::operator*= (const Fraction& rhs) {
    numerator *= rhs.numerator;
    denominator *= rhs.denominator;
    normalize();
    reduce();
    return *this;
}

Fraction& Fraction::operator/= (const Fraction& rhs) {
    numerator *= rhs.denominator;
    denominator *= rhs.numerator;
    normalize();
    reduce();
    return *this;
}

Fraction& Fraction::operator++ () {
    numerator += denominator;
    normalize();
    reduce();
    return *this;
}

Fraction& Fraction::operator-- () {
    numerator -= denominator;
    normalize();
    reduce();
    return *this;
}

string Fraction::operator() () const {
    string s;
    s += "(" + to_string(numerator) + "/" 
        + to_string(denominator) + ")";
    return s;
}

Fraction& Fraction::operator* () {
    return *this;
}

long& Fraction::operator[] (const string& s) {
    return (s == "top") ? numerator : denominator;
}

const long& Fraction::operator[] (const string s) const {
    return (s == "top") ? numerator : denominator;
}

Fraction Fraction::operator+ () const {
    Fraction temp{*this};
    return temp;
}

Fraction Fraction::operator- () const {
    Fraction temp{*this};
    temp *= -1;
    return temp;
}

Fraction Fraction::operator++ (int) {
    Fraction temp{*this};
    ++(*this);
    return temp;
}
Fraction Fraction::operator-- (int) {
    Fraction temp{*this};
    --(*this);
    return temp;
}

void Fraction::normalize() {
    if (denominator < 0) {
        numerator *= -1;
        denominator *= -1;
    }
}

void Fraction::reduce() {
    if (numerator == 0 || denominator == 1) {
        return;
    }
    long n = (numerator > 0) ? numerator : -numerator;
    long d{denominator};
    long exp2{0};
    long gcd;
    // bitwise test for even-ness - find power of two in the gcd decomposition
    while (!(n & 1) && !(d & 1)) {
        n /= 2;
        d /= 2;
        ++exp2;
    }
    while (n != d) {
        if (!(n & 1)) {
            n /= 2;
        } else if (!(d & 1)) {
            d /= 2;
        // the gcd of n and d must also be the gcd of their difference
        } else if (n > d) {
            n = (n-d)/2;
        } else { // d > n
            d = (d-n)/2;
        }
    }
    gcd = n * (1 << exp2);
    numerator /= gcd;
    denominator /= gcd;
}

Fraction operator+ (const Fraction& lhs, const Fraction& rhs) {
    Fraction temp{lhs};
    temp += rhs;
    return temp;
}

Fraction operator+ (const Fraction& lhs, const int& rhs) {
    Fraction temp{lhs};
    temp += rhs;
    return temp;
}

Fraction operator+ (const int& lhs, const Fraction& rhs) {
    Fraction temp{lhs};
    temp += rhs;
    return temp;
}

Fraction operator- (const Fraction& lhs, const Fraction& rhs) {
    Fraction temp{lhs};
    temp -= rhs;
    return temp;
}

Fraction operator- (const Fraction& lhs, const int& rhs) {
    Fraction temp{lhs};
    temp -= rhs;
    return temp;
}

Fraction operator- (const int& lhs, const Fraction& rhs) {
    Fraction temp{lhs};
    temp -= rhs;
    return temp;
}

Fraction operator* (const Fraction& lhs, const Fraction& rhs) {
    Fraction temp{lhs};
    temp *= rhs;
    return temp;
}

Fraction operator* (const Fraction& lhs, const int& rhs) {
    Fraction temp{lhs};
    temp *= rhs;
    return temp;
}

Fraction operator* (const int& lhs, const Fraction& rhs) {
    Fraction temp{lhs};
    temp *= rhs;
    return temp;
}


Fraction operator/ (const Fraction& lhs, const Fraction& rhs) {
    Fraction temp{lhs};
    temp /= rhs;
    return temp;
}

Fraction operator/ (const Fraction& lhs, const int& rhs) {
    Fraction temp{lhs};
    temp /= rhs;
    return temp;
}

Fraction operator/ (const int& lhs, const Fraction& rhs) {
    Fraction temp{lhs};
    temp /= rhs;
    return temp;
}


bool operator== (const Fraction& lhs, const Fraction& rhs) {
    return ((lhs.getNumerator() * rhs.getDenominator()) 
            == (rhs.getNumerator() * lhs.getDenominator()));
}
bool operator== (const Fraction& lhs, const int& rhs) {
    return ((lhs.getDenominator() * rhs) == lhs.getNumerator());
}

bool operator== (const int& lhs, const Fraction& rhs) {
    return ((rhs.getDenominator() * lhs) == rhs.getNumerator());
}

bool operator!= (const Fraction& lhs, const Fraction& rhs) {
    return !(lhs == rhs);
}

bool operator!= (const Fraction& lhs, const int& rhs) {
    return !(lhs == rhs);
}
bool operator!= (const int& lhs, const Fraction& rhs) {
    return !(lhs == rhs);
}

bool operator< (const Fraction& lhs, const Fraction& rhs) {
    return ((lhs.getNumerator() * rhs.getDenominator()) 
            < (lhs.getDenominator() * rhs.getNumerator()));
}

bool operator< (const Fraction& lhs, const int& rhs) {
    return (lhs.getNumerator() < (lhs.getDenominator() * rhs));
}

bool operator< (const int& lhs, const Fraction& rhs) {
    return ((lhs * rhs.getDenominator()) < rhs.getNumerator());
}

bool operator<= (const Fraction& lhs, const Fraction& rhs) {
    return !(lhs > rhs);
}

bool operator<= (const Fraction& lhs, const int& rhs) {
    return !(lhs > rhs);
}

bool operator<= (const int& lhs, const Fraction& rhs) {
    return !(lhs > rhs);
}


bool operator> (const Fraction& lhs, const Fraction& rhs) {
    return rhs < lhs;
}

bool operator> (const Fraction& lhs, const int& rhs) {
    return rhs < lhs;
}

bool operator> (const int& lhs, const Fraction& rhs) {
    return rhs < lhs;
}

bool operator>= (const Fraction& lhs, const Fraction& rhs) {
    return !(lhs < rhs);
}

bool operator>= (const Fraction& lhs, const int& rhs) {
    return !(lhs < rhs);
}

bool operator>= (const int& lhs, const Fraction& rhs) {
    return !(lhs < rhs);
}

istream& operator>> (istream& istr, Fraction& rhs) {
    // this is nicer, takes num/den from cin, but we're following specs
    /*string stringN;
    getline(istr, stringN, '/');
    rhs.setNumerator(std::stol(stringN));*/
    long temp;
    cout << "numerator? ";
    istr >> temp;
    rhs.setNumerator(temp);
    cout << "denominator? ";
    istr >> temp;
    rhs.setDenominator(temp);
    rhs.normalize();
    rhs.reduce();
    return istr;
}

ostream& operator<< (ostream& ostr, const Fraction& rhs) {
    string s;
    if (rhs.getNumerator() == 0) {
        s = "0";
    } else if (rhs.getDenominator() == 1) {
        s = to_string(rhs.getNumerator());
    } else {
        s = to_string(rhs.getNumerator()) + "/" 
            + to_string(rhs.getDenominator());
    }
    ostr << s;
    return ostr;    
}

