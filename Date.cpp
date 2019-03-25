#include"Date.h"



Date::Date(int m,int d,int y)
{
	if(m<=12&&m>0)
		month=m;
	else
		month=1;
	if(y<=9999&&y>=1000)
		year=y;
	else 
		year=2000;
	if(d<=30&&d>0)
		date=d;
	else
		date=1;
}
Date::Date()
{

	month=1;

	year=2000;

	date=1;
}

bool Date::operator==(const Date & d)
{
	if(d.year!=year)
		return false;
	if(d.month!=month)
		return false;
	if(d.date!=date)
		return false;
	else 
		return true;
}

Date Date::operator+(int s)
{
	date=date+s;
	if(date>30)
	{
		month=month+1;
	    date=date-30;
		if(month>12)
		{
			year=year+1;
		month=1;
		}
	}
	return *this;
}
Date Date::operator=(const Date&d)
{
	date=d.date;
	month=d.month;
	year=d.year;
	return *this;
}
Date Date::operator--()
{
	date=date-1;;
	if(date<1)
	{
		month=month-1;
	    date=30;
		if(month<1)
		{
			year=year-1;
		month=12;
		}
	}
	return *this;

}
Date Date::operator--(int a)
{
	Date temp(month,date,year);
	--(*this);
	return temp;;
}
int Date::operator[](int a)
{
	if(a<3&&a>=0)
	{
		if(a==0)
			cout<<date;
		if(a==1)
			cout<<month;
		if(a==2)
			cout<<year;
	}
	else
	{
		cout<<0<<"-";
		cout<<"sorry index can only be 0,1,2";
	}
	return 0;
}