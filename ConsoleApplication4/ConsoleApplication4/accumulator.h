#ifndef _ACCUMULATOR_H
#define _ACCUMULATOR_H
#include "date.h"
class Accumulator            //��ĳ����ֵ�����ۼ�
{
public:
	//dateΪ��ʼ�ۼӵ����ڣ�valueΪ��ʼֵ
	Accumulator(const Date &date, double value) :lastDate(date), value(value), sum(0)
	{
	}
	double getSum(const Date &date)const
	{
		return sum + value * (date - lastDate);
	}
	//��date����ֵ���Ϊvalue
	void change(const Date &date, double value)
	{
		sum = getSum(date);
		lastDate = date;
		this->value = value;
	}
	//��ʼ���������ڱ�Ϊdate,��ֵ��Ϊvalue,�ۼ�������
	void reset(const Date &date, double value)
	{
		lastDate = date;
		this->value = value;
		sum = 0;
	}
private:
	Date lastDate;           //�ϴα����ֵ��ʱ��
	double value;            //��ֵ�ĵ�ǰֵ
	double sum;              //��ֵ�����ۼ�֮��
};

#endif