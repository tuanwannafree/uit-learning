#include <algorithm>
#include <bitset>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <unordered_map>
#include <vector>
#define ll long long
#define pb push_back
#define _for(i,a,b) for(int i = a, i < b; i++)
#define _ford(i,a,b) for(int i = a, i > b; i--)
#define ln endl
using namespace std;

class Fraction {
    private:
        int numerator, denominator;
    public:
        void input();
        Fraction sosanh(Fraction f2) const;
        void display();

};

void Fraction::input() {
    cout << "Nhap numrator ";
    cin >> numerator;
    cout << "Nhap denominator ";
    cin >> denominator;
    while( denominator == 0) {
        cout << "Nhap lai";
        cin >> denominator;
    }
}

Fraction Fraction::sosanh( Fraction f2 ) const {
    Fraction c;
    int n,d;
    if(numerator * denominator >= f2.numerator * f2.denominator) {
        c.numerator = numerator;
        c.denominator = denominator;
    } else {
        c.numerator = f2.numerator;
        c.denominator = f2.denominator;
    }
    return c;
}

void Fraction::display() {
    cout << numerator <<"/"<<denominator;
}

int main()
{
	//ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

	Fraction a, b, c;
	a.input();
	b.input();

	c = a.sosanh(b);

	c.display();

	return 0;
}
