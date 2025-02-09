#pragma once
class Fraction
{
	private:
		int numerator;
		int denominator;
	public:
		void input();
		Fraction add(Fraction a);
		Fraction sub(Fraction a);
		Fraction mult(Fraction a);
		Fraction div(Fraction a);
		void display();
};

