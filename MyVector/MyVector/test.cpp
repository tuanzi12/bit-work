#include "My_Vector.h"
using namespace Myvector;
void test_vector1()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);
	v.push_back(4);
	v.push_back(4);

	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v[0]++;
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	v.insert(v.begin(), 100);
	print_vector(v);

	v.insert(v.begin(), 100);
	print_vector(v);

	int i = 0;
	int j = int();
	int k = int(10);
}
void test_vector4()
{
	vector<string> v;
	v.reserve(10);
	v.push_back("xxxx");
	v.push_back("xxxx");
	v.push_back("xxxx");
	v.push_back("xxxx");
	v.push_back("xxxx");
	v.push_back("xxxx");

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.resize(8);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.resize(15, "yyyy");
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.resize(3);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_vector5()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.erase(v.begin() + 3);

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}
// 迭代器失效
void test_vector6()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	//v.push_back(7);

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	// 要求删除所有的偶数
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
		{
			it = v.erase(it);
		}
		else
		{
			++it;
		}
	}

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}
void test_vector7()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	v.push_back(9);

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;


	vector<string> vstr;
	vstr.push_back("1111");
	vstr.push_back("1111");
	vstr.push_back("1111");
	vstr.push_back("1111");
	vstr.push_back("1111");

	for (auto e : vstr)
	{
		cout << e << " ";
	}
	cout << endl;
}

int main()
{
	test_vector1();
	test_vector4(); 
	test_vector5();
	test_vector6();
	test_vector7();
	return 0;
}