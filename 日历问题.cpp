#include<iostream>
#include<iomanip>
using namespace std;

int yearDays(int year)                                                //返回该年的天数
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 366;
    else
        return 365;
}

int monthDays(int year, int month)                                        //返回对应月份天数
{
   int a[13];
for(int i=1;i<13;i++)
if(i==4||i==6||i==9||i==11)
a[i]=30;
else
a[i]=31;
if(yearDays(year)==366)
a[2]=29;
else
a[2]=28;
return a[month];
}                                                    
void cal(int n, int &year, int &month, int &day)            //计算年月日
{
    year = 2000;
    while (n >= yearDays(year))
    {
        n -= yearDays(year);
        year++;
    }
    month = 1;
    while (n >= monthDays(year,month))
    {
        n -= monthDays(year, month);
        month++;
    }
    day = n+1;
}
void week(int n)                                    //计算星期几
{
    int week = n % 7;
    switch (week)
    {
    case 0:cout << "Saturday"; break;
    case 1:cout << "Sunday"; break;
    case 2:cout << "Monday"; break;
    case 3:cout << "Tuesday"; break;
    case 4:cout << "Wednesday"; break;
    case 5:cout << "Thursday"; break;
    case 6:cout << "Friday";
    }
}

int main()
{
    int n,year,month,day;

    while ((cin >> n) && (n != EOF))
    {
        n;
        cal(n, year, month, day);
        cout << year << "-" <<setw(2)<<setfill('0')<< month << "-" <<setw(2)<<setfill('0')<< day << " ";
        week(n);
        cout << endl;
    }
  
    return 0;
}