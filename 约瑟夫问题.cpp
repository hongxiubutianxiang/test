// #include <iostream>
// #include <queue> 
// using namespace std;
// int main()
// {
//     queue<int> map; 
//     int n, m;
//    cin >> n >> m;
//     {if (n == 0)
//     { 
//         return 0;
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         map.push(i); 
//     }
//     int a;                
//     while (map.size() > 1) 
//     {
//         for (int i = 1; i <= m - 1; i++) 
//         {
//             a = map.front(); 
//             map.pop();
//             map.push(a);            
//         }                           
//         cout << map.front() << ' '; 
//         map.pop();                  
//     }                               
//     cout << map.front();  
//     }         
//     return 0;
// }
#include <iostream>
using namespace std;
int main()
{
    int i, k, m, n, num[110], *p, c;
    
    while(cin >> n >> c)
    {p = num;
    for (i = 0; i < n; i++)
    {
        *(p + i) = i + 1;
        
    }
    
    i = 0;
    k = 0;
    m = 0;
    if (n == 0)
        return 0;
    while (m < n - 1)
    {
        
        if (*(p + i) != 0)
            k++;
        if (k == c)
        {
            cout << *(p + i) << " ";
            *(p + i) = 0;
            k = 0;
           
            m++;
           
        }
        i++;       
        if (i == n) 
            i = 0;
    }
    while (*p == 0) 
        p++;
    cout << *p << endl;}
    return 0;
}