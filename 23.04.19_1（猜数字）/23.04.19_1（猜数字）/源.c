#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void menu()
{
	printf("**************************\n");
	printf("**1.开始游戏      2.退出**\n");
	printf("**************************\n");
}

void game()
{
	int ret = rand() % 100 + 1;
	int guess = 0;
	int small = 0, max = 100;
	while (1)
	{
		printf("请猜数字");
		scanf("%d", &guess);
		if (guess > ret)
		{
			printf("猜大了\n");
			max = guess;
			printf("%d--%d的数字\n", small, max);
		}
		else if (guess < ret)
		{
			printf("猜小了\n");
			small = guess;
			printf("%d--%d的数字\n", small , max );
		}
		else
		{
			printf("恭喜你，猜对了\n");
			break;
		}
	}
}

int main()
{
	int input = 0;
	srand(time(0));
	do
	{
		menu();
		printf("请选择-->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:printf("猜数字游戏\n"); game(); break;
		case 2:printf("退出游戏\n"); break;
		default:printf("选择错误，重新选择\n");
		}
	} while (input != 2);
	return 0;
}
