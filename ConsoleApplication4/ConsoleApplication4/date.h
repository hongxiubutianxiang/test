
#ifndef _DATE_H
#define _DATE_H
#include <iostream>
using namespace std;
class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1);
	int getYear()const
	{
		return year;
	}
	int getMonth()const
	{
		return month;
	}
	int getDay()const
	{
		return day;
	}
	int getMaxDay()const;        //获得当月有多少天
	bool isLeapYear() const      //判断当年是否为闰年
	{
		return year % 4 == 0 && year % 100 != 0 && year % 400 == 0;
	}
	void show()const;        //输出当前日期
	int operator-(const Date &date)const      //计算两个日期之间差多少天
	{
		return totalDays - date.totalDays;
	}
	bool operator<(const Date &date)const     //判断两个日期的前后顺序
	{
		return totalDays < date.totalDays;
	}
private:
	int year;
	int month;
	int day;
	int totalDays;       //该日期是从公元元年1月1日开始的第几天
};
istream& operator >> (istream &in, Date &date);
ostream& operator << (ostream &out, const Date &date);

#endif