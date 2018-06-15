#include <cstdio>
#include<iostream>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int main()
{
    int n;
   while( cin>>n)
    {int num[n];
    for (int i = 0; i < n; i++)
    {
        cin>>num[i];
    }
    int q = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (gcd(num[i], num[j]) == 1)
            {
                q++;
            }
        }
    }
    cout<<q;
    }
    return 0;
}