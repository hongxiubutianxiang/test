#include <iostream>
#include <cstring>
using namespace std;
struct xx
{
    char xm[222];
    int qmcj;
    int bjpf;
    char xsgb[5];
    char xbxs[5];
    int lws;

} a[222];
int main()
{
    int i, n, t, k, b[222], max = 0, sum = 0;
    while (cin >> n)
    {
        for (i = 0; i < n; i++)
            cin >> a[i].xm >> a[i].qmcj >> a[i].bjpf >> a[i].xsgb >> a[i].xbxs >> a[i].lws;
        for (i = 0; i < n; i++)
            b[i] = 0;
        for (i = 0; i < n; i++)
        {
            if (a[i].qmcj > 80 && a[i].lws > 0)
                b[i] += 8000;
            if (a[i].qmcj > 85 && a[i].bjpf > 80)
                b[i] += 4000;
            if (a[i].qmcj > 90)
                b[i] += 2000;
            if (a[i].qmcj > 85 && strcmp(a[i].xbxs, "Y") == 0)
                b[i] += 1000;
            if (a[i].bjpf > 80 && strcmp(a[i].xsgb, "Y") == 0)
                b[i] += 850;
        }
        for (i = 0; i < n; i++)
            sum += b[i];
        for (i = 0; i < n; i++)
            if (b[i] > max)
            {
                max = b[i];
                t = i;
            }
        cout << a[t].xm << endl
             << max << endl
             << sum << endl;
    }
    return 0;
}