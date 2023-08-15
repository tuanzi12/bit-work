#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int killer;
	for (killer = 'a'; killer <= 'd'; killer++)
	{
		if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd') == 3)
			printf("Ð×ÊÖÊÇ£º%c", killer);
	}
	return 0;
}
