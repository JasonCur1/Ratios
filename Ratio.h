#include <iostream>
#include <vector>
#include <cstdlib>
#include "stdio.h"

#ifndef RATIO_INCLUDED
#define RATIO_INCLUDED

class Ratio {
    public:
        Ratio() = delete; // forbidden
        Ratio(float f) = delete; // forbidden
        Ratio(double d) = delete; // forbidden
        Ratio(long double ld) = delete; // forbidden
        Ratio(long n) : num(n), den(1) {}
        Ratio(long n, long d) : num(n), den(d) { normalize(num, den); if (d == 0) throw std::runtime_error("divisor of zero"); }
        Ratio(int n) : num(n), den(1) {}
        Ratio(int n, int d) : num(n), den(d) { normalize(num, den); if (d == 0) throw std::runtime_error("divisor of zero"); }

        Ratio(const Ratio &ob) { // copy ctor
            this->num = ob.num;
            this->den = ob.den;
        }

        Ratio &operator=(const Ratio &ob) { // assignment operator
            num = ob.num;
            den = ob.den;
            return *this;
        }

        Ratio operator+(Ratio rhs) const;
        Ratio operator-(Ratio rhs) const;
        Ratio operator*(Ratio rhs) const;
        Ratio operator/(Ratio rhs) const;

        Ratio operator+(long rhs) const;
        Ratio operator-(long rhs) const;
        Ratio operator*(long rhs) const;
        Ratio operator/(long rhs) const;

        void operator+=(Ratio rhs);
        void operator-=(Ratio rhs);
        void operator*=(Ratio rhs);
        void operator/=(Ratio rhs);

        void operator+=(long rhs);
        void operator-=(long rhs);
        void operator*=(long rhs);
        void operator/=(long rhs);

        bool operator==(const Ratio rhs) const;
        bool operator!=(const Ratio rhs) const; 
        bool operator<(const Ratio rhs) const; 
        bool operator<=(const Ratio rhs) const; 
        bool operator>(const Ratio rhs) const; 
        bool operator>=(const Ratio rhs) const;        

        bool operator==(long double rhs) const;
        bool operator!=(long double rhs) const; 
        bool operator<(long double rhs) const; 
        bool operator<=(long double rhs) const; 
        bool operator>(long double rhs) const; 
        bool operator>=(long double rhs) const;   
        
        ~Ratio() = default;
        long numerator() const;
        void numerator(long x);
        long denominator() const;
        void denominator(long x);
        long double ratio() const;
        Ratio add(Ratio r1, Ratio r2=Ratio(0), Ratio r3=Ratio(0), Ratio r4=Ratio(0), Ratio r5=Ratio(0), Ratio r6=Ratio(0), Ratio r7=Ratio(0), Ratio r8=Ratio(0)) const;
        Ratio subtract(Ratio r) const;
        Ratio multiply(Ratio r) const;
        Ratio divide(Ratio r) const;
        int compare(Ratio r) const;
        int compare(long double x) const;

        long gcd(long x, long y) const; // helper function
        void normalize(long &num, long &den) const; // helper function

        friend std::ostream &operator << (std::ostream &os, Ratio &r);
        friend std::ostream &operator << (std::ostream &os, const Ratio &r);
        friend std::istream &operator >> (std::istream &is, Ratio &r);
    
    private:
        long num, den;

};

// takes a long and a ratio
Ratio operator+(long lhs, Ratio rhs);
Ratio operator-(long lhs, Ratio rhs);
Ratio operator*(long lhs, Ratio rhs);
Ratio operator/(long lhs, Ratio rhs);

bool operator==(long double lhs, const Ratio rhs);
bool operator!=(long double lhs, const Ratio rhs);
bool operator<(long double lhs, const Ratio rhs);
bool operator<=(long double lhs, const Ratio rhs);
bool operator>(long double lhs, const Ratio rhs);
bool operator>=(long double lhs, const Ratio rhs);

#endif