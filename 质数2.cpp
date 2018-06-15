#include <iostream>

using namespace std;
#include <math.h>
int main()
{
    int i,j,k,flag;
    
    for(i=2;i<=10000;i++)
    {
        flag=1;
        k=sqrt(i);
       
        for (j = 2; j <= k;j++)
        {
            if(i%j==0)
         {
                  flag=0;
                 break;
         }
        
        }
        if (flag)
        {
            cout << i << endl;
        }
        
    }
    
   cin>>i; 
}