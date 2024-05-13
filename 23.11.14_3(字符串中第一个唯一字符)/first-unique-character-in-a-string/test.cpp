#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;


int firstUniqChar(string s)
{

    for (int i = 0; i < s.size(); ++i)
    {
        int index = s.find(s[i]);
        int reverse_index = s.rfind(s[i]);
        if (index == reverse_index)
            return i;
    }
    return -1;
}

int main()
{
    string s = "loveleetcode";
    int num = firstUniqChar(s);
    cout << num << endl;
}

