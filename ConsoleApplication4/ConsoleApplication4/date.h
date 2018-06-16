
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
	int getMaxDay()const;        //��õ����ж�����
	bool isLeapYear() const      //�жϵ����Ƿ�Ϊ����
	{
		return year % 4 == 0 && year % 100 != 0 && year % 400 == 0;
	}
	void show()const;        //�����ǰ����
	int operator-(const Date &date)const      //������������֮��������
	{
		return totalDays - date.totalDays;
	}
	bool operator<(const Date &date)const     //�ж��������ڵ�ǰ��˳��
	{
		return totalDays < date.totalDays;
	}
private:
	int year;
	int month;
	int day;
	int totalDays;       //�������Ǵӹ�ԪԪ��1��1�տ�ʼ�ĵڼ���
};
istream& operator >> (istream &in, Date &date);
ostream& operator << (ostream &out, const Date &date);

#endif