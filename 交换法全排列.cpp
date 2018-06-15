/*#include<iostream>
using namespace std;
int n,panduan[100],used[100];
void print()
{int i;
for(i=1;i<=n;i++)
cout<<used[i];
cout<<endl;
}

void dfs(int k) 
{
    int i;
    if (k == n) 
    {
        print(); 
        return;
    }
    for (i = 1; i <= n; i++) 
    {
        if (!panduan[i])
        {
            panduan[i] = 1;
            used[k + 1] = i; 
            dfs(k + 1);
            panduan[i] = 0;
        }
    }
}
int main()
{
    while(cin >> n)
    {dfs(0); //注意，这里是从第0格开始的！
    }
    return 0;
}*/



// #include <cstdio>
// #include <iostream>
// #include <cstring>
// #include <cstdlib>
// using namespace std;
// int a[10], b[10];
// int n, cnt = 0;
// void dfs(int i)
// {
//     if (i == n)
//     {
//         cnt++;
//         for (int j = 1; j <= n; j++)
//             cout<<a[j];
//         cout << endl;
//     }
//     else
//     {
//         for (int j = 1; j <= n; j++)
//             if (!b[j])
//             {
//                 a[i + 1] = j;
//                 b[j] = 1;
//                 dfs(i + 1);
//                 b[j] = 0;
//             }
//     }
// }
// int main()
// {
//     while(cin >> n)
//    {memset(b, 0, sizeof(b));
//     dfs(0);}
//     return 0;
// }



#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
int n = 0;

void swap(int *a, int *b) 
{

    int m;
    m = *a;
    *a = *b;
    *b = m;
}

void perm(int list[], int k, int m) 
{
    int i;

    if(k > m)

    {

        for(i = 0; i <= m; i++)

            printf("%d", list[i]);

        printf("\n");

        n++;

    }

    else

    {

        for(i = k; i <= m; i++)

        {

            swap(&list[k], &list[i]);

            perm(list, k + 1, m);

            swap(&list[k], &list[i]);

        }

    } 
} 
int main() 
{

    int list[] = {1, 2, 3, 4, 5,6,7,8,9,10},n;
while(cin>>n)
  { perm(list, 0, n-1);

    
  }

    return 0; 
}