#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	long long seconds;
	int hours=0, minutes=0;
	scanf("%lld", &seconds);
	if (seconds / 3600 > 0)
	{
		hours=seconds/3600;
		seconds = seconds % 3600;
	}
	if (seconds / 60 > 0)
	{
		minutes = seconds / 60;
		seconds = seconds % 60;
	}
	printf("%d %d %lld", hours, minutes, seconds);
	return 0;
}