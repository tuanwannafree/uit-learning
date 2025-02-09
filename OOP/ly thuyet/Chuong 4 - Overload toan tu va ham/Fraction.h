#pragma once
class Fraction
{
	private:
		long numerator, denomitator;
		void UocLuoc();
	public:
		Fraction(long n, long d) {
			Set(n, d);
		}
		void Set(long n, long d);
		long GetNumerator() const {
			return this->numerator;
		}
		long GetDenomitator() const {
			return this->denomitator;
		}
		Fraction add(Fraction b) const;
		Fraction operator + (Fraction b) const;

		Fraction operator - () const {
			return Fraction(-numerator, denomitator);
		}
		Fraction sub(Fraction b) const;
		Fraction operator - (Fraction b) const;
		Fraction mult(Fraction b) const;
		Fraction operator * (Fraction b) const;
		Fraction div(Fraction b) const;
		Fraction operator / (Fraction b) const;
		bool operator == (Fraction b) const;
		bool operator != (Fraction b) const;
		void display() const;
};

