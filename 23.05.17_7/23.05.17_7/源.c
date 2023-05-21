#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int money,bottle,lost,price,tmp;
	printf("请输入你有多少钱");
	scanf("%d", &money);
	printf("请输入汽水的价格");
	scanf("%d", &price);
	bottle = money / price;
	lost = bottle;
	while (lost / 2 !=0)
	{
		tmp = lost;
		lost = lost / 2;
		bottle += lost;
		lost = tmp % 2 + lost;
	}
	printf("你可以买到%d瓶汽水", bottle);
	return 0;
}