#include "My_String.h"
namespace mystr
{
    void print_str(const string& s)
    {
        string::const_iterator it = s.begin();
        while (it != s.end())
        {
            cout << *it << " ";
            ++it;
        }
        cout << endl;
    }

    void test_string1()
    {
        string s1("hello world");
        cout << s1.c_str() << endl;

        string s2;
        cout << s2.c_str() << endl;

        for (size_t i = 0; i < s1.size(); i++)
        {
            s1[i++];
        }
        cout << s1.c_str() << endl;

        string::iterator it = s1.begin();
        while (it != s1.end())
        {
            cout << *it << " ";
            ++it;
        }
        cout << endl;

        // 傻瓜式的替换成迭代器
        for (auto ch : s1)
        {
            cout << ch << " ";
        }
        cout << endl;

        print_str(s1);
    }

	void test_string2()
	{
		string s1("hello world");
		cout << s1.c_str() << endl;

		s1 += ' ';
		s1 += "xxxxxx";
		cout << s1.c_str() << endl;

		s1.insert(5, 'y');
		s1.insert(5, 'y');
		s1.insert(5, 'y');
		cout << s1.c_str() << endl;

		s1.insert(0, 'y');
		cout << s1.c_str() << endl;

		s1.insert(0, "zzzzzzz");
		cout << s1.c_str() << endl;
	}

	void test_string3()
	{
		string s1("hello world");
		cout << s1.c_str() << endl;

		s1.erase(5, 4);
		cout << s1.c_str() << endl;

		s1.erase(5, 100);
		cout << s1.c_str() << endl;

		/*s1.erase(2);
		cout << s1.c_str() << endl;*/
	}

	void test_string4()
	{
		string s1("hello world");
		string s2("xxxx");
		/*std::swap(s1, s2);*/
		s1.swap(s2);
		cout << s1.c_str() << " " << s2.c_str() << endl;

		string str("https://legacy.cplusplus.com/reference/string/string/substr/");
		string sub1, sub2, sub3;
		size_t pos1 = str.find(':');
		sub1 = str.substr(0, pos1 - 0);
		cout << sub1.c_str() << endl;

		size_t pos2 = str.find('/', pos1 + 3);
		sub2 = str.substr(pos1 + 3, pos2 - (pos1 + 3));
		cout << sub2.c_str() << endl;

		sub3 = str.substr(pos2 + 1);
		cout << sub3.c_str() << endl;
	}

	void test_string5()
	{
		string s1("hello world");
		string s2(s1);

		string s3("xxxx");
		s1 = s3;
		cout << s1.c_str()<< endl;
	}

	void test_string6()
	{
		string s1("hello world");
		string s2(s1);

		string s3("xxxx");
		s1 = s3;

		cout << s1.c_str() << endl;
		cout << s1 << endl;

		cin >> s1;
		cout << s1 << endl;

		cin >> s2;
		cout << s2 << endl;
	}


	void test_string7()
	{
		string s1("hello world");
		cout << s1.c_str() << endl;
		cout << s1 << endl;

		s1.clear();
		cout << s1.c_str() << endl;
		cout << s1 << endl;
	}

	void test_string8()
	{
		string s1("hello world");
		string s2(s1);

		cout << s1 << endl;
		cout << s2 << endl;

		string s3("xxxxxxxxxxxxxxxx");
		s1 = s3;
		cout << s1 << endl;
		cout << s3 << endl;
	}
}
int main()
{
	mystr::test_string1();
	mystr::test_string2();
	mystr::test_string3();
	mystr::test_string4();
	mystr::test_string5();
	mystr::test_string6();
	mystr::test_string7();
	mystr::test_string8();
	return 0;
}