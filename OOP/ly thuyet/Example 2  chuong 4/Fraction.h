#pragma once
class Fraction
{
	private:
		long numerator, denomitator;
		void UocLuoc();
	public:
		Fraction(long n, long d) { Set(n, d); }
		void Set(long n, long d);
		Fraction operator + (Fraction b) const;
		Fraction operator + (long b) const; 
		friend Fraction operator + (int a, Fraction b);
		Fraction operator - () const {
			return Fraction(-numerator, denomitator);
		}
		Fraction operator - (Fraction b) const;
		Fraction operator - (long b) const;
		friend Fraction operator - (int a, Fraction b);
		Fraction operator * (Fraction b) const;
		Fraction operator * (long b) const;
		friend Fraction operator * (int a, Fraction b);
		Fraction operator / (Fraction b) const;
		Fraction operator / (long b) const;
		friend Fraction operator / (int a, Fraction b);
		//bool operator == (Fraction b) const;
		//bool operator == (long b) const;
		//friend bool operator == (long a, Fraction b);
		//bool operator != (Fraction b) const;
		//bool operator != (long b) const;
		//friend bool operator != (long a, Fraction b);
		//bool operator < (Fraction b) const;
		//bool operator < (long b) const;
		//friend bool operator < (long a, Fraction b);
		//bool operator > (Fraction b) const;
		//bool operator > (long b) const;
		//friend bool operator > (long a, Fraction b);
		void display() const;

};

