#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        int res = 0;
        int i = 0;
        int flag = 1;
        while (str[i] == ' ')
        {
            i++;
        }
        if (str[i] == '-')
        {
            flag = -1;
        }
        if (str[i] == '+' || str[i] == '-')
        {
            i++;
        }
        // 1. 用低于int型数据长度一位的数据border判断了超过int型数据长度的值 
        // 2. 将超过最大值和低于最小值的情况都包括了
        while (i < str.size() && isdigit(str[i]))
        {
            int r = str[i] - '0';
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && r > 7))
            {
                return flag > 0 ? INT_MAX : INT_MIN;
            }
            res = res * 10 + r;
            i++;
        }
        return flag > 0 ? res : -res;
    }
};

int main()
{
    Solution str;
    int num = str.myAtoi(" -2 3");
    cout << num << endl;
}