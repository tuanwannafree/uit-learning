// Example 2  chuong 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Fraction.h"
using namespace std;

long USCLN(long x, long y) {
    long r;
    x = abs(x);
    y = abs(y);
    if (x == 0 || y == 0) return 1;
    while ((r = x % y) != 0) {
        x = y;
        y = r;
    }
    return y;
}

void Fraction::UocLuoc() {
    long usc = USCLN(numerator, denomitator);
    numerator /= usc;
    denomitator /= usc;
    if (denomitator < 0) denomitator = -denomitator, numerator = -numerator;
    if (numerator == 0) denomitator = 1;
}

void Fraction::Set(long n, long d) {
    if (d) {
        numerator = n;
        denomitator = d;
        UocLuoc();
    }
}

void Fraction::display() const {
    cout << numerator;
    if (numerator != 0 && denomitator != 1) {
        cout << "/" << denomitator;
    }
    cout << endl;
}


Fraction Fraction::operator + (Fraction b) const {
    return Fraction(numerator * b.denomitator + denomitator * b.numerator, denomitator * b.denomitator);
}

Fraction Fraction::operator + (long b) const {
    return Fraction(numerator + b* denomitator, denomitator);
}

Fraction operator + (int a, Fraction b)  {
    return Fraction(a * b.denomitator + b.numerator, b.denomitator);
}

Fraction Fraction::operator - (Fraction b) const {
    return Fraction(numerator * b.denomitator - denomitator * b.numerator, denomitator * b.denomitator);
}

Fraction Fraction::operator - (long b) const {
    return Fraction(numerator - b * denomitator, denomitator);
}

Fraction operator - (int a, Fraction b) {
    return Fraction(a * b.denomitator - b.numerator, b.denomitator);
}

Fraction Fraction::operator * (Fraction b) const {
    return Fraction(numerator * b.numerator, denomitator * b.denomitator);
}

Fraction Fraction::operator * (long b) const {
    return Fraction(numerator * b , denomitator);
}

Fraction operator * (int a, Fraction b) {
    return Fraction(a * b.numerator, b.denomitator);
}

Fraction Fraction::operator / (Fraction b) const {
    if (b.numerator == 0) {
        cout << "Khong the chia cho 0" << endl;
        return Fraction(NULL, NULL);
    }
    return Fraction(numerator * b.denomitator, denomitator * b.numerator);
}

Fraction Fraction::operator / (long b) const {
    if (b == 0) {
        cout << "Khong the chia cho 0" << endl;
        return Fraction(NULL, NULL);
    }
    return Fraction(numerator , denomitator * b);
}

Fraction operator / (int a, Fraction b) {
    if (b.denomitator == 0) {
        cout << "Khong the chia cho 0" << endl;
        return Fraction(NULL, NULL);
    }
    return Fraction(b.numerator, a * b.denomitator);
}

//bool Fraction::operator == (Fraction b) const {
//    return numerator * b.denomitator == denomitator * b.numerator;
//}
//
//bool Fraction::operator == (long b) const {
//    return numerator == b * denomitator;
//}
//
//bool operator == (int a, Fraction b) {
//    return a * b.denomitator == 
//}



int main()
{
    Fraction a(2, 3), b(1 ,4), c(3, 1), d(2,5);
    a = b * -c;
    a.display();
    c = (b + 2) * 2 / a;
    c.display();
    d = a / 3 + (b * c - 2) / 5;
    d.display();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
