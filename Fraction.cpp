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
    s = s + "(" + to_string(numerator) + "/" + to_string(denominator) + ")";
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
    Fraction temp = *this;
    return temp;
}

Fraction Fraction::operator- () const {
    Fraction temp = *this;
    temp *= -1;
    return temp;
}

Fraction Fraction::operator++ (int) {
    Fraction temp = *this;
    ++(*this);
    return temp;
}
Fraction Fraction::operator-- (int) {
    Fraction temp = *this;
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
    // TODO this is a fun one...
    if (numerator == 0 || denominator == 1) {
        return;
    }
    long n = (numerator > 0) ? numerator : -numerator;
    long d{denominator};
    long exp2{0};
    long gcd;
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
    Fraction temp{lhs}; // TODO assignment for initialization elsewhere
    temp += rhs;
    return temp;
}

Fraction operator+ (const Fraction& lhs, const int& rhs) {
    Fraction temp{lhs}; // TODO assignment for initialization elsewhere
    temp += rhs;
    return temp;
}

Fraction operator+ (const int& lhs, const Fraction& rhs) {
    Fraction temp{lhs}; // TODO assignment for initialization elsewhere
    temp += rhs;
    return temp;
}

Fraction operator- (const Fraction& lhs, const Fraction& rhs) {
    Fraction temp{lhs}; // TODO assignment for initialization elsewhere
    temp -= rhs;
    return temp;
}

Fraction operator- (const Fraction& lhs, const int& rhs) {
    Fraction temp{lhs}; // TODO assignment for initialization elsewhere
    temp -= rhs;
    return temp;
}

Fraction operator- (const int& lhs, const Fraction& rhs) {
    Fraction temp{lhs}; // TODO assignment for initialization elsewhere
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
    string stringN;
    getline(istr, stringN, '/');
    rhs.setNumerator(std::stol(stringN));
    long temp;
    istr >> temp;
    rhs.setDenominator(temp);
    return istr;
}

ostream& operator<< (ostream& ostr, const Fraction& rhs) {
    ostr << rhs();
    return ostr;    
}

