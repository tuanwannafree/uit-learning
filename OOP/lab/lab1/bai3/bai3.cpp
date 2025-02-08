// bai3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Fraction.h"
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void Fraction::rutgon() {
    int tmp = gcd(numerator, denominator);
    numerator = numerator / tmp;
    denominator = denominator / tmp;
}

void Fraction::input() {
    cout << "Nhap numrator ";
    cin >> numerator;
    cout << "Nhap denominator ";
    cin >> denominator;
    while (denominator == 0) {
        cout << "Nhap lai ";
        cin >> denominator;
    }

}

void Fraction::display() {
    if (denominator == 1) {
        cout << numerator << endl;
    }
    else {
        cout << numerator << " / " << denominator;
        cout << endl;
    }
}

Fraction Fraction::add(Fraction a) const {
    Fraction c;
    c.numerator = numerator * a.denominator + denominator * a.numerator;
    c.denominator = denominator * a.denominator;
    c.rutgon();
    return c;
}

Fraction Fraction::sub(Fraction a) const {
    Fraction c;
    c.numerator = numerator * a.denominator - denominator * a.numerator;
    c.denominator = denominator * a.denominator;
    c.rutgon();
    return c;
}

Fraction Fraction::mult(Fraction a) const {
    Fraction c;
    c.numerator = numerator * a.numerator;
    c.denominator = denominator * a.denominator;
    c.rutgon();
    return c;
}

Fraction Fraction::div(Fraction a) const {
    if (a.numerator == 0) {
        cout << "Khong the thuc hien" << endl;
    }
    else {
        Fraction c;
        c.numerator = numerator * a.denominator;
        c.denominator = denominator * a.numerator;
        c.rutgon();
        return c;
    }
}

int main()
{
    //cout << "Hello World!\n";
    Fraction a, b, addc, subc, multc, divc;
    a.input();
    b.input();
    addc = a.add(b);
    subc = a.sub(b);
    multc = a.mult(b);
    divc = a.div(b);
    addc.display();
    subc.display();
    multc.display();
    divc.display();
   
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
