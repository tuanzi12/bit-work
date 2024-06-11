#include <iostream>
using namespace std;

static int GetMonthandDay(int& _year, int& _day)
{
	int montharr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int month = 1;
	for (; month <= 12; month++)
	{
		if (month == 2 && ((_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0))
			++montharr[month];
		if (_day > montharr[month])
			_day -= montharr[month];
		else
			break;
	}
	return month;
}


int main()
{
	int _year, _day;
	cin >> _year >> _day;
	int _month = GetMonthandDay(_year, _day);
	printf("%d-%02d-%02d\n", _year, _month, _day);
	return 0;
}


