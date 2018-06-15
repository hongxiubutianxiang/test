#include<iostream>
using namespace std;
#include <stdio.h>
int main()
{
    int n, i, j, res[100] = {1};
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 100; j++)
            res[j] *= 2;
        for (j = 0; j < 99; j++)
        {
            res[j + 1] += res[j] / 10;
            res[j] %= 10;
        }
    }
    while (!res[j])
        j--;
    for (; j >= 0; j--)
        printf("%d", res[j]);
         cin>>n;
}
