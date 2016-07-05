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

bool operator== (const Fraction& lhs, const Fraction& rhs) {
    return ((lhs.numerator == rhs numerator) 
            && (lhs.denominator == rhs.denominator));
}
bool operator== (const Fraction& lhs, const int& rhs) {
    return ((lhs.denominator == 1) && (lhs.numerator == rhs.numerator));
}

bool operator== (const int& lhs, const Fraction& rhs) {
    return rhs == lhs;
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

istream& operator>> (istream istr, Fraction& rhs);
ostream& operator>> (ostream ostr, Fraction& rhs);


