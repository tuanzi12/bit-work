#pragma once

#include <iostream>
#include <assert.h>
using namespace std;
class Date
{
public:
	//全缺省的构造函数
	Date(int year = 1900, int month = 1, int day = 1);
	void Print() const;
	// 获取某年某月的天数
	int GetMonthDay(int year, int month);
	 //拷贝构造函数
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	// 赋值运算符重载
	Date& operator=(const Date& d);
	// 析构函数
	~Date()
	{	}
	//// 日期+=天数
	Date& operator+=(int day);
	//// 日期+天数
	Date operator+(int day) const;
	// 日期-天数
	Date operator-(int day)const;
	//// 日期-=天数
	Date& operator-=(int day);
	//// 前置++
	Date& operator++();
	//// 后置++
	Date operator++(int);
	// 后置--
	Date operator--(int);
	// 前置--
	Date& operator--();
	// >运算符重载
	bool operator>(const Date& d)const;
	// ==运算符重载
	bool operator==(const Date& d)const;
	// >=运算符重载
	bool operator >= (const Date& d)const;
	// <运算符重载
	bool operator < (const Date& d)const;
	// <=运算符重载
	bool operator <= (const Date& d)const;
	// !=运算符重载
	bool operator != (const Date& d)const;
	// 日期-日期 返回天数
	int operator-(const Date& d)const;
	// 自定义输出重载
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);

private:

	int _year;
	int _month;
	int _day;

};
