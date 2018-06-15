// #include <iostream>
// #include <cstring>
// using namespace std;
// const int MAX = 100;
// char n1[MAX], n2[MAX];
// int q1[MAX], q2[MAX], q3[2 * MAX + 10];

// int main()
// {
//     while (cin >> n1 >> n2)
//     {
//         int len1 = strlen(n1), len2 = strlen(n2);
//         memset(q1, 0, sizeof q1);
//         memset(q2, 0, sizeof q2);
//         memset(q3, 0, sizeof q3);
//         for (int i = len1 - 1, j = 0; i >= 0; i--, j++)
//             q1[j] = n1[i] - '0';
//         for (int i = len2 - 1, j = 0; i >= 0; i--, j++)
//             q2[j] = n2[i] - '0';
//         for (int i = 0; i < len1; i++)
//             for (int j = 0; j < len2; j++)
//                 q3[i + j] += q1[i] * q2[j];
//         int i;
//         int z,x,c,v,b,h,k;
//         char e,r,t,y;
//         for (i = 0; i < 2 * MAX; i++)
//         {
//             q1[i + 1] += q3[i] / 10;
//             q3[i] %= 10;
//         }
//         while (q3[i] == 0)
//             {i--;}
//         if (i < 0)
//           cout << "0";
//         for (; i >= 0; i--)
//             cout <<q3[i];
//         cout << endl;
//     }
//     return 0;
// }
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

#define nn 70000
#define snn 60000

using namespace std;

struct gjtype
{
    int a[nn];
    void clean()
    {
        memset(a, 0, sizeof(a));
    }
    void ntog(long long s)
    {
        clean();
        int i = 0;
        while (s > 0)
        {
            i++;
            a[i] = s % 100;
            s = s / 100;
        }
        a[0] = i;
    }
    void stog(char s1[])
    {
        clean();
        char ss[snn], s[snn];
        bool pos = true;
        if (s1[0] == '-')
        {
            strcpy(s, s1 + 1);
            pos = false;
        }
        else
            strcpy(s, s1);
        int i = 0;
        while (strlen(s) >= 2)
        {
            i++;
            for (int j = strlen(s) - 2; j < strlen(s); j++)
                ss[j - strlen(s) + 2] = s[j];
            s[strlen(s) - 2] = '\0';
            a[i] = atoi(ss);
        }
        if (strlen(s) > 0)
        {
            i++;
            a[i] = atoi(s);
        }
        a[0] = i;
        if (!pos)
            a[a[0]] = -a[a[0]];
    }
    void out()
    {
        printf("%d", a[a[0]]);
        for (int i = a[0] - 1; i >= 1; i--)
            printf("%02d", a[i]);
        putchar('\n');
    }
};
gjtype a, b, c;

const double PI = acos(-1.0);

struct fstype
{
    double x, y;
    fstype(double real = 0.0, double imag = 0.0)
    {
        x = real;
        y = imag;
    }
    fstype operator-(const fstype &b) const
    {
        return fstype(x - b.x, y - b.y);
    }
    fstype operator+(const fstype &b) const
    {
        return fstype(x + b.x, y + b.y);
    }
    fstype operator*(const fstype &b) const
    {
        return fstype(x * b.x - y * b.y, x * b.y + y * b.x);
    }
};

void fft(fstype y[], int len, int on)
{
    int i, j, k;
    for (i = 1, j = len / 2; i < len - 1; i++)
    {
        if (i < j)
            swap(y[i], y[j]);

        k = len / 2;
        while (j >= k)
        {
            j -= k;
            k /= 2;
        }
        if (j < k)
            j += k;
    }

    for (int h = 2; h <= len; h <<= 1)
    {
        fstype wn(cos(-on * 2 * PI / h), sin(-on * 2 * PI / h));
        for (int j = 0; j < len; j += h)
        {
            fstype w(1, 0);
            for (int k = j; k < j + h / 2; k++)
            {
                fstype u = y[k];
                fstype t = w * y[k + h / 2];
                y[k] = u + t;
                y[k + h / 2] = u - t;
                w = w * wn;
            }
        }
    }

    if (on == -1)
        for (int i = 0; i < len; i++)
            y[i].x /= len;
}

fstype x1[nn], x2[nn];
gjtype cc;

gjtype fftcheng(gjtype aa, gjtype bb)
{
    int len1 = aa.a[0], len2 = bb.a[0], len = 1;

    while (len < len1 * 2 || len < len2 * 2)
        len <<= 1;

    for (int i = 1; i <= len1; i++)
        x1[i - 1] = fstype(aa.a[i], 0);
    for (int i = len1; i < len; i++)
        x1[i] = fstype(0, 0);

    for (int i = 1; i <= len2; i++)
        x2[i - 1] = fstype(bb.a[i], 0);
    for (int i = len2; i < len; i++)
        x2[i] = fstype(0, 0);

    fft(x1, len, 1);
    fft(x2, len, 1);

    for (int i = 0; i < len; i++)
        x1[i] = x1[i] * x2[i];

    fft(x1, len, -1);

    cc.clean();

    for (int i = 0; i < len; i++)
        cc.a[i + 1] = (int)(x1[i].x + 0.5);
    for (int i = 1; i <= len; i++)
    {
        cc.a[i + 1] += cc.a[i] / 100;
        cc.a[i] %= 100;
    }

    while (cc.a[len] == 0 && len > 1)
        len--;

    cc.a[0] = len;

    return cc;
}

int main()
{

    gjtype a, b, c;

    char s1[snn], s2[snn];

    while (scanf("%s%s", s1, s2) != EOF)
    {
        a.stog(s1);
        b.stog(s2);

        c = fftcheng(a, b);
        c.out();
    }

    return 0;
}