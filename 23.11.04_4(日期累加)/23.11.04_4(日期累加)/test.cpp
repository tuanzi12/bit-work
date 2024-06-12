#include <iostream>
#include <assert.h>
using namespace std;

static int GetMonthandDay(int& year, int _month,int& day)
{
	
	int montharr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	while(day > montharr[_month])
	{
		if (_month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
			++montharr[_month];
		if (day > montharr[_month])
			day -= montharr[_month];
		++_month;
		if (_month == 13)
		{
			_month = 1;
			++year;
		}
		if (day == 0)
			day = 1;
	}
	return _month;
}


int main()
{	
	int n = 0;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			int year, month, day, num;
			cin >> year >> month >> day >> num;
			day += num;
			int _month = GetMonthandDay(year, month,day);
			printf("%d-%02d-%02d\n", year, _month, day);
		}
		
	}
	
	return 0;
}


