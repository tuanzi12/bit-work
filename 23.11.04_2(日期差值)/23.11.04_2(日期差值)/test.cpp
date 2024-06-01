#include <iostream>
#include <assert.h>
using namespace std;

int GetMonthDay(int year, int month)
{
	assert(year >= 1 && month >= 1 && month <= 12);
	int montharr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0)) || year % 400 == 0)
		return 29;
	return montharr[month];
}

class Date
{
	public:
	Date(int year = 0, int month = 0, int day = 0)
		:_year(year),
		_month(month),
		_day(day)
	{}

	friend Date Getdate(int n);
	bool operator!=(Date& d)
	{
		return !(*this == d);
	}

	Date& operator++()
	{
		_day++;
		if (_day > GetMonthDay(_year, _month))
		{
			_month++;
			_day = 1;
			if (_month == 13)
			{
				_month = 1;
				_year++;
			}
		}
		return *this;
	}

	bool operator==(Date& d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}

	bool operator<(Date& d)
	{
		if (_year < d._year)
			return true;
		else if (_year == d._year && _month < d._month)
			return true;
		else if (_year == d._year && _month == d._month && _day < d._day)
			return true;
		return false;
	}

	int operator-(Date& d)
	{
		//int flag = 1;
		Date max = *this;
		Date min = d;
		if (*this < d)
		{
			max = d;
			min = *this;
			//flag = -1;
		}
		int i = 0;
		while (min != max)
		{
			++min;
			++i;
		}
		return i;
	}

private:
	int _year;
	int _month;
	int _day;

};

Date Getdate(int n)
{
	Date d;
	d._year = n / 10000;
	d._day = n % 100;
	d._month = (n - d._year * 10000) / 100;
	return d;
}
int main()
{
	//20240601
	//20250601
	int date1, date2;
	cin >> date1 >> date2;
	Date n1 = Getdate(date1);
	Date n2 = Getdate(date2);
	cout << n1 - n2 + 1 << endl;
}