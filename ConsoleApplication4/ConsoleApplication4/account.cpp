#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <utility>
#include "account.h"
using namespace std;
using namespace std::rel_ops;

//AccountRecord类的实现
AccountRecord::AccountRecord(const Date &date, const Account* account, double amount, double balance, const string &desc) :\
date(date), account(account), amount(amount), balance(balance), desc(desc)
{
}
void AccountRecord::show()const
{
	cout << date << "\t#" << account->getId() << "\t" << amount << "\t" << balance << "\t" << desc << endl;
}

//Account类的实现
double Account::total = 0;
RecordMap Account::recordMap;
Account::Account(const Date &date, const string &id) :id(id), balance(0)
{
	cout << date << "\t#" << id << " created" << endl;
}
void Account::record(const Date &date, double amount, const string &desc)
{
	amount = floor(amount * 100 + 0.5) / 100;      //保留小数点后两位
	balance += amount;
	total += amount;
	date.show();
	cout << "\t#" << id << "\t" << amount << "\t" << balance << "\t" << desc << endl;
}
void Account::show(ostream &out)const
{
	out << id << "\tBalance: " << balance;
}
void Account::error(const string &msg)const
{
	throw AccountException(this, msg);
}
void Account::query(const Date &begin, const Date &end)
{
	if (begin <= end)
	{
		RecordMap::iterator iter1 = recordMap.lower_bound(begin);
		RecordMap::iterator iter2 = recordMap.upper_bound(end);
		for (RecordMap::iterator iter = iter1; iter != iter2; ++iter)
			iter->second.show();
	}
}

//CreditAccount类的实现
CreditAccount::CreditAccount(const Date &date, const string &id, double credit, double rate, double fee) :\
Account(date, id), credit(credit), rate(rate), fee(fee), acc(date, 0)
{
}
void CreditAccount::deposit(const Date &date, double amount, const string &desc)
{
	record(date, amount, desc);
	acc.change(date, getDebt());
}
void CreditAccount::withdraw(const Date &date, double amount, const string &desc)
{
	if (amount - getBalance() > credit)
	{
		error("not enough credit");
	}
	else
	{
		record(date, -amount, desc);
		acc.change(date, getDebt());
	}
}
void CreditAccount::settle(const Date &date)
{
	double interest = acc.getSum(date)*rate;
	if (interest != 0)
		record(date, interest, "interest");
	if (date.getMonth() == 1)
		record(date, -fee, "annual fee");
	acc.reset(date, getDebt());
}
void CreditAccount::show(ostream &out)const
{
	Account::show(out);
	out << "\tAvailable credit: " << getAvailableCredit();
}

//SavingAccount类的实现
SavingAccount::SavingAccount(const Date &date, const string &id, double rate) :Account(date, id), rate(rate), acc(date, 0)
{
}
void SavingAccount::deposit(const Date &date, double amount, const string &desc)
{
	record(date, amount, desc);
	acc.change(date, getBalance());
}
void SavingAccount::withdraw(const Date &date, double amount, const string &desc)
{
	if (amount > getBalance())
	{
		error("not enough money");
	}
	else
	{
		record(date, -amount, desc);
		acc.change(date, getBalance());
	}
}
void SavingAccount::settle(const Date &date)
{
	if (date.getMonth() == 1)        //每年的1月计算一次利息
	{
		double interest = acc.getSum(date)*rate / (date - Date(date.getYear() - 1, 1, 1));
		if (interest != 0)
			record(date, interest, "interest");
		acc.reset(date, getBalance());
	}
}
