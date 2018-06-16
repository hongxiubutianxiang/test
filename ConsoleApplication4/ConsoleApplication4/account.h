#ifndef _ACCOUNT_H
#define _ACCOUNT_H
#include "date.h"
#include "accumulator.h"
#include <iostream>
#include <string>
#include <map>
#include <istream>
#include <stdexcept>
using namespace std;

class Account;
class AccountRecord        //��Ŀ��¼
{
public:
	AccountRecord(const Date &date, const Account* account, double amount, double balance, const string &desc);
	void show()const;          //�����ǰ��¼
private:
	Date date;                 //����
	const Account* account;    //�˻�
	double amount;             //���
	double balance;            //���
	string desc;               //����
};

typedef multimap<Date, AccountRecord> RecordMap;
//�˻���
class Account
{
public:
	const string& getId()const
	{
		return id;
	}
	double getBalance()const
	{
		return balance;
	}
	static double getTotal()
	{
		return total;
	}
	//�����ֽ�dateΪ���ڣ�amountΪ��descΪ����˵��
	virtual void deposit(const Date &date, double amount, const string &desc) = 0;
	//ȡ���ֽ�dateΪ���ڣ�amountΪ��descΪ����˵��
	virtual void withdraw(const Date &date, double amount, const string &desc) = 0;
	//���㣬ÿ�½���һ�Σ�dateΪ��������
	virtual void settle(const Date &date) = 0;
	//��ʾ�˻���Ϣ
	virtual void show(ostream &out)const;
	//��ѯָ��ʱ���ڵ���Ŀ��¼
	static void query(const Date &begin, const Date &end);
protected:
	//����������õĹ��캯��
	Account(const Date &date, const string &id);
	//��¼һ���ˣ�dateΪ���ڣ�amountΪ��descΪ˵��
	void record(const Date &date, double amount, const string &desc);
	//���������Ϣ
	void error(const string &msg)const;
private:
	string id;              //�˻�
	double balance;         //���
	static double total;    //�����˻����ܽ��
	static RecordMap recordMap;    //��Ŀ��¼
};
inline ostream& operator<<(ostream &out, const Account &account)
{
	account.show(out);
	return out;
}

class SavingAccount :public Account         //�����˻���
{
public:
	SavingAccount(const Date &date, const string &id, double rate);
	double getRate()const
	{
		return rate;
	}
	//�����ֽ�
	void deposit(const Date &date, double amount, const string &desc);
	//ȡ���ֽ�
	void withdraw(const Date &date, double amount, const string &desc);
	//������Ϣ��ÿ��1��1�յ���һ�θú���
	void settle(const Date &date);
private:
	Accumulator acc;           //����������Ϣ���ۼ���
	double rate;               //����������
};

class CreditAccount :public Account        //�����˻���
{
public:
	CreditAccount(const Date &date, const string &id, double credit, double rate, double fee);
	double getCredit()const
	{
		return credit;
	}
	double getRate()const
	{
		return rate;
	}
	double getFee()const
	{
		return fee;
	}
	double getAvailableCredit()const            //��ÿ������ö��
	{
		if (getBalance() < 0)
			return credit + getBalance();
		else
			return credit;
	}
	//�����ֽ�
	void deposit(const Date &date, double amount, const string &desc);
	//ȡ���ֽ�
	void withdraw(const Date &date, double amount, const string &desc);
	//������Ϣ����ѣ�ÿ��1�յ���һ�θú���
	void settle(const Date &date);
	virtual void show(ostream &out)const;
private:
	Accumulator acc;         //����������Ϣ���ۼ���
	double credit;           //���ö��
	double rate;             //Ƿ���������
	double fee;              //���ÿ����
	double getDebt() const   //���Ƿ���
	{
		double balance = getBalance();
		return (balance < 0 ? balance : 0);
	}
};

class AccountException :public runtime_error
{
public:
	AccountException(const Account* account, const string &msg) :runtime_error(msg), account(account)
	{
	}
	const Account* getAccount()const
	{
		return account;
	}
private:
	const Account* account;
};

#endif