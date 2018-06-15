#include<iostream>
using namespace std;
int num[1000][1000];
int min(int a, int b)
{
    return a < b ? a : b;
}
int main()
{  int i,j,n;
    while(cin>>n)
    {
        for(i=0;i<n;i++)
        for(j=0;j<=i;j++)
        cin>>num[i][j];
        for (i = n - 2; i >= 0; i--)
            for (j = 0; j <= i; j++)
               num[i][j] += min(num[i + 1][j], num[i + 1][j + 1]);
                cout<<num[0][0]<<endl;
    }
    return 0;
} 