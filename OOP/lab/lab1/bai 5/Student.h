#pragma once
class Student
{
	private:
		char name[25];
		int mathScore;
		int literatureScore;
		double average;
	public:
		void input();
		void caculate();
		void display();

};

