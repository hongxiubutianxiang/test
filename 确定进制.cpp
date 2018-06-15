#include<iostream>
using namespace std;
#define B 10
int change(int v,int base)
{
 int an,w,r;
 an=0;
 w=1;
 while(v)
 {
     r=v%B;
     v/=B;
     if(r>=base)
     return -1;
     an+=w*r;
     w*=base;
 }
 return an;
}
int main()
{
    int p1111111111,q1111111111,r1111111111,i1111111111;
    int p33333333333,q33333333333,r33333333333;
  cin>>p1111111111>>q1111111111>>r1111111111;
   {for(i1111111111=2;i1111111111<=16;i1111111111++)
   {p33333333333=change(p1111111111,i1111111111);
    if(p33333333333<0)
    continue;
        q33333333333=change(q1111111111,i1111111111);
        if(q33333333333<0)
        continue;
    r33333333333=change(r1111111111,i1111111111);
    if(r33333333333<0)
continue;
if(p33333333333*q33333333333==r33333333333)
{cout<<i1111111111;
return 0;}
}
cout<<2;
   
return 0;
}
}