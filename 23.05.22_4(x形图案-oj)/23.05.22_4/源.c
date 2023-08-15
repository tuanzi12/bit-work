#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main() 
{
    int num = 0;
    int i, j;
    while (scanf("%d", &num) != EOF)
    {
        for (i = 0; i < num; i++)
        {
            for (j = 0; j < num; j++)
            {
                if (i == j)
                    printf("*");
                else if (j == num - i - 1)
                    printf("*");
                else
                    printf(" ");
            }
            printf("\n");
        }   
    }
    return 0;
}
