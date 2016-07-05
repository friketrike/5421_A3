#include "Fraction.h"

Fraction& Fraction::operator=  (const int& val) {
    numerator = val;
    denominator = 1;
}

Fraction& Fraction::operator+= (const int& val) {
    numerator += (denominator * val);
    reduce();
}

Fraction& Fraction::operator-= (const int& val) { 
    numerator -= (denominator * val);
    normalize();
    reduce();
}

Fraction& Fraction::operator*= (const int& val) {
    numerator *= val;
    normalize();
    reduce();
}

Fraction& Fraction::operator/= (const int& val) {
    denominator *= val;
    normalize();
    reduce();
}

Fraction& Fraction::operator=  (const Fraction& rhs) {
    numerator = rhs.numerator;
    denominator = rhs.denominator;
}

Fraction& Fraction::operator+= (const Fraction& rhs) {
    numerator = (numerator * rhs.denominator) 
        + (rhs.numerator * denominator);
    normalize();
    reduce();
}

Fraction& Fraction::operator-= (const Fraction& rhs) {
    numerator = (numerator * rhs.denominator) 
        - (rhs.numerator * denominator);
    normalize();
    reduce();
}

Fraction& Fraction::operator*= (const Fraction& rhs) {
    numerator *= rhs.numerator;
    denominator *= rhs.denominator;
    normalize();
    reduce();
}

Fraction& Fraction::operator/= (const Fraction& rhs) {
    numerator *= rhs.denominator;
    denominator *= rhs.numerator;
    normalize();
    reduce();
}

Fraction& Fraction::operator++ () {
    numerator += denominator;
    normalize();
    reduce();
}

Fraction& Fraction::operator-- () {
    numerator -= denominator;
    normalize();
    reduce();
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

Fraction Fraction::operator+ (const Fraction& rhs) const {
    Fraction temp = *this;
    temp += rhs;
    return temp;
}

Fraction Fraction::operator- (const Fraction& rhs) const {
    Fraction temp = *this;
    temp -= rhs;
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
    *this *= (denominator < 0) ? -1 : 1;
}

void Fraction::reduce() {
    // TODO this is a fun one...
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
    return ((lhs.getNumerator() == rhs.getNumerator()) 
            && (lhs.getDenominator() == rhs.getDenominator()));
}
bool operator== (const Fraction& lhs, const int& rhs) {
    return ((lhs.getDenominator() == 1) && (lhs.getNumerator() == rhs));
}

bool operator== (const int& lhs, const Fraction& rhs) {
    return ((rhs.getDenominator() == 1) && (lhs == rhs.getNumerator()));
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

istream& operator>> (istream& istr, Fraction& rhs) {
    string stringN;
    getline(istr, stringN, '/');
    rhs.setNumerator(stol(stringN));
    long temp;
    istr >> temp;
    rhs.setDenominator(temp);
    return istr;
}

ostream& operator<< (ostream& ostr, Fraction& rhs) {
    ostr << rhs();
    return ostr;    
}

