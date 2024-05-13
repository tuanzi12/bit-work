#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;
/*

*思路：

* 1. 收尾交换，进行翻转

*/
    void reverseString(vector<string>& s)
    {
        if (s.empty())
            return;
        int start = 0;
        int end = s.size() - 1;
        while (start < end)
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
        for (auto it = s.begin(); it != s.end(); ++it)
        {
            cout << *it << " ";
        }
    }


    int main()
    {
        vector<string> str;
        str.push_back("a");
        str.push_back("p");
        str.push_back("p");
        str.push_back("l");
        str.push_back("e");
        reverseString(str);
    }

