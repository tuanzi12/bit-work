#pragma once

#include <iostream>
#include <assert.h>
using namespace std;
class Date
{
public:
	//ȫȱʡ�Ĺ��캯��
	Date(int year = 1900, int month = 1, int day = 1);
	void Print() const;
	// ��ȡĳ��ĳ�µ�����
	int GetMonthDay(int year, int month);
	 //�������캯��
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	// ��ֵ���������
	Date& operator=(const Date& d);
	// ��������
	~Date()
	{	}
	//// ����+=����
	Date& operator+=(int day);
	//// ����+����
	Date operator+(int day) const;
	// ����-����
	Date operator-(int day)const;
	//// ����-=����
	Date& operator-=(int day);
	//// ǰ��++
	Date& operator++();
	//// ����++
	Date operator++(int);
	// ����--
	Date operator--(int);
	// ǰ��--
	Date& operator--();
	// >���������
	bool operator>(const Date& d)const;
	// ==���������
	bool operator==(const Date& d)const;
	// >=���������
	bool operator >= (const Date& d)const;
	// <���������
	bool operator < (const Date& d)const;
	// <=���������
	bool operator <= (const Date& d)const;
	// !=���������
	bool operator != (const Date& d)const;
	// ����-���� ��������
	int operator-(const Date& d)const;
	// �Զ����������
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);

private:

	int _year;
	int _month;
	int _day;

};
