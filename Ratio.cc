#include "Ratio.h"
#include <stdexcept>
#include <vector>
#include "stdio.h"

long Ratio::numerator() const {
    return num;
}

void Ratio::numerator(long x) {
    num = x;
    normalize(num, den);
}

long Ratio::denominator() const {
    return den;
}

void Ratio::denominator(long x) {
    if (x == 0) {
        throw std::runtime_error("divisor of zero");
    } else {
        den = x;
        normalize(num, den);
    }
}

long double Ratio::ratio() const {
    long double x = this->numerator();
    long double y = this->denominator();
    return x/y;
}

Ratio Ratio::operator+(Ratio rhs) const {
    Ratio currRatio(*this);

    return Ratio(currRatio.numerator()*rhs.denominator()+rhs.numerator()*currRatio.denominator(), currRatio.denominator()*rhs.denominator());
}

Ratio Ratio::operator-(Ratio rhs) const {
    Ratio currRatio(*this);

    return Ratio((currRatio.numerator()*rhs.denominator())-rhs.numerator()*currRatio.denominator(), currRatio.denominator()*rhs.denominator());
}

Ratio Ratio::operator*(Ratio rhs) const {
    Ratio currRatio(*this);

    return Ratio(currRatio.numerator()*rhs.numerator(), currRatio.denominator()*rhs.denominator());
}

Ratio Ratio::operator/(Ratio rhs) const {
    Ratio currRatio(*this);

    long numer = currRatio.numerator()*rhs.denominator();
    long denom = currRatio.denominator()*rhs.numerator();

    if (denom == 0) {
        throw std::runtime_error("divisor of zero");
    }

    return Ratio(numer, denom);
}

Ratio Ratio::operator+(long rhs) const {
    return Ratio(*this) + Ratio(rhs);
}

Ratio Ratio::operator-(long rhs) const {
    return Ratio(*this) - Ratio(rhs);
}

Ratio Ratio::operator*(long rhs) const {
    return Ratio(*this) * Ratio(rhs);
}

Ratio Ratio::operator/(long rhs) const {
    return Ratio(*this) / Ratio(rhs);
}

Ratio operator+(long lhs, Ratio rhs)  {
    return Ratio(lhs) + rhs;
}

Ratio operator-(long lhs, Ratio rhs)  {
    return Ratio(lhs) - rhs;
}

Ratio operator*(long lhs, Ratio rhs)  {
    return Ratio(lhs) * rhs;
}

Ratio operator/(long lhs, Ratio rhs)  {
    return Ratio(lhs) / rhs;
}

void Ratio::operator+=(Ratio rhs) {
    Ratio currRatio(*this);

    this->denominator(currRatio.denominator()*rhs.denominator());
    this->numerator(currRatio.numerator()*rhs.denominator()+rhs.numerator()*currRatio.denominator());
}

void Ratio::operator-=(Ratio rhs) {
    Ratio currRatio(*this);

    this->denominator(currRatio.denominator()*rhs.denominator());
    this->numerator(currRatio.numerator()*rhs.denominator()-rhs.numerator()*currRatio.denominator());
}

void Ratio::operator*=(Ratio rhs) {
    Ratio currRatio(*this);

    this->denominator(currRatio.denominator()*rhs.denominator());
    this->numerator(currRatio.numerator()*rhs.numerator());
}

void Ratio::operator/=(Ratio rhs) {
    Ratio currRatio(*this);

    long numer = currRatio.numerator()*rhs.denominator();
    long denom = currRatio.denominator()*rhs.numerator();

    if (denom == 0) {
        throw std::runtime_error("divisor of zero");
    }

    this->denominator(denom);
    this->numerator(numer);
}

void Ratio::operator+=(long rhs) {
    Ratio currRatio(*this);

    this->denominator(currRatio.denominator());
    this->numerator(currRatio.numerator()+(currRatio.denominator()*rhs));
}

void Ratio::operator-=(long rhs) {
    Ratio currRatio(*this);

    this->denominator(currRatio.denominator());
    this->numerator(currRatio.numerator()-(currRatio.denominator()*rhs)); // num - (den * rhs)
}

void Ratio::operator*=(long rhs) {
    Ratio currRatio(*this);

    this->denominator(currRatio.denominator());
    this->numerator(currRatio.numerator()*rhs);
}

void Ratio::operator/=(long rhs) {
    Ratio currRatio(*this);

    long numer = currRatio.numerator();
    long denom = currRatio.denominator()*rhs;

    if (denom == 0) {
        throw std::runtime_error("divisor of zero");
    }

    this->denominator(denom);
    this->numerator(numer);
}

bool Ratio::operator==(const Ratio rhs) const {
    return Ratio(*this).ratio() == rhs.ratio();
}

bool Ratio::operator!=(const Ratio rhs) const {
    return Ratio(*this).ratio() != rhs.ratio();
}

bool Ratio::operator<(const Ratio rhs) const {
    return Ratio(*this).ratio() < rhs.ratio();
}

bool Ratio::operator<=(const Ratio rhs) const {
    return Ratio(*this).ratio() <= rhs.ratio();
}

bool Ratio::operator>(const Ratio rhs) const {
    return Ratio(*this).ratio() > rhs.ratio();
}

bool Ratio::operator>=(const Ratio rhs) const {
    return Ratio(*this).ratio() >= rhs.ratio();
}

bool Ratio::operator==(long double rhs) const {
    return Ratio(*this).ratio() == rhs;
}

bool Ratio::operator!=(long double rhs) const {
    return Ratio(*this).ratio() != rhs;
}

bool Ratio::operator<(long double rhs) const {
    return Ratio(*this).ratio() < rhs;
}

bool Ratio::operator<=(long double rhs) const {
    return Ratio(*this).ratio() <= rhs;
}

bool Ratio::operator>(long double rhs) const {
    return Ratio(*this).ratio() > rhs;
}

bool Ratio::operator>=(long double rhs) const {
    return Ratio(*this).ratio() >= rhs;
}

bool operator==(long double lhs, const Ratio rhs) {
    return lhs == rhs.ratio();
}

bool operator!=(long double lhs, const Ratio rhs) {
    return lhs != rhs.ratio();
}

bool operator<(long double lhs, const Ratio rhs) {
    return lhs < rhs.ratio();
}

bool operator<=(long double lhs, const Ratio rhs) {
    return lhs <= rhs.ratio();
}

bool operator>(long double lhs, const Ratio rhs) {
    return lhs > rhs.ratio();
}

bool operator>=(long double lhs, const Ratio rhs) {
    return lhs >= rhs.ratio();
}

// Credit: https://www.tutorialspoint.com/cplusplus-program-to-find-gcd
long Ratio::gcd(long x, long y) const {
    x = abs(x);
    y = abs(y);
    long gcd = 1;

    if (y > x) {
        long temp = y;
        y = x;
        x = temp;
    }

    for (long i = 1; i <= y; ++i) {
        if (x % i == 0 && y % i == 0) {
            gcd = i;
        }
    }

    return gcd;
}

void Ratio::normalize(long &x, long &y) const {
    if (x == 0) {
        y = 1;
    }

    if ((x < 0 && y < 0) || (x >= 0 && y < 0)) { // -2/-4 -> 2/4 | 2/-4 -> -2/4
        x *= -1;
        y *= -1;
    }

    long d = gcd(x,y);

    x = x / d;
    y = y / d;
}

std::ostream &operator<<(std::ostream &os, Ratio &ratio) {
    return os << ratio.numerator() << "/" << ratio.denominator();
}

std::ostream &operator<<(std::ostream &os, const Ratio &ratio) {
    Ratio x(ratio);
    return os << x.numerator() << "/" << x.denominator();
}

std::istream &operator>>(std::istream &is, Ratio &r) {
    std::string n, d;
    bool slashEncountered = false;
    char c;

    while (is.get(c)) {
        if (c == '/') {
            slashEncountered = true;
            continue;
        } else if (c == '+') { // skip + signs to make error checking easier
            continue;
        } else if (slashEncountered) {
            if (isspace(c) && d != "" && d.find_first_not_of(' ') != d.npos) { // if we find a space after the denominator, break
                break;
            }

            if (!isdigit(c) && c != '-' && !isspace(c)) { // detect invalid denominator char
                is.setstate(std::ios_base::failbit);
                return is;
            }

            d += c;
        } else {
            if (!isdigit(c) && c != '-' && !isspace(c)) { // detect invalid numerator char
                is.setstate(std::ios_base::failbit);
                return is;
            }

            n += c;
        }
    }

    if (d != "" && stol(d) == 0) {
        is.setstate(std::ios_base::failbit);
        throw std::runtime_error("divisor of zero");
        return is;
    }

    if (n == "" || d == "") {
        is.setstate(std::ios_base::failbit);
    } else {
        r = Ratio(stol(n), stol(d));
    }
    
    return is;
}