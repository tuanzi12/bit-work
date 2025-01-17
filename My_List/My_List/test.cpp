#include "MyList.h"
using namespace std;
void test_list1()
{
	MyList::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	MyList::list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		//*it += 10;

		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}
void test_list2()
{
	MyList::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);


	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.push_back(5);
	lt.push_front(0);

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.pop_back();
	lt.pop_front();

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.clear();

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.push_back(10);
	lt.push_back(20);

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_list3()
{
	MyList::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	MyList::list<int> copy(lt);
	for (auto e : copy)
	{
		cout << e << " ";
	}
	cout << endl;

	MyList::list<int> lt1;
	lt1.push_back(10);
	lt1.push_back(20);
	lt1.push_back(30);
	lt1.push_back(40);

	lt = lt1;
	for (auto e : copy)
	{
		cout << e << " ";
	}
	cout << endl;
}
int main()
{
	test_list2();
	//test_list3();

	return 0;
}
