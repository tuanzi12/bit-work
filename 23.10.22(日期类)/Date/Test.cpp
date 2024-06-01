#define _CRT_SECURE_NO_WARNINGS 1
#include "Date.h"

int main()
{
	Date d1;
	Date d2 = { 2024, 3, 9 };
	Date d3(d2);
	Date d4 = d2 + 40;
	Date d5 = d2 - d1;
	/*cout << d3 << endl;*/
	cout << d1 << d2 << d3 << d4 << endl;


	return 0;
}