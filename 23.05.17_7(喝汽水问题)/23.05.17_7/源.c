#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int money,bottle,lost,price,tmp;
	printf("���������ж���Ǯ");
	scanf("%d", &money);
	printf("��������ˮ�ļ۸�");
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
	printf("�������%dƿ��ˮ", bottle);
	return 0;
}