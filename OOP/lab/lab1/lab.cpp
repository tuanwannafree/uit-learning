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
        void rutgon();
        void display();
};

int ucln(int a, int b) {
    while(b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void Fraction::input() {
    cout << "Nhap numrator ";
    cin >> numerator ;
    cout << "Nhap denominator ";
    cin >> denominator;
    while(denominator == 0) {
        cout << "Nhap lai";
        cin >> denominator;
    }

}

void Fraction::rutgon() {
    int tmp = ucln( numerator, denominator);
    numerator = numerator / tmp;
    denominator = denominator / tmp;
}

void Fraction::display() {
    if(denominator == 1) {
        cout << numerator;
    } else {
        cout << numerator << "/" << denominator;
    }
    //

}



int main()
{
	//ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    Fraction a;
    a.input();
    cout << "Phan so sau khi duoc rut gon" << endl;
    a.rutgon();
    a.display();



	return 0;
}
