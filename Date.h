#include<iostream>
#include<string>
using namespace std;

class Date{
	friend ostream& operator<<(ostream& out,const Date & d)
	{
		static string monthNames[13] = { "", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
		out<<monthNames[d.month];
		out<<" "<<d.date;
		out<<", "<<d.year;
		out<<endl;

		return out;
	}
	friend istream& operator>>(istream& in,Date & d)
	{
		in>>d.month;
		in>>d.date;
		in>>d.year;

		return in;
	}
private:
	int month;
	int year;
	int date;
public:
	Date(int m,int d, int y);
	Date();
	bool operator==(const Date & d);
	Date operator+(int s);
	Date operator=(const Date&d);
	Date operator--();
	Date operator--(int a);
	int operator[](int a);
};
