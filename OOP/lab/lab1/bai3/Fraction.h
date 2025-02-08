#pragma once
class Fraction
{
	private: 
		int numerator;
		int denominator;

	public:
		//Fraction(int n = 0, int d = 1);
		Fraction add(Fraction f2) const;
		Fraction sub(Fraction f2) const;
		Fraction mult(Fraction f2) const;
		Fraction div(Fraction f2) const;
		void rutgon();
		void input();
		void display();
};

