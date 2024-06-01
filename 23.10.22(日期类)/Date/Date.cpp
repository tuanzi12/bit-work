#define _CRT_SECURE_NO_WARNINGS 1
#include "Date.h"


Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
	if (year < 1 || _month < 1 || _month > 12
		|| _day <1 || _day >GetMonthDay(_year, _month))
	{
		Print();
		cout << "日期非法" << endl;
	}
}

int Date::GetMonthDay(int year, int month)
{
	assert(year >= 1 && month >= 1 && month <= 12);
	int montharr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0)) ||  year % 400 == 0)
		return 29;
		return montharr[month];
}

void Date::Print() const
{
	cout << _year << "/" << _month << "/" << _day << endl;
}

//日期+=天数
Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		return *this -= (-day);
	}
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		++_month;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}

//赋值运算符重载
Date& Date::operator=(const Date& d)
{
	_day = d._day;
	_month = d._month;
	_year = d._year;
	return *this;
}

// 日期+天数
Date Date::operator+(int day) const 
{
	Date tmp(*this);
	tmp += day;
	return tmp;
}

// 日期-天数
Date Date::operator-(int day) const
{
	Date tmp(*this);
	tmp -= day;
	return tmp;
}
//
 //日期-=天数
Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += (-day); 
	}
	_day -= day;
	while (_day <= 0)
	{
		--_month;
		if (_month == 0)
		{
			--_year;
			_month = 12;

		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;

}


// 前置++
Date& Date::operator++()
{
	*this += 1;
	return *this;
}

// 后置++
Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;
	return tmp;
}

// 前置--
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

// 后置--
Date Date::operator--(int)
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}

// >运算符重载
bool Date::operator>(const Date& d)const
{
	if (_year > d._year)
	{
		return true;
	}
	else if (_year == d._year && _month > d._month)
	{
		return true;
	}
	else if (_year == d._year && _month == d._month && _day > d._day)
	{
		return true;
	}
	return false;
}

// ==运算符重载
bool Date::operator==(const Date& d)const
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

// >=运算符重载
bool Date::operator >= (const Date& d)const
{
	return *this > d || *this == d;
}

// <运算符重载
bool Date::operator < (const Date& d) const
{
	return !(*this >= d);
}

// <=运算符重载
bool Date::operator <= (const Date& d)const
{
	return !(*this > d);
}

// !=运算符重载
bool Date::operator != (const Date& d)const
{
	return !(*this == d);
}

// 日期-日期 返回天数
int Date::operator-(const Date& d)const
{
	int flag = 1;
	Date max = *this;
	Date min = d;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int i = 0;
	while (min != max)
	{
		++min;
		++i;
	}
	return i * flag;
}
//
ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "年" << d._month << "月" << d._day << "日"<< endl;
	return out;
}

istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}