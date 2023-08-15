#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <string.h>
void reverse(char* left, char* right)
{
	
		assert(left && right);
		while (left<right)
			{
				char tmp = *left;
				*left = *right;
				*right = tmp;
				left++;
				right--;
			}
}
void left_move(char *str,int k)
{
	
		int len = strlen(str);
		k %= len;
		//×ó±ßÄæÐò
		reverse(str, str+k-1);
		//ÓÒ±ßÄæÐò
		reverse(str+k, str + len - 1);
		//ÕûÌåÄæÐò
		reverse(str, str + len-1);
		
}
int main()
{
	char arr[] = "ABCD";
	int k = 0;
	printf("ÇëÊäÈëÄãÒªÐý×ªµÄÖµ");
	scanf("%d", &k);
	left_move(arr,k);
	printf("%s\n", arr);
	return 0;
}
